///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-903526e)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "stdafx.h"

#include "WxUIBase.h"

///////////////////////////////////////////////////////////////////////////

Frame_Main::Frame_Main( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 500,-1 ), wxDefaultSize );
	this->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );
	this->SetBackgroundColour( wxColour( 255, 255, 255 ) );

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );

	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( wxVERTICAL, this, _("Test Area") );

	m_button_test = new wxTestButton( sbSizer1->GetStaticBox(), wxID_ANY, _("Test wxButton"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer1->Add( m_button_test, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer5->Add( sbSizer1, 0, wxEXPAND, 5 );

	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( wxVERTICAL, this, _("Button background setting") );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText2 = new wxStaticText( sbSizer2->GetStaticBox(), wxID_ANY, _("R:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer6->Add( m_staticText2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_slider_background_r = new wxSlider( sbSizer2->GetStaticBox(), wxID_ANY, 225, 0, 255, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL|wxSL_MIN_MAX_LABELS );
	bSizer6->Add( m_slider_background_r, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrl_background_r = new wxTextCtrl( sbSizer2->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	m_textCtrl_background_r->SetMaxSize( wxSize( 50,-1 ) );

	bSizer6->Add( m_textCtrl_background_r, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	sbSizer2->Add( bSizer6, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer61;
	bSizer61 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText21 = new wxStaticText( sbSizer2->GetStaticBox(), wxID_ANY, _("G:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText21->Wrap( -1 );
	bSizer61->Add( m_staticText21, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_slider_background_g = new wxSlider( sbSizer2->GetStaticBox(), wxID_ANY, 225, 0, 255, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL|wxSL_MIN_MAX_LABELS );
	bSizer61->Add( m_slider_background_g, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrl_background_g = new wxTextCtrl( sbSizer2->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	m_textCtrl_background_g->SetMaxSize( wxSize( 50,-1 ) );

	bSizer61->Add( m_textCtrl_background_g, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	sbSizer2->Add( bSizer61, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer62;
	bSizer62 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText22 = new wxStaticText( sbSizer2->GetStaticBox(), wxID_ANY, _("B:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText22->Wrap( -1 );
	bSizer62->Add( m_staticText22, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_slider_background_b = new wxSlider( sbSizer2->GetStaticBox(), wxID_ANY, 225, 0, 255, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL|wxSL_MIN_MAX_LABELS );
	bSizer62->Add( m_slider_background_b, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrl_background_b = new wxTextCtrl( sbSizer2->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	m_textCtrl_background_b->SetMaxSize( wxSize( 50,-1 ) );

	bSizer62->Add( m_textCtrl_background_b, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	sbSizer2->Add( bSizer62, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer29;
	bSizer29 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText212 = new wxStaticText( sbSizer2->GetStaticBox(), wxID_ANY, _("Gray:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText212->Wrap( -1 );
	bSizer29->Add( m_staticText212, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText_background_gray = new wxStaticText( sbSizer2->GetStaticBox(), wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_background_gray->Wrap( -1 );
	bSizer29->Add( m_staticText_background_gray, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText2121 = new wxStaticText( sbSizer2->GetStaticBox(), wxID_ANY, _("Lightness:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2121->Wrap( -1 );
	bSizer29->Add( m_staticText2121, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_staticText_background_lightness = new wxStaticText( sbSizer2->GetStaticBox(), wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_background_lightness->Wrap( -1 );
	bSizer29->Add( m_staticText_background_lightness, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer29->Add( 0, 0, 1, wxEXPAND, 5 );

	m_button_background_def = new wxButton( sbSizer2->GetStaticBox(), wxID_ANY, _("Restore default values"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer29->Add( m_button_background_def, 0, wxALL, 5 );


	sbSizer2->Add( bSizer29, 1, wxEXPAND, 5 );


	bSizer5->Add( sbSizer2, 0, wxEXPAND, 5 );

	wxStaticBoxSizer* sbSizer21;
	sbSizer21 = new wxStaticBoxSizer( wxVERTICAL, this, _("Button foreground setting") );

	wxBoxSizer* bSizer63;
	bSizer63 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText23 = new wxStaticText( sbSizer21->GetStaticBox(), wxID_ANY, _("R:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText23->Wrap( -1 );
	bSizer63->Add( m_staticText23, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_slider_foreground_r = new wxSlider( sbSizer21->GetStaticBox(), wxID_ANY, 0, 0, 255, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL|wxSL_MIN_MAX_LABELS );
	bSizer63->Add( m_slider_foreground_r, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrl_foreground_r = new wxTextCtrl( sbSizer21->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	m_textCtrl_foreground_r->SetMaxSize( wxSize( 50,-1 ) );

	bSizer63->Add( m_textCtrl_foreground_r, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	sbSizer21->Add( bSizer63, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer611;
	bSizer611 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText211 = new wxStaticText( sbSizer21->GetStaticBox(), wxID_ANY, _("G:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText211->Wrap( -1 );
	bSizer611->Add( m_staticText211, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_slider_foreground_g = new wxSlider( sbSizer21->GetStaticBox(), wxID_ANY, 0, 0, 255, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL|wxSL_MIN_MAX_LABELS );
	bSizer611->Add( m_slider_foreground_g, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrl_foreground_g = new wxTextCtrl( sbSizer21->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	m_textCtrl_foreground_g->SetMaxSize( wxSize( 50,-1 ) );

	bSizer611->Add( m_textCtrl_foreground_g, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	sbSizer21->Add( bSizer611, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer621;
	bSizer621 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText221 = new wxStaticText( sbSizer21->GetStaticBox(), wxID_ANY, _("B:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText221->Wrap( -1 );
	bSizer621->Add( m_staticText221, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_slider_foreground_b = new wxSlider( sbSizer21->GetStaticBox(), wxID_ANY, 0, 0, 255, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL|wxSL_MIN_MAX_LABELS );
	bSizer621->Add( m_slider_foreground_b, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrl_foreground_b = new wxTextCtrl( sbSizer21->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	m_textCtrl_foreground_b->SetMaxSize( wxSize( 50,-1 ) );

	bSizer621->Add( m_textCtrl_foreground_b, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	sbSizer21->Add( bSizer621, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer291;
	bSizer291 = new wxBoxSizer( wxHORIZONTAL );


	bSizer291->Add( 0, 0, 1, wxEXPAND, 5 );

	m_button_foreground_def = new wxButton( sbSizer21->GetStaticBox(), wxID_ANY, _("Restore default values"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer291->Add( m_button_foreground_def, 0, wxALL, 5 );


	sbSizer21->Add( bSizer291, 1, wxEXPAND, 5 );


	bSizer5->Add( sbSizer21, 1, wxEXPAND, 5 );

	wxStaticBoxSizer* sbSizer8;
	sbSizer8 = new wxStaticBoxSizer( wxVERTICAL, this, _("Hot state lighter or darker setting") );

	wxBoxSizer* bSizer39;
	bSizer39 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText31 = new wxStaticText( sbSizer8->GetStaticBox(), wxID_ANY, _("Mode:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText31->Wrap( -1 );
	bSizer39->Add( m_staticText31, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	wxString m_choice_modeChoices[] = { _("Gray Mode"), _("Lightness Mode") };
	int m_choice_modeNChoices = sizeof( m_choice_modeChoices ) / sizeof( wxString );
	m_choice_mode = new wxChoice( sbSizer8->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice_modeNChoices, m_choice_modeChoices, 0 );
	m_choice_mode->SetSelection( 1 );
	bSizer39->Add( m_choice_mode, 0, wxALL, 5 );


	sbSizer8->Add( bSizer39, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer24;
	bSizer24 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText_gray = new wxStaticText( sbSizer8->GetStaticBox(), wxID_ANY, _("Gray Range:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_gray->Wrap( -1 );
	bSizer24->Add( m_staticText_gray, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_slider_gray = new wxSlider( sbSizer8->GetStaticBox(), wxID_ANY, 128, 0, 255, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL|wxSL_MIN_MAX_LABELS );
	bSizer24->Add( m_slider_gray, 1, wxALL, 5 );

	m_textCtrl_gray = new wxTextCtrl( sbSizer8->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	m_textCtrl_gray->SetMaxSize( wxSize( 50,-1 ) );

	bSizer24->Add( m_textCtrl_gray, 0, wxALL, 5 );


	sbSizer8->Add( bSizer24, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer242;
	bSizer242 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText_lightness = new wxStaticText( sbSizer8->GetStaticBox(), wxID_ANY, _("Lightness Range:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_lightness->Wrap( -1 );
	bSizer242->Add( m_staticText_lightness, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_slider_lightness = new wxSlider( sbSizer8->GetStaticBox(), wxID_ANY, 165, 0, 255, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL|wxSL_MIN_MAX_LABELS );
	bSizer242->Add( m_slider_lightness, 1, wxALL, 5 );

	m_textCtrl_lightness = new wxTextCtrl( sbSizer8->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	m_textCtrl_lightness->SetMaxSize( wxSize( 50,-1 ) );

	bSizer242->Add( m_textCtrl_lightness, 0, wxALL, 5 );


	sbSizer8->Add( bSizer242, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer28;
	bSizer28 = new wxBoxSizer( wxHORIZONTAL );


	bSizer28->Add( 0, 0, 1, wxEXPAND, 5 );

	m_radioBtn_dl = new wxRadioButton( sbSizer8->GetStaticBox(), wxID_ANY, _("Greater = Darker, Less = Lighter"), wxDefaultPosition, wxDefaultSize, 0 );
	m_radioBtn_dl->SetValue( true );
	bSizer28->Add( m_radioBtn_dl, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_radioBtn_ld = new wxRadioButton( sbSizer8->GetStaticBox(), wxID_ANY, _("Greater = Lighter, Less = Darker"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer28->Add( m_radioBtn_ld, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer28->Add( 0, 0, 1, wxEXPAND, 5 );


	sbSizer8->Add( bSizer28, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer241;
	bSizer241 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText181 = new wxStaticText( sbSizer8->GetStaticBox(), wxID_ANY, _("ChangeLightness:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText181->Wrap( -1 );
	bSizer241->Add( m_staticText181, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_slider_change = new wxSlider( sbSizer8->GetStaticBox(), wxID_ANY, 20, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL|wxSL_MIN_MAX_LABELS );
	bSizer241->Add( m_slider_change, 1, wxALL, 5 );

	m_textCtrl_change = new wxTextCtrl( sbSizer8->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	m_textCtrl_change->SetMaxSize( wxSize( 50,-1 ) );

	bSizer241->Add( m_textCtrl_change, 0, wxALL, 5 );


	sbSizer8->Add( bSizer241, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer2911;
	bSizer2911 = new wxBoxSizer( wxHORIZONTAL );


	bSizer2911->Add( 0, 0, 1, wxEXPAND, 5 );

	m_button_ld_def = new wxButton( sbSizer8->GetStaticBox(), wxID_ANY, _("Restore default values"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2911->Add( m_button_ld_def, 0, wxALL, 5 );


	sbSizer8->Add( bSizer2911, 1, wxEXPAND, 5 );


	bSizer5->Add( sbSizer8, 0, wxEXPAND, 5 );


	this->SetSizer( bSizer5 );
	this->Layout();
	bSizer5->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	m_slider_background_r->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( Frame_Main::EventScrollBackgroundR ), NULL, this );
	m_slider_background_r->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( Frame_Main::EventScrollBackgroundR ), NULL, this );
	m_slider_background_r->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( Frame_Main::EventScrollBackgroundR ), NULL, this );
	m_slider_background_r->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( Frame_Main::EventScrollBackgroundR ), NULL, this );
	m_slider_background_r->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( Frame_Main::EventScrollBackgroundR ), NULL, this );
	m_slider_background_r->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( Frame_Main::EventScrollBackgroundR ), NULL, this );
	m_slider_background_r->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( Frame_Main::EventScrollBackgroundR ), NULL, this );
	m_slider_background_r->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( Frame_Main::EventScrollBackgroundR ), NULL, this );
	m_slider_background_r->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Frame_Main::EventScrollBackgroundR ), NULL, this );
	m_textCtrl_background_r->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Frame_Main::EventKillFocusBackgroundR ), NULL, this );
	m_textCtrl_background_r->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Frame_Main::EventTextEnterBackgroundR ), NULL, this );
	m_slider_background_g->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( Frame_Main::EventScrollBackgroundG ), NULL, this );
	m_slider_background_g->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( Frame_Main::EventScrollBackgroundG ), NULL, this );
	m_slider_background_g->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( Frame_Main::EventScrollBackgroundG ), NULL, this );
	m_slider_background_g->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( Frame_Main::EventScrollBackgroundG ), NULL, this );
	m_slider_background_g->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( Frame_Main::EventScrollBackgroundG ), NULL, this );
	m_slider_background_g->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( Frame_Main::EventScrollBackgroundG ), NULL, this );
	m_slider_background_g->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( Frame_Main::EventScrollBackgroundG ), NULL, this );
	m_slider_background_g->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( Frame_Main::EventScrollBackgroundG ), NULL, this );
	m_slider_background_g->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Frame_Main::EventScrollBackgroundG ), NULL, this );
	m_textCtrl_background_g->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Frame_Main::EventKillFocusBackgroundG ), NULL, this );
	m_textCtrl_background_g->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Frame_Main::EventTextEnterBackgroundG ), NULL, this );
	m_slider_background_b->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( Frame_Main::EventScrollBackgroundB ), NULL, this );
	m_slider_background_b->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( Frame_Main::EventScrollBackgroundB ), NULL, this );
	m_slider_background_b->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( Frame_Main::EventScrollBackgroundB ), NULL, this );
	m_slider_background_b->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( Frame_Main::EventScrollBackgroundB ), NULL, this );
	m_slider_background_b->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( Frame_Main::EventScrollBackgroundB ), NULL, this );
	m_slider_background_b->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( Frame_Main::EventScrollBackgroundB ), NULL, this );
	m_slider_background_b->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( Frame_Main::EventScrollBackgroundB ), NULL, this );
	m_slider_background_b->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( Frame_Main::EventScrollBackgroundB ), NULL, this );
	m_slider_background_b->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Frame_Main::EventScrollBackgroundB ), NULL, this );
	m_textCtrl_background_b->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Frame_Main::EventKillFocusBackgroundB ), NULL, this );
	m_textCtrl_background_b->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Frame_Main::EventTextEnterBackgroundB ), NULL, this );
	m_button_background_def->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Frame_Main::EventButtonClickBackgroundDef ), NULL, this );
	m_slider_foreground_r->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( Frame_Main::EventScrollForegroundR ), NULL, this );
	m_slider_foreground_r->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( Frame_Main::EventScrollForegroundR ), NULL, this );
	m_slider_foreground_r->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( Frame_Main::EventScrollForegroundR ), NULL, this );
	m_slider_foreground_r->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( Frame_Main::EventScrollForegroundR ), NULL, this );
	m_slider_foreground_r->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( Frame_Main::EventScrollForegroundR ), NULL, this );
	m_slider_foreground_r->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( Frame_Main::EventScrollForegroundR ), NULL, this );
	m_slider_foreground_r->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( Frame_Main::EventScrollForegroundR ), NULL, this );
	m_slider_foreground_r->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( Frame_Main::EventScrollForegroundR ), NULL, this );
	m_slider_foreground_r->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Frame_Main::EventScrollForegroundR ), NULL, this );
	m_textCtrl_foreground_r->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Frame_Main::EventKillFocusForegroundR ), NULL, this );
	m_textCtrl_foreground_r->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Frame_Main::EventTextEnterForegroundR ), NULL, this );
	m_slider_foreground_g->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( Frame_Main::EventScrollForegroundG ), NULL, this );
	m_slider_foreground_g->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( Frame_Main::EventScrollForegroundG ), NULL, this );
	m_slider_foreground_g->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( Frame_Main::EventScrollForegroundG ), NULL, this );
	m_slider_foreground_g->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( Frame_Main::EventScrollForegroundG ), NULL, this );
	m_slider_foreground_g->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( Frame_Main::EventScrollForegroundG ), NULL, this );
	m_slider_foreground_g->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( Frame_Main::EventScrollForegroundG ), NULL, this );
	m_slider_foreground_g->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( Frame_Main::EventScrollForegroundG ), NULL, this );
	m_slider_foreground_g->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( Frame_Main::EventScrollForegroundG ), NULL, this );
	m_slider_foreground_g->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Frame_Main::EventScrollForegroundG ), NULL, this );
	m_textCtrl_foreground_g->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Frame_Main::EventKillFocusForegroundG ), NULL, this );
	m_textCtrl_foreground_g->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Frame_Main::EventTextEnterForegroundG ), NULL, this );
	m_slider_foreground_b->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( Frame_Main::EventScrollForegroundB ), NULL, this );
	m_slider_foreground_b->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( Frame_Main::EventScrollForegroundB ), NULL, this );
	m_slider_foreground_b->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( Frame_Main::EventScrollForegroundB ), NULL, this );
	m_slider_foreground_b->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( Frame_Main::EventScrollForegroundB ), NULL, this );
	m_slider_foreground_b->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( Frame_Main::EventScrollForegroundB ), NULL, this );
	m_slider_foreground_b->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( Frame_Main::EventScrollForegroundB ), NULL, this );
	m_slider_foreground_b->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( Frame_Main::EventScrollForegroundB ), NULL, this );
	m_slider_foreground_b->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( Frame_Main::EventScrollForegroundB ), NULL, this );
	m_slider_foreground_b->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Frame_Main::EventScrollForegroundB ), NULL, this );
	m_textCtrl_foreground_b->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Frame_Main::EventKillFocusForegroundB ), NULL, this );
	m_textCtrl_foreground_b->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Frame_Main::EventTextEnterForegroundB ), NULL, this );
	m_button_foreground_def->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Frame_Main::EventButtonClickForegroundDef ), NULL, this );
	m_choice_mode->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Frame_Main::EventChoiceMode ), NULL, this );
	m_slider_gray->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( Frame_Main::EventScrollGray ), NULL, this );
	m_slider_gray->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( Frame_Main::EventScrollGray ), NULL, this );
	m_slider_gray->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( Frame_Main::EventScrollGray ), NULL, this );
	m_slider_gray->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( Frame_Main::EventScrollGray ), NULL, this );
	m_slider_gray->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( Frame_Main::EventScrollGray ), NULL, this );
	m_slider_gray->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( Frame_Main::EventScrollGray ), NULL, this );
	m_slider_gray->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( Frame_Main::EventScrollGray ), NULL, this );
	m_slider_gray->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( Frame_Main::EventScrollGray ), NULL, this );
	m_slider_gray->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Frame_Main::EventScrollGray ), NULL, this );
	m_textCtrl_gray->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Frame_Main::EventKillFocusGray ), NULL, this );
	m_textCtrl_gray->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Frame_Main::EventTextEnterGray ), NULL, this );
	m_slider_lightness->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( Frame_Main::EventScrollLightness ), NULL, this );
	m_slider_lightness->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( Frame_Main::EventScrollLightness ), NULL, this );
	m_slider_lightness->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( Frame_Main::EventScrollLightness ), NULL, this );
	m_slider_lightness->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( Frame_Main::EventScrollLightness ), NULL, this );
	m_slider_lightness->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( Frame_Main::EventScrollLightness ), NULL, this );
	m_slider_lightness->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( Frame_Main::EventScrollLightness ), NULL, this );
	m_slider_lightness->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( Frame_Main::EventScrollLightness ), NULL, this );
	m_slider_lightness->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( Frame_Main::EventScrollLightness ), NULL, this );
	m_slider_lightness->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Frame_Main::EventScrollLightness ), NULL, this );
	m_textCtrl_lightness->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Frame_Main::EventKillFocusLightness ), NULL, this );
	m_textCtrl_lightness->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Frame_Main::EventTextEnterLightness ), NULL, this );
	m_radioBtn_dl->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( Frame_Main::EventRadioDL ), NULL, this );
	m_radioBtn_ld->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( Frame_Main::EventRadioLD ), NULL, this );
	m_slider_change->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( Frame_Main::EventScrollChange ), NULL, this );
	m_slider_change->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( Frame_Main::EventScrollChange ), NULL, this );
	m_slider_change->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( Frame_Main::EventScrollChange ), NULL, this );
	m_slider_change->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( Frame_Main::EventScrollChange ), NULL, this );
	m_slider_change->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( Frame_Main::EventScrollChange ), NULL, this );
	m_slider_change->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( Frame_Main::EventScrollChange ), NULL, this );
	m_slider_change->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( Frame_Main::EventScrollChange ), NULL, this );
	m_slider_change->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( Frame_Main::EventScrollChange ), NULL, this );
	m_slider_change->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( Frame_Main::EventScrollChange ), NULL, this );
	m_textCtrl_change->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( Frame_Main::EventKillFocusChange ), NULL, this );
	m_textCtrl_change->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Frame_Main::EventTextEnterChange ), NULL, this );
	m_button_ld_def->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Frame_Main::EventButtonClickLdDef ), NULL, this );
}

Frame_Main::~Frame_Main()
{
}
