#pragma once

#include <iostream>

class Point
{
public:
	double x_;
	double y_;
	Point() : x_(0), y_(0) {};
	Point(double x, double y) : x_(x), y_(y) {};
	friend std::ostream& operator<< (std::ostream& stream, const Point& point)
	{
		return (stream << point.x_ << ' ' << point.y_);
	}
	Point& operator= (const Point& obj) 
	{
		x_ = obj.x_;
		y_ = obj.y_;
		return *this;
	}
	Point& moveAway(const Point& p, double k)  
		// increase the distance between points by k times in a straight line
	{
		x_ = p.x_ + (x_ - p.x_) * k;
		y_ = p.y_ + (y_ - p.y_) * k;
		return *this;
	}
};

