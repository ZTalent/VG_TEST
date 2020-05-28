#include "GLRender.h"

GLRender::GLRender()
{
	backgroun_color = glm::fvec4(0.2, 0.3, 0.3, 1.0);
}

GLRender::~GLRender()
{
}

void GLRender::Render(Shape* shape_test)
{
	if (shape_test->GetShapeStyle() == Shape::circle)
	{

		for (int i = 0; i < shape_test->GetCount(); i++)
		{
			render_shader->setBool("isCircle", shape_test->IsCir());
			render_shader->setVec3("CenterPosition", shape_test->GetCenterPosition(i));
			render_shader->setVec3("CColor", shape_test->GetColor(i));
			render_shader->setFloat("R", shape_test->GetRadius(i));
			if (shape_test->IsSetWidth())
			{
				glLineWidth(shape_test->GetWidth());
			}
			glDrawArrays(shape_test->GetStyle(), 0, shape_test->real_render_.size());
		}
		render_shader->setBool("isCircle", false);
	}
	else
	{
		if (shape_test->IsSetSize())
		{
			glPointSize(shape_test->GetSize());
		}
		if (shape_test->IsSetWidth())
		{
			glLineWidth(shape_test->GetWidth());
		}
		glDrawArrays(shape_test->GetStyle(), 0, shape_test->real_render_.size() / 6);
	}
}

void GLRender::BindLoader(std::vector<class Shape*> models_)
{
	render_models = models_;
}

void GLRender::BindShader(Shader* shader_test)
{
	render_shader = shader_test;
}

void GLRender::init()
{
	glClearColor(backgroun_color.x,backgroun_color.y,backgroun_color.z,backgroun_color.w);
	glClear(GL_COLOR_BUFFER_BIT);
}

void GLRender::StartRender()
{
	for (int i=0;i<render_models.size();i++)
	{
		glBindVertexArray(render_models[i]->GetVAOID());
		Render(render_models[i]);
	}
}

void GLRender::SetBackGroundColor(glm::fvec4 background_color_)
{
	backgroun_color = background_color_;
}

void GLRender::SetBackGroundColor(float r, float g, float b, float a)
{
	backgroun_color = glm::fvec4(r, g, b, a);
}
