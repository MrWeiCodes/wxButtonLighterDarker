#pragma once

//This class inherits from the wx file [wxWidgets\include\wx\msw\button.h]
class wxTestButton :public wxButton
{
protected:
    wxColour m_currentBackgroundColour;
    bool  m_hasCurrentBgCol : 1;

public:
	wxTestButton();
    wxTestButton(wxWindow* parent,
        wxWindowID id,
        const wxString& label = wxEmptyString,
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        long style = 0,
        const wxValidator& validator = wxDefaultValidator,
        const wxString& name = wxASCII_STR(wxButtonNameStr));
	virtual ~wxTestButton() {};

    //Overloaded in wx file [wxWidgets\include\wx\msw\anybutton.h]
    virtual bool MSWOnDraw(WXDRAWITEMSTRUCT* wxdis) override;

    virtual bool SetCurrentBackgroundColour(const wxColour& colour);
    wxColour GetCurrentBackgroundColour() const;
    bool UseCurrentBgCol() const
    {
        return m_hasCurrentBgCol;
    }
private:
	wxDECLARE_NO_COPY_CLASS(wxTestButton);
};

