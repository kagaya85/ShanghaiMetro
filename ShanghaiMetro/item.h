#pragma once
#include <qgraphicsitem.h>
#include <qpainter.h>
#include "node.h"

#define NodeWidth 8
#define NodeHeight 8
#define Radio 0.5	// ’æµ„Œª÷√Àı∑≈
#define X0 -400
#define Y0 -360

class Station : public QGraphicsItem, public Node {
public:	
	Station();
	Station(const Node &n);
	QRectF boundingRect() const;
	void setColor(const QColor &c) { color = c; };
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
		QWidget *widget);
private:
	QColor color;
	Qt::PenStyle style;
	Qt::PenCapStyle cap;
	Qt::PenJoinStyle join;
	const static int penWidth = 3;
};

class Route : public QGraphicsItem {
public:

};