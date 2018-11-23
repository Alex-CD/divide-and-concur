//
// Created by Alex on 09/11/2018.
//

#include "renderer.h"

#include <stdint.h>
#include <string>
#include <iostream>
#include <glad/glad.h>

#include <GLFW/glfw3.h>


GLFWwindow *window;

int instantiateWindow() {

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

  glfwTerminate();
  return 0;
}


int initalise() {
  if(instantiateWindow() == -1){
    printf("Failed to instantiate openGL");
    return -1;
  }


  while (!glfwWindowShouldClose(window)) {
  }
}

int renderLoop(){
  /*
   * Draw objects from currentscene in back buffer here.
   * */

  /* Render here */
  glClear(GL_COLOR_BUFFER_BIT);

  /* Swap front and back buffers */
  glfwSwapBuffers(window);

  /* Poll for and process events */
  glfwPollEvents();

}
