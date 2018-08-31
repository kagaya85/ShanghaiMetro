#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_ShanghaiMetro.h"
#include "node.h"
#include <qstack.h>
#include <qstring.h>

class ShanghaiMetro : public QMainWindow {
	Q_OBJECT

public:
	ShanghaiMetro(QWidget *parent = Q_NULLPTR);
	Node* findNode(QString name);
	QStack<Node> findShortestPath(Node start, Node end);
	QStack<Node> findDirectPath(Node start, Node end);
	QStack<Node> findOneTransferPath(Node start, Node end);
	void addNode(QString n, int x, int y);
	void testShow();
private:
	Ui::ShanghaiMetroClass ui;
	QVector<Node> Nodes;
	QStack<Node> Paths;
};
