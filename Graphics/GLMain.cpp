#include "GLMain.h"

#include<iostream>

GLMain::GLMain(QWidget *parent)
{
}

GLMain::~GLMain()
{
}

void GLMain::initializeGL()
{
	// Required for classes extendeing QOpenGL(Extra)Functions
	initializeOpenGLFunctions();
	// Sets the color that the entire OpenGL window is set to
	glClearColor(0.97f, 0.69f, 0.58f, 1.0f);
	//vertices of a triangle~
	float vertices[] = {
	-0.5f, -0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	 0.0f,  0.5f, 0.0f
	};
	// "ID" of a Vertex Buffer Object 
	
	glGenVertexArrays(1, &VAO);
	//VAO's allow you to bind the vertex attributes once rather than on every draw call
	glBindVertexArray(VAO);	// This function is the main reason we use QOpenGLExtraFunctions

	unsigned int  VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	// This attribute will store the positions of our vertices
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)NULL);
	glEnableVertexAttribArray(0);
	// Currently written as a C string but we'll eventually load files instead
	const char *vertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = vec4(aPos, 1.0);\n"
		"}\0";
	const char *fragmentShaderSource = "#version 330 core\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
		"   FragColor = vec4(0.42f, 0.36f, 0.48f, 1.0f);\n"
		"}\n\0";

	//Create and compile shaders
	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
	//Attach shaders to the program and link
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	//Once the shaders are part of the program they don't need to exist anymore so bye bye shaders 
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	//I just feel happy and safe seeing the version pop up idk why ~
	std::cout << glGetString(GL_VERSION) << std::endl;
}

void GLMain::resizeGL(int w, int h)
{
}

void GLMain::paintGL()
{
	// Sets the window's color to the color set in glClearColor
	glClear(GL_COLOR_BUFFER_BIT);
	// Tells OpenGL which shader program to use for the subsequent draw calls
	glUseProgram(shaderProgram);
	// Binds the VAO of our cute lil triangle making it ready to draw!
	glBindVertexArray(VAO);
	//Draw triangles, how many vertices am i going to use?? Only one triangle so 3 I think...
	glDrawArrays(GL_TRIANGLES,0,3);
}
