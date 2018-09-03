#pragma once
#include <qstring.h>
#include <qlist.h>
#include <link.h>
#include <qpoint.h>

// �Զ���������������
#define OFFSET_X 80
#define OFFSET_Y 10

class Node {
public:
	QString name;
	int posx;
	int posy;
	QList<Link> links;

	int costT; // ��Ŀ�����軨�ѣ�Ѱ·ʱ��
	int costF;	// �����Ļ��ѣ�Ѱ·ʱ��
	Node* pathFrom; // ����·��

	Node(QString n = QString::null);
	Node(const Node &n);
	Node(QString n, QPoint pos);
	Node(QStringList strList);
	void set_node(QStringList strList);
	bool operator==(const Node& b) const;
	///*����·�����ȶ��бȽ���*/
	//bool operator<(const Node& x) const;	
};
