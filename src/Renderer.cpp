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

/**
 * Default constructor for the method.
 * @param isTerminating points to the thread termination signal variable in Core.
 */
Renderer::Renderer(bool* isTerminating){
  isTerminating = isTerminating;
}


/**
 * Built on GLFW example docs (https://www.glfw.org/docs/latest/window_guide.html)
 * Internal method, instantiates an OpenGL window.
 * @returns status code, indicating success of window instantiation.
 */
int Renderer::instantiateWindow() {

  /* Initialize the library */
  if (!glfwInit())
    return -1;


  /* Create a windowed mode window and its OpenGL context */
  window = glfwCreateWindow(400, 400, "Divide and Concur", nullptr, nullptr);

  if (!window) {
    glfwTerminate();
    return -1;
  }

  /* Make the window's context current */
  glfwMakeContextCurrent(window);
  cout << "Message from renderer thread.";


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
}
/**
 * Starts the thread that runs the renderer.
 */
void Renderer::start(){
  DWORD threadID;
  unsigned int threadCount = 0;
  CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)initSelf, &threadCount, 0, &threadID);

}

/**
 * Internal method, used to create the thread of the renderer component
 * @param lpParameter Data to be passed to the new thread.
 * @return Unused.
 * @see Core.initSelf
 */
DWORD WINAPI Renderer::initSelf(LPVOID* lpParameter) {
  // Instantiate components
  Renderer *renderer = (Renderer*)lpParameter;
  renderer->initialise();
  return 0;
}


/**
 * Initialises the renderer.
 * @return
 */
int Renderer::initialise() {

  if(instantiateWindow() == -1){
    printf("Failed to instantiate openGL");
    return -1;
  }

  renderLoop();
  return 0;
}
