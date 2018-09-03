#include "mapScene.h"
#include <qvector.h>
#include <qalgorithms.h>

MapScene::MapScene(const QVector<Node> &Nodes, QWidget *parent)
	: QGraphicsScene(parent)
{
	setSceneRect(0, 0, 1200, 898);
	for (int i = 0; i < Nodes.size(); i++) {
		// 路线
		for (int j = 0; j < Nodes[i].links.size(); j++) {
			if (Nodes[i].links[j].flag != 0) {
				Route *route = new Route(Nodes[i].links[j], Nodes[i].links[j].line.color);
				addItem(route);
			}
		}
		// 站点
		Station *station = new Station(Nodes[i]);
		addItem(station);
		// 站名
		Lable *lable = new Lable(Nodes[i]);
		addItem(lable);
	}
}

MapScene::MapScene(QWidget *parent)
	: QGraphicsScene(parent)
{
	// 设置一个空画布
	setSceneRect(0, 0, 1200, 898);
}
