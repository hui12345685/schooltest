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
	// TODO:  ������Ĵ����Ի���ָ����
	CDC* pDc = CDC::FromHandle(lpDrawItemStruct->hDC);
	//�洢�豸��ǰ����
	int nSaveDc = pDc->SaveDC();
	//ѡ��ťĬ��״̬�µĻ�ˢ
	pDc->SelectObject(&m_normalBrush);
	//ѡ�񻭱�
	pDc->SelectObject(&m_Pen);
	//��ȡ��ť��������
	CRect rct = lpDrawItemStruct->rcItem;
	if (lpDrawItemStruct->itemState & ODS_SELECTED){
		//���ư�ť����ʱ����ɫ
		pDc->SelectObject(&m_activeBrush);
	}
	//����Բ��ť
	pDc->Ellipse(&rct);
	//���ñ���ɫ
	pDc->SetBkMode(TRANSPARENT);

	CString strText{};
	GetWindowText(strText);
	pDc->DrawText(strText, rct, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	pDc->RestoreDC(nSaveDc);
}


void CRoundButton::PreSubclassWindow()
{
	// TODO: �ڴ����ר�ô����/����û���
	ModifyStyle(0, BS_OWNERDRAW);
	CRgn rgn;
	CRect rct;
	GetClientRect(&rct);
	//�ڰ�ť�����ڴ�����Բ����
	rgn.CreateEllipticRgnIndirect(&rct);
	//����Բ����Ӧ�õ���ť��
	::SetWindowRgn(GetSafeHwnd(), (HRGN)rgn, true);

	CButton::PreSubclassWindow();
}
