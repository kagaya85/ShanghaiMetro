#include <ShanghaiMetro.h>
#include <qfile.h>
#include <qdebug.h>
#include "myDialog.h"

ShanghaiMetro::ShanghaiMetro(QWidget *parent)
	: QMainWindow(parent) 
{	
	ui.setupUi(this);
	setWindowTitle("ShanghaiMetro ver:1.0.0");
	//setAttribute(Qt::WA_DeleteOnClose); // 设置窗口关闭后自动释放内存 会报错
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

	// 添加链接
	for (int i = 0; i < Nodes.size(); i++) {
		for (int j = 0; j < Nodes[i].links.size(); j++) {
			Nodes[i].links[j].from = &Nodes[i];
			Nodes[i].links[j].to = findNode(Nodes[i].links[j].toName);
		}
	}

	connect(ui.map, &MapView::addNewStation, this, &ShanghaiMetro::addNode);
	connect(ui.addLink, &QPushButton::clicked, this, &ShanghaiMetro::addLinkDialog);

	mapScene = new MapScene(Nodes);
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

void ShanghaiMetro::addNode(QString n, QPoint pos)
{
	if (n == QString::null)
		return;
	/*pos为scene坐标*/
	int realx = (pos.x() - X0) / Radio;
	int realy = (pos.y() - X0) / Radio;
	Node newNode(n, QPoint(realx, realy));
	Nodes.append(newNode);

	delete mapScene;
	mapScene = new MapScene(Nodes);
	ui.map->setScene(mapScene);

	return;
}

void ShanghaiMetro::addLinkDialog()
{
	AddLink* addLink = new AddLink();
	connect(addLink, &AddLink::addNewLink, this, &ShanghaiMetro::addLink);
	if (addLink->exec() == QDialog::Accepted) {
		emit addLink->addNewLink(addLink->returnStaFrom(), addLink->returnStaTo(), addLink->returnLineNum());
	}
	disconnect(addLink, &AddLink::addNewLink, this, &ShanghaiMetro::addLink);
}

void ShanghaiMetro::addLink(QString StaFrom, QString StaTo, int lineNum)
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
