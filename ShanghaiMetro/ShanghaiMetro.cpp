#include "ShanghaiMetro.h"
#include <qfile.h>
#include <qdebug.h>

ShanghaiMetro::ShanghaiMetro(QWidget *parent)
	: QMainWindow(parent) 
{	
	ui.setupUi(this);
	ShanghaiMetro::setWindowTitle("ShanghaiMetro ver:1.0.0");

	QFile fp("info.txt");
	if (!fp.open(QIODevice::ReadOnly | QIODevice::Text))
		qDebug() << "open file error" << endl;

	QString str;
	QStringList strList;

	while (!fp.atEnd()) {
		Node tempNode;
		Link tempLink;

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

}

Node ShanghaiMetro::findNode(QString name) {
	for (int i = 0; i < Nodes.size(); i++) {
		if (Nodes[i].name == name)
			return Nodes[i];
	}

	return Node(); // null
}

void ShanghaiMetro::paintEvent(QPaintEvent *) {
	QPainter painter(this);
	QPen pen;
}
