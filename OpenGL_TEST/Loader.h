#pragma once
#include "Shape.h"
#include <vector>

class Loader
{
public:
	void end();
	void AddShape(Shape* shape_test);
	void CleanUp();
	std::vector<class Shape*> GetModels();

private:
	unsigned int CreateVAO();

	void UnbindVAO();
	void BindBuffer(Shape* shape_test);

	std::vector<class Shape*> models;
	std::vector<unsigned int> vaos;
	std::vector<unsigned int> vbos;
};

