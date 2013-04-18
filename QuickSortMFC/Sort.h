#pragma once


// GPA 对话框

class GPA : public CDialog
{
	DECLARE_DYNAMIC(GPA)

public:
	GPA(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~GPA();

// 对话框数据
	enum { IDD = IDD_GPA };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
//	CButton m_btn1;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedOk();
};
