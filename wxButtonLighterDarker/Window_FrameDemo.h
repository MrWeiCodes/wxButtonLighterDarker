#pragma once
#include "WxUIBase.h"

class Window_FrameDemo :public Frame_Main
{
protected:
	wxColour m_background_rgb; //cache for background color
	wxColour m_foreground_rgb; //cache for foreground color
	BYTE m_gray_range; //Gray threshold. When this threshold is exceeded, the button's hot state is made lighter or darker based on the m_is_lighter variable.
	BYTE m_lightness_range; //Brightness threshold. When this threshold is exceeded, the hot state of the button will become brighter or darker based on the m_is_lighter variable.
	BYTE m_change_val; //When the button enters the hot state, apply the intensity value for lighter or darker.
	bool m_is_lighter; //When the value is true, if the background color is greater than m_gray_range, then the button will be lightened when entering the hot state; otherwise, it will be darkened.
	int m_select_mode; //0 for gray mode, 1 for lightness mode
public:
	Window_FrameDemo(wxWindow* parent = NULL);
	virtual ~Window_FrameDemo() {};

protected:
	//Scroll Event
	virtual void EventScrollBackgroundR(wxScrollEvent& event);
	virtual void EventScrollBackgroundG(wxScrollEvent& event);
	virtual void EventScrollBackgroundB(wxScrollEvent& event);
	virtual void EventScrollForegroundR(wxScrollEvent& event);
	virtual void EventScrollForegroundG(wxScrollEvent& event);
	virtual void EventScrollForegroundB(wxScrollEvent& event);
	virtual void EventScrollGray(wxScrollEvent& event);
	virtual void EventScrollLightness(wxScrollEvent& event);
	virtual void EventScrollChange(wxScrollEvent& event);
	//Edit Box Val Change Event
	virtual void EventTextEnterBackgroundR(wxCommandEvent& event);
	virtual void EventKillFocusBackgroundR(wxFocusEvent& event);
	virtual void EventTextEnterBackgroundG(wxCommandEvent& event);
	virtual void EventKillFocusBackgroundG(wxFocusEvent& event);
	virtual void EventTextEnterBackgroundB(wxCommandEvent& event);
	virtual void EventKillFocusBackgroundB(wxFocusEvent& event);
	virtual void EventTextEnterForegroundR(wxCommandEvent& event);
	virtual void EventKillFocusForegroundR(wxFocusEvent& event);
	virtual void EventTextEnterForegroundG(wxCommandEvent& event);
	virtual void EventKillFocusForegroundG(wxFocusEvent& event);
	virtual void EventTextEnterForegroundB(wxCommandEvent& event);
	virtual void EventKillFocusForegroundB(wxFocusEvent& event);
	virtual void EventTextEnterGray(wxCommandEvent& event);
	virtual void EventKillFocusGray(wxFocusEvent& event);
	virtual void EventTextEnterLightness(wxCommandEvent& event);
	virtual void EventKillFocusLightness(wxFocusEvent& event);
	virtual void EventTextEnterChange(wxCommandEvent& event);
	virtual void EventKillFocusChange(wxFocusEvent& event);
	//Choice Event
	virtual void EventChoiceMode(wxCommandEvent& event);
	//Radio Button Event
	virtual void EventRadioLD(wxCommandEvent& event);
	virtual void EventRadioDL(wxCommandEvent& event);
	//Default Button Click Event
	virtual void EventButtonClickBackgroundDef(wxCommandEvent& event);
	virtual void EventButtonClickForegroundDef(wxCommandEvent& event);
	virtual void EventButtonClickLdDef(wxCommandEvent& event);

	void ChangeMode();
	void UpdateButtonUI();
};

