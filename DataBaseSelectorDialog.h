
#ifndef __DATABASESELECTORDIALOG_H__
#define __DATABASESELECTORDIALOG_H__


#ifndef WX_PRECOMP
#include "wx/wx.h"
#include "wx/dialog.h"
#else
#include "wx/wxprec.h"
#endif

#include "wx/textctrl.h"
#include "wx/statbox.h"
#include "wx/button.h"
#include "wx/filepicker.h"
#include "wx/stattext.h"


class DataBaseSelectorDialog : public wxDialog
{	

public:
	DataBaseSelectorDialog(
		wxWindow* parent, 
		wxWindowID id = 1, 
		const wxString& title = wxT("DataBaseSelector"), 
		const wxPoint& pos = wxDefaultPosition, 
		const wxSize& size = wxDefaultSize, 
		long style = wxCAPTION | wxCLOSE_BOX);

	virtual ~DataBaseSelectorDialog();


private:

	DECLARE_EVENT_TABLE();

	
	wxTextCtrl* PassEdit;
	wxStaticText* PassLabel;
	wxTextCtrl* UserEdit;
	wxStaticText* UserLabel;
	wxStaticBox* LoginBox;
	wxButton* CancelButton;
	wxButton* AcceptButton;
	wxFilePickerCtrl* SelectDataBasePicker;
	wxStaticText* SelectDataBaseLabel;

	enum
	{
		ID_SELECTDATABASEPICKER = 1001,
		ID_SELECTDATABASELABEL = 1002,

		ID_LOGINBOX = 1003,
		
		ID_USERLABEL = 1004,
		ID_USEREDIT = 1005,
		
		ID_PASSLABEL = 1006,
		ID_PASSEDIT = 1007,


		ID_CANCELBUTTON = 1009,
		ID_ACCEPTBUTTON = 1008,
		
	
		ID_DUMMY_VALUE_ 
	};

private:
	void OnClose(wxCloseEvent& event);
	void CreateGUIControls();
};

#endif