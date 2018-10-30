#include<iostream>
#include<gl/glut.h>
#include<cmath>
#include"generate.h"
#define DIS 10
using namespace std;
// Xu lý xoay hinh
float g_x = 0.0;
float g_z= 0.0;
float g_angle = 0.0;
float delta_angle = 0.0;
float g_x_origin = 0.0;
bool g_is_rotate = false;

void MouseButton(int type_button, int state, int x, int y) {
	if (type_button == GLUT_LEFT_BUTTON) {
		if (state == GLUT_DOWN) {
   			g_x_origin = x;
   			g_is_rotate = true;
   	
		} else {
   			g_is_rotate = false;
   			g_angle += delta_angle;
   			g_x_origin = -1;
   
  		}
 	}
 
}

void mouseMove(int x, int y) {
	if(g_is_rotate) {
 		delta_angle = (x - g_x_origin) * 0.005f;
 		g_x = DIS*sin(g_angle + delta_angle);
 		g_z = DIS*cos(g_angle + delta_angle);
 	}

}


void toaDo() {
	glBegin(GL_LINES); //OX
 	glColor3f(1.0, 0.0, 0.0);
 	glVertex3f(0.0, 0.0, 0.0);
 	glVertex3f(10.0, 0.0, 0.0);
 	glEnd();
 
 	glBegin(GL_LINES); //OY
 	glColor3f(0.0, 1.0, 0.0);
 	glVertex3f(0.0, 0.0, 0.0);
 	glVertex3f(0.0, 10.0, 0.0);
 	glEnd();
 
 	glBegin(GL_LINES); //OZ
 	glColor3f(0.0, 0.0, 1.0);
 	glVertex3f(0.0, 0.0, 0.0);
 	glVertex3f(0.0, 0.0, 10.0);
 	glEnd();
}

void Init()
{
	// bât chiêu sáng
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);

  GLfloat light_pos [] = {0.0, 1.0, 1.0, 1.0};
  glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
  GLfloat ambient [] = {1.0, 0.0, 0.0, 1.0};
  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
  GLfloat diff_use [] = {0.0, 0.5, 0.0, 1.0};
  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff_use);
 
  GLfloat specular[] = {1.0, 1.0, 1.0, 1.0};
  glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
 
  GLfloat shininess = 50.0f;
  glMateriali(GL_FRONT, GL_SHININESS, shininess);
 
  g_x = DIS * sin(g_angle);
  g_z = DIS * cos(g_angle);
}
 
void ReShape(int width, int height)
{
 	glViewport(0, 0, width, height);
 	glMatrixMode(GL_PROJECTION);
 	glLoadIdentity();
// 	glOrtho(-10.0, 10.0, -10.0, 10.0, 10.0, -10.0);
// 	glOrtho(-1.0, 1.0, -1.0, 1.0, 1, 10.0);

 	float ratio = (float)width/(float)height;
 	gluPerspective(35.0,ratio,1.0,100.0);
 	glMatrixMode(GL_MODELVIEW);
}
 
void RenderScene()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  gluLookAt(g_x, 1, g_z, 0.0, 0.0, 0.0, 0.0,1.0, 0.0);
  
//	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
  toaDo();
  
//  glTranslatef(0,0,-2);
  draw();
  glFlush();
  glutPostRedisplay();
  
}


int main()
{
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 
  glutInitWindowSize(500, 500);
 
  glutInitWindowPosition(100, 100);
 
  glutCreateWindow("Opengl Study");
 
  Init();
 
  glutReshapeFunc(ReShape);
 
  glutDisplayFunc(RenderScene);
 // genarate();
  for (int i=0;i<2; i++) {
  		genarate();
  		cout<< "\n";
  }
  glutMouseFunc(MouseButton);
  glutMotionFunc(mouseMove);
  glutMainLoop();
  
  return 0;
} 
 

