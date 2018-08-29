#pragma once
#include <qcolor.h>

class Line {
public:
	int num;
	QColor color;
	Line();
	Line(int n);
	int get_num() { return num; };
};