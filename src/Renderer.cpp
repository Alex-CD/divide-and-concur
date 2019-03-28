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
#include "renderables/DoubleLinkedObject.h"



/**
 *
 * @param isTerminating
 */
Renderer::Renderer(bool *isTerminating, int *maxObjects, DoubleLinkedObject *objects, Mouse *mouse) {
  this->isTerminating = isTerminating;
  this->maxObjects = maxObjects;
  this->objects = objects;
  this->mouse = mouse;

  this->xViewportSizePx = 400;
  this->yViewportSizePx = 400;
}


/**
 * For multithreading on this component, create a new thread on this method.
 * Calls start()
 */
void *Renderer::threadEntry(void *param){
  cout << "started!";
  auto thisRenderer = (Renderer *)param;
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
 */
void Renderer::hideCursor(){
  glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
}

/**
 *
 */
void Renderer::showCursor(){
  glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
}

/**
 *
 * @param toSave
 */
void Renderer::saveLog(char *toSave, string filename){
  FileHelper::saveString(toSave, filename + ".log");
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
 * @param VAO
 * @param VBO
 */
void Renderer::initBuffers(GLuint* VAO, GLuint* VBO){

  // Empty data to init
  float vertices[] = {
      0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
      0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
      0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f
  };



  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glGenBuffers(*this->maxObjects, VBO);
  glGenVertexArrays(*this->maxObjects, VAO);



  // Bind a VBO to each VAO.
  for (int i = 0; i < *maxObjects; i++){

    glBindVertexArray(VAO[i]);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[i]);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), nullptr);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3*sizeof(float)));

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);

    //Enable vertex attribs
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(3);
  }

  // Unbind vertex array and buffer
  glBindVertexArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
}

/**
 *
 */
void Renderer::initShaders(){
  this->shaderProgram = glCreateProgram();

  // Loading and compiling vertex shader (then logging)
  GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);

  string vertex_src = loadShader("VertexShader.vsh");
  const char* vertex_src_c = vertex_src.c_str();

  glShaderSource(vertexShader, 1, &vertex_src_c, nullptr);
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
  string fragment_src = loadShader("FragmentShader.fsh");
  const char* fragment_src_c = fragment_src.c_str();


  glShaderSource(fragmentShader, 1, &fragment_src_c, nullptr);
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
}

/**
 *
 */
void Renderer::initGL(){
  glfwInit();
}

/**
 *
 * Built on GLFW example docs (https://www.glfw.org/docs/latest/window_guide.html)
 * Internal method, instantiates an OpenGL window.
 * @returns status code, indicating success of window instantiation.
 */
int Renderer::initWindow() {
  /* Create a windowed mode window and its OpenGL context */
  window = glfwCreateWindow(400, 400, "Divide and Concur", nullptr, nullptr);

  if (!window) {
    *this->isTerminating = true;
    glfwTerminate();
    return -1;
  }

  /* Make the window's context current */
  glfwMakeContextCurrent(this->window);


  if (!gladLoadGL()) {
    printf("Something went wrong!\n");
    exit(-1);
  }


  this->mouse->setMouseWindow(this->window);

  initShaders();

  // openGL settings
  glfwSwapInterval(1);
  glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

  return 0;
}


/**
 * Built on GLFW docs ( https://www.glfw.org/docs/latest/window_guide.html )
 * Internal method, The main render loop of the application.
 * Continues until the window closes or the
 */
void Renderer::renderLoop() {


  // Init variables
  unsigned int VAO[*this->maxObjects];
  unsigned int VBO[*this->maxObjects];

  initBuffers(VAO, VBO);



  float buffer[] = {
      0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
      0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
      0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f
  };


  // Init shader program
  glUseProgram(this->shaderProgram);


  // Render loop
  while (!glfwWindowShouldClose(this->window) && !*this->isTerminating) {
    DoubleLinkedObject *currObject = this->objects;

    glClear(GL_COLOR_BUFFER_BIT);
    
    int x = 0;
    while(currObject != nullptr && x < sizeof(VAO)){
      currObject->object->generateVertices(buffer, this->xViewportSizePx, this->yViewportSizePx);


      glBindVertexArray(VAO[x]);
      glBindBuffer(GL_ARRAY_BUFFER, VBO[x]);

      glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(buffer), buffer);
      glDrawArrays(GL_TRIANGLES, 0, 6);

      x += 1;
      currObject = currObject->nextObject;
    }

    /* Swap front and back buffers */
    glfwSwapBuffers(window);
    glfwPollEvents();
    glfwGetWindowSize(this->window, &this->xViewportSizePx, &this->yViewportSizePx);
    glViewport(0, 0, this->xViewportSizePx, this->yViewportSizePx);
    mouse->updateMouseState(&this->xViewportSizePx, &this->yViewportSizePx);
  }

  *this->isTerminating = true;
  glfwDestroyWindow(this->window);
}