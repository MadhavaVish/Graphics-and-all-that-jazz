#pragma once

#include <QMainWindow>

#include "GLMain.h"

class GUIMain : public QMainWindow{
	Q_OBJECT
public:
	GUIMain(QWidget *parent = NULL);
	~GUIMain();

private:
	GLMain *view3D;
};

