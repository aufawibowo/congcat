#include "ImageWindow.h"
#include "Pocong.h"
#include <wx/stdpaths.h>
#include <wx/filename.h>
#define TIMER_ID 2000
BEGIN_EVENT_TABLE(ImageWindow, wxWindow)
EVT_PAINT(ImageWindow::OnPaint)
EVT_TIMER(TIMER_ID, ImageWindow::OnTimer)
END_EVENT_TABLE()


ImageWindow::ImageWindow(wxFrame *parent)
	: wxWindow(parent, wxID_ANY)
{
	this->SetBackgroundColour(wxColour(*wxWHITE));
	//load JPEGHandler untuk membaca file JPEG.
	wxImageHandler *jpegLoader = new wxJPEGHandler();
	wxImage::AddHandler(jpegLoader);
	//load image
	this->LoadPotatoBitmap();

	timer = new wxTimer(this, TIMER_ID);
	//memulai timer dengan interval 50ms.
	timer->Start(0.001);
	pocong = new Pocong(10, 10, 50, 50);

}
ImageWindow::~ImageWindow()
{
	delete potatoBitmap;
	timer->Stop();
	delete timer;
	delete pocong;
}
void ImageWindow::LoadPotatoBitmap()
{
	//jika menggunakan absolute path
	//sesuaikan path dimana lokasi file potato.jpg berada
	wxImage image(wxT("D:\\Materi Kuliah\\Semester 3\\PBO\\congcatt.jpeg"),	wxBITMAP_TYPE_JPEG);
	potatoBitmap = new wxBitmap(image);
}
void ImageWindow::OnPaint(wxPaintEvent &event)
{
	wxPaintDC pdc(this);
	if (potatoBitmap != nullptr)
	{
		pdc.DrawBitmap(*potatoBitmap, wxPoint(0,0), true);
	}


	
}

void ImageWindow::OnTimer(wxTimerEvent &event)
{
	static int counter = 0;
	wxMessageOutputDebug().Printf("wxTimer event %d.", counter++);
	if (pocong != nullptr)
	{
		pocong->Move(5, 2, GetClientSize().GetWidth(),
			GetClientSize().GetHeight());
		Refresh();
	}
}

void ImageWindow::Pencet(wxKeyEvent &event) {

	wxPaintDC pdc(this);
	if (event.GetKeyCode() == WXK_SPACE)
	{
		pocong->Draw(pdc);
	}
	event.Skip();
}