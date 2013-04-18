// Sort.cpp : ʵ���ļ�
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

// GPA �Ի���

IMPLEMENT_DYNAMIC(GPA, CDialog)

GPA::GPA(CWnd* pParent /*=NULL*/)
	: CDialog(GPA::IDD, pParent)
{
	
}


GPA::~GPA()
{
	 // TODO: �ڴ���ӿؼ�֪ͨ����������  
  
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


// GPA ��Ϣ�������


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
  pDC->SetBkMode(TRANSPARENT);   //���ñ���͸��
  pDC->SetTextColor(RGB(240,240,240));
  return   HBRUSH(GetStockObject(HOLLOW_BRUSH));   
  
 }   
	// TODO:  �ڴ˸��� DC ���κ�����

	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
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

//��������
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
    AfxMessageBox(L"�޷�����Excel������!");  
    return;  
    }  
    books.AttachDispatch(app.get_Workbooks());  
    lpDisp = books.Open(strbook,covOptional, covOptional, covOptional, covOptional, covOptional,covOptional, covOptional, covOptional, covOptional, covOptional,covOptional, covOptional, covOptional,covOptional);  
      
    //�õ�Workbook  
    book.AttachDispatch(lpDisp);  
    //�õ�Worksheets  
    sheets.AttachDispatch(book.get_Worksheets());  
   
    //�õ���ǰ��Ծsheet  
    //����е�Ԫ�������ڱ༭״̬�У��˲������ܷ��أ���һֱ�ȴ�  
    lpDisp=book.get_ActiveSheet();  
    sheet.AttachDispatch(lpDisp);  
    //��ȡ��һ����Ԫ���ֵ
	int i=2;
	int n=0;
	double a[9999];
	do{
    range.AttachDispatch(sheet.get_Cells());  
    range.AttachDispatch(range.get_Item (COleVariant((long)i),COleVariant((long)1)).pdispVal );  
    /*COleVariant*/ vResult =range.get_Value2();  
    CString str;  
    if(vResult.vt == VT_BSTR) //�ַ���  
    {  
    str=vResult.bstrVal;  
    }  
    else if (vResult.vt==VT_R8) //8�ֽڵ�����  
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
    app.Quit();             // �˳�  
    //�ͷŶ���    
    range.ReleaseDispatch();  
    sheet.ReleaseDispatch();  
    sheets.ReleaseDispatch();  
    book.ReleaseDispatch();  
    books.ReleaseDispatch();  
    app.ReleaseDispatch();  

	AfxMessageBox(L"Success!\nPlease check your data in Data.xlsx.");
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void GPA::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialog::OnOK();
}

