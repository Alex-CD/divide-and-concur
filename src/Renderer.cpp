//
// Created by Alex on 09/11/2018.
//

#include <stdint.h>
#include <string>
#include <iostream>
#include <glad.c>
#include <fstream>
#include <GLFW/glfw3.h>
#include <sstream>

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

  initWindow();

  initGL();

  renderLoop();
}

/**
 *
 * @param sourceFile
 * @return
 */
string Renderer::loadShader(string sourceFile){
  ifstream fileStream;
  string path = "shaders/" + sourceFile;

  fileStream.open(path);

  if (!fileStream.good()){
    return "fail!";
  }
  std::stringstream streamBuffer;

  streamBuffer << fileStream.rdbuf();
  fileStream.close();

  return streamBuffer.str();
};

void Renderer::initGL(){
  glfwSwapInterval(1);

  this->shaderProgram = glCreateProgram();

  glGenBuffers(1, &this->vertexBuffer);

  glBufferData(GL_ARRAY_BUFFER, 10000, nullptr, GL_DYNAMIC_DRAW);


  GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
  const char* vertex_src = loadShader("VertexShader.vsh").c_str();
  glShaderSource(vertexShader, 1, &vertex_src, nullptr);
  glCompileShader(vertexShader);
  glAttachShader(vertexShader, GL_VERTEX_SHADER);

  GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  const char* fragment_src = loadShader("FragmentShader.fsh").c_str();
  glShaderSource(fragmentShader, 1, &fragment_src, nullptr);
  glCompileShader(fragmentShader);
  glAttachShader(fragmentShader, GL_FRAGMENT_SHADER);

  GLint linkSuccess;
  glad_glGetProgramiv(this->shaderProgram, GL_LINK_STATUS, &linkSuccess);

  if(!linkSuccess) {
    cout << "failure to lin shaders";
    *this->isTerminating = true;
  }
  glLinkProgram(this->shaderProgram);
  glUseProgram(this->shaderProgram);

}

/**
 *
 * Built on GLFW example docs (https://www.glfw.org/docs/latest/window_guide.html)
 * Internal method, instantiates an OpenGL window.
 * @returns status code, indicating success of window instantiation.
 */
int Renderer::initWindow() {

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
  while(!glfwWindowShouldClose(this->window) && !isTerminating) {

    glClear(GL_COLOR_BUFFER_BIT);

    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f,  0.5f, 0.0f
    };


    /* Swap front and back buffers */
    glfwSwapBuffers(window);


    glfwPollEvents();
    // glfwWaitEvents();
    // Pauses program until input (useful for debug)

  }

  *this->isTerminating = true;
  glfwTerminate();
}
