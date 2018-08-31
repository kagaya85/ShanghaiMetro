#include <qfile.h>
#include <qdebug.h>
#include "ShanghaiMetro.h"
#include "mapScene.h"

ShanghaiMetro::ShanghaiMetro(QWidget *parent)
	: QMainWindow(parent) 
{	
	ui.setupUi(this);
	setWindowTitle("ShanghaiMetro ver:1.0.0");
	
	QFile fp("info.txt");

	if (!fp.open(QIODevice::ReadOnly | QIODevice::Text))
		qDebug() << "open file error" << endl;

	QString str;
	QStringList strList;
	Node tempNode;
	Link tempLink;

	while (!fp.atEnd()) {

		str = fp.readLine();
		strList = str.split(' ');

		if (strList.size() == 3) {
			tempNode.set_node(strList);
		}
		else if (strList.size() == 4) {
			tempLink.set_link(strList);
			tempNode.links.append(tempLink);
		}
		else if (str == "*****\n") {
			Nodes.append(tempNode);
		}

	}

	//testShow();

	// Ìí¼ÓÁ´½Ó
	for (int i = 0; i < Nodes.size(); i++) {
		for (int j = 0; j < Nodes[i].links.size(); j++) {
			Nodes[i].links[j].from = &Nodes[i];
			Nodes[i].links[j].to = findNode(Nodes[i].links[j].toName);
		}
	}


	MapScene *mapScene = new MapScene(Nodes);
	ui.map->setScene(mapScene);
}

Node* ShanghaiMetro::findNode(QString name) {
	for (int i = 0; i < Nodes.size(); i++) {
		if (Nodes[i].name == name)
			return &Nodes[i];
	}

 	return NULL; // null
}

QStack<Node> ShanghaiMetro::findShortestPath(Node start, Node end)
{
	return QStack<Node>();
}

QStack<Node> ShanghaiMetro::findDirectPath(Node start, Node end)
{
	return QStack<Node>();
}

QStack<Node> ShanghaiMetro::findOneTransferPath(Node start, Node end)
{
	return QStack<Node>();
}

void ShanghaiMetro::addNode(QString n, int x, int y)
{
}

void ShanghaiMetro::testShow()
{
	qDebug() << Nodes.size();

	for (int i = 0; i<Nodes.size(); i++)
	{
		qDebug() << Nodes[i].name << "  " << Nodes[i].posx << "  " << Nodes[i].posy;
		for (int j = 0; j<Nodes[i].links.size(); j++)
		{
			qDebug() << Nodes[i].links.size();
			qDebug() << Nodes[i].links[j].to << "  " <<
				Nodes[i].links[j].line.get_num() << "  " <<
				Nodes[i].links[j].flag;
		}

	}
}
