
#include <QApplication>
#include <vld.h>
#include "GUIMain.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	GUIMain window;
	window.resize(1366, 728);
	window.show();
	return a.exec();
}
