cmake_minimum_required (VERSION 2.8)

# projectname is the same as the main-executable
project(QtOpenGL)

add_definitions('-g')
add_definitions('-Wall')
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(Qt5 COMPONENTS Core Widgets OpenGL REQUIRED)
set(CMAKE_AUTOMOC ON)
include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} src/MainWidget.cpp src/QOglTest.cpp)
target_link_libraries(${PROJECT_NAME} Qt5::Widgets Qt5::OpenGL ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})


