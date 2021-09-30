#include "pch.h"
#include "CRoundButton.h"

CRoundButton::CRoundButton() {
	m_Pen.CreatePen(PS_SOLID, 1, RGB(201, 201, 233));
	m_normalBrush.CreateSolidBrush(RGB(231, 231, 231));
}

CRoundButton::~CRoundButton() {
    m_Pen.DeleteObject();
    m_normalBrush.DeleteObject();
}

void CRoundButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	// TODO:  添加您的代码以绘制指定项
	CDC* pDc = this->GetDC();
	//存储设备当前环境
	int nSaveDc = pDc->SaveDC();
	//选择按钮默认状态下的画刷
	pDc->SelectObject(&m_normalBrush);
	//选择画笔
	pDc->SelectObject(&m_Pen);
	
	//获取按钮矩形区域
	CRect conRect;
	::GetClientRect(this->m_hWnd, conRect);
	//设置坐标偏移值
	pDc->SetViewportOrg(conRect.right / 2, conRect.bottom / 2);

    //画圆形按钮
	CRect rct;
	rct.left = -22;
	rct.top = -22;
	rct.right = 22;
	rct.bottom = 22;
    pDc->Ellipse(rct);
	//设置背景色
	pDc->SetBkMode(TRANSPARENT);

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
