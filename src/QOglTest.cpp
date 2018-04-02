#include "DateTime.h"
#include "MainWidget.h"
#include <QApplication>
#include <QLabel>
#include <QtOpenGL>

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  MainWidget *main = new MainWidget();
  main->setVisible(true);

  return app.exec();
}
