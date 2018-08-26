
// zxpfractal.h : main header file for the zxpfractal application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CzxpfractalApp:
// See zxpfractal.cpp for the implementation of this class
//

class CzxpfractalApp : public CWinAppEx
{
public:
	CzxpfractalApp();


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CzxpfractalApp theApp;
