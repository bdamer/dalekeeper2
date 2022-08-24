// TabCharacteristicsDlg.cpp : implementation file
//

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

#include "stdafx.h"
#include "dalekeeper.h"
#include "TabCharacteristicsDlg.h"
#include "Global.h"
#include "ValueList.h"
#include "SetValueDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTabCharacteristicsDlg dialog


CTabCharacteristicsDlg::CTabCharacteristicsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTabCharacteristicsDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTabCharacteristicsDlg)
	m_nMovementSpeed = 0;
	//}}AFX_DATA_INIT

	m_hAccel = NULL;

	m_bAlignment = FALSE;
	m_bClass = FALSE;
	m_bRace = FALSE;
	m_bSubRace = FALSE;
	m_bGender = FALSE;
	m_bEnemyAlly = FALSE;
}


void CTabCharacteristicsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTabCharacteristicsDlg)
	DDX_Control(pDX, IDC_ENEMYALLY, m_cbEnemyAlly);
	DDX_Control(pDX, IDC_ALIGNMENT, m_cbAlignment);
	DDX_Control(pDX, IDC_CLASS, m_cbClass);
	DDX_Control(pDX, IDC_RACE, m_cbRace);
	DDX_Control(pDX, IDC_SUBRACE, m_cbSubRace);
	DDX_Control(pDX, IDC_GENDER, m_cbGender);
	DDX_Text(pDX, IDC_MOVEMENTSPEED, m_nMovementSpeed);
	DDV_MinMaxUInt(pDX, m_nMovementSpeed, 0, 50);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTabCharacteristicsDlg, CDialog)
	//{{AFX_MSG_MAP(CTabCharacteristicsDlg)
	ON_BN_CLICKED(IDC_SETVALUE_ALIGNMENT, OnSetvalueAlignment)
	ON_BN_CLICKED(IDC_SETVALUE_CLASS, OnSetvalueClass)
	ON_BN_CLICKED(IDC_SETVALUE_GENDER, OnSetvalueGender)
	ON_BN_CLICKED(IDC_SETVALUE_RACE, OnSetvalueRace)
	ON_BN_CLICKED(IDC_SETVALUE_SUBRACE, OnSetvalueSubRace)
	ON_BN_CLICKED(IDC_SETVALUE_ENEMYALLY, OnSetvalueEnemyally)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTabCharacteristicsDlg message handlers

BOOL CTabCharacteristicsDlg::PreTranslateMessage(MSG* pMsg) 
{
	// This was the only way I could get the accelerators to work while the
	// focus is on the modeless dialog.

	CFrameWnd *pWnd = GetParentFrame();
	if (pWnd && ::TranslateAccelerator(pWnd->GetSafeHwnd(),m_hAccel,pMsg))
		return(TRUE);

	return(CDialog::PreTranslateMessage(pMsg));
}


BOOL CTabCharacteristicsDlg::OnCommand(WPARAM wParam, LPARAM lParam) 
{
	// If ENTER or ESC is hit on any of the controls on a dialog, they send the messages
	// back to the parent dialog. This causes the dialog to close itself down if the
	// IDOK and IDCANCEL messages are not mapped. I was putting the OK and Cancel buttons
	// on the dialogs and hiding them, then mapping the messages and doing nothing, but
	// this is a much easier solution.
	if (wParam == IDOK || wParam == IDCANCEL)
		return(TRUE);
	
	return CDialog::OnCommand(wParam, lParam);
}

BOOL CTabCharacteristicsDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_hAccel = ::LoadAccelerators(AfxGetApp()->m_hInstance,MAKEINTRESOURCE(IDR_MAINFRAME));

	_vlGender.FillComboBox(m_cbGender);
	_vlGenderUser.FillComboBox(m_cbGender);
	_vlRace.FillComboBox(m_cbRace);
	_vlRaceUser.FillComboBox(m_cbRace);
	_vlSubRace.FillComboBox(m_cbSubRace);
	_vlClass.FillComboBox(m_cbClass);
	_vlClassUser.FillComboBox(m_cbClass);
	_vlAlignment.FillComboBox(m_cbAlignment);
	_vlEnemyAlly.FillComboBox(m_cbEnemyAlly);

	return TRUE; 
}

BOOL CTabCharacteristicsDlg::SetValue(int nValue, CComboBox &cb)
{
	int nCount = cb.GetCount();
	for (int i=0;i<nCount;i++)
		if ((int)cb.GetItemData(i) == nValue)
		{
			cb.SetCurSel(i);
			cb.EnableWindow(TRUE);
			return(TRUE);
		}

	cb.SetCurSel(-1);
	cb.EnableWindow(FALSE);
	return(FALSE);
}

// The values on this page all come from known-value lists. If the value passed
// in doesn't exist in the appropriate list I'm disabling the control. The actual
// value passed in will be preserved, but the user will not be able to edit it.
void CTabCharacteristicsDlg::SetAlignment(BYTE chAlignment)
{
	if (!CValueList::SetComboBoxValue(m_cbAlignment,chAlignment,TRUE))
	{
		m_bAlignment = TRUE;
		m_chAlignment = chAlignment;
	}
	else
		m_bAlignment = FALSE;
}

void CTabCharacteristicsDlg::SetClass(BYTE chClass)
{
	if (!CValueList::SetComboBoxValue(m_cbClass,chClass,TRUE))
	{
		m_chClass = chClass;
		m_bClass = TRUE;
	}
	else
		m_bClass = FALSE;
}

