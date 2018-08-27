#include "ShanghaiMetro.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ShanghaiMetro w;
	w.show();
	return a.exec();
}

