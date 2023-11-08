#ifndef SCOP_HPP
# define SCOP_HPP

# include <iostream>
# include <GL/glew.h>
# include <GLFW/glfw3.h>
# include <vector>
# include <string>
# include <iostream>
# include <fstream>
# include <sstream>
# include <cerrno>
# include <math.h>

#define WIN_WIDTH 800
#define WIN_HEIGHT 600

#define NB_ARG 0
#define FILE_ERROR 1
#define VERTICE_ERROR 2
#define FACE_ERROR 3

extern GLFWwindow*      window;
extern GLuint           VBO, VAO, EBO, VBO_colors;

int     initLibraries();
void    setUpOpenGl();
void    cleanUp();

void    error(int errorType);

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);


#endif