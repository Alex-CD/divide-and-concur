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


/**
 *
 * @param isTerminating
 */
Renderer::Renderer(bool *isTerminating, int *maxObjects) {
  this->isTerminating = isTerminating;
  this->maxObjects = maxObjects;
}

/**
 * For multithreading on this component, create a new thread on this method.
 * Calls start()
 */
void *Renderer::threadEntry(void *param){
  Renderer* thisRenderer = (Renderer *)param;
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
 * Callback for the GL resize window functions.
 * Can't be a member function because it would have to be static
 * (and wouldn't match the callback signature).
 * @param window The GLFW window to resize.
 * @param width The window width, in screen coords (not necessarily px).
 * @param heightThe window width, in screen coords (not necessarily px).
 */
void windowResizeCallback(GLFWwindow* window, int width, int height)
{
  glViewport(0, 0, width, height);
}


void Renderer::initBuffers(GLuint* VAO, GLuint* VBO){

  glGenBuffers(*this->maxObjects, VBO);
  glGenVertexArrays(*this->maxObjects, VAO);

  // Bind a VBO to each VAO.
  for (int object = 0; object < *maxObjects; object++){
    glBindVertexArray(VAO[object]);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[object]);

    // Attaching buffer to VBO.
    glEnableClientState(GL_ARRAY_BUFFER);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
    glEnableVertexAttribArray(VAO[object]);

    //Unbind array
    glBindVertexArray(0);
  }
}


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

  initShaders();

  // openGL settings
  glfwSwapInterval(1);
  glfwSetFramebufferSizeCallback(this->window, windowResizeCallback);
  glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

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
void Renderer::renderLoop() {
  GLuint VAO [*this->maxObjects];
  GLuint VBO [*this->maxObjects];

  initBuffers(VAO, VBO);

  // Contains all of the vertex buffer objects

  glUseProgram(this->shaderProgram);

  while (!glfwWindowShouldClose(this->window) && !*this->isTerminating) {
    glClear(GL_COLOR_BUFFER_BIT);

    updateBuffers(VAO);

    for(int i = 0; i < *maxObjects; i++) {
      glBindVertexArray(VAO[i]);
      //glBindBuffer(VAO[0])
      glDrawArrays(GL_TRIANGLES, 0, 4);
      glBindVertexArray(0);
    }

    /* Swap front and back buffers */
    glfwSwapBuffers(window);


    glfwPollEvents();


    // glfwWaitEvents();
    // Pauses program until input (useful for debug)

  }

  *this->isTerminating = true;
  glfwTerminate();
}


void Renderer::updateBuffers(GLuint* VAO){
  float vertices[] = {
      -1.0f, -1.0f, 1.0f,
      1.0f, 1.0f, 0.0f,
      -1.0f,  1.0f, 0.0f,
      -1.0f,  1.0f, 0.0f
  };

  for(int i = 0; i < *this->maxObjects; i++){
    glBindVertexArray(VAO[i]);
    // Rewrite entire buffer (without assigning new one (quick and dirty!).
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);
  }

  glBindVertexArray(0);
}