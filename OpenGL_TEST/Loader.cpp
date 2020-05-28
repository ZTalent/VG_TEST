#include "Loader.h"

void Loader::end()
{
	for (int i=0; i<models.size(); i++)
	{
		models[i]->SetVAO(CreateVAO());
		BindBuffer(models[i]);
		UnbindVAO();
	}
}

void Loader::AddShape(Shape* shape_test)
{
	models.push_back(shape_test);
}

void Loader::CleanUp()
{
	if (models.size() > 0) {
		for (Shape* item : models) {
			delete item;
		}
	}

	if (vaos.size() > 0) {
		glDeleteVertexArrays(vaos.size(), vaos.data());
	}

	if (vbos.size() > 0) {
		glDeleteBuffers(vbos.size(), vbos.data());
	}
}

std::vector<class Shape*> Loader::GetModels()
{
	return models;
}

unsigned int Loader::CreateVAO()
{
	unsigned int VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	vaos.push_back(VAO);
	return VAO;
}

void Loader::UnbindVAO()
{
	glBindVertexArray(0);
}

void Loader::BindBuffer(Shape* shape_test)
{
	unsigned int VBO;
	if (shape_test->GetShapeStyle() == Shape::circle)
	{

		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(float) * (shape_test->real_render_.size()), &((shape_test->real_render_)[0]), GL_STATIC_DRAW);
		glVertexAttribPointer(2, 1, GL_FLOAT, GL_FALSE, sizeof(float), (void*)0);
		glEnableVertexAttribArray(2);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
	else
	{
		
		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(float) * (shape_test->real_render_.size()), &((shape_test->real_render_)[0]), GL_DYNAMIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
	vbos.push_back(VBO);
}