void CTabCharacteristicsDlg::SetGender(BYTE chGender)
{
	if (!CValueList::SetComboBoxValue(m_cbGender,chGender,TRUE))
	{
		m_chGender = chGender;
		m_bGender = TRUE;
	}
	else
		m_bGender = FALSE;
}

void CTabCharacteristicsDlg::SetRace(BYTE chRace)
{
	if (!CValueList::SetComboBoxValue(m_cbRace,chRace,TRUE))
	{
		m_chRace = chRace;
		m_bRace = TRUE;
	}
	else
		m_bRace = FALSE;
}

void CTabCharacteristicsDlg::SetSubRace(BYTE chSubRace)
{
	if (!CValueList::SetComboBoxValue(m_cbSubRace, chSubRace, TRUE))
	{
		m_chSubRace = chSubRace;
		m_bSubRace = TRUE;
	}
	else
		m_bSubRace = FALSE;
}

void CTabCharacteristicsDlg::SetEnemyAlly(BYTE chEnemyAlly)
{
	if (!CValueList::SetComboBoxValue(m_cbEnemyAlly,chEnemyAlly,TRUE))
	{
		m_chEnemyAlly = chEnemyAlly;
		m_bEnemyAlly = TRUE;
	}
	else
		m_bEnemyAlly = FALSE;
}

DWORD CTabCharacteristicsDlg::GetValue(CComboBox &cb)
{
	int nIndex = cb.GetCurSel();
	if (nIndex == CB_ERR)
		return(-1);
	return(cb.GetItemData(nIndex));
}

BYTE CTabCharacteristicsDlg::GetAlignment()
{
	if (m_bAlignment)
		return(m_chAlignment);

	return((BYTE)CValueList::GetComboBoxValue(m_cbAlignment));
}

BYTE CTabCharacteristicsDlg::GetClass()
{
	if (m_bClass)
		return(m_chClass);

	return((BYTE)CValueList::GetComboBoxValue(m_cbClass));
}

BYTE CTabCharacteristicsDlg::GetRace()
{
	if (m_bRace)
		return(m_chRace);

	return((BYTE)CValueList::GetComboBoxValue(m_cbRace));
}

BYTE CTabCharacteristicsDlg::GetSubRace()
{
	if (m_bSubRace)
		return(m_chSubRace);

	return((BYTE)CValueList::GetComboBoxValue(m_cbSubRace));
}

BYTE CTabCharacteristicsDlg::GetGender()
{
	if (m_bGender)
		return(m_chGender);

	return((BYTE)CValueList::GetComboBoxValue(m_cbGender));
}

BYTE CTabCharacteristicsDlg::GetEnemyAlly()
{
	if (m_bEnemyAlly)
		return(m_chEnemyAlly);

	return((BYTE)CValueList::GetComboBoxValue(m_cbEnemyAlly));
}

BOOL CTabCharacteristicsDlg::EditValue(CComboBox &cb, DWORD &dwCurrentValue, BOOL &bKnownFlag, int nPad)
{
	CSetValueDlg d;

	d.SetCombo(&cb);
	if (bKnownFlag)
		d.SetCurrentValue(dwCurrentValue,nPad);
	else
	{
		int nIndex = cb.GetCurSel();
		if (nIndex == -1)
			return(FALSE);
		d.SetCurrentValue(cb.GetItemData(nIndex),nPad);
	}
	if (d.DoModal() != IDOK)
		return(FALSE);

	dwCurrentValue = d.GetValue();
	if (!SetValue(dwCurrentValue,cb))
		bKnownFlag = TRUE;
	else
		bKnownFlag = FALSE;

	return(TRUE);
}

BOOL CTabCharacteristicsDlg::EditValue(CComboBox &cb, BYTE &chValue, BOOL &bKnownFlag, int nPad)
{
	DWORD dwValue = chValue;
	if (!EditValue(cb,dwValue,bKnownFlag,nPad))
		return(FALSE);

	chValue = (BYTE)dwValue;
	return(TRUE);
}

BOOL CTabCharacteristicsDlg::EditValue(CComboBox &cb, WORD &wValue, BOOL &bKnownFlag, int nPad)
{
	DWORD dwValue = wValue;
	if (!EditValue(cb,dwValue,bKnownFlag,nPad))
		return(FALSE);

	wValue = (WORD)dwValue;
	return(TRUE);
}

void CTabCharacteristicsDlg::OnSetvalueAlignment() 
{
	EditValue(m_cbAlignment,m_chAlignment,m_bAlignment,2);
}

void CTabCharacteristicsDlg::OnSetvalueClass() 
{
	EditValue(m_cbClass,m_chClass,m_bClass,2);
}

void CTabCharacteristicsDlg::OnSetvalueGender() 
{
	EditValue(m_cbGender,m_chGender,m_bGender,2);
}

void CTabCharacteristicsDlg::OnSetvalueRace() 
{
	EditValue(m_cbRace,m_chRace,m_bRace,2);
}

void CTabCharacteristicsDlg::OnSetvalueSubRace()
{
	EditValue(m_cbSubRace, m_chSubRace, m_bSubRace, 2);
}

void CTabCharacteristicsDlg::OnSetvalueEnemyally() 
{
	EditValue(m_cbEnemyAlly,m_chEnemyAlly,m_bEnemyAlly,2);
}
