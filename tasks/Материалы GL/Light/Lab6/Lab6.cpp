#include "stdafx.h"
#include <Windows.h>
#include <GL\gl.h>
#include <GL\glu.h>
#include "glut.h"
#include "image.h"
#include "textfile.h"
#include <string.h>
#include <math.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

#include "glarb.h"

#ifdef __cplusplus
}
#endif


#define MAX 3 
int		cur = 0;
int		mode = 'r';
int		r[MAX] = {0};
double	s[MAX] = {0};
double	t[MAX] = {0};

GLfloat Light[]	=	{0.0, 5.0, 4.0, 1.0};
GLfloat Eye[]	=	{7.0, 5.0, 7.0, 1.0};
float X = 0, Y = 0, Z = 0;
GLuint v, f, p;
double angle	=	180;
int w	=	1000;
int h	=	500;

GLfloat l[]		=	{5.0,0.0,4.0,1.0};
GLint light, eye, texture;

GLuint texid[5]	=	{ 0, 0, 0, 0, 0 };
int OldX=0,OldY=0;

void init(void)
{
	glEnable(GL_DEPTH_TEST);
	glLightfv(GL_LIGHT0,GL_POSITION,l);
	//glLightfv(GL_LIGHT0,GL_DIFFUSE,diffColor);
	//glLightfv(GL_LIGHT0,GL_SPECULAR,specColor);
	//glLightfv(GL_LIGHT0,GL_AMBIENT,ambient);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	BitmapBits texture1_image;
	texture1_image.load("6.bmp");
	glGenTextures(5, texid);
	glBindTexture(GL_TEXTURE_2D, texid[0]);
	//glBindTexture(GL_TEXTURE_2D, texid[1]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, 3, 
		         texture1_image.getWidth(),
				 texture1_image.getHeight(),
				 0, GL_BGR_EXT, GL_UNSIGNED_BYTE,
				 texture1_image.getBits());	
}




void reshape ( int w, int h )
{
   glViewport     ( 0, 0, (GLsizei)w, (GLsizei)h );
   glMatrixMode   ( GL_PROJECTION );
   											// factor all camera ops into projection matrix
   glLoadIdentity ();
   gluPerspective ( 60.0, (GLfloat)w/(GLfloat)h, 1.0, 60.0 );
   gluLookAt      ( 7.0,5.0,7.0,
					0, 0, 0,
					0.0, 1.0, 0.0 );

   glMatrixMode   ( GL_MODELVIEW );
   glLoadIdentity ();
}

void display()
{

	glClearColor(0.0, 0.0, 0.0, 1.0); 	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgramObjectARB(0);
	glRotatef		( X, 1, 0, 0 );
	glRotatef		( Y, 0, 1, 0 );
	glRotatef		( Z, 0, 0, 1 );

	glPushMatrix ();
	glTranslatef		( Light[0], Light[1], Light[2] );
	glColor3f			(1.0,1.0,1.0);
	glutSolidSphere		( 0.1f, 15, 15 );
	glPopMatrix		();

	GLUquadricObj *quadObj; 
	quadObj = gluNewQuadric(); 
	gluQuadricTexture(quadObj, GL_TRUE);
	gluQuadricDrawStyle(quadObj, GLU_FILL); 
  
	glEnable(GL_POLYGON_SMOOTH);
	glPushMatrix();
	glTranslatef(-2.7, 2.7, 2.3);
	glUseProgramObjectARB(p);
	gluSphere(quadObj, 0.8, 21, 21);
	glUseProgramObjectARB(0);

	glPopMatrix();


	glPushMatrix();
	glTranslatef(2.7f, -2.7f, -2.3f);

	glUseProgramObjectARB(p);
	gluSphere(quadObj,0.8,21,21);
	glUseProgramObjectARB(0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.0f, 1.0f, 1.0f);

	glUseProgramObjectARB(p);
	glutSolidTeapot(2);
	glUseProgramObjectARB(0);
	glPopMatrix();

	glDisable(GL_POLYGON_SMOOTH);
	gluDeleteQuadric(quadObj);
	glutSwapBuffers();
}  

void MyKeyBoard(unsigned char key, int x, int y)
{
	switch(key)
	{
		case 27:
			exit(0);
			break;
	}
}

void SpecKeyBoard(int key, int x, int y)
{
	switch(key)
	{
		case GLUT_KEY_PAGE_DOWN:
			X--;
			glutPostRedisplay();
			break;
		case GLUT_KEY_PAGE_UP:
			X++;
			glutPostRedisplay();
			break;
		case GLUT_KEY_UP:
			Z--;
			glutPostRedisplay();
			break;
		case GLUT_KEY_DOWN:
			Z++;
			glutPostRedisplay();
			break;
		case GLUT_KEY_LEFT:
			Y--;
			glutPostRedisplay();
			break;
		case GLUT_KEY_RIGHT:
			Y++;
			glutPostRedisplay();
			break;
	}
}

void Shader()
{
	char *vs = NULL,*fs = NULL,*fs2 = NULL;

	v = glCreateShaderObjectARB(GL_VERTEX_SHADER);
	f = glCreateShaderObjectARB(GL_FRAGMENT_SHADER);
	vs = textFileRead("vert.v");
	fs = textFileRead("frag.f");
	const char * ff = fs;
	const char * vv = vs;

	glShaderSourceARB(v, 1, &vv,NULL);
	glShaderSourceARB(f, 1, &ff,NULL);
	free(vs);
	free(fs);
	
	glCompileShaderARB(v);
	glCompileShaderARB(f);
	
	p = glCreateProgramObjectARB();
	glAttachObjectARB(p,f);
	glAttachObjectARB(p,v);

	glLinkProgramARB(p);
	//glUseProgram(p);
	light = glGetUniformLocationARB(p,"lightPos");
	eye = glGetUniformLocationARB(p,"eyePos");
	texture = glGetUniformLocationARB(p,"samp");

}

void animate ()
{
	angle  = 0.005f * glutGet ( GLUT_ELAPSED_TIME ); 
	float f;
	f = 3*cos( angle );
	Light[0] = sin(angle);
	Light[1] = 4*sin(angle);
	Light[2] = f;
	glUseProgramObjectARB(p);
	glUniform4fvARB(light, 1, Light);
	glUniform4fvARB(eye, 1, Eye);
	glUniform4fvARB(eye, 1, Eye);
	glUniform1fARB(texture, 0);
	glUseProgramObjectARB(0);
	glutPostRedisplay ();
}


int main(int argc, char **argv)
{
	glutInit			(&argc, argv);
	glutInitDisplayMode	(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize	(w, h);
	glutCreateWindow	(argv[0]);
	glutReshapeFunc		(reshape);
	init				();
	glutDisplayFunc		(display);
	glutIdleFunc		( animate );
	glutSpecialFunc		(SpecKeyBoard);
	glutKeyboardFunc	(MyKeyBoard);
	Shader();
	glutMainLoop();
	return 0;
}