#pragma once
#include "Shape.h"

const int accuracy = 36000;
const float PI = 3.1415926f;

class Circle :
	public Shape
{
public:
	enum CircleStyle { circle_polygon, circle_line };
	Circle(void);
	Circle(const glm::fvec3 positon, const glm::fvec3 color, const float r);
	~Circle(void);

	void AddCenterPosition(glm::fvec3 position);
	void AddCenterPosition(float x, float y, float z);
	void SetCircleColor(glm::fvec3 color);
	void SetCircleColor(float r, float g, float b);
	void SetRadius(float r);
	void SetWidth(float line_width);
	void SetStyle(CircleStyle style);

	glm::fvec3 GetCenterPosition(int index);
	glm::fvec3 GetColor(int index);
	GLenum GetStyle(void);
	float GetRadius(int index);
	float GetWidth(void);
	void end();
	bool isLine;
private:
	glm::fvec3 center_position_;
	glm::fvec3 circle_color_;
	std::vector<glm::fvec3> center_positions_;
	std::vector<float> radius_;
	float radius;
	float line_width_;
	GLenum style_;
};

