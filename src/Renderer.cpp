//
// Created by Alex on 09/11/2018.
//

#include <stdint.h>
#include <string>
#include <iostream>
#include <glad.c>
#include <GLFW/glfw3.h>

#include "FileHelper.h"
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

  const GLubyte *ver = glGetString( GL_SHADING_LANGUAGE_VERSION);

  renderLoop();
}

/**
 *
 * @param toSave
 */
void Renderer::saveLog(char *toSave, string filename){
  FileHelper::saveString(toSave, "logs/" + filename);
};

/**
 *
 * @param sourceFile
 * @return
 */
string Renderer::loadShader(string sourceFile){
  return FileHelper::loadString("shaders/" + sourceFile);
};


/**
 *
 */
void Renderer::initGL(){
  glfwSwapInterval(1);


  this->shaderProgram = glCreateProgram();

  glGenBuffers(1, &this->vertexBuffer);
  glBufferData(GL_ARRAY_BUFFER, 10000, nullptr, GL_DYNAMIC_DRAW);


  // Loading and compiling vertex shader (then logging)
  GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
  const char* vertex_src = loadShader("VertexShader.vsh").c_str();
  glShaderSource(vertexShader, 1, &vertex_src, nullptr);
  glCompileShader(vertexShader);
  glAttachShader(this->shaderProgram, vertexShader);

  GLint operationSuccess;
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &operationSuccess);


  if(!operationSuccess)
  {
    cout << vertex_src;
    char* logText = new char[512];
    memset(logText, '\0', 512);
    glGetShaderInfoLog(vertexShader, 512, nullptr, logText);
    saveLog(logText, "VertexCompile");
    *this->isTerminating = true;
  };


  // Loading and compiling fragment shader (then logging)
  GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  const char* fragment_src = loadShader("FragmentShader.fsh").c_str();
  glShaderSource(fragmentShader, 1, &fragment_src, nullptr);
  glCompileShader(fragmentShader);
  glAttachShader(this->shaderProgram, fragmentShader);


  glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &operationSuccess);

  if(!operationSuccess)
  {
    char* logText = new char[512];
    memset(logText, '\0', 512);
    glGetShaderInfoLog(fragmentShader, 512, nullptr, logText);
    saveLog(logText, "FragmentCompile");
    *this->isTerminating = true;
  };


  // Attaching shaders to shader program (then logging)
  glLinkProgram(this->shaderProgram);
  glad_glGetProgramiv(this->shaderProgram, GL_LINK_STATUS, &operationSuccess);


  if(!operationSuccess) {
    char* logText = new char[512];
    memset(logText, '\0', 512);

    glGetProgramInfoLog(shaderProgram, 512, nullptr, logText);
    saveLog(logText, "ShadersLink");
    *this->isTerminating = true;
  }

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
