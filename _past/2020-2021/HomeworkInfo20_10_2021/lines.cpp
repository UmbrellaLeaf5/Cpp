#include <QPainter>
#include "lines.h"
#include <QColor>
#include <stdio.h>
#include <string.h>
#include <QFileInfo>
#include <fstream>

using namespace Qt;

Lines::Lines(QWidget *parent)
    : QWidget(parent)
{ }

void Lines::paintEvent(QPaintEvent *e){

  Q_UNUSED(e);

  QPainter qp(this);
  drawLines(&qp);
}

void Lines::drawLines(QPainter *qp)
{
  QRgb C1 = qRgb(0, 0, 0);

  QPen C1pen;
  QBrush C1brush(C1, SolidPattern);
  C1pen.setBrush(C1brush);
  C1pen.setWidth(2);
  qp->setPen(C1pen);
  qp->drawEllipse(400, 100, 300, 300);
  qp->drawEllipse(450, 175, 60, 60);
  qp->drawEllipse(587, 175, 60, 60);
  qp->drawLine(550, 200, 550, 300);
  qp->drawLine(500, 350, 600, 350);

  qp->drawRect(100, 250, 250, 200);
  qp->drawRect(175, 310, 100, 75);
  qp->drawLine(225, 340, 225, 387);
  qp->drawLine(175, 340, 275, 340);
  qp->drawLine(100, 250, 225, 125);
  qp->drawLine(225, 125, 350, 250);

  qp->drawLine(950, 100, 950, 250);
  qp->drawLine(800, 250, 1100, 250);
  qp->drawLine(850, 325, 1050, 325);
  qp->drawLine(800, 250, 850, 325);
  qp->drawLine(1100, 250, 1050, 325);
  qp->drawLine(950, 100, 1050, 150);
  qp->drawLine(1050, 150, 950, 200);

}
