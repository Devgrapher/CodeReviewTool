
// CodeReviewTool.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CCodeReviewToolApp:
// �� Ŭ������ ������ ���ؼ��� CodeReviewTool.cpp�� �����Ͻʽÿ�.
//

class CCodeReviewToolApp : public CWinApp
{
public:
	CCodeReviewToolApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CCodeReviewToolApp theApp;