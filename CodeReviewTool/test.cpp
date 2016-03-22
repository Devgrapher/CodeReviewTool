// CommentView.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "CodeReviewTool.h"
#include "CommentView.h"


// CCommentView

IMPLEMENT_DYNCREATE(CCommentView, CView)

CCommentView::CCommentView()
{
	m_cmtSourceCode = NULL;
	m_numberEditCtrlWidth = 0;
	m_maxLineNumber = 0;
}

CCommentView::~CCommentView()
{
}

BEGIN_MESSAGE_MAP(CCommentView, CView)
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CCommentView �׸����Դϴ�.

void CCommentView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: ���⿡ �׸��� �ڵ带 �߰��մϴ�.
}


// CCommentView �����Դϴ�.

#ifdef _DEBUG
void CCommentView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CCommentView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CCommentView �޽��� ó�����Դϴ�.


int CCommentView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.
	CRect cr;
	GetClientRect(&cr);

	m_codeRichEdit.Create(WS_CHILD | WS_VISIBLE | ES_AUTOVSCROLL | ES_AUTOHSCROLL | ES_MULTILINE |
		WS_VSCROLL | WS_HSCROLL,
		cr, this, IDC_CODERICHEDIT);

	//m_codeRichEdit.SetEventMask(m_codeRichEdit.GetEventMask() | ENM_UPDATE);

	CHARFORMAT cf;
	cf.cbSize = sizeof(cf);
	cf.dwEffects = CFE_PROTECTED;
	cf.dwMask = CFM_BOLD | CFM_ITALIC | CFM_STRIKEOUT | CFM_UNDERLINE | CFM_FACE | CFM_SIZE | CFM_CHARSET | CFM_PROTECTED | CFM_COLOR;
	cf.yHeight = 200;
	cf.crTextColor = RGB(0, 0, 0);
	cf.bCharSet = HANGEUL_CHARSET;
	m_codeRichEdit.SetDefaultCharFormat(cf);

	m_codeRichEdit.SendMessage(EM_SETMARGINS, EC_LEFTMARGIN, 35 & 0xFFFF);
	return 0;
}


void CCommentView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	CRect cr;
	GetClientRect(&cr);

	m_codeRichEdit.MoveWindow(&cr, 1);
}

void CCommentView::SetCmtSourceCode(LPTSTR sourceCode)
{
	// ����ó�� �ʿ� NULL���� �ƴ���.
	m_cmtSourceCode = sourceCode;

	m_codeRichEdit.SetWindowTextW(m_cmtSourceCode);
}

LPWSTR CCommentView::GetCmtSourceCode()
{
	int length = m_codeRichEdit.GetTextLength();

	delete[] m_cmtSourceCode;
	m_cmtSourceCode = NULL;

	m_cmtSourceCode = new WCHAR[length + 1];
	m_codeRichEdit.GetWindowTextW(m_cmtSourceCode, length * 2 + 1);

	return m_cmtSourceCode;
}

int CCommentView::GetCmtSourceCodeLength()
{
	return m_codeRichEdit.GetTextLength();
}

void CCommentView::SrcLineCount()
{


}

BOOL CCommentView::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	/*if (LOWORD(wParam) == IDC_CODERICHEDIT)
	{
	MSGFILTER* mf = (MSGFILTER*)lParam;
	switch (mf->msg)
	{
	case WM_COMMAND:
	switch (HIWORD(wParam)) {
	case EN_UPDATE:
	{
	//CPaintDC dc(m_codeRichEdit.FromHandle(m_codeRichEdit.m_hWnd));
	//PrintLineNumber(&dc);
	HDC hdc;
	hdc = ::GetDC(m_codeRichEdit.m_hWnd);
	PrintLineNumber(&hdc);
	::ReleaseDC(m_codeRichEdit.m_hWnd, hdc);
	}
	}
	}
	}*/
	return CView::OnNotify(wParam, lParam, pResult);
}

void CCommentView::PrintSourceCode(CString sourceCode)
{
	m_codeRichEdit.SetWindowTextW(sourceCode);
}

void CCommentView::ScrollEditor(int lineNumber)
{
	m_codeRichEdit.ScrollEditor(lineNumber);
}