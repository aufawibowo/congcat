#pragma once
#include "wx\wx.h"
#include <wx/dcbuffer.h>

class Pocong;
class ImageWindow : public wxWindow
{
public:
	ImageWindow(wxFrame *parent);
	~ImageWindow();
	void OnPaint(wxPaintEvent &event);
	void OnTimer(wxTimerEvent &event);
	void Pencet(wxKeyEvent &event);
	void Pencet2(wxKeyEvent &event);
	void OnEraseBackground(wxEraseEvent &event);
private:
	wxBitmap *potatoBitmap = nullptr;
	wxTimer *timer;
	Pocong *pocong;
	DECLARE_EVENT_TABLE()
	void LoadPotatoBitmap();
};