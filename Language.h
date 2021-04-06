#include <wx/language.h>

static const wxLanguage langIds[] =
{
    wxLANGUAGE_DEFAULT,
    wxLANGUAGE_SPANISH,
    wxLANGUAGE_SPANISH_MEXICAN,
    wxLANGUAGE_ENGLISH,
    wxLANGUAGE_ENGLISH_US
};

const wxString langNames[] =
{
    "System default",
    "Espa�ol",
    "Espa�ol (M�xico)",
    "English",
    "English (USA)"
};

wxCOMPILE_TIME_ASSERT(WXSIZEOF(langNames) == WXSIZEOF(langIds),LangArraysMismatch);