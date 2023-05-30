#include "Teacups.h"
#include <stdio.h>
#include <FL/math.h> //EEPER
#include "libtarga.h"
#include <stdlib.h> 
#include <iostream>

Teacups::~Teacups(void)
{
	if (initialized)
	{
		glDeleteLists(track_list, 1);
		glDeleteLists(train_list, 1);
		glDeleteLists(carriage_list, 1);
		glDeleteLists(wheel_list, 1);
	}
}

bool Teacups::Initialize(void)
{
	GLUquadricObj* objhold;
	objhold = gluNewQuadric();
	gluQuadricDrawStyle(objhold, GLU_FILL);
	gluQuadricNormals(objhold, GLU_SMOOTH);

	glNewList(track_list, GL_COMPILE);
	glColor3f(.882, .756, .431);
	glBegin(GL_QUADS);
	glNormal3f(0.0, 0.0, -1.0);
	glVertex3f(-2.0, -2.0, 0.0);
	glVertex3f(-2.0, 2.0, 0.0);
	glVertex3f(2.0, 2.0, 0.0);
	glVertex3f(2.0, -2.0, 0.0);

	glNormal3f(0.0, 0.0, 1.0);
	glVertex3f(2.0, 12.0, 22.5);
	glVertex3f(2.0, 14.0, 22.5);
	glVertex3f(-2.0, 14.0, 22.5);
	glVertex3f(-2.0, 12.0, 22.5);

	glNormal3f(0.0, -0.8491, 0.5283);
	glVertex3f(2.0, -2.0, 0.0);
	glVertex3f(2.0, 12.0, 22.5);
	glVertex3f(-2.0, 12.0, 22.5);
	glVertex3f(-2.0, -2.0, 0.0);

	glNormal3f(1.0, 0.0, 0.0);
	glVertex3f(2.0, -2.0, 0.0);
	glVertex3f(2.0, 2.0, 0.0);
	glVertex3f(2.0, 14.0, 22.5);
	glVertex3f(2.0, 12.0, 22.5);

	glNormal3f(0.0, 0.8824, -0.4706);
	glVertex3f(2.0, 2.0, 0.0);
	glVertex3f(-2.0, 2.0, 0.0);
	glVertex3f(-2.0, 14.0, 22.5);
	glVertex3f(2.0, 14.0, 22.5);

	glNormal3f(-1.0, 0.0, 0.0);
	glVertex3f(-2.0, -2.0, 0.0);
	glVertex3f(-2.0, 12.0, 22.5);
	glVertex3f(-2.0, 14.0, 22.5);
	glVertex3f(-2.0, 2.0, 0.0);
	glEnd();
	glEndList();

	frame = glGenLists(1);
	glNewList(frame, GL_COMPILE);
	glPushMatrix();
	glTranslatef(6.5, -13.0, 0.0);		glCallList(track_list);
	glTranslatef(-13.0, 0.0, 0.0);		glCallList(track_list);
	glRotatef(180.0, 0.0, 0.0, 1.0);
	glTranslatef(0.0, -26.0, 0.0);		glCallList(track_list);
	glTranslatef(-13.0, 0.0, 0.0);		glCallList(track_list);
	glPopMatrix();

	glTranslatef(0.0, 0.0, 21.5);
	glPushMatrix();
	glColor3f(.882, .756, .431);
	glRotatef(90.0, 0.0, 1.0, 0.0);
	glTranslatef(0.0, 0.0, -4.5);
	gluCylinder(objhold, 1.0, 1.0, 9.0, 10, 5);
	glPopMatrix();
	glEndList();

	carriage_list = glGenLists(1);
	glNewList(carriage_list, GL_COMPILE);
	glTranslatef(0.0, 0.0, 4.33);		
	gluCylinder(objhold, 2.0, 1.0, 12.67, 15, 5);
	glTranslatef(0.0, 0.0, 12.67);		
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glTranslatef(0.0, 0.0, -2.0);		
	gluCylinder(objhold, 2, 2, 4.0, 6, 2);
	glTranslatef(0.0, 0.0, 4.0);		
	gluDisk(objhold, 0.0, 2.0, 6, 2);
	glTranslatef(0.0, 0.0, -4.0);		
	gluDisk(objhold, 0.0, 2.0, 6, 2);
	glTranslatef(2.0, 2.0, -2);		
	glRotatef(-45.0, 0.0, 1.0, 0.0);  
	gluDisk(objhold, 0.0, 1.0, 6, 2);

	glEndList();

	wheel_list = glGenLists(1);
	glNewList(wheel_list, GL_COMPILE);
	glTranslatef(-1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glColor3f(.917, .866, .792);
	glNormal3f(0.0, 0.0, 1.0);
	glVertex3f(2.5, -2.5, 4.33);
	glVertex3f(2.5, 2.5, 4.33);
	glVertex3f(-2.5, 2.5, 4.33);
	glVertex3f(-2.5, -2.5, 4.33);

	glColor3f(.882, .756, .431);
	glNormal3f(0.0, 0.866, 0.5);
	glVertex3f(2.5, 2.5, 4.33);
	glVertex3f(2.5, 5.0, 0.0);
	glVertex3f(-2.5, 5.0, 0.0);
	glVertex3f(-2.5, 2.5, 4.33);

	glColor3f(.803, .498, .196);
	glNormal3f(0.0, 0.866, -0.5);
	glVertex3f(2.5, 5.0, 0.0);
	glVertex3f(2.5, 2.5, -4.33);
	glVertex3f(-2.5, 2.5, -4.33);
	glVertex3f(-2.5, 5.0, 0.0);

	glColor3f(.647, .165, .165);
	glNormal3f(0.0, 0.0, -1.0);
	glVertex3f(2.5, -2.5, -4.33);
	glVertex3f(-2.5, -2.5, -4.33);
	glVertex3f(-2.5, 2.5, -4.33);
	glVertex3f(2.5, 2.5, -4.33);

	glColor3f(.854, .627, .427);
	glNormal3f(0.0, -0.866, -0.5);
	glVertex3f(2.5, -2.5, -4.33);
	glVertex3f(2.5, -5.0, 0.0);
	glVertex3f(-2.5, -5.0, 0.0);
	glVertex3f(-2.5, -2.5, -4.33);

	glColor3f(.501, 0, .125);
	glNormal3f(0.0, -0.866, 0.5);
	glVertex3f(2.5, -5.0, 0.0);
	glVertex3f(2.5, -2.5, 4.33);
	glVertex3f(-2.5, -2.5, 4.33);
	glVertex3f(-2.5, -5.0, 0.0);
	glEnd();

	glPushMatrix();

	glColor3f(.917, .866, .792);
	glCallList(carriage_list);
	glPopMatrix();

	glPushMatrix();
	glRotatef(-60.0, 1.0, 0.0, 0.0);
	glColor3f(.882, .756, .431);
	glCallList(carriage_list);
	glPopMatrix();

	glPushMatrix();
	glRotatef(-120.0, 1.0, 0.0, 0.0);
	glColor3f(.803, .498, .196);
	glCallList(carriage_list);
	glPopMatrix();

	glPushMatrix();
	glRotatef(-180.0, 1.0, 0.0, 0.0);
	glColor3f(.647, .165, .165);
	glCallList(carriage_list);
	glPopMatrix();

	glPushMatrix();
	glRotatef(-240.0, 1.0, 0.0, 0.0);
	glColor3f(.854, .627, .427);
	glCallList(carriage_list);
	glPopMatrix();

	glPushMatrix();
	glRotatef(-300.0, 1.0, 0.0, 0.0);
	glColor3f(.501, 0, .125);
	glCallList(carriage_list);
	glPopMatrix();
	glEndList();

	initialized = true;

	return true;
}

void Teacups::Draw(void)
{
	glPushMatrix();
	glTranslatef(-35.0, 0.0, 0.0);
	glCallList(frame);
	glRotatef(angle_on_wheel , 1.0, 0.0, 0.0);
	glCallList(wheel_list);
	glPopMatrix();
}

void Teacups::Update(float dt)
{
	angle_on_wheel += 6.0 * dt;
	while (angle_on_wheel >= 360.0)
		angle_on_wheel -= 360.0;
	while (angle_on_wheel < 0.0)
		angle_on_wheel += 360.0;
}

