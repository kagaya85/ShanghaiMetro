#include "mapView.h"

MapView::MapView(QWidget *parent) : QGraphicsView(parent)
{
	// 设置不显示滚动条
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	// 设置窗口关闭后自动释放内存
	setAttribute(Qt::WA_DeleteOnClose); 
}

void MapView::mousePressEvent(QMouseEvent * event)
{
	if (event->button() == Qt::LeftButton) {
		NewStation *newSta = new NewStation;
		if (newSta->exec() == QDialog::Accepted) {
			/*pos已转换为scene坐标*/
			emit addNewStation(newSta->returnText(), mapToScene(event->pos()).toPoint());
		}
		delete newSta;
	}
	else {
		QGraphicsView::mousePressEvent(event);
	}
}
