#include "GUIMain.h"

#include <QSurfaceFormat>

GUIMain::GUIMain(QWidget *parent)
{
	// This will be where all the OpenGL goodness goes down
	view3D = new GLMain();	
	// The surface is where the OpenGL rendering happens, and the format describes the behavior of the surface
	QSurfaceFormat format;
	// Yes
	format.setRenderableType(QSurfaceFormat::OpenGL);	
	// QSurfaceFomat::CoreProfile doesn't allow function calls that are below OpenGL version 3.0
	format.setProfile(QSurfaceFormat::CoreProfile);
	// Yes
	format.setVersion(4,6);
	view3D->setFormat(format);
	// QMainWindow has regions for several widgets, we'll use some of those later~
	setCentralWidget(view3D);
}


GUIMain::~GUIMain()
{
	/* 
		All Qt classes that are extended from QObject get deleted as long as they have valid parent objects.
		This automatic cleanup also happens for any classes you create that extend a Qt class.
		Don't assume this is true for other types of objects such as QString if you created it using the new keyword,
		which you shouldn't have but oh well...life??
	*/
	
}
