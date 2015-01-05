#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <Windows.h>
using namespace std;


enum DataTypes{
	IMAGES,
	BINARY
};

enum StrideTypes{
	BYT,
	SHOR
};
//This is used for the reading in the .size file to gather a description of the data to be read in. 
struct DataInfo{
	string sizeFile;
	string dataPath;
	string fileName;
	/*
	in the case of images:
	width x height - image resolution
	depth - how many images there are. 

	example: 50 1080x1080 images
	width = 1080
	height = 1080
	depth = 50
	*/
	int width, height, depth;
	int stride;
	int dataType;

	unsigned char *data;
};

void processBinary(DataInfo info);
void downsampleByFour(unsigned char *data, int factor);

void splitData(DataInfo info, int factor);
void helperSplit(DataInfo info, int factor, int x_start, int x_end, int y_start, int y_end, int z_start, int z_end, int chunkWidth, int chunkHeight, int chunkDepth, int fileNum);