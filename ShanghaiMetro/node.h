#pragma once
#include <qstring.h>
#include <qlist.h>
#include <link.h>
#include <qpoint.h>

// 对读入的坐标进行修正
#define OFFSET_X 80
#define OFFSET_Y 10

class Node {
public:
	QString name;
	int posx;
	int posy;
	QList<Link> links;
	int cost; // 到目标所需花费，寻路时用

	Node(QString n = QString::null);
	Node(const Node &n);
	Node(QString n, QPoint pos);
	Node(QStringList strList);
	void set_node(QStringList strList);
	bool operator==(const Node b) const;
};
