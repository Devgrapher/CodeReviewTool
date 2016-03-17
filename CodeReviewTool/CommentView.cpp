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
	m_codeRichEdit.Create(WS_CHILD | WS_VISIBLE | ES_AUTOVSCROLL | ES_AUTOHSCROLL | ES_MULTILINE | WS_VSCROLL | WS_HSCROLL,
		cr, this, RICHEDITID2);

	CHARFORMAT cf;
	cf.cbSize = sizeof(cf);
	cf.dwEffects = CFE_PROTECTED;
	cf.dwMask = CFM_BOLD | CFM_ITALIC | CFM_STRIKEOUT | CFM_UNDERLINE | CFM_FACE | CFM_SIZE | CFM_CHARSET | CFM_PROTECTED | CFM_COLOR;
	cf.yHeight = 200;
	cf.crTextColor = RGB(0, 0, 0);
	cf.bCharSet = HANGEUL_CHARSET;
	m_codeRichEdit.SetDefaultCharFormat(cf);
	return 0;
}


void CCommentView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	CRect cr;
	GetClientRect(&cr);
	m_codeRichEdit.SetRect(&cr);
}

void CCommentView::SetCmtSourceCode(LPTSTR sourceCode)
{
	// ����ó�� �ʿ� NULL���� �ƴ���.
	m_cmtSourceCode = sourceCode;

	m_codeRichEdit.SetWindowTextW(m_cmtSourceCode);
}