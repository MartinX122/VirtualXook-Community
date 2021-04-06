//VirtualXookCommunity

#include "VirtualXookCommunity.h"

#include "Images/SplashScreen.xpm"

IMPLEMENT_APP(VirtualXook)

bool VirtualXook::OnInit()
{   

    this->SetAppName("VirtualXook Community");
    this->SetVendorName("Hector Martin Ruiz Rosas");

    long language = wxLANGUAGE_SPANISH_MEXICAN;
    wxLocale* locale = new wxLocale();
    
    locale->Init(language, wxLOCALE_DONT_LOAD_DEFAULT);


    MainFrame* frame = new MainFrame(NULL);

    frame->SetLocale(locale);

    this->SetTopWindow(frame);
    
    //SkinDocSplashScreen *splash = new  SkinDocSplashScreen();

    
    wxSplashScreen* splash = new wxSplashScreen(wxBitmap(SHASHSCREEN),
        wxSPLASH_CENTRE_ON_SCREEN | wxSPLASH_TIMEOUT,
        2000, frame, -1, wxDefaultPosition, wxDefaultSize,
        wxBORDER_SIMPLE | wxSTAY_ON_TOP);
    
    wxYield();
    wxSleep(2);

    frame->Show();

    return true;
}

int VirtualXook::OnExit()
{
    return 0;
}