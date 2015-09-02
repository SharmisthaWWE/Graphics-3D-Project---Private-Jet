#include<windows.h>
#include<GL/glaux.h>
#include<math.h>
#include<GL/glut.h>
#include<GL/glu.h>
#include<stdio.h>
#include<stdarg.h>
#include<string.h>
#define PI acos(-1.0)

float angle=0.0,deltaAngle = 0.0,ratio;
float x=230.0f,y=15.4f,z=36.0f;
float lx=-18.0f,ly=0.0f,lz=0.0f;
float deltaMove = 0,h,w;
int font=(int)GLUT_BITMAP_8_BY_13;
static GLint snowman_display_list;
int bitmapHeight=13,state=0,state2=0,count=0,statew=0,state3=0,fix=0,raf=1,aa=0,sum=0;
float j=-20.0f,k=-10.0f,q=20.0f,l=10.0f;
float deltaDist = 0.0;
GLfloat	l_t=0,u_p=0, b_a = 0;
GLfloat ra=0;
GLUquadricObj *Quadric;
float segments = 100;
char* PointBackgroundMusic = NULL;
char* PointStopMusic = NULL;
GLuint texture[100];

void LoadGLTextures()
{
	AUX_RGBImageRec* TextureImage;

	glGenTextures(100,texture);

	if (TextureImage = auxDIBImageLoad("whit.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[0]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}


	if (TextureImage = auxDIBImageLoad("red.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[1]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}


	if (TextureImage = auxDIBImageLoad("wel1.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[2]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("seamless.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[3]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("window.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[4]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("whit.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[5]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("fan.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[6]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("ground.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[7]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("art.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[8]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("table.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[9]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("wall.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[10]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("road.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[11]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("art1.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[12]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("ac.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[13]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}


	if (TextureImage = auxDIBImageLoad("screen.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[14]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("key.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[15]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("art5.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[16]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("art4.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[17]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}


	if (TextureImage = auxDIBImageLoad("art6.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[18]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("table.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[19]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}


	if (TextureImage = auxDIBImageLoad("fruits.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[20]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("art8.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[21]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("art9.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[22]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}


	if (TextureImage = auxDIBImageLoad("art10.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[23]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("food1.bmp"))            //OK
	{
		glBindTexture(GL_TEXTURE_2D, texture[24]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("art12.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[25]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("art13.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[26]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("rest.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[27]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}
	if (TextureImage = auxDIBImageLoad("bed.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[28]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("art16.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[29]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("art17.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[30]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	/*if (TextureImage = auxDIBImageLoad("art18.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[31]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}*/

	if (TextureImage = auxDIBImageLoad("art19.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[32]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("art20.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[33]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("art21.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[34]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("art22.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[35]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}
	if (TextureImage = auxDIBImageLoad("art23.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[36]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("art24.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[37]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("art25.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[38]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}


	if (TextureImage = auxDIBImageLoad("art26.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[39]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("lcd.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[40]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("art28.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[41]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("art29.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[42]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("art30.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[43]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}
	if (TextureImage = auxDIBImageLoad("art31.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[44]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("art32.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[45]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("seamless.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[46]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("red.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[47]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}


	if (TextureImage = auxDIBImageLoad("black.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[48]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}


	if (TextureImage = auxDIBImageLoad("steel.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[49]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}


	if (TextureImage = auxDIBImageLoad("white.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[50]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("light.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[51]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("metal1.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[52]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}


	if (TextureImage = auxDIBImageLoad("cloth.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[53]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("sofa.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[54]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}


	if (TextureImage = auxDIBImageLoad("metal1.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[55]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("white11.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[56]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("s17.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[57]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("floor.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[58]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("floor1.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[59]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}



	if (TextureImage = auxDIBImageLoad("dine.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[60]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("s3.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[61]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("s4.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[62]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("chair.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[63]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("s6.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[64]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}
	if (TextureImage = auxDIBImageLoad("s7.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[65]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("br.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[66]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("s9.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[67]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("s10.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[68]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}


	if (TextureImage = auxDIBImageLoad("windo.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[69]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}


	if (TextureImage = auxDIBImageLoad("s12.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[70]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}


	if (TextureImage = auxDIBImageLoad("s13.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[71]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("s14.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[72]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("s15.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[73]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}


	if (TextureImage = auxDIBImageLoad("s16.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[74]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("s18.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[75]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}


	if (TextureImage = auxDIBImageLoad("s19.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[76]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("body.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[77]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("soffa.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[78]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}
	if (TextureImage = auxDIBImageLoad("v.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[79]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("almirah.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[80]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("t.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[81]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("g.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[82]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}
	if (TextureImage = auxDIBImageLoad("v.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[83]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}


	if (TextureImage = auxDIBImageLoad("off.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[84]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("food.bmp"))             //OK
	{
		glBindTexture(GL_TEXTURE_2D, texture[85]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("drink.bmp"))            //OK
	{
		glBindTexture(GL_TEXTURE_2D, texture[86]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}
	if (TextureImage = auxDIBImageLoad("rose.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[87]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("steel.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[88]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}

	if (TextureImage = auxDIBImageLoad("drink1.bmp"))
	{
		glBindTexture(GL_TEXTURE_2D, texture[89]);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	}
}

void my_keyboard(unsigned char key, int x, int y)
{

switch (key) {


		case 'z':
        statew=1;
		count=count+1;
		if((count%2)==0)
		 statew=0;
		break;

	   case 'f':
		state2=0;
        fix=1;
		raf=1;
        angle=0;
		break;

	   case 'x':
        state3=1;
		break;

		case 's':
        state=1;
		break;

		case 'n':
		state2=1;
		break;

   case 'd':
	u_p=u_p+3;
	   glutPostRedisplay();
	   break;

	case 'u':
	u_p=u_p-3;
	   glutPostRedisplay();
	   break;

	case 'l':
	  l_t =l_t-3;
	   glutPostRedisplay();
	   break;

   case 'r':
	  l_t =l_t+3;
	   glutPostRedisplay();
	   break;

   case 't':
    b_a = b_a + 3;
    glutPostRedisplay();
	   break;

   case 'p':
    b_a = b_a - 3;
    glutPostRedisplay();
	   break;

	  default:
			break;

	}
}

void changeSize(int w1, int h1)
{
    if(h1 == 0)
        h1 = 1;

    w = w1;
    h = h1;
    ratio = 1.0f * w / h;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
        gluPerspective(45,ratio,0.1,1000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(x, y, z,
              x + lx, y + ly, z + lz,
              0.0f,1.0f,0.0f);
}

void arts()
{
	glBegin(GL_QUADS);
		glColor3f(1.0f,1.0f,1.0f);
		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 5.0f, 5.0f, 5.0f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-5.0f, 5.0f, 5.0f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-5.0f,-5.0f, 5.0f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 5.0f,-5.0f, 5.0f);                   // Bottom Right Of The Quad (Front)
	glEnd();
}

void InnerWindow()
{
    glBegin(GL_QUADS);
        glBindTexture(GL_TEXTURE_2D, texture[4]);
		glColor3f(1.0f,1.0f,1.0f);
		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 2.0f, 2.0f, 3.0f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-2.0f, 2.0f, 3.0f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-2.0f,-2.0f, 3.0f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 2.0f,-2.0f, 3.0f);                   // Bottom Right Of The Quad (Front)
	glEnd();
}

void Front_Window()
{
	glBegin(GL_QUADS);
		glColor3f(0.0/255.0,255.0/255.0, 0.0/255.0);
		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 5.0f, 5.0f, -13.0f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-5.0f, 5.0f, -13.0f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-5.0f,-5.0f, 5.0f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 5.0f,-5.0f, 5.0f);                   // Bottom Right Of The Quad (Front)
	glEnd();
}

void light()
{
	glBindTexture(GL_TEXTURE_2D, texture[51]);
	glBegin(GL_QUADS);
		glColor3f(1.0f,1.0f,1.0f);
		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 5.0f, 1.5f, 5.0f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-5.0f, 1.5f, 5.0f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-5.0f,-0.5f, 5.0f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 5.0f,-0.5f, 5.0f);                   // Bottom Right Of The Quad (Front)
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texture[50]);
	glBegin(GL_QUADS);

	    glTexCoord2f(0.0f, 0.0f);		glVertex3f(5.0f, 1.5f,7.0f);					// Top Right Of The Quad (Top)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-5.0f, 1.5f,7.0f);					// Top Left Of The Quad (Top)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-5.0f, 1.5f,5.0f);					// Bottom Left Of The Quad (Top)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(5.0f, 1.5f, 5.0f);					// Bottom Right Of The Quad (Top)

	    glTexCoord2f(0.0f, 0.0f);		glVertex3f(5.0f, -0.5f,7.0f);					// Top Right Of The Quad (Top)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-5.0f, -0.5f,7.0f);					// Top Left Of The Quad (Top)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-5.0f, -0.5f,5.0f);					// Bottom Left Of The Quad (Top)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(5.0f, -0.5f, 5.0f);					// Bottom Right Of The Quad (Top)

	glEnd();
	glBindTexture(GL_TEXTURE_2D, texture[3]);
	glBegin(GL_QUADS);

		glTexCoord2f(0.0f, 0.0f);		glVertex3f(5.0f, 1.5f, 7.0f);					// Top Right Of The Quad (Left)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(5.0f, 1.5f,5.0f);					// Top Left Of The Quad (Left)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(5.0f,-.5f,5.0f);					// Bottom Left Of The Quad (Left)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(5.0f,-.5f, 7.0f);

		glTexCoord2f(0.0f, 0.0f);		glVertex3f(-5.0f, 1.5f, 7.0f);					// Top Right Of The Quad (Left)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-5.0f, 1.5f,5.0f);					// Top Left Of The Quad (Left)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-5.0f,-.5f,5.0f);					// Bottom Left Of The Quad (Left)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(-5.0f,-.5f, 7.0f);

	glEnd();

}

void ac()
{

      	glBindTexture(GL_TEXTURE_2D, texture[13]);
	glBegin(GL_QUADS);
		glColor3f(1.0f,1.0f,1.0f);
		glTexCoord2f(1.0f, 1.0f);		glVertex3f( 5.0f, 2.5f, 5.0f);					// Top Right Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(-5.0f, 2.5f, 5.0f);					// Top Left Of The Quad (Front)
		glTexCoord2f(0.0f, 0.0f);		glVertex3f(-5.0f,-2.5f, 5.0f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f( 5.0f,-2.5f, 5.0f);                   // Bottom Right Of The Quad (Front)

		glEnd();

	glBindTexture(GL_TEXTURE_2D, texture[52]);
	glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 1.0f);		glVertex3f( 5.0f, 2.5f, 6.0f);					// Top Right Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(-5.0f, 2.5f, 6.0f);					// Top Left Of The Quad (Front)
		glTexCoord2f(0.0f, 0.0f);		glVertex3f(-5.0f,2.5f, 5.0f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f( 5.0f,2.5f, 5.0f);                   // Bottom Right Of The Quad (Front)

		glTexCoord2f(1.0f, 1.0f);		glVertex3f( 5.0f, -2.5f, 6.0f);					// Top Right Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(-5.0f, -2.5f, 6.0f);					// Top Left Of The Quad (Front)
		glTexCoord2f(0.0f, 0.0f);		glVertex3f(-5.0f,-2.5f, 5.0f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f( 5.0f,-2.5f, 5.0f);                   // Bottom Right Of The Quad (Front)


	glEnd();
	glBindTexture(GL_TEXTURE_2D, texture[52]);
	glBegin(GL_QUADS);

		glTexCoord2f(1.0f, 1.0f);		glVertex3f( 5.0f, 2.5f, 6.0f);					// Top Right Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(5.0f, 2.5f, 5.0f);					// Top Left Of The Quad (Front)
		glTexCoord2f(0.0f, 0.0f);		glVertex3f(5.0f,-2.5f, 5.0f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f( 5.0f,-2.5f, 6.0f);

		glTexCoord2f(1.0f, 1.0f);		glVertex3f(- 5.0f, 2.5f, 6.0f);					// Top Right Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(-5.0f, 2.5f, 5.0f);					// Top Left Of The Quad (Front)
		glTexCoord2f(0.0f, 0.0f);		glVertex3f(-5.0f,-2.5f, 5.0f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(- 5.0f,-2.5f, 6.0f);

	glEnd();


}

void tab()
{
	glBindTexture(GL_TEXTURE_2D, texture[58]);
	glBegin(GL_QUADS);

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 9.2f, 0.5f,-4.5f);					// Top Right Of The Quad (Top)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(5.2f, 0.5f,-4.5f);					// Top Left Of The Quad (Top)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(5.2f, 0.5f, 4.5f);					// Bottom Left Of The Quad (Top)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 9.2f, 0.5f, 4.5f);					// Bottom Right Of The Quad (Top)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 9.2f,-0.5f, 4.5f);					// Top Right Of The Quad (Bottom)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(5.2f,-0.5f, 4.5f);					// Top Left Of The Quad (Bottom)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(5.2f,-0.5f,-4.50f);					// Bottom Left Of The Quad (Bottom)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 9.2f,-0.5f,-4.5f);					// Bottom Right Of The Quad (Bottom)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 9.2f, 0.5f, 4.5f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(5.2f, 0.5f, 4.5f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(5.2f,-0.5f, 4.5f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 9.2f,-0.5f, 4.5f);					// Bottom Right Of The Quad (Front)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 9.2f,-0.5f,-4.5f);					// Top Right Of The Quad (Back)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(5.2f,-0.5f,-4.5f);					// Top Left Of The Quad (Back)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(5.2f, 0.5f,-4.5f);					// Bottom Left Of The Quad (Back)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 9.2f, 0.5f,-4.5f);					// Bottom Right Of The Quad (Back)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f(5.2f, 0.5f, 4.5f);					// Top Right Of The Quad (Left)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(5.2f, 0.5f,-4.5f);					// Top Left Of The Quad (Left)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(5.2f,-0.5f,-4.5f);					// Bottom Left Of The Quad (Left)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(5.2f,-0.5f, 4.5f);					// Bottom Right Of The Quad (Left)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 9.2f, 0.5f,-4.5f);					// Top Right Of The Quad (Right)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f( 9.2f, 0.5f, 4.5f);					// Top Left Of The Quad (Right)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f( 9.2f,-0.5f,4.5f);					// Bottom Left Of The Quad (Right)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 9.2f,-0.5f,-4.5f);					// Bottom Left Of The Quad (Right)
	glEnd();
}

void table()
{
glBindTexture(GL_TEXTURE_2D, texture[52]);

glBegin(GL_QUADS);


		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 0.2f, 23.5f,-0.2f);					// Top Right Of The Quad (Top)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-0.2f, 23.5f,-0.2f);					// Top Left Of The Quad (Top)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-0.2f, 23.5f, 0.2f);					// Bottom Left Of The Quad (Top)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 0.2f, 23.5f, 0.2f);					// Bottom Right Of The Quad (Top)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 0.2f,0.1f, 0.2f);					// Top Right Of The Quad (Bottom)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-0.2f,0.1f, 0.2f);					// Top Left Of The Quad (Bottom)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-0.2f,0.1f,-0.20f);					// Bottom Left Of The Quad (Bottom)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 0.2f,0.1f,-0.2f);					// Bottom Right Of The Quad (Bottom)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 0.2f, 23.5f, 0.2f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-0.2f, 23.5f, 0.2f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-0.2f,0.1f, 0.2f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 0.2f,0.1f, 0.2f);					// Bottom Right Of The Quad (Front)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 0.2f,0.1f,-0.2f);					// Top Right Of The Quad (Back)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-0.2f,0.1f,-0.2f);					// Top Left Of The Quad (Back)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-0.2f, 23.5f,-0.2f);					// Bottom Left Of The Quad (Back)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 0.2f, 23.5f,-0.2f);					// Bottom Right Of The Quad (Back)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f(-0.2f, 23.5f, 0.2f);					// Top Right Of The Quad (Left)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-0.2f, 23.5f,-0.2f);					// Top Left Of The Quad (Left)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-0.2f,0.1f,-0.2f);					// Bottom Left Of The Quad (Left)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(-0.2f,0.1f, 0.2f);					// Bottom Right Of The Quad (Left)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 0.2f, 23.5f,-0.2f);					// Top Right Of The Quad (Right)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f( 0.2f, 23.5f, 0.2f);					// Top Left Of The Quad (Right)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f( 0.2f,0.1f, 0.2f);					// Bottom Left Of The Quad (Right)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 0.2f,0.1f,-0.2f);						// Bottom Right Of The Quad (Top)
	glEnd();
}

void top()
{
    glBindTexture(GL_TEXTURE_2D, texture[54]);
   	glBegin(GL_QUADS);

		glColor3f(1.0f,1.0f,1.0f);
		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 1.2f, 0.9f,-2.5f);					// Top Right Of The Quad (Top)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-1.2f, 0.9f,-2.5f);					// Top Left Of The Quad (Top)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-1.2f, 0.9f, 2.5f);					// Bottom Left Of The Quad (Top)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 1.2f, 0.9f, 2.5f);					// Bottom Right Of The Quad (Top)

		glVertex3f( 1.2f,-0.1f, 2.5f);					// Top Right Of The Quad (Bottom)
		glVertex3f(-1.2f,-0.1f, 2.5f);					// Top Left Of The Quad (Bottom)
		glVertex3f(-1.2f,-0.1f,-2.50f);					// Bottom Left Of The Quad (Bottom)
		glVertex3f( 1.2f,-0.1f,-2.5f);					// Bottom Right Of The Quad (Bottom)

		glColor3f(1.0f,1.0f,1.0f);
		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 1.2f, 0.9f, 2.5f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-1.2f, 0.9f, 2.5f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-1.2f,-0.1f, 2.5f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 1.2f,-0.1f, 2.5f);					// Bottom Right Of The Quad (Front)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 1.2f,-0.1f,-2.5f);					// Top Right Of The Quad (Back)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-1.2f,-0.1f,-2.5f);					// Top Left Of The Quad (Back)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-1.2f, 0.9f,-2.5f);					// Bottom Left Of The Quad (Back)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 1.2f, 0.9f,-2.5f);					// Bottom Right Of The Quad (Back)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f(-1.2f, 0.9f, 2.5f);					// Top Right Of The Quad (Left)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-1.2f, 0.9f,-2.5f);					// Top Left Of The Quad (Left)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-1.2f,-0.1f,-2.5f);					// Bottom Left Of The Quad (Left)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(-1.2f,-0.1f, 2.5f);					// Bottom Right Of The Quad (Left)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 1.2f, 0.9f,-2.5f);					// Top Right Of The Quad (Right)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f( 1.2f, 0.9f, 2.5f);					// Top Left Of The Quad (Right)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f( 1.2f,-0.1f, 2.5f);					// Bottom Left Of The Quad (Right)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 1.2f,-0.1f,-2.5f);					// Bottom Left Of The Quad (Right)
	glEnd();

}

void leftwall()
{

		glBindTexture(GL_TEXTURE_2D, texture[1]);
		glBegin(GL_QUADS);
		glColor3f(1.0f,1.0f,1.0f);

		glTexCoord2f(0.0f, 0.0f);		glVertex3f(70.0f, 15.0f, 80.0f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(35.0f, 15.0f, 80.0f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(35.0f, 5.0f, 100.0f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(70.0f, 5.0f, 100.0f);

        glTexCoord2f(0.0f, 0.0f);		glVertex3f(70.0f, 5.0f, 100.0f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(35.0f, 5.0f, 100.0f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(35.0f, -5.0f, 80.0f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(70.0f, -5.0f, 80.0f);

		glTexCoord2f(0.0f, 0.0f);		glVertex3f(70.0f, 17.f, 79.0f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(35.0f, 17.3f, 79.0f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(35.0f,  5.0f, 102.0f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(70.0f,  5.0f, 102.0f);

		glTexCoord2f(0.0f, 0.0f);		glVertex3f(70.0f, 5.0f, 102.0f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(35.0f, 5.0f, 102.0f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(35.0f, -5.0f, 79.0f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(70.0f, -5.0f, 79.0f);

       // glBindTexture(GL_TEXTURE_2D, texture[47]);
       /* glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f);		glVertex3f( -80.0f, 8.7f, 72.0f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-80.0f, 8.7f, 70.0f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-80.0f, - 11.1f, 70.0f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( -80.0f, - 11.1f, 72.0f);

        glTexCoord2f(0.0f, 0.0f);		glVertex3f(80.0f, 8.7f, 72.0f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(80.0f, 8.7f, 70.0f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(80.0f, - 11.1f, 70.0f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(80.0f, - 11.1f, 72.0f);

		glEnd();*/

    glBegin(GL_QUADS);

/*glColor3f(1.0, 0.0, 0.0);
        glTexCoord2f(0.0f, 1.0f);		glVertex3f(90.0f, 5.0f, 79.0f);
        glTexCoord2f(0.0f, 0.0f);		glVertex3f(70.0f, 5.0f, 102.0f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(70.0f, 5.0f, 79.0f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f( 70.0f, -5.0f, 102.0f);					// Bottom Left Of The Quad (Front)
        glEnd();*/

    glEnd();
}

void inleft()
{

	    glPushMatrix();
	    glTranslatef(10.0f, 15.0f, -40.0);
		glBindTexture(GL_TEXTURE_2D, texture[77]);
		glBegin(GL_QUADS);
		glColor3f(1.0f,1.0f,1.0f);
		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 40.0f, 8.7f, 70.0f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(28.0f, 8.7f, 70.0f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(28.0f,-11.5f, 70.0f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 42.0f,-11.5f, 70.0f);

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 42.0f, 8.7f, 71.0f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(28.0f, 8.7f, 71.0f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(28.0f,-11.5f, 71.0f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 42.0f,-11.5f, 71.0f);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, texture[47]);
        glBegin(GL_QUADS);
		glColor3f(1.0f,1.0f,1.0f);
		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 40.0f, -11.5f, 71.0f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(40.0f,-11.5f, 70.0f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(40.0f,8.7f, 70.0f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 40.0f,8.7f, 71.0f);

		glColor3f(1.0f,1.0f,1.0f);
		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 28.0f,-11.5f, 71.0f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(28.0f, -11.5f, 70.0f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(28.0f,8.7f, 70.0f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 28.0f,8.7f, 71.0f);
		glEnd();

	    glPopMatrix();

	    glPushMatrix();
	    glTranslatef(10.0f, 15.0f, -40.0);
		glBindTexture(GL_TEXTURE_2D, texture[77]);
		glBegin(GL_QUADS);
	    glTexCoord2f(0.0f, 0.0f);		glVertex3f( 16.0f, 8.7f, 70.0f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(6.6f, 8.7f, 70.0f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(6.6f,-11.5f, 70.0f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 16.0f,-11.5f, 70.0f);

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 16.0f, 8.7f, 71.0f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(6.6f, 8.7f, 71.0f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(6.6f,-11.5f, 71.0f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 16.0f,-11.5f, 71.0f);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, texture[47]);
        glBegin(GL_QUADS);
		glColor3f(1.0f,1.0f,1.0f);
		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 16.0f, -11.5f, 71.0f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(16.0f,-11.5f, 70.0f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(16.0f,8.7f, 70.0f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 16.0f,8.7f, 71.0f);

		glColor3f(1.0f,1.0f,1.0f);
		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 6.6f,-11.5f, 71.0f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(6.6f, -11.5f, 70.0f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(6.6f,8.7f, 70.0f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 6.6f,8.7f, 71.0f);
		glEnd();


		glPopMatrix();
}

void rightwall()
{
        glBindTexture(GL_TEXTURE_2D, texture[0]);
		glBegin(GL_QUADS);
		glColor3f(1.0f,1.0f,1.0f);
		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 70.0f, 5.0f, -100.0f);					// Top Right Of The Quad (Back)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(35.0f, 5.0f, -100.0f);					// Top Left Of The Quad (Back)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(35.0f, 15.0f, -80.0f);					// Bottom Left Of The Quad (Back)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 70.0f, 15.0f, -80.0f);

		glColor3f(1.0f,1.0f,1.0f);
		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 70.0f, -5.0f,-80.0f);					// Top Right Of The Quad (Back)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(35.0f, -5.0f,-80.0f);					// Top Left Of The Quad (Back)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(35.0f, 5.0f,-100.0f);					// Bottom Left Of The Quad (Back)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 70.0f, 5.0f,-100.0f);
        glEnd();
}

void inright()
{
    glPushMatrix();
	    glTranslatef(10.0f, 15.0f, -40.0);
		glBindTexture(GL_TEXTURE_2D, texture[77]);
		glBegin(GL_QUADS);

		glColor3f(1.0f,1.0f,1.0f);
		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 40.0f, 8.7f, 15.0f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(27.0f, 8.7f, 15.0f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(27.0f,-11.5f, 15.0f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 42.0f,-11.5f, 15.0f);

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 42.0f, 8.7f, 16.0f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(27.0f, 8.7f, 16.0f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(27.0f,-11.5f, 16.0f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 42.0f,-11.5f, 16.0f);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, texture[47]);
        glBegin(GL_QUADS);

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 40.0f, -11.5f, 16.0f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(40.0f,-11.5f, 15.0f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(40.0f,8.7f, 15.0f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 40.0f,8.7f, 16.0f);

	   glColor3f(1.0f,1.0f,1.0f);
		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 27.0f,-11.5f, 16.0f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(27.0f, -11.5f, 15.0f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(27.0f,8.7f, 15.0f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 27.0f,8.7f, 16.0f);
		glEnd();

	    glPopMatrix();

        glPushMatrix();
	    glTranslatef(10.0f, 15.0f, -40.0);
		glBindTexture(GL_TEXTURE_2D, texture[77]);
		glBegin(GL_QUADS);

	    glTexCoord2f(0.0f, 0.0f);		glVertex3f(18.2f, 8.7f, 15.0f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(6.6f, 8.7f, 15.0f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(6.6f,-11.5f, 15.0f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(18.2f,-11.5f, 15.0f);

		glTexCoord2f(0.0f, 0.0f);		glVertex3f(18.2f, 8.7f, 16.0f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(6.6f, 8.7f, 16.0f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(6.6f,-11.5f, 16.0f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(18.2f,-11.5f, 16.0f);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, texture[47]);
        glBegin(GL_QUADS);

		glColor3f(1.0f,1.0f,1.0f);
		glTexCoord2f(0.0f, 0.0f);		glVertex3f(18.2f, -11.5f, 16.0f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(18.2f,-11.5f, 15.0f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(18.2f,8.0f, 15.0f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(18.2f,8.0f, 16.0f);

		glColor3f(1.0f,1.0f,1.0f);
		glTexCoord2f(0.0f, 0.0f);		glVertex3f(6.6f,-11.5f, 16.0f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(6.6f, -11.5f, 15.0f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(6.6f, 8.0f, 15.0f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(6.6f,8.0f, 16.0f);
		glEnd();

		glPopMatrix();


}

void frontwall()
{
		glBindTexture(GL_TEXTURE_2D, texture[5]);
		glBegin(GL_QUADS);
		glColor3f(1.0f,1.0f,1.0f);
		glTexCoord2f(0.0f, 0.0f);		glVertex3f(38.0f, 15.0f, 80.0f);					// Top Right Of The Quad (Left)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(38.0f, 15.0f,-100.0f);					// Top Left Of The Quad (Left)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(34.0f, 5.0f,-100.05f);					// Bottom Left Of The Quad (Left)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(34.0f, 5.0f, 80.0f);

		glTexCoord2f(0.0f, 0.0f);		glVertex3f(34.0f, 5.0f, 80.0f);					// Top Right Of The Quad (Left)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(34.0f, 5.0f,-100.0f);					// Top Left Of The Quad (Left)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(38.0f, -5.0f,-100.05f);					// Bottom Left Of The Quad (Left)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(38.0f, -5.0f, 80.0f);

		/*glTexCoord2f(0.0f, 0.0f);		glVertex3f(-82.0f, 8.7f, 70.0f);					// Top Right Of The Quad (Left)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-82.0f, 8.7f,-70.0f);					// Top Left Of The Quad (Left)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-82.0f,-8.7f,-70.05f);					// Bottom Left Of The Quad (Left)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(-82.0f,-8.7f, 70.0f);
        glEnd();*/

        glBindTexture(GL_TEXTURE_2D, texture[47]);

        glBegin(GL_QUADS);
		glColor3f(1.0f,1.0f,1.0f);
		/*glTexCoord2f(0.0f, 0.0f);		glVertex3f(-82.0f,8.7f,- 70.0f);					// Top Right Of The Quad (Left)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-80.0f, 8.7f,-70.0f);					// Top Left Of The Quad (Left)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-80.0f,-11.1f,-70.05f);					// Bottom Left Of The Quad (Left)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(-82.0f,-11.1f, -70.0f);

		glTexCoord2f(0.0f, 0.0f);		glVertex3f(-82.0f, 8.7f,70.0f);					// Top Right Of The Quad (Left)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-80.0f, 8.7f,70.0f);					// Top Left Of The Quad (Left)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-80.0f,-11.1f,70.05f);					// Bottom Left Of The Quad (Left)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(-82.0f,-11.1f, 70.0f);*/
		glEnd();
		glPopMatrix();
}

void ground()
{
    glBindTexture(GL_TEXTURE_2D, texture[0]);
		glBegin(GL_QUADS);
		glColor3f(1.0f,1.0f,1.0f);
		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 70.0f, -5.0f, 80.0f);					// Top Right Of The Quad (Bottom)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f( 37.0f, -5.0f, 80.0f);					// Top Left Of The Quad (Bottom)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f( 37.0f, -5.0f, -70.0f);					// Bottom Left Of The Quad (Bottom)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 70.0f, -5.0f, -70.0f);
		glEnd();

      /*glBindTexture(GL_TEXTURE_2D, texture[46]);

        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f);		glVertex3f(-82.0f, -8.65f, 70.0f);					// Top Right Of The Quad (Left)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-82.0f, -8.65f,-70.0f);					// Top Left Of The Quad (Left)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-82.0f,-12.1f,-70.05f);					// Bottom Left Of The Quad (Left)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(-82.0f,-12.1f, 70.0f);

        glTexCoord2f(0.0f, 0.0f);		glVertex3f(80.0f, -7.95f, 70.0f);					// Top Right Of The Quad (Left)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(80.0f, -7.95f,-70.0f);					// Top Left Of The Quad (Left)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(80.0f,-12.1f,-70.05f);					// Bottom Left Of The Quad (Left)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(80.0f,-12.1f, 70.0f);

        glTexCoord2f(0.0f, 0.0f);		glVertex3f( 80.0f, -8.7f, 72.0f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-80.0f, -8.7f, 72.0f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-80.0f, -12.1f, 72.0f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 80.0f, -12.1f, 72.0f);

        glColor3f(1.0f,1.0f,1.0f);
		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 80.0f,-8.7f,-72.0f);					// Top Right Of The Quad (Back)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-80.0f,-8.7f,-72.0f);					// Top Left Of The Quad (Back)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-80.0f, -12.1f,-72.0f);					// Bottom Left Of The Quad (Back)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 80.0f, -12.1f,-72.0f);

        glEnd();*/
}

void roof()
{
		glBindTexture(GL_TEXTURE_2D, texture[0]);
		glBegin(GL_QUADS);
		glColor3f(1.0f,1.0f,1.0f);
		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 70.0f, 15.0f, -80.0f);					// Top Right Of The Quad (Top)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(35.0f, 15.0f, -80.0f);					// Top Left Of The Quad (Top)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(35.0f, 15.0f, 80.0f);					// Bottom Left Of The Quad (Top)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 70.0f, 15.0f, 80.0f);

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 70.0f, 17.2f,-80.0f);					// Top Right Of The Quad (Top)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(35.0f, 17.2f,-80.0f);					// Top Left Of The Quad (Top)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(35.0f, 17.2f, 80.0f);					// Bottom Left Of The Quad (Top)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 70.0f, 17.2f, 80.0f);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, texture[0]);
        glBegin(GL_QUADS);

        glTexCoord2f(0.0f, 0.0f);		glVertex3f(35.0f, 15.0f, 80.0f);					// Top Right Of The Quad (Left)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(35.0f, 15.0f,-80.0f);					// Top Left Of The Quad (Left)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(35.0f,17.2f,-80.05f);					// Bottom Left Of The Quad (Left)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(35.0f,17.2f, 80.0f);

        glTexCoord2f(0.0f, 0.0f);		glVertex3f(70.0f, 15.0f, 80.0f);					// Top Right Of The Quad (Left)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(70.0f, 15.0f,-80.0f);					// Top Left Of The Quad (Left)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(70.0f,17.2f,-80.05f);					// Bottom Left Of The Quad (Left)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(70.0f,17.2f, 80.0f);

        glTexCoord2f(0.0f, 0.0f);		glVertex3f( 70.0f, 15.0f, 80.0f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(35.0f, 15.0f, 80.0f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(35.0f, 17.2f, 80.0f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 70.0f, 17.2f, 80.0f);

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 70.0f,15.0f,-80.0f);					// Top Right Of The Quad (Back)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(35.0f,15.0f,-80.0f);					// Top Left Of The Quad (Back)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(35.0f, 17.2f,-80.0f);					// Bottom Left Of The Quad (Back)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 70.0f, 17.2f,-80.0f);
		glEnd();

}

void welcome()
{
		glBindTexture(GL_TEXTURE_2D, texture[4]);
		glBegin(GL_QUADS);
		glColor3f(1.0f,1.0f,1.0f);
		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 90.0f, 18.9f,-60.0f);					// Top Right Of The Quad (Top)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f( 89.0f, 18.9f,-60.0f);					// Top Left Of The Quad (Top)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(89.0f, 18.9f, -40.0f);					// Bottom Left Of The Quad (Top)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 90.0f, 18.9f, -40.0f);

        glColor3f(1.0f,1.0f,1.0f);
		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 90.0f, 11.1f,-60.0f);					// Top Right Of The Quad (Top)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(89.0f, 11.1f,-60.0f);					// Top Left Of The Quad (Top)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(89.0f, 11.1f, -40.0f);					// Bottom Left Of The Quad (Top)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 90.0f, 11.1f, -40.0f);
        glEnd();

 glBindTexture(GL_TEXTURE_2D, texture[85]);
        glBegin(GL_QUADS);

        glTexCoord2f(0.0f, 0.0f);		glVertex3f(89.0f,11.1f,-40.0f);					// Top Right Of The Quad (Left)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(89.0f,11.1f,-60.0f);					// Top Left Of The Quad (Left)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(89.0f,18.9f,-60.0f);					// Bottom Left Of The Quad (Left)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(89.0f,18.9f,-40.0f);

        glTexCoord2f(0.0f, 0.0f);		glVertex3f(90.0f, 11.1f,-40.0f);					// Top Right Of The Quad (Left)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(90.0f, 11.1f,-60.0f);					// Top Left Of The Quad (Left)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(90.0f,18.9f,-60.0f);					// Bottom Left Of The Quad (Left)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(90.0f,18.9f,-40.0f);

        glTexCoord2f(0.0f, 0.0f);		glVertex3f( 90.0f, 11.1f,-40.0f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(89.0f, 11.1f,-40.0f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(89.0f, 18.9f,-40.0f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 90.0f,18.9f,-40.0f);

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 90.0f,11.1f,-60.0f);					// Top Right Of The Quad (Back)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(89.0f,11.1f,-60.0f);					// Top Left Of The Quad (Back)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(89.0f, 18.9f,-60.0f);					// Bottom Left Of The Quad (Back)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 90.0f, 18.9f,-60.0f);
		glEnd();
}

void welcome1()
{
		glBindTexture(GL_TEXTURE_2D, texture[4]);
		glBegin(GL_QUADS);
		glColor3f(1.0f,1.0f,1.0f);
		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 90.0f, 24.9f,-70.0f);					// Top Right Of The Quad (Top)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f( 89.0f, 24.9f,-70.0f);					// Top Left Of The Quad (Top)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(89.0f, 24.9f, -40.0f);					// Bottom Left Of The Quad (Top)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 90.0f, 24.9f, -40.0f);

        glColor3f(1.0f,1.0f,1.0f);
		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 90.0f, 11.1f,-70.0f);					// Top Right Of The Quad (Top)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(89.0f, 11.1f,-70.0f);					// Top Left Of The Quad (Top)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(89.0f, 11.1f, -40.0f);					// Bottom Left Of The Quad (Top)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 90.0f, 11.1f, -40.0f);
        glEnd();

 glBindTexture(GL_TEXTURE_2D, texture[86]);
        glBegin(GL_QUADS);

        glTexCoord2f(0.0f, 0.0f);		glVertex3f(89.0f,11.1f,-30.0f);					// Top Right Of The Quad (Left)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(89.0f,11.1f,-70.0f);					// Top Left Of The Quad (Left)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(89.0f,24.9f,-70.0f);					// Bottom Left Of The Quad (Left)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(89.0f,24.9f,-30.0f);

        glTexCoord2f(0.0f, 0.0f);		glVertex3f(90.0f, 11.1f,-30.0f);					// Top Right Of The Quad (Left)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(90.0f, 11.1f,-70.0f);					// Top Left Of The Quad (Left)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(90.0f,24.9f,-70.0f);					// Bottom Left Of The Quad (Left)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(90.0f,24.9f,-30.0f);

        glTexCoord2f(0.0f, 0.0f);		glVertex3f( 90.0f, 11.1f,-30.0f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(89.0f, 11.1f,-30.0f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(89.0f, 24.9f,-30.0f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 90.0f,24.9f,-30.0f);

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 90.0f,11.1f,-70.0f);					// Top Right Of The Quad (Back)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(89.0f,11.1f,-70.0f);					// Top Left Of The Quad (Back)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(89.0f, 24.9f,-70.0f);					// Bottom Left Of The Quad (Back)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 90.0f,24.9f,-70.0f);
		glEnd();
}

void backwall()
{

  glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, texture[5]);
		glTranslatef(10.0f,8.2f,50.0f);
        glColor3f(1.0f,0.0f,0.0f);

		/*glTexCoord2f(0.0f, 0.0f);		glVertex3f(70.0f, 20.0f, 19.75f);					// Top Right Of The Quad (Left)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(70.0f, 20.0f,-19.75f);					// Top Left Of The Quad (Left)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(70.0f, 4.0f,-19.75f);					// Bottom Left Of The Quad (Left)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(70.0f, 4.0f, 19.75f);*/
/*glTexCoord2f(0.0f, 0.0f);		glVertex3f(0.0f, 20.0f, 80.0f);					// Top Right Of The Quad (Left)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(0.0f, 20.0f,-80.0f);					// Top Left Of The Quad (Left)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-10.0f, 10.0f,-80.05f);					// Bottom Left Of The Quad (Left)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(-10.0f, 10.0f, 80.0f);

		glTexCoord2f(0.0f, 0.0f);		glVertex3f(-10.0f, 10.0f, 80.0f);					// Top Right Of The Quad (Left)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-10.0f, 10.0f,-80.0f);					// Top Left Of The Quad (Left)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(0.0f, 0.0f,-80.05f);					// Bottom Left Of The Quad (Left)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(0.0f, 0.0f, 80.0f);*/

		glBegin(GL_QUADS);
		glColor3f(1.0f,1.0f,1.0f);
		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 40.0f, 15.0f, -150.0f);					// Top Right Of The Quad (Right)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(40.0f, 15.0f, 30.0f);					// Top Left Of The Quad (Right)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f( 42.0f, -5.0f, 30.0f);					// Bottom Left Of The Quad (Right)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 42.0f, -5.0f, -150.0f);               // Bottom Right Of The Quad (Right)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 42.0f, -1.0f, -150.0f);					// Top Right Of The Quad (Right)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f( 42.0f, -1.0f, 30.0f);					// Top Left Of The Quad (Right)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f( 40.0f, -5.0f, 30.0f);					// Bottom Left Of The Quad (Right)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 40.0f, -5.0f, -150.0f);               // Bottom Right Of The Quad (Right)
	glEnd();

	  /* glBindTexture(GL_TEXTURE_2D, texture[47]);
		glBegin(GL_QUADS);
		glColor3f(1.0f,1.0f,1.0f);						// Set The Color To Violet
		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 40.0f, 8.9f,-19.75f);					// Top Right Of The Quad (Right)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(39.0f, 8.9f, -19.75f);					// Top Left Of The Quad (Right)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f( 39.0f,-8.9f,- 19.75f);					// Bottom Left Of The Quad (Right)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 40.0f,-8.9f,-19.75f);               // Bottom Right Of The Quad (Right)


	glEnd();*/

	glPopMatrix();
}

void chair()
{
  glBindTexture(GL_TEXTURE_2D, texture[10]);

	glBegin(GL_QUADS);

		glColor3f(1.0f,1.0f,1.0f);
		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 0.2f, 0.5f,-0.2f);					// Top Right Of The Quad (Top)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-0.2f, 0.5f,-0.2f);					// Top Left Of The Quad (Top)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-0.2f, 0.5f, 0.5f);					// Bottom Left Of The Quad (Top)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 0.2f, 0.5f, 0.5f);					// Bottom Right Of The Quad (Top)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 0.2f,-8.3f, 0.5f);					// Top Right Of The Quad (Bottom)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-0.2f,-8.3f, 0.5f);					// Top Left Of The Quad (Bottom)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-0.2f,-8.3f,-0.2f);					// Bottom Left Of The Quad (Bottom)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 0.2f,-8.3f,-0.2f);					// Bottom Right Of The Quad (Bottom)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 0.2f, 0.5f, 0.5f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-0.2f, 0.5f, 0.5f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-0.2f,-8.3f, 0.5f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 0.2f,-8.3f, 0.5f);					// Bottom Right Of The Quad (Front)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 0.2f,-8.3f,-0.2f);					// Top Right Of The Quad (Back)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-0.2f,-8.3f,-0.2f);					// Top Left Of The Quad (Back)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-0.2f, 0.5f,-0.2f);					// Bottom Left Of The Quad (Back)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 0.2f, 0.5f,-0.2f);					// Bottom Right Of The Quad (Back)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f(-0.2f, 0.5f, 0.5f);					// Top Right Of The Quad (Left)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-0.2f, 0.5f,-0.2f);					// Top Left Of The Quad (Left)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-0.2f,-8.3f,-0.2f);					// Bottom Left Of The Quad (Left)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(-0.2f,-8.3f, 0.5f);					// Bottom Right Of The Quad (Left)


		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 0.2f, 0.5f,-0.2f);					// Top Right Of The Quad (Right)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f( 0.2f, 0.5f, 0.5f);					// Top Left Of The Quad (Right)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f( 0.2f,-8.3f, 0.5f);					// Bottom Left Of The Quad (Right)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 0.2f,-8.3f,-0.2f);						// Bottom Right Of The Quad (Top)
	glEnd();
}

void Sofa()
{
    glBindTexture(GL_TEXTURE_2D, texture[54]);
   	glBegin(GL_QUADS);

		glColor3f(1.0f,1.0f,1.0f);
		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 3.0f, 0.9f,-2.5f);					// Top Right Of The Quad (Top)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-1.2f, 0.9f,-2.5f);					// Top Left Of The Quad (Top)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-1.2f, 0.9f, 7.0f);					// Bottom Left Of The Quad (Top)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 3.0f, 0.9f, 7.0f);					// Bottom Right Of The Quad (Top)

		glVertex3f( 3.0f,-0.7f, 7.0f);					// Top Right Of The Quad (Bottom)
		glVertex3f(-1.2f,-0.7f, 7.0f);					// Top Left Of The Quad (Bottom)
		glVertex3f(-1.2f,-0.7f,-2.50f);					// Bottom Left Of The Quad (Bottom)
		glVertex3f( 3.0f,-0.7f,-2.5f);					// Bottom Right Of The Quad (Bottom)

		glColor3f(1.0f,1.0f,1.0f);
		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 3.0f, 0.9f, 7.0f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-1.2f, 0.9f, 7.0f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-1.2f,-0.7f, 7.0f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 3.0f,-0.7f, 7.0f);					// Bottom Right Of The Quad (Front)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 3.0f,-0.7f,-2.5f);					// Top Right Of The Quad (Back)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-1.2f,-0.7f,-2.5f);					// Top Left Of The Quad (Back)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-1.2f, 0.9f,-2.5f);					// Bottom Left Of The Quad (Back)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 3.0f, 0.9f,-2.5f);					// Bottom Right Of The Quad (Back)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f(-1.2f, 0.9f, 7.0f);					// Top Right Of The Quad (Left)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-1.2f, 0.9f,-2.5f);					// Top Left Of The Quad (Left)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-1.2f,-0.7f,-2.5f);					// Bottom Left Of The Quad (Left)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(-1.2f,-0.7f, 7.0f);					// Bottom Right Of The Quad (Left)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 3.0f, 0.9f,-2.5f);					// Top Right Of The Quad (Right)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f( 3.0f, 0.9f, 7.0f);					// Top Left Of The Quad (Right)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f( 3.0f,-0.7f, 7.0f);					// Bottom Left Of The Quad (Right)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 3.0f,-0.7f,-2.5f);					// Bottom Left Of The Quad (Right)
	glEnd();

}

void SofaStable()
{
    glBindTexture(GL_TEXTURE_2D, texture[54]);
   	glBegin(GL_QUADS);

		glColor3f(1.0f,1.0f,1.0f);
		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 4.0f, 5.5f,-2.5f);					// Top Right Of The Quad (Top)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(3.0f, 5.5f,-2.5f);					// Top Left Of The Quad (Top)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(3.0f, 5.5f, 7.0f);					// Bottom Left Of The Quad (Top)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 4.0f, 5.5f, 7.0f);					// Bottom Right Of The Quad (Top)

		glColor3f(1.0f,1.0f,1.0f);
		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 4.0f, 5.5f, 7.0f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(3.0f, 5.5f, 7.0f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(3.0f,-0.7f, 7.0f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(4.0f,-0.7f, 7.0f);					// Bottom Right Of The Quad (Front)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 4.0f,-0.7f,-2.5f);					// Top Right Of The Quad (Back)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(3.0f,-0.7f,-2.5f);					// Top Left Of The Quad (Back)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(3.0f, 5.5f,-2.5f);					// Bottom Left Of The Quad (Back)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 4.0f, 5.5f,-2.5f);					// Bottom Right Of The Quad (Back)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f(3.0f, 5.5f, 7.0f);					// Top Right Of The Quad (Left)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(3.0f, 5.5f,-2.5f);					// Top Left Of The Quad (Left)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(3.0f,-0.7f,-2.5f);					// Bottom Left Of The Quad (Left)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(3.0f,-0.7f, 7.0f);					// Bottom Right Of The Quad (Left)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 4.0f, 5.5f,-2.5f);					// Top Right Of The Quad (Right)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f( 4.0f, 5.5f, 7.0f);					// Top Left Of The Quad (Right)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f( 4.0f,-0.7f, 7.0f);					// Bottom Left Of The Quad (Right)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 4.0f,-0.7f,-2.5f);					// Bottom Left Of The Quad (Right)
	glEnd();

}

void Handle()
{
    glBindTexture(GL_TEXTURE_2D, texture[54]);
    glBegin(GL_QUADS);
		glColor3f(1.0f,1.0f,1.0f);
		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 4.0f, 2.0f, 6.0f);					// Top Right Of The Quad (Top)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-1.0f, 2.0f, 6.0f);					// Top Left Of The Quad (Top)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-1.0f, 2.0f, 7.0f);					// Bottom Left Of The Quad (Top)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 4.0f, 2.0f, 7.0f);					// Bottom Right Of The Quad (Top)

		glColor3f(1.0f,1.0f,1.0f);
		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 4.0f, 2.0f, 7.0f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-1.0f, 2.0f, 7.0f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-1.0f, 2.5f, 7.0f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(4.0f, 2.5f, 7.0f);					// Bottom Right Of The Quad (Front)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 4.0f, 2.5f,6.0f);					// Top Right Of The Quad (Back)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-1.0f, 2.5f, 6.0f);					// Top Left Of The Quad (Back)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-1.0f, 2.0f, 6.0f);					// Bottom Left Of The Quad (Back)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 4.0f, 2.0f, 6.0f);					// Bottom Right Of The Quad (Back)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f(-1.0f, 2.0f, 7.0f);					// Top Right Of The Quad (Left)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-1.0f, 2.0f, 6.0f);					// Top Left Of The Quad (Left)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-1.0f, 2.5f, 6.0f);					// Bottom Left Of The Quad (Left)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(-1.0f, 2.5f, 7.0f);					// Bottom Right Of The Quad (Left)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 4.0f, 2.0f, 6.0f);					// Top Right Of The Quad (Right)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f( 4.0f, 2.0f, 7.0f);					// Top Left Of The Quad (Right)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f( 4.0f, 2.5f, 7.0f);					// Bottom Left Of The Quad (Right)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 4.0f, 2.5f, 6.0f);					// Bottom Left Of The Quad (Right)
	glEnd();

glBindTexture(GL_TEXTURE_2D, texture[9]);
    glBegin(GL_QUADS);

		glColor3f(1.0f,1.0f,1.0f);
		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 4.0f, 2.0f, 6.4f);					// Top Right Of The Quad (Top)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-1.0f, 2.0f, 6.4f);					// Top Left Of The Quad (Top)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-1.0f, 2.0f, 6.5f);					// Bottom Left Of The Quad (Top)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 4.0f, 2.0f, 6.5f);					// Bottom Right Of The Quad (Top)

		glColor3f(1.0f,1.0f,1.0f);
		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 4.0f, 2.0f, 6.5f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-1.0f, 2.0f, 6.5f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-1.0f, 0.9f, 6.5f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(4.0f, 0.9f, 6.5f);					// Bottom Right Of The Quad (Front)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 4.0f, 0.9f,6.4f);					// Top Right Of The Quad (Back)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-1.0f, 0.9f, 6.4f);					// Top Left Of The Quad (Back)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-1.0f, 2.0f, 6.4f);					// Bottom Left Of The Quad (Back)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 4.0f, 2.0f, 6.4f);					// Bottom Right Of The Quad (Back)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f(-1.0f, 2.0f, 6.5f);					// Top Right Of The Quad (Left)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-1.0f, 2.0f, 6.4f);					// Top Left Of The Quad (Left)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-1.0f, 0.9f, 6.4f);					// Bottom Left Of The Quad (Left)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(-1.0f, 0.9f, 6.5f);					// Bottom Right Of The Quad (Left)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 4.0f, 2.0f, 6.4f);					// Top Right Of The Quad (Right)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f( 4.0f, 2.0f, 6.5f);					// Top Left Of The Quad (Right)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f( 4.0f, 0.9f, 6.5f);					// Bottom Left Of The Quad (Right)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 4.0f, 0.9f, 6.4f);					// Bottom Left Of The Quad (Right)
	glEnd();
}

void glass()                                    //OK
{
glBindTexture(GL_TEXTURE_2D, texture[79]);

glBegin(GL_QUADS);

			// Bottom Right Of The Quad (Back)
		glTexCoord2f(0.0f, 0.0f);		glVertex3f(-.25f,7.25f, .25f);					// Top Right Of The Quad (Left)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-.25f,7.25f,-.25f);					// Top Left Of The Quad (Left)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-.25f,6.0f,-.25f);					// Bottom Left Of The Quad (Left)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(-.25f,6.0f, .25f);					// Bottom Right Of The Quad (Left)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f(.25f, 7.25f,-.25f);					// Top Right Of The Quad (Right)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f( .25f,7.25f,.25f);					// Top Left Of The Quad (Right)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(.25f,6.0f, .25f);					// Bottom Left Of The Quad (Right)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( .25f,6.0f,-.25f);						// Bottom Right Of The Quad (Top)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( .25f, 7.25f, .25f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-.25f,7.25f, .25f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-.25f,6.0f, .25f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( .25f,6.0f, .25f);					// Bottom Right Of The Quad (Front)

		glTexCoord2f(1.0f, 1.0f);		glVertex3f( .25f,6.0f,-.25f);					// Top Right Of The Quad (Back)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(-.25f,6.0f,-.25f);					// Top Left Of The Quad (Back)
		glTexCoord2f(0.0f, 0.0f);		glVertex3f(-.25f,7.25f,-.25f);					// Bottom Left Of The Quad (Back)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f( .25f,7.25f,-.25f);

glEnd();
}

void bottle()                                   //OK
{
glBindTexture(GL_TEXTURE_2D, texture[81]);

glBegin(GL_QUADS);
       glTexCoord2f(0.0f, 0.0f);		glVertex3f( .4f, 8.0f,-.4f);					// Top Right Of The Quad (Top)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-.4f, 8.0f,-.4f);					// Top Left Of The Quad (Top)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-.4f, 8.0f, .4f);					// Bottom Left Of The Quad (Top)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( .4f, 8.0f, .4f);					// Bottom Right Of The Quad (Top)

	    glTexCoord2f(0.0f, 0.0f);		glVertex3f(-.4f,8.0f, .4f);					// Top Right Of The Quad (Left)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-.4f,8.0f,-.4f);					// Top Left Of The Quad (Left)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-.4f,6.0f,-.4f);					// Bottom Left Of The Quad (Left)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(-.4f,6.0f, .4f);					// Bottom Right Of The Quad (Left)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f(.4f,8.0f,-.4f);					// Top Right Of The Quad (Right)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f( .4f,8.0f,.4f);					// Top Left Of The Quad (Right)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(.4f,6.0f, .4f);					// Bottom Left Of The Quad (Right)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( .4f,6.0f,-.4f);						// Bottom Right Of The Quad (Top)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( .4f, 8.0f, .4f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-.4f,8.0f, .4f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-.4f,6.0f, .4f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( .4f,6.0f, .4f);					// Bottom Right Of The Quad (Front)

		glTexCoord2f(1.0f, 1.0f);		glVertex3f( .4f,6.0f,-.4f);					// Top Right Of The Quad (Back)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(-.4f,6.0f,-.4f);					// Top Left Of The Quad (Back)
		glTexCoord2f(0.0f, 0.0f);		glVertex3f(-.4f,8.0f,-.4f);					// Bottom Left Of The Quad (Back)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f( .4f,8.0f,-.4f);

glEnd();


glBindTexture(GL_TEXTURE_2D, texture[80]);

glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f);		glVertex3f( .1f, 8.4f,-.1f);					// Top Right Of The Quad (Top)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-.1f, 8.4f,-.1f);					// Top Left Of The Quad (Top)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-.1f, 8.4f, .1f);					// Bottom Left Of The Quad (Top)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( .1f, 8.4f, .1f);					// Bottom Right Of The Quad (Top)


	    glTexCoord2f(0.0f, 0.0f);		glVertex3f(-.1f,8.4f, .1f);					// Top Right Of The Quad (Left)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-.1f,8.4f,-.1f);					// Top Left Of The Quad (Left)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-.1f,8.0f,-.1f);					// Bottom Left Of The Quad (Left)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(-.1f,8.0f, .1f);					// Bottom Right Of The Quad (Left)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f(.1f,8.4f,-.1f);					// Top Right Of The Quad (Right)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f( .1f,8.4f,.1f);					// Top Left Of The Quad (Right)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(.1f,8.0f, .1f);					// Bottom Left Of The Quad (Right)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( .1f,8.0f,-.1f);						// Bottom Right Of The Quad (Top)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( .1f, 8.4f, .1f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-.1f,8.4f, .1f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-.1f,8.0f, .1f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( .1f,8.0f, .1f);					// Bottom Right Of The Quad (Front)

		glTexCoord2f(1.0f, 1.0f);		glVertex3f( .1f,8.0f,-.1f);					// Top Right Of The Quad (Back)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(-.1f,8.0f,-.1f);					// Top Left Of The Quad (Back)
		glTexCoord2f(0.0f, 0.0f);		glVertex3f(-.1f,8.4f,-.1f);					// Bottom Left Of The Quad (Back)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f( .1f,8.4f,-.1f);

glEnd();

}

void flower()
{

    glBindTexture(GL_TEXTURE_2D, texture[79]);

    glBegin(GL_QUADS);

		glColor3f(1.0f,1.0f,1.0f);
					// Bottom Right Of The Quad (Back)
		glTexCoord2f(0.0f, 0.0f);		glVertex3f(-.6f,9.0f, .6f);					// Top Right Of The Quad (Left)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-.6f,9.0f,-.6f);					// Top Left Of The Quad (Left)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-.6f,6.0f,-.6f);					// Bottom Left Of The Quad (Left)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(-.6f,6.0f, .6f);					// Bottom Right Of The Quad (Left)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f(.6f, 9.0f,-.6f);					// Top Right Of The Quad (Right)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f( .6f,9.0f,.6f);					// Top Left Of The Quad (Right)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(.6f,6.0f, .6f);					// Bottom Left Of The Quad (Right)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( .6f,6.0f,-.6f);						// Bottom Right Of The Quad (Top)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( .6f, 9.0f, .6f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-.6f,9.0f, .6f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-.6f,6.0f, .6f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( .6f,6.0f, .6f);					// Bottom Right Of The Quad (Front)

		glTexCoord2f(1.0f, 1.0f);		glVertex3f( .6f,6.0f,-.6f);					// Top Right Of The Quad (Back)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(-.6f,6.0f,-.6f);					// Top Left Of The Quad (Back)
		glTexCoord2f(0.0f, 0.0f);		glVertex3f(-.6f,9.0f,-.6f);					// Bottom Left Of The Quad (Back)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f( .6f,9.0f,-.6f);

		glEnd();

		glBindTexture(GL_TEXTURE_2D, texture[87]);

    glBegin(GL_QUADS);

		glColor3f(1.0f,1.0f,1.0f);
					// Bottom Right Of The Quad (Back)
		glTexCoord2f(0.0f, 0.0f);		glVertex3f(-.6f,10.0f, .6f);					// Top Right Of The Quad (Left)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-.6f,10.0f,-.6f);					// Top Left Of The Quad (Left)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-.6f,9.0f,-.6f);					// Bottom Left Of The Quad (Left)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(-.6f,9.0f, .6f);					// Bottom Right Of The Quad (Left)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f(.6f, 10.0f,-.6f);					// Top Right Of The Quad (Right)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f( .6f,10.0f,.6f);					// Top Left Of The Quad (Right)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(.6f,9.0f, .6f);					// Bottom Left Of The Quad (Right)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( .6f,9.0f,-.6f);						// Bottom Right Of The Quad (Top)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( .6f, 10.0f, .6f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-.6f,10.0f, .6f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-.6f,9.0f, .6f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( .6f,9.0f, .6f);					// Bottom Right Of The Quad (Front)

		glTexCoord2f(1.0f, 1.0f);		glVertex3f( .6f,9.0f,-.6f);					// Top Right Of The Quad (Back)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(-.6f,9.0f,-.6f);					// Top Left Of The Quad (Back)
		glTexCoord2f(0.0f, 0.0f);		glVertex3f(-.6f,10.0f,-.6f);					// Bottom Left Of The Quad (Back)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f( .6f,10.0f,-.6f);

		glEnd();

        glPushMatrix();
        glTranslatef(2,0.0f,0.0f);
        bottle();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-2,0.0f,0.0f);
        bottle();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(6,0.0f,0.0f);
        glass();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-6,0.0f,0.0f);
        glass();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-3,0.0f,3.0f);
        glass();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-3,0.0f,-3.0f);
        glass();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(3,0.0f,3.0f);
        glass();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(3,0.0f,-3.0f);
        glass();
        glPopMatrix();
}

void door()
{
	glBindTexture(GL_TEXTURE_2D, texture[88]);
	glBegin(GL_QUADS);
		glColor3f(1.0f,1.0f,1.0f);
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( -5.2f, 8.7f,-4.0f);					// Top Right Of The Quad (Right)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f( -5.2f, 8.7f, 4.0f);					// Top Left Of The Quad (Right)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f( 3.5f,-8.7f, 4.0f);					// Bottom Left Of The Quad (Right)
		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 3.5f,-8.7f,-4.0f);	                // Bottom Right Of The Quad (Right)

		glTexCoord2f(0.0f, 1.0f);		glVertex3f( -5.8f, 8.7f,-4.0f);					// Top Right Of The Quad (Right)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f( -5.8f, 8.7f, 4.0f);					// Top Left Of The Quad (Right)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f( 4.1f,-8.7f, 4.0f);					// Bottom Left Of The Quad (Right)
		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 4.1f,-8.7f,-4.0f);
	glEnd();

	   glBindTexture(GL_TEXTURE_2D, texture[49]);

		/*glBegin(GL_QUADS);
		glColor3f(1.0f,1.0f,1.0f);
		glTexCoord2f(0.0f, 0.0f);		glVertex3f(5.0f, 8.9f,-4.0f);					// Top Right Of The Quad (Right)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(4.1f, 8.9f, -4.0f);					// Top Left Of The Quad (Right)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f( 4.1f,-8.9f,- 4.0f);					// Bottom Left Of The Quad (Right)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 5.0f,-8.9f,-4.0f);               // Bottom Right Of The Quad (Right)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f(5.0f, 8.9f,4.0f);					// Top Right Of The Quad (Right)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(4.1f, 8.9f,4.0f);					// Top Left Of The Quad (Right)
1		glTexCoord2f(1.0f, 1.0f);		glVertex3f( 4.1f,-8.9f,4.0f);					// Bottom Left Of The Quad (Right)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 5.0f,-8.9f,4.0f);               // Bottom Right Of The Quad (Right)
	glEnd();*/

}

void Body()
{
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
        gluCylinder(Quadric, 28.0, 28.0, 180.0, 30.0, 30.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0, 0.0, 180.0);
        gluDisk(Quadric, 0.0, 28.0, 30.0, 1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.0);
        gluDisk(Quadric, 0.0, 28.0, 30.0, 1.0);
    glPopMatrix();
}

void Front()                //OK
{
        glBindTexture(GL_TEXTURE_2D, texture[0]);
        glColor3f(245.0/255.0, 245.0/255.0, 245.0/255.0);
        glPushMatrix();
            glutSolidCone(28.0, 40.0, 100.0, 100.0);
        glPopMatrix();
}

void Back()                 //OK
{
        glBindTexture(GL_TEXTURE_2D, texture[0]);
        glColor3f(245.0/255.0, 245.0/255.0, 245.0/255.0);
        glPushMatrix();
            glutSolidCone(28.0, 40.0, 100.0, 100.0);
        glPopMatrix();
}

void DrawEllipse(float cxg, float cyg, float czg, float radiusg)
{
     float z = 0.0;
     int i;

    glColor3f(1.0, 1.0, 1.0);
    for(i = segments - 1; i >= 0; i--)
    {
        float theta = 2.0 * (-1.5708) * (float) i/ (float) segments;
        float x = radiusg * cos(theta);
        float y = radiusg * sin(theta);

        glVertex3f(x+cxg, y+cyg, z+czg);
    }
}

void NormalPolygon()        //OK
{
    glBindTexture(GL_TEXTURE_2D, texture[19]);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f);		glVertex3f( 4.0f, 5.5f,-2.9f);					// Top Right Of The Quad (Top)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(1.0f, 5.5f,-2.9f);					// Top Left Of The Quad (Top)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(1.0f, 5.5f, 7.0f);					// Bottom Left Of The Quad (Top)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 4.0f, 5.5f, 7.0f);					// Bottom Right Of The Quad (Top)

		glColor3f(1.0f,1.0f,1.0f);
		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 4.0f, 5.5f, 7.0f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(1.0f, 5.5f, 7.0f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(1.0f, 4.0f, 7.0f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(4.0f, 4.0f, 7.0f);					// Bottom Right Of The Quad (Front)
        glEnd();

        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 4.0f, 4.0f,-2.9f);					// Top Right Of The Quad (Back)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(1.0f, 4.0f,-2.9f);					// Top Left Of The Quad (Back)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(1.0f, 5.5f,-2.9f);					// Bottom Left Of The Quad (Back)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 4.0f, 5.5f,-2.9f);					// Bottom Right Of The Quad (Back)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f(1.0f, 5.5f, 7.0f);					// Top Right Of The Quad (Left)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(1.0f, 5.5f,-2.9f);					// Top Left Of The Quad (Left)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(1.0f, 4.0f,-2.9f);					// Bottom Left Of The Quad (Left)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(1.0f, 4.0f, 7.0f);					// Bottom Right Of The Quad (Left)
	glEnd();

    glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f);		glVertex3f( 4.0f, 5.5f,-2.9f);					// Top Right Of The Quad (Right)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f( 4.0f, 5.5f, 7.0f);					// Top Left Of The Quad (Right)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f( 4.0f, 4.0f, 7.0f);					// Bottom Left Of The Quad (Right)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 4.0f, 4.0f,-2.9f);

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 4.0f, 4.0f,-2.9f);					// Top Right Of The Quad (Right)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f( 1.0f, 4.0f, -2.9f);					// Top Left Of The Quad (Right)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f( 1.0f, 4.0f, 7.0f);					// Bottom Left Of The Quad (Right)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 4.0f, 4.0f, 7.0f);
	glEnd();
}

void LabelPolygon()
{
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f);		glVertex3f( 4.0f, 5.5f,-2.9f);					// Top Right Of The Quad (Top)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(1.0f, 5.5f,-2.9f);					// Top Left Of The Quad (Top)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(1.0f, 5.5f, 7.0f);					// Bottom Left Of The Quad (Top)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 4.0f, 5.5f, 7.0f);					// Bottom Right Of The Quad (Top)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 4.0f, 5.5f, 7.0f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(1.0f, 5.5f, 7.0f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(1.0f, 3.0f, 7.0f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(4.0f, 3.0f, 7.0f);
    glEnd();

    glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 4.0f, 3.0f,-2.9f);					// Top Right Of The Quad (Back)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(1.0f, 3.0f,-2.9f);					// Top Left Of The Quad (Back)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(1.0f, 5.5f,-2.9f);					// Bottom Left Of The Quad (Back)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 4.0f, 5.5f,-2.9f);				// Bottom Right Of The Quad (Back)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f(1.0f, 5.5f, 7.0f);					// Top Right Of The Quad (Left)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(1.0f, 5.5f,-2.9f);					// Top Left Of The Quad (Left)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(1.0f, 3.0f,-2.9f);					// Bottom Left Of The Quad (Left)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(1.0f, 3.0f, 7.0f);					// Bottom Right Of The Quad (Left)
	glEnd();

	glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f);		glVertex3f( 4.0f, 5.5f,-2.9f);					// Top Right Of The Quad (Right)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f( 4.0f, 5.5f, 7.0f);					// Top Left Of The Quad (Right)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f( 4.0f, 3.0f, 7.0f);					// Bottom Left Of The Quad (Right)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 4.0f, 3.0f,-2.9f);

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 4.0f, 3.0f,-2.9f);					// Top Right Of The Quad (Right)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f( 1.0f, 3.0f, -2.9f);					// Top Left Of The Quad (Right)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f( 1.0f, 3.0f, 7.0f);					// Bottom Left Of The Quad (Right)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 4.0f, 3.0f, 7.0f);
	glEnd();
}

void RoomLabelPolygon()
{
    glBindTexture(GL_TEXTURE_2D, texture[40]);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f);		glVertex3f( 4.0f, 5.5f,-5.9f);					// Top Right Of The Quad (Top)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(3.0f, 5.5f,-5.9f);					// Top Left Of The Quad (Top)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(3.0f, 5.5f, 7.0f);					// Bottom Left Of The Quad (Top)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 4.0f, 5.5f, 7.0f);					// Bottom Right Of The Quad (Top)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 4.0f, 5.5f, 7.0f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(3.0f, 5.5f, 7.0f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(3.0f, 3.0f, 7.0f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(4.0f, 3.0f, 7.0f);
		glEnd();
							// Bottom Right Of The Quad (Front)
        glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 4.0f, 3.0f,-5.9f);					// Top Right Of The Quad (Back)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(3.0f, 3.0f,-5.9f);					// Top Left Of The Quad (Back)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(3.0f, 5.5f,-5.9f);					// Bottom Left Of The Quad (Back)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 4.0f, 5.5f,-5.9f);				// Bottom Right Of The Quad (Back)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f(3.0f, 5.5f, 7.0f);					// Top Right Of The Quad (Left)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(3.0f, 5.5f,-5.9f);					// Top Left Of The Quad (Left)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(3.0f, 3.0f,-5.9f);					// Bottom Left Of The Quad (Left)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(3.0f, 3.0f, 7.0f);					// Bottom Right Of The Quad (Left)

	glEnd();

	glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f);		glVertex3f( 4.0f, 5.5f,-5.9f);					// Top Right Of The Quad (Right)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f( 4.0f, 5.5f, 7.0f);					// Top Left Of The Quad (Right)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f( 4.0f, 3.0f, 7.0f);					// Bottom Left Of The Quad (Right)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 4.0f, 3.0f,-5.9f);

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 4.0f, 3.0f,-5.9f);					// Top Right Of The Quad (Right)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f( 3.0f, 3.0f, -5.9f);					// Top Left Of The Quad (Right)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f( 3.0f, 3.0f, 7.0f);					// Bottom Left Of The Quad (Right)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 4.0f, 3.0f, 7.0f);
	glEnd();

}

void wall1()
{
    glPushMatrix();
	    glTranslatef(10.0f, 15.0f, -40.0);
		glBindTexture(GL_TEXTURE_2D, texture[77]);
		glBegin(GL_QUADS);
		glColor3f(1.0f,1.0f,1.0f);
		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 40.0f, 8.7f, 80.0f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(28.0f, 8.7f, 80.0f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(28.0f,-11.5f, 80.0f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 42.0f,-11.5f, 80.0f);

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 42.0f, 8.7f, 80.8f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(28.0f, 8.7f, 80.8f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(28.0f,-11.5f, 80.8f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 42.0f,-11.5f, 80.8f);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, texture[47]);
        glBegin(GL_QUADS);
		glColor3f(1.0f,1.0f,1.0f);
		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 40.0f, -11.5f, 80.8f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(40.0f,-11.5f, 80.0f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(40.0f,8.7f, 80.0f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 40.0f,8.7f, 80.8f);

		glColor3f(1.0f,1.0f,1.0f);
		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 28.0f,-11.5f, 80.8f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(28.0f, -11.5f, 80.0f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(28.0f,8.7f, 80.0f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 28.0f,8.7f, 80.8f);
		glEnd();

	    glPopMatrix();

	    glPushMatrix();
	    glTranslatef(10.0f, 15.0f, -40.0);
		glBindTexture(GL_TEXTURE_2D, texture[77]);
		glBegin(GL_QUADS);
	    glTexCoord2f(0.0f, 0.0f);		glVertex3f( 16.0f, 8.7f, 80.0f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(6.6f, 8.7f, 80.0f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(6.6f,-11.5f, 80.0f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 16.0f,-11.5f, 80.0f);

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 16.0f, 8.7f, 80.8f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(6.6f, 8.7f, 80.8f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(6.6f,-11.5f, 80.8f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 16.0f,-11.5f, 80.8f);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, texture[47]);
        glBegin(GL_QUADS);
		glColor3f(1.0f,1.0f,1.0f);
		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 16.0f, -11.5f, 80.8f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(16.0f,-11.5f, 80.0f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(16.0f,8.7f, 80.0f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 16.0f,8.7f, 80.8f);

		glColor3f(1.0f,1.0f,1.0f);
		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 6.6f,-11.5f, 80.8f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(6.6f, -11.5f, 80.0f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(6.6f,8.7f, 80.0f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 6.6f,8.7f, 80.8f);
		glEnd();

		glPopMatrix();
}

void Window()                       //OK
{
    glBindTexture(GL_TEXTURE_2D, texture[47]);
    glColor3f(0.0, 0.0, 0.0);
	glPushMatrix();
        gluCylinder(Quadric, 3.0, 3.0, 5.0, 30.0, 30.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0, 0.0, 5.0);
        gluDisk(Quadric, 0.0, 3.0, 30.0, 1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.0);
        gluDisk(Quadric, 0.0, 3.0, 30.0, 1.0);
    glPopMatrix();
}

void Door()                         //OK
{
    glBindTexture(GL_TEXTURE_2D, texture[47]);
    glColor3f(0.0, 0.0, 0.0);
	glPushMatrix();
        gluCylinder(Quadric, 12.0, 12.0, 9.0, 30.0, 30.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0, 0.0, 9.0);
        gluDisk(Quadric, 0.0, 12.0, 30.0, 1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.0);
        gluDisk(Quadric, 0.0, 12.0, 30.0, 1.0);
    glPopMatrix();
}

void PlaneFan(float x1, float x2)                   //OK
{
    glBindTexture(GL_TEXTURE_2D, texture[5]);
        glBegin(GL_QUADS);
            glTexCoord2f(0.0f, 0.0f);		glVertex3f( x1, 5.5f,-2.9f);					// Top Right Of The Quad (Top)
            glTexCoord2f(1.0f, 0.0f);		glVertex3f(x1, 5.5f,28.9f);					// Top Left Of The Quad (Top)
            glTexCoord2f(1.0f, 1.0f);		glVertex3f(x2, 5.5f, -5.9f);					// Bottom Left Of The Quad (Top)
            glTexCoord2f(0.0f, 1.0f);		glVertex3f(x2, 5.5f, -7.9f);
		glEnd();

		glBegin(GL_QUADS);
            glTexCoord2f(0.0f, 0.0f);		glVertex3f( x1, 5.0f,-2.9f);					// Top Right Of The Quad (Top)
            glTexCoord2f(1.0f, 0.0f);		glVertex3f(x1, 5.0f,28.9f);					// Top Left Of The Quad (Top)
            glTexCoord2f(1.0f, 1.0f);		glVertex3f(x2, 5.0f, -5.9f);					// Bottom Left Of The Quad (Top)
            glTexCoord2f(0.0f, 1.0f);		glVertex3f(x2, 5.0f, -7.9f);
		glEnd();

		glBegin(GL_QUADS);
            glTexCoord2f(0.0f, 0.0f);		glVertex3f( x1, 5.5f,28.9f);					// Top Right Of The Quad (Top)
            glTexCoord2f(1.0f, 0.0f);		glVertex3f(x1, 5.0f,28.9f);					// Top Left Of The Quad (Top)
            glTexCoord2f(1.0f, 1.0f);		glVertex3f(x2, 5.0f, -5.9f);					// Bottom Left Of The Quad (Top)
            glTexCoord2f(0.0f, 1.0f);		glVertex3f(x2, 5.5f, -5.9f);
		glEnd();

		glBegin(GL_QUADS);
            glTexCoord2f(0.0f, 0.0f);		glVertex3f( x1, 5.5f,-2.9f);					// Top Right Of The Quad (Top)
            glTexCoord2f(1.0f, 0.0f);		glVertex3f(x1, 5.0f,-2.9f);					// Top Left Of The Quad (Top)
            glTexCoord2f(1.0f, 1.0f);		glVertex3f(x2, 5.0f, -7.9f);					// Bottom Left Of The Quad (Top)
            glTexCoord2f(0.0f, 1.0f);		glVertex3f(x2, 5.5f, -7.9f);
		glEnd();

		glBegin(GL_QUADS);
            glTexCoord2f(0.0f, 0.0f);		glVertex3f(x2, 5.5f,-5.9f);					// Top Right Of The Quad (Top)
            glTexCoord2f(1.0f, 0.0f);		glVertex3f(x2, 5.0f,-5.9f);					// Top Left Of The Quad (Top)
            glTexCoord2f(1.0f, 1.0f);		glVertex3f(x2, 5.0f, -7.9f);					// Bottom Left Of The Quad (Top)
            glTexCoord2f(0.0f, 1.0f);		glVertex3f(x2, 5.5f, -7.9f);
		glEnd();
}

void PlaneFanRight(float x1, float x2)              //OK
{
    glBindTexture(GL_TEXTURE_2D, texture[5]);
        glBegin(GL_QUADS);
            glTexCoord2f(0.0f, 0.0f);		glVertex3f( x1, 5.5f,-2.9f);					// Top Right Of The Quad (Top)
            glTexCoord2f(1.0f, 0.0f);		glVertex3f(x1, 5.5f,28.9f);					// Top Left Of The Quad (Top)
            glTexCoord2f(1.0f, 1.0f);		glVertex3f(x2, 5.5f, -5.9f);					// Bottom Left Of The Quad (Top)
            glTexCoord2f(0.0f, 1.0f);		glVertex3f(x2, 5.5f, -7.9f);
		glEnd();

		glBegin(GL_QUADS);
            glTexCoord2f(0.0f, 0.0f);		glVertex3f(x1, 5.0f,-2.9f);					// Top Right Of The Quad (Top)
            glTexCoord2f(1.0f, 0.0f);		glVertex3f(x1, 5.0f,28.9f);					// Top Left Of The Quad (Top)
            glTexCoord2f(1.0f, 1.0f);		glVertex3f(x2, 5.0f, -5.9f);					// Bottom Left Of The Quad (Top)
            glTexCoord2f(0.0f, 1.0f);		glVertex3f(x2, 5.0f, -7.9f);
		glEnd();

		glBegin(GL_QUADS);
            glTexCoord2f(0.0f, 0.0f);		glVertex3f(x1, 5.5f,28.9f);					// Top Right Of The Quad (Top)
            glTexCoord2f(1.0f, 0.0f);		glVertex3f(x1, 5.0f,28.9f);					// Top Left Of The Quad (Top)
            glTexCoord2f(1.0f, 1.0f);		glVertex3f(x2, 5.0f, -5.9f);					// Bottom Left Of The Quad (Top)
            glTexCoord2f(0.0f, 1.0f);		glVertex3f(x2, 5.5f, -5.9f);
		glEnd();

		glBegin(GL_QUADS);
            glTexCoord2f(0.0f, 0.0f);		glVertex3f(x1, 5.5f,-2.9f);					// Top Right Of The Quad (Top)
            glTexCoord2f(1.0f, 0.0f);		glVertex3f(x1, 5.0f,-2.9f);					// Top Left Of The Quad (Top)
            glTexCoord2f(1.0f, 1.0f);		glVertex3f(x2, 5.0f, -7.9f);					// Bottom Left Of The Quad (Top)
            glTexCoord2f(0.0f, 1.0f);		glVertex3f(x2, 5.5f, -7.9f);
		glEnd();

		glBegin(GL_QUADS);
            glTexCoord2f(0.0f, 0.0f);		glVertex3f(x2, 5.5f,-5.9f);					// Top Right Of The Quad (Top)
            glTexCoord2f(1.0f, 0.0f);		glVertex3f(x2, 5.0f,-5.9f);					// Top Left Of The Quad (Top)
            glTexCoord2f(1.0f, 1.0f);		glVertex3f(x2, 5.0f, -7.9f);					// Bottom Left Of The Quad (Top)
            glTexCoord2f(0.0f, 1.0f);		glVertex3f(x2, 5.5f, -7.9f);
		glEnd();
}

void PlaneFanBack()                                 //OK
{
    glBindTexture(GL_TEXTURE_2D, texture[5]);
        glBegin(GL_QUADS);
            glTexCoord2f(0.0f, 0.0f);		glVertex3f(4.0f, 40.5f,-30.9f);					// Top Right Of The Quad (Top)
            glTexCoord2f(1.0f, 0.0f);		glVertex3f(4.0f, 40.5f,-20.9f);					// Top Left Of The Quad (Top)
            glTexCoord2f(1.0f, 1.0f);		glVertex3f(4.0f, 5.5f, 0.9f);					// Bottom Left Of The Quad (Top)
            glTexCoord2f(0.0f, 1.0f);		glVertex3f(4.0f, 5.5f, -30.9f);
		glEnd();

        glBegin(GL_QUADS);
            glTexCoord2f(0.0f, 0.0f);		glVertex3f(5.0f, 40.5f,-30.9f);					// Top Right Of The Quad (Top)
            glTexCoord2f(1.0f, 0.0f);		glVertex3f(5.0f, 40.5f,-20.9f);					// Top Left Of The Quad (Top)
            glTexCoord2f(1.0f, 1.0f);		glVertex3f(5.0f, 5.5f, 0.9f);					// Bottom Left Of The Quad (Top)
            glTexCoord2f(0.0f, 1.0f);		glVertex3f(5.0f, 5.5f, -30.9f);
		glEnd();

		glBegin(GL_QUADS);
            glTexCoord2f(0.0f, 0.0f);		glVertex3f(5.0f, 40.5f,-30.9f);					// Top Right Of The Quad (Top)
            glTexCoord2f(1.0f, 0.0f);		glVertex3f(4.0f, 40.5f,-30.9f);					// Top Left Of The Quad (Top)
            glTexCoord2f(1.0f, 1.0f);		glVertex3f(4.0f, 40.5f, -20.9f);					// Bottom Left Of The Quad (Top)
            glTexCoord2f(0.0f, 1.0f);		glVertex3f(5.0f, 40.5f, -20.9f);
		glEnd();

		glBegin(GL_QUADS);
            glTexCoord2f(0.0f, 0.0f);		glVertex3f(5.0f, 5.5f,-30.9f);					// Top Right Of The Quad (Top)
            glTexCoord2f(1.0f, 0.0f);		glVertex3f(4.0f, 5.5f,-30.9f);					// Top Left Of The Quad (Top)
            glTexCoord2f(1.0f, 1.0f);		glVertex3f(4.0f, 5.5f, 0.9f);					// Bottom Left Of The Quad (Top)
            glTexCoord2f(0.0f, 1.0f);		glVertex3f(5.0f, 5.5f, 0.9f);
		glEnd();

		glBegin(GL_QUADS);
            glTexCoord2f(0.0f, 0.0f);		glVertex3f(5.0f, 40.5f,-20.9f);					// Top Right Of The Quad (Top)
            glTexCoord2f(1.0f, 0.0f);		glVertex3f(5.0f, 5.5f, 0.9f);					// Top Left Of The Quad (Top)
            glTexCoord2f(1.0f, 1.0f);		glVertex3f(4.0f, 5.5f, 0.9f);					// Bottom Left Of The Quad (Top)
            glTexCoord2f(0.0f, 1.0f);		glVertex3f(4.0f, 40.5f, -20.9f);
		glEnd();

		glBegin(GL_QUADS);
            glTexCoord2f(0.0f, 0.0f);		glVertex3f(5.0f, 40.5f,-30.9f);					// Top Right Of The Quad (Top)
            glTexCoord2f(1.0f, 0.0f);		glVertex3f(5.0f, 5.5f, -30.9f);					// Top Left Of The Quad (Top)
            glTexCoord2f(1.0f, 1.0f);		glVertex3f(4.0f, 5.5f, -30.9f);					// Bottom Left Of The Quad (Top)
            glTexCoord2f(0.0f, 1.0f);		glVertex3f(4.0f, 40.5f, -30.9f);
		glEnd();
}

void DiningTable(float x1, float x2)                //OK
{

	glBindTexture(GL_TEXTURE_2D, texture[9]);
	glBegin(GL_QUADS);

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 19.2f, x1,-4.5f);					// Top Right Of The Quad (Top)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(5.2f, x1,-4.5f);					// Top Left Of The Quad (Top)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(5.2f, x1, 20.5f);					// Bottom Left Of The Quad (Top)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 19.2f, x1, 20.5f);					// Bottom Right Of The Quad (Top)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 19.2f,x2, 20.5f);					// Top Right Of The Quad (Bottom)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(5.2f,x2, 20.5f);					// Top Left Of The Quad (Bottom)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(5.2f,x2,-4.50f);					// Bottom Left Of The Quad (Bottom)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 19.2f,x2,-4.5f);					// Bottom Right Of The Quad (Bottom)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 19.2f, x1, 20.5f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(5.2f, x1, 20.5f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(5.2f,x2, 20.5f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 19.2f,x2, 20.5f);					// Bottom Right Of The Quad (Front)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 19.2f,x2,-4.5f);					// Top Right Of The Quad (Back)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(5.2f,x2,-4.5f);					// Top Left Of The Quad (Back)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(5.2f, x1,-4.5f);					// Bottom Left Of The Quad (Back)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 19.2f, x1,-4.5f);					// Bottom Right Of The Quad (Back)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f(5.2f, x1, 20.5f);					// Top Right Of The Quad (Left)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(5.2f, x1,-4.5f);					// Top Left Of The Quad (Left)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(5.2f,x2,-4.5f);					// Bottom Left Of The Quad (Left)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(5.2f,x2, 20.5f);					// Bottom Right Of The Quad (Left)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 19.2f, x1,-4.5f);					// Top Right Of The Quad (Right)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f( 19.2f, x1, 20.5f);					// Top Left Of The Quad (Right)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f( 19.2f,x2, 20.5f);					// Bottom Left Of The Quad (Right)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 19.2f,x2,-4.5f);					// Bottom Left Of The Quad (Right)
	glEnd();

}

void TableLeg()                                     //OK
{
     glBindTexture(GL_TEXTURE_2D, texture[9]);

        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f);		glVertex3f( 4.0f, 5.5f,3.0f);					// Top Right Of The Quad (Top)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(3.0f, 5.5f,3.0f);					// Top Left Of The Quad (Top)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(3.0f, 5.5f, 7.0f);					// Bottom Left Of The Quad (Top)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 4.0f, 5.5f, 7.0f);					// Bottom Right Of The Quad (Top)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 4.0f, 5.5f, 7.0f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(3.0f, 5.5f, 7.0f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(3.0f, 13.0f, 7.0f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(4.0f, 13.0f, 7.0f);
		glEnd();

        glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 4.0f, 13.0f,3.0f);					// Top Right Of The Quad (Back)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(3.0f, 13.0f,3.0f);					// Top Left Of The Quad (Back)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(3.0f, 5.5f,3.0f);					// Bottom Left Of The Quad (Back)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 4.0f, 5.5f,3.0f);				// Bottom Right Of The Quad (Back)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f(3.0f, 5.5f, 7.0f);					// Top Right Of The Quad (Left)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(3.0f, 5.5f,3.0f);					// Top Left Of The Quad (Left)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(3.0f, 13.0f,3.0f);					// Bottom Left Of The Quad (Left)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(3.0f, 13.0f, 7.0f);					// Bottom Right Of The Quad (Left)

	glEnd();

	glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f);		glVertex3f( 4.0f, 5.5f,3.0f);					// Top Right Of The Quad (Right)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f( 4.0f, 5.5f, 7.0f);					// Top Left Of The Quad (Right)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f( 4.0f, 13.0f, 7.0f);					// Bottom Left Of The Quad (Right)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 4.0f, 13.0f,3.0f);

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 4.0f, 13.0f,3.0f);					// Top Right Of The Quad (Right)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f( 3.0f, 13.0f, 3.0f);					// Top Left Of The Quad (Right)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f( 3.0f, 13.0f, 7.0f);					// Bottom Left Of The Quad (Right)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 4.0f, 13.0f, 7.0f);
	glEnd();

}

void FoodCorners(float x1, float x2)
{
	glBindTexture(GL_TEXTURE_2D, texture[10]);
	glBegin(GL_QUADS);

		glTexCoord2f(0.0f, 0.0f);		glVertex3f(12.2f, x1,-4.5f);					// Top Right Of The Quad (Top)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(5.2f, x1,-4.5f);					// Top Left Of The Quad (Top)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(5.2f, x1, 5.5f);					// Bottom Left Of The Quad (Top)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(12.2f, x1, 5.5f);					// Bottom Right Of The Quad (Top)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f(12.2f,x2, 5.5f);					// Top Right Of The Quad (Bottom)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(5.2f,x2, 5.5f);					// Top Left Of The Quad (Bottom)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(5.2f,x2,-4.50f);					// Bottom Left Of The Quad (Bottom)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(12.2f,x2,-4.5f);					// Bottom Right Of The Quad (Bottom)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f(12.2f, x1, 5.5f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(5.2f, x1, 5.5f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(5.2f,x2, 5.5f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(12.2f,x2, 5.5f);					// Bottom Right Of The Quad (Front)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f(12.2f,x2,-4.5f);					// Top Right Of The Quad (Back)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(5.2f,x2,-4.5f);					// Top Left Of The Quad (Back)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(5.2f, x1,-4.5f);					// Bottom Left Of The Quad (Back)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(12.2f, x1,-4.5f);					// Bottom Right Of The Quad (Back)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f(5.2f, x1, 5.5f);					// Top Right Of The Quad (Left)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(5.2f, x1,-4.5f);					// Top Left Of The Quad (Left)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(5.2f,x2,-4.5f);					// Bottom Left Of The Quad (Left)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(5.2f,x2, 5.5f);					// Bottom Right Of The Quad (Left)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f(12.2f, x1,-4.5f);					// Top Right Of The Quad (Right)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(12.2f, x1, 5.5f);					// Top Left Of The Quad (Right)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(12.2f,x2, 5.5f);					// Bottom Left Of The Quad (Right)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(12.2f,x2,-4.5f);					// Bottom Left Of The Quad (Right)
	glEnd();

}

void Bed(float x1, float x2)
{
	glBegin(GL_QUADS);

		glTexCoord2f(0.0f, 0.0f);		glVertex3f(39.2f, x1,-4.5f);					// Top Right Of The Quad (Top)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(7.2f, x1,-4.5f);					// Top Left Of The Quad (Top)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(7.2f, x1, 15.5f);					// Bottom Left Of The Quad (Top)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(39.2f, x1, 15.5f);					// Bottom Right Of The Quad (Top)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f(39.2f,x2, 15.5f);					// Top Right Of The Quad (Bottom)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(7.2f,x2, 15.5f);					// Top Left Of The Quad (Bottom)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(7.2f,x2,-4.50f);					// Bottom Left Of The Quad (Bottom)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(39.2f,x2,-4.5f);					// Bottom Right Of The Quad (Bottom)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f(39.2f, x1, 15.5f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(7.2f, x1, 15.5f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(7.2f,x2, 15.5f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(39.2f,x2, 15.5f);					// Bottom Right Of The Quad (Front)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f(39.2f,x2,-4.5f);					// Top Right Of The Quad (Back)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(7.2f,x2,-4.5f);					// Top Left Of The Quad (Back)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(7.2f, x1,-4.5f);					// Bottom Left Of The Quad (Back)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(39.2f, x1,-4.5f);					// Bottom Right Of The Quad (Back)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f(7.2f, x1, 15.5f);					// Top Right Of The Quad (Left)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(7.2f, x1,-4.5f);					// Top Left Of The Quad (Left)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(7.2f,x2,-4.5f);					// Bottom Left Of The Quad (Left)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(7.2f,x2, 15.5f);					// Bottom Right Of The Quad (Left)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f(39.2f, x1,-4.5f);					// Top Right Of The Quad (Right)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(39.2f, x1, 15.5f);					// Top Left Of The Quad (Right)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(39.2f,x2, 15.5f);					// Bottom Left Of The Quad (Right)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(39.2f,x2,-4.5f);					// Bottom Left Of The Quad (Right)
	glEnd();

}

void Balish()
{
    glBindTexture(GL_TEXTURE_2D, texture[19]);
    glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f);		glVertex3f( 4.0f, 5.5f,-2.9f);					// Top Right Of The Quad (Top)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(9.0f, 5.5f,-2.9f);					// Top Left Of The Quad (Top)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(9.0f, 5.5f, 5.0f);					// Bottom Left Of The Quad (Top)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 4.0f, 5.5f, 5.0f);					// Bottom Right Of The Quad (Top)

		glColor3f(1.0f,1.0f,1.0f);
		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 4.0f, 5.5f, 5.0f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(9.0f, 5.5f, 5.0f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(9.0f, 4.0f, 5.0f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(4.0f, 4.0f, 5.0f);					// Bottom Right Of The Quad (Front)
        glEnd();

        glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 4.0f, 4.0f,-2.9f);					// Top Right Of The Quad (Back)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(9.0f, 4.0f,-2.9f);					// Top Left Of The Quad (Back)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(9.0f, 5.5f,-2.9f);					// Bottom Left Of The Quad (Back)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 4.0f, 5.5f,-2.9f);					// Bottom Right Of The Quad (Back)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f(9.0f, 5.5f, 5.0f);					// Top Right Of The Quad (Left)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(9.0f, 5.5f,-2.9f);					// Top Left Of The Quad (Left)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(9.0f, 4.0f,-2.9f);					// Bottom Left Of The Quad (Left)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(9.0f, 4.0f, 5.0f);					// Bottom Right Of The Quad (Left)

							// Bottom Left Of The Quad (Right)
	glEnd();

	glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f);		glVertex3f( 4.0f, 5.5f,-2.9f);					// Top Right Of The Quad (Right)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f( 4.0f, 5.5f, 5.0f);					// Top Left Of The Quad (Right)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f( 4.0f, 4.0f, 5.0f);					// Bottom Left Of The Quad (Right)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 4.0f, 4.0f,-2.9f);

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 4.0f, 4.0f,-2.9f);					// Top Right Of The Quad (Right)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f( 9.0f, 4.0f, -2.9f);					// Top Left Of The Quad (Right)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f( 9.0f, 4.0f, 5.0f);					// Bottom Left Of The Quad (Right)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 4.0f, 4.0f, 5.0f);
	glEnd();

}

void Almari()
{
    glBindTexture(GL_TEXTURE_2D, texture[3]);
	glBegin(GL_QUADS);
        glBindTexture(GL_TEXTURE_2D, texture[80]);
		glTexCoord2f(0.0f, 0.0f);		glVertex3f(17.2f, 0.5,-4.5f);					// Top Right Of The Quad (Top)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(7.2f, 0.5,-4.5f);					// Top Left Of The Quad (Top)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(7.2f, 0.5, 17.5f);					// Bottom Left Of The Quad (Top)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(17.2f, 0.5, 17.5f);					// Bottom Right Of The Quad (Top)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f(17.2f, -18.0, 17.5f);					// Top Right Of The Quad (Bottom)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(7.2f, -18.0, 17.5f);					// Top Left Of The Quad (Bottom)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(7.2f, -18.0,-4.50f);					// Bottom Left Of The Quad (Bottom)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(17.2f, -18.0,-4.5f);					// Bottom Right Of The Quad (Bottom)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f(17.2f, 0.5, 17.5f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(7.2f, 0.5, 17.5f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(7.2f, -18.0, 17.5f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(17.2f, -18.0, 17.5f);					// Bottom Right Of The Quad (Front)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f(17.2f, -18.0,-4.5f);					// Top Right Of The Quad (Back)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(7.2f, -18.0,-4.5f);					// Top Left Of The Quad (Back)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(7.2f, 0.5,-4.5f);					// Bottom Left Of The Quad (Back)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(17.2f, 0.5,-4.5f);					// Bottom Right Of The Quad (Back)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f(7.2f, 0.5, 17.5f);					// Top Right Of The Quad (Left)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(7.2f, 0.5,-4.5f);					// Top Left Of The Quad (Left)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(7.2f, -18.0,-4.5f);					// Bottom Left Of The Quad (Left)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(7.2f, -18.0, 17.5f);					// Bottom Right Of The Quad (Left)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f(17.2f, 0.5,-4.5f);					// Top Right Of The Quad (Right)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(17.2f, 0.5, 17.5f);					// Top Left Of The Quad (Right)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(17.2f, -18.0, 17.5f);					// Bottom Left Of The Quad (Right)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(17.2f, -18.0,-4.5f);					// Bottom Left Of The Quad (Right)
	glEnd();
}

void LCDTV()
{
    glBindTexture(GL_TEXTURE_2D, texture[40]);
    glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f);		glVertex3f( 4.0f, 6.5f,-2.9f);					// Top Right Of The Quad (Top)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(3.0f, 6.5f,-2.9f);					// Top Left Of The Quad (Top)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(3.0f, 6.5f, 8.0f);					// Bottom Left Of The Quad (Top)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 4.0f, 6.5f, 8.0f);					// Bottom Right Of The Quad (Top)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 4.0f, 6.5f, 8.0f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(3.0f, 6.5f, 8.0f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(3.0f, 0.0f, 8.0f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(4.0f, 0.0f, 8.0f);
		glEnd();

		glBegin(GL_QUADS);

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 4.0f, 0.0f,-2.9f);					// Top Right Of The Quad (Back)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(3.0f, 0.0f,-2.9f);					// Top Left Of The Quad (Back)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(3.0f, 6.5f,-2.9f);					// Bottom Left Of The Quad (Back)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 4.0f, 6.5f,-2.9f);				// Bottom Right Of The Quad (Back)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f(3.0f, 6.5f, 8.0f);					// Top Right Of The Quad (Left)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(3.0f, 6.5f,-2.9f);					// Top Left Of The Quad (Left)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(3.0f, 0.0f,-2.9f);					// Bottom Left Of The Quad (Left)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(3.0f, 0.0f, 8.0f);					// Bottom Right Of The Quad (Left)

	glEnd();

	glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f);		glVertex3f( 4.0f, 6.5f,-2.9f);					// Top Right Of The Quad (Right)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f( 4.0f, 6.5f, 8.0f);					// Top Left Of The Quad (Right)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f( 4.0f, 0.0f, 8.0f);					// Bottom Left Of The Quad (Right)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 4.0f, 0.0f,-2.9f);

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 4.0f, 0.0f,-2.9f);					// Top Right Of The Quad (Right)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f( 3.0f, 0.0f, -2.9f);					// Top Left Of The Quad (Right)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f( 3.0f, 0.0f, 8.0f);					// Bottom Left Of The Quad (Right)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 4.0f, 0.0f, 8.0f);
	glEnd();

}

void Chair()                                   //OK
{
    glBindTexture(GL_TEXTURE_2D, texture[54]);
   	glBegin(GL_QUADS);                          //Chair Upper Portion

		glColor3f(1.0f,1.0f,1.0f);
		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 3.0f, 0.9f,-2.5f);					// Top Right Of The Quad (Top)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-1.2f, 0.9f,-2.5f);					// Top Left Of The Quad (Top)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-1.2f, 0.9f, 4.0f);					// Bottom Left Of The Quad (Top)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 3.0f, 0.9f, 4.0f);					// Bottom Right Of The Quad (Top)

		glVertex3f( 3.0f,-0.7f, 4.0f);					// Top Right Of The Quad (Bottom)
		glVertex3f(-1.2f,-0.7f, 4.0f);					// Top Left Of The Quad (Bottom)
		glVertex3f(-1.2f,-0.7f,-2.50f);					// Bottom Left Of The Quad (Bottom)
		glVertex3f( 3.0f,-0.7f,-2.5f);					// Bottom Right Of The Quad (Bottom)

		glColor3f(1.0f,1.0f,1.0f);
		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 3.0f, 0.9f, 4.0f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-1.2f, 0.9f, 4.0f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-1.2f,-0.7f, 4.0f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 3.0f,-0.7f, 4.0f);					// Bottom Right Of The Quad (Front)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 3.0f,-0.7f,-2.5f);					// Top Right Of The Quad (Back)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-1.2f,-0.7f,-2.5f);					// Top Left Of The Quad (Back)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-1.2f, 0.9f,-2.5f);					// Bottom Left Of The Quad (Back)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 3.0f, 0.9f,-2.5f);					// Bottom Right Of The Quad (Back)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f(-1.2f, 0.9f, 4.0f);					// Top Right Of The Quad (Left)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-1.2f, 0.9f,-2.5f);					// Top Left Of The Quad (Left)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-1.2f,-0.7f,-2.5f);					// Bottom Left Of The Quad (Left)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(-1.2f,-0.7f, 4.0f);					// Bottom Right Of The Quad (Left)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 3.0f, 0.9f,-2.5f);					// Top Right Of The Quad (Right)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f( 3.0f, 0.9f, 4.0f);					// Top Left Of The Quad (Right)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f( 3.0f,-0.7f, 4.0f);					// Bottom Left Of The Quad (Right)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 3.0f,-0.7f,-2.5f);					// Bottom Left Of The Quad (Right)
	glEnd();

	glPushMatrix();
	glRotatef(90.0, 0.0, 0.0, 1.0);
   	glBegin(GL_QUADS);                          //Chair Lower Portion

		glColor3f(1.0f,1.0f,1.0f);
		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 10.2f, -2.1f,-2.5f);					// Top Right Of The Quad (Top)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(0.0f, -2.1f,-2.5f);					// Top Left Of The Quad (Top)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(0.0f, -2.1f, 4.0f);					// Bottom Left Of The Quad (Top)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(10.2f, -2.1f, 4.0f);					// Bottom Right Of The Quad (Top)

		glVertex3f( 10.2f,-3.7f, 4.0f);					// Top Right Of The Quad (Bottom)
		glVertex3f(0.0f,-3.7f, 4.0f);					// Top Left Of The Quad (Bottom)
		glVertex3f(0.0f,-3.7f,-2.50f);					// Bottom Left Of The Quad (Bottom)
		glVertex3f( 10.2f,-3.7f,-2.5f);					// Bottom Right Of The Quad (Bottom)

		glColor3f(1.0f,1.0f,1.0f);
		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 10.2f, -2.1f, 4.0f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(0.0f, -2.1f, 4.0f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(0.0f,-3.7f, 4.0f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 10.2f,-3.7f, 4.0f);					// Bottom Right Of The Quad (Front)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 10.2f,-3.7f,-2.5f);					// Top Right Of The Quad (Back)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(0.0f,-3.7f,-2.5f);					// Top Left Of The Quad (Back)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(0.0f, -2.1f,-2.5f);					// Bottom Left Of The Quad (Back)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 10.2f, -2.1f,-2.5f);					// Bottom Right Of The Quad (Back)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f(0.0f, -2.1f, 4.0f);					// Top Right Of The Quad (Left)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(0.0f, -2.1f,-2.5f);					// Top Left Of The Quad (Left)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(0.0f,-3.7f,-2.5f);					// Bottom Left Of The Quad (Left)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(0.0f,-3.7f, 4.0f);					// Bottom Right Of The Quad (Left)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 10.2f, -2.1f,-2.5f);					// Top Right Of The Quad (Right)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f( 10.2f, -2.1f, 4.0f);					// Top Left Of The Quad (Right)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f( 10.2f,-3.7f, 4.0f);					// Bottom Left Of The Quad (Right)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 10.2f,-3.7f,-2.5f);					// Bottom Left Of The Quad (Right)
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.0, -1.0, -2.0);
        chair();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.0, -1.0, 3.0);
        chair();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.0, -1.0, 3.0);
        chair();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.0, -1.0, -2.0);
        chair();
    glPopMatrix();

}

void TableCloth()
{
    glBindTexture(GL_TEXTURE_2D, texture[40]);
    glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f);		glVertex3f( 4.0f, 6.5f,-2.9f);					// Top Right Of The Quad (Top)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(7.0f, 6.5f,-2.9f);					// Top Left Of The Quad (Top)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(7.0f, 6.5f, 3.0f);					// Bottom Left Of The Quad (Top)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 4.0f, 6.5f, 3.0f);
    glEnd();				// Bottom Right Of The Quad (Top)
}

void Cooker()                               //OK
{
    glBindTexture(GL_TEXTURE_2D, texture[82]);
	glPushMatrix();
        gluCylinder(Quadric, 1.6, 1.6, 1.5, 30.0, 30.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0, 0.0, 5.0);
        gluDisk(Quadric, 2.0, 1.6, 30.0, 1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.0);
        gluDisk(Quadric, 0.0, 1.7, 30.0, 1.0);
    glPopMatrix();
}

void Vash()
{

    glBindTexture(GL_TEXTURE_2D, texture[79]);

    glBegin(GL_QUADS);

		glColor3f(1.0f,1.0f,1.0f);
					// Bottom Right Of The Quad (Back)
		glTexCoord2f(0.0f, 0.0f);		glVertex3f(-.6f,9.0f, .6f);					// Top Right Of The Quad (Left)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-.6f,9.0f,-.6f);					// Top Left Of The Quad (Left)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-.6f,6.0f,-.6f);					// Bottom Left Of The Quad (Left)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(-.6f,6.0f, .6f);					// Bottom Right Of The Quad (Left)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f(.6f, 9.0f,-.6f);					// Top Right Of The Quad (Right)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f( .6f,9.0f,.6f);					// Top Left Of The Quad (Right)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(.6f,6.0f, .6f);					// Bottom Left Of The Quad (Right)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( .6f,6.0f,-.6f);						// Bottom Right Of The Quad (Top)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( .6f, 9.0f, .6f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-.6f,9.0f, .6f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-.6f,6.0f, .6f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( .6f,6.0f, .6f);					// Bottom Right Of The Quad (Front)

		glTexCoord2f(1.0f, 1.0f);		glVertex3f( .6f,6.0f,-.6f);					// Top Right Of The Quad (Back)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(-.6f,6.0f,-.6f);					// Top Left Of The Quad (Back)
		glTexCoord2f(0.0f, 0.0f);		glVertex3f(-.6f,9.0f,-.6f);					// Bottom Left Of The Quad (Back)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f( .6f,9.0f,-.6f);

		glEnd();

		glBindTexture(GL_TEXTURE_2D, texture[87]);

    glBegin(GL_QUADS);

		glColor3f(1.0f,1.0f,1.0f);
					// Bottom Right Of The Quad (Back)
		glTexCoord2f(0.0f, 0.0f);		glVertex3f(-.6f,10.0f, .6f);					// Top Right Of The Quad (Left)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-.6f,10.0f,-.6f);					// Top Left Of The Quad (Left)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-.6f,9.0f,-.6f);					// Bottom Left Of The Quad (Left)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(-.6f,9.0f, .6f);					// Bottom Right Of The Quad (Left)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f(.6f, 10.0f,-.6f);					// Top Right Of The Quad (Right)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f( .6f,10.0f,.6f);					// Top Left Of The Quad (Right)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(.6f,9.0f, .6f);					// Bottom Left Of The Quad (Right)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( .6f,9.0f,-.6f);						// Bottom Right Of The Quad (Top)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( .6f, 10.0f, .6f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-.6f,10.0f, .6f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-.6f,9.0f, .6f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( .6f,9.0f, .6f);					// Bottom Right Of The Quad (Front)

		glTexCoord2f(1.0f, 1.0f);		glVertex3f( .6f,9.0f,-.6f);					// Top Right Of The Quad (Back)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(-.6f,9.0f,-.6f);					// Top Left Of The Quad (Back)
		glTexCoord2f(0.0f, 0.0f);		glVertex3f(-.6f,10.0f,-.6f);					// Bottom Left Of The Quad (Back)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f( .6f,10.0f,-.6f);

		glEnd();


        glPushMatrix();
        glTranslatef(2,0.0f,0.0f);
        bottle();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-1.5 ,0.0f,0.0f);
        glass();
        glPopMatrix();

}

void TableDecoration()                      //OK
{
     glBindTexture(GL_TEXTURE_2D, texture[79]);

    glBegin(GL_QUADS);
		glColor3f(1.0f,1.0f,1.0f);
		glTexCoord2f(0.0f, 0.0f);		glVertex3f(-.6f,9.0f, .6f);					// Top Right Of The Quad (Left)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-.6f,9.0f,-.6f);					// Top Left Of The Quad (Left)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-.6f,6.0f,-.6f);					// Bottom Left Of The Quad (Left)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(-.6f,6.0f, .6f);					// Bottom Right Of The Quad (Left)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f(.6f, 9.0f,-.6f);					// Top Right Of The Quad (Right)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f( .6f,9.0f,.6f);					// Top Left Of The Quad (Right)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(.6f,6.0f, .6f);					// Bottom Left Of The Quad (Right)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( .6f,6.0f,-.6f);						// Bottom Right Of The Quad (Top)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( .6f, 9.0f, .6f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-.6f,9.0f, .6f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-.6f,6.0f, .6f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( .6f,6.0f, .6f);					// Bottom Right Of The Quad (Front)

		glTexCoord2f(1.0f, 1.0f);		glVertex3f( .6f,6.0f,-.6f);					// Top Right Of The Quad (Back)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(-.6f,6.0f,-.6f);					// Top Left Of The Quad (Back)
		glTexCoord2f(0.0f, 0.0f);		glVertex3f(-.6f,9.0f,-.6f);					// Bottom Left Of The Quad (Back)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f( .6f,9.0f,-.6f);

		glEnd();

		glBindTexture(GL_TEXTURE_2D, texture[87]);

    glBegin(GL_QUADS);

		glColor3f(1.0f,1.0f,1.0f);
					// Bottom Right Of The Quad (Back)
		glTexCoord2f(0.0f, 0.0f);		glVertex3f(-.6f,10.0f, .6f);					// Top Right Of The Quad (Left)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-.6f,10.0f,-.6f);					// Top Left Of The Quad (Left)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-.6f,9.0f,-.6f);					// Bottom Left Of The Quad (Left)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(-.6f,9.0f, .6f);					// Bottom Right Of The Quad (Left)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f(.6f, 10.0f,-.6f);					// Top Right Of The Quad (Right)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f( .6f,10.0f,.6f);					// Top Left Of The Quad (Right)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(.6f,9.0f, .6f);					// Bottom Left Of The Quad (Right)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( .6f,9.0f,-.6f);						// Bottom Right Of The Quad (Top)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( .6f, 10.0f, .6f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-.6f,10.0f, .6f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-.6f,9.0f, .6f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( .6f,9.0f, .6f);					// Bottom Right Of The Quad (Front)

		glTexCoord2f(1.0f, 1.0f);		glVertex3f( .6f,9.0f,-.6f);					// Top Right Of The Quad (Back)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(-.6f,9.0f,-.6f);					// Top Left Of The Quad (Back)
		glTexCoord2f(0.0f, 0.0f);		glVertex3f(-.6f,10.0f,-.6f);					// Bottom Left Of The Quad (Back)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f( .6f,10.0f,-.6f);

		glEnd();


        glPushMatrix();
        glTranslatef(2,0.0f,0.0f);
        bottle();
        glPopMatrix();


        glPushMatrix();
        glTranslatef(6,0.0f,0.0f);
        glass();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-6,0.0f,0.0f);
        glass();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-3,0.0f,3.0f);
        glass();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-3,0.0f,-3.0f);
        glass();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(3,0.0f,3.0f);
        glass();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(3,0.0f,-3.0f);
        glass();
        glPopMatrix();
}

void Drinks()
{
     glBindTexture(GL_TEXTURE_2D, texture[79]);

    glPushMatrix();
        glTranslatef(2,0.0f,0.0f);
        bottle();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-2,0.0f,0.0f);
        bottle();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(4,0.0f,0.0f);
        glass();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-4,0.0f,0.0f);
        glass();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-3,0.0f,2.0f);
        glass();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-3,0.0f,-2.0f);
        glass();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(3,0.0f,2.0f);
        glass();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(3,0.0f,-2.0f);
        glass();
        glPopMatrix();
}

void Laptop()
{
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture[15]);
   	glBegin(GL_QUADS);                          //Chair Upper Portion

		glColor3f(1.0f,1.0f,1.0f);
		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 3.0f, 0.9f,-2.5f);					// Top Right Of The Quad (Top)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-1.2f, 0.9f,-2.5f);					// Top Left Of The Quad (Top)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-1.2f, 0.9f, 4.0f);					// Bottom Left Of The Quad (Top)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 3.0f, 0.9f, 4.0f);					// Bottom Right Of The Quad (Top)

		glVertex3f( 3.0f,0.7f, 4.0f);					// Top Right Of The Quad (Bottom)
		glVertex3f(-1.2f,0.7f, 4.0f);					// Top Left Of The Quad (Bottom)
		glVertex3f(-1.2f,0.7f,-2.50f);					// Bottom Left Of The Quad (Bottom)
		glVertex3f( 3.0f,0.7f,-2.5f);					// Bottom Right Of The Quad (Bottom)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 3.0f, 0.9f, 4.0f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-1.2f, 0.9f, 4.0f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-1.2f,0.7f, 4.0f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 3.0f,0.7f, 4.0f);					// Bottom Right Of The Quad (Front)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 3.0f,0.7f,-2.5f);					// Top Right Of The Quad (Back)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-1.2f,0.7f,-2.5f);					// Top Left Of The Quad (Back)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-1.2f, 0.9f,-2.5f);					// Bottom Left Of The Quad (Back)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 3.0f, 0.9f,-2.5f);					// Bottom Right Of The Quad (Back)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f(-1.2f, 0.9f, 4.0f);					// Top Right Of The Quad (Left)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-1.2f, 0.9f,-2.5f);					// Top Left Of The Quad (Left)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-1.2f,0.7f,-2.5f);					// Bottom Left Of The Quad (Left)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(-1.2f,0.7f, 4.0f);					// Bottom Right Of The Quad (Left)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 3.0f, 0.9f,-2.5f);					// Top Right Of The Quad (Right)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f( 3.0f, 0.9f, 4.0f);					// Top Left Of The Quad (Right)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f( 3.0f,0.7f, 4.0f);					// Bottom Left Of The Quad (Right)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 3.0f,0.7f,-2.5f);					// Bottom Left Of The Quad (Right)
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, texture[14]);
	glRotatef(90.0, 0.0, 0.0, 1.0);
   	glBegin(GL_QUADS);                          //Chair Lower Portion

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 5.2f, -2.8f,-2.5f);					// Top Right Of The Quad (Top)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(0.8f, -2.8f,-2.5f);					// Top Left Of The Quad (Top)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(0.8f, -2.8f, 4.0f);					// Bottom Left Of The Quad (Top)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(5.2f, -2.8f, 4.0f);					// Bottom Right Of The Quad (Top)

		glVertex3f( 5.2f,-3.0f, 4.0f);					// Top Right Of The Quad (Bottom)
		glVertex3f(0.8f,-3.0f, 4.0f);					// Top Left Of The Quad (Bottom)
		glVertex3f(0.8f,-3.0f,-2.50f);					// Bottom Left Of The Quad (Bottom)
		glVertex3f( 5.2f,-3.0f,-2.5f);					// Bottom Right Of The Quad (Bottom)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 5.2f, -2.8f, 4.0f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(0.8f, -2.8f, 4.0f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(0.8f,-3.0f, 4.0f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 5.2f,-3.0f, 4.0f);					// Bottom Right Of The Quad (Front)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 5.2f,-3.0f,-2.5f);					// Top Right Of The Quad (Back)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(1.0f,-3.0f,-2.5f);					// Top Left Of The Quad (Back)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(0.8f, -2.8f,-2.5f);					// Bottom Left Of The Quad (Back)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 5.2f, -2.8f,-2.5f);					// Bottom Right Of The Quad (Back)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f(0.8f, -2.8f, 4.0f);					// Top Right Of The Quad (Left)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(0.8f, -2.8f,-2.5f);					// Top Left Of The Quad (Left)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(0.8f,-3.0f,-2.5f);					// Bottom Left Of The Quad (Left)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(0.8f,-3.0f, 4.0f);					// Bottom Right Of The Quad (Left)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( 5.2f, -2.8f,-2.5f);					// Top Right Of The Quad (Right)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f( 5.2f, -2.8f, 4.0f);					// Top Left Of The Quad (Right)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f( 5.2f,-3.0f, 4.0f);					// Bottom Left Of The Quad (Right)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 5.2f,-3.0f,-2.5f);					// Bottom Left Of The Quad (Right)
	glEnd();
    glPopMatrix();
}

void Fruits()                               //OK
{
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture[79]);

    glBegin(GL_QUADS);
		glColor3f(1.0f,1.0f,1.0f);
		glTexCoord2f(0.0f, 0.0f);		glVertex3f(-.6f,7.0f, 1.6f);					// Top Right Of The Quad (Left)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-.6f,7.0f,-.6f);					// Top Left Of The Quad (Left)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-.6f,6.0f,-.6f);					// Bottom Left Of The Quad (Left)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(-.6f,6.0f, 1.6f);					// Bottom Right Of The Quad (Left)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f(.6f, 7.0f,-.6f);					// Top Right Of The Quad (Right)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f( .6f,7.0f,1.6f);					// Top Left Of The Quad (Right)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(.6f,6.0f, 1.6f);					// Bottom Left Of The Quad (Right)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( .6f,6.0f,-.6f);						// Bottom Right Of The Quad (Top)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( .6f, 7.0f, 1.6f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-.6f,7.0f, 1.6f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-.6f,6.0f, 1.6f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( .6f,6.0f, 1.6f);					// Bottom Right Of The Quad (Front)

		glTexCoord2f(1.0f, 1.0f);		glVertex3f( .6f,6.0f,-.6f);					// Top Right Of The Quad (Back)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(-.6f,6.0f,-.6f);					// Top Left Of The Quad (Back)
		glTexCoord2f(0.0f, 0.0f);		glVertex3f(-.6f,7.0f,-.6f);					// Bottom Left Of The Quad (Back)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f( .6f,7.0f,-.6f);

    glEnd();
    glPopMatrix();

    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture[20]);
    glBegin(GL_QUADS);
		glColor3f(1.0f,1.0f,1.0f);
		glTexCoord2f(0.0f, 0.0f);		glVertex3f(-.6f,7.6f, 1.6f);					// Top Right Of The Quad (Left)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-.6f,7.6f,-.6f);					// Top Left Of The Quad (Left)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-.6f,7.0f,-.6f);					// Bottom Left Of The Quad (Left)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(-.6f,7.0f, 1.6f);					// Bottom Right Of The Quad (Left)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f(.6f, 7.6f,-.6f);					// Top Right Of The Quad (Right)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f( .6f,7.6f,1.6f);					// Top Left Of The Quad (Right)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(.6f,7.0f, 1.6f);					// Bottom Left Of The Quad (Right)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( .6f,7.0f,-.6f);						// Bottom Right Of The Quad (Top)

		glTexCoord2f(0.0f, 0.0f);		glVertex3f( .6f, 7.6f, 1.6f);					// Top Right Of The Quad (Front)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-.6f,7.6f, 1.6f);					// Top Left Of The Quad (Front)
		glTexCoord2f(1.0f, 1.0f);		glVertex3f(-.6f,7.0f, 1.6f);					// Bottom Left Of The Quad (Front)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( .6f,7.0f, 1.6f);					// Bottom Right Of The Quad (Front)

		glTexCoord2f(1.0f, 1.0f);		glVertex3f( .6f,7.6f,-.6f);					// Top Right Of The Quad (Back)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f(-.6f,7.6f,-.6f);					// Top Left Of The Quad (Back)
		glTexCoord2f(0.0f, 0.0f);		glVertex3f(-.6f,7.0f,-.6f);					// Bottom Left Of The Quad (Back)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f( .6f,7.0f,-.6f);

    glEnd();
    glPopMatrix();

}

void drawSnowMan()
{
	glPushMatrix();
	glTranslatef(-20.0f,8.2f,0.0f);

    roof();
	ground();
    frontwall();
    backwall();

    wall1();
    inleft();       //Wall 2
    inright();      //Wall 3

    glPushMatrix();
        glTranslatef(35.0f, 25.0f, 80.0f);
         Front();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(35.0f, 25.0f, -100.0f);
        glRotated(180,0,1,0);
         Back();
    glPopMatrix();

 	//DOOR

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	glTranslatef(41.0f, 10.0f, 52.0f);
    glBegin(GL_POLYGON);
      DrawEllipse(20.0, -5.0, -10.0, 8.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(41.0f, 10.0f, 42.0f);
    glBegin(GL_POLYGON);
      DrawEllipse(20.0, -5.0, -10.0, 8.0);
	glEnd();
	glPopMatrix();

	//Stairs

	glPushMatrix();
	glTranslatef(58.3f, -7.0f, 35.0f);
    glBegin(GL_POLYGON);
       NormalPolygon();
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(55.3f, -5.5f, 35.0f);
    glBegin(GL_POLYGON);
       NormalPolygon();
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(52.3f, -4.0f, 35.0f);
    glBegin(GL_POLYGON);
       NormalPolygon();
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(49.3f, -2.5f, 35.0f);
    glBegin(GL_POLYGON);
       NormalPolygon();
	glEnd();
	glPopMatrix();

	//Labels

    glPushMatrix();
    // glBindTexture(GL_TEXTURE_2D, texture[2]);
	glTranslatef(15.0f, 25.5f, 37.5f);
	glRotatef(180.0, 1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
       LabelPolygon();
	glEnd();
	glPopMatrix();

	//Room Identity
    glBindTexture(GL_TEXTURE_2D, texture[60]);
        glPushMatrix();                         //Wall1
        glTranslatef(31.5f, 17.0f, 43.7f);
        glRotatef(90.0, 0.0, 1.0, 0.0);
        glBegin(GL_POLYGON);
           RoomLabelPolygon();
        glEnd();
        glPopMatrix();

	glPushMatrix();
	 glBindTexture(GL_TEXTURE_2D, texture[27]);
	glTranslatef(31.5f, 17.0f, 35.7f);         //Wall2
	glRotatef(90.0, 0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
       RoomLabelPolygon();
	glEnd();
	glPopMatrix();

	glPushMatrix();
	 glBindTexture(GL_TEXTURE_2D, texture[66]);
	glTranslatef(31.5f, 17.0f, -19.7f);          //Wall3
	glRotatef(90.0, 0.0, 1.0, 0.0);
	//glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
       RoomLabelPolygon();
	glEnd();
	glPopMatrix();

	//Pakha

    glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
	glTranslatef(58.5f, 14.0f, -10.7f);          //Pakha Front
       PlaneFan(4.0, 90.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(75.5f, 14.0f, -10.7f);          //Pakha Front Cylinder
       gluCylinder(Quadric, 5.0, 5.0, 13.0, 30.0, 30.0);
        gluDisk(Quadric, 0.0, 5.0, 30.0, 1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(75.5f, 14.0f, 2.3f);          //Pakha Front Disk + Fan
	glRotatef(180, 1.0, 0.0, 0.0);
	glBindTexture(GL_TEXTURE_2D, texture[6]);
        gluDisk(Quadric, 0.0, 5.0, 30.0, 1.0);
	glPopMatrix();

    glPushMatrix();
	glTranslatef(3.5f, 14.0f, -10.7f);          //Pakha Back
       PlaneFanRight(4.0, -80.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-8.5f, 14.0f, -10.7f);                 //Pakha Back Cylinder
       gluCylinder(Quadric, 5.0, 5.0, 13.0, 30.0, 30.0);
       gluDisk(Quadric, 0.0, 5.0, 30.0, 1.0);
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, texture[6]);
	glTranslatef(-8.5f, 14.0f, 2.3f);          //Pakha Back Disk + Fan
	glRotatef(180, 1.0, 0.0, 0.0);
        gluDisk(Quadric, 0.0, 5.0, 30.0, 1.0);
	glPopMatrix();

    glPushMatrix();
	glTranslatef(30.5f, 21.0f, -107.0f);          //Pakha Back
       PlaneFanBack();
	glPopMatrix();

    glPushMatrix();
	glTranslatef(35.5f, 33.0f, -120.7f);          //Small Pakha Front
       PlaneFan(4.0, 40.0);
	glPopMatrix();

    glPushMatrix();
	glTranslatef(35.5f, 33.0f, -120.7f);          //Small Pakha Back
       PlaneFanRight(4.0, -40.0);
	glPopMatrix();

	//Dining Room

	glPushMatrix();
	glTranslatef(10.5f, 12.0f, 49.7f);      //Dinning Table
       DiningTable(0.5, -2.5);
	glPopMatrix();

	glPushMatrix();                         //Leg 1
	glTranslatef(23.5f, -3.0f, 44.7f);
        TableLeg();
	glPopMatrix();

	glPushMatrix();                          //Leg 2
	glTranslatef(23.5f, -3.0f, 58.7f);
        TableLeg();
	glPopMatrix();

	glPushMatrix();                         //Food Corner Label
	glBindTexture(GL_TEXTURE_2D, texture[85]);
	glTranslatef(39.5f, 17.0f, 48.7f);
    glBegin(GL_POLYGON);
       RoomLabelPolygon();
	glEnd();
	glPopMatrix();

	glPushMatrix();                         //Food Corner
	glTranslatef(32.5f, 12.0f, 48.7f);
       FoodCorners(1.5, -8.5);
	glPopMatrix();


    glPushMatrix();                         //Drinks Corner Label
    glBindTexture(GL_TEXTURE_2D, texture[86]);
	glTranslatef(39.5f, 17.0f, 63.7f);
    glBegin(GL_POLYGON);
       RoomLabelPolygon();
	glEnd();
	glPopMatrix();

    glPushMatrix();                         //Drinks Corner
	glTranslatef(32.5f, 12.0f, 63.0f);
       FoodCorners(1.5, -8.5);
	glPopMatrix();

	 glPushMatrix();                         //Drinks Bottle + Vash
	glTranslatef(41.0f, 7.5f, 63.7f);
	glRotatef(90.0, 0.0, 1.0, 0.0);
        Drinks();
	glPopMatrix();

    glPushMatrix();                         //Drinks Bottle
	glTranslatef(41.0f, 7.5f, 63.7f);
	glRotatef(90.0, 0.0, 1.0, 0.0);
	glColor3f(255.0/255.0, 265.0/255.0, 0.0/255.0);
        bottle();
	glPopMatrix();

	 glPushMatrix();                         //Drinks Bottle
	glTranslatef(43.0f, 7.5f, 64.2f);
	glRotatef(90.0, 0.0, 1.0, 0.0);
	glColor3f(250.0/255.0, 128.0/255.0, 214.0/255.0);
        bottle();
	glPopMatrix();

	glPushMatrix();                         //Drinks Bottle
	glTranslatef(43.0f, 7.5f, 61.5f);
	glRotatef(90.0, 0.0, 1.0, 0.0);
	glColor3f(255.0/255.0, 99.0/255.0, 71.0/255.0);
        bottle();
	glPopMatrix();

	glPushMatrix();                         //Drinks Bottle
	glTranslatef(43.0f, 7.5f, 63.0f);
	glRotatef(90.0, 0.0, 1.0, 0.0);
	glColor3f(255.0/255.0, 182.0/255.0, 193.0/255.0);
        bottle();
	glPopMatrix();

	glPushMatrix();
    glTranslatef(39.5f, 15.0f, 52.9f);      //Food Corner Buffet
    glRotatef(90.0, 1.0, 0.0, 0.0);
    Cooker();
	glPopMatrix();

	glPushMatrix();
    glTranslatef(39.5f, 15.0f, 45.9f);      //Food Corner Buffet
    glRotatef(90.0, 1.0, 0.0, 0.0);
    Cooker();
	glPopMatrix();

	glPushMatrix();
    glTranslatef(41.5f, 7.5f, 48.9f);      //Fruits
    Fruits();
	glPopMatrix();

    glColor3f(0.0, 0.0, 0.0);
	glPushMatrix();
        glTranslatef(39.5f, 15.2f, 45.9f);      //Food Corner Buffet
        glRotatef(90.0, 1.0, 0.0, 0.0);
        gluCylinder(Quadric, .3, .3, .2, 30.0, 30.0);
    glPopMatrix();

    glColor3f(0.0, 0.0, 0.0);
	glPushMatrix();
        glTranslatef(39.5f, 15.2f, 52.9f);      //Food Corner Buffet
        glRotatef(90.0, 1.0, 0.0, 0.0);
        gluCylinder(Quadric, .3, .3, .2, 30.0, 30.0);
    glPopMatrix();

	glPushMatrix();                         //Dining Chair left
	glTranslatef(22.5f, 8.0f, 45.0f);
	glRotatef(90.0, 0.0, 1.0, 0.0);
      Chair();
	glPopMatrix();

	glPushMatrix();                         //Dining Chair right
	glTranslatef(22.5f, 8.0f, 70.0f);
	glRotatef(270.0, 0.0, 1.0, 0.0);
      Chair();
	glPopMatrix();

	glPushMatrix();                         //Dining Chair LL
	glTranslatef(28.5f, 8.0f, 53.0f);
	glRotatef(360.0, 0.0, 1.0, 0.0);
      Chair();
	glPopMatrix();

	glPushMatrix();                         //Dining Chair RR
	glTranslatef(28.5f, 8.0f, 63.0f);
	glRotatef(360.0, 0.0, 1.0, 0.0);
      Chair();
	glPopMatrix();

	glPushMatrix();                         //Table Cloth
	glTranslatef(24.5f, 6.3f, 52.5f);
	glRotatef(90.0, 0.0, 1.0, 0.0);
      TableCloth();
	glPopMatrix();

	glPushMatrix();                         //Table Cloth
	glTranslatef(22.7f, 6.3f, 71.5f);
	glRotatef(90.0, 0.0, 1.0, 0.0);
      TableCloth();
	glPopMatrix();

    glPushMatrix();                         //Table Cloth
	glTranslatef(21.8f, 6.3f, 63.0f);
	glRotatef(360.0, 0.0, 1.0, 0.0);
      TableCloth();
	glPopMatrix();

    glPushMatrix();                         //Table Cloth
	glTranslatef(21.8f, 6.3f, 53.0f);
	glRotatef(360.0, 0.0, 1.0, 0.0);
      TableCloth();
	glPopMatrix();

	glPushMatrix();                         //Table Plate
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glTranslatef(25.0f, 12.9f, 47.0f);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
      gluDisk(Quadric, 0.0, 1.4, 30.0, 1.0);
	glPopMatrix();

	glPushMatrix();                         //Table Plate
	glTranslatef(23.0f, 12.9f, 65.7f);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
      gluDisk(Quadric, 0.0, 1.4, 30.0, 1.0);
	glPopMatrix();

	glPushMatrix();                         //Table Plate
	glTranslatef(27.3f, 12.9f, 63.0f);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
      gluDisk(Quadric, 0.0, 1.4, 30.0, 1.0);
	glPopMatrix();

	glPushMatrix();                         //Table Plate
	glTranslatef(27.3f, 12.9f, 53.0f);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
      gluDisk(Quadric, 0.0, 1.4, 30.0, 1.0);
	glPopMatrix();

	glPushMatrix();                         //Table glass
	glTranslatef(20.3f, 6.5f, 47.0f);
        glass();
	glPopMatrix();

	glPushMatrix();                         //Table glass
	glTranslatef(19.1f, 6.5f, 66.8f);
        glass();
	glPopMatrix();

	glPushMatrix();                         //Table glass
	glTranslatef(26.0f, 6.5f, 59.3f);
        glass();
	glPopMatrix();

	glPushMatrix();                         //Table glass
	glTranslatef(26.0f, 6.5f, 49.7f);
        glass();
	glPopMatrix();

	glPushMatrix();                         //Table Bottle + Vash
	glTranslatef(20.0f, 6.5f, 57.7f);
	glRotatef(90.0, 0.0, 1.0, 0.0);
        Vash();
	glPopMatrix();

	glPushMatrix();                         //Table Bottle + Vash
	glTranslatef(20.0f, 6.5f, 57.7f);
	glRotatef(90.0, 0.0, 1.0, 0.0);
        Vash();
	glPopMatrix();

    //Bedroom

    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture[6]);
	glTranslatef(10.5f, 10.0f, -80.7f);
       Bed(0.5, -5.5);
	glPopMatrix();

	glPushMatrix();                         //Bed Wood
	glBindTexture(GL_TEXTURE_2D, texture[3]);
	glTranslatef(10.5f, 5.0f, -80.7f);
       Bed(0.5, -2.0);
	glPopMatrix();

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, texture[6]);                        //Balish 1
	glTranslatef(15.5f, 6.5f, -70.7f);
      Balish();
	glPopMatrix();

	glPushMatrix();                            //Balish 1
	glBindTexture(GL_TEXTURE_2D, texture[6]);
	glTranslatef(15.5f, 6.5f, -80.7f);
      Balish();
	glPopMatrix();

    glPushMatrix();                         //Almari
	glTranslatef(35.5f, 22.0f, -45.7f);
       Almari();
	glPopMatrix();

	glPushMatrix();                         //Bed table
	glTranslatef(13.5f, 8.0f, -59.0f);
       FoodCorners(0.5, -5.5);
	glPopMatrix();

	glPushMatrix();
      glTranslatef(23.0, 3.1f, -59.5f);
      glRotatef(90.0, 0.0, 1.0, 0.0);
        Vash();
    glPopMatrix();

	glPushMatrix();                         //LCD TV
	glTranslatef(45.5f, 15.0f, -77.0f);
       LCDTV();
	glPopMatrix();

	glPushMatrix();                         //LCD TV
	glTranslatef(25.0f, 8.0f, -54.0f);
	glRotatef(180.0, 0.0, 1.0, 0.0);
       Laptop();
	glPopMatrix();

    //Window Shape

    glPushMatrix();                     //Window Front 1
    glTranslatef(61.5f, 30.0f, 10.0f);
    Window();
	glPopMatrix();

	glPushMatrix();
    glTranslatef(61.5f, 30.0f, 0.0f);  //Window Front 2
    Window();
	glPopMatrix();

	glPushMatrix();
    glTranslatef(61.5f, 30.0f, -10.0f);  //Window Front 3
    Window();
	glPopMatrix();

	glPushMatrix();
    glTranslatef(61.5f, 30.0f, -20.0f);  //Window Front 4
    Window();
	glPopMatrix();

	glPushMatrix();
    glTranslatef(61.5f, 30.0f, -30.0f);  //Window Front 5
    Window();
	glPopMatrix();

	glPushMatrix();
    glTranslatef(61.5f, 30.0f, -40.0f);  //Window Front 6
    Window();
	glPopMatrix();

	glPushMatrix();
    glTranslatef(61.5f, 30.0f, -50.0f);  //Window Front 7
    Window();
	glPopMatrix();

	glPushMatrix();
    glTranslatef(61.5f, 30.0f, -60.0f);  //Window Front 8
    Window();
	glPopMatrix();

	glPushMatrix();
    glTranslatef(61.5f, 30.0f, -70.0f);  //Window Front 9
    Window();
	glPopMatrix();

	glPushMatrix();
    glTranslatef(61.5f, 30.0f, 60.0f);  //Window Front Differennt
    Window();
	glPopMatrix();

	glPushMatrix();                     //Window Back 1
    glTranslatef(9.5f, 30.0f, 10.0f);
    Window();
	glPopMatrix();

	glPushMatrix();
    glTranslatef(9.5f, 30.0f, 0.0f);  //Window Back 2
    Window();
	glPopMatrix();

	glPushMatrix();
    glTranslatef(9.5f, 30.0f, -10.0f);  //Window Back 3
    Window();
	glPopMatrix();

	glPushMatrix();
    glTranslatef(9.5f, 30.0f, -20.0f);  //Window Back 4
    Window();
	glPopMatrix();

	glPushMatrix();
    glTranslatef(9.5f, 30.0f, -30.0f);  //Window Back 5
    Window();
	glPopMatrix();

	glPushMatrix();
    glTranslatef(9.5f, 30.0f, -40.0f);  //Window Back 6
    Window();
	glPopMatrix();

	glPushMatrix();
    glTranslatef(9.5f, 30.0f, -50.0f);  //Window Back 7
    Window();
	glPopMatrix();

	glPushMatrix();
    glTranslatef(9.5f, 30.0f, -60.0f);  //Window Back 8
    Window();
	glPopMatrix();

	glPushMatrix();
    glTranslatef(9.5f, 30.0f, -70.0f);  //Window Back 9
    Window();
	glPopMatrix();

	glPushMatrix();                     //Window Back 10
    glTranslatef(9.5f, 30.0f, 20.0f);
    Window();
	glPopMatrix();

	glPushMatrix();                     //Window Back 11
    glTranslatef(9.5f, 30.0f, 30.0f);
    Window();
	glPopMatrix();

	glPushMatrix();
    glTranslatef(9.5f, 30.0f, 60.0f);  //Window Back Differennt
    Window();
	glPopMatrix();

	//Door

	glPushMatrix();
    glTranslatef(58.5f, 20.0f, 32.0f);
    Door();
	glPopMatrix();

	//Front Operating Window

	glPushMatrix();                         //Back
    glTranslatef(28.5f, 28.0f, 82.0f);
        glutSolidCone(22.0, 30.0, 30, 1);
	glPopMatrix();

	glPushMatrix();
    glTranslatef(41.0f, 28.0f, 82.0f);
        glutSolidCone(22.0, 30.0, 30, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(34.6f, 27.0f, 82.5f);
        gluCylinder(Quadric, 25.0, 5.3, 29.5, 30.0, 30.0);
    glPopMatrix();

	//Arts
	glPushMatrix();
	glTranslatef(11.7f,15.0f,53.9f);
	glRotatef(90.0, 0.0, 1.0, 0.0);
	glBindTexture(GL_TEXTURE_2D, texture[8]);
    arts();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(51.7f,15.0f,50.9f);
	glRotatef(270.0, 0.0, 1.0, 0.0);
	glBindTexture(GL_TEXTURE_2D, texture[89]);
    arts();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(51.7f,15.0f,63.9f);
	glRotatef(270.0, 0.0, 1.0, 0.0);
	glBindTexture(GL_TEXTURE_2D, texture[24]);
    arts();
	glPopMatrix();

	//Inner Window

	glPushMatrix();                         //Left Window
	glTranslatef(51.7f,10.0f,18.9f);
	glRotatef(270.0, 0.0, 1.0, 0.0);
	glBindTexture(GL_TEXTURE_2D, texture[4]);
    InnerWindow();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(51.7f,10.0f,13.9f);
	glRotatef(270.0, 0.0, 1.0, 0.0);
	glBindTexture(GL_TEXTURE_2D, texture[4]);
    InnerWindow();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(51.7f,10.0f,8.9f);
	glRotatef(270.0, 0.0, 1.0, 0.0);
	glBindTexture(GL_TEXTURE_2D, texture[4]);
    InnerWindow();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(51.7f,10.0f,3.9f);
	glRotatef(270.0, 0.0, 1.0, 0.0);
	glBindTexture(GL_TEXTURE_2D, texture[4]);
    InnerWindow();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(51.7f,10.0f,-2.9f);
	glRotatef(270.0, 0.0, 1.0, 0.0);
	glBindTexture(GL_TEXTURE_2D, texture[4]);
    InnerWindow();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(51.7f,10.0f,-7.9f);
	glRotatef(270.0, 0.0, 1.0, 0.0);
	glBindTexture(GL_TEXTURE_2D, texture[4]);
    InnerWindow();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(51.7f,10.0f,-12.9f);
	glRotatef(270.0, 0.0, 1.0, 0.0);
	glBindTexture(GL_TEXTURE_2D, texture[4]);
    InnerWindow();
	glPopMatrix();

	glPushMatrix();                         //Right Window
	glTranslatef(13.7f,10.0f,18.9f);
	glRotatef(90.0, 0.0, 1.0, 0.0);
	glBindTexture(GL_TEXTURE_2D, texture[4]);
    InnerWindow();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(19.7f,10.0f,13.9f);
	glRotatef(270.0, 0.0, 1.0, 0.0);
	glBindTexture(GL_TEXTURE_2D, texture[4]);
    InnerWindow();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(19.7f,10.0f,8.9f);
	glRotatef(270.0, 0.0, 1.0, 0.0);
	glBindTexture(GL_TEXTURE_2D, texture[4]);
    InnerWindow();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(19.7f,10.0f,3.9f);
	glRotatef(270.0, 0.0, 1.0, 0.0);
	glBindTexture(GL_TEXTURE_2D, texture[4]);
    InnerWindow();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(19.7f,10.0f,-2.9f);
	glRotatef(270.0, 0.0, 1.0, 0.0);
	glBindTexture(GL_TEXTURE_2D, texture[4]);
    InnerWindow();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(19.7f,10.0f,-7.9f);
	glRotatef(270.0, 0.0, 1.0, 0.0);
	glBindTexture(GL_TEXTURE_2D, texture[4]);
    InnerWindow();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(19.7f,10.0f,-12.9f);
	glRotatef(270.0, 0.0, 1.0, 0.0);
	glBindTexture(GL_TEXTURE_2D, texture[4]);
    InnerWindow();
	glPopMatrix();

//Operating Windows

	glPushMatrix();
	glTranslatef(22.0f, 22.0f, 90.2f);
	glBindTexture(GL_TEXTURE_2D, texture[88]);
    Front_Window();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(32.0f, 22.0f, 90.2f);
    Front_Window();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(42.0f, 22.0f, 90.2f);
    Front_Window();
	glPopMatrix();

	//ROAD
	glPushMatrix();
	glTranslatef(140.0f,0.0f,0.0f);
	glBindTexture(GL_TEXTURE_2D, texture[11]);
	glBegin(GL_QUADS);

		glColor3f(1.0f,1.0f,1.0f);
		glTexCoord2f(1.0f, 1.0f);		glVertex3f( 80.0f,- 2.88f, 0.6f);					// Top Right Of The Quad (Top)
		glTexCoord2f(1.0f, 0.0f);		glVertex3f(-180.0f, -2.88f, 0.6f);					// Top Left Of The Quad (Top)
		glTexCoord2f(0.0f, 0.0f);		glVertex3f(-180.0f, -2.88f, 70.6f);					// Bottom Left Of The Quad (Top)
		glTexCoord2f(0.0f, 1.0f);		glVertex3f( 80.0f, -2.88f, 70.6f);
	glEnd();
	glPopMatrix();

	//Table
	glPushMatrix();
	glTranslatef(42.0f,6.0f,24);
	glRotatef(90.0, 0.0, 1.0, 0.0);
	tab();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(23.0f, 6.0f, 24);
	glRotatef(90.0, 0.0, 1.0, 0.0);
	tab();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(42.0f,6.0f,10);
	glRotatef(90.0, 0.0, 1.0, 0.0);
	tab();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(23.0f, 6.0f, 10);
	glRotatef(90.0, 0.0, 1.0, 0.0);
	tab();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(42.0f,6.0f,-4);
	glRotatef(90.0, 0.0, 1.0, 0.0);
	tab();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(23.0f, 6.0f, -4);
	glRotatef(90.0, 0.0, 1.0, 0.0);
	tab();
	glPopMatrix();

	glPushMatrix();
      glTranslatef(41.0, 0.5f, 18.0f);
        Vash();
    glPopMatrix();

    glPushMatrix();
      glTranslatef(24.0, 0.5f, 18.0f);
        Vash();
    glPopMatrix();

    glPushMatrix();
      glTranslatef(41.0, 0.5f, 3.0f);
        Vash();
    glPopMatrix();

    glPushMatrix();
      glTranslatef(23.0, 0.5f, 3.0f);
        Vash();
    glPopMatrix();

    glPushMatrix();
      glTranslatef(41.0, 0.5f, -11.0f);
        Vash();
    glPopMatrix();

    glPushMatrix();
      glTranslatef(23.0, 0.5f, -11.0f);
        Vash();
    glPopMatrix();

	//Sitting Arrangement

	glPushMatrix();
        glTranslatef(40.0f, 4.0f, 10.0);
        glRotatef(90.0f,0.0f,1.0f,0.0f);
        Sofa();
        SofaStable();
        Handle();
        glPopMatrix();
        glPushMatrix();
        glTranslatef(35.5f, 4.0f, 10.0);
        glRotatef(90.0f,0.0f,1.0f,0.0f);
        Handle();
        glPopMatrix();
        glPushMatrix();
        glTranslatef(31.5f, 4.0f, 10.0);
        glRotatef(90.0f,0.0f,1.0f,0.0f);
        Handle();
	glPopMatrix();

    glPushMatrix();
        glTranslatef(21.0f, 4.0f, 10.0);
        glRotatef(90.0f,0.0f,1.0f,0.0f);
        Sofa();
        SofaStable();
        Handle();
        glPopMatrix();
        glPushMatrix();
        glTranslatef(16.5f, 4.0f, 10.0);
        glRotatef(90.0f,0.0f,1.0f,0.0f);
        Handle();
        glPopMatrix();
        glPushMatrix();
        glTranslatef(12.5f, 4.0f, 10.0);
        glRotatef(90.0f,0.0f,1.0f,0.0f);
        Handle();
    glPopMatrix();

	glPushMatrix();
    glTranslatef(40.0f, 4.0f, -5.0);
	glRotatef(90.0f,0.0f,1.0f,0.0f);
    Sofa();
    SofaStable();
    Handle();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(35.5f, 4.0f, -5.0);
	glRotatef(90.0f,0.0f,1.0f,0.0f);
	Handle();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(31.5f, 4.0f, -5.0);
	glRotatef(90.0f,0.0f,1.0f,0.0f);
	Handle();
	glPopMatrix();

    glPushMatrix();
    glTranslatef(21.0f, 4.0f, -5.0);
	glRotatef(90.0f,0.0f,1.0f,0.0f);
    Sofa();
    SofaStable();
    Handle();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(16.5f, 4.0f, -5.0);
	glRotatef(90.0f,0.0f,1.0f,0.0f);
	Handle();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(12.5f, 4.0f, -5.0);
	glRotatef(90.0f,0.0f,1.0f,0.0f);
	Handle();
	glPopMatrix();

    glPushMatrix();
    glTranslatef(40.0f, 4.0f, -20.0);
	glRotatef(90.0f,0.0f,1.0f,0.0f);
    Sofa();
    SofaStable();
    Handle();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(35.5f, 4.0f, -20.0);
	glRotatef(90.0f,0.0f,1.0f,0.0f);
	Handle();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(31.5f, 4.0f, -20.0);
	glRotatef(90.0f,0.0f,1.0f,0.0f);
	Handle();
	glPopMatrix();

    glPushMatrix();
    glTranslatef(21.0f, 4.0f, -20.0);
	glRotatef(90.0f,0.0f,1.0f, 0.0f);
    Sofa();
    SofaStable();
    Handle();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(16.5f, 4.0f, -20.0);
	glRotatef(90.0f,0.0f,1.0f,0.0f);
	Handle();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(12.5f, 4.0f, -20.0);
	glRotatef(90.0f,0.0f,1.0f,0.0f);
	Handle();
	glPopMatrix();

	//AC

	glPushMatrix();
	glTranslatef(21.0f,14.0f,23.8f);
	ac();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(46.0f,14.0f,23.8f);
	ac();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(10.0f, 15.0f, -30.8f);
	glRotatef(90.0, 0.0, 1.0, 0.0);
	ac();
	glPopMatrix();

	//Plain Main Body
	glPushMatrix();
	glTranslatef(35.0f,25.0f,-100.0f);
    Body();
    glPopMatrix();

glutSwapBuffers() ;

}

GLuint createDL()
{
    GLuint snowManDL;
    snowManDL = glGenLists(2);
    glNewList(snowManDL+1,GL_COMPILE);
    drawSnowMan();
    glEndList();
    glNewList(snowManDL,GL_COMPILE);
    glPushMatrix();
    glCallList(snowManDL+1);
    glPopMatrix();
    glEndList();
    return(snowManDL);
}

void initScene()
{
	LoadGLTextures();

	glEnable(GL_TEXTURE_2D);

	glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

    snowman_display_list = createDL();
}

void orientMe(float ang)
{

    angle += ang;
    lx = sin(angle);
    lz = -cos(angle);
    glLoadIdentity();
    gluLookAt(x, y, z, x + lx,y + ly,z + lz,0.0f,1.0f,0.0f);
}

void moveMeFlat(float i)
{
   x= x + i*(lx)*.10;
   if(statew == 1 )
   y= y + i*(ly)*.10;
   z= z + i*(lz)*.10;
    glLoadIdentity();
    gluLookAt(x, y, z,x +lx,y +ly,z + lz,0.0f,1.0f,0.0f);
}

void setOrthographicProjection()
{

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0, w, 0, h);
    glScalef(1, -1, 1);
    glTranslatef(0, -h, 0);
    glMatrixMode(GL_MODELVIEW);
}

void resetPerspectiveProjection()
{
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
}

void renderBitmapString(float x, float y, void *font,char *string)
{
  char *c;

  glRasterPos2f(x, y);

  for (c=string; *c != '\0'; c++)
  {
		glutBitmapCharacter(font, *c);
  }
}

void renderScene(void)
{

    if (deltaMove)
        moveMeFlat(deltaMove);

	if(fix == 1)
	{
	if(raf ==1)
     moveMeFlat(.1);
	if(angle> -7.85 && x <=7)
	{
       raf=0;
        orientMe(-.003);
	}

	if(angle <= -7.85 )
	{
        moveMeFlat(.3);
		if(x<= -84)
		{
          orientMe(-.003);
		}
	}
		if( angle <= -9.48 )
      orientMe(.003);

		if(z>30)
			{
             orientMe(-.003);
			}

            if(angle <= -9.6 &&  x>21 && z>-30)
            {
               orientMe(-.0015);
                if(x>62)
                {
                        fix=0;
                        state2=1;
                }
            }
        }

    if (deltaAngle)
	{
      orientMe(deltaAngle);
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     if(state == 1)
     {
         x=0.0f,y=250.80f,z=25.0f;
         lx=0.0f,ly=-8.0f,lz=-1.0f;
         state=0;
     }
     if(state2 == 1)
     {
         x=230.0f,y=6.4f,z=0.0f;
         lx=-18.0f,ly=0.0f,lz=0.0f;
         state2 =0;
    }

    if(state3 == 1)
    {
        ly=0.0f;
        state3=0;
    }
  glLoadIdentity();
  gluLookAt(x, y, z,
             x +lx,y +ly,z +lz,
             0.0f,1.0f,0.0f);
    glColor3f(1.0f, 1.0f,1.0f);

	glBindTexture(GL_TEXTURE_2D, texture[7]);
    glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f);		glVertex3f(-400.0f, -3.0f, -400.0f);
        glTexCoord2f(1.0f, 0.0f);		glVertex3f(-400.0f, -3.0f,  400.0f);
        glTexCoord2f(1.0f, 1.0f);		glVertex3f( 400.0f, -3.0f,  400.0f);
        glTexCoord2f(0.0f, 1.0f);		glVertex3f( 400.0f, -3.0f, -400.0f);
    glEnd();
	glPushMatrix();
	glRotatef(l_t,0.0f,1.0f,0.0f);
	glPushMatrix();
	glRotatef(u_p,1.0f,0.0f,0.0f);

    glCallList(snowman_display_list);

	glPopMatrix();
	glPopMatrix();


    glClearColor(0, 0.7, 1, 0.0);
    setOrthographicProjection();
    glPushMatrix();
    glLoadIdentity();
    glPopMatrix();
    resetPerspectiveProjection();
    glutSwapBuffers();
}

void processNormalKeys(unsigned char key, int x, int y)
{
    if (key == 27)
        exit(0);
}

void pressKey(int key, int x, int y)
{
    switch (key)
	{
        case GLUT_KEY_LEFT : deltaAngle = -0.02f;break;
        case GLUT_KEY_RIGHT : deltaAngle = 0.02f;break;
        case GLUT_KEY_UP : deltaMove = .6;break;
        case GLUT_KEY_DOWN : deltaMove = -.6;break;
    }
}

void releaseKey(int key, int x, int y)
{
    switch (key)
	{
        case GLUT_KEY_LEFT : if (deltaAngle < 0.0f)
                                 deltaAngle = 0.0f;

                             break;
        case GLUT_KEY_RIGHT : if (deltaAngle > 0.0f)
                                 deltaAngle = 0.0f;

                             break;
        case GLUT_KEY_UP :     if (deltaMove > 0)
                                 deltaMove = 0;
                             break;
        case GLUT_KEY_DOWN : if (deltaMove < 0)
                                 deltaMove = 0;
                             break;
    }
}

void spinDisplay(void)
{
	l_t =l_t+.2;
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
   switch (button)
   {
      case GLUT_LEFT_BUTTON:
         if (state == GLUT_DOWN)
            glutIdleFunc(spinDisplay);
         break;
      case GLUT_RIGHT_BUTTON:
         if (state == GLUT_DOWN)
            glutIdleFunc(NULL);
            glutIdleFunc(renderScene);
         break;
      default:
         break;
   }
}

void init()
{
    Quadric = gluNewQuadric();
    gluQuadricNormals(Quadric, GL_SMOOTH);
    gluQuadricTexture(Quadric, GL_TRUE);
   // atexit(clean)
}

void noop(int value)
{
    if(value == 1){
        PlaySound("visit.wav", NULL, SND_ASYNC| SND_FILENAME| SND_LOOP| SND_NOSTOP| SND_NOWAIT);
    }
    else if(value == 2){
        PlaySound("Silent.wav", NULL, SND_ASYNC| SND_FILENAME);
    }
    else exit(0);
    glutPostRedisplay();
}

int main(int argc, char **argv)
{

	 printf("Welcome to the Luxurious Private Jet of The Jet Production Company Limited!\n\n\n");
     printf("Enjoy the tour in the Jet and take a round of every angle!\n\n");
     printf("Keyboard Configuration.\n\t\tPress 'n' Walking View");
     printf("\n\t\tPress 's'   Satellite View");
     printf("\n\t\tPress 'f'   Fixed View");
     printf("\n\t\tPress 'd'   Down");
     printf("\n\t\tPress 'u'   Up");
     printf("\n\t\tPress 'l'   Left");
     printf("\n\t\tPress 'r'   Right\n\n\n");
     printf("\n\t\t\t\tEnjoy!!!\n\n\n");

	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(1200,600);
    glutCreateWindow("Private Jet");
    init();
	glutIgnoreKeyRepeat(1);
    glutKeyboardFunc(processNormalKeys);
    glutSpecialFunc(pressKey);
    glutSpecialUpFunc(releaseKey);
    glutDisplayFunc(renderScene);
    glutIdleFunc(renderScene);
    glutReshapeFunc(changeSize);
    glutMouseFunc(mouse);
    glutKeyboardFunc(my_keyboard);

    PlaySound("visit.wav", NULL, SND_ASYNC| SND_FILENAME| SND_LOOP| SND_NOSTOP| SND_NOWAIT);

    glutCreateMenu(noop);
    glutAddMenuEntry("Play Music", 1);
    glutAddMenuEntry("Stop Music", 2);
    glutAddMenuEntry("Quit", 3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    initScene();
    glutMainLoop();

    return(0);
}
