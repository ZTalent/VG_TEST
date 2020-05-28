#pragma once
#include "Shape.h"
class Point :
	public Shape
{
public:
	Point(void);
	~Point();
	void AddPoint(const glm::fvec3& position);
	void AddPoint(const float x, const float y, const float z);
	void end();
	void SetSize(int point_size);
	void SetColor(const glm::fvec3& color);
	void SetColor(const float r, const float g, const float b);
	
	glm::fvec3 GetColor(void);
	float GetSize(void);
	GLenum GetStyle(void);
	
protected:
	glm::fvec3 point_position_;
	glm::fvec3 point_color_;
	float point_size_;
	GLenum style_ = GL_POINTS;
};

