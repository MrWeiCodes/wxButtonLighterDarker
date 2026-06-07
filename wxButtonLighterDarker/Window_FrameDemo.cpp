#include "stdafx.h"
#include "Window_FrameDemo.h"

#undef max
#undef min

Window_FrameDemo::Window_FrameDemo(wxWindow* parent) :Frame_Main(parent)
{
	wxTextValidator valid_dig(wxFILTER_DIGITS);

	//Initialize the content of the edit box
	m_textCtrl_background_r->SetValidator(valid_dig);
	m_textCtrl_background_r->ChangeValue(wxString::FromCDouble(m_slider_background_r->GetValue()));
	m_textCtrl_background_g->SetValidator(valid_dig);
	m_textCtrl_background_g->ChangeValue(wxString::FromCDouble(m_slider_background_g->GetValue()));
	m_textCtrl_background_b->SetValidator(valid_dig);
	m_textCtrl_background_b->ChangeValue(wxString::FromCDouble(m_slider_background_b->GetValue()));

	m_textCtrl_foreground_r->SetValidator(valid_dig);
	m_textCtrl_foreground_r->ChangeValue(wxString::FromCDouble(m_slider_foreground_r->GetValue()));
	m_textCtrl_foreground_g->SetValidator(valid_dig);
	m_textCtrl_foreground_g->ChangeValue(wxString::FromCDouble(m_slider_foreground_g->GetValue()));
	m_textCtrl_foreground_b->SetValidator(valid_dig);
	m_textCtrl_foreground_b->ChangeValue(wxString::FromCDouble(m_slider_foreground_b->GetValue()));

	m_textCtrl_gray->SetValidator(valid_dig);
	m_textCtrl_gray->ChangeValue(wxString::FromCDouble(m_slider_gray->GetValue()));
	m_textCtrl_lightness->SetValidator(valid_dig);
	m_textCtrl_lightness->ChangeValue(wxString::FromCDouble(m_slider_lightness->GetValue()));
	m_textCtrl_change->SetValidator(valid_dig);
	m_textCtrl_change->ChangeValue(wxString::FromCDouble(m_slider_change->GetValue()));

	ChangeMode();
	UpdateButtonUI();
}

void Window_FrameDemo::EventScrollBackgroundR(wxScrollEvent& event)
{
	m_textCtrl_background_r->ChangeValue(wxString::FromCDouble(m_slider_background_r->GetValue()));
	UpdateButtonUI();
	event.Skip();
}

void Window_FrameDemo::EventScrollBackgroundG(wxScrollEvent& event)
{
	m_textCtrl_background_g->ChangeValue(wxString::FromCDouble(m_slider_background_g->GetValue()));
	UpdateButtonUI();
	event.Skip();
}

void Window_FrameDemo::EventScrollBackgroundB(wxScrollEvent& event)
{
	m_textCtrl_background_b->ChangeValue(wxString::FromCDouble(m_slider_background_b->GetValue()));
	UpdateButtonUI();
	event.Skip();
}

void Window_FrameDemo::EventScrollForegroundR(wxScrollEvent& event)
{
	m_textCtrl_foreground_r->ChangeValue(wxString::FromCDouble(m_slider_foreground_r->GetValue()));
	UpdateButtonUI();
	event.Skip();
}

void Window_FrameDemo::EventScrollForegroundG(wxScrollEvent& event)
{
	m_textCtrl_foreground_g->ChangeValue(wxString::FromCDouble(m_slider_foreground_g->GetValue()));
	UpdateButtonUI();
	event.Skip();
}

void Window_FrameDemo::EventScrollForegroundB(wxScrollEvent& event)
{
	m_textCtrl_foreground_b->ChangeValue(wxString::FromCDouble(m_slider_foreground_b->GetValue()));
	UpdateButtonUI();
	event.Skip();
}

void Window_FrameDemo::EventScrollGray(wxScrollEvent& event)
{
	m_textCtrl_gray->ChangeValue(wxString::FromCDouble(m_slider_gray->GetValue()));
	UpdateButtonUI();
	event.Skip();
}

