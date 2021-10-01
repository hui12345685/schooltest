#pragma once


// CSetLightTimesDlg 对话框

class CSetLightTimesDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSetLightTimesDlg)

public:
	CSetLightTimesDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CSetLightTimesDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SET };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CEdit m_redEdt;
	CEdit m_greenEdt;
	virtual BOOL OnInitDialog();
};
