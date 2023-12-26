#pragma once

#include <stdexcept>
#include <iomanip>
#include "Shape.h"

const char* const INVALID_CORNERS_ERROR = "RECTANGLE. Write down the coordinates of your corners in pairs: bottom left and top right.";

class Rectangle : public Shape
{
private:
	Point ll_;  // lower left corner
	Point ur_;  // upper right corner
public:
	Rectangle(const Point& p1, const Point& p2);
	Rectangle(const Rectangle& obj) : ll_(obj.ll_), ur_(obj.ur_) {};

	virtual Rectangle& move(const Point& pos) override;
	virtual Rectangle& scale(double k) override;
	virtual Rectangle* clone() const override;
	friend std::ostream& operator<< (std::ostream& stream, const Rectangle& obj);

	Point getCenter() const;
	double getWidth() const;
	double getHeight() const;
	virtual double  getArea() const override;
	virtual FrameRectangle getFrameRectangle() const override;
	virtual const char* getName() const override;
};

