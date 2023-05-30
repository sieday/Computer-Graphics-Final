#include "Box.h"
#include "libtarga.h"

#include <stdio.h>
#include <GL/glu.h>

// Destructor
Box::~Box()
{
	if (initialized) {
		glDeleteLists(display_list, 1);
		glDeleteTextures(1, &front_texture_obj);
		glDeleteTextures(1, &back_texture_obj);
		glDeleteTextures(1, &side_texture_obj);
	}

}

bool Box::Initialize(void)
{
	ubyte* front_image_data;
	int	    front_image_height, front_image_width;
	ubyte* back_image_data;
	int	    back_image_height, back_image_width;
	ubyte* side_image_data;
	int	    side_image_height, side_image_width;
	ubyte* roof_image_data;
	int		roof_image_height, roof_image_width;

	
	if (!(front_image_data = (ubyte*)tga_load("./pb.tga", &front_image_width,
		&front_image_height, TGA_TRUECOLOR_24))) {
		return false;
	}

	if (!(back_image_data = (ubyte*)tga_load("./checker.tga", &back_image_width,
		&back_image_height, TGA_TRUECOLOR_24))) {
		return false;
	}

	if (!(side_image_data = (ubyte*)tga_load("./checker.tga", &side_image_width,
		&side_image_height, TGA_TRUECOLOR_24))) {
		return false;
	}

	if (!(roof_image_data = (ubyte*)tga_load("./checker.tga", &roof_image_width,
		&roof_image_height, TGA_TRUECOLOR_24))) {
		fprintf(stderr, "Booth::Initialize: Couldn't load side_front.tga\n");
		return false;
	}

	glGenTextures(1, &front_texture_obj);
	glBindTexture(GL_TEXTURE_2D, front_texture_obj);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, front_image_width, front_image_height,
		GL_RGB, GL_UNSIGNED_BYTE, front_image_data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
		GL_NEAREST_MIPMAP_LINEAR);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	glGenTextures(1, &side_texture_obj);
	glBindTexture(GL_TEXTURE_2D, side_texture_obj);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, side_image_width, side_image_height,
		GL_RGB, GL_UNSIGNED_BYTE, side_image_data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
		GL_NEAREST_MIPMAP_LINEAR);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	glGenTextures(1, &back_texture_obj);
	glBindTexture(GL_TEXTURE_2D, back_texture_obj);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, back_image_width, back_image_height,
		GL_RGB, GL_UNSIGNED_BYTE, back_image_data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
		GL_NEAREST_MIPMAP_LINEAR);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	glGenTextures(1, &roof_texture_obj);
	glBindTexture(GL_TEXTURE_2D, roof_texture_obj);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, roof_image_width, roof_image_height,
		GL_RGB, GL_UNSIGNED_BYTE, roof_image_data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
		GL_NEAREST_MIPMAP_LINEAR);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	
	display_list = glGenLists(1);
	glNewList(display_list, GL_COMPILE);

	glTranslatef(-25.0, 0.0, 0.0);

	glColor3f(1.0, 1.0, 1.0);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, front_texture_obj);

	glBegin(GL_QUADS);
	glNormal3f(1.0, 0.0, 0.0);
	glTexCoord2f(0.0, 0.0);			
	glVertex3f(2.5, -5.0, 0.0);
	glTexCoord2f(1.0, 0.0);			
	glVertex3f(2.5, 5.0, 0.0);
	glTexCoord2f(1.0, 1.0);			
	glVertex3f(2.5, 5.0, 4.8);
	glTexCoord2f(0.0, 1.0);			
	glVertex3f(2.5, -5.0, 4.8);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, back_texture_obj);
	glBegin(GL_QUADS);
	glNormal3f(-1.0, 0.0, 0.0);
	glTexCoord2f(0.0, 0.0);			
	glVertex3f(-2.5, 5.0, 0.0);
	glTexCoord2f(1.0, 0.0);			
	glVertex3f(-2.5, -5.0, 0.0);
	glTexCoord2f(1.0, 1.0);			
	glVertex3f(-2.5, -5.0, 4.8);
	glTexCoord2f(0.0, 1.0);			
	glVertex3f(-2.5, 5.0, 4.8);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, side_texture_obj);
	glBegin(GL_QUADS);
	glNormal3f(0.0, -1.0, 0.0);
	glTexCoord2f(0.0, 0.0);			
	glVertex3f(-2.5, -5.0, 0.0);
	glTexCoord2f(0.0, 1.0);			
	glVertex3f(2.5, -5.0, 0.0);
	glTexCoord2f(1.0, 1.0);			
	glVertex3f(2.5, -5.0, 4.8);
	glTexCoord2f(1.0, 0.0);			
	glVertex3f(-2.5, -5.0, 4.8);

	glNormal3f(0.0, 1.0, 0.0);
	glTexCoord2f(0.0, 0.0);			
	glVertex3f(-2.5, 5.0, 0.0);
	glTexCoord2f(0.0, 1.0);			
	glVertex3f(-2.5, 5.0, 4.8);
	glTexCoord2f(1.0, 1.0);			
	glVertex3f(2.5, 5.0, 4.8);
	glTexCoord2f(1.0, 0.0);			
	glVertex3f(2.5, 5.0, 0.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(.803, .498, .196);
	glNormal3f(-0.5391, 0, 0.8423);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0.0, -2.5, 6.4);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(0.0, 2.5, 6.4);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(-2.5, 5.0, 4.8);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-2.5, -5.0, 4.8);
	glNormal3f(0.5391, 0, 0.8423);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0.0, 2.5, 6.4);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(0.0, -2.5, 6.4);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(2.5, -5.0, 4.8);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(2.5, 5.0, 4.8);
	glEnd();

	glDisable(GL_TEXTURE_2D);
	glBegin(GL_TRIANGLES);
	glNormal3f(0.0, -0.5391, 0.8423);
	glVertex3f(2.5, -5.0, 4.8);
	glVertex3f(0.0, -2.5, 6.4);
	glVertex3f(-2.5, -5.0, 4.8);

	glNormal3f(0.0, 0.5391, 0.8423);
	glVertex3f(2.5, 5.0, 4.8);
	glVertex3f(-2.5, 5.0, 4.8);
	glVertex3f(0.0, 2.5, 6.4);
	glEnd();
	glEndList();

	initialized = true;

	return true;
}


void Box::Draw(void)
{
	glPushMatrix();
	glCallList(display_list);
	glPopMatrix();
}