#ifndef __MAINFRAME_H__
#define __MAINFRAME_H__


#ifndef WX_PRECOMP
#include "wx/wx.h"
#include "wx/frame.h"
#else
#include "wx/wxprec.h"
#endif

#include "wx/menu.h"
#include "wx/translation.h"
#include "wx/tglbtn.h"
#include "wx/artprov.h"
#include "wx/statusbr.h"
#include "wx/treectrl.h"
#include "wx/spinctrl.h"
#include "wx/wxhtml.h"
#include "wx/ribbon/bar.h"
#include "wx/ribbon/buttonbar.h"
#include "wx/ribbon/gallery.h"
#include "wx/ribbon/toolbar.h"
#include "wx/aui/aui.h"
#include "wx/grid.h"
#include "wx/dataview.h"

//#include "LoginDialog.h"

#include "circle.xpm"
#include "Images/Refresh.xpm"


#include "Language.h"
#include "DataBaseSelectorDialog.h"

class MainFrame : public wxFrame
{
	DECLARE_EVENT_TABLE();

public:
	MainFrame(
		wxWindow* parent,
		wxWindowID id = 1,
		const wxString& title = wxString::Format(""),
		const wxPoint& pos = wxDefaultPosition,
		const wxSize& size = wxDefaultSize,
		long style = wxCAPTION | wxRESIZE_BORDER | wxSYSTEM_MENU | wxMINIMIZE_BOX | wxMAXIMIZE_BOX | wxCLOSE_BOX);


	virtual ~MainFrame();

	void SetLocale(wxLocale* _locale);

	enum
	{
		ID_EXAMPLE,
		ID_EMPTY,

		ID_FILEMENU_ABOUT,
		
		ID_TOOLMENU_OPTIONS,

		ID_STANDARTOOLBARNEWITEM,
		ID_STANDARTOOLBAROPENITEM,
		ID_STANDARTOOLBARSAVEITEM,
		ID_STANDARTOOLBARCOPYITEM,
		ID_STANDARTOOLBARPASTEITEM,
		ID_DATAOPTIONSTOOLBARCREATEITEM,
		ID_DATAOPTIONSTOOLBARDELETEITEM,
		ID_DATAOPTIONSTOOLBARSIGNITEM,
		ID_DATAOPTIONSTOOLBARFIRSTITEM,
		ID_DATAOPTIONSTOOLBARPREVITEM,
		ID_DATAOPTIONSTOOLBARNEXTITEM,
		ID_DATAOPTIONSTOOLBARLASTITEM,

		ID_CustomizeToolbar,
		ID_SampleItem,

		ID_EXIT
	};

	
private:

	void OnClose(wxCloseEvent& event);

	void CreateGUIControls();

	wxLocale* locale;
	wxMenuBar* MenuBar;
	wxAuiManager* AuiMgr;
	wxAuiToolBarItemArray prepend_items;
	wxAuiToolBarItemArray append_items;
	wxAuiToolBarItem item;

	long m_notebook_style;

	//wxLocale& m_locale;

	wxAuiNotebook* CreateNotebook();
	wxHtmlWindow* CreateHTMLCtrl(wxWindow* parent);
	wxString GetIntroText();
	wxTreeCtrl* CreateTreeCtrl();
	wxTreeCtrl* CreateNavView();
	wxGrid* CreateGrid();
	wxDataViewListCtrl* CreateList1();
	
	void OnExample(wxCommandEvent& evt);
	void OnFileMenuAbout(wxCommandEvent& evt);
	void OnToolMenuOptions(wxCommandEvent& evt);
	void OnCustomizeToolbar(wxCommandEvent& evt);
	void OnExit(wxCommandEvent& evt);

	//wxDECLARE_EVENT_TABLE();
};

#endif