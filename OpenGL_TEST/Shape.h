#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
class Shape
{
public:
	enum CStyle { point, line, triangle, rect, circle };
	Shape(void);
	~Shape();
	virtual glm::fvec3 GetPosition(void);
	virtual glm::fvec3 GetColor(void);
	virtual GLenum GetStyle(void);
	virtual CStyle GetShapeStyle(void);
	bool IsCir(void);
	bool IsSetSize(void);
	bool IsSetWidth(void);
	virtual float GetSize(void);
	virtual float GetWidth(void);
	

	//圆的相关读取
	virtual float GetRadius(int index);
	virtual glm::fvec3 GetCenterPosition(int index);
	virtual glm::fvec3 GetColor(int index);

	//VAO,VBO绑定相关
	unsigned int GetVAOID();
	void SetVAO(unsigned int vaoid_);

	int GetCount(void);
	CStyle cstyle;
	std::vector<float> real_render_;

protected:
	std::vector<glm::fvec3> point_list_;
	std::vector<glm::fvec3> ColorList;
	bool isCir;
	bool isSetW;
	bool isSetS;
	int count;
	unsigned int vao;
	void vector2float(std::vector<glm::fvec3>render_point, std::vector<glm::fvec3> render_color, std::vector<float>& render_list);

};

