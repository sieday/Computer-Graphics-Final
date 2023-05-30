#pragma once
#ifndef _BOX_H_
#define _BOX_H_

#include <Fl/gl.h>

class Box {
private:
	GLubyte display_list;
	GLuint  front_texture_obj;
	GLuint  back_texture_obj;
	GLuint  side_texture_obj;
	GLuint	roof_texture_obj;
	bool    initialized;
public:
	Box(void) {
		display_list = 0;
		initialized = false;
	};
	~Box(void);
	bool    Initialize(void);
	void    Draw(void);
};


#endif
