#pragma once

#include <QOpenGLWidget>
#include <QOpenGLExtraFunctions>


class GLMain : public QOpenGLWidget, protected QOpenGLExtraFunctions{
	Q_OBJECT
public:
	GLMain(QWidget *parent = NULL);
	~GLMain();
protected:
	void initializeGL();
	void resizeGL(int w, int h);
	void paintGL();
private: 
	unsigned int shaderProgram;
	unsigned int VAO;
};

