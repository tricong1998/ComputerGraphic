#include<iostream>
#include<gl/glut.h>
#include<stack>

#include"drawLine.h"
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
	
	glRotatef(-8, 0.0, 1.0, 0.8);

}
void TurnRight() {
	
	glRotatef(8, 0.0, 1.0, 0.8);

}

void draw () {
	stack <char> S;
	glTranslatef(0,-1,0);
	for (int i=0; i<str.length(); i++) {
		char curent = str.at(i);
		if(curent == 'F') {
			drawLine(0.3);
  			
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
				drawLine(0.5);
			}
			else if (S.size() == 1) {
				drawLine(0.25);
			}
		}
	}
}
