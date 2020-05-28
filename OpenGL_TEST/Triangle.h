#pragma once
#include "Point.h"
#include "Shape.h"
class Triangle :
	public Point
{
public:
	Triangle(void);
	~Triangle(void);

	void AddPoint(const glm::fvec3& position);
	void AddPoint(const float x, const float y, const float z);
	void end();
	void SetPointColor(const glm::fvec3& color);
	void SetPointColor(const float r, const float g, const float b);
	void SetStyle(GLenum style);
	glm::fvec3 GetColor(void);
	GLenum GetStyle(void);
private:
	GLenum style_;
	CStyle cstyle = triangle;
};