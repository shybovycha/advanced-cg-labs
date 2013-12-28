// shaders.cpp : Defines the entry point for the console application.
//


#include "Image.h"
#include "wshaderprogram.h"
#include "glut.h"

#define    SIZE  64
GLfloat    mesh[SIZE][SIZE][3];    // Наша статическая модель
GLfloat    wave_time = 0.0f;
GLuint     tex[8];

WShaderProgram *program1 = NULL;

void init()
{
//	glOrtho( -SIZE, SIZE, -SIZE, SIZE, 1, 1000 );

	// Создать модель
	for (int x = 0; x < SIZE; x++)
	{
		for (int y = 0; y < SIZE; y++)
		{
			mesh[x][y][0] = (float) (SIZE / 2) - x; // Центр модели в начале координат
			mesh[x][y][1] = (float) (SIZE / 2) - y; // Центр модели в начале координат
			mesh[x][y][2] = 0.0f;            // Задать все значение Y для всех точек равным 0
		}
	}

	program1 = new WShaderProgram();

	WShader *shader1 = new WShader( GL_VERTEX_SHADER_ARB );
	if( !shader1->compileSourceFile("../../files/light.vsh") || !program1->addShader( shader1 ) )
	{
		std::cout << shader1->log() << std::endl;
		std::cout << program1->log() << std::endl;
		delete shader1;
	}

	WShader *shader2 = new WShader( GL_FRAGMENT_SHADER_ARB );
	if( !shader2->compileSourceFile("../../files/light.fsh") || !program1->addShader( shader2 ) )
	{
		std::cout << shader2->log() << std::endl;
		std::cout << program1->log() << std::endl;
		delete shader1;
	}

	if( !program1->link() )
		std::cout << program1->log() << std::endl;

	glEnable( GL_LIGHTING );

	glEnable( GL_LIGHT0 );
	GLfloat pos0[] = { 3, 3, -4, 1 };
	glLightfv( GL_LIGHT0, GL_POSITION, pos0 );
	GLfloat dif0[] = { 0.9, 0.9, 0.9, 1 };
	glLightfv( GL_LIGHT0, GL_DIFFUSE, dif0 );
	GLfloat spe0[] = { 0.0, 0.0, 0.0, 1 };
	glLightfv( GL_LIGHT0, GL_SPECULAR, spe0 );

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);

	glTexGenf( GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR );
	glTexGenf( GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR );

	// 
	BitmapBits bits;
	bits.load( "1-bot.bmp" );
	glGenTextures(8, tex );
	glBindTexture( GL_TEXTURE_2D, tex[ 0 ] );
	gluBuild2DMipmaps( GL_TEXTURE_2D, 3, bits.getWidth(), bits.getHeight(), GL_BGR_EXT, GL_UNSIGNED_BYTE, bits.getBits() );
}

void display(void)
{
	glClearColor(0.3, 0.5, 7.0, 1.0); // clear the screen to blue
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); // clear the color

	glBegin(GL_LINES);
		glColor3d( 1, 0, 0 );
		glVertex3d( -SIZE, 0, 0 );
		glVertex3d(  SIZE, 0, 0 );
		glColor3d( 0, 1, 0 );
		glVertex3d( 0, -SIZE, 0 );
		glVertex3d( 0,  SIZE, 0 );
		glColor3d( 0, 0, 1 );
		glVertex3d( 0, 0, -SIZE );
		glVertex3d( 0, 0,  SIZE );
	glEnd();

	// glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );

	GLfloat amb0[] = {0.2125, 0.1275, 0.054, 1.0};
	GLfloat dif0[] = {0.714, 0.4284,  0.18144, 1.0};
	GLfloat spe0[] = {0.393548, 0.271906, 0.1666721,1.0};
	glMaterialfv( GL_FRONT_AND_BACK, GL_AMBIENT, amb0 );
	glMaterialfv( GL_FRONT_AND_BACK, GL_DIFFUSE, dif0 );
	glMaterialfv( GL_FRONT_AND_BACK, GL_SPECULAR, spe0 );
	glMaterialf( GL_FRONT_AND_BACK, GL_SHININESS, 25.6 );

	// Начать рисование модели
	program1->enable();
	program1->setValue1f("waveHeight", 2.0f);
	program1->setValue1f("waveTime", wave_time);
	program1->setValue1i("myTexture", tex[0]);
/*
	for (int x = 0; x < SIZE - 1; x++)
	{
		// Рисовать полоску треугольников для каждой колонки нашей модели
		glBegin( GL_TRIANGLE_STRIP );

		glColor4d( 0.75, 0.25, 0, 1 );
		for (int z = 0; z < SIZE - 1; z++)
		{
			// Задать параметр волны для нашего шейдера.
			// Значение wave увеличивается в основной программе
			glVertex3f(mesh[x][z][0], mesh[x][z][1], mesh[x][z][2]);  // Рисовать вершину
			glVertex3f(mesh[x+1][z][0], mesh[x+1][z][1], mesh[x+1][z][2]);  // Рисовать вершину
		}
		glEnd();
	}
*/

	glBindTexture( GL_TEXTURE_2D, tex[0] );
	glutSolidSphere( 2, 21, 21 );
	glBindTexture( GL_TEXTURE_2D, 0 );

	program1->disable();

	glutSwapBuffers(); // swap the buffers
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);

	glMatrixMode( GL_PROJECTION );
	gluPerspective( 45, w / (double)h, 1, 100 ); 
	gluLookAt(0.0f, 0.0f, 10.0f, 0.0f, 0.0f, 0.0f, 0, 1, 0);
}

void keyboard(unsigned char key, int x, int y)
{
	if( key == 27 )
	{
		exit(0); // quit the program
	}
	else if( key == 'a' )
	{
		glMatrixMode( GL_MODELVIEW );
		glRotated( 3, 1, 0, 0 );
		glutPostRedisplay();
	}
	else if( key == 'd' )
	{
		glMatrixMode( GL_MODELVIEW );
		glRotated( -3, 1, 0, 0 );
		glutPostRedisplay();
	}
	else if( key == 'w' )
	{
		glMatrixMode( GL_MODELVIEW );
		glRotated( 3, 0, 1, 0 );
		glutPostRedisplay();
	}
	else if( key == 's' )
	{
		glMatrixMode( GL_MODELVIEW );
		glRotated( -3, 0, 1, 0 );
		glutPostRedisplay();
	}
}

void timef(int value)
{
	wave_time += 0.025f; // Увеличить движение волны
	if (wave_time > 2 * 3.1415) // Предотвратить крах программы
		wave_time = 0.0f;

	glutPostRedisplay();
	glutTimerFunc(16, timef, 1);
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE); //set the display to Double buffer
	glutInitWindowSize(300, 300);
	glutCreateWindow(argv[0]);

	init();

	glutDisplayFunc(display); //use the display function to draw everything
	glutReshapeFunc(reshape); //reshape the window accordingly
	glutKeyboardFunc(keyboard); //check the keyboard
	glutTimerFunc(16, timef, 1);

	glutMainLoop(); //call the main loop

	return 0;
}

