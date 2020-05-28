#include "Display.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>

void Display::create(ContextAttri attr)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, attr.major);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, attr.minor);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	/*if (attr.bProfileCore) {
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	}*/

	mWindow = glfwCreateWindow(mDisplayMode.width, mDisplayMode.height, title, NULL, NULL);
	if (mWindow == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return;
	}
	glfwMakeContextCurrent(mWindow);
	glfwSetFramebufferSizeCallback(mWindow, frameBufferSizeCallback);
	
	if (!gladLoadGL())
	{
		printf("Init GLAD failed.");
		glfwTerminate();
		return ;
	}
}

void Display::update()
{
	glfwPollEvents();
	glfwSwapBuffers(mWindow);
	processEvent();
}

void Display::destroy()
{
	glfwDestroyWindow(mWindow);
	glfwTerminate();
	mWindow = nullptr;
}

bool Display::isRequestClosed()
{
	return glfwWindowShouldClose(mWindow);
}

void Display::setDisplayMode(DisplayMode mode)
{
	mDisplayMode = mode;
}

void Display::setTitle(const char* _title)
{
	title = _title;
}

void Display::frameBufferSizeCallback(GLFWwindow*, int w, int h)
{
	glViewport(0, 0, w, h);
}

bool Display::isKeyPressed(unsigned int keyCode)
{
	return glfwGetKey(mWindow, keyCode) == GLFW_PRESS;
}

void Display::processEvent()
{
	if (glfwGetKey(mWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(mWindow, true);
	}
}

DisplayMode::DisplayMode()
{
	width = 0;
	height = 0;
}

DisplayMode::DisplayMode(int w, int h)
{
	width = w;
	height = h;
}
