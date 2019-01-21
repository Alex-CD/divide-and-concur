//
// Created by Alex on 09/11/2018.
//


#include <stdint.h>
#include <string>
#include <iostream>
#include <glad.c>
#include <GLFW/glfw3.h>

#include "Renderer.h"


Renderer::Renderer(bool *isTerminating) {
  this->isTerminating = isTerminating;
}

/**
 * For multithreading on this component, create a new thread on this method.
 * Calls start()
 */
void *Renderer::threadEntry(void *param){
  auto *thisRenderer = (Renderer*)param;
  thisRenderer->start();
  return nullptr;
}

/**
 * Starts the logic for the renderer module.
 * Terminates when isTerminating is set to true
 * Create a new thread on threadEntry if you need multithreading.1
 */
void Renderer::start(){
  instantiateWindow();
  renderLoop();
}

/**
 * Built on GLFW example docs (https://www.glfw.org/docs/latest/window_guide.html)
 * Internal method, instantiates an OpenGL window.
 * @returns status code, indicating success of window instantiation.
 */
int Renderer::instantiateWindow() {

  /* Initialize the library */
  if (!glfwInit()) {
    *this->isTerminating = true;
    return -1;
  }


  /* Create a windowed mode window and its OpenGL context */
  window = glfwCreateWindow(400, 400, "Divide and Concur", nullptr, nullptr);

  if (!window) {
    *this->isTerminating = true;
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


/**
 * Built on GLFW docs ( https://www.glfw.org/docs/latest/window_guide.html )
 * Internal method, The main render loop of the application.
 * Continues until the window closes or the
 */
void Renderer::renderLoop(){
  while(!glfwWindowShouldClose(this->window) || !isTerminating) {
    // TODO draw objects into back frame buffer

    /* Render here */
    glClear(GL_COLOR_BUFFER_BIT);

    /* Swap front and back buffers */
    glfwSwapBuffers(window);

    /* Poll for and process events */
    glfwPollEvents();

  }

  *this->isTerminating = true;
  glfwTerminate();
}
