# include "../incs/scop.hpp"

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    std::vector<GLfloat> *vertices = static_cast<std::vector<GLfloat> *>(glfwGetWindowUserPointer(window));

    // std::cout << key << std::endl;
    if (action == GLFW_PRESS)
    {
        switch (key)
        {
            case 262: // - x
                for (int i = 0; i < static_cast<int>((*vertices).size()); i += 3)
                    (*vertices)[i] += 0.07;
                break;
            case 263: // + x
                for (int i = 0; i < static_cast<int>((*vertices).size()); i += 3)
                    (*vertices)[i] -= 0.07;
                break;
            case 264: // + y
                for (int i = 1; i < static_cast<int>((*vertices).size()); i += 3)
                    (*vertices)[i] -= 0.07;
                break;
            case 265: // - y
                for (int i = 1; i < static_cast<int>((*vertices).size()); i += 3)
                    (*vertices)[i] += 0.07;
                break;
            case 331: // /
                for (int i = 0; i < static_cast<int>((*vertices).size()); i += 3)
                {
                    float x = (*vertices)[i];
                    float z = (*vertices)[i + 2];
                    (*vertices)[i] = cos(0.2) * x + sin(0.2) * z;
                    (*vertices)[i + 2] = -sin(0.2) * x + cos(0.2) * z;
                }
                    // (*vertices)[i] -= 0.01;
                break;
            case 332: // *
                for (int i = 0; i < static_cast<int>((*vertices).size()); i += 3)
                {
                    float x = (*vertices)[i];
                    float z = (*vertices)[i + 2];
                    (*vertices)[i] = cos(-0.2) * x + sin(-0.2) * z;
                    (*vertices)[i + 2] = -sin(-0.2) * x + cos(-0.2) * z;
                }
                break;
            case 333: // -
                for (int i = 0; i < static_cast<int>((*vertices).size()); i++)
                    (*vertices)[i] /= 1.05;
                break;
            case 334: // +
                for (int i = 0; i < static_cast<int>((*vertices).size()); i++)
                    (*vertices)[i] *= 1.05;
                break;
            
            default:
                break;
        }
    }
    (void)window;
    (void)mods;
    (void)scancode;
}