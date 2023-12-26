#pragma once

#include "Point.h"

class FrameRectangle
{
public:
	double width_;
	double height_;
	Point pos_;

	FrameRectangle(double w, double h, const Point& c) : width_(w), height_(h), pos_(c) {};

	Point getLowerLeft()
	{
		double x = pos_.x_ - width_ / 2;
		double y = pos_.y_ - height_ / 2;
		return Point(x, y);
	}

	Point getUpperRight()
	{
		double x = pos_.x_ + width_ / 2;
		double y = pos_.y_ + height_ / 2;
		return Point(x, y);
	}

};

