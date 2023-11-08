#ifndef SHADERCLASS_HPP
# define SHADERCLASS_HPP

#include "../incs/scop.hpp"

std::string get_file_contents(const char *filename);

class shaderClass
{
    public:
        int     success;
        char    infoLog[512];
        GLuint  ID;
        shaderClass(const char *vertexFile, const char *fragmentFile);

        void Activate();
        void Delete();
};

#endif