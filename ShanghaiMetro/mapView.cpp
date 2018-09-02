#include "mapView.h"

MapView::MapView(QWidget *parent) : QGraphicsView(parent)
{
	// ���ò���ʾ������
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	// ���ô��ڹرպ��Զ��ͷ��ڴ�
	setAttribute(Qt::WA_DeleteOnClose); 
}

void MapView::mousePressEvent(QMouseEvent * event)
{
	if (event->button() == Qt::LeftButton) {
		NewStation *newSta = new NewStation;
		if (newSta->exec() == QDialog::Accepted) {
			/*pos��ת��Ϊscene����*/
			emit addNewStation(newSta->returnText(), mapToScene(event->pos()).toPoint());
		}
		delete newSta;
	}
	else {
		QGraphicsView::mousePressEvent(event);
	}
}
