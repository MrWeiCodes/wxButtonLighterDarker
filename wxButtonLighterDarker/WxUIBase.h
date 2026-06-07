///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-903526e)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include "wxTestButton.h"
#include <wx/button.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/stattext.h>
#include <wx/slider.h>
#include <wx/textctrl.h>
#include <wx/choice.h>
#include <wx/radiobut.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class Frame_Main
///////////////////////////////////////////////////////////////////////////////
class Frame_Main : public wxFrame
{
	private:

	protected:
		wxTestButton* m_button_test;
		wxStaticText* m_staticText2;
		wxSlider* m_slider_background_r;
		wxTextCtrl* m_textCtrl_background_r;
		wxStaticText* m_staticText21;
		wxSlider* m_slider_background_g;
		wxTextCtrl* m_textCtrl_background_g;
		wxStaticText* m_staticText22;
		wxSlider* m_slider_background_b;
		wxTextCtrl* m_textCtrl_background_b;
		wxStaticText* m_staticText212;
		wxStaticText* m_staticText_background_gray;
		wxStaticText* m_staticText2121;
		wxStaticText* m_staticText_background_lightness;
		wxButton* m_button_background_def;
		wxStaticText* m_staticText23;
		wxSlider* m_slider_foreground_r;
		wxTextCtrl* m_textCtrl_foreground_r;
		wxStaticText* m_staticText211;
		wxSlider* m_slider_foreground_g;
		wxTextCtrl* m_textCtrl_foreground_g;
		wxStaticText* m_staticText221;
		wxSlider* m_slider_foreground_b;
		wxTextCtrl* m_textCtrl_foreground_b;
		wxButton* m_button_foreground_def;
		wxStaticText* m_staticText31;
		wxChoice* m_choice_mode;
		wxStaticText* m_staticText_gray;
		wxSlider* m_slider_gray;
		wxTextCtrl* m_textCtrl_gray;
		wxStaticText* m_staticText_lightness;
		wxSlider* m_slider_lightness;
		wxTextCtrl* m_textCtrl_lightness;
		wxRadioButton* m_radioBtn_dl;
		wxRadioButton* m_radioBtn_ld;
		wxStaticText* m_staticText181;
		wxSlider* m_slider_change;
		wxTextCtrl* m_textCtrl_change;
		wxButton* m_button_ld_def;

		// Virtual event handlers, override them in your derived class
		virtual void EventScrollBackgroundR( wxScrollEvent& event ) { event.Skip(); }
		virtual void EventKillFocusBackgroundR( wxFocusEvent& event ) { event.Skip(); }
		virtual void EventTextEnterBackgroundR( wxCommandEvent& event ) { event.Skip(); }
		virtual void EventScrollBackgroundG( wxScrollEvent& event ) { event.Skip(); }
		virtual void EventKillFocusBackgroundG( wxFocusEvent& event ) { event.Skip(); }
		virtual void EventTextEnterBackgroundG( wxCommandEvent& event ) { event.Skip(); }
		virtual void EventScrollBackgroundB( wxScrollEvent& event ) { event.Skip(); }
		virtual void EventKillFocusBackgroundB( wxFocusEvent& event ) { event.Skip(); }
		virtual void EventTextEnterBackgroundB( wxCommandEvent& event ) { event.Skip(); }
		virtual void EventButtonClickBackgroundDef( wxCommandEvent& event ) { event.Skip(); }
		virtual void EventScrollForegroundR( wxScrollEvent& event ) { event.Skip(); }
		virtual void EventKillFocusForegroundR( wxFocusEvent& event ) { event.Skip(); }
		virtual void EventTextEnterForegroundR( wxCommandEvent& event ) { event.Skip(); }
		virtual void EventScrollForegroundG( wxScrollEvent& event ) { event.Skip(); }
		virtual void EventKillFocusForegroundG( wxFocusEvent& event ) { event.Skip(); }
		virtual void EventTextEnterForegroundG( wxCommandEvent& event ) { event.Skip(); }
		virtual void EventScrollForegroundB( wxScrollEvent& event ) { event.Skip(); }
		virtual void EventKillFocusForegroundB( wxFocusEvent& event ) { event.Skip(); }
		virtual void EventTextEnterForegroundB( wxCommandEvent& event ) { event.Skip(); }
		virtual void EventButtonClickForegroundDef( wxCommandEvent& event ) { event.Skip(); }
		virtual void EventChoiceMode( wxCommandEvent& event ) { event.Skip(); }
		virtual void EventScrollGray( wxScrollEvent& event ) { event.Skip(); }
		virtual void EventKillFocusGray( wxFocusEvent& event ) { event.Skip(); }
		virtual void EventTextEnterGray( wxCommandEvent& event ) { event.Skip(); }
		virtual void EventScrollLightness( wxScrollEvent& event ) { event.Skip(); }
		virtual void EventKillFocusLightness( wxFocusEvent& event ) { event.Skip(); }
		virtual void EventTextEnterLightness( wxCommandEvent& event ) { event.Skip(); }
		virtual void EventRadioDL( wxCommandEvent& event ) { event.Skip(); }
		virtual void EventRadioLD( wxCommandEvent& event ) { event.Skip(); }
		virtual void EventScrollChange( wxScrollEvent& event ) { event.Skip(); }
		virtual void EventKillFocusChange( wxFocusEvent& event ) { event.Skip(); }
		virtual void EventTextEnterChange( wxCommandEvent& event ) { event.Skip(); }
		virtual void EventButtonClickLdDef( wxCommandEvent& event ) { event.Skip(); }


	public:

		Frame_Main( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("wxButtonLighterDarker"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~Frame_Main();

};

