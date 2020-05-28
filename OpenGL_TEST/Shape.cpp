#include "Shape.h"

Shape::Shape(void)
{
}

Shape::~Shape()
{
}

void Shape::vector2float(std::vector<glm::fvec3> render_point, std::vector<glm::fvec3> render_color, std::vector<float>& render_list)
{
	for (int i = 0; i < render_point.size(); i++)
	{
		render_list.push_back(render_point[i].x);
		render_list.push_back(render_point[i].y);
		render_list.push_back(render_point[i].z);

		render_list.push_back(render_color[i].x);
		render_list.push_back(render_color[i].y);
		render_list.push_back(render_color[i].z);
	}
}

glm::fvec3 Shape::GetPosition()
{
	return glm::fvec3();
}

glm::fvec3 Shape::GetColor()
{
	return glm::fvec3();
}

GLenum Shape::GetStyle()
{
	return GLenum();
}

Shape::CStyle Shape::GetShapeStyle()
{
	return cstyle;
}

bool Shape::IsCir()
{
	return isCir;
}

bool Shape::IsSetSize()
{
	return isSetS;
}

bool Shape::IsSetWidth(void)
{
	return isSetW;
}

float Shape::GetSize(void)
{
	return 0.0f;
}

float Shape::GetWidth(void)
{
	return 0.0f;
}

float Shape::GetRadius(int index)
{
	return 0.0f;
}

glm::fvec3 Shape::GetCenterPosition(int index)
{
	return glm::fvec3();
}

glm::fvec3 Shape::GetColor(int index)
{
	return glm::fvec3();
}

unsigned int Shape::GetVAOID()
{
	return vao;
}

void Shape::SetVAO(unsigned int vaoid_)
{
	vao = vaoid_;
}

int Shape::GetCount(void)
{
	return count;
}
