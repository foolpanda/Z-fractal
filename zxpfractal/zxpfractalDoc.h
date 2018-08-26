
// zxpfractalDoc.h : interface of the CzxpfractalDoc class
//
#include "CComplex.h"

#pragma once


class CzxpfractalDoc : public CDocument
{
protected: // create from serialization only
	CzxpfractalDoc();
	DECLARE_DYNCREATE(CzxpfractalDoc)

// Attributes
public:
  CComplex m_c;
  int m_i;
  int m_num;
// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// Implementation
public:
	virtual ~CzxpfractalDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
  void redrawbmp();
// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnZnext();
	afx_msg void OnEditvc();
};


