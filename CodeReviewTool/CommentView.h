#pragma once

#define IDC_CODERICHEDIT 101
#define IDC_NUMRICHEDIT 102

#define LINELENGTH 30
// CCommentView ���Դϴ�.
#include "RichEditor.h"

class CCommentView : public CView
{
	DECLARE_DYNCREATE(CCommentView)
protected:
	CRichEditor m_codeRichEdit;
	LPWSTR m_cmtSourceCode;

	LONG m_numberEditCtrlWidth;
	int m_maxLineNumber;

protected:
	CCommentView();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
	virtual ~CCommentView();
public:
	virtual void OnDraw(CDC* pDC);      // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);

public:
	void SetCmtSourceCode(LPTSTR sourceCode);
	LPWSTR GetCmtSourceCode();
	int GetCmtSourceCodeLength();
	void SrcLineCount();
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);

	void PrintSourceCode(CString sourceCode);
};

