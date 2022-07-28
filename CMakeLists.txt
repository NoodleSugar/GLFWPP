cmake_minimum_required(VERSION 3.22.0)
project(
	GLFWPP
		VERSION 0.0.1
		DESCRIPTION "GLFW Wrapper for C++"
		LANGUAGES CXX
)

add_library(${PROJECT_NAME} STATIC)

set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17)

target_include_directories(${PROJECT_NAME} PUBLIC include)

if(TARGET_WINDOWS)
	set(GlfwLibs glfw3 gdi32)
else()
	set(GlfwLibs glfw)
endif()

target_link_libraries(${PROJECT_NAME}
	PRIVATE
		${GlfwLibs}
)

target_sources(${PROJECT_NAME}
	PRIVATE
		src/Library.cpp
		src/Window.cpp
		src/EventManager.cpp
)