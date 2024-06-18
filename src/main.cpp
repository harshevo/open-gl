#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main() 
{
  GLFWwindow* window;

  if(!glfwInit())
  {
    return -1;
  }

  window = glfwCreateWindow(640, 480, "OpenGL", NULL, NULL);

  if(!window) {
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);

  if(glewInit() != GLEW_OK)
  {
    std::cout << "Failed to init window";
    glfwTerminate();
    return -1;
  }

  float positions[6] = {
   -0.5f, -0.5f,
    0.0f,  0.5f,
    0.5f, -0.5f,
  };

  unsigned int buffer;
  glGenBuffers(1, &buffer);
  glBindBuffer(GL_ARRAY_BUFFER, buffer);
  glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);
  glEnableVertexAttribArray(0);


  while(!glfwWindowShouldClose(window))
  {
    glClear(GL_COLOR_BUFFER_BIT);

    glDrawArrays(GL_TRIANGLES, 0, 3);
    glfwSwapBuffers(window);

    glfwPollEvents();
  }

  glfwTerminate();
}