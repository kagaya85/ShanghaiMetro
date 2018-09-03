#include "mapScene.h"
#include <qvector.h>
#include <qalgorithms.h>

MapScene::MapScene(const QVector<Node> &Nodes, QWidget *parent)
	: QGraphicsScene(parent)
{
	setSceneRect(0, 0, 1200, 898);
	for (int i = 0; i < Nodes.size(); i++) {
		// ·��
		for (int j = 0; j < Nodes[i].links.size(); j++) {
			if (Nodes[i].links[j].flag != 0) {
				Route *route = new Route(Nodes[i].links[j], Nodes[i].links[j].line.color);
				addItem(route);
			}
		}
		// վ��
		Station *station = new Station(Nodes[i]);
		addItem(station);
		// վ��
		Lable *lable = new Lable(Nodes[i]);
		addItem(lable);
	}
}

MapScene::MapScene(QWidget *parent)
	: QGraphicsScene(parent)
{
	// ����һ���ջ���
	setSceneRect(0, 0, 1200, 898);
}
