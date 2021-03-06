
// trafficlightvcDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "trafficlightvc.h"
#include "trafficlightvcDlg.h"
#include "afxdialogex.h"
#include "CSetLightTimesDlg.h"
#include "CQuestDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CtrafficlightvcDlg 对话框


CtrafficlightvcDlg::CtrafficlightvcDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TRAFFICLIGHTVC_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CtrafficlightvcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RED, m_btn_red);
	DDX_Control(pDX, IDC_GREEN, m_btn_green);
}

BEGIN_MESSAGE_MAP(CtrafficlightvcDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_START, &CtrafficlightvcDlg::OnBnClickedStart)
	ON_BN_CLICKED(IDC_STOP, &CtrafficlightvcDlg::OnBnClickedStop)
	ON_BN_CLICKED(IDC_SET, &CtrafficlightvcDlg::OnBnClickedSet)
	ON_BN_CLICKED(IDC_QUESTASK, &CtrafficlightvcDlg::OnBnClickedQuestask)
END_MESSAGE_MAP()


// CtrafficlightvcDlg 消息处理程序

BOOL CtrafficlightvcDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CtrafficlightvcDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CtrafficlightvcDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CtrafficlightvcDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CtrafficlightvcDlg::SetColor(int xID, PainColor painColor, int num) {
    
    CWnd* pWnd = GetDlgItem(xID);//在图象控件中设圆形状态指示灯
    CDC* pDC = pWnd->GetDC();
	CRect conRect;
    ::GetClientRect(pWnd->m_hWnd, conRect);
    CBrush NewBrush(painColor== RED ? (COLORREF)0x000FF0 : (COLORREF)0x00FF00);//指示灯为color色
    CBrush* pOldBrush = pDC->SelectObject(&NewBrush);
    pDC->SetViewportOrg(conRect.right / 2, conRect.bottom / 2);
    CRect rct;
	CRoundButton::GetDefaulRect(rct);
    pDC->Ellipse(rct);
    pDC->SelectObject(pOldBrush);

	/*CRoundButton* crBtn = (CRoundButton*)pWnd;
	crBtn->DrawRoundShape(painColor);
	CRect rct;
	crBtn->GetDefaulRect(rct);*/
    CString strText;
	if (0 != num){
		strText.Format("%d", num);
	}
	pDC->DrawText(strText, rct, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    pWnd->ReleaseDC(pDC);
}

void CtrafficlightvcDlg::SetColorDefault(int xID) {
	CWnd* pWnd = GetDlgItem(xID);//在图象控件中设圆形状态指示灯
	CRoundButton* crBtn = (CRoundButton*)pWnd;
	crBtn->DrawRoundShape(DEFAULT);
}

static void ThreadProc(void* argc) {
	CtrafficlightvcDlg* pDlg = (CtrafficlightvcDlg*)argc;
    while (!pDlg->stop_) {
        for (int idx = pDlg->GetRedTimes(); idx >= 0 && !pDlg->stop_; idx--) {
			pDlg->SetColor(IDC_RED, RED, idx);//red
            Sleep(999);
        }
		pDlg->SetColorDefault(IDC_RED);

        for (int idx = pDlg->GetGreenTimes(); idx >= 0 && !pDlg->stop_; idx--) {
			pDlg->SetColor(IDC_GREEN, GREEN, idx);//green
            Sleep(999);
        }
		pDlg->SetColorDefault(IDC_GREEN);
    }
	pDlg->SetColorDefault(IDC_RED);
	pDlg->SetColorDefault(IDC_GREEN);
}

void CtrafficlightvcDlg::OnBnClickedStart()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!stop_){
		//提示线程还未退出
		return;
	}
	stop_ = false;
	_beginthread(ThreadProc, 0, this);
}


void CtrafficlightvcDlg::OnBnClickedStop()
{
	// TODO: 在此添加控件通知处理程序代码
	stop_ = true;
}


void CtrafficlightvcDlg::OnBnClickedSet()
{
	// TODO: 在此添加控件通知处理程序代码
	CSetLightTimesDlg dlg(this);
	if (IDOK == dlg.DoModal()) {
		stop_ = true;
		Sleep(1500);

		OnBnClickedStart();
	}
}

void CtrafficlightvcDlg::OnBnClickedQuestask()
{
	// TODO: 在此添加控件通知处理程序代码
	CQuestDlg dlg(this);
    if (IDOK == dlg.DoModal()) {
		AfxMessageBox(m_askResult);
    }
}
