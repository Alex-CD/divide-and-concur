# Divide and Concur

![DaC screenshot](docs/images/readme_splash.gif)


### What is is

A basic multithreading game engine, with collection of simple demonstration games.

This was my first foray into low-level graphics programming, and was the product of the dissertation for my Software Engineering BSc.

### What is does

Runs multiple different games at once (under the same process), with each game being run by several of its own threads, concurrently handling game logic and rendering.

It's a simple framework for games, providing utility for object creation, and automatically handling window creation and rendering.

Ideally, it functions as an example of how to handle multithreading with GLFW, if somewhat bloated!

### What it's built with

Written in: [C++](https://isocpp.org/), [GLSL](https://www.khronos.org/opengl/wiki/OpenGL_Shading_Language)

Uses: [OpenGL](https://www.opengl.org/),
[GLFW](https://www.glfw.org/),
[GLAD](https://glad.dav1d.de/),
[GLM](https://glm.g-truc.net/0.9.9/index.html),
[Doxygen](https://glm.g-truc.net/0.9.9/index.html)


## Getting started

### Generating Docs

This project is fully documented with Javadoc-style comments.

To generate documentation, run:

```
cd [project root]
doxygen Doxyfile
```
doxygen will then spit out HTML and LaTeX documentation in docs/ .

### Installing dependencies

By the end of this section, your source folder should look something like this


```
docs
include/
  glad/
  GLFW/
  gml/
  KHR/
src/
tests/
...
```
##### OpenGL:

Depending on what drivers are installed, you should already have this installed.
For a full list of packages that contain this, run

```
apt-file search libGL.so
```

Virtualbox additions definitely has this dependency, so if you really can't get this to work, try compiling it in a virtualbox dev environment.


##### X11dev tools

You'll need the x11 window manager dev tools to build this.

```
sudo apt-get install x11-dev
```


##### GLFW (v3.2.1 tested):

GLFW is the wrapper library for OpenGL, for things like window management.

If you're on Linux, you'll need to compile GLFW yourself as most package manager versions are out of date.
You'll need to download the [source files](https://www.glfw.org/download.html), then run:

```
cmake .
make install
```

this will place a compiled version of the library into your libs folder :)

There are pre-compiled versions of GLFW for windows available, though you'll have to modify some of the linux-specific dependencies in cmakelists to get it to compile.

##### GLM (v0.9.9.3):

An OpenGL maths utility used by the rendering module to calculate complicated stuff like perspective and field of view.

You'll have to get a copy from the [GLM site](https://glm.g-truc.net/0.9.9/index.html).



##### GLAD / KHR

Generate a version of the glad loader through their [web form](https://glad.dav1d.de/), and drop it into the includes directory.

### Compiling

You need to use cmake to build this project.
It should work with up to date versions of g++, gcc and make.


### Running

Compiling the project will spit out two executables, one is the program itself, one is a test suite.

## How to create a new game

1. Create a new folder inside src/Games
2. Create two new classes, inheriting from Core and GameLogic respectively.
3. Include boilerplate constructors (see Demo Game 1)
4. Import any required classes from renderables/
5. Write game logic code in GameLogic
6. Add game to launcher in Main.cpp

# License
