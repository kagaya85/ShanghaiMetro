#pragma once
#include <qgraphicsitem.h>
#include <qpainter.h>
#include "node.h"
#include "link.h"

#define Radio 0.6	// 站点位置缩放
//#define X0 -460		// translate坐标
//#define Y0 -380
#define X0 0
#define Y0 0
#define Offset 4

//class Item : public QGraphicsItem, public Node {
//public:	
//	Item(const Node &n);
//	Item(const Node &n, QColor c, Qt::PenStyle s, Qt::PenCapStyle ca,
//		Qt::PenJoinStyle j, int penw, int type);
//	QRectF boundingRect() const;
//	void setColor(const QColor &c) { color = c; };
//	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
//		QWidget *widget);
//private:
//	QColor color;
//	Qt::PenStyle style;
//	Qt::PenCapStyle cap;
//	Qt::PenJoinStyle join;
//	int penWidth;
//	int width;
//	int height;
//	int drawType;
//};

class Station : public QGraphicsItem, public Node {
public:
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
	int penWidth;
	int width;
	int height;
};

class Route : public QGraphicsItem, public Link {
public:
	Route(const Link &n, QColor c = Qt::black);
	QRectF boundingRect() const;
	void setColor(const QColor &c) { color = c; };
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
		QWidget *widget);
private:
	int fx, fy, tx, ty;
	QColor color;
	Qt::PenStyle style;
	Qt::PenCapStyle cap;
	Qt::PenJoinStyle join;
	int penWidth;
	qreal width;
	qreal height;
};

class Lable : public QGraphicsItem, public Node {
public:
	Lable(const Node &n);
	QRectF boundingRect() const;
	void setColor(const QColor &c) { color = c; };
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
		QWidget *widget);
private:
	QColor color;
	Qt::PenStyle style;
	Qt::PenCapStyle cap;
	Qt::PenJoinStyle join;
	QFont font;
	int penWidth;
	int width;
	int height;
};