#include "stdafx.h"
#include "wxTestButton.h"

#include <wx/msw/uxtheme.h>
#include <wx/msw/dc.h>


// wxWidgets version £º3.3.3 master [ddd2b3f]
// Copy from wx file [wxWidgets\include\wx\msw\anybutton.cpp] and modified for our test button class

wxTestButton::wxTestButton()
{
	m_hasBgCol = m_currentBackgroundColour.IsOk();
}

wxTestButton::wxTestButton(wxWindow* parent, wxWindowID id, const wxString& label, const wxPoint& pos, const wxSize& size, long style, const wxValidator& validator, const wxString& name)
	:wxButton(parent, id, label, pos, size, style, validator, name)
{
	
}

// return the button state using both the ODS_XXX flags specified in state
// parameter and the current button state
wxAnyButton::State GetButtonState(wxAnyButton* btn, UINT state)
{
    if (state & ODS_DISABLED)
        return wxAnyButton::State_Disabled;

    // We need to check for the pressed state of the button itself before the
    // other checks because even if it is selected or current, it it still
    // pressed first and foremost.
    const wxAnyButton::State btnState = btn->GetNormalState();

    if (btnState == wxAnyButton::State_Pressed || state & ODS_SELECTED)
        return wxAnyButton::State_Pressed;

    if (btn->HasCapture() || btn->IsMouseInWindow())
        return wxAnyButton::State_Current;

    if (state & ODS_FOCUS)
        return wxAnyButton::State_Focused;

    return btnState;
}

// This is a hack used by the owner-drawn wxButton implementation to ensure
// that the brush used for erasing its background is correctly aligned with the
// control.
extern wxWindowMSW* wxWindowBeingErased;
// somehow the margin is one pixel greater than the value returned by
// GetThemeMargins() call
const int XP_BUTTON_EXTRA_MARGIN = 1;
// the gap between button edge and the interior area used by Windows for the
// standard buttons
const int OD_BUTTON_MARGIN = 4;

void DrawXPBackground(wxTestButton* button, HDC hdc, RECT& rectBtn, UINT state)
{
    wxUxThemeHandle theme(button, L"BUTTON");

    // this array is indexed by wxAnyButton::State values and so must be kept in
    // sync with it
    static const int uxStates[] =
    {
        PBS_NORMAL, PBS_HOT, PBS_PRESSED, PBS_DISABLED, PBS_DEFAULTED
    };

    int iState = uxStates[GetButtonState(button, state)];

    // draw parent background if needed
    if (::IsThemeBackgroundPartiallyTransparent
    (
        theme,
        BP_PUSHBUTTON,
        iState
    ))
    {
        // Set this button as the one whose background is being erased: this
        // allows our WM_ERASEBKGND handler used by DrawThemeParentBackground()
        // to correctly align the background brush with this window instead of
        // the parent window to which WM_ERASEBKGND is sent. Notice that this
        // doesn't work with custom user-defined EVT_ERASE_BACKGROUND handlers
        // as they won't be aligned but unfortunately all the attempts to fix
        // it by shifting DC origin before calling DrawThemeParentBackground()
        // failed to work so we at least do this, even though this is far from
        // being the perfect solution.
        wxWindowBeingErased = button;

        ::DrawThemeParentBackground(GetHwndOf(button), hdc, &rectBtn);

        wxWindowBeingErased = nullptr;
    }

    // draw background
    theme.DrawBackground(hdc, rectBtn, BP_PUSHBUTTON, iState);

    // calculate content area margins, using the defaults in case we fail to
    // retrieve the current theme margins
    MARGINS margins = { 3, 3, 3, 3 };
    ::GetThemeMargins(theme, hdc, BP_PUSHBUTTON, iState,
        TMT_CONTENTMARGINS, &rectBtn, &margins);
    ::InflateRect(&rectBtn, -margins.cxLeftWidth, -margins.cyTopHeight);


    if (button->UseBgCol() && iState != PBS_HOT)
    {
        COLORREF colBg = wxColourToRGB(button->GetBackgroundColour());
        AutoHBRUSH hbrushBackground(colBg);

        FillRect(hdc, &rectBtn, hbrushBackground);
    }
    if (button->UseCurrentBgCol() && iState == PBS_HOT)
    {
        COLORREF colCurrentBg = wxColourToRGB(button->GetCurrentBackgroundColour());
        AutoHBRUSH hbrushBackground(colCurrentBg);

        FillRect(hdc, &rectBtn, hbrushBackground);
    }

    ::InflateRect(&rectBtn, -XP_BUTTON_EXTRA_MARGIN, -XP_BUTTON_EXTRA_MARGIN);
}

