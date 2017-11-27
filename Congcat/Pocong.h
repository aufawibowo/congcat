#pragma once
#include <wx\dcclient.h>
class Pocong
{
private:
	int x;
	int y;
	int width;
	int height;
	int xDirection = 1;
	int yDirection = 1;
public:
	Pocong();
	Pocong(int x, int y, int width, int height);
	void Draw(wxPaintDC &dc);
	void Move();
	void Move2();
};