// PreCodeView.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "CodeReviewTool.h"
#include "PreCodeView.h"


// CPreCodeView

IMPLEMENT_DYNCREATE(CPreCodeView, CView)

CPreCodeView::CPreCodeView()
{

}

CPreCodeView::~CPreCodeView()
{
}

BEGIN_MESSAGE_MAP(CPreCodeView, CView)
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CPreCodeView �׸����Դϴ�.

void CPreCodeView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: ���⿡ �׸��� �ڵ带 �߰��մϴ�.
}


// CPreCodeView �����Դϴ�.

#ifdef _DEBUG
void CPreCodeView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CPreCodeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CPreCodeView �޽��� ó�����Դϴ�.


int CPreCodeView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.
	CRect cr;
	GetClientRect(&cr);
	m_codeRichEdit.Create(WS_CHILD | WS_VISIBLE | ES_AUTOVSCROLL | ES_AUTOHSCROLL | ES_MULTILINE | WS_VSCROLL | WS_HSCROLL,
							cr, this, RICHEDITID);
	return 0;
}


void CPreCodeView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	CRect cr;
	GetClientRect(&cr);

	m_codeRichEdit.MoveWindow(&cr, 1);
	
}
