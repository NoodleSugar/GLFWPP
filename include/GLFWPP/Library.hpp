#pragma once

#include <exception>
#include <string>

namespace glfwpp
{

class GLFWInitException : public std::exception
{
public:
	GLFWInitException(int, const char*);
	~GLFWInitException() noexcept = default;

	const char* what() const noexcept override;

private:
	std::string m_error;
};

namespace Library
{

void initialize() noexcept(false);
void terminate();

}; // namespace Library

} // namespace glfwpp