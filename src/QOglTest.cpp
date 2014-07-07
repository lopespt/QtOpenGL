
#include "DateTime.h"
#include <QApplication>
#include <qglwidget>
#include <QLabel>


int main( int argc, char * argv[] )
{
    QApplication app(argc, argv);
    QGLWidget l;
    l.setVisible(true);


    return app.exec();
}
