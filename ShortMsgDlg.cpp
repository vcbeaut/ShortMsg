
// ShortMsgDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ShortMsg.h"
#include "ShortMsgDlg.h"
#include "afxdialogex.h"
#include "Txtdeal.h"
#include "Encode.h"
#include "strCoding.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CShortMsgDlg 对话框



CShortMsgDlg::CShortMsgDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CShortMsgDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CShortMsgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_INDEX, m_lst);
}

BEGIN_MESSAGE_MAP(CShortMsgDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CShortMsgDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON_OPENFILE, &CShortMsgDlg::OnBnClickedButtonOpenfile)
END_MESSAGE_MAP()


// CShortMsgDlg 消息处理程序

BOOL CShortMsgDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// TODO:  在此添加额外的初始化代码
	m_lst.InsertColumn(0, _T("序号"), LVCFMT_CENTER, 50);
	m_lst.InsertColumn(1, _T("手机号"), LVCFMT_CENTER, 130);
	m_lst.InsertColumn(2, _T("状态"), LVCFMT_CENTER, 130);
	this->SetDlgItemTextW(IDC_EDIT_THREAD, _T("1"));
	this->SetDlgItemTextW(IDC_EDIT_SUMTHREAD, _T("10"));
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CShortMsgDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CShortMsgDlg::OnPaint()
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
HCURSOR CShortMsgDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CShortMsgDlg::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	/*string tempstr = "上海";
	CString t_Str;
	strCoding strCd;
	tempstr = strCd.UrlUTF8((char *)tempstr.c_str());
	t_Str = tempstr.c_str();
	MessageBox(t_Str);*/
	MessageBox(_T("待更新！！"));
	//CDialogEx::OnOK();
}

void CShortMsgDlg::OnBnClickedButtonOpenfile()
{
	// TODO:  在此添加控件通知处理程序代码
	CFileDialog cfdlg(TRUE);
	CString csPathName;
	if (cfdlg.DoModal() == IDOK){
		csPathName = cfdlg.GetPathName();
	}

	CFile c_File;
	wchar_t w_str[1024];
	char r_str[1024];
	memset(r_str, '\0', 1024);
	if (!c_File.Open(csPathName, CFile::modeReadWrite)){
		MessageBox(_T("文件打开失败！"));
		return;
	}
	else{
		c_File.Read(r_str, 1024);
	}
	c_File.Close();
	C2W(r_str, w_str, 1024);
	CString c_Str = w_str;
	vector<CString> vecStr;
	vecStr = spiltcstring(c_Str, _T("\n"));
	int r_Index;
	CString s_Index;
	for (int i = 0; i < vecStr.size(); i++){
		s_Index.Format(_T("%d"), i+1);
		r_Index = m_lst.InsertItem(i, s_Index);
		m_lst.SetItemText(r_Index, 1, vecStr[i]);
		s_Index.Empty();
	}
}



