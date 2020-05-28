#pragma once
#include "glad/glad.h"
#include "Shape.h"
#include "Shader.h"
#include "Loader.h"
#include <iostream>
class GLRender
{
public:
	GLRender();
	~GLRender();
	
	void BindLoader(std::vector<class Shape*> models_);
	void BindShader(Shader* shader_test);
	void init();
	void StartRender();
	void SetBackGroundColor(glm::fvec4 background_color_);
	void SetBackGroundColor(float r,float g,float b,float a);

private:
	glm::fvec4 backgroun_color;
	std::vector<class Shape*> render_models;
	Shader* render_shader;
	void Render(Shape* shape_test);
	
};

