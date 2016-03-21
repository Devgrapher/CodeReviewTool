// FileListView.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "CodeReviewTool.h"
#include "FileListView.h"
#include "afxdialogex.h"
#include "MainFrm.h"

// CFileListView ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CFileListView, CDialogEx)

CFileListView::CFileListView(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_FILESELECT, pParent)
{

}

CFileListView::~CFileListView()
{
}

void CFileListView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_REVISION, m_revisionLB);
	DDX_Control(pDX, IDC_CODEFILE, m_fileNameLB);
}

BEGIN_MESSAGE_MAP(CFileListView, CDialogEx)
	ON_WM_CLOSE()
	ON_LBN_SELCHANGE(IDC_REVISION, &CFileListView::OnLbnSelchangeRevision)
	ON_LBN_DBLCLK(IDC_CODEFILE, &CFileListView::OnLbnDblclkCodefile)
END_MESSAGE_MAP()


// CFileListView �޽��� ó�����Դϴ�.


void CFileListView::PostNcDestroy()
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	int count = 0;
	CMainFrame* mf;
	mf = (CMainFrame*)AfxGetMainWnd();

	mf->CloseFileListView();
	delete this;
	CDialogEx::PostNcDestroy();
}


void CFileListView::OnClose()
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	DestroyWindow();
	//CDialogEx::OnClose();
}

void CFileListView::InitRevisions(std::list<CString>* revisions)
{
	std::list<CString>::iterator iter;
	m_revisions = revisions;
	
	for (iter = m_revisions->begin(); iter != m_revisions->end(); iter++)
	{
		m_revisionLB.AddString(*iter);
	}

	m_revisionLB.SetCurSel(0);
}

void CFileListView::InitReviews(std::list<CReviewData>* reviews)
{
	m_reviews = reviews;
	ViewFileListByIndex(0);
}

void CFileListView::ViewFileListByIndex(int index)
{
	CString rivision;
	std::list<CReviewData>::iterator iter;

	m_revisionLB.GetText(index, rivision);
	for (iter = m_reviews->begin(); iter != m_reviews->end(); iter++)
	{
		if (rivision.CompareNoCase(iter->GetRevision()) == 0)
		{
			m_fileNameLB.AddString(iter->GetFilePath());
		}
	}
}

void CFileListView::OnLbnSelchangeRevision()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString rivision;

	m_revisionLB.GetText(m_revisionLB.GetCurSel(), rivision);
	ClearFileNameLB();
	ViewFileListByIndex(m_revisionLB.GetCurSel());
}


void CFileListView::ClearFileNameLB()
{
	m_fileNameLB.ResetContent();
}

void CFileListView::ClearRevisionLB()
{
	m_revisionLB.ResetContent();
}

void CFileListView::OnLbnDblclkCodefile()
{
	CString filepath;
	CMainFrame* mf;
	
	m_fileNameLB.GetText(m_fileNameLB.GetCurSel(), filepath);
	mf = (CMainFrame*)AfxGetMainWnd();
	mf->PrintReview(filepath);
	mf->PrintSourceCode(filepath);
}