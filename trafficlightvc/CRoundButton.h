#pragma once
#include <afxwin.h>
class CRoundButton :
    public CButton
{
public:
    CRoundButton();
    ~CRoundButton();
    virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
    virtual void PreSubclassWindow();
protected:
    CBrush m_normalBrush;
    CPen m_Pen;
    CBrush m_activeBrush;
};

