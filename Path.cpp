//EEPER
#include "Path.h"
#include "libtarga.h"
#include <stdio.h>
#include <GL/glu.h>

Path::~Path(void)
{
	if (initialized)
	{
		glDeleteLists(display_list, 1);
		glDeleteTextures(1, &texture_obj);
	}
}

bool Path::Initialize(void)
{
	ubyte* image_data;
	int image_height, image_width;
	if (!(image_data = (ubyte*)(tga_load("./checker.tga", &image_width, &image_height, TGA_TRUECOLOR_24))))
	{
		return false;
	}
	glGenTextures(1, &texture_obj);
		glBindTexture(GL_TEXTURE_2D, texture_obj);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		gluBuild2DMipmaps(GL_TEXTURE_2D, 3, image_width, image_height, GL_RGB, GL_UNSIGNED_BYTE, image_data);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	display_list = glGenLists(1);
	glNewList(display_list, GL_COMPILE);
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0, 0.0, 1.0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture_obj);
	glBegin(GL_QUADS);

	//EEPER
	glTexCoord2f(0.0, 0.0);
	glVertex3f(5.0, 0.0, 0.1);
	glTexCoord2f(20.0, 0.0);
	glVertex3f(5.0, 45.0, 0.1);
	glTexCoord2f(20.0, 10.0);
	glVertex3f(-5.0, 45.0, 0.1);
	glTexCoord2f(0.0, 10.0);
	glVertex3f(-5.0, 0.0, 0.1);
	
	//l = 45 w = 5
	float hold_l = 30.0;
	float hold_w = 2.0;
	glTexCoord2f(hold_l , hold_w);
	glVertex3f(hold_l, hold_w, 0.1);
	glTexCoord2f(-hold_l, hold_w);
	glVertex3f(-hold_l, hold_w, 0.1);
	glTexCoord2f(-hold_l, -hold_w);
	glVertex3f(-hold_l, -hold_w, 0.1);
	glTexCoord2f(hold_l, -hold_w);
	glVertex3f(hold_l, -hold_w, 0.1);

	hold_l = 2.0;
	hold_w = 10.0;
	glTexCoord2f(hold_l, hold_w);
	glVertex3f(hold_l, hold_w, 0.1);
	glTexCoord2f(-hold_l, hold_w);
	glVertex3f(-hold_l, hold_w, 0.1);
	glTexCoord2f(-hold_l, -hold_w);
	glVertex3f(-hold_l, -hold_w, 0.1);
	glTexCoord2f(hold_l, -hold_w);
	glVertex3f(hold_l, -hold_w, 0.1);

	glEnd();

	glDisable(GL_TEXTURE_2D);
	glEndList();

	initialized = true;

	return true;
}

void Path::Draw(void)
{
	glPushMatrix();
	glTranslatef(20.0, 5.0, 0.0);
	glCallList(display_list);
	glRotatef(180, 0.0, 0.0, 1.0);
	glTranslatef(0.0, 10.0, 0.0);
	glCallList(display_list);
	glPopMatrix();
}
