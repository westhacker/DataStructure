#pragma once


// GPA �Ի���

class GPA : public CDialog
{
	DECLARE_DYNAMIC(GPA)

public:
	GPA(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~GPA();

// �Ի�������
	enum { IDD = IDD_GPA };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
//	CButton m_btn1;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedOk();
};
