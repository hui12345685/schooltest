// CQuestDlg.cpp: 实现文件
//

#include "pch.h"
#include "trafficlightvc.h"
#include "CQuestDlg.h"
#include "afxdialogex.h"
#include "CQuestionBank.h"
#include "trafficlightvcDlg.h"

// CQuestDlg 对话框

IMPLEMENT_DYNAMIC(CQuestDlg, CDialogEx)

CQuestDlg::CQuestDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_QUESTION, pParent)
{

}

CQuestDlg::~CQuestDlg()
{
}

void CQuestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_QUESTION1, m_question1);
	DDX_Control(pDX, IDC_QUESTION2, m_question2);
	DDX_Control(pDX, IDC_QUESTION3, m_question3);
	DDX_Control(pDX, IDC_RADIO1, m_question1_ask1);
	DDX_Control(pDX, IDC_RADIO2, m_question1_ask2);
	DDX_Control(pDX, IDC_RADIO3, m_question2_ask1);
	DDX_Control(pDX, IDC_RADIO4, m_question2_ask2);
	DDX_Control(pDX, IDC_RADIO5, m_question3_ask1);
	DDX_Control(pDX, IDC_RADIO6, m_question3_ask2);
}

BEGIN_MESSAGE_MAP(CQuestDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CQuestDlg::OnBnClickedOk)
END_MESSAGE_MAP()

// CQuestDlg 消息处理程序

static CString GetSelectAsk(CButton& ask1, CButton& ask2) {
	CString sel;
	if (ask1.GetCheck()){
		ask1.GetWindowText(sel);
	}
	else if (ask2.GetCheck()) {
		ask2.GetWindowText(sel);
	}
	return sel;
}

void CQuestDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strSelAsk1 = GetSelectAsk(m_question1_ask1, m_question1_ask2);
	CString strSelAsk2 = GetSelectAsk(m_question2_ask1, m_question2_ask2);
	CString strSelAsk3 = GetSelectAsk(m_question3_ask1, m_question3_ask2);
	
    CString strQuestion1;
    CString selQuestion2;
    CString selQuestion3;
	m_question1.GetWindowText(strQuestion1);
	m_question2.GetWindowText(selQuestion2);
	m_question3.GetWindowText(selQuestion3);
	CtrafficlightvcDlg* pDlg = (CtrafficlightvcDlg*)GetParent();
	if (strSelAsk1 == m_question1Answer && strSelAsk2 == m_question2Answer && strSelAsk3 == m_question3Answer){
		pDlg->SetAskResult("你很棒，全部回答正确！");
	}
	else {
		CString strAskRst;
        if (strSelAsk1 == m_question1Answer) {
			strAskRst = strQuestion1 + "所选答案：" + strSelAsk1 + " : 回答正确。\n\n";
        }
        else {
			strAskRst = strQuestion1 + "所选答案：" + strSelAsk1 + " : 回答错误。\n\n";
        }
        if (strSelAsk2 == m_question2Answer) {
            strAskRst = strAskRst + selQuestion2 + "所选答案：" + strSelAsk2 + " : 回答正确。\n\n";
        }
        else {
            strAskRst = strAskRst + selQuestion2 + "所选答案：" + strSelAsk2 +  " : 回答错误。\n\n";
        }
        if (strSelAsk3 == m_question3Answer) {
            strAskRst = strAskRst + selQuestion3 + "所选答案：" + strSelAsk3 + " : 回答正确。\n\n";
        }
        else {
            strAskRst = strAskRst + selQuestion3 + "所选答案：" + strSelAsk3 + " : 回答错误。\n\n";
        }
		pDlg->SetAskResult(strAskRst);
	}
	
	CDialogEx::OnOK();
}


BOOL CQuestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	UpdateData(TRUE);
	// TODO:  在此添加额外的初始化
	//默认是3个问题
	std::vector<QuestionAndAnswer*>asks = QuestionMgr::GetInst().RandQuests();
	if (asks.size() >= 1){
        m_question1.SetWindowText(asks[0]->Question);
        m_question1_ask1.SetWindowText(asks[0]->Answer1);
        m_question1_ask2.SetWindowText(asks[0]->Answer2);
        m_question1Answer = asks[0]->CorrectAnswer;
	}

    if (asks.size() >= 2) {
        m_question2.SetWindowText(asks[1]->Question);
        m_question2_ask1.SetWindowText(asks[1]->Answer1);
        m_question2_ask2.SetWindowText(asks[1]->Answer2);
        m_question2Answer = asks[1]->CorrectAnswer;
    }

    if (asks.size() >= 3) {
        m_question3.SetWindowText(asks[2]->Question);
        m_question3_ask1.SetWindowText(asks[2]->Answer1);
        m_question3_ask2.SetWindowText(asks[2]->Answer2);
        m_question3Answer = asks[2]->CorrectAnswer;
    }

	//设置默认选中
	m_question1_ask1.SetCheck(1);
	m_question2_ask1.SetCheck(1);
	m_question3_ask1.SetCheck(1);

	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
