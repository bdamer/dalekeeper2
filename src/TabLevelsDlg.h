#pragma once

#include "InfCreature.h"

// TabLevelsDlg dialog
class TabLevelsDlg : public CDialog
{
	DECLARE_DYNAMIC(TabLevelsDlg)

public:
	TabLevelsDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~TabLevelsDlg();

	void populate(const CInfCreature& cre);
	void collect_values(CInfCreature& cre);

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LEVELS1 };
#endif
	CEdit	m_edBarbarian;
	CEdit	m_edTotalLevels;

	UINT	m_nBarbarian;
	UINT	m_nBard;
	UINT	m_nCleric;
	UINT	m_nDruid;
	UINT	m_nFighter;
	UINT	m_nMonk;
	UINT	m_nPaladin;
	UINT	m_nRanger;
	UINT	m_nRogue;
	UINT	m_nSorcerer;
	UINT	m_nWizard;
	UINT	m_nTotal;
	int lock_total_levels;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedLockTotalLevel();
	afx_msg void OnKillFocusLevels();
};
