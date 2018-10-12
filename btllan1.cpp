
// khaOn.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include<string>

#include<gl/glut.h>
#include<stack>
using namespace std;
float width = 1.0;
float leng1 = 1.5;
float leng2 = 5;
float leng3 = 2.5;
float leng4 = 1;
float leng5 = 0.5;
float angle = 8.0;
void DrawLine();
void draw();


struct {
	char f = 'F';
	string F = "![+++++F][-------F]-![++++F][------F]-![+++F][-----F]-![F]";

}Rules;

string axiom = "F";
string str = axiom;
void Init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
}

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
}

void ReShape(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-10.0, 10.0, -10.0, 10.0, 10.0, -10.0);
	glMatrixMode(GL_MODELVIEW);
}

void RenderScene()
{
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	draw();

	glFlush();

}
void TurnLeft() {
	
	glRotatef(angle, 0, 0, 1);

}
void TurnRight() {
	
	glRotatef(-angle, 0, 0, 1);

}
void DrawLine() {
	
	
	glLineWidth(width);
//	glTranslatef(0,-5,0);
	glBegin(GL_LINES);
	glColor3f(0.0, 1.0, 0.0);// xanh
	glVertex3f(0,0,0);
	glVertex3f(0,leng1,0);
	glEnd();
	glTranslatef(0,leng1, 0);

}
void DrawBone() {


	glLineWidth(width);
	
	
	
	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 0.0);// xanh
	glVertex3f(0, 0, 0);
	glVertex3f(0, leng2, 0);
	glEnd();
	glTranslatef(0, leng2, 0);
	
}
void DrawBone1() {


	glLineWidth(width);
	
	
	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 0.0);// xanh
	glVertex3f(0, 0, 0);
	glVertex3f(0, leng3, 0);
	glEnd();
	glTranslatef(0, leng3, 0);

}

void DrawBone2() {


	glLineWidth(width);

	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 0.0);// xanh
	glVertex3f(0, 0, 0);
	glVertex3f(0, leng4, 0);
	glEnd();
	glTranslatef(0, leng4, 0);

}
void DrawBone3() {


	glLineWidth(width);

	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 0.0);// xanh
	glVertex3f(0, 0, 0);
	glVertex3f(0, leng5, 0);
	glEnd();
	glTranslatef(0, leng5, 0);

}
void push() {
	glPushMatrix();
}
void pop() {
	glPopMatrix();
}
void length (float x) {
	leng1 = x*leng1;
	leng2 = x*leng2;
	leng3 = x*leng3;
	leng4 = x*leng4;
	leng5 = x*leng5;
}
void genarate(int i) {
	if (i==3) length(0.75);
	else if (i==2) length(0.55);
	else if (i==4) length (0.85);
	else if (i=1) length (0.5);
	string strCurent = "";
	for (int i = 0; i < str.length(); i++) {
		char curent =  str.at(i);
		if (curent == Rules.f) {
			strCurent += Rules.F;			
		}		
		else
			strCurent += curent;

		
	}
	cout << strCurent;
	
	str = strCurent;
	
}

void draw() {
	stack <char> S;
	glTranslatef(0,-7,0);
	for (int i = 0; i < str.length(); i++) {
		char curent = str.at(i);
		if (curent == 'F') {
			// drawLine
			DrawLine();
			//glTranslated(x, y + 5, z);
		}
		else if (curent == '+') {
			// turn Right
			TurnRight();
		}
		else if (curent == '-') {
			// turn Left
			TurnLeft();
		}
		
		else if (curent == '[') {
			push();
			S.push(1);
		}
		else if(curent == ']') {
			pop();
			S.pop();
		}
		else if (curent == '!') {
			if (S.empty()) DrawBone();
			else if(S.size() == 1) DrawBone1();
			else if (S.size() == 2) DrawBone2();
			else if (S.size() == 3) DrawBone3();
		}
	}
}
void resize(int width, int height) {
    // we ignore the params and do:
    glutReshapeWindow( 500, 500);
}
int main()
{
	glutInitDisplayMode(GLUT_SINGLE || GLUT_RGB);

	glutInitWindowSize(700, 700);
	
	glutInitWindowPosition(100, 100);

	glutCreateWindow("BTL");

	Init();
	int n;
	cout << "Press generate : " ;
	cin >> n;
	
	if (n==1) {
		for (int i=0; i<1; i++) {
			genarate(1);
		}
	}
	
	else if (n == 2) {
		for (int i=0; i<2; i++) {
			genarate (2);
		}
	}
	else if (n == 3) {
		for (int i=0; i<3; i++) {
			genarate (3);
		}
	}
	else if(n==4) {
		for (int i=0; i<4; i++) {
			genarate(4);
		}
	}
	
	
	glutReshapeFunc(ReShape);
	glutDisplayFunc(RenderScene);
	
	glutMainLoop();

	return 0;
	
	
}

