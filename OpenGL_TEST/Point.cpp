#include "Point.h"

Point::Point(void)
{
	cstyle = point;
	style_ = GL_POINTS;
	isCir = false;
	count = 1;
	point_size_ = 1;
}

Point::~Point()
{
	real_render_.clear();
	ColorList.clear();
}

void Point::AddPoint(const glm::fvec3& position)
{
	point_list_.push_back(position);
}

void Point::AddPoint(const float x, const float y, const float z)
{
	point_list_.push_back(glm::fvec3(x, y, z));
}

void Point::end()
{
	Shape::vector2float(point_list_, ColorList, real_render_);
}

void Point::SetSize(int point_size)
{
	point_size_ = point_size;
	isSetS = true;
}

void Point::SetColor(const glm::fvec3& color)
{
	ColorList.push_back(color);
}

void Point::SetColor(const float r, const float g, const float b)
{
	ColorList.push_back(glm::fvec3(r, g, b));
}

glm::fvec3 Point::GetColor(void)
{
	return point_color_;
}

float Point::GetSize(void)
{
	return point_size_;
}

GLenum Point::GetStyle(void)
{
	return style_;
}


