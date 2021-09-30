#include "pch.h"
#include "CRoundButton.h"

CRoundButton::CRoundButton() {
	m_Pen.CreatePen(PS_SOLID, 1, RGB(201, 201, 233));
	m_normalBrush.CreateSolidBrush(RGB(231, 231, 231));
	m_activeBrush.CreateSolidBrush(RGB(201, 201, 231));
}

CRoundButton::~CRoundButton() {
    m_Pen.DeleteObject();
    m_normalBrush.DeleteObject();
    m_activeBrush.DeleteObject();
}

void CRoundButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	// TODO:  添加您的代码以绘制指定项
	CDC* pDc = CDC::FromHandle(lpDrawItemStruct->hDC);
	//存储设备当前环境
	int nSaveDc = pDc->SaveDC();
	//选择按钮默认状态下的画刷
	pDc->SelectObject(&m_normalBrush);
	//选择画笔
	pDc->SelectObject(&m_Pen);
	//获取按钮矩形区域
	CRect rct = lpDrawItemStruct->rcItem;
	if (lpDrawItemStruct->itemState & ODS_SELECTED){
		//绘制按钮按下时的颜色
		pDc->SelectObject(&m_activeBrush);
	}
	//画椭圆按钮
	pDc->Ellipse(&rct);
	//设置背景色
	pDc->SetBkMode(TRANSPARENT);

	CString strText{};
	GetWindowText(strText);
	pDc->DrawText(strText, rct, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	pDc->RestoreDC(nSaveDc);
}


void CRoundButton::PreSubclassWindow()
{
	// TODO: 在此添加专用代码和/或调用基类
	ModifyStyle(0, BS_OWNERDRAW);
	CRgn rgn;
	CRect rct;
	GetClientRect(&rct);
	//在按钮矩形内创建椭圆区域
	rgn.CreateEllipticRgnIndirect(&rct);
	//将椭圆区域应用到按钮上
	::SetWindowRgn(GetSafeHwnd(), (HRGN)rgn, true);

	CButton::PreSubclassWindow();
}
