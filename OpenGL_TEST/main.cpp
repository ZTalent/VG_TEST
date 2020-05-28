#ifndef GLAD_STATIC
#define GLAD_STATIC


#include "glad/glad.h"
#include <GLFW/glfw3.h>

#include <iostream>
#include "Loader.h"
#include "GLRender.h"
#include "Shader.h"
#include "Point.h"
#include "Line.h"
#include "Triangle.h"
#include "Rect.h"
#include "Circle.h"
#include "DisplayManager.h"
#include <ctime>
#include <ratio>
#include <chrono>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

int main()
{
	DisplayManager mDisplayMgr; 
	mDisplayMgr.createDisplay();             //窗口的创建
	
#pragma region Point
	Point* test_point = new Point();
	//set position
	test_point->AddPoint(-0.3, -0.6, 0.0);
	test_point->AddPoint(glm::fvec3(0.8, 0.2, 0.0));
	test_point->AddPoint(glm::fvec3(-0.5, 0.5, 0.0));
	test_point->AddPoint(0.3, 0.25, 0.0);
	test_point->SetColor(1.0, 0.0, 0.0);
	test_point->SetColor(glm::fvec4(1.0, 1.0, 0.0, 1.0));
	test_point->SetColor(0.5, 0.4, 0.3);
	test_point->SetColor(0.0, 1.0, 0.0);
	
	for (int i=0;i<100;i++)
	{
		test_point->AddPoint(-1.0 + 0.01 * i, -1.0 + 0.01 * i, 0.0);
		test_point->SetColor(0.002 * i, 0.003 * i, 0.01 * i);
	}
	//set color
	
	//set size
	test_point->SetSize(8);

	test_point->end();
#pragma endregion

#pragma  region Line
	Line* test_line = new Line();
	//set position	
	test_line->AddPoint(-0.3, -0.8, 0.0);
	test_line->AddPoint(0.5, -0.5, 0.0);

	test_line->AddPoint(0.5, 0.0, 0.0);
	test_line->AddPoint(0.5, 0.5, 0.0);

	test_line->AddPoint(0.5, 0.8, 0.0);
	test_line->AddPoint(0.0, 0.5, 0.0);

	//set color
	test_line->SetLineColor(1.0, 0.0, 0.0);
	test_line->SetLineColor(1.0, 0.0, 0.0);

	test_line->SetLineColor(0.0, 1.0, 0.0);
	test_line->SetLineColor(0.0, 1.0, 0.0);

	test_line->SetLineColor(0.0, 0.0, 1.0);
	test_line->SetLineColor(0.0, 0.0, 1.0);
	
	//set width
	test_line->SetWidth(5);
	
	//set style
	test_line->SetLineStyle(Line::strip);

	test_line->end();

#pragma  endregion

#pragma region Triangle
	Triangle* test_triangle = new Triangle();
	//test_triangle->AddPoint(0.0, 0.0, 0.0);
	//test_triangle->AddPoint(0.7, -0.7, 0.0);
	//test_triangle->AddPoint(0.7, 0.0, 0.0);

	//test_triangle->SetPointColor(1.0, 0.0, 0.0);
	//test_triangle->SetPointColor(1.0, 0.0, 0.0);
	//test_triangle->SetPointColor(1.0, 0.0, 0.0);


	test_triangle->AddPoint(0.0, 0.0, 0.0);
	test_triangle->AddPoint(-0.5, 0.5, 0.0);
	test_triangle->AddPoint(-0.5, 0.0, 0.0);

	test_triangle->SetPointColor(1.0, 0.0, 0.0);
	test_triangle->SetPointColor(0.0, 1.0, 0.0);
	test_triangle->SetPointColor(0.0, 0.0, 1.0);

	test_triangle->end();
#pragma endregion

#pragma region Rectangle
	Rect* test_rectangle = new Rect();
	test_rectangle->AddPoint(glm::fvec3(-0.75, -0.75, 0.0), glm::fvec3(-0.3, -0.3, 0.0));
	test_rectangle->SetRectColor(1.0, 1.0, 0.0);
	//test_rectangle->AddRect(glm::fvec3(0.0, 0.0, 0.0), 0.5, 0.5);
	//test_rectangle->SetRectColor(1.0, 0.0, 0.0);
	test_rectangle->AddRect(glm::fvec3(-0.8, 0.2, 0.0), 0.5, 0.5);
	test_rectangle->SetRectColor(0.0, 1.0, 0.0);
	test_rectangle->AddRect(glm::fvec3(0.2, -0.4, 0.0), 0.2, 0.3);
	test_rectangle->SetRectColor(0.3, 0.5, 0.6);

	for (int i = 0; i <= 10000; i++)
	{
		test_rectangle->AddPoint(glm::fvec3(-0.5+0.00005*i, 0.5-0.00005*i, 0.0), glm::fvec3(0.5-0.00005*i, -0.5+0.00005*i, 0.0));
		if (i%2==0)
		{
			test_rectangle->SetRectColor(1.0,0.0,0.0);
		}
		else
		{
			test_rectangle->SetRectColor(1.0, 1.0, 0.0);
		}
		
	}

	test_rectangle->SetRectStyle(Rect::rect_polygon);
	test_rectangle->end();
#pragma endregion

#pragma region Circle
	Circle* test_circle = new Circle();

	test_circle->AddCenterPosition(-0.5, 0.5, 0.0);
	test_circle->SetCircleColor(glm::vec3(1.0, 1.0, 0.0));
	test_circle->SetRadius(0.3);

	test_circle->AddCenterPosition(0.5, 0.3, 0.0);
	test_circle->SetCircleColor(glm::vec3(0.4, 0.2, 0.8));
	test_circle->SetRadius(0.5);

	test_circle->AddCenterPosition(0.3, -0.2, 0.0);
	test_circle->SetCircleColor(glm::vec3(0.0, 0.2, 0.8));
	test_circle->SetRadius(0.4);

	test_circle->AddCenterPosition(-0.7, -0.6, 0.0);
	test_circle->SetCircleColor(glm::vec3(0.3, 0.2, 0.5));
	test_circle->SetRadius(0.5);

	/*for (int i = 0; i < 1000; i++)
	{
		test_circle->AddCenterPosition(0.0, 0.0, 0.0);
		if (i % 2 == 0)
		{
			test_circle->SetCircleColor(1.0, 1.0, 1.0);
		}
		else
		{
			test_circle->SetCircleColor(0.0, 0.0, 0.0);
		}
		test_circle->SetRadius(0.3+((float)1/(i+2)));
	}*/

	test_circle->SetWidth(1.0);
	test_circle->SetStyle(Circle::circle_polygon);
	test_circle->end();

#pragma endregion

#pragma region SetVB&Shader
	Shader* myShader = new Shader("../Shader/point.vert", "../Shader/point.frag");
	GLRender* render = new GLRender();
	Loader* loader = new Loader();
	
	loader->AddShape(test_triangle);
	loader->AddShape(test_line);
	loader->AddShape(test_rectangle);
	//loader->AddShape(test_circle);
	loader->AddShape(test_point);
	loader->end();
	
	render->SetBackGroundColor(0.2, 0.3, 0.3, 1.0);
	render->BindLoader(loader->GetModels());
	render->BindShader(myShader);

#pragma endregion

#pragma region loop
	int count = 0;
	float average = 0;
	while (!mDisplayMgr.isRequestClosed())
	{
		count++;
		render->init();                      //渲染相关的内容初始化
		myShader->use();                     //着色器的使用
		std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
		render->StartRender();	 	         //开始渲染
		std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
		std::cout << "in millisecond time:";
		std::chrono::duration<double, std::ratio<1, 1000000>> duration_mcs = std::chrono::duration_cast<std::chrono::duration<double, std::ratio<1, 1000000>>>(t2 - t1);
		std::cout << duration_mcs.count() << "microseconds" << std::endl;
		average += duration_mcs.count();
		mDisplayMgr.updateDisplay();
		myShader->stop();
	}
	loader->CleanUp();
	mDisplayMgr.closeDisplay();
	std::cout << "average time=" <<average/count<< "microseconds"<<std::endl;
	return 0;
}
#pragma endregion

#endif