void DrawRect(HDC hdc, const RECT& r, COLORREF color)
{
    wxDrawHVLine(hdc, r.left, r.top, r.right, r.top, color, 1);
    wxDrawHVLine(hdc, r.right, r.top, r.right, r.bottom, color, 1);
    wxDrawHVLine(hdc, r.right, r.bottom, r.left, r.bottom, color, 1);
    wxDrawHVLine(hdc, r.left, r.bottom, r.left, r.top, color, 1);
}

/*
   The button frame looks like this normally:

   WWWWWWWWWWWWWWWWWWB
   WHHHHHHHHHHHHHHHHGB  W = white       (HILIGHT)
   WH               GB  H = light grey  (LIGHT)
   WH               GB  G = dark grey   (SHADOW)
   WH               GB  B = black       (DKSHADOW)
   WH               GB
   WGGGGGGGGGGGGGGGGGB
   BBBBBBBBBBBBBBBBBBB

   When the button is selected, the button becomes like this (the total button
   size doesn't change):

   BBBBBBBBBBBBBBBBBBB
   BWWWWWWWWWWWWWWWWBB
   BWHHHHHHHHHHHHHHGBB
   BWH             GBB
   BWH             GBB
   BWGGGGGGGGGGGGGGGBB
   BBBBBBBBBBBBBBBBBBB
   BBBBBBBBBBBBBBBBBBB

   When the button is pushed (while selected) it is like:

   BBBBBBBBBBBBBBBBBBB
   BGGGGGGGGGGGGGGGGGB
   BG               GB
   BG               GB
   BG               GB
   BG               GB
   BGGGGGGGGGGGGGGGGGB
   BBBBBBBBBBBBBBBBBBB
*/
void DrawButtonFrame(HDC hdc, RECT& rectBtn,
    bool selected, bool pushed)
{
    RECT r;
    ::CopyRect(&r, &rectBtn);

    COLORREF clrBlack = ::GetSysColor(COLOR_3DDKSHADOW),
        clrGrey = ::GetSysColor(COLOR_3DSHADOW),
        clrLightGr = ::GetSysColor(COLOR_3DLIGHT),
        clrWhite = ::GetSysColor(COLOR_3DHILIGHT);

    r.right--;
    r.bottom--;

    if (pushed)
    {
        DrawRect(hdc, r, clrBlack);

        ::InflateRect(&r, -1, -1);

        DrawRect(hdc, r, clrGrey);
    }
    else // !pushed
    {
        if (selected)
        {
            DrawRect(hdc, r, clrBlack);

            ::InflateRect(&r, -1, -1);
        }

        wxDrawHVLine(hdc, r.left, r.bottom, r.right, r.bottom, clrBlack, 1);
        wxDrawHVLine(hdc, r.right, r.bottom, r.right, r.top - 1, clrBlack, 1);

        wxDrawHVLine(hdc, r.left, r.bottom - 1, r.left, r.top, clrWhite, 1);
        wxDrawHVLine(hdc, r.left, r.top, r.right, r.top, clrWhite, 1);

        wxDrawHVLine(hdc, r.left + 1, r.bottom - 2, r.left + 1, r.top + 1, clrLightGr, 1);
        wxDrawHVLine(hdc, r.left + 1, r.top + 1, r.right - 1, r.top + 1, clrLightGr, 1);

        wxDrawHVLine(hdc, r.left + 1, r.bottom - 1, r.right - 1, r.bottom - 1, clrGrey, 1);
        wxDrawHVLine(hdc, r.right - 1, r.bottom - 1, r.right - 1, r.top, clrGrey, 1);
    }

    InflateRect(&rectBtn, -OD_BUTTON_MARGIN, -OD_BUTTON_MARGIN);
}