void Window_FrameDemo::EventScrollLightness(wxScrollEvent& event)
{
	m_textCtrl_lightness->ChangeValue(wxString::FromCDouble(m_slider_lightness->GetValue()));
	UpdateButtonUI();
	event.Skip();
}

void Window_FrameDemo::EventScrollChange(wxScrollEvent& event)
{
	m_textCtrl_change->ChangeValue(wxString::FromCDouble(m_slider_change->GetValue()));
	UpdateButtonUI();
	event.Skip();
}

void Window_FrameDemo::EventTextEnterBackgroundR(wxCommandEvent& event)
{
	int val = wxAtoi(m_textCtrl_background_r->GetValue());
	if (val < 0) val = 0;
	if (val > 255) val = 255;
	m_slider_background_r->SetValue(val);
	UpdateButtonUI();
	event.Skip();
}

void Window_FrameDemo::EventKillFocusBackgroundR(wxFocusEvent& event)
{
	int val = wxAtoi(m_textCtrl_background_r->GetValue());
	if (val < 0) val = 0;
	if (val > 255) val = 255;
	m_slider_background_r->SetValue(val);
	UpdateButtonUI();
	event.Skip();
}

void Window_FrameDemo::EventTextEnterBackgroundG(wxCommandEvent& event)
{
	int val = wxAtoi(m_textCtrl_background_g->GetValue());
	if (val < 0) val = 0;
	if (val > 255) val = 255;
	m_slider_background_g->SetValue(val);
	UpdateButtonUI();
	event.Skip();
}

void Window_FrameDemo::EventKillFocusBackgroundG(wxFocusEvent& event)
{
	int val = wxAtoi(m_textCtrl_background_g->GetValue());
	if (val < 0) val = 0;
	if (val > 255) val = 255;
	m_slider_background_g->SetValue(val);
	UpdateButtonUI();
	event.Skip();
}

void Window_FrameDemo::EventTextEnterBackgroundB(wxCommandEvent& event)
{
	int val = wxAtoi(m_textCtrl_background_b->GetValue());
	if (val < 0) val = 0;
	if (val > 255) val = 255;
	m_slider_background_b->SetValue(val);
	UpdateButtonUI();
	event.Skip();
}

void Window_FrameDemo::EventKillFocusBackgroundB(wxFocusEvent& event)
{
	int val = wxAtoi(m_textCtrl_background_b->GetValue());
	if (val < 0) val = 0;
	if (val > 255) val = 255;
	m_slider_background_b->SetValue(val);
	UpdateButtonUI();
	event.Skip();
}

void Window_FrameDemo::EventTextEnterForegroundR(wxCommandEvent& event)
{
	int val = wxAtoi(m_textCtrl_foreground_r->GetValue());
	if (val < 0) val = 0;
	if (val > 255) val = 255;
	m_slider_foreground_r->SetValue(val);
	UpdateButtonUI();
	event.Skip();
}

void Window_FrameDemo::EventKillFocusForegroundR(wxFocusEvent& event)
{
	int val = wxAtoi(m_textCtrl_foreground_r->GetValue());
	if (val < 0) val = 0;
	if (val > 255) val = 255;
	m_slider_foreground_r->SetValue(val);
	UpdateButtonUI();
	event.Skip();
}

void Window_FrameDemo::EventTextEnterForegroundG(wxCommandEvent& event)
{
	int val = wxAtoi(m_textCtrl_foreground_g->GetValue());
	if (val < 0) val = 0;
	if (val > 255) val = 255;
	m_slider_foreground_g->SetValue(val);
	UpdateButtonUI();
	event.Skip();
}

void Window_FrameDemo::EventKillFocusForegroundG(wxFocusEvent& event)
{
	int val = wxAtoi(m_textCtrl_foreground_g->GetValue());
	if (val < 0) val = 0;
	if (val > 255) val = 255;
	m_slider_foreground_g->SetValue(val);
	UpdateButtonUI();
	event.Skip();
}

void Window_FrameDemo::EventTextEnterForegroundB(wxCommandEvent& event)
{
	int val = wxAtoi(m_textCtrl_foreground_b->GetValue());
	if (val < 0) val = 0;
	if (val > 255) val = 255;
	m_slider_foreground_b->SetValue(val);
	UpdateButtonUI();
	event.Skip();
}

