#include <GLFWPP/EventManager.hpp>

namespace glfwpp
{
EventManager::EventManager(Window& rWindow) :
	m_pWindow(rWindow.m_pWindow) {}

void EventManager::pollEvents() { glfwPollEvents(); }

void EventManager::setStickyKeys(bool sticky) { glfwSetInputMode(m_pWindow, GLFW_STICKY_KEYS, sticky ? GLFW_TRUE : GLFW_FALSE); }
void EventManager::setLockKeys(bool lock) { glfwSetInputMode(m_pWindow, GLFW_LOCK_KEY_MODS, lock ? GLFW_TRUE : GLFW_FALSE); }
void EventManager::setCursorMode(CursorMode mode) { glfwSetInputMode(m_pWindow, GLFW_CURSOR, (int)mode); }
void EventManager::setStickyMouseButtons(bool sticky) { glfwSetInputMode(m_pWindow, GLFW_STICKY_MOUSE_BUTTONS, sticky ? GLFW_TRUE : GLFW_FALSE); }

void EventManager::setKeyCallback(GLFWkeyfun callback) { glfwSetKeyCallback(m_pWindow, callback); }
int	 EventManager::getKeyState(int key) { return glfwGetKey(m_pWindow, key); }

void				  EventManager::setCursorCallback(GLFWcursorposfun callback) { glfwSetCursorPosCallback(m_pWindow, callback); }
EventManager::DArray2 EventManager::getCursorPosition()
{
	DArray2 pos;
	glfwGetCursorPos(m_pWindow, &pos[0], &pos[1]);
	return pos;
}

void EventManager::setMouseButtonCallback(GLFWmousebuttonfun callback) { glfwSetMouseButtonCallback(m_pWindow, callback); }
int	 EventManager::getMouseButtonState(int button) { return glfwGetMouseButton(m_pWindow, button); }

void EventManager::setScrollCallback(GLFWscrollfun callback) { glfwSetScrollCallback(m_pWindow, callback); }
} // namespace glfwpp
