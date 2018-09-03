#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_ShanghaiMetro.h"
#include "node.h"
#include <qstack.h>
#include <qstring.h>
#include <qqueue.h>
#include "mapScene.h"

class ShanghaiMetro : public QMainWindow {
	Q_OBJECT

public:
	ShanghaiMetro(QWidget *parent = Q_NULLPTR);
	Node* findNode(QString name);
	QStack<Link> findShortestPath(Node* start, Node* end);
	//QStack<Node> findDirectPath(Node start, Node end);
	//QStack<Node> findOneTransferPath(Node start, Node end);
	void testShow();
	bool isInQueue(const QQueue<Node*> q, const Node* x);
	void searchPath(QString staFrom, QString staTo);

public slots:
	void addNode(QString n, QPoint pos);
	void addLink(QString staFrom, QString staTo, int lineNum);
	void addLinkDialog();
	void search();
	void clear();
private:
	Ui::ShanghaiMetroClass ui;
	QVector<Node> Nodes;
	QStack<Link> Path;	// »»³ËÂ·¾¶
	MapScene* mapScene;
	void initCost(Node* dest);
};
