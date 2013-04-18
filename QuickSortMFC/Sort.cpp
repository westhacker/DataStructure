// Sort.cpp : 实现文件
// 

#include "stdafx.h"
#include "Main.h"
#include "Sort.h"
#include "afxdialogex.h"
#include "CApplication.h"  
#include "CRange.h"  
#include "CRanges.h"
#include "CWorkbook.h"  
#include "CWorkbooks.h"  
#include "CWorksheet.h"  
#include "CWorksheets.h"
#include "stack.h"

// GPA 对话框

IMPLEMENT_DYNAMIC(GPA, CDialog)

GPA::GPA(CWnd* pParent /*=NULL*/)
	: CDialog(GPA::IDD, pParent)
{
	
}


GPA::~GPA()
{
	 // TODO: 在此添加控件通知处理程序代码  
  
}

void GPA::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	
}


BEGIN_MESSAGE_MAP(GPA, CDialog)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON2, &GPA::OnBnClickedButton2)
	ON_BN_CLICKED(IDOK, &GPA::OnBnClickedOk)
END_MESSAGE_MAP()


// GPA 消息处理程序


void GPA::OnPaint()
{ CPaintDC   dc(this);   

          CRect   rect;   

          GetClientRect(&rect);   

          CDC   dcMem;   

          dcMem.CreateCompatibleDC(&dc);   

          CBitmap   bmpBackground;   

          bmpBackground.LoadBitmap(IDB_BITMAP3);                  

          BITMAP   bitmap;   

          bmpBackground.GetBitmap(&bitmap);   

          CBitmap   *pbmpOld=dcMem.SelectObject(&bmpBackground);   

          dc.StretchBlt(0,0,rect.Width(),rect.Height(),&dcMem,0,0,   

         bitmap.bmWidth,bitmap.bmHeight,SRCCOPY);  
		  
}


HBRUSH GPA::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	 if( nCtlColor == CTLCOLOR_STATIC)     
 {   
  pDC->SetBkMode(TRANSPARENT);   //设置背景透明
  pDC->SetTextColor(RGB(240,240,240));
  return   HBRUSH(GetStockObject(HOLLOW_BRUSH));   
  
 }   
	// TODO:  在此更改 DC 的任何特性

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}
CString GetModulePath(){
    TCHAR lpszFileName[MAX_PATH+1];
    ::GetModuleFileName(NULL,lpszFileName,MAX_PATH+1);
    CString sModulePath = lpszFileName;
    int index = sModulePath.ReverseFind('\\');
    sModulePath = sModulePath.Left(index+1);
    long len = sModulePath.GetLength();
    #ifdef _DEBUG
        CString dbg = sModulePath.Right(6);
        dbg.MakeUpper();
        if(dbg == "DEBUG\\")
            sModulePath = sModulePath.Left(len-6);
    #else
        CString dbg = sModulePath.Right(8);
        dbg.MakeUpper();
        if(dbg == "RELEASE\\")
            sModulePath = sModulePath.Left(len-8);
    #endif
    return sModulePath;
	}

//快速排序
int partion(int a[],int low,int high)
{
int temp=a[low];
do{
while(low<high&&a[high]>=temp)high--;
if(low<high){a[low]=a[high];low++;}
while(low<high&&a[low]<=temp)low++;
if(low<high){a[high]=a[low];high--;}
}
while(low!=high);
a[low]=temp;
return low;
}

void quicksort(int a[],int n)
{
Stack<int> qt;
qt.push(n-1);
qt.push(0);
while(!qt.empty())
{
	int low=qt.pop();
	int high=qt.pop();
	int mid=partion(a,low,high);
	if(low<mid)
	{
		qt.push(mid-1);
		qt.push(low);
	}
	if(mid<high)
	{
		qt.push(high);
		qt.push(mid+1);
	}
}
}

void double2Variant(double dData,VARIANT &va)
{
va.vt = VT_R8;
va.dblVal = dData;
}

void GPA::OnBnClickedButton2()
{  CApplication app;  
    CWorkbooks books;  
    CWorkbook book;  
    CWorksheets sheets;  
    CWorksheet sheet;  
    CRange range;  
	CRanges ranges;
    CRange iCell;  
	CString strbook,szzxf,szzcj,szgpa,szjd,szzc,gpa7;

	

	strbook=GetModulePath()+_T("Data.xlsx");
    LPDISPATCH lpDisp;  
    COleVariant vResult;  
    COleVariant covOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR);  
    if(!app.CreateDispatch(L"Excel.Application"))  
    {  
    AfxMessageBox(L"无法启动Excel服务器!");  
    return;  
    }  
    books.AttachDispatch(app.get_Workbooks());  
    lpDisp = books.Open(strbook,covOptional, covOptional, covOptional, covOptional, covOptional,covOptional, covOptional, covOptional, covOptional, covOptional,covOptional, covOptional, covOptional,covOptional);  
      
    //得到Workbook  
    book.AttachDispatch(lpDisp);  
    //得到Worksheets  
    sheets.AttachDispatch(book.get_Worksheets());  
   
    //得到当前活跃sheet  
    //如果有单元格正处于编辑状态中，此操作不能返回，会一直等待  
    lpDisp=book.get_ActiveSheet();  
    sheet.AttachDispatch(lpDisp);  
    //读取第一个单元格的值
	int i=2;
	int n=0;
	double a[9999];
	do{
    range.AttachDispatch(sheet.get_Cells());  
    range.AttachDispatch(range.get_Item (COleVariant((long)i),COleVariant((long)1)).pdispVal );  
    /*COleVariant*/ vResult =range.get_Value2();  
    CString str;  
    if(vResult.vt == VT_BSTR) //字符串  
    {  
    str=vResult.bstrVal;  
    }  
    else if (vResult.vt==VT_R8) //8字节的数字  
    {  
    str.Format(L"%f",vResult.dblVal);  
    }  
	a[i-2]=_ttof(str);
	n++;
	i++;
	}while(vResult.vt!=VT_EMPTY);

	quicksort(a,n);

	i=3;
	do{
    range.AttachDispatch(sheet.get_Cells());  
    range.AttachDispatch(range.get_Item (COleVariant((long)i-1),COleVariant((long)2)).pdispVal );  
    /*COleVariant*/ vResult =range.get_Value2();  
    CString str;
	VARIANT tmp;
	double2Variant(a[i-2],tmp);
	range.put_Value2(tmp);
	i++;
	}while(i<n+2);

	

    books.Close();   
    app.Quit();             // 退出  
    //释放对象    
    range.ReleaseDispatch();  
    sheet.ReleaseDispatch();  
    sheets.ReleaseDispatch();  
    book.ReleaseDispatch();  
    books.ReleaseDispatch();  
    app.ReleaseDispatch();  

	AfxMessageBox(L"Success!\nPlease check your data in Data.xlsx.");
	// TODO: 在此添加控件通知处理程序代码
}


void GPA::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialog::OnOK();
}

