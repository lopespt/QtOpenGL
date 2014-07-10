
#include "DateTime.h"
#include <QApplication>
#include <qglwidget>
#include <QLabel>
#include "MainWidget.h"

int main( int argc, char * argv[] )
{
    QApplication app(argc, argv);
    MainWidget *main = new MainWidget();
    main->setVisible(true);


    return app.exec();
}
