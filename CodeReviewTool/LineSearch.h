#pragma once
#include "afxwin.h"


// CLineSearch ��ȭ �����Դϴ�.

class CLineSearch : public CDialogEx
{
	DECLARE_DYNAMIC(CLineSearch)
protected:
	CEdit m_currentLine;

public:
	CLineSearch(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CLineSearch();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LINESEARCH };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	void SetTextOnEdit(int number);

	afx_msg void OnBnClickedPrevlinebutton();
	afx_msg void OnBnClickedNextlinebutton();
	virtual void PostNcDestroy();
	afx_msg void OnClose();
};
