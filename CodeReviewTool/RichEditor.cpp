// RichEditor.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "CodeReviewTool.h"
#include "RichEditor.h"


// CRichEditor

IMPLEMENT_DYNAMIC(CRichEditor, CRichEditCtrl)

CRichEditor::CRichEditor()
{

}

CRichEditor::~CRichEditor()
{
}


BEGIN_MESSAGE_MAP(CRichEditor, CRichEditCtrl)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// CRichEditor 메시지 처리기입니다.




void CRichEditor::OnPaint()
{
	CRichEditCtrl::OnPaint();

	CDC* pDC = GetDC();
	PrintLineNumber(pDC);
	ReleaseDC(pDC);
}

void CRichEditor::PrintLineNumber(CDC* hdc)
{
	//Gdiplus::Graphics g(dc->m_hDC);

	HBRUSH B = CreateSolidBrush(RGB(0, 0, 0));
	int firstVisibleLine = this->GetFirstVisibleLine();
	int lineCount = this->SendMessage(EM_GETLINECOUNT, 0, 0);

	if (lineCount <= 1)
	{
		return ;
	}
	int len = (int)this->SendMessage(EM_LINELENGTH, 0, 0);
	int secondLineIndex = len + 1;

	POINT point1;
	POINT point2;

	this->SendMessage(EM_POSFROMCHAR, (WPARAM)&point1, secondLineIndex);
	this->SendMessage(EM_POSFROMCHAR, (WPARAM)&point2, 0);

	POINT caretPosition1;
	POINT caretPosition2;

	caretPosition1 = point1;
	caretPosition2 = point2;

	int lineHeight = caretPosition1.y - caretPosition2.y;

	TEXTMETRIC tm;
	::GetTextMetrics(*hdc, &tm);
	CRect cr;
	this->GetRect(&cr);
	cr.right = 35 & 0xFFFF;
	int posibleVisibleLineCount = lineHeight == 0 ? 1 : (cr.Height() / lineHeight);

	CString text;
	for (int i = 0; i < posibleVisibleLineCount && i < lineCount; i++)
	{
		text.Format(L"%d", (firstVisibleLine + i + 1));
		TextOut(*hdc, 0, (i * lineHeight), (LPCWSTR)text, text.GetLength());
	}

	//g.ReleaseHDC(dc->m_hDC);
}

void CRichEditor::ScrollEditor(int lineNumber)
{
	int firstVisibleLine = this->GetFirstVisibleLine();

	int distance = lineNumber - firstVisibleLine;
	// 4가 무엇을 뜻하는건가요? const int로 상수를 선언해두고 사용하면 코드가독성에 도움이 됩니다.
	LineScroll(distance - 4, 0);
}
