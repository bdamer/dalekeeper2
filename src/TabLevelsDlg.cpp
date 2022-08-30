// C:\development\dalekeeper2\src\TabLevelsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DaleKeeper.h"
#include "TabLevelsDlg.h"
#include "afxdialogex.h"

// TabLevelsDlg dialog

IMPLEMENT_DYNAMIC(TabLevelsDlg, CDialog)

TabLevelsDlg::TabLevelsDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_LEVELS, pParent)
{
	m_nBarbarian = 0;
	m_nBard = 0;
	m_nCleric = 0;
	m_nDruid = 0;
	m_nFighter = 0;
	m_nMonk = 0;
	m_nPaladin = 0;
	m_nRanger = 0;
	m_nRogue = 0;
	m_nSorcerer = 0;
	m_nWizard = 0;
	m_nTotal = 0;
	lock_total_levels = 1;
}

TabLevelsDlg::~TabLevelsDlg()
{
}

void TabLevelsDlg::populate(const CInfCreature& cre)
{
	m_nBarbarian = cre.GetBarbarianLevels();
	m_nBard = cre.GetBardLevels();
	m_nCleric = cre.GetClericLevels();
	m_nDruid = cre.GetDruidLevels();
	m_nFighter = cre.GetFighterLevels();
	m_nMonk = cre.GetMonkLevels();
	m_nPaladin = cre.GetPaladinLevels();
	m_nRanger = cre.GetRangerLevels();
	m_nRogue = cre.GetRogueLevels();
	m_nSorcerer = cre.GetSorcererLevels();
	m_nWizard = cre.GetWizardLevels();
	m_nTotal = cre.GetTotalLevels();
}

void TabLevelsDlg::collect_values(CInfCreature& cre)
{
	cre.SetBarbarianLevels(m_nBarbarian);
	cre.SetBardLevels(m_nBard);
	cre.SetClericLevels(m_nCleric);
	cre.SetDruidLevels(m_nDruid);
	cre.SetFighterLevels(m_nFighter);
	cre.SetMonkLevels(m_nMonk);
	cre.SetPaladinLevels(m_nPaladin);
	cre.SetRangerLevels(m_nRanger);
	cre.SetRogueLevels(m_nRogue);
	cre.SetSorcererLevels(m_nSorcerer);
	cre.SetWizardLevels(m_nWizard);
	cre.SetTotalLevels(m_nTotal);
}

void TabLevelsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_BARBARIAN_LEVELS, m_edBarbarian);
	DDX_Text(pDX, IDC_BARBARIAN_LEVELS, m_nBarbarian);
	DDV_MinMaxUInt(pDX, m_nBarbarian, 0, 255);
	DDX_Text(pDX, IDC_BARD_LEVELS, m_nBard);
	DDV_MinMaxUInt(pDX, m_nBard, 0, 255);
	DDX_Text(pDX, IDC_CLERIC_LEVELS, m_nCleric);
	DDV_MinMaxUInt(pDX, m_nCleric, 0, 255);
	DDX_Text(pDX, IDC_DRUID_LEVELS, m_nDruid);
	DDV_MinMaxUInt(pDX, m_nDruid, 0, 255);
	DDX_Text(pDX, IDC_FIGHTER_LEVELS, m_nFighter);
	DDV_MinMaxUInt(pDX, m_nFighter, 0, 255);
	DDX_Text(pDX, IDC_MONK_LEVELS, m_nMonk);
	DDV_MinMaxUInt(pDX, m_nMonk, 0, 255);
	DDX_Text(pDX, IDC_PALADIN_LEVELS, m_nPaladin);
	DDV_MinMaxUInt(pDX, m_nPaladin, 0, 255);
	DDX_Text(pDX, IDC_RANGER_LEVELS, m_nRanger);
	DDV_MinMaxUInt(pDX, m_nRanger, 0, 255);
	DDX_Text(pDX, IDC_ROGUE_LEVELS, m_nRogue);
	DDV_MinMaxUInt(pDX, m_nRogue, 0, 255);
	DDX_Text(pDX, IDC_SORCERER_LEVELS, m_nSorcerer);
	DDV_MinMaxUInt(pDX, m_nSorcerer, 0, 255);
	DDX_Text(pDX, IDC_WIZARD_LEVELS, m_nWizard);
	DDV_MinMaxUInt(pDX, m_nWizard, 0, 255);

	DDX_Text(pDX, IDC_TOTAL_LEVEL, m_nTotal);
	DDV_MinMaxUInt(pDX, m_nTotal, 0, 255);

	DDX_Check(pDX, IDC_LOCK_TOTAL_LEVEL, lock_total_levels);
	DDX_Control(pDX, IDC_TOTAL_LEVEL, m_edTotalLevels);	
}

BEGIN_MESSAGE_MAP(TabLevelsDlg, CDialog)
	ON_BN_CLICKED(IDC_LOCK_TOTAL_LEVEL, &TabLevelsDlg::OnBnClickedLockTotalLevel)
	ON_EN_KILLFOCUS(IDC_BARBARIAN_LEVELS, &TabLevelsDlg::OnKillFocusLevels)
	ON_EN_KILLFOCUS(IDC_BARD_LEVELS, &TabLevelsDlg::OnKillFocusLevels)
	ON_EN_KILLFOCUS(IDC_CLERIC_LEVELS, &TabLevelsDlg::OnKillFocusLevels)
	ON_EN_KILLFOCUS(IDC_DRUID_LEVELS, &TabLevelsDlg::OnKillFocusLevels)
	ON_EN_KILLFOCUS(IDC_FIGHTER_LEVELS, &TabLevelsDlg::OnKillFocusLevels)
	ON_EN_KILLFOCUS(IDC_MONK_LEVELS, &TabLevelsDlg::OnKillFocusLevels)
	ON_EN_KILLFOCUS(IDC_PALADIN_LEVELS, &TabLevelsDlg::OnKillFocusLevels)
	ON_EN_KILLFOCUS(IDC_RANGER_LEVELS, &TabLevelsDlg::OnKillFocusLevels)
	ON_EN_KILLFOCUS(IDC_ROGUE_LEVELS, &TabLevelsDlg::OnKillFocusLevels)
	ON_EN_KILLFOCUS(IDC_SORCERER_LEVELS, &TabLevelsDlg::OnKillFocusLevels)
	ON_EN_KILLFOCUS(IDC_WIZARD_LEVELS, &TabLevelsDlg::OnKillFocusLevels)
END_MESSAGE_MAP()

// TabLevelsDlg message handlers

void TabLevelsDlg::OnBnClickedLockTotalLevel()
{
	UpdateData(TRUE);
	m_edTotalLevels.EnableWindow(lock_total_levels == 0);
	if (lock_total_levels)
		OnKillFocusLevels();
}

void TabLevelsDlg::OnKillFocusLevels()
{
	if (lock_total_levels)
	{
		UpdateData(TRUE);
		m_nTotal = (m_nBarbarian + m_nBard + m_nCleric + m_nDruid
			+ m_nFighter + m_nMonk + m_nPaladin + m_nRanger
			+ m_nRogue + m_nSorcerer + m_nWizard) % 256;
		UpdateData(FALSE);
	}
}
