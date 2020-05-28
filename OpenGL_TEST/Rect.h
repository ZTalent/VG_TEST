#pragma once
#include "Point.h"
#include "Shape.h"
class Rect :
	public Shape
{
public:
	enum RectStyle { rect_line, rect_polygon };
	Rect(void);
	Rect(glm::fvec3 start_position, glm::fvec3 end_position);
	~Rect(void);
	void AddPoint(glm::fvec3 start_position, glm::fvec3 end_position);
	void AddRect(glm::fvec3 point_position, float w, float h);
	void SetRectColor(const glm::fvec3& color);
	void SetRectColor(const float r, const float g, const float b);
	void SetRectStyle(RectStyle rect_style);
	glm::fvec3 GetColor();
	GLenum GetStyle();
	void end();
private:
	std::vector<glm::fvec3>TempColor;
	glm::fvec3 rect_color_;
	GLenum style_;
	RectStyle rect_style_;

	void ColorChange();
};

