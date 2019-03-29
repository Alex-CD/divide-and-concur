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
 * Constructor for the renderer object.
 * @param isTerminating Pointer to the boolean indicating if this component should gracefully terminate.
 * @param maxObjects Max objects that can be rendered by this component. (also how much VRAM should be allocated)
 * @param objects Pointer to the list of objects to be rendered by the rendering loop.
 * @param mouse Pointer to the mouse object, so that the viewbox size can be passed.
 */
Renderer::Renderer(bool *isTerminating, int *maxObjects, DoubleLinkedObject *objects, Mouse *mouse, string windowName) {
  this->isTerminating = isTerminating;
  this->maxObjects = maxObjects;
  this->objects = objects;
  this->mouse = mouse;

  this->windowText = windowName;

  this->xViewportSizePx = 400;
  this->yViewportSizePx = 400;
}


/**
 * Static method, to which new threads in an outer scope should be directed.
 * This directs threads onto a core object on which to run.
 * @param The object on which this thread should run.
 */
void *Renderer::threadEntry(void *param){
  auto thisRenderer = (Renderer *)param;
  thisRenderer->start();
  return nullptr;
}


/**
 * First method run by new threads in this component.
 * This thread takes control from here.
 * Coordinate high level logic here!
 */
void Renderer::start(){
  initWindow();
  initGL();
  renderLoop();
}

/**
 * Stops the cursor from being rendered over this game's window.
 */
void Renderer::hideCursor(){
  glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
}

/**
 * Makes the cursor be rendered over this game's window.
 */
void Renderer::showCursor(){
  glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
}

/**
 * Saves a log to a file.
 * @param toSave String to save to a file
 * @param filename  Filename of the file in which the log will be saved.
 */
void Renderer::saveLog(char *toSave, string filename){
  FileHelper::saveString(toSave, filename + ".log");
};

/**
 * Loads a shader file from the disk.
 * @param sourceFile Name of the shader file to be loaded (including extension).
 * @return
 */
string Renderer::loadShader(string sourceFile){
  return FileHelper::loadString("shaders/" + sourceFile);
};

/**
 * Initialises the given VBO's and VAO's.
 * Logic relating to data layout in the buffers in contained here.
 * @param VAO Vertex array object to initialise.
 * @param VBO Vertex buffer object to initialise.
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
  }

  // Unbind vertex array and buffer
  glBindVertexArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
}

/**
 * Loads, compiles and attaches the shaders used by this game.
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
 * Initialises openGL.
 * SHOULD BE CALLED ONCE PER PROCESS (regardless of how many threads).
 */
void Renderer::initGL(){
  glfwInit();
}

/**
 * Initialises the window and viewbox used by this game.
 * Built on GLFW example docs (https://www.glfw.org/docs/latest/window_guide.html)
 * Internal method, instantiates an OpenGL window.
 * @returns status code, indicating success of window instantiation.
 */
int Renderer::initWindow() {
  /* Create a windowed mode window and its OpenGL context */
  window = glfwCreateWindow(400, 400, "Divide and Concur", nullptr, nullptr);

  glfwSetWindowTitle(window, windowText.c_str());
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
 * The render loop.
 * Continually renders the objects contained in the objects list,
 * using the initialised buffers.
 * Only terminates when the window is closed, or isTerminating is set to true.
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