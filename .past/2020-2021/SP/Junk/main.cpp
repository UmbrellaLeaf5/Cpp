#include <QApplication>
#include <QFileInfo>

#include "lines.h"
#include "widget.h"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  Lines window;
  Widget Widget;

  window.resize(800, 700);
  window.setWindowTitle("Lines");
  window.show();
  Widget.show();
  return app.exec();
}
