//EEPER
#ifndef _PATH_H_
#define _PATH_H_

#include <FL/gl.h>

class Path {
private:
	GLubyte display_list;
	GLuint texture_obj;
	bool initialized;
	float posn[3];
public:
	Path(void) { display_list = 0; initialized = false; };
	~Path(void);
	bool Initialize(void);
	void Draw(void);
};

/*#pragma once
#ifndef _WALKWAY_H_
#define _WALKWAY_H_

//#include <OpenGL/glu.h>
#include <GL/glu.h>
#include <GL/gl.h>

class Path {
private:
	GLubyte display_list;
	GLuint texture_obj;
	bool initialized;
	GLdouble width;
	GLdouble length;
	float posn[3];
public:
	Path(void);
	Path(GLdouble inputwidth, GLdouble inputlength, float x, float y, float z);
	~Path(void);
	bool initialize(void);
	void draw(void);
};
*/
#endif