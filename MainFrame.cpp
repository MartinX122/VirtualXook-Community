#include "MainFrame.h"

BEGIN_EVENT_TABLE(MainFrame, wxFrame)
	EVT_CLOSE(MainFrame::OnClose)
	
	//EVT_MENU(MainFrame::ID_EXAMPLE, MainFrame::OnExample)
	//EVT_MENU(MainFrame::ID_EXAMPLE, MainFrame::OnExample)
	
	EVT_MENU(MainFrame::ID_CustomizeToolbar, MainFrame::OnCustomizeToolbar)
	
	
	EVT_MENU(MainFrame::ID_FILEMENU_ABOUT, MainFrame::OnFileMenuAbout)
	EVT_MENU(MainFrame::ID_TOOLMENU_OPTIONS, MainFrame::OnToolMenuOptions)

	EVT_MENU(MainFrame::ID_EXIT, MainFrame::OnExit)
END_EVENT_TABLE()



MainFrame::MainFrame(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxFrame(parent, id, title, pos, size, style)
{
	CreateGUIControls();

	this->locale;
	//this->DefaultLoginDialog = new LoginDialog(NULL);
	//this->DefaultLoginDialog->ShowModal();

}

MainFrame::~MainFrame()
{
}

void MainFrame::SetLocale(wxLocale* _locale)
{
	this->locale = _locale;
}

void MainFrame::CreateGUIControls()
{

	AuiMgr = new wxAuiManager();
	MenuBar = new wxMenuBar();

	AuiMgr->SetManagedWindow(this);

	int iconSize = AuiMgr->GetArtProvider()->GetMetric(wxAUI_DOCKART_CAPTION_SIZE);
	iconSize &= ~1;

	m_notebook_style = wxAUI_NB_DEFAULT_STYLE | wxAUI_NB_TAB_EXTERNAL_MOVE | wxNO_BORDER;

	item.SetKind(wxITEM_SEPARATOR);
	append_items.Add(item);
	item.SetKind(wxITEM_NORMAL);
	item.SetId(ID_CustomizeToolbar);
	item.SetLabel(_("Customize..."));
	append_items.Add(item);

	wxMenu* File_menu = new wxMenu;
	File_menu->Append(ID_FILEMENU_ABOUT, _("&About"));
	File_menu->AppendSeparator();
	File_menu->Append(ID_EXIT, _("Exit"));
	MenuBar->Append(File_menu, _("&File"));

	wxMenu* Tools_menu = new wxMenu;
	Tools_menu->Append(ID_TOOLMENU_OPTIONS, _("&Options"));
	MenuBar->Append(Tools_menu, _("&Tool"));

	wxMenu* View_menu = new wxMenu;
	View_menu->Append(ID_EXAMPLE, _("Example"));
	MenuBar->Append(View_menu, _("&View"));

	item.SetKind(wxITEM_SEPARATOR);
	append_items.Add(item);
	item.SetKind(wxITEM_NORMAL);
	item.SetId(ID_CustomizeToolbar);
	item.SetLabel(_("Customize..."));
	append_items.Add(item);

	wxAuiToolBar* StandarToolBar = new wxAuiToolBar(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_TB_DEFAULT_STYLE | wxAUI_TB_OVERFLOW | wxAUI_TB_HORIZONTAL | wxAUI_TB_TEXT | wxAUI_TB_HORZ_TEXT);
	StandarToolBar->SetToolBitmapSize(FromDIP(wxSize(32, 32)));

	wxBitmap StandarToolBarNewItemIcon   =   wxArtProvider::GetBitmap(wxART_NORMAL_FILE, wxART_OTHER, FromDIP(wxSize(16, 16)));
	wxBitmap StandarToolBarOpenItemIcon  =   wxArtProvider::GetBitmap(wxART_FILE_OPEN, wxART_OTHER, FromDIP(wxSize(16, 16)));
	wxBitmap StandarToolBarSaveItemIcon  =   wxArtProvider::GetBitmap(wxART_FILE_SAVE, wxART_OTHER, FromDIP(wxSize(16, 16)));
	wxBitmap StandarToolBarCutItemIcon   =   wxArtProvider::GetBitmap(wxART_CUT, wxART_OTHER, FromDIP(wxSize(16, 16)));
	wxBitmap StandarToolBarCopyItemIcon  =   wxArtProvider::GetBitmap(wxART_COPY, wxART_OTHER, FromDIP(wxSize(16, 16)));
	wxBitmap StandarToolBarPasteItemIcon =   wxArtProvider::GetBitmap(wxART_PASTE, wxART_OTHER, FromDIP(wxSize(16, 16)));

	StandarToolBar->AddTool(ID_STANDARTOOLBARNEWITEM,  "Nuevo",   StandarToolBarNewItemIcon);
	StandarToolBar->AddTool(ID_STANDARTOOLBAROPENITEM, "Abrir",   StandarToolBarOpenItemIcon);
	StandarToolBar->AddTool(ID_STANDARTOOLBARSAVEITEM, "Guardar", StandarToolBarSaveItemIcon);
	StandarToolBar->AddSeparator();
	StandarToolBar->AddTool(ID_STANDARTOOLBAROPENITEM, "Cortar",  StandarToolBarCutItemIcon);
	StandarToolBar->AddTool(ID_STANDARTOOLBARNEWITEM,  "Copiar",  StandarToolBarCopyItemIcon);
	StandarToolBar->AddTool(ID_STANDARTOOLBAROPENITEM, "Pegar",   StandarToolBarPasteItemIcon);

	StandarToolBar->Realize();


	wxAuiToolBar* DataOptionsToolBar = new wxAuiToolBar(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_TB_DEFAULT_STYLE | wxAUI_TB_OVERFLOW | wxAUI_TB_HORZ_TEXT );
	DataOptionsToolBar->SetToolBitmapSize(FromDIP(wxSize(16, 16)));

	wxBitmap DataOptionsToolBarAddItemIcon    = wxArtProvider::GetBitmap(wxART_NEW, wxART_OTHER, FromDIP(wxSize(16, 16)));
	wxBitmap DataOptionsToolBarDeleteItemIcon = wxArtProvider::GetBitmap(wxART_DELETE, wxART_OTHER, FromDIP(wxSize(16, 16)));
	
	wxBitmap DataOptionsToolBarRefreshItemIcon = wxBitmap(IconRefresh,16,16);
	wxBitmap DataOptionsToolBarFirstItemIcon =   wxArtProvider::GetBitmap(wxART_GOTO_FIRST, wxART_OTHER, FromDIP(wxSize(16, 16)));
	wxBitmap DataOptionsToolBarPrevItemIcon  =   wxArtProvider::GetBitmap(wxART_GO_BACK, wxART_OTHER, FromDIP(wxSize(16, 16)));
	wxBitmap DataOptionsToolBarNextItemIcon  =   wxArtProvider::GetBitmap(wxART_GO_FORWARD, wxART_OTHER, FromDIP(wxSize(16, 16)));
	wxBitmap DataOptionsToolBarLastItemIcon  =   wxArtProvider::GetBitmap(wxART_GOTO_LAST, wxART_OTHER, FromDIP(wxSize(16, 16)));

	DataOptionsToolBar->AddTool(ID_DATAOPTIONSTOOLBARCREATEITEM, "Crear",   DataOptionsToolBarAddItemIcon);
	DataOptionsToolBar->AddTool(ID_DATAOPTIONSTOOLBARDELETEITEM, "Borrar",  DataOptionsToolBarDeleteItemIcon);
	DataOptionsToolBar->AddSeparator();
	DataOptionsToolBar->AddTool(ID_DATAOPTIONSTOOLBARSIGNITEM,  "Sincronizar",  DataOptionsToolBarRefreshItemIcon);
	DataOptionsToolBar->AddTool(ID_DATAOPTIONSTOOLBARFIRSTITEM, "Primero",      DataOptionsToolBarFirstItemIcon);
	DataOptionsToolBar->AddTool(ID_DATAOPTIONSTOOLBARPREVITEM,  "Anterior",     DataOptionsToolBarPrevItemIcon);
	DataOptionsToolBar->AddTool(ID_DATAOPTIONSTOOLBARNEXTITEM,  "Siguiente",    DataOptionsToolBarNextItemIcon);
	DataOptionsToolBar->AddTool(ID_DATAOPTIONSTOOLBARLASTITEM,  "Ultimo",       DataOptionsToolBarLastItemIcon);
	DataOptionsToolBar->Realize();


	AuiMgr->AddPane(CreateNavView(), wxAuiPaneInfo().
			Name("NavView").Caption("Modules").
			Left().Layer(1).Position(1).
			CloseButton(true).MaximizeButton(false));

	AuiMgr->AddPane(CreateNotebook(), wxAuiPaneInfo().Name("notebook_content").
		CenterPane().PaneBorder(false));

	AuiMgr->AddPane(StandarToolBar, wxAuiPaneInfo().
		Name("StandarToolBar").Caption("Standar Tool Bar").
		ToolbarPane().Top().Row(1));

	AuiMgr->AddPane(DataOptionsToolBar, wxAuiPaneInfo().
		Name("DataOptionsToolBar").Caption("Data Options Tool Bar").
		ToolbarPane().Top().Row(1));

	wxString perspective_all = AuiMgr->SavePerspective();

	int i, count;
	wxAuiPaneInfoArray& all_panes = AuiMgr->GetAllPanes();
	for (i = 0, count = all_panes.GetCount(); i < count; ++i)
		if (!all_panes.Item(i).IsToolbar())
			all_panes.Item(i).Hide();

	AuiMgr->GetPane("NavView").Show().Left().Layer(0).Row(0).Position(0);

	AuiMgr->GetPane("notebook_content").Show();

	wxString perspective_default = AuiMgr->SavePerspective();

	AuiMgr->Update();
		
	this->SetMenuBar(MenuBar);
	this->CreateStatusBar();
	this->SetMinSize(FromDIP(wxSize(400, 300)));
	this->SetTitle(wxString("VirtualXook Community"));
	this->SetIcon(wxNullIcon);
	this->SetSize(8, 8, 800, 640);
	this->SetBackgroundColour(wxColour(*wxWHITE));
	this->Center();

	this->GetStatusBar()->SetStatusText(_("Ready"));
}

void MainFrame::OnExample(wxCommandEvent& evt)
{
	wxMessageBox("Example");
}


void  MainFrame::OnCustomizeToolbar(wxCommandEvent& evt)
{
	wxMessageBox(_("Customize Toolbar clicked"));
}

void MainFrame::OnClose(wxCloseEvent& event)
{
	this->Destroy();
}

wxAuiNotebook* MainFrame::CreateNotebook()
{
	
	wxSize client_size = GetClientSize();

	wxAuiNotebook* ctrl = new wxAuiNotebook(this, wxID_ANY,
		wxPoint(client_size.x, client_size.y),
		FromDIP(wxSize(430, 200)),
		m_notebook_style);

	ctrl->Freeze();

	wxBitmap page_bmp = wxArtProvider::GetBitmap(wxART_NORMAL_FILE, wxART_OTHER, FromDIP(wxSize(16, 16)));

	ctrl->AddPage(CreateHTMLCtrl(ctrl), "Welcome to wxAUI", false, page_bmp);
	ctrl->SetPageToolTip(0, "Welcome to wxAUI (this is a page tooltip)");

	ctrl->AddPage(CreateGrid(), "TABLE", false, page_bmp);
	ctrl->SetPageToolTip(1, "TABLE");

	ctrl->AddPage(CreateList1(), "LIST", false, page_bmp);
	ctrl->SetPageToolTip(2, "LIST");
	
	//ctrl->AddPage(panel, "wxPanel", false, page_bmp);

	ctrl->Thaw();
	return ctrl;
}

wxHtmlWindow* MainFrame::CreateHTMLCtrl(wxWindow* parent)
{
	if (!parent)
		parent = this;

	wxHtmlWindow* ctrl = new wxHtmlWindow(parent, wxID_ANY,
		wxDefaultPosition,
		FromDIP(wxSize(400, 300)));
	ctrl->SetPage(GetIntroText());
	return ctrl;
}

wxTreeCtrl* MainFrame::CreateNavView()
{

	wxTreeCtrl* tree = new wxTreeCtrl(this, wxID_ANY,
		wxPoint(0, 0),
		FromDIP(wxSize(160, 250)),
		wxTR_HAS_BUTTONS | wxTR_LINES_AT_ROOT | wxTR_HIDE_ROOT | wxTR_DEFAULT_STYLE | wxNO_BORDER);

	wxSize size = FromDIP(wxSize(16, 16));
	wxImageList* imglist = new wxImageList(size.x, size.y, true, 2);

	imglist->Add(wxArtProvider::GetBitmap(wxART_FOLDER, wxART_OTHER, size));
	imglist->Add(wxArtProvider::GetBitmap(wxART_REPORT_VIEW, wxART_OTHER, size));
	tree->AssignImageList(imglist);

	wxTreeItemId root = tree->AddRoot(_(""));
	wxArrayTreeItemIds items;

	items.Add(tree->AppendItem(root, "Administración", 0));
	tree->AppendItem(items.Item(0), "Contactos", 1);

	items.Add(tree->AppendItem(root, "Calificaciones", 0));
	tree->AppendItem(items.Item(1), "Subitem 1", 1);
	tree->AppendItem(items.Item(1), "Subitem 2", 1);
	tree->AppendItem(items.Item(1), "Subitem 3", 1);
	tree->AppendItem(items.Item(1), "Subitem 4", 1);
	tree->AppendItem(items.Item(1), "Subitem 5", 1);

	//tree->Expand(root);
	
	return tree;
}

wxString MainFrame::GetIntroText()
{
	const char* text =
		"<html><body>"
		"<h3>Welcome to VirtualXook Community</h3>"
		"</body></html>";

	return wxString::FromAscii(text);
}

wxGrid* MainFrame::CreateGrid()
{
	wxGrid* grid = new wxGrid(this, wxID_ANY,
		wxPoint(0, 0),
		FromDIP(wxSize(150, 250)),
		wxNO_BORDER | wxWANTS_CHARS);
	grid->CreateGrid(50, 20);
	return grid;
}


wxDataViewListCtrl* MainFrame::CreateList1() {

	wxDataViewListCtrl* listctrl = new wxDataViewListCtrl(this, wxID_ANY);
	listctrl->AppendToggleColumn("Toggle");
	listctrl->AppendTextColumn("Text");
	wxVector<wxVariant> data;
	data.push_back(wxVariant(true));
	data.push_back(wxVariant("row 1"));
	listctrl->AppendItem(data);
	data.clear();
	data.push_back(wxVariant(false));
	data.push_back(wxVariant("row 3"));
	listctrl->AppendItem(data);

	return listctrl;
}

/*Menu Actions*/

void MainFrame::OnFileMenuAbout(wxCommandEvent& evt)
{
	wxString localeInfo;
	wxString locale = this->locale->GetLocale();
	wxString sysname = this->locale->GetSysName();
	wxString canname = this->locale->GetCanonicalName();

	localeInfo.Printf(_("Language: %s\nSystem locale name: %s\nCanonical locale name: %s\n"),
		locale, sysname, canname);

	wxMessageDialog dlg(
		this,
		wxString(_("VirtualXook Community\n(c) 2021 Hector Martin Ruiz Rosas"))
		+ "\n\n"
		+ localeInfo,
		_("About VirtualXook Community"),
		wxOK | wxICON_INFORMATION
	);
	dlg.ShowModal();
}

void MainFrame::OnToolMenuOptions(wxCommandEvent& evt)
{
	wxMessageBox("Options");

}

void MainFrame::OnExit(wxCommandEvent& evt)
{
	Close(true);
}
