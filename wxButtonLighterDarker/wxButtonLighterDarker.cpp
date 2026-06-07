// wxButtonLighterDarker.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "wxButtonLighterDarker.h"

#include "Window_FrameDemo.h"

class MyApp : public wxApp {
public:
	virtual bool OnInit() {
		Window_FrameDemo* frame = new Window_FrameDemo(NULL);
		frame->Show(true);
		return true;

	};
};


wxIMPLEMENT_APP(MyApp);