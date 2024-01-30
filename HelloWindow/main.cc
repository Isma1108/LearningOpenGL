#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
  glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window) {
  //GLFW_KEY_ESCAPE equals to 256
  if (glfwGetKey(window, 256) == GLFW_PRESS)
    glfwSetWindowShouldClose(window, true);
}

int main() {

  //First we initialize and configure glfw 
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  //Next we create a window object
  GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
  if (window == NULL) {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return -1;
  }
  //We tell GLFW to make the context of our window the main context of the current thread
  glfwMakeContextCurrent(window);

  //GLAD manages function pointers for OpenGL, so we initialize GLAD before
  //we call any OpenGL function 
  //The function to load the address of a OpenGL function pointer is OS-specific,
  //so we can use glfwGetProcAddress that defines the correct function based on our OS.
  if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return -1;
  }

  //We define the viewport (NDC -> depht + viewport transformation -> window space)
  glViewport(0, 0, 800, 600);
  
  //Callback function on the window that gets called each time the window is resized
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  //Render loop
  while(!glfwWindowShouldClose(window)) {
    //input
    processInput(window);

    //rendering commands herw
    //...
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    //check and call events and swap the buffers
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();

  return 0;
}
