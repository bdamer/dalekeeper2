/************************************************************************************
	Copyright (c) 2000 Aaron O'Neil
	All rights reserved.

	Redistribution and use in source and binary forms, with or without
	modification, are permitted provided that the following conditions
	are met:

		1) Redistributions of source code must retain the above copyright notice, 
				this list of conditions and the following disclaimer.
		2) Redistributions in binary form must reproduce the above copyright notice, 
				this list of conditions and the following disclaimer in the documentation
				and/or other materials provided with the distribution.
		3) Redistributions in binary form must reproduce the above copyright notice on
				program startup. Additional credits for program modification are acceptable
				but original copyright and credits must be visible at startup.
		4) You may charge a reasonable copying fee for any distribution of Shadow Keeper. 
				You may charge any fee you choose for support of Shadow Keeper. You may not 
				charge a fee for Shadow Keeper itself.

  THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
	IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
	OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
	IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
	INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
	NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
	DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
	THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
	(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
	THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

**************************************************************************************/


#if !defined(AFX_TABABILITIESDLG_H__7177E663_5E1E_11D4_9BE4_444553540000__INCLUDED_)
#define AFX_TABABILITIESDLG_H__7177E663_5E1E_11D4_9BE4_444553540000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TabAbilitiesDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTabAbilitiesDlg dialog

class CTabAbilitiesDlg : public CDialog
{
// Construction
public:
	CTabAbilitiesDlg(CWnd* pParent = NULL);   // standard constructor

	HACCEL m_hAccel;

// Dialog Data
	//{{AFX_DATA(CTabAbilitiesDlg)
	enum { IDD = IDD_ABILITIES };
	CEdit	m_edStr;
	UINT	m_nCha;
	UINT	m_nCon;
	UINT	m_nDex;
	UINT	m_nInt;
	UINT	m_nStr;
	UINT	m_nWis;
	UINT	m_nExp;
	UINT	m_nGold;
	UINT	m_nHP;
	int		m_nAC;
	short	m_nACModCrushing;
	short	m_nACModMissile;
	short	m_nACModPiercing;
	short	m_nACModSlashing;
	UINT	m_nReputation;
	UINT	m_nExpForKill;
	short	m_nCurrentHP;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTabAbilitiesDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTabAbilitiesDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TABABILITIESDLG_H__7177E663_5E1E_11D4_9BE4_444553540000__INCLUDED_)
