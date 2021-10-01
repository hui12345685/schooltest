#pragma once
#include <afxwin.h>

enum PainColor
{
    DEFAULT = 0,
    RED =1,
    GREEN = 2
};

class CRoundButton :
    public CButton
{
public:
    CRoundButton();
    ~CRoundButton();
    void DrawRoundShape(PainColor painColor = DEFAULT);
    static void GetDefaulRect(CRect& rct);
    virtual void DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/);
    virtual void PreSubclassWindow();
protected:
    CBrush m_normalBrush;
};

