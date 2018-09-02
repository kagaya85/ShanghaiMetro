#include "mapView.h"

MapView::MapView(QWidget *parent) : QGraphicsView(parent)
{
	setAttribute(Qt::WA_DeleteOnClose); // 设置窗口关闭后自动释放内存
}

void MapView::mousePressEvent(QMouseEvent * event)
{
	if (event->button() == Qt::LeftButton) {
		NewStation *newSta = new NewStation;
		if (newSta->exec() == QDialog::Accepted) {
			/*pos已转换为scene坐标*/
			emit addNewStation(newSta->returnText(), mapToScene(event->pos()).toPoint());
		}
	}
	else {
		QGraphicsView::mousePressEvent(event);
	}
}
