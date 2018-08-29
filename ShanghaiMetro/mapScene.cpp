#include "mapScene.h"

MapScene::MapScene(const QVector<Node> &Nodes, QWidget *parent)
	: QGraphicsScene(parent)
{
	// Õ¾µã
	for (int i = 0; i < Nodes.size(); i++) {
		Station *sta = new Station(Nodes[i]);
		addItem(sta);
	}
	// Â·Ïß


}


