#include <GLFWPP/Library.hpp>

#include <GLFW/glfw3.h>

namespace glfwpp
{
GLFWInitException::GLFWInitException(int code, const char* description)
{
	m_error.append("Error code : ");
	m_error.append(std::to_string(code));
	m_error.append("\n Description : ");
	m_error.append(description);
}

const char* GLFWInitException::what() const noexcept { return m_error.c_str(); }

void Library::initialize() noexcept(false)
{
	glfwInit();

	const char* description = nullptr;

	int code = glfwGetError(&description);
	if(description)
		throw GLFWInitException(code, description);

	// V-Sync
	glfwSwapInterval(1);
}

void Library::terminate()
{
	glfwTerminate();
}

} // namespace glfwpp