void DrawButtonText(HDC hdc,
    RECT* pRect,
    wxAnyButton* btn,
    int flags)
{
    const wxString text = btn->GetLabel();

    // To get a native look for owner-drawn button in disabled state (without
    // theming) we must use DrawState() to draw the text label.
    //
    // Notice that we use the enabled state at MSW, not wx, level because we
    // don't want to grey it out when it's disabled just because its parent is
    // disabled by MSW as it happens when showing a modal dialog, but we do
    // want to grey it out if either it or its parent are explicitly disabled
    // at wx level, see #18011.
    if (!wxUxThemeIsActive() && !::IsWindowEnabled(GetHwndOf(btn)))
    {
        // However using DrawState() has some drawbacks:
        // 1. It generally doesn't support alignment flags (except right
        //    alignment), so we need to align the text on our own.
        // 2. It doesn't support multliline texts and there is necessary to
        //    draw/align multiline text line by line.

        // Compute bounding rect for the whole text.
        RECT rc;
        ::SetRectEmpty(&rc);
        ::DrawText(hdc, text.t_str(), text.length(), &rc, DT_CALCRECT);

        const LONG h = rc.bottom - rc.top;

        // Based on wxButton flags determine bottom edge of the drawing rect
        // inside the entire button area.
        int y0;
        if (btn->HasFlag(wxBU_BOTTOM))
        {
            y0 = pRect->bottom - h;
        }
        else if (!btn->HasFlag(wxBU_TOP))
        {
            // DT_VCENTER
            y0 = pRect->top + (pRect->bottom - pRect->top) / 2 - h / 2;
        }
        else // DT_TOP is the default
        {
            y0 = pRect->top;
        }

        UINT dsFlags = DSS_DISABLED;
        if (flags & DT_HIDEPREFIX)
            dsFlags |= (DSS_HIDEPREFIX | DST_PREFIXTEXT);
        else
            dsFlags |= DST_TEXT;

        const wxArrayString lines = wxSplit(text, '\n', '\0');
        const int hLine = h / lines.size();
        for (size_t lineNum = 0; lineNum < lines.size(); lineNum++)
        {
            // Each line must be aligned in horizontal direction individually.
            ::SetRectEmpty(&rc);
            ::DrawText(hdc, lines[lineNum].t_str(), lines[lineNum].length(),
                &rc, DT_CALCRECT);
            const LONG w = rc.right - rc.left;

            // Based on wxButton flags set horizontal position of the rect
            // inside the entire button area. Text is always centered for
            // multiline label.
            if ((!btn->HasFlag(wxBU_LEFT) && !btn->HasFlag(wxBU_RIGHT)) ||
                lines.size() > 1)
            {
                // DT_CENTER
                rc.left = pRect->left + (pRect->right - pRect->left) / 2 - w / 2;
                rc.right = rc.left + w;
            }
            else if (btn->HasFlag(wxBU_RIGHT))
            {
                rc.right = pRect->right;
                rc.left = rc.right - w;
            }
            else // DT_LEFT is the default
            {
                rc.left = pRect->left;
                rc.right = rc.left + w;
            }

            ::OffsetRect(&rc, 0, y0 + lineNum * hLine);

            ::DrawState(hdc, nullptr, nullptr, wxMSW_CONV_LPARAM(lines[lineNum]),
                lines[lineNum].length(),
                rc.left, rc.top, rc.right, rc.bottom, dsFlags);
        }
    }
    else // Button is enabled or using themes.
    {
        if (text.find(wxT('\n')) != wxString::npos)
        {
            // draw multiline label

            // first we need to compute its bounding rect
            RECT rc;
            ::CopyRect(&rc, pRect);
            ::DrawText(hdc, text.t_str(), text.length(), &rc,
                flags | DT_CALCRECT);

            // now position this rect inside the entire button area: notice
            // that DrawText() doesn't respect alignment flags for multiline
            // text, which is why we have to do it on our own (but still use
            // the horizontal alignment flags for the individual lines to be
            // aligned correctly)
            const LONG w = rc.right - rc.left;
            const LONG h = rc.bottom - rc.top;

            if (btn->HasFlag(wxBU_RIGHT))
            {
                rc.left = pRect->right - w;

                flags |= DT_RIGHT;
            }
            else if (!btn->HasFlag(wxBU_LEFT))
            {
                rc.left = pRect->left + (pRect->right - pRect->left) / 2 - w / 2;

                flags |= DT_CENTER;
            }
            else // wxBU_LEFT
            {
                rc.left = pRect->left;
            }

            if (btn->HasFlag(wxBU_BOTTOM))
            {
                rc.top = pRect->bottom - h;
            }
            else if (!btn->HasFlag(wxBU_TOP))
            {
                rc.top = pRect->top + (pRect->bottom - pRect->top) / 2 - h / 2;
            }
            else // wxBU_TOP
            {
                rc.top = pRect->top;
            }

            rc.right = rc.left + w;
            rc.bottom = rc.top + h;

            ::DrawText(hdc, text.t_str(), text.length(), &rc, flags);
        }
        else // single line label
        {
            // translate wx button flags to alignment flags for DrawText()
            if (btn->HasFlag(wxBU_RIGHT))
            {
                flags |= DT_RIGHT;
            }
            else if (!btn->HasFlag(wxBU_LEFT))
            {
                flags |= DT_CENTER;
            }
            //else: DT_LEFT is the default anyhow (and its value is 0 too)

            if (btn->HasFlag(wxBU_BOTTOM))
            {
                flags |= DT_BOTTOM;
            }
            else if (!btn->HasFlag(wxBU_TOP))
            {
                flags |= DT_VCENTER;
            }
            //else: as above, DT_TOP is the default

            // notice that we must have DT_SINGLELINE for vertical alignment
            // flags to work
            ::DrawText(hdc, text.t_str(), text.length(), pRect,
                flags | DT_SINGLELINE);
        }
    }
}

