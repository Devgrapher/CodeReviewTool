
// MainFrm.h : CMainFrame Ŭ������ �������̽�
//

#pragma once
#include "ChildView.h"
#include "PreCodeView.h"
#include "CommentView.h"
#include "DataProcessing.h"

#include "afxext.h"

class CMainFrame : public CFrameWnd
{
	
public:
	CMainFrame();
protected: 
	DECLARE_DYNAMIC(CMainFrame)

// Ư���Դϴ�.
public:

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);

// �����Դϴ�.
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // ��Ʈ�� ������ ���Ե� ����Դϴ�.
	CToolBar          m_wndToolBar;
	CStatusBar        m_wndStatusBar;
	//CChildView    m_wndView;
	CSplitterWnd m_wndSplitter;
	CDataProcessing m_dataProcessor;
	CPreCodeView* m_ptPreView;
	CCommentView* m_ptCmtView;

	LPWSTR m_preSourceCodeFileName;
	LPWSTR m_commentSourceCodeFileName;

// ������ �޽��� �� �Լ�
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSetFocus(CWnd *pOldWnd);
	afx_msg void OnApplicationLook(UINT id);
	afx_msg void OnUpdateApplicationLook(CCmdUI* pCmdUI);
	DECLARE_MESSAGE_MAP()

	
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
public:

	afx_msg void OnSize(UINT nType, int cx, int cy);
	// Command line�� arguments�� �޾ƿ�
	bool SetCmdArguments(LPTSTR arguments);
	afx_msg void OnSave();
};


