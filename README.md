# Divide and Concur
A concurrency-base game environment, written in C++.

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

You'll have to get a 



##### GLAD / KHR

Generate a version of the glad loader through their [web form](https://glad.dav1d.de/), and drop it into the includes directory.

### Compiling

You need to use cmake to build this project.
It should work with up to date versions of g++, gcc and make.


### Running

Compiling the project will spit out two executables, one is the program itself, one is a test suite.

# License