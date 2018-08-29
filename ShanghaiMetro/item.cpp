#include "item.h"
#include <qpoint.h>

Station::Station()
{
	color = Qt::black;
	style = Qt::SolidLine;
	cap = Qt::FlatCap;
	join = Qt::RoundJoin;
}

Station::Station(const Node &n) : Node(n)
{
	color = Qt::black;
	style = Qt::SolidLine;
	cap = Qt::FlatCap;
	join = Qt::RoundJoin;
}

QRectF Station::boundingRect() const
{
	return QRectF(0, 0, NodeWidth, NodeHeight);
}

void Station::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
	QWidget *widget)
{
	painter->translate(X0, Y0);
	painter->setPen(QPen(color, penWidth, style, cap, join));
	painter->drawRoundRect(posx * Radio, posy * Radio, NodeWidth, NodeHeight, 99, 99);
}