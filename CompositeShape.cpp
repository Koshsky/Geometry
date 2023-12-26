#include "CompositeShape.h"

CompositeShape::CompositeShape(size_t maxCount) 
{
	maxCount_ = maxCount;
	numShapes_ = 0;
	shapes_ = new Shape*[maxCount];
}

FrameRectangle CompositeShape::getFrameRectangle() const
{
	double minX = std::numeric_limits<double>::max(),
		minY = std::numeric_limits<double>::max(),
		maxX = std::numeric_limits<double>::min(),
		maxY = std::numeric_limits<double>::min();
	for (size_t i = 0; i != numShapes_; i++)
	{
		FrameRectangle frame = shapes_[i]->getFrameRectangle();
		minX = std::min(minX, frame.getLowerLeft().x_);
		minY = std::min(minY, frame.getLowerLeft().y_);
		maxX = std::max(maxX, frame.getUpperRight().x_);
		maxY = std::max(maxY, frame.getUpperRight().y_);
	}
	return FrameRectangle(
		maxX - minX,
		maxY - minY,
		Point((maxX + minX) / 2, (minY + maxY) / 2)
	);
}

CompositeShape& CompositeShape::move(const Point& pos)
{
	Point center = getCenter();
	double dx = pos.x_ - center.x_;
	double dy = pos.y_ - center.y_;
	Point oldShpCenter, newShpCenter;
	for (size_t i = 0; i != numShapes_; i++)
	{
		oldShpCenter = shapes_[i]->getFrameRectangle().pos_;
		newShpCenter = Point(oldShpCenter.x_ + dx, oldShpCenter.y_ + dy);
		shapes_[i]->move(newShpCenter);
	}
	return *this;
}

CompositeShape& CompositeShape::scale(double k)
{
	Point center = getCenter();
	Point oldCenter;
	for (size_t i = 0; i != numShapes_; i++)
	{
		oldCenter = shapes_[i]->getFrameRectangle().pos_;
		shapes_[i]->move(center);
		shapes_[i]->scale(k);
		shapes_[i]->move(oldCenter.moveAway(center, k));
	}
	return *this;
}

CompositeShape& CompositeShape::append(Shape& obj)
{
	if (numShapes_ >= maxCount_)
		throw std::out_of_range(APPEND_ERROR);

	shapes_[numShapes_++] = &obj;
	return *this;
}
	
void CompositeShape::operator+= (Shape& obj)
{
	append(obj);
}