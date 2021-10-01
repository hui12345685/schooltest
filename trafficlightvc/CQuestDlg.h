#pragma once

// CQuestDlg 对话框

class CQuestDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CQuestDlg)

public:
	CQuestDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CQuestDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_QUESTION };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	CStatic m_question1;
	CStatic m_question2;
	CStatic m_question3;
	CButton m_question1_ask1;
	CButton m_question1_ask2;
	CButton m_question2_ask1;
	CButton m_question2_ask2;
	CButton m_question3_ask1;
	CButton m_question3_ask2;

    CString m_question1Answer;
	CString m_question2Answer;
	CString m_question3Answer;
};
