#include "node.h"

Node::Node() {
	name = QString::null;
	posx = 0;
	posy = 0;
}

Node::Node(QStringList strList) {
	name = strList[0];
	posx = strList[1].toInt();
	posy = strList[2].toInt();
}

void Node::set_node(QStringList strList) {
	name = strList[0];
	posx = strList[1].toInt();
	posy = strList[2].toInt();
}

bool Node::operator==(const Node b) {
	if (name == b.name)
		return true;
	else
		return false;
}