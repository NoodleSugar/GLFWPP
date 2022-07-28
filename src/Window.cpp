#include <GLFWPP/Window.hpp>

namespace glfwpp
{

GLFWWindowException::GLFWWindowException(const char* pError) :
	m_error(pError) {}

const char* GLFWWindowException::what() const noexcept { return m_error.c_str(); }

Window::Window(const char* title, int width, int height) :
	m_pWindow(nullptr), m_width(width), m_height(height)
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	m_pWindow = glfwCreateWindow(width, height, title, nullptr, nullptr);
	if(!m_pWindow)
	{
		const char* error;
		glfwGetError(&error);
		throw GLFWWindowException(error);
	}
	glfwMakeContextCurrent(m_pWindow);
}

Window::~Window() { glfwDestroyWindow(m_pWindow); }

void Window::swapBuffer() { glfwSwapBuffers(m_pWindow); }

void Window::setFullscreen() { glfwSetWindowMonitor(m_pWindow, glfwGetPrimaryMonitor(), 0, 0, 0, 0, GLFW_DONT_CARE); }
void Window::setWindowed() { glfwSetWindowMonitor(m_pWindow, nullptr, 0, 0, m_width, m_height, GLFW_DONT_CARE); }
void Window::setBorderless()
{
	GLFWmonitor*	   pMonitor = glfwGetPrimaryMonitor();
	const GLFWvidmode* pMode	= glfwGetVideoMode(pMonitor);
	glfwSetWindowMonitor(m_pWindow, pMonitor, 0, 0, pMode->width, pMode->height, pMode->refreshRate);
}

void Window::setSize(int width, int height)
{
	m_width	 = width;
	m_height = height;
	glfwSetWindowSize(m_pWindow, m_width, m_height);
}

void Window::setSizeMinimum(int width, int height) { glfwSetWindowSizeLimits(m_pWindow, GLFW_DONT_CARE, GLFW_DONT_CARE, width, height); }

void Window::setSizeMaximum(int width, int height) { glfwSetWindowSizeLimits(m_pWindow, width, height, GLFW_DONT_CARE, GLFW_DONT_CARE); }

void Window::setAspectRation(int width, int height) { glfwSetWindowAspectRatio(m_pWindow, width, height); }

void Window::setTitle(const char* title) { glfwSetWindowTitle(m_pWindow, title); }

Window::IArray2 Window::getSize() const
{
	IArray2 size;
	glfwGetWindowSize(m_pWindow, &size[0], &size[1]);
	return size;
}

Window::IArray2 Window::getFramebufferSize() const
{
	IArray2 size;
	glfwGetFramebufferSize(m_pWindow, &size[0], &size[1]);
	return size;
}

Window::FArray2 Window::getContentScale() const
{
	FArray2 scale;
	glfwGetWindowContentScale(m_pWindow, &scale[0], &scale[1]);
	return scale;
}

bool Window::shouldClose() const { return glfwWindowShouldClose(m_pWindow); }
void Window::setShouldClose(bool state) { glfwSetWindowShouldClose(m_pWindow, state ? GLFW_TRUE : GLFW_FALSE); }

} // namespace glfwpp
