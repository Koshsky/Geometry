#include "Diamond.h"


double Diamond::getArea() const
{
	return d1_ * d2_ / 2;
}

FrameRectangle Diamond::getFrameRectangle() const
{
	return FrameRectangle(d2_, d1_, center_);
}

Diamond&  Diamond::move(const Point& pos)
{
	center_.x_ = pos.x_;
	center_.y_ = pos.y_;
	return *this;
}

Diamond& Diamond::scale(double k)
{
	if (k <= 0)
		throw std::invalid_argument(INVALID_SCALE_ERROR);
	d1_ *= k;
	d2_ *= k;
	return *this;
}

Diamond* Diamond::clone() const
{
	return new Diamond(*this);
}

const char* Diamond::getName() const
{
	return "DIAMOND";
}

std::ostream& operator<< (std::ostream& stream, const Diamond& obj)
{
	FrameRectangle frame = obj.getFrameRectangle();
	return (stream << std::fixed << std::setprecision(1) << obj.getName() << ' ' << obj.getArea() << ' '  
		<< frame.getLowerLeft() << ' ' << frame.getUpperRight());
}
