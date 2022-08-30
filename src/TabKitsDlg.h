#pragma once


// TabKitsDlg dialog

class TabKitsDlg : public CDialog
{
	DECLARE_DYNAMIC(TabKitsDlg)

public:
	TabKitsDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~TabKitsDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD =  };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
