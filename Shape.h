#pragma once

#include "FrameRectangle.h"
#include "Point.h"

const char* const INVALID_SCALE_ERROR = "The scale coefficient cannot be less than or equal to zero";

class Shape {
public:
	virtual ~Shape() {};
	virtual double  getArea() const { return 0.0; }
	virtual FrameRectangle getFrameRectangle() const = 0;
	virtual Shape& move(const Point& pos) = 0;
	virtual Shape& scale(double k) = 0;
	virtual Shape* clone() const { return nullptr; }
	virtual const char* getName() const { return nullptr; }
};

