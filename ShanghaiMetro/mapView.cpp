#include "mapView.h"

MapView::MapView(QWidget *parent) : QGraphicsView(parent)
{
	setAttribute(Qt::WA_DeleteOnClose); // ���ô��ڹرպ��Զ��ͷ��ڴ�
}

void MapView::mousePressEvent(QMouseEvent * event)
{
	if (event->button() == Qt::LeftButton) {
		NewStation *newSta = new NewStation;
		if (newSta->exec() == QDialog::Accepted) {
			/*pos��ת��Ϊscene����*/
			emit addNewStation(newSta->returnText(), mapToScene(event->pos()).toPoint());
		}
	}
	else {
		QGraphicsView::mousePressEvent(event);
	}
}
