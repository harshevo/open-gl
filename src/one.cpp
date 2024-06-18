#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main() 
{
  GLFWwindow* window = window;

  if(!glfwInit())
  {
    return -1;
  }

  if(!window)
  {
    glfwTerminate();
    return -1;
  }

  window = glfwCreateWindow(640, 480, "OpenGL", NULL, NULL);
  glfwMakeContextCurrent(window);

  if(glewInit() != GLEW_OK)
  {
    std::cout << "Failed to Init GLEW !!" << std::endl;
    return -1;
  }

  while(!glfwWindowShouldClose(window))
  {
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
}