#include <iostream>
#include <vector>
#include <string>
#include "main.h"

using namespace std;
//Bottom 4 textures
#define BLL_TEX 0
#define BLR_TEX 1
#define BUL_TEX 2
#define BUR_TEX 3
//Top 4 textures
#define TLL_TEX 4
#define TLR_TEX 5
#define TUL_TEX 6
#define TUR_TEX 7


enum gridPointTypes{
	//All the corners 
	BUL_CORNER,
	BUR_CORNER,
	BLL_CORNER,
	BLR_CORNER,
	TUL_CORNER,
	TUR_CORNER,
	TLL_CORNER,
	TLR_CORNER,

	//Edges that go up and down in the x and z positions (top face)
	TOP_POSZ_EDGE,
	TOP_POSX_EDGE,
	TOP_NEGZ_EDGE,
	TOP_NEGX_EDGE,

	//Edges that go up and down in the x and z positions (bottom face)
	BOT_POSZ_EDGE,
	BOT_POSX_EDGE,
	BOT_NEGZ_EDGE,
	BOT_NEGX_EDGE,

	//Edges that go up and down in the y direction
	SIDE_NN_EDGE,
	SIDE_NP_EDGE,
	SIDE_PP_EDGE,
	SIDE_PN_EDGE,

	//Points on a given plane
	POS_XY_PLANE,
	NEG_XY_PLANE,
	POS_YZ_PLANE,
	NEG_YZ_PLANE,
	POS_XZ_PLANE,
	NEG_XZ_PLANE,

	//Any interior point
	INTERIOR
};

struct Point{
	float x, y, z;
};

//A TextureGridPoint is a point in space 
struct TextureGridPoint{
	Point point; //grid point
	int type;
	int tex[8]; //corresponds to which textures to use from HDD
};

void setupTextureGrid(DataInfo info);