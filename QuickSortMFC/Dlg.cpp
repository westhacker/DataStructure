
// SJTUGPADlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Main.h"
#include "Dlg.h"
#include "afxdialogex.h"
#include "CApplication.h"  
#include "CRange.h"  
#include "CRanges.h"
#include "CWorkbook.h"  
#include "CWorkbooks.h"  
#include "CWorksheet.h"  
#include "CWorksheets.h"
#include "Sort.h"

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
public:
//	afx_msg void OnPaint();
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
//	ON_WM_PAINT()
END_MESSAGE_MAP()


// CSJTUGPADlg 对话框




CSJTUGPADlg::CSJTUGPADlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSJTUGPADlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

void CSJTUGPADlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON2, m_btn);
}

BEGIN_MESSAGE_MAP(CSJTUGPADlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CSJTUGPADlg::OnBnClickedButton1)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON2, &CSJTUGPADlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CSJTUGPADlg 消息处理程序

BOOL CSJTUGPADlg::OnInitDialog()
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CSJTUGPADlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CSJTUGPADlg::OnPaint()
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
		//CDialog::OnPaint();
		 CPaintDC   dc(this);   

          CRect   rect;   

          GetClientRect(&rect);   

          CDC   dcMem;   

          dcMem.CreateCompatibleDC(&dc);   

          CBitmap   bmpBackground;   

          bmpBackground.LoadBitmap(IDB_BITMAP2);                  

          BITMAP   bitmap;   

          bmpBackground.GetBitmap(&bitmap);   

          CBitmap   *pbmpOld=dcMem.SelectObject(&bmpBackground);   

          dc.StretchBlt(0,0,rect.Width(),rect.Height(),&dcMem,0,0,   

         bitmap.bmWidth,bitmap.bmHeight,SRCCOPY);  

	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CSJTUGPADlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSJTUGPADlg::OnBnClickedButton1()
{ 
   
	GPA gpadlg;
	gpadlg.DoModal();
}  


	




HBRUSH CSJTUGPADlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	 if( nCtlColor == CTLCOLOR_STATIC)     
 {   
  pDC->SetBkMode(TRANSPARENT);   //设置背景透明
  pDC->SetTextColor(RGB(240,240,240));
  return   HBRUSH(GetStockObject(HOLLOW_BRUSH));   
  
 }   
	
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}


void CSJTUGPADlg::OnBnClickedButton2()
{
	ShellExecute(NULL, _T("open"), _T("http://zhuoyue.eu5.org/drupal/"), NULL, NULL, SW_SHOWNORMAL); 
	// TODO: 在此添加控件通知处理程序代码
}
