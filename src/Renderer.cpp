//
// Created by Alex on 09/11/2018.
//

#include "Renderer.h"
#include <stdint.h>
#include <string>
#include <iostream>
#include <glad.c>
#include <GLFW/glfw3.h>

GLFWwindow *window;
Renderer::Renderer(bool* isTerminating){
  isTerminating = isTerminating;
}


int Renderer::instantiateWindow() {

  /* Initialize the library */
  if (!glfwInit())
    return -1;


  /* Create a windowed mode window and its OpenGL context */
  window = glfwCreateWindow(400, 400, "Hello World", nullptr, nullptr);

  if (!window) {
    glfwTerminate();
    return -1;
  }

  /* Make the window's context current */
  glfwMakeContextCurrent(window);


  if (!gladLoadGL()) {
    printf("Something went wrong!\n");
    exit(-1);
  }


  return 0;
}


int Renderer::renderLoop(){
  while(!glfwWindowShouldClose(window) || *isTerminating) {
    // TODO draw objects into back frame buffer

    /* Render here */
    glClear(GL_COLOR_BUFFER_BIT);

    /* Swap front and back buffers */
    glfwSwapBuffers(window);

    /* Poll for and process events */
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}

void Renderer::start(){
  DWORD threadID;
  unsigned int threadCount = 0;
  CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)initSelf, &threadCount, 0, &threadID);

}

DWORD WINAPI Renderer::initSelf(LPVOID* lpParameter) {
  // Instantiate components
  Renderer *renderer = (Renderer*)lpParameter;
  renderer->initialise();
  return 0;
}



int Renderer::initialise() {


  // TODO create new thread and run render loop
  if(instantiateWindow() == -1){
    printf("Failed to instantiate openGL");
    return -1;
  }

  renderLoop();
  return 0;
}
