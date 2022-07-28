#pragma once

#include "Window.hpp"

namespace glfwpp
{

enum class CursorMode
{
	Normal	 = GLFW_CURSOR_NORMAL,
	Disabled = GLFW_CURSOR_DISABLED,
	Hidden	 = GLFW_CURSOR_HIDDEN
};

class EventManager
{
	using DArray2 = std::array<double, 2>;

public:
	EventManager() = delete;

	explicit EventManager(Window&);

	static void pollEvents();

	void setStickyKeys(bool);
	void setLockKeys(bool);
	void setCursorMode(CursorMode);
	void setStickyMouseButtons(bool);

	void setKeyCallback(GLFWkeyfun);
	int	 getKeyState(int);

	void	setCursorCallback(GLFWcursorposfun);
	DArray2 getCursorPosition();

	void setMouseButtonCallback(GLFWmousebuttonfun);
	int	 getMouseButtonState(int);

	void setScrollCallback(GLFWscrollfun);

private:
	GLFWwindow* const m_pWindow;
};

} // namespace glfwpp
