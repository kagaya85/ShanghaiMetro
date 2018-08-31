#include "mapView.h"

MapView::MapView(QWidget *parent) : QGraphicsView(parent)
{
	;
}

void MapView::mousePressEvent(QMouseEvent * event)
{
	if (event->button() == Qt::LeftButton) {
		NewStation *newStation = new NewStation;
		newStation->show();
	}
	else {
		QGraphicsView::mousePressEvent(event);
	}
}