void Window_FrameDemo::EventKillFocusForegroundB(wxFocusEvent& event)
{
	int val = wxAtoi(m_textCtrl_foreground_b->GetValue());
	if (val < 0) val = 0;
	if (val > 255) val = 255;
	m_slider_foreground_b->SetValue(val);
	UpdateButtonUI();
	event.Skip();
}

void Window_FrameDemo::EventTextEnterGray(wxCommandEvent& event)
{
	int val = wxAtoi(m_textCtrl_gray->GetValue());
	if (val < 0) val = 0;
	if (val > 255) val = 255;
	m_slider_gray->SetValue(val);
	UpdateButtonUI();
	event.Skip();
}

void Window_FrameDemo::EventKillFocusGray(wxFocusEvent& event)
{
	int val = wxAtoi(m_textCtrl_gray->GetValue());
	if (val < 0) val = 0;
	if (val > 255) val = 255;
	m_slider_gray->SetValue(val);
	UpdateButtonUI();
	event.Skip();
}

void Window_FrameDemo::EventTextEnterLightness(wxCommandEvent& event)
{
	int val = wxAtoi(m_textCtrl_lightness->GetValue());
	if (val < 0) val = 0;
	if (val > 255) val = 255;
	m_slider_lightness->SetValue(val);
	UpdateButtonUI();
	event.Skip();
}

void Window_FrameDemo::EventKillFocusLightness(wxFocusEvent& event)
{
	int val = wxAtoi(m_textCtrl_lightness->GetValue());
	if (val < 0) val = 0;
	if (val > 255) val = 255;
	m_slider_lightness->SetValue(val);
	UpdateButtonUI();
	event.Skip();
}

void Window_FrameDemo::EventTextEnterChange(wxCommandEvent& event)
{
	int val = wxAtoi(m_textCtrl_change->GetValue());
	if (val < 0) val = 0;
	if (val > 100) val = 100;
	m_slider_change->SetValue(val);
	UpdateButtonUI();
	event.Skip();
}

void Window_FrameDemo::EventKillFocusChange(wxFocusEvent& event)
{
	int val = wxAtoi(m_textCtrl_change->GetValue());
	if (val < 0) val = 0;
	if (val > 100) val = 100;
	m_slider_change->SetValue(val);
	UpdateButtonUI();
	event.Skip();
}

void Window_FrameDemo::EventChoiceMode(wxCommandEvent& event)
{
	ChangeMode();
	UpdateButtonUI();
	event.Skip();
}

void Window_FrameDemo::EventRadioLD(wxCommandEvent& event)
{
	UpdateButtonUI();
	event.Skip();
}

void Window_FrameDemo::EventRadioDL(wxCommandEvent& event)
{
	UpdateButtonUI();
	event.Skip();
}

void Window_FrameDemo::EventButtonClickBackgroundDef(wxCommandEvent& event)
{
	m_slider_background_r->SetValue(225);
	m_slider_background_g->SetValue(225);
	m_slider_background_b->SetValue(225);
	m_textCtrl_background_r->ChangeValue(wxString::FromCDouble(m_slider_background_r->GetValue()));
	m_textCtrl_background_g->ChangeValue(wxString::FromCDouble(m_slider_background_g->GetValue()));
	m_textCtrl_background_b->ChangeValue(wxString::FromCDouble(m_slider_background_b->GetValue()));
	UpdateButtonUI();
	event.Skip();
}

void Window_FrameDemo::EventButtonClickForegroundDef(wxCommandEvent& event)
{
	m_slider_foreground_r->SetValue(0);
	m_slider_foreground_g->SetValue(0);
	m_slider_foreground_b->SetValue(0);
	m_textCtrl_foreground_r->ChangeValue(wxString::FromCDouble(m_slider_foreground_r->GetValue()));
	m_textCtrl_foreground_g->ChangeValue(wxString::FromCDouble(m_slider_foreground_g->GetValue()));
	m_textCtrl_foreground_b->ChangeValue(wxString::FromCDouble(m_slider_foreground_b->GetValue()));
	UpdateButtonUI();
	event.Skip();
}

