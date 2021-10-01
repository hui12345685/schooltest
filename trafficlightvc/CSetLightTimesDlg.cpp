// CSetLightTimesDlg.cpp: 实现文件
//

#include "pch.h"
#include "trafficlightvc.h"
#include "CSetLightTimesDlg.h"
#include "afxdialogex.h"
#include "trafficlightvcDlg.h"

// CSetLightTimesDlg 对话框

IMPLEMENT_DYNAMIC(CSetLightTimesDlg, CDialogEx)

CSetLightTimesDlg::CSetLightTimesDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SET, pParent)
{
}

CSetLightTimesDlg::~CSetLightTimesDlg()
{
}

void CSetLightTimesDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RED_TIMES, m_redEdt);
	DDX_Control(pDX, IDC_GREEN_TIMES, m_greenEdt);
}


BEGIN_MESSAGE_MAP(CSetLightTimesDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CSetLightTimesDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CSetLightTimesDlg 消息处理程序
void CSetLightTimesDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strRedTimes;
	m_redEdt.GetWindowText(strRedTimes);

	CString strGreenTimes;
	m_greenEdt.GetWindowText(strGreenTimes);

	CtrafficlightvcDlg* pDlg = (CtrafficlightvcDlg*)GetParent();
	pDlg->SetRedTimes(atoi(strRedTimes));
	pDlg->SetGreenTimes(atoi(strGreenTimes));

	CDialogEx::OnOK();
}


BOOL CSetLightTimesDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
    CtrafficlightvcDlg* pDlg = (CtrafficlightvcDlg*)GetParent();

    CString strRedTimes;
    strRedTimes.Format("%d", pDlg->GetRedTimes());
    m_redEdt.SetWindowText(strRedTimes);

    CString strGreenTimes;
    strGreenTimes.Format("%d", pDlg->GetGreenTimes());
    m_greenEdt.SetWindowText(strGreenTimes);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
