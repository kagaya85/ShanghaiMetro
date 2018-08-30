#pragma once
#include <qstring.h>
#include <line.h>
//#include <node.h>

class Node;

class Link {
public:
	Node* to;
	Node* from;
	QString toName;
	Line line;
	int flag;
	int weight;

	Link() { ; };
	Link(const Link &l);
	Link(QStringList strList);
	void set_link(QStringList strList);
};