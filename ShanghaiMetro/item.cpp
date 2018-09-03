#include "item.h"
#include <qpoint.h>

Station::Station(const Node& n) : Node(n)
{
	// Ä¬ÈÏstation
	color = Qt::black;
	style = Qt::SolidLine;
	cap = Qt::FlatCap;
	join = Qt::RoundJoin;
	penWidth = 3;
	width = 8;
	height = 8;
}


QRectF Station::boundingRect() const
{
	return QRectF(0, 0, width, height);
}

void Station::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
	QWidget *widget)
{
	painter->translate(X0, Y0);
	painter->setPen(QPen(color, penWidth, style, cap, join));
	painter->drawRoundRect(posx * Radio, posy * Radio, width, height, 99, 99);
}

Route::Route(const Link &n, QColor c) : Link(n)
{
	color = c;
	style = Qt::SolidLine;
	cap = Qt::FlatCap;
	join = Qt::BevelJoin;
	penWidth = 6;
	fx = n.from->posx * Radio;
	fy = n.from->posy * Radio;
	tx = n.to->posx * Radio;
	ty = n.to->posy * Radio;
	width = abs(fx - tx);
	height = abs(fy - ty);
}


QRectF Route::boundingRect() const
{
	return QRectF(0, 0, width, height);
}

void Route::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
	QWidget *widget)
{
	painter->translate(X0, Y0);
	painter->setPen(QPen(color, penWidth, style, cap, join));
	if(flag == -1)
		painter->drawLine(QPoint(fx + !!(fy - ty) * Offset, fy + !!(fx - tx)* Offset),
			QPoint(tx + !!(fy - ty) * Offset, ty + !!(fx - tx)* Offset));
	else
		painter->drawLine(QPoint(fx, fy), QPoint(tx, ty));
}

Lable::Lable(const Node &n) : Node(n)
{
	// Ä¬ÈÏstation
	color = Qt::black;
	style = Qt::SolidLine;
	cap = Qt::FlatCap;
	join = Qt::RoundJoin;
	font = QFont("Microsoft YaHei");
	//font.setPixelSize(1);
	QFontMetricsF fontMetrics(font);
	width = fontMetrics.width(name);
	height = fontMetrics.height();
	penWidth = 1;
}


QRectF Lable::boundingRect() const
{
	return QRectF(0, 0, width, height);
}

void Lable::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
	QWidget *widget)
{
	painter->translate(X0, Y0);
	painter->setPen(QPen(color, penWidth, style, cap, join));
	//painter->rotate(-30);
	painter->drawText(QPoint(posx * Radio, posy * Radio), name);
}