// text background and foreground colours
class wxTextColoursChanger
{
public:
    wxTextColoursChanger(HDC hdc, const wxMSWDCImpl& dc)
        : m_hdc(hdc)
    {
        Change(dc.GetTextForeground(), dc.GetTextBackground());
    }

    wxTextColoursChanger(HDC hdc, const wxColour& colFg, const wxColour& colBg)
        : m_hdc(hdc)
    {
        Change(colFg, colBg);
    }

    wxTextColoursChanger(HDC hdc, COLORREF colFg, COLORREF colBg)
        : m_hdc(hdc)
    {
        Change(colFg, colBg);
    }

    ~wxTextColoursChanger()
    {
        if (m_oldColFg != CLR_INVALID)
            ::SetTextColor(m_hdc, m_oldColFg);
        if (m_oldColBg != CLR_INVALID)
            ::SetBkColor(m_hdc, m_oldColBg);
    }

protected:
    // this ctor doesn't change mode immediately, call Change() later to do it
    // only if needed
    wxTextColoursChanger(HDC hdc)
        : m_hdc(hdc)
    {
        m_oldColFg =
            m_oldColBg = CLR_INVALID;
    }

    void Change(const wxColour& colFg, const wxColour& colBg)
    {
        Change(colFg.IsOk() ? colFg.GetPixel() : CLR_INVALID,
            colBg.IsOk() ? colBg.GetPixel() : CLR_INVALID);
    }

    void Change(COLORREF colFg, COLORREF colBg)
    {
        if (colFg != CLR_INVALID)
        {
            m_oldColFg = ::SetTextColor(m_hdc, colFg);
            if (m_oldColFg == CLR_INVALID)
            {
                wxLogLastError(wxT("SetTextColor"));
            }
        }
        else
        {
            m_oldColFg = CLR_INVALID;
        }

        if (colBg != CLR_INVALID)
        {
            m_oldColBg = ::SetBkColor(m_hdc, colBg);
            if (m_oldColBg == CLR_INVALID)
            {
                wxLogLastError(wxT("SetBkColor"));
            }
        }
        else
        {
            m_oldColBg = CLR_INVALID;
        }
    }

private:
    const HDC m_hdc;
    COLORREF m_oldColFg,
        m_oldColBg;

    wxDECLARE_NO_COPY_CLASS(wxTextColoursChanger);
};
// background mode
class wxBkModeChanger
{
public:
    // set background mode to opaque if mode != wxBRUSHSTYLE_TRANSPARENT
    wxBkModeChanger(HDC hdc, int mode)
        : m_hdc(hdc)
    {
        Change(mode);
    }

