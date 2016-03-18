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

	m_numberEditCtrlWidth = cr.right / 10;
	cr.right = m_numberEditCtrlWidth;
	m_codeLineEdit.Create(WS_CHILD | WS_VISIBLE | ES_AUTOVSCROLL | ES_MULTILINE |
						  WS_VSCROLL | WS_HSCROLL | ES_READONLY | ES_CENTER,
						  cr, this, IDC_NUMRICHEDIT);

	GetClientRect(&cr);
	cr.left = m_numberEditCtrlWidth;
	cr.right = cr.right - m_numberEditCtrlWidth;
	m_codeRichEdit.Create(WS_CHILD | WS_VISIBLE | ES_AUTOVSCROLL | ES_AUTOHSCROLL | ES_MULTILINE | 
						  WS_VSCROLL | WS_HSCROLL,
						  cr, this, IDC_CODERICHEDIT);

	m_codeRichEdit.SetEventMask(m_codeRichEdit.GetEventMask() | NM_KEYDOWN);

	CHARFORMAT cf;
	cf.cbSize = sizeof(cf);
	cf.dwEffects = CFE_PROTECTED;
	cf.dwMask = CFM_BOLD | CFM_ITALIC | CFM_STRIKEOUT | CFM_UNDERLINE | CFM_FACE | CFM_SIZE | CFM_CHARSET | CFM_PROTECTED | CFM_COLOR;
	cf.yHeight = 200;
	cf.crTextColor = RGB(0, 0, 0);
	cf.bCharSet = HANGEUL_CHARSET;
	m_codeRichEdit.SetDefaultCharFormat(cf);
	m_codeLineEdit.SetDefaultCharFormat(cf);

	return 0;
}


void CCommentView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	CRect cr;
	GetClientRect(&cr);

	cr.right = m_numberEditCtrlWidth;
	m_codeLineEdit.MoveWindow(&cr, 1);

	GetClientRect(&cr);
	cr.left = m_numberEditCtrlWidth;
	cr.right = cr.right - m_numberEditCtrlWidth;
	m_codeRichEdit.MoveWindow(&cr, 1);
}

void CCommentView::SetCmtSourceCode(LPTSTR sourceCode)
{
	// ����ó�� �ʿ� NULL���� �ƴ���.
	m_cmtSourceCode = sourceCode;

	m_codeRichEdit.SetWindowTextW(m_cmtSourceCode);

	this->SrcLineCount();
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
	WCHAR cntStr[LINELENGTH];
	LPWSTR enterLoc = NULL;
	
	enterLoc = wcsstr(m_cmtSourceCode, L"\r\n");
	wsprintf(cntStr, L"%d\r\n", ++m_maxLineNumber);
	m_codeLineEdit.ReplaceSel(cntStr, 0);

	while ((enterLoc = wcsstr(enterLoc + 1, L"\r\n")) != NULL)
	{
		wsprintf(cntStr, L"%d\r\n", ++m_maxLineNumber);
		m_codeLineEdit.ReplaceSel(cntStr, 0);
	}

	wsprintf(cntStr, L"%d\r\n", ++m_maxLineNumber);
	m_codeLineEdit.ReplaceSel(cntStr, 0);
}

BOOL CCommentView::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if (LOWORD(wParam) == IDC_CODERICHEDIT)
	{
		MSGFILTER* mf = (MSGFILTER*)lParam;
		switch (mf->msg)
		{
		case WM_KEYDOWN:
		{
			switch (mf->wParam)
			{
			case VK_RETURN:
			{
				WCHAR cntStr[LINELENGTH];
				m_maxLineNumber++;
				wsprintf(cntStr, L"%d\r\n", m_maxLineNumber);
				m_codeLineEdit.ReplaceSel(cntStr, 0);
				break;
			}
			}
			break;
			
		}
		}
	}
	return CView::OnNotify(wParam, lParam, pResult);
}
