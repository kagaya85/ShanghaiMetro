#include "node.h"

Node::Node(QString n) {
	name = n;
	posx = 0;
	posy = 0;
}

Node::Node(const Node &n) {
	name = n.name;
	posx = n.posx;
	posy = n.posy;
	links = n.links;
}

Node::Node(QString n, QPoint pos) {
	name = n;
	posx = pos.x();
	posy = pos.y();
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
	links.clear();
}

bool Node::operator==(const Node b) {
	if (name == b.name)
		return true;
	else
		return false;
}