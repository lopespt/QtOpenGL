/*
 * MainWidget.h
 *
 *  Created on: 07/07/2014
 *      Author: wachs
 */

#ifndef MAINWIDGET_H_
#define MAINWIDGET_H_

#include <GL/glu.h>
#include <GL/glut.h>
#include <QTimer>
#include <QWidget>
#include <QtOpenGL>
#include <math.h>

class MainWidget : public QGLWidget {
  Q_OBJECT
public:
  MainWidget(QWidget *parent = NULL);
  void initializeGL();
  void paintGL();

  virtual ~MainWidget();

private:
  QTimer timer;

  void drawGrid();
  void drawCube();
  void drawFunction();
  void resizeGL(int w, int h);
  void drawAxis();

  void drawCube(GLfloat x, GLfloat y, GLfloat z, GLfloat dx, GLfloat dy,
                GLfloat dz);
};

#endif /* MAINWIDGET_H_ */
