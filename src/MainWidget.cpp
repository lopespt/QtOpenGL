/*
 * MainWidget.cpp
 *
 *  Created on: 07/07/2014
 *      Author: wachs
 */

#include "MainWidget.h"

MainWidget::MainWidget(QWidget *parent) :
		QGLWidget(parent), timer(this) {
	timer.setInterval(50);
	QObject::connect(&timer, SIGNAL(timeout()), this, SLOT(updateGL()));
	timer.start();

}

void MainWidget::initializeGL() {
	glClearColor(0, 0, 0, 1);

	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 50.0 };
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glShadeModel(GL_FLAT);

	//glTranslatef(1.5, 1.5, 0);
	glEnable(GL_CULL_FACE);
	//glCullFace(GL_FRONT_AND_BACK);
	//glFrontFace(GL_CCW);

	glEnable(GL_LINE_SMOOTH);

	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
	//glEnable (GL_COLOR_MATERIAL);

	GLfloat light_ambient[] = { 0.1, 0.1, 0.1, 1.0 };
	GLfloat light_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
	GLfloat light_specular[] = { 0.3, 0.3, 0.3, 1.0 };
	GLfloat light_position[] = { 3, 0.0, 0, 1 };

	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glEnable(GL_DEPTH_TEST);

	//glPushMatrix();
}

void MainWidget::paintGL() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	GLfloat qaBlack[] = { 0, 0, 0, 1 };
	GLfloat qaGreen[] = { 0, 1, 0, 1 };
	GLfloat qaWhite[] = { 1, 1, 1, 1 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, qaGreen);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, qaGreen);
	glMaterialfv(GL_FRONT, GL_SPECULAR, qaWhite);
	glMaterialf(GL_FRONT, GL_SHININESS, 60.0);

	glRotatef(1, 0, 0, 1);
	glPushMatrix();
	//drawGrid();
	glColor3f(1, 0, 0);
	//drawCube();
	drawCube(1, 1, 1, 1, 1, 1);
	glEnable(GL_COLOR_MATERIAL);
	glDisable(GL_LIGHTING);
	drawAxis();
	drawGrid();
	glDisable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glPopMatrix();
}

MainWidget::~MainWidget() {
	// TODO Auto-generated destructor stub
}

void MainWidget::drawGrid() {
	glColor3f(0.65, 0.65, 0.65);
	//glPushAttrib(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINES);
	for (float i = -1; i <= 1; i += 2.0 / 20.0) {
		glVertex2d(i, -1);
		glVertex2d(i, 1);
	}
	for (float i = -1; i <= 1; i += 2. / 20.0) {
		glVertex2d(-1, i);
		glVertex2d(1, i);
	}
	glEnd();
}

void MainWidget::drawCube() {

	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);
	glVertex3d(-1, -1, -1);
	glVertex3d(-1, 1, -1);
	glVertex3d(1, 1, -1);
	glVertex3d(1, -1, -1);
	glColor3f(0, 0, 1);
	glVertex3d(-1, -1, -1);
	glVertex3d(-1, -1, 1);
	glVertex3d(-1, 1, 1);
	glVertex3d(-1, 1, -1);

	glEnd();
}

void MainWidget::drawFunction() {
	glColor3f(0, 1, 0);

	for (float i = -1; i <= 1; i += 0.1) {
		glVertex3d(i, 0, (i * i) / 400.0);
	}
	for (int i = 19; i >= 0; i--) {
		glVertex3d(i / 20.0, 0, (i * i) / 400.0 + 0.01);
	}

	glEnd();
}

void MainWidget::resizeGL(int w, int h) {
	int side = qMin(w, h);
	glViewport((w - side) / 2, (h - side) / 2, side, side);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1.0, +1.0, -1.0, 1.0, 5.0, 60.0);

	//glOrtho(-2.0, +2.0, -2.0, 2.0, 5.0, 60.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(10, 10, 10, 0, 0, 0, 0, 0, 1);
	//glTranslated(0.0, 0.0, -20.0);
	//glRotated(20, 1, 0, 0);
	//glRotated(45, 0, 0, 1);

}

void MainWidget::drawAxis() {
	glBegin(GL_LINES);
	glColor3f(1, 0, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(10, 0, 0);

	glColor3f(0, 1, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 10, 0);

	glColor3f(0, 0, 1);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, 10);
	glEnd();
}

void MainWidget::drawCube(GLfloat x, GLfloat y, GLfloat z, GLfloat dx,
		GLfloat dy, GLfloat dz) {

	glBegin(GL_QUADS);

	glNormal3f(0, 0, 1);
	glVertex3d(1, -1, 1);
	glVertex3d(1, 1, 1);
	glVertex3d(-1, 1, 1);
	glVertex3d(-1, -1, 1);

	glNormal3f(0, -1, 0);
	glVertex3d(1, -1, -1);
	glVertex3d(1, -1, 1);
	glVertex3d(-1, -1, 1);
	glVertex3d(-1, -1, -1);

	glNormal3f(0, 1, 0);
	glVertex3d(-1, 1, -1);
	glVertex3d(-1, 1, 1);
	glVertex3d(1, 1, 1);
	glVertex3d(1, 1, -1);

	glNormal3f(-1, 0, 0);
	glVertex3d(-1, -1, -1);
	glVertex3d(-1, -1, 1);
	glVertex3d(-1, 1, 1);
	glVertex3d(-1, 1, -1);

	glNormal3f(1, 0, 0);
	glVertex3d(1, 1, -1);
	glVertex3d(1, 1, 1);
	glVertex3d(1, -1, 1);
	glVertex3d(1, -1, -1);

	glEnd();

}

