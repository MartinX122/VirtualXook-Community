#include "DataBaseSelectorDialog.h"

BEGIN_EVENT_TABLE(DataBaseSelectorDialog, wxDialog)

	EVT_CLOSE(DataBaseSelectorDialog::OnClose)

END_EVENT_TABLE()

DataBaseSelectorDialog::DataBaseSelectorDialog(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& position, const wxSize& size, long style)
	: wxDialog(parent, id, title, position, size, style)
{
	this->CreateGUIControls();
}

DataBaseSelectorDialog::~DataBaseSelectorDialog()
{
}

void DataBaseSelectorDialog::OnClose(wxCloseEvent& event)
{
	this->Destroy();
}

void DataBaseSelectorDialog::CreateGUIControls()
{

	SelectDataBaseLabel = new wxStaticText(this, ID_SELECTDATABASELABEL, _("Selecciona el archivo de base de datos"), wxPoint(20, 20), wxDefaultSize, 0, _("SelectDataBaseLabel"));
	SelectDataBasePicker = new wxFilePickerCtrl(this, ID_SELECTDATABASEPICKER, /*Ubicacion Predeterminada*/ _(""), _("Selecciona Base de Datos"), _("*.db"), wxPoint(20, 40), wxSize(260, 24), wxFLP_DEFAULT_STYLE, wxDefaultValidator, _("SelectDataBasePicker"));

	LoginBox = new wxStaticBox(this, ID_LOGINBOX, _("Ingresa tus credenciales para acceder"), wxPoint(20, 80), wxSize(260, 160));

	UserLabel = new wxStaticText(this, ID_USERLABEL, _("Usuario"), wxPoint(40, 100), wxDefaultSize, 0, _("UserLabel"));
	UserEdit = new wxTextCtrl(this, ID_USEREDIT, _(""), wxPoint(40, 121), wxSize(220, 21), 0, wxDefaultValidator, _("UserEdit"));

	PassLabel = new wxStaticText(this, ID_PASSLABEL, _("Contraseña"), wxPoint(40, 160), wxDefaultSize, 0, _("PassLabel"));
	PassEdit = new wxTextCtrl(this, ID_PASSEDIT, _(""), wxPoint(40, 180), wxSize(220, 21), wxTE_PASSWORD, wxDefaultValidator, _("PassEdit"));

	AcceptButton = new wxButton(this, ID_ACCEPTBUTTON, _("Aceptar"), wxPoint(181, 250), wxSize(99, 23), 0, wxDefaultValidator, _("AcceptButton"));

	CancelButton = new wxButton(this, ID_CANCELBUTTON, _("Cancelar"), wxPoint(70, 250), wxSize(99, 23), 0, wxDefaultValidator, _("CancelButton"));

	this->SetTitle(_("Base de Datos"));
	this->SetIcon(wxNullIcon);
	this->SetSize(268, 28, 320, 334);
	this->CentreOnParent();
}
