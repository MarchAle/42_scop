#include "../incs/scop.hpp"

void    error(int errorType)
{
    std::cerr << "Error : ";
    switch (errorType)
    {
        case NB_ARG:
            std::cerr << "Please provide a model file" << std::endl;
            break;
        case FILE_ERROR:
            std::cerr << "Can't open model file" << std::endl;
            break;
        case VERTICE_ERROR:
            std::cerr << "Vertice must have 3 coordonate" << std::endl;
            break;
        case FACE_ERROR:
            std::cerr << "Face must have 3 or 4 vertices" << std::endl;
            break;
        
        default:
            break;
    }

    std::cerr << "Usage : \"./scop <model.obj>\"" << std::endl;
    exit (EXIT_FAILURE);
}