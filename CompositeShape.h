#pragma once

#include <stdexcept>
#include <limits>
#include "Shape.h"
#include "FrameRectangle.h"
#include "Point.h"

const char* const APPEND_ERROR = "The array is already full. No space for new element";

class CompositeShape : public Shape
{
private:
	size_t maxCount_;
	size_t numShapes_;
public:
	Shape** shapes_;
	CompositeShape(size_t maxCount);
	~CompositeShape() { delete[] shapes_; }
	virtual CompositeShape& move(const Point& pos) override;
	virtual CompositeShape& scale(double k) override;
	void operator+= (Shape& obj);
	CompositeShape& append(Shape& obj);
	virtual FrameRectangle getFrameRectangle() const override;
	Point getCenter() const { return getFrameRectangle().pos_; }
};

