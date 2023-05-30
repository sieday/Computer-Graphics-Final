#ifndef _TREE_H_
#define _TREE_H_

#include <FL/gl.h>

class Tree 
{
	private:
		GLubyte display_list[10];
		GLubyte road_list;
		GLuint road_obj;
		bool initialized;
	public:
		Tree(void) {for (int i = 0; i < 10; ++i) display_list[i] = 0; road_list = 0; initialized = false;};
		~Tree(void);
		bool Initialize(void);
		void Draw_tree(float tall_leaf, float tall_trunk, float wide_leaf, float radius_trunk, float relative_x, float relative_y, int draw_index);
		void Draw();
};
#endif