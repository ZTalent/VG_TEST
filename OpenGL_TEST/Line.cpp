#include "Line.h"

Line::Line(void)
{
	line_style_ = single;
	cstyle = line;
	isCir = false;
	count = 1;
	line_width_ = 1;
}

Line::~Line(void)
{
	ColorList.clear();
	point_list_.clear();
}

void Line::AddPoint(const glm::fvec3& position)
{
	point_list_.push_back(position);
}

void Line::AddPoint(const float x, const float y, const float z)
{
	point_list_.push_back(glm::fvec3(x, y, z));
}

void Line::SetWidth(float line_width)
{
	line_width_ = line_width;
	isSetW = true;
}

void Line::SetLineColor(const glm::fvec3& line_color)
{
	ColorList.push_back(line_color);
}

void Line::SetLineColor(const float r, const float g, const float b)
{
	glm::fvec3 temp = glm::fvec3(r, g, b);
	ColorList.push_back(temp);
}

void Line::SetLineStyle(LineStyle line_style)
{
	switch (line_style)
	{
	case single:
		style_ = GL_LINES;
		break;
	case loop:
		style_ = GL_LINE_LOOP;
		break;
	case strip:
		style_ = GL_LINE_STRIP;
		break;
	}
}

void Line::end()
{
	Shape::vector2float(point_list_, ColorList, real_render_);
}

glm::fvec3 Line::GetColor(void)
{
	return line_color_;
}

float Line::GetWidth(void)
{
	return line_width_;
}

GLenum Line::GetStyle(void)
{
	return style_;
}
