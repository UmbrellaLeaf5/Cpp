#include "lines.h"

#include <stdio.h>
#include <string.h>

#include <QColor>
#include <QFileInfo>
#include <QPainter>
#include <fstream>

using namespace std;

Lines::Lines(QWidget *parent) : QWidget(parent) {}

void Lines::paintEvent(QPaintEvent *e) {
  Q_UNUSED(e);

  QPainter qp(this);
  drawLines(&qp);
}

void Lines::drawLines(QPainter *qp) {
  int C1Ri, C1Gi, C1Bi, C2Ri, C2Gi, C2Bi, C3Ri, C3Gi, C3Bi, C4Ri, C4Gi, C4Bi,
      C5Ri, C5Gi, C5Bi, C6Ri, C6Gi, C6Bi;

  ifstream file("C:\\Junk\\C1R.txt");
  if (file.is_open()) {
    file >> C1Ri;
    if (C1Ri > 255) {
      C1Ri = 193;
    }
  } else {
    C1Ri = 193;
  }

  ifstream file1("C:\\Junk\\C1G.txt");
  if (file1.is_open()) {
    file1 >> C1Gi;
    if (C1Gi > 255) {
      C1Gi = 100;
    }
  } else {
    C1Gi = 100;
  }

  ifstream file2("C:\\Junk\\C1B.txt");
  if (file2.is_open()) {
    file2 >> C1Bi;
    if (C1Bi > 255) {
      C1Bi = 39;
    }
  } else {
    C1Bi = 39;
  }

  ifstream file3("C:\\Junk\\C2R.txt");
  if (file3.is_open()) {
    file3 >> C2Ri;
    if (C2Ri > 255) {
      C2Ri = 122;
    }
  } else {
    C2Ri = 122;
  }

  ifstream file4("C:\\Junk\\C2G.txt");
  if (file4.is_open()) {
    file4 >> C2Gi;
    if (C2Gi > 255) {
      C2Gi = 67;
    }
  } else {
    C2Gi = 67;
  }

  ifstream file5("C:\\Junk\\C2B.txt");
  if (file5.is_open()) {
    file5 >> C2Bi;
    if (C2Bi > 255) {
      C2Bi = 30;
    }
  } else {
    C2Bi = 30;
  }

  ifstream file6("C:\\Junk\\C3R.txt");
  if (file6.is_open()) {
    file6 >> C3Ri;
    if (C3Ri > 255) {
      C3Ri = 90;
    }
  } else {
    C3Ri = 90;
  }

  ifstream file7("C:\\Junk\\C3G.txt");
  if (file7.is_open()) {
    file7 >> C3Gi;
    if (C3Gi > 255) {
      C3Gi = 50;
    }
  } else {
    C3Gi = 50;
  }

  ifstream file8("C:\\Junk\\C3B.txt");
  if (file8.is_open()) {
    file8 >> C3Bi;
    if (C3Bi > 255) {
      C3Bi = 23;
    }
  } else {
    C3Bi = 23;
  }

  ifstream file9("C:\\Junk\\C4R.txt");
  if (file9.is_open()) {
    file9 >> C4Ri;
    if (C4Ri > 255) {
      C4Ri = 78;
    }
  } else {
    C4Ri = 78;
  }

  ifstream file10("C:\\Junk\\C4G.txt");
  if (file10.is_open()) {
    file10 >> C4Gi;
    if (C4Gi > 255) {
      C4Gi = 41;
    }
  } else {
    C4Gi = 41;
  }

  ifstream file11("C:\\Junk\\C4B.txt");
  if (file11.is_open()) {
    file11 >> C4Bi;
    if (C4Bi > 255) {
      C4Bi = 15;
    }
  } else {
    C4Bi = 15;
  }

  ifstream file12("C:\\Junk\\C5R.txt");
  if (file12.is_open()) {
    file12 >> C5Ri;
    if (C5Ri > 255) {
      C5Ri = 47;
    }
  } else {
    C5Ri = 47;
  }

  ifstream file13("C:\\Junk\\C5G.txt");
  if (file13.is_open()) {
    file13 >> C5Gi;
    if (C5Gi > 255) {
      C5Gi = 27;
    }
  } else {
    C5Gi = 27;
  }

  ifstream file14("C:\\Junk\\C5B.txt");
  if (file14.is_open()) {
    file14 >> C5Bi;
    if (C5Bi > 255) {
      C5Bi = 14;
    }
  } else {
    C5Bi = 14;
  }

  ifstream file15("C:\\Junk\\C6R.txt");
  if (file15.is_open()) {
    file15 >> C6Ri;
    if (C6Ri > 255) {
      C6Ri = 24;
    }
  } else {
    C6Ri = 24;
  }

  ifstream file16("C:\\Junk\\C6G.txt");
  if (file16.is_open()) {
    file16 >> C6Gi;
    if (C6Gi > 255) {
      C6Gi = 14;
    }
  } else {
    C6Gi = 14;
  }

  ifstream file17("C:\\Junk\\C6B.txt");
  if (file17.is_open()) {
    file17 >> C6Bi;
    if (C6Bi > 255) {
      C6Bi = 8;
    }
  } else {
    C6Bi = 8;
  }

  QRgb C1 = qRgb(C1Ri, C1Gi, C1Bi), C2 = qRgb(C2Ri, C2Gi, C2Bi),
       C3 = qRgb(C3Ri, C3Gi, C3Bi), C4 = qRgb(C4Ri, C4Gi, C4Bi),
       C5 = qRgb(C5Ri, C5Gi, C5Bi), C6 = qRgb(C6Ri, C6Gi, C6Bi);

  QPen C1pen;
  QBrush C1brush(C1, Qt::SolidPattern);
  C1pen.setBrush(C1brush);
  C1pen.setWidth(32);
  qp->setPen(C1pen);
  qp->drawLine(264, 164, 520, 164);
  qp->drawLine(296, 196, 520, 196);
  qp->drawLine(296, 228, 520, 228);

  QPen C2pen;
  QBrush C2brush(C2, Qt::SolidPattern);
  C2pen.setBrush(C2brush);
  C2pen.setWidth(32);
  qp->setPen(C2pen);
  qp->drawLine(232, 132, 456, 132);
  qp->drawLine(200, 164, 232, 164);
  qp->drawLine(232, 196, 264, 196);
  qp->drawLine(264, 228, 264, 228);
  qp->drawLine(264, 292, 520, 292);
  qp->drawLine(264, 292, 264, 420);
  qp->drawLine(264, 420, 328, 420);
  qp->drawLine(360, 388, 456, 388);
  qp->drawLine(360, 324, 520, 324);
  qp->drawLine(296, 324, 296, 324);
  qp->drawLine(392, 356, 520, 356);

  QPen C3pen;
  QBrush C3brush(C3, Qt::SolidPattern);
  C3pen.setBrush(C3brush);
  C3pen.setWidth(32);
  qp->setPen(C3pen);
  qp->drawLine(168, 260, 488, 260);
  qp->drawLine(168, 292, 232, 292);
  qp->drawLine(168, 324, 232, 324);
  qp->drawLine(168, 356, 232, 356);
  qp->drawLine(200, 388, 232, 388);
  qp->drawLine(200, 228, 232, 228);
  qp->drawLine(200, 196, 200, 196);
  qp->drawLine(328, 388, 328, 388);
  qp->drawLine(328, 388, 328, 388);
  qp->drawLine(296, 356, 360, 356);
  qp->drawLine(328, 324, 328, 324);
  qp->drawLine(520, 388, 520, 388);
  qp->drawLine(456, 420, 520, 420);
  qp->drawLine(264, 452, 424, 452);

  QPen C4pen;
  QBrush C4brush(C4, Qt::SolidPattern);
  C4pen.setBrush(C4brush);
  C4pen.setWidth(32);
  qp->setPen(C4pen);
  qp->drawLine(456, 452, 520, 452);
  qp->drawLine(264, 484, 424, 484);
  qp->drawLine(200, 420, 232, 420);
  qp->drawLine(168, 388, 168, 388);
  qp->drawLine(264, 548, 264, 548);
  qp->drawLine(456, 548, 456, 548);

  QPen C5pen;
  QBrush C5brush(C5, Qt::SolidPattern);
  C5pen.setBrush(C5brush);
  C5pen.setWidth(32);
  qp->setPen(C5pen);
  qp->drawLine(200, 452, 232, 452);
  qp->drawLine(168, 420, 168, 420);
  qp->drawLine(456, 484, 520, 484);
  qp->drawLine(296, 516, 520, 516);

  QPen C6pen;
  QBrush C6brush(C6, Qt::SolidPattern);
  C6pen.setBrush(C6brush);
  C6pen.setWidth(32);
  qp->setPen(C6pen);
  qp->drawLine(200, 516, 264, 516);
  qp->drawLine(168, 484, 232, 484);
  qp->drawLine(168, 452, 168, 452);

  QPen pen(Qt::black, 32, Qt::SolidLine);
  qp->setPen(pen);
  qp->drawLine(232, 100, 456, 100);
  qp->drawLine(488, 132, 520, 132);
  qp->drawLine(552, 164, 552, 228);
  qp->drawLine(520, 260, 520, 260);
  qp->drawLine(552, 292, 552, 516);
  qp->drawLine(520, 548, 488, 548);
  qp->drawLine(456, 580, 456, 580);
  qp->drawLine(424, 548, 296, 548);
  qp->drawLine(264, 580, 264, 580);
  qp->drawLine(232, 548, 200, 548);
  qp->drawLine(168, 516, 168, 516);
  qp->drawLine(136, 484, 136, 260);
  qp->drawLine(168, 228, 168, 164);
  qp->drawLine(200, 132, 200, 132);
  qp->drawLine(488, 388, 488, 388);
  qp->drawLine(424, 420, 360, 420);
  qp->drawLine(296, 388, 296, 388);
}
