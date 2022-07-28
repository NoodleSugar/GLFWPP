#pragma once

#include <GLFW/glfw3.h>

#include <array>
#include <exception>
#include <string>

namespace glfwpp
{

class GLFWWindowException : public std::exception
{
public:
	GLFWWindowException(const char*);

	~GLFWWindowException() noexcept = default;

	const char* what() const noexcept override;

private:
	std::string m_error;
};

class Window
{
	friend class EventManager;

	using IArray2 = std::array<int, 2>;
	using FArray2 = std::array<float, 2>;

public:
	Window(const char* title, int width, int height);

	~Window();

	void swapBuffer();

	void setFullscreen();
	void setWindowed();
	void setBorderless();

	void setSize(int width, int height);
	void setSizeMinimum(int width, int height);
	void setSizeMaximum(int width, int height);
	void setAspectRation(int width, int height);
	void setTitle(const char*);
	// void setIcon(const Image*, int count);

	IArray2 getSize() const;
	IArray2 getFramebufferSize() const;
	FArray2 getContentScale() const;
	// Monitor* getWindowMonitor();

	void setShouldClose(bool);
	bool shouldClose() const;

private:
	GLFWwindow* m_pWindow;

	int m_width;
	int m_height;
};

} // namespace glfwpp