
// zxpfractalView.h : interface of the CzxpfractalView class
//


#pragma once


class CzxpfractalView : public CView
{
protected: // create from serialization only
	CzxpfractalView();
	DECLARE_DYNCREATE(CzxpfractalView)

// Attributes
public:
	CzxpfractalDoc* GetDocument() const;
    COLORREF m_map[300];
// Operations
public:
      CBitmap m_bmp;  
	  CString m_cur;
// Overrides
public:
	COLORREF getcolor(int ik);
	void DrawFractal(CDC* pdc,CzxpfractalDoc* pDoc) ;
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	void drawtmp();
	void drawdc(CDC*pdc,CzxpfractalDoc* pDoc);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
    void  InitPallette(double h1 /* = 137.0 */, double h2 /* = 30.0 */);
// Implementation
public:
	virtual ~CzxpfractalView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg LRESULT OnDrawBmp(WPARAM, LPARAM);
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in zxpfractalView.cpp
inline CzxpfractalDoc* CzxpfractalView::GetDocument() const
   { return reinterpret_cast<CzxpfractalDoc*>(m_pDocument); }
#endif

