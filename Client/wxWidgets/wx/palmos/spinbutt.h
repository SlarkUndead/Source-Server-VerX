/////////////////////////////////////////////////////////////////////////////
// Name:        wx/palmos/spinbutt.h
// Purpose:     wxSpinButton class
// Author:      William Osborne - minimal working wxPalmOS port
// Modified by:
// Created:     10/13/04
// RCS-ID:      $Id: spinbutt.h,v 1.3 2005/01/18 21:14:27 ABX Exp $
// Copyright:   (c) William Osborne
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#ifndef _WX_SPINBUTT_H_
#define _WX_SPINBUTT_H_

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
    #pragma interface "spinbutt.h"
#endif

#include "wx/control.h"
#include "wx/event.h"

class WXDLLEXPORT wxSpinButton : public wxSpinButtonBase
{
public:
    // construction
    wxSpinButton() { }

    wxSpinButton(wxWindow *parent,
                 wxWindowID id = wxID_ANY,
                 const wxPoint& pos = wxDefaultPosition,
                 const wxSize& size = wxDefaultSize,
                 long style = wxSP_VERTICAL | wxSP_ARROW_KEYS,
                 const wxString& name = wxSPIN_BUTTON_NAME)
    {
        Create(parent, id, pos, size, style, name);
    }

    virtual ~wxSpinButton();

    bool Create(wxWindow *parent,
                wxWindowID id = wxID_ANY,
                const wxPoint& pos = wxDefaultPosition,
                const wxSize& size = wxDefaultSize,
                long style = wxSP_VERTICAL | wxSP_ARROW_KEYS,
                const wxString& name = wxSPIN_BUTTON_NAME);


    // accessors
    virtual int GetValue() const;
    virtual void SetValue(int val);
    virtual void SetRange(int minVal, int maxVal);

    // a wxSpinButton can't do anything useful with focus, only wxSpinCtrl can
    virtual bool AcceptsFocus() const { return false; }

protected:
   virtual wxSize DoGetBestSize() const;

private:
    DECLARE_DYNAMIC_CLASS_NO_COPY(wxSpinButton)
};

#endif
    // _WX_SPINBUTT_H_
