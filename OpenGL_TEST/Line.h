#pragma once
#include "Shape.h"

class Line :
	public Shape
{
public:
	enum LineStyle { single, loop, strip };
	Line(void);
	~Line(void);

	void AddPoint(const glm::fvec3& position);
	void AddPoint(const float x, const float y, const float z);
	void SetWidth(float line_width);
	void SetLineColor(const glm::fvec3& color);
	void SetLineColor(const float r, const float g, const float b);
	void SetLineStyle(LineStyle line_style);
	void end();

	glm::fvec3 GetColor(void);
	float GetWidth(void);
	GLenum GetStyle(void);

protected:
	LineStyle line_style_;
	glm::fvec3 line_color_;
	float line_width_;
	GLenum style_;
};

