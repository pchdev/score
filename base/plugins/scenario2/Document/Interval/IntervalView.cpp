#include "IntervalView.hpp"
#include <QPainter>
#include <QGraphicsScene>
#include <QDebug>
IntervalView::IntervalView(QGraphicsObject* parent):
	QNamedGraphicsObject{parent, "IntervalView"}
{
	this->setParentItem(parent);
}

QRectF IntervalView::boundingRect() const
{
	return m_rect;
}

void IntervalView::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
	painter->drawRect(m_rect);
	painter->drawRect(m_rect.x(),
					  m_rect.y(),
					  m_rect.width(),
					  15);
	painter->drawText(m_rect, "Interval");
}

void IntervalView::setTopLeft(QPointF p)
{
	m_rect = {p.x(), p.y(), m_rect.width(), m_rect.height()};
}