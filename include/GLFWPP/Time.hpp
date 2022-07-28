#pragma once

#include <GLFW/glfw3.h>

namespace glfwpp
{

namespace Time
{

inline void	  setTime(double time) { glfwSetTime(time); }
inline double getTime() { return glfwGetTime(); }

} // namespace Time

} // namespace glfwpp
