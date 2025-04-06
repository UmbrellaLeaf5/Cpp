#include <QApplication>
#include "lines.h"
#include "widget.h"
#include <QFileInfo>

int main(int argc, char *argv[]) {

  QApplication app(argc, argv);
  Lines window;
  Widget Widget;

  window.resize(1200, 500);
  window.setWindowTitle("Lines");
  window.show();
  return app.exec();
}
