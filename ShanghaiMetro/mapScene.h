#pragma once
#include <qgraphicsscene.h>
#include <qlist.h>
#include <qqueue.h>
#include <qwidget.h>
#include <qvector.h>
#include "item.h"

class MapScene : public QGraphicsScene {
	Q_OBJECT

public:
	MapScene(const QVector<Node> &, QWidget *parent = Q_NULLPTR);

private:
	QVector<Station> stations;
};