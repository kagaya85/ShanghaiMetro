#include "link.h"

Link::Link() {
	;
}

Link::Link(QStringList strList) {
	to = strList[0];
	line = Line(strList[1].toInt());
	flag = strList[2].toInt();
	weight = 1;
}

void Link::set_link(QStringList strList) {
	to = strList[0];
	line = Line(strList[1].toInt());
	flag = strList[2].toInt();
	weight = 1;
}