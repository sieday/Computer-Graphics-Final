#include "Trees.h"
#include "libtarga.h"
#include <stdio.h>

#include <GL/glu.h>

Tree::~Tree(void)
{
	if (initialized)
	{
		glDeleteLists(road_list, 1);
		glDeleteTextures(1, &road_obj);
		for (int i = 0; i < 10; ++i)
		{
			glDeleteLists(display_list[i], 1);
		}
	}
}

void Tree::Draw(void)
{
	glPushMatrix();
	glCallList(road_list);
	for (int i = 0; i < 10; ++i) {
		glCallList(display_list[i]);
	}
	glPopMatrix();
}

bool Tree::Initialize(void)
{
	Draw_tree(10, 5, 2, .25, 35, -10, 0);
	Draw_tree(10, 5, 2, .25, 35, 10, 1);
	Draw_tree(8, 5, 2, .25, 40, -10, 2);
	Draw_tree(8, 5, 2, .25, 40, 10, 3);
	Draw_tree(8, 4, 2, .15, 45, -10, 4);
	Draw_tree(8, 4, 2, .15, 45, 10, 5);
	Draw_tree(10, 5, 2, .35, 30, -10, 6);
	Draw_tree(10, 5, 2, .35, 30, 10, 7);

	Draw_tree(20, 5, 4, .5, -30, -20, 8);
	Draw_tree(20, 5, 4, .5, -30, 20, 9);

	initialized = true;
	return true;
}

void Tree::Draw_tree(float tall_leaf, float tall_trunk, float wide_leaf, float radius_trunk, float relative_x, float relative_y, int draw_index)
{
	GLUquadricObj* qobj;
	qobj = gluNewQuadric();
	gluQuadricDrawStyle(qobj, GLU_FILL);
	gluQuadricNormals(qobj, GLU_SMOOTH);
	display_list[draw_index] = glGenLists(1);
	glNewList(display_list[draw_index], GL_COMPILE);
		glPushMatrix();
		glTranslatef(relative_x, relative_y, 0.0);
		glColor3f(0.5, .25, 0);
		gluCylinder(qobj, radius_trunk, radius_trunk, tall_trunk, 15, 5);
		glTranslatef(0.0, 0.0, tall_trunk);
		glRotatef(180.0, 0.0, 1.0, 0.0);
		gluDisk(qobj, 0.0, wide_leaf, 15, 5);
		glRotatef(180, 0, 1, 0);
		glColor3f(0, .5, .25);
		gluCylinder(qobj, wide_leaf, 0, tall_leaf, 15, 5);
		glPopMatrix();
	glEndList();
	return;
}


