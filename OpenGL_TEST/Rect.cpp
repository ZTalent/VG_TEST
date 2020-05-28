#include "Rect.h"
#include "Point.h"


Rect::Rect(void)
{
	rect_style_ = rect_polygon;
	cstyle = rect;
	isCir = false;
	count = 1;
}

Rect::Rect(glm::fvec3 start_position, glm::fvec3 end_position)
{
	rect_style_ = rect_polygon;
	Rect::AddPoint(start_position, end_position);
	cstyle = rect;
	isCir = false;
}

Rect::~Rect(void)
{
	real_render_.clear();
	ColorList.clear();
	point_list_.clear();
}

void Rect::AddPoint(glm::fvec3 start_position, glm::fvec3 end_position)
{
	point_list_.push_back(start_position);
	point_list_.push_back(glm::fvec3(end_position.x, start_position.y, start_position.z));
	point_list_.push_back(glm::fvec3(start_position.x, end_position.y, start_position.z));

	point_list_.push_back(end_position);
	point_list_.push_back(glm::fvec3(start_position.x, end_position.y, start_position.z));
	point_list_.push_back(glm::fvec3(end_position.x, start_position.y, start_position.z));

}

void Rect::AddRect(glm::fvec3 point_position, float w, float h)
{
	//point_position为矩形左下角点
	point_list_.push_back(point_position);
	point_list_.push_back(glm::fvec3(point_position.x + w, point_position.y, point_position.z));
	point_list_.push_back(glm::fvec3(point_position.x, point_position.y + h, point_position.z));

	point_list_.push_back(glm::fvec3(point_position.x + w, point_position.y + h, point_position.z));
	point_list_.push_back(glm::fvec3(point_position.x, point_position.y + h, point_position.z));
	point_list_.push_back(glm::fvec3(point_position.x + w, point_position.y, point_position.z));
}

void Rect::SetRectColor(const glm::fvec3& color)
{
	rect_color_ = color;
	TempColor.push_back(rect_color_);
}

void Rect::SetRectColor(const float r, const float g, const float b)
{
	rect_color_ = glm::fvec3(r, g, b);
	TempColor.push_back(rect_color_);
}

void Rect::SetRectStyle(RectStyle rect_style)
{
	rect_style_ = rect_style;
	switch (rect_style_)
	{
	case rect_line:
		style_ = GL_LINE_LOOP;
		break;
	case rect_polygon:
		style_ = GL_TRIANGLES;
		break;
	}
}

glm::fvec3 Rect::GetColor()
{
	return rect_color_;
}

GLenum Rect::GetStyle()
{
	return style_;
}

void Rect::end()
{
	ColorChange();
	Shape::vector2float(point_list_, ColorList, real_render_);
}

void Rect::ColorChange()
{
	for (int i = 0; i < TempColor.size(); i++)
	{
		for (int j = 0; j < 6; j++)
		{
			ColorList.push_back(TempColor[i]);
		}
	}
}


