#pragma once
#include <qstring.h>
#include <qlist.h>
#include <link.h>
#include <qpoint.h>

class Node {
public:
	QString name;
	int posx;
	int posy;
	QList<Link> links;

	Node(QString n = QString::null);
	Node(const Node &n);
	Node(QString n, QPoint pos);
	Node(QStringList strList);
	void set_node(QStringList strList);
	bool operator==(const Node b);
};
