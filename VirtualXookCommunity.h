#ifndef WX_PRECOMP
#include "wx/wx.h"
#else
#include "wx/wxprec.h"
#endif

#include "wx/splash.h"
#include "wx/intl.h"
#include "wx/fileconf.h"
#include "wx/translation.h"
//#include "wx/wxsqlite3.h"

#include "MainFrame.h"

class VirtualXook : public wxApp
{

public:
	bool OnInit();
	int OnExit();
};

//#endif
