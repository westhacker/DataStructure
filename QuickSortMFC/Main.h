
// SJTUGPA.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CSJTUGPAApp:
// �йش����ʵ�֣������ SJTUGPA.cpp
//

class CSJTUGPAApp : public CWinApp
{
public:
	CSJTUGPAApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CSJTUGPAApp theApp;