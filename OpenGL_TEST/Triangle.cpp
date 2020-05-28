#include "Triangle.h"
#include "Point.h"


Triangle::Triangle(void)
{
	style_ = GL_TRIANGLES;
	isCir = false;
	count = 1;
}

Triangle::~Triangle(void)
{
}

void Triangle::AddPoint(const glm::fvec3& position)
{
	Point::AddPoint(position);
}

void Triangle::AddPoint(const float x, const float y, const float z)
{
	Point::AddPoint(x, y, z);
}

void Triangle::end()
{
	Point::vector2float(point_list_, ColorList, real_render_);
}

void Triangle::SetPointColor(const glm::fvec3& color)
{
	Point::SetColor(color);
}

void Triangle::SetPointColor(const float r, const float g, const float b)
{
	Point::SetColor(r, g, b);
}

void Triangle::SetStyle(GLenum style)
{
	style_ = style;
}

glm::fvec3 Triangle::GetColor(void)
{
	return Point::GetColor();
}

GLenum Triangle::GetStyle(void)
{
	return style_;
}