void Window_FrameDemo::EventButtonClickLdDef(wxCommandEvent& event)
{
	m_slider_gray->SetValue(128);
	m_slider_lightness->SetValue(165);
	m_slider_change->SetValue(20);
	m_textCtrl_gray->ChangeValue(wxString::FromCDouble(m_slider_gray->GetValue()));
	m_textCtrl_lightness->ChangeValue(wxString::FromCDouble(m_slider_lightness->GetValue()));
	m_textCtrl_change->ChangeValue(wxString::FromCDouble(m_slider_change->GetValue()));
	m_radioBtn_ld->SetValue(true);
	m_radioBtn_dl->SetValue(false);
	UpdateButtonUI();
	event.Skip();
}

float GetLightness(BYTE r, BYTE g, BYTE b)
{
	float max = std::max({ r,g,b });
	float min = std::min({ r,g,b });
	return (max + min) / 2.0f;
}

void Window_FrameDemo::ChangeMode()
{
	m_textCtrl_gray->Hide();
	m_slider_gray->Hide();
	m_staticText_gray->Hide();

	m_textCtrl_lightness->Hide();
	m_slider_lightness->Hide();
	m_staticText_lightness->Hide();

	m_select_mode = m_choice_mode->GetSelection();
	switch (m_select_mode)
	{
	case 0: //Gray Mode
		m_textCtrl_gray->Show();
		m_slider_gray->Show();
		m_staticText_gray->Show();
		break;
	case 1: //Lightness Mode
	default:
		m_textCtrl_lightness->Show();
		m_slider_lightness->Show();
		m_staticText_lightness->Show();
		break;
	}
	Fit();
}

#define RGB2GRAY(r,g,b) (((b)*117 + (g)*601 + (r)*306) >> 10)
void Window_FrameDemo::UpdateButtonUI()
{
	//Update cache to local variable
	m_background_rgb = wxColour(m_slider_background_r->GetValue(), m_slider_background_g->GetValue(), m_slider_background_b->GetValue());
	m_foreground_rgb = wxColour(m_slider_foreground_r->GetValue(), m_slider_foreground_g->GetValue(), m_slider_foreground_b->GetValue());

	m_gray_range = m_slider_gray->GetValue();
	m_lightness_range = m_slider_lightness->GetValue();
	m_change_val = m_slider_change->GetValue();
	m_is_lighter = m_radioBtn_ld->GetValue();

	//Set button color
	m_button_test->SetBackgroundColour(m_background_rgb);
	m_button_test->SetForegroundColour(m_foreground_rgb);

	//Determine whether the original background color is dark or light based on the grayscale value.
	//This [wxColour::MakeGrey] function has no return value, requiring the creation of a new variable, which is inconvenient to use. Switch to the macro RGB2GRAY for the same effect.
	//wxColour::MakeGrey(m_background_rgb.R, m_background_rgb.G, m_background_rgb.B);
	BYTE gray_val = RGB2GRAY(m_background_rgb.Red(), m_background_rgb.Green(), m_background_rgb.Blue());
	BYTE lightness_val = GetLightness(m_background_rgb.Red(), m_background_rgb.Green(), m_background_rgb.Blue());
	m_staticText_background_gray->SetLabel(wxString::FromCDouble(gray_val));
	m_staticText_background_lightness->SetLabel(wxString::FromCDouble(lightness_val, 1));

	bool is_lighter = false;
	switch (m_select_mode)
	{
	case 0: //0.gray mode
		is_lighter = (gray_val >= m_gray_range) ? m_is_lighter : !m_is_lighter;
		break;
	case 1: //1.lightness mode
	default:
		is_lighter = (lightness_val >= m_lightness_range) ? m_is_lighter : !m_is_lighter;
		break;
	}

	//construct the background color for the new hot state based on the button's background color
	wxColour hot_color = m_background_rgb;
	if (is_lighter)
	{
		//This function uses 100 as the base value; values below 100 darken, and values above 100 brighten.
		hot_color = hot_color.ChangeLightness(100 + m_change_val);
	}
	else
	{
		//This function uses 100 as the base value; values below 100 darken, and values above 100 brighten.
		hot_color = hot_color.ChangeLightness(100 - m_change_val);
	}
	m_button_test->SetCurrentBackgroundColour(hot_color);

}


