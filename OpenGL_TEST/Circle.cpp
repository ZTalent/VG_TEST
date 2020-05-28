#include "Circle.h"
#include <iostream>
Circle::Circle(void)
{
	style_ = GL_TRIANGLE_FAN;
	cstyle = circle;
	count = 0;
	isLine = false;
	isCir = true;
}

Circle::Circle(const glm::fvec3 position, const glm::fvec3 color, const float r)
{
	center_position_ = position;
	circle_color_ = color;
	radius = r;
	style_ = GL_TRIANGLE_FAN;
	cstyle = circle;
	count = 0;
	center_positions_.push_back(position);
	ColorList.push_back(circle_color_);
	isLine = false;
	isCir = true;
}

Circle::~Circle(void)
{
}

void Circle::AddCenterPosition(glm::fvec3 position)
{
	center_position_ = position;
	center_positions_.push_back(center_position_);
	count++;
}

void Circle::AddCenterPosition(float x, float y, float z)
{
	center_position_ = glm::fvec3(x, y, z);
	center_positions_.push_back(center_position_);
	count++;
}

void Circle::SetCircleColor(glm::fvec3 color)
{
	circle_color_ = color;
	ColorList.push_back(circle_color_);
}

void Circle::SetCircleColor(float r, float g, float b)
{
	circle_color_ = glm::fvec3(r, g, b);
	ColorList.push_back(circle_color_);
}

void Circle::SetRadius(float r)
{
	radius = r;
	radius_.push_back(radius);
}

void Circle::SetWidth(float line_width)
{
	line_width_ = line_width;
	isSetW = true;
}

void Circle::SetStyle(CircleStyle style)
{
	switch (style)
	{
	case circle_polygon:
		style_ = GL_TRIANGLE_FAN;
		break;
	case circle_line:
		style_ = GL_LINE_LOOP;
		isLine = true;
		break;
	}
}

glm::fvec3 Circle::GetCenterPosition(int index)
{
	return center_positions_[index];
}

glm::fvec3 Circle::GetColor(int index)
{
	return ColorList[index];
}

GLenum Circle::GetStyle(void)
{
	return style_;
}

float Circle::GetRadius(int index)
{
	return radius_[index];
}

float Circle::GetWidth(void)
{
	return line_width_;
}

void Circle::end()
{
	for (int i = 0; i < accuracy; i++)
	{
		real_render_.push_back((float)i / accuracy);
	}
}
