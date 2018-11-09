
#include<gl/glut.h>
using namespace std;

GLuint g_box;
void MakeCylinder(const float& radius, const float& length)
{
	glPushMatrix();
 	//GLuint dp_list;
// 	dp_list = glGenLists(1); 
// 	glNewList(dp_list, GL_COMPILE);
	GLUquadricObj *quadratic_obj;
 	quadratic_obj = gluNewQuadric();
 	glRotatef(-90, 1.0, 0.0, 0.0);
 	gluCylinder(quadratic_obj, radius, radius, length, 32, 32);
 	glPopMatrix();
 	//glEndList();
// 	return dp_list;
}

void drawLine(float x) {

	MakeCylinder(0.01,x);
	glCallList(g_box);
//	glTranslatef(0,x,0);
}