    ~wxBkModeChanger()
    {
        if (m_oldMode)
            ::SetBkMode(m_hdc, m_oldMode);
    }

protected:
    // this ctor doesn't change mode immediately, call Change() later to do it
    // only if needed
    wxBkModeChanger(HDC hdc) : m_hdc(hdc) { m_oldMode = 0; }

    void Change(int mode)
    {
        m_oldMode = ::SetBkMode(m_hdc, mode == wxBRUSHSTYLE_TRANSPARENT
            ? TRANSPARENT
            : OPAQUE);
        if (!m_oldMode)
        {
            wxLogLastError(wxT("SetBkMode"));
        }
    }

private:
    const HDC m_hdc;
    int m_oldMode;

    wxDECLARE_NO_COPY_CLASS(wxBkModeChanger);
};


bool wxTestButton::MSWOnDraw(WXDRAWITEMSTRUCT* wxdis)
{
    LPDRAWITEMSTRUCT lpDIS = (LPDRAWITEMSTRUCT)wxdis;
    HDC hdc = lpDIS->hDC;
    // We expect here a DC with default settings (in GM_COMPATIBLE mode
    // with non-scaled coordinates system) but will check this because
    // our line drawing function wxDrawHVLine() works effectively only
    // on a non-transformed DC.
    //wxASSERT(IsNonTransformedDC(hdc));

    UINT state = lpDIS->itemState;
    switch (GetButtonState(this, state))
    {
    case State_Disabled:
        state |= ODS_DISABLED;
        break;
    case State_Pressed:
        state |= ODS_SELECTED;
        break;
    case State_Focused:
        state |= ODS_FOCUS;
        break;
    default:
        break;
    }

    bool pushed = MSWIsPushed();

    RECT rectBtn;
    CopyRect(&rectBtn, &lpDIS->rcItem);

    // draw the button background
    if (!HasFlag(wxBORDER_NONE))
    {
        if (wxUxThemeIsActive())
        {
            DrawXPBackground(this, hdc, rectBtn, state);
        }
        else
        {
            COLORREF colBg = wxColourToRGB(GetBackgroundColour());

            // first, draw the background
            AutoHBRUSH hbrushBackground(colBg);
            FillRect(hdc, &rectBtn, hbrushBackground);

            // draw the border for the current state
            bool selected = (state & ODS_SELECTED) != 0;
            if (!selected)
            {
                wxTopLevelWindow*
                    tlw = wxDynamicCast(wxGetTopLevelParent(this), wxTopLevelWindow);
                if (tlw)
                {
                    selected = tlw->GetDefaultItem() == this;
                }
            }

            DrawButtonFrame(hdc, rectBtn, selected, pushed);
        }

        // draw the focus rectangle if we need it
        if ((state & ODS_FOCUS) && !(state & ODS_NOFOCUSRECT))
        {
            DrawFocusRect(hdc, &rectBtn);

            if (!wxUxThemeIsActive() && pushed)
            {
                // the label is shifted by 1 pixel to create "pushed" effect
                OffsetRect(&rectBtn, 1, 1);
            }
        }
    }
    else
    {
        // clear the background (and erase any previous bitmap)
        COLORREF colBg = wxColourToRGB(GetBackgroundColour());
        AutoHBRUSH hbrushBackground(colBg);
        FillRect(hdc, &rectBtn, hbrushBackground);
    }

    // draw the image, if any
    //if (m_imageData)
    //{
    //    wxBitmap bmp = m_imageData->GetBitmap(GetButtonState(this, state));
    //    if (!bmp.IsOk())
    //        bmp = m_imageData->GetBitmap(State_Normal);

    //    const wxSize sizeBmp = bmp.GetSize();
    //    const wxSize margin = m_imageData->GetBitmapMargins();
    //    const wxSize sizeBmpWithMargins(sizeBmp + 2 * margin);
    //    wxRect rectButton(wxRectFromRECT(rectBtn));

    //    // for simplicity, we start with centred rectangle and then move it to
    //    // the appropriate edge
    //    wxRect rectBitmap = wxRect(sizeBmp).CentreIn(rectButton);

    //    // move bitmap only if we have a label, otherwise keep it centered
    //    if (ShowsLabel())
    //    {
    //        switch (m_imageData->GetBitmapPosition())
    //        {
    //        default:
    //            wxFAIL_MSG("invalid direction");
    //            wxFALLTHROUGH;

    //        case wxLEFT:
    //            rectBitmap.x = rectButton.x + margin.x;
    //            rectButton.x += sizeBmpWithMargins.x;
    //            rectButton.width -= sizeBmpWithMargins.x;
    //            break;

    //        case wxRIGHT:
    //            rectBitmap.x = rectButton.GetRight() - sizeBmp.x - margin.x;
    //            rectButton.width -= sizeBmpWithMargins.x;
    //            break;

    //        case wxTOP:
    //            rectBitmap.y = rectButton.y + margin.y;
    //            rectButton.y += sizeBmpWithMargins.y;
    //            rectButton.height -= sizeBmpWithMargins.y;
    //            break;

    //        case wxBOTTOM:
    //            rectBitmap.y = rectButton.GetBottom() - sizeBmp.y - margin.y;
    //            rectButton.height -= sizeBmpWithMargins.y;
    //            break;
    //        }
    //    }

    //    wxDCTemp dst((WXHDC)hdc);
    //    dst.DrawBitmap(bmp, rectBitmap.GetPosition(), true);

    //    wxCopyRectToRECT(rectButton, rectBtn);
    //}


    // finally draw the label
    if (ShowsLabel())
    {
        COLORREF colFg;
        if (state & ODS_DISABLED)
        {
            colFg = ::GetSysColor(COLOR_GRAYTEXT);
        }
        //else if (wxUxThemeIsActive() &&
        //    GetButtonState(this, state) == wxAnyButton::State_Current)
        //{
        //    // The button is highlighted, use the standard colour to ensure
        //    // that its text is readable.
        //    colFg = ::GetSysColor(COLOR_BTNTEXT);
        //}
        else
        {
            colFg = wxColourToRGB(GetForegroundColour());
        }

        wxTextColoursChanger changeFg(hdc, colFg, CLR_INVALID);
        wxBkModeChanger changeBkMode(hdc, wxBRUSHSTYLE_TRANSPARENT);

//#if wxUSE_MARKUP
//        if (m_markupText)
//        {
//            wxDCTemp dc((WXHDC)hdc);
//            dc.SetTextForeground(wxColour(colFg));
//            dc.SetFont(GetFont());
//
//            m_markupText->Render(dc, wxRectFromRECT(rectBtn),
//                state & ODS_NOACCEL
//                ? wxMarkupText::Render_Default
//                : wxMarkupText::Render_ShowAccels);
//        }
//        else // Plain text label
//#endif // wxUSE_MARKUP
        {
            // notice that DT_HIDEPREFIX doesn't work on old (pre-Windows 2000)
            // systems but by happy coincidence ODS_NOACCEL is not used under
            // them either so DT_HIDEPREFIX should never be used there
            DrawButtonText(hdc, &rectBtn, this,
                state & ODS_NOACCEL ? DT_HIDEPREFIX : 0);
        }
    }

    return true;
}

bool wxTestButton::SetCurrentBackgroundColour(const wxColour& colour)
{
	if (colour == m_currentBackgroundColour)
	{
        return false;
	}
    m_hasCurrentBgCol = colour.IsOk();
	m_currentBackgroundColour = colour;
    return true;
}

// Copy from wx file [wxWidgets\src\common\wincmn.cpp]
wxColour wxTestButton::GetCurrentBackgroundColour() const
{
    if (!m_currentBackgroundColour.IsOk())
    {
        wxASSERT_MSG(!m_hasCurrentBgCol, wxT("we have invalid explicit current bg colour?"));

        // get our default background colour
        wxColour colBg = GetDefaultAttributes().colBg;

        // we must return some valid colour to avoid redoing this every time
        // and also to avoid surprising the applications written for older
        // wxWidgets versions where GetBackgroundColour() always returned
        // something -- so give them something even if it doesn't make sense
        // for this window (e.g. it has a themed background)
        if (!colBg.IsOk())
            colBg = GetClassDefaultAttributes().colBg;

        return colBg;
    }
    else
        return m_currentBackgroundColour;
}
