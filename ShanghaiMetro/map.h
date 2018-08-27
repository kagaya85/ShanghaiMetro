#include <qlist.h>
#include <qqueue.h>
#include <qwidget.h>
#include <qvector.h>
#include <qfile.h>
#include "node.h"


class Map : public QWidget {
	Q_OBJECT

public:
	explicit Map(QWidget *parent = Q_NULLPTR);

private:
	QVector<Node> Nodes;
};