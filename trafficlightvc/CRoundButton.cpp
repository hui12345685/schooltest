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
	// TODO:  ������Ĵ����Ի���ָ����
	CDC* pDc = this->GetDC();
	//�洢�豸��ǰ����
	int nSaveDc = pDc->SaveDC();
	//ѡ��ťĬ��״̬�µĻ�ˢ
	pDc->SelectObject(&m_normalBrush);
	//ѡ�񻭱�
	pDc->SelectObject(&m_Pen);
	
	//��ȡ��ť��������
	CRect conRect;
	::GetClientRect(this->m_hWnd, conRect);
	//��������ƫ��ֵ
	pDc->SetViewportOrg(conRect.right / 2, conRect.bottom / 2);

    //��Բ�ΰ�ť
	CRect rct;
	rct.left = -22;
	rct.top = -22;
	rct.right = 22;
	rct.bottom = 22;
    pDc->Ellipse(rct);
	//���ñ���ɫ
	pDc->SetBkMode(TRANSPARENT);

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
