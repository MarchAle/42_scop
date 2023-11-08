#include "../incs/scop.hpp"

std::vector<std::string> split(std::string &line, char sep)
{
	std::string tmp = line;
	std::stringstream ss(line);
	std::vector<std::string> result;
	while (getline(ss, tmp, sep))
	{
		if (tmp.length())
			result.push_back(tmp);
	}
	return (result);
}

void    addVertice(std::vector<GLfloat> &vertices, std::vector<std::string> &vertice)
{
    if (vertice.size() != 4)
        error(VERTICE_ERROR);
    for (int i = 1; i < 4; i++)
        vertices.push_back(std::stof(vertice[i]) / 3);
}

void    addFace(std::vector<GLuint> &faces, std::vector<std::string> &face)
{
    if (face.size() == 4)
    {
        for (size_t i = 1; i < 4; i++)
            faces.push_back(std::stoi(face[i]));
    }
    else if (face.size() == 5)
    {
        faces.push_back(std::stoi(face[1]));
        faces.push_back(std::stoi(face[2]));
        faces.push_back(std::stoi(face[4]));
        faces.push_back(std::stoi(face[2]));
        faces.push_back(std::stoi(face[3]));
        faces.push_back(std::stoi(face[4]));
    }
    else
        error(FACE_ERROR);
    // if (face.size() != 4 && face.size() != 5)
    //     error(FACE_ERROR);
    // for (size_t i = 1; i < face.size(); i++)
    //     faces.push_back(std::stoi(face[i]));
}

void    parseFile(std::vector<GLfloat> &vertices, std::vector<GLuint> &faces, std::string filePath)
{
    std::string                 line;
    std::vector<std::string>    splitLine;
    std::ifstream file(filePath);
    if (!file)
        error(FILE_ERROR);
    while (std::getline(file, line))
    {
        splitLine = split(line, ' ');
        if (splitLine.size() < 1)
            continue;
        if (splitLine[0].compare("v") == 0)
            addVertice(vertices, splitLine);
        if (splitLine[0].compare("f") == 0)
            addFace(faces, splitLine);
    }
}

void render(std::vector<GLfloat> &vertices, std::vector<GLuint> &faces)
{
    // Clean the window, prepare buffer for drawing next frame
    glClear(GL_COLOR_BUFFER_BIT);
    // Tells OpenGL which VAO to use for the upcoming rendering operations
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), vertices.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, faces.size() * sizeof(GLuint), faces.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);
    glEnableVertexAttribArray(0);
    // Specify color attribute
        //Buffer for color
    // glGenBuffers(1, &VBO_colors);
    // glBindBuffer(GL_ARRAY_BUFFER, VBO_colors);
    // glEnableVertexAttribArray(1);

    // glBufferData(GL_ARRAY_BUFFER, (colors.size())*sizeof(float), colors.data(), GL_STATIC_DRAW);
    // glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0); //size = 3 (R,G,B)

    // GLuint colorLocation = 1;  // Location of the color attribute in the vertex shader
    // glVertexAttribPointer(colorLocation, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)(particules.size() * 8 * sizeof(GLfloat)));
    // glEnableVertexAttribArray(1);
    glDrawElements(GL_TRIANGLES, faces.size(), GL_UNSIGNED_INT, 0);
    glfwSwapBuffers(window);
}

int main(int ac, char const *av[])
{
    std::vector<GLfloat>    vertices;
    std::vector<GLuint>     faces;

    if (ac < 2)
        error(NB_ARG);

    parseFile(vertices, faces, av[1]);

    if (initLibraries() == 1)
        return (1);
    setUpOpenGl();
    glfwSetWindowUserPointer(window, &vertices);
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        render(vertices, faces);
        // glClear(GL_COLOR_BUFFER_BIT);
        // glfwSwapBuffers(window);

    }
    cleanUp();
    (void)av;
    return (0);
}
