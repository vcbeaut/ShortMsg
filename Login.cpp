// Login.cpp : 实现文件
//

#include "stdafx.h"
#include "ShortMsg.h"
#include "Login.h"
#include "afxdialogex.h"


// CLogin 对话框

IMPLEMENT_DYNAMIC(CLogin, CDialogEx)

CLogin::CLogin(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLogin::IDD, pParent)
{

}

CLogin::~CLogin()
{
}

void CLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CLogin, CDialogEx)
	ON_BN_CLICKED(ID_LOGIN, &CLogin::OnBnClickedLogin)
END_MESSAGE_MAP()


// CLogin 消息处理程序

void CLogin::OnBnClickedLogin()
{
	// TODO:  在此添加控件通知处理程序代码
	/*CString username,password;
	this->GetDlgItemTextW(IDC_EDIT_USER, username);
	this->GetDlgItemTextW(IDC_EDIT_PWD, password);
	if (username == _T("tianlu") && password == _T("123!!")){
		OnOK();
	}
	else
	{
		MessageBox(_T("username or password false!!"));
	}*/
	OnOK();
}
