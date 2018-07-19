
// ShortMsgDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"


// CShortMsgDlg 对话框
class CShortMsgDlg : public CDialogEx
{
// 构造
public:
	CShortMsgDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_ShortMsg_DIALOG };

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
	afx_msg void OnBnClickedOk();
	CListCtrl m_lst;
	afx_msg void OnBnClickedButtonOpenfile();
};
