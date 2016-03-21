#pragma once
#include "afxwin.h"
//#include "MainFrm.h"
#include <list>
// CFileListView ��ȭ �����Դϴ�.

class CReviewData;

class CFileListView : public CDialogEx
{
	DECLARE_DYNAMIC(CFileListView)
protected:
	std::list<CReviewData>* m_reviews;
	std::list<CString>* m_revisions;

	CListBox m_revisionLB;
	CListBox m_fileNameLB;

public:
	CFileListView(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CFileListView();

	void InitRevisions(std::list<CString>* revisions);
	void InitReviews(std::list<CReviewData>* reviews);
// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FILESELECT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
	
	void ClearFileNameLB();
	void ClearRevisionLB();
	void ViewFileListByIndex(int index);
	virtual void PostNcDestroy();
public:
	afx_msg void OnClose();
	afx_msg void OnLbnSelchangeRevision();
	afx_msg void OnLbnDblclkCodefile();
};
