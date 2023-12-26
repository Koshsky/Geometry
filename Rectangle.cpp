#include "Rectangle.h"


Rectangle::Rectangle(const Point& p1, const Point& p2)
{
	if (p1.x_ >= p2.x_ || p1.y_ >= p2.y_)
		throw std::invalid_argument(INVALID_CORNERS_ERROR);
	ll_ = p1;
	ur_ = p2;
}

double  Rectangle::getArea() const
{
	return (ur_.x_ - ll_.x_) * (ur_.y_ - ll_.y_);
}

FrameRectangle  Rectangle::getFrameRectangle() const
{
	return FrameRectangle(
		getWidth(),
		getHeight(),
		getCenter()
	);
}

Rectangle& Rectangle::move(const Point& pos)
{
	Point center = getCenter();
	double dx = pos.x_ - center.x_;
	double dy = pos.y_ - center.y_;
	ll_.x_ += dx;
	ur_.x_ += dx;
	ll_.y_ += dy;
	ur_.y_ += dy;
	return *this;
}

Rectangle& Rectangle::scale(double k)
{
	if (k <= 0)
		throw std::invalid_argument(INVALID_SCALE_ERROR);
	Point center = getCenter();
	ll_.moveAway(center, k);
	ur_.moveAway(center, k);
	return *this;
}

Rectangle*  Rectangle::clone() const
{
	return new Rectangle(*this);
}

const char*  Rectangle::getName() const
{
	return "RECTANGLE";
}

Point Rectangle::getCenter() const
{
	return Point((ur_.x_ + ll_.x_) / 2, (ur_.y_ + ll_.y_) / 2);
}

double Rectangle::getWidth() const
{
	return ur_.x_ - ll_.x_;
}

double Rectangle::getHeight() const
{
	return ur_.y_ - ll_.y_;
}

std::ostream& operator<< (std::ostream& stream, const Rectangle& obj)
{
	return (stream << std::fixed << std::setprecision(1) << obj.getName() << ' ' << obj.getArea() << ' ' 
		<< obj.ll_ << ' ' << obj.ur_);
}
