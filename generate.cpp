#include<iostream>
#include<gl/glut.h>
#include<stack>

#include"drawLine.h"
float l1 = 0.3;
float l2 = 0.5;
float l3 = 0.25;
float l4 = 0.15;
float l5 = 0.07;
using namespace std;
struct {
	char f = 'F';
	string F = "![+++++F][-------F]-![++++F][------F]-![+++F][-----F]-![F]";
}Rules;

string axiom = "F";
string str = axiom;

void genarate() {
	
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

void push() {
	glPushMatrix();
}
void pop() {
	glPopMatrix();
}
void TurnLeft() {
	
	glRotatef(-8, 0.0, 1.0, 0.9);

}
void TurnRight() {
	
	glRotatef(8, 0.0, 1.0, 0.9);

}

void draw () {
	stack <char> S;
	glTranslatef(0,-1.5,0);
	for (int i=0; i<str.length(); i++) {
		char curent = str.at(i);
		if(curent == 'F') {
			drawLine(l1);
			
			glTranslatef(0,l1,0);
  			
		}
		else if(curent == '+') {
			TurnRight();
		}
		else if(curent == '-') {
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
		else if (curent == '!'){
			if(S.empty()) {
				drawLine(l2);
				glTranslatef(0,l2,0);
			}
			else if (S.size() == 1) {
				drawLine(l3);
				glTranslatef(0,l3,0);
			}
			else if (S.size() == 2) {
				drawLine(l4);
				glTranslatef(0,l4,0);
			}
			else if (S.size() == 3) {
				drawLine(l5);
				glTranslatef(0,l5,0);
			}
		}
	}
}
