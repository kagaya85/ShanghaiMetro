#include "link.h"

Link::Link(const Link &l) {
	toName = l.toName;
	line = l.line;
	flag = l.flag;
	weight = 1;
	to = l.to;
	from = l.from;
}

Link::Link(QStringList strList) {
	toName = strList[0];
	line = Line(strList[1].toInt());
	flag = strList[2].toInt();
	weight = 1;
	to = NULL;
	from = NULL;
}

void Link::set_link(QStringList strList) {
	toName = strList[0];
	line = Line(strList[1].toInt());
	flag = strList[2].toInt();
	weight = 1;
	from = NULL;
}