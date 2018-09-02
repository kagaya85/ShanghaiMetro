#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_ShanghaiMetro.h"
#include "node.h"
#include <qstack.h>
#include <qstring.h>
#include "mapScene.h"

class ShanghaiMetro : public QMainWindow {
	Q_OBJECT

public:
	ShanghaiMetro(QWidget *parent = Q_NULLPTR);
	Node* findNode(QString name);
	QStack<Node> findShortestPath(Node start, Node end);
	QStack<Node> findDirectPath(Node start, Node end);
	QStack<Node> findOneTransferPath(Node start, Node end);
	void testShow();

public slots:
	void addNode(QString n, QPoint pos);
	void addLinkDialog();

private:
	Ui::ShanghaiMetroClass ui;
	QVector<Node> Nodes;
	QStack<Node> Paths;
	MapScene* mapScene;
};
