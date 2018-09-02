#pragma once
#include <qgraphicsview.h>
#include <qevent.h>
#include "myDialog.h"

class MapView : public QGraphicsView {
	Q_OBJECT
public:
	explicit MapView(QWidget *parent = 0);

protected:
	void mousePressEvent(QMouseEvent *event);
signals:
	void addNewStation(QString newStaName, QPoint newPos);
public slots:
};