#pragma once

#include <stdexcept>
#include <iomanip>
#include "Shape.h"

class Diamond : public Shape
{
private:
	Point center_;
	double d1_;  // vertical diagonal
	double d2_;  // horizontal diagonal
public:

	Diamond(const Point& center, double vertical, double horizontal) : center_(center), d1_(vertical), d2_(horizontal) {};
	Diamond(const Diamond& obj) : center_(obj.center_), d1_(obj.d1_), d2_(obj.d2_) {};
	virtual Diamond& move(const Point& pos) override;
	virtual Diamond& scale(double k) override;
	virtual Diamond* clone() const;

	virtual const char* getName() const;
	virtual double  getArea() const override;
	virtual FrameRectangle getFrameRectangle() const override;
	friend std::ostream& operator<< (std::ostream& stream, const Diamond& obj);
};

