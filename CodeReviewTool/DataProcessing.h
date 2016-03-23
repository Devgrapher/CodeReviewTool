#pragma once
#include <list>
#include "ReviewData.h"

// 전역 네임스페이스에 enum을 노출시키는거는 이름 충돌때문에 권장되지 않아요.
// CDataProcessing클래스 안에다 두면 더 좋을거 같네요.
enum Commands{ CMD_INCREASE, CMD_DECREASE, CMD_GETCURRENTLINE, CMD_INIT };
enum Encodings { UNICODE_, UNICODE_BIGENDIAN, UTF8, ANSI };
class CDataProcessing
{
protected:
	CString m_reviewText;

	CString m_url;
	std::list<CString> m_revisions;
	std::list<CReviewData> m_reviews;

	CReviewData* m_currentReviewData;
protected:
	CString ConvertMultibyteToUnicode(LPSTR pMultibyte);
	void ClearAllData();
	bool GetTextFromFile(LPWSTR filepath, CString& contents);
	bool FillReviewData();
	void SetReviewText(CString text);
	int AddLineNumbers(CString numbers, CReviewData* reviewData);
	int CheckEncoding(CFile* file, LPSTR buffer);

public:
	CDataProcessing();
	~CDataProcessing();

	std::list<CString>* GetRivisions();
	std::list<CReviewData>* GetReviews();

	int EditorScrollControl(int command);
	

	bool FillAllDataFromFile(LPWSTR filepath);
	bool GetReviewNCodeText(CString filepath, CString* reviewText, CString* sourceCodeText);
};

