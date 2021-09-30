﻿
// trafficlightvcDlg.h: 头文件
//

#pragma once

#include "CRoundButton.h"

// CtrafficlightvcDlg 对话框
class CtrafficlightvcDlg : public CDialogEx
{
// 构造
public:
	CtrafficlightvcDlg(CWnd* pParent = nullptr);	// 标准构造函数

	void State(int xID, int color, int num);

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TRAFFICLIGHTVC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedStart();
	CRoundButton m_btn_red;
	CRoundButton m_btn_green;

	bool stop_ = true ;
	afx_msg void OnBnClickedStop();
};
