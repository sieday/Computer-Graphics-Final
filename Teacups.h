#ifndef _TEACUPS_H_
#define _TEACUPS_H_

#include <Fl/gl.h>
#include <GL/glu.h> //EEPER

class Teacups {
private:
	GLubyte track_list;
	GLubyte train_list;
	GLubyte carriage_list;
	GLubyte wheel_list;
	GLubyte frame;
	bool initialized;
	float angle_on_wheel;
	float speed;

public:
	Teacups(void) { initialized = false; angle_on_wheel = 0.0f; speed = 0.0f; };
	~Teacups(void);
	bool    Initialize(void);
	void    Update(float);
	void    Draw(void);
	//MODIFICATION 11/7/22 - EEPER
};

#endif