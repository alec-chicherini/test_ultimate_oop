#include <QApplication>
#include "oop.h"
int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	oop widget;
	widget.show();
	return app.exec();
}