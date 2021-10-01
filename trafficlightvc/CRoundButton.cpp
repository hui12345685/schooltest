#include "pch.h"
#include "CRoundButton.h"

CRoundButton::CRoundButton() {
	//m_normalBrush.CreateSolidBrush(RGB(231, 231, 231));
}

CRoundButton::~CRoundButton() {
    m_normalBrush.DeleteObject();
}

void CRoundButton::GetDefaulRect(CRect& rct) {
    rct.left = -22;
    rct.top = -22;
    rct.right = 22;
    rct.bottom = 22;
}

void CRoundButton::DrawRoundShape(PainColor painColor) {
    CDC* pDc = this->GetDC();
    //�洢�豸��ǰ����
    switch (painColor)
    {
    case DEFAULT:
        //ѡ��ťĬ��״̬�µĻ�ˢ
        pDc->SelectObject(&m_normalBrush);
        break;
    case RED:{
        //ѡ��ťʹ�ú�ɫ��ˢ
        CBrush NewBrush((COLORREF)0x000FF0);
        pDc->SelectObject(&NewBrush);
        break;
    }
    case GREEN:{
        //ѡ��ťʹ����ɫ��ˢ
        CBrush NewBrush((COLORREF)0x00FF00);
        pDc->SelectObject(&NewBrush);
        break;
    }
    default:
        return;
    }
    
    //��ȡ��ť��������
    CRect conRect;
    ::GetClientRect(this->m_hWnd, conRect);
    //��������ƫ��ֵ
    pDc->SetViewportOrg(conRect.right / 2, conRect.bottom / 2);
    //��Բ�ΰ�ť
    CRect rct;
    GetDefaulRect(rct);
    pDc->Ellipse(rct);
}

void CRoundButton::DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/)
{
	// TODO:  ������Ĵ����Ի���ָ����
    DrawRoundShape();
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
