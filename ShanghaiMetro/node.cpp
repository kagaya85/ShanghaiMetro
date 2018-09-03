#include "node.h"

Node::Node(QString n) {
	name = n;
	posx = 0;
	posy = 0;
	pathFrom = NULL;
}

Node::Node(const Node &n) {
	name = n.name;
	posx = n.posx;
	posy = n.posy;
	links = n.links;
	costF = n.costF;
	costT = n.costT;
	pathFrom = NULL;
}

Node::Node(QString n, QPoint pos) {
	name = n;
	posx = pos.x();
	posy = pos.y();
	pathFrom = NULL;
}

Node::Node(QStringList strList) {
	name = strList[0];
	posx = strList[1].toInt();
	posy = strList[2].toInt();
	pathFrom = NULL;
}

/*读入坐标时的set函数，包含坐标修正*/
void Node::set_node(QStringList strList) {
	name = strList[0];
	posx = strList[1].toInt() + OFFSET_X;
	posy = strList[2].toInt() + OFFSET_X;
	pathFrom = NULL;
	links.clear();
}

bool Node::operator==(const Node& b) const {
	if (name == b.name)
		return true;
	else
		return false;
}

///*搜索路径优先队列比较用*/
//bool Node::operator<(const Node& x) const {
//	return costF + costT > x.costF + x.costT;
//}