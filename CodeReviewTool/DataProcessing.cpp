#include "stdafx.h"
#include "DataProcessing.h"


CDataProcessing::CDataProcessing()
{
	m_preCodeFileName = NULL;
	m_cmtCodeFileName = NULL;

	m_preSourceCode = NULL;
	m_cmtSourceCode = NULL;
}


CDataProcessing::~CDataProcessing()
{
	delete[] m_preSourceCode;
	m_preSourceCode = NULL;

	delete[] m_cmtSourceCode;
	m_cmtSourceCode = NULL;
}

bool CDataProcessing::ReadCodeFile(LPTSTR arguments)
{
	// ���ϸ��� �Ľ��ϰ� ���ϸ����� �ڵ� ������ ��.
	// �� �� ����ó���� �Ŀ� �߰�.
	CFile preFile, cmtFile;
	char* tmp = NULL;
	LPTSTR context = NULL;
	int preFileLength, cmtFileLength;
	size_t len = 0;
	

	m_preCodeFileName = wcstok_s(arguments, TEXT(" "), &context);
	m_cmtCodeFileName = wcstok_s(context, TEXT(" "), &context);


	preFile.Open(m_preCodeFileName, CFile::modeRead, 0);

	preFileLength = preFile.GetLength();
	tmp = new char[preFileLength + 1];
	tmp[preFileLength] = '\0';

	preFile.Read(tmp, preFileLength); 
	m_preSourceCode = new WCHAR[preFileLength + 1];
	m_preSourceCode[preFileLength] = '\0';
	
	MultiByteToWideChar(CP_ACP, 0, tmp, -1, m_preSourceCode, preFileLength * 2);

	delete[] tmp;
	tmp = NULL;

	preFile.Close();


	cmtFile.Open(m_cmtCodeFileName, CFile::modeRead, 0);

	cmtFileLength = cmtFile.GetLength();
	tmp = new char[cmtFileLength + 1];
	tmp[cmtFileLength] = '\0';

	cmtFile.Read(tmp, cmtFileLength);
	
	m_cmtSourceCode = new WCHAR[cmtFileLength + 1];
	m_cmtSourceCode[cmtFileLength] = '\0';

	MultiByteToWideChar(CP_ACP, 0, tmp, -1, m_cmtSourceCode, cmtFileLength * 2);
	delete[] tmp;
	tmp = NULL;

	cmtFile.Close();
	return true;
}

LPTSTR CDataProcessing::GetPreSourceCode()
{
	return m_preSourceCode;
}


LPTSTR CDataProcessing::GetCmtSourceCode()
{
	return m_cmtSourceCode;
}