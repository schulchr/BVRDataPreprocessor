#include "Gridpoints.h"

void setupTextureGrid(DataInfo info)
{
	int gridNum = 0;

	//these variables represent the amount of actual textures (opposed to grid points)
	int texWidth  = info.factor.widthFactor;
	int texHeight = info.factor.heightFactor;
	int texDepth  = info.factor.depthFactor;

	int width, height, depth;

	width  = texWidth  + 1;
	height = texHeight + 1;
	depth  = texDepth  + 1;


	ofstream myfile;

	string fileName = info.fileName;
	fileName.append(".grid");
	myfile.open(fileName);

	myfile << "GridWidth "  << width  << "\n";
	myfile << "GridHeight " << height << "\n";
	myfile << "GridDepth "  << depth  << "\n";

	//Going to have to do some fancy stuff with this later to be more adaptable to various sizes.
	myfile << "TexWidth " << info.width / info.factor.widthFactor << "\n";
	myfile << "TexHeight " << info.height / info.factor.heightFactor << "\n";
	myfile << "TexDepth " << info.depth / info.factor.depthFactor << "\n";

	for (int z = 0; z < depth; z++)
	{
		for (int y = 0; y < height; y++)
		{
			for (int x = 0; x < width; x++)
			{
				TextureGridPoint temp;
				//CORNERS
				//(-1,-1, -1) corner

				if (gridNum == 17)
				{
					int wat = 0;
				}

				if (x == 0 && y == 0 && z == 0)
				{
					temp.tex[BLL_TEX] = 0;
					temp.tex[BLR_TEX] = 1;
					temp.tex[TLL_TEX] = temp.tex[BLL_TEX] + texWidth;
					temp.tex[TLR_TEX] = temp.tex[BLL_TEX] + width;

					temp.tex[BUL_TEX] = temp.tex[BLL_TEX] + texWidth * texHeight;
					temp.tex[BUR_TEX] = temp.tex[BLR_TEX] + texWidth * texHeight;
					temp.tex[TUL_TEX] = temp.tex[TLL_TEX] + texWidth * texHeight;
					temp.tex[TUR_TEX] = temp.tex[TLR_TEX] + texWidth * texHeight;

					temp.type = gridPointTypes::BLL_CORNER;
				}
				else
					//(1, -1, -1) corner
				if (x == width - 1 && y == 0 && z == 0)
				{
					temp.tex[BLL_TEX] = texWidth - 2;
					temp.tex[BLR_TEX] = temp.tex[BLL_TEX] + 1;
					temp.tex[TLL_TEX] = temp.tex[BLL_TEX] + texWidth;
					temp.tex[TLR_TEX] = temp.tex[BLL_TEX] + texWidth + 1;

					temp.tex[BUL_TEX] = temp.tex[BLL_TEX] + texWidth * texHeight;
					temp.tex[BUR_TEX] = temp.tex[BLR_TEX] + texWidth * texHeight;
					temp.tex[TUL_TEX] = temp.tex[TLL_TEX] + texWidth * texHeight;
					temp.tex[TUR_TEX] = temp.tex[TLR_TEX] + texWidth * texHeight;
					temp.type = gridPointTypes::BLR_CORNER;
				}
				else
					//(-1, 1, -1) corner
				if (x == 0 && y == height - 1 && z == 0)
				{
					temp.tex[BLL_TEX] = texWidth * (height - 3);
					temp.tex[BLR_TEX] = temp.tex[BLL_TEX] + 1;
					temp.tex[TLL_TEX] = temp.tex[BLL_TEX] + texWidth;
					temp.tex[TLR_TEX] = temp.tex[BLL_TEX] + texWidth + 1;

					temp.tex[BUL_TEX] = temp.tex[BLL_TEX] + texWidth * texHeight;
					temp.tex[BUR_TEX] = temp.tex[BLR_TEX] + texWidth * texHeight;
					temp.tex[TUL_TEX] = temp.tex[TLL_TEX] + texWidth * texHeight;
					temp.tex[TUR_TEX] = temp.tex[TLR_TEX] + texWidth * texHeight;
					temp.type = gridPointTypes::TLL_CORNER;
				}
				else
					//(1, 1, -1) corner
				if (x == width - 1 && y == height - 1 && z == 0)
				{
					temp.tex[TLR_TEX] = texWidth * texHeight - 1;
					temp.tex[BLL_TEX] = temp.tex[TLR_TEX] - (texWidth + 1);
					temp.tex[BLR_TEX] = temp.tex[BLL_TEX] + 1;
					temp.tex[TLL_TEX] = temp.tex[BLL_TEX] + texWidth;

					temp.tex[BUL_TEX] = temp.tex[BLL_TEX] + texWidth * texHeight;
					temp.tex[BUR_TEX] = temp.tex[BLR_TEX] + texWidth * texHeight;
					temp.tex[TUL_TEX] = temp.tex[TLL_TEX] + texWidth * texHeight;
					temp.tex[TUR_TEX] = temp.tex[TLR_TEX] + texWidth * texHeight;

					temp.type = gridPointTypes::TLR_CORNER;
				}
				else
					//(-1,-1, 1) corner
				if (x == 0 && y == 0 && z == depth - 1)
				{
					temp.tex[BLL_TEX] = (texDepth - 2) * texWidth * texHeight;
					temp.tex[BLR_TEX] = temp.tex[BLL_TEX] + 1;
					temp.tex[TLL_TEX] = temp.tex[BLL_TEX] + texWidth;
					temp.tex[TLR_TEX] = temp.tex[BLL_TEX] + texWidth + 1;

					temp.tex[BUL_TEX] = temp.tex[BLL_TEX] + texWidth * texHeight;
					temp.tex[BUR_TEX] = temp.tex[BLR_TEX] + texWidth * texHeight;
					temp.tex[TUL_TEX] = temp.tex[TLL_TEX] + texWidth * texHeight;
					temp.tex[TUR_TEX] = temp.tex[TLR_TEX] + texWidth * texHeight;

					temp.type = gridPointTypes::BUL_CORNER;
				}
				else
					//(1,-1, 1) corner
				if (x == width - 1 && y == 0 && z == depth - 1)
				{
					temp.tex[BLL_TEX] = (texDepth - 2) * texWidth * texHeight + texWidth - 2;
					temp.tex[BLR_TEX] = temp.tex[BLL_TEX] + 1;
					temp.tex[TLL_TEX] = temp.tex[BLL_TEX] + texWidth;
					temp.tex[TLR_TEX] = temp.tex[BLL_TEX] + texWidth + 1;

					temp.tex[BUL_TEX] = temp.tex[BLL_TEX] + texWidth * texHeight;
					temp.tex[BUR_TEX] = temp.tex[BLR_TEX] + texWidth * texHeight;
					temp.tex[TUL_TEX] = temp.tex[TLL_TEX] + texWidth * texHeight;
					temp.tex[TUR_TEX] = temp.tex[TLR_TEX] + texWidth * texHeight;
					temp.type = gridPointTypes::BUR_CORNER;
				}
				else
					//(-1, 1, 1) corner
				if (x == 0 && y == height - 1 && z == depth - 1)
				{
					temp.tex[BLL_TEX] = (texDepth - 2) * texWidth * texHeight + texWidth * (texHeight - 2);
					temp.tex[BLR_TEX] = temp.tex[BLL_TEX] + 1;
					temp.tex[TLL_TEX] = temp.tex[BLL_TEX] + texWidth;
					temp.tex[TLR_TEX] = temp.tex[BLL_TEX] + texWidth + 1;

					temp.tex[BUL_TEX] = temp.tex[BLL_TEX] + texWidth * texHeight;
					temp.tex[BUR_TEX] = temp.tex[BLR_TEX] + texWidth * texHeight;
					temp.tex[TUL_TEX] = temp.tex[TLL_TEX] + texWidth * texHeight;
					temp.tex[TUR_TEX] = temp.tex[TLR_TEX] + texWidth * texHeight;
					temp.type = gridPointTypes::TUL_CORNER;
				}
				else
					//(1, 1, 1) corner
				if (x == width - 1 && y == height - 1 && z == depth - 1)
				{
					temp.tex[BLL_TEX] = (texDepth - 2) * texWidth * texHeight + texWidth * (texHeight - 2) + (texWidth - 2);
					temp.tex[BLR_TEX] = temp.tex[BLL_TEX] + 1;
					temp.tex[TLL_TEX] = temp.tex[BLL_TEX] + texWidth;
					temp.tex[TLR_TEX] = temp.tex[BLL_TEX] + texWidth + 1;

					temp.tex[BUL_TEX] = temp.tex[BLL_TEX] + texWidth * texHeight;
					temp.tex[BUR_TEX] = temp.tex[BLR_TEX] + texWidth * texHeight;
					temp.tex[TUL_TEX] = temp.tex[TLL_TEX] + texWidth * texHeight;
					temp.tex[TUR_TEX] = temp.tex[TLR_TEX] + texWidth * texHeight;
					temp.type = gridPointTypes::TUR_CORNER;
				}
				else
					//BOTTOM EDGES
					//bottom edge where z = 1, y = -1
				if (y == 0 && z == 0)
				{
					temp.tex[BLL_TEX] = x - 1;
					temp.tex[BLR_TEX] = temp.tex[BLL_TEX] + 1;
					temp.tex[TLL_TEX] = temp.tex[BLL_TEX] + texWidth;
					temp.tex[TLR_TEX] = temp.tex[BLL_TEX] + texWidth + 1;

					temp.tex[BUL_TEX] = temp.tex[BLL_TEX] + texWidth * texHeight;
					temp.tex[BUR_TEX] = temp.tex[BLR_TEX] + texWidth * texHeight;
					temp.tex[TUL_TEX] = temp.tex[TLL_TEX] + texWidth * texHeight;
					temp.tex[TUR_TEX] = temp.tex[TLR_TEX] + texWidth * texHeight;
				}
				else
					//bottom edge where x = -1 and y = -1
				if (x == 0 && y == 0)
				{
					temp.tex[BLL_TEX] = (z - 1) * texWidth * texHeight;
					temp.tex[BLR_TEX] = temp.tex[BLL_TEX] + 1;
					temp.tex[TLL_TEX] = temp.tex[BLL_TEX] + texWidth;
					temp.tex[TLR_TEX] = temp.tex[BLL_TEX] + texWidth + 1;

					temp.tex[BUL_TEX] = temp.tex[BLL_TEX] + texWidth * texHeight;
					temp.tex[BUR_TEX] = temp.tex[BLR_TEX] + texWidth * texHeight;
					temp.tex[TUL_TEX] = temp.tex[TLL_TEX] + texWidth * texHeight;
					temp.tex[TUR_TEX] = temp.tex[TLR_TEX] + texWidth * texHeight;
				}
				else
					//bottom edge where y = -1 and z = 1
				if (y == 0 && z == depth - 1)
				{
					temp.tex[BLL_TEX] = ((z - 2) * (texWidth * texHeight)) + (x - 1);
					temp.tex[BLR_TEX] = temp.tex[BLL_TEX] + 1;
					temp.tex[TLL_TEX] = temp.tex[BLL_TEX] + texWidth;
					temp.tex[TLR_TEX] = temp.tex[BLL_TEX] + texWidth + 1;

					temp.tex[BUL_TEX] = temp.tex[BLL_TEX] + texWidth * texHeight;
					temp.tex[BUR_TEX] = temp.tex[BLR_TEX] + texWidth * texHeight;
					temp.tex[TUL_TEX] = temp.tex[TLL_TEX] + texWidth * texHeight;
					temp.tex[TUR_TEX] = temp.tex[TLR_TEX] + texWidth * texHeight;
				}
				else
					//bottom edge where x = 1 and y = -1
				if (x == width - 1 && y == 0)
				{
					temp.tex[BLL_TEX] = ((z - 1) * texWidth * texHeight) + (texWidth - 2);
					temp.tex[BLR_TEX] = temp.tex[BLL_TEX] + 1;
					temp.tex[TLL_TEX] = temp.tex[BLL_TEX] + texWidth;
					temp.tex[TLR_TEX] = temp.tex[BLL_TEX] + texWidth + 1;

					temp.tex[BUL_TEX] = temp.tex[BLL_TEX] + texWidth * texHeight;
					temp.tex[BUR_TEX] = temp.tex[BLR_TEX] + texWidth * texHeight;
					temp.tex[TUL_TEX] = temp.tex[TLL_TEX] + texWidth * texHeight;
					temp.tex[TUR_TEX] = temp.tex[TLR_TEX] + texWidth * texHeight;
				}
				else
					//TOP EDGES
					//top edge where y = 1, z = -1
				if (y == height - 1 && z == 0)
				{
					temp.tex[BLL_TEX] = ((y - 2) * (texWidth)) + (x - 1);
					temp.tex[BLR_TEX] = temp.tex[BLL_TEX] + 1;
					temp.tex[TLL_TEX] = temp.tex[BLL_TEX] + texWidth;
					temp.tex[TLR_TEX] = temp.tex[BLL_TEX] + texWidth + 1;

					temp.tex[BUL_TEX] = temp.tex[BLL_TEX] + texWidth * texHeight;
					temp.tex[BUR_TEX] = temp.tex[BLR_TEX] + texWidth * texHeight;
					temp.tex[TUL_TEX] = temp.tex[TLL_TEX] + texWidth * texHeight;
					temp.tex[TUR_TEX] = temp.tex[TLR_TEX] + texWidth * texHeight;
				}
				else
					//top edge where y = 1, z = 1
				if (y == height - 1 && z == depth - 1)
				{
					temp.tex[BLL_TEX] = ((z - 2) * (texWidth * texHeight)) + ((y - 2) * (texWidth)) + (x - 1);
					temp.tex[BLR_TEX] = temp.tex[BLL_TEX] + 1;
					temp.tex[TLL_TEX] = temp.tex[BLL_TEX] + texWidth;
					temp.tex[TLR_TEX] = temp.tex[BLL_TEX] + texWidth + 1;

					temp.tex[BUL_TEX] = temp.tex[BLL_TEX] + texWidth * texHeight;
					temp.tex[BUR_TEX] = temp.tex[BLR_TEX] + texWidth * texHeight;
					temp.tex[TUL_TEX] = temp.tex[TLL_TEX] + texWidth * texHeight;
					temp.tex[TUR_TEX] = temp.tex[TLR_TEX] + texWidth * texHeight;
				}
				else
					//top edge where x = -1, y = 1
				if (y == height - 1 && x == 0)
				{
					temp.tex[BLL_TEX] = ((z - 1) * (texWidth * texHeight)) + ((y - 2) * (texWidth));
					temp.tex[BLR_TEX] = temp.tex[BLL_TEX] + 1;
					temp.tex[TLL_TEX] = temp.tex[BLL_TEX] + texWidth;
					temp.tex[TLR_TEX] = temp.tex[BLL_TEX] + texWidth + 1;

					temp.tex[BUL_TEX] = temp.tex[BLL_TEX] + texWidth * texHeight;
					temp.tex[BUR_TEX] = temp.tex[BLR_TEX] + texWidth * texHeight;
					temp.tex[TUL_TEX] = temp.tex[TLL_TEX] + texWidth * texHeight;
					temp.tex[TUR_TEX] = temp.tex[TLR_TEX] + texWidth * texHeight;
				}
				else
					//top edge where x = 1, y = 1
				if (y == height - 1 && x == width - 1)
				{
					temp.tex[BLL_TEX] = ((z - 1) * (texWidth * texHeight)) + ((y - 2) * (texWidth)) + (texWidth - 2);
					temp.tex[BLR_TEX] = temp.tex[BLL_TEX] + 1;
					temp.tex[TLL_TEX] = temp.tex[BLL_TEX] + texWidth;
					temp.tex[TLR_TEX] = temp.tex[BLL_TEX] + texWidth + 1;

					temp.tex[BUL_TEX] = temp.tex[BLL_TEX] + texWidth * texHeight;
					temp.tex[BUR_TEX] = temp.tex[BLR_TEX] + texWidth * texHeight;
					temp.tex[TUL_TEX] = temp.tex[TLL_TEX] + texWidth * texHeight;
					temp.tex[TUR_TEX] = temp.tex[TLR_TEX] + texWidth * texHeight;
				}
				else
					//COLUMN EDGES
					//column edge where x = -1, z = -1
				if (x == 0 && z == 0)
				{
					temp.tex[BLL_TEX] = (y - 1) * texWidth;
					temp.tex[BLR_TEX] = temp.tex[BLL_TEX] + 1;
					temp.tex[TLL_TEX] = temp.tex[BLL_TEX] + texWidth;
					temp.tex[TLR_TEX] = temp.tex[BLL_TEX] + texWidth + 1;

					temp.tex[BUL_TEX] = temp.tex[BLL_TEX] + texWidth * texHeight;
					temp.tex[BUR_TEX] = temp.tex[BLR_TEX] + texWidth * texHeight;
					temp.tex[TUL_TEX] = temp.tex[TLL_TEX] + texWidth * texHeight;
					temp.tex[TUR_TEX] = temp.tex[TLR_TEX] + texWidth * texHeight;
				}
				else
					//column edge where x = 1, z = 1
				if (x == width - 1 && z == 0)
				{
					temp.tex[BLL_TEX] = ((y - 1) * texWidth) + (texWidth - 2);
					temp.tex[BLR_TEX] = temp.tex[BLL_TEX] + 1;
					temp.tex[TLL_TEX] = temp.tex[BLL_TEX] + texWidth;
					temp.tex[TLR_TEX] = temp.tex[BLL_TEX] + texWidth + 1;

					temp.tex[BUL_TEX] = temp.tex[BLL_TEX] + texWidth * texHeight;
					temp.tex[BUR_TEX] = temp.tex[BLR_TEX] + texWidth * texHeight;
					temp.tex[TUL_TEX] = temp.tex[TLL_TEX] + texWidth * texHeight;
					temp.tex[TUR_TEX] = temp.tex[TLR_TEX] + texWidth * texHeight;
				}
				else
					//column edge where x = -1, z = 1
				if (x == 0 && z == depth - 1)
				{
					temp.tex[BLL_TEX] = ((z - 2) * (texWidth * texHeight)) + ((y - 1) * texWidth);
					temp.tex[BLR_TEX] = temp.tex[BLL_TEX] + 1;
					temp.tex[TLL_TEX] = temp.tex[BLL_TEX] + texWidth;
					temp.tex[TLR_TEX] = temp.tex[BLL_TEX] + texWidth + 1;

					temp.tex[BUL_TEX] = temp.tex[BLL_TEX] + texWidth * texHeight;
					temp.tex[BUR_TEX] = temp.tex[BLR_TEX] + texWidth * texHeight;
					temp.tex[TUL_TEX] = temp.tex[TLL_TEX] + texWidth * texHeight;
					temp.tex[TUR_TEX] = temp.tex[TLR_TEX] + texWidth * texHeight;
				}
				else
					//column edge where x = 1, z = 1
				if (x == width - 1 && z == depth - 1)
				{
					temp.tex[BLL_TEX] = ((z - 2) * (texWidth * texHeight)) + ((y - 1) * texWidth) + (texWidth - 2);
					temp.tex[BLR_TEX] = temp.tex[BLL_TEX] + 1;
					temp.tex[TLL_TEX] = temp.tex[BLL_TEX] + texWidth;
					temp.tex[TLR_TEX] = temp.tex[BLL_TEX] + texWidth + 1;

					temp.tex[BUL_TEX] = temp.tex[BLL_TEX] + texWidth * texHeight;
					temp.tex[BUR_TEX] = temp.tex[BLR_TEX] + texWidth * texHeight;
					temp.tex[TUL_TEX] = temp.tex[TLL_TEX] + texWidth * texHeight;
					temp.tex[TUR_TEX] = temp.tex[TLR_TEX] + texWidth * texHeight;
				}
				//FACES
				else
					//face where z = -1
				if (z == 0)
				{
					temp.tex[BLL_TEX] = ((y - 1) * (texWidth)) + (x - 1);
					temp.tex[BLR_TEX] = temp.tex[BLL_TEX] + 1;
					temp.tex[TLL_TEX] = temp.tex[BLL_TEX] + texWidth;
					temp.tex[TLR_TEX] = temp.tex[BLL_TEX] + texWidth + 1;

					temp.tex[BUL_TEX] = temp.tex[BLL_TEX] + texWidth * texHeight;
					temp.tex[BUR_TEX] = temp.tex[BLR_TEX] + texWidth * texHeight;
					temp.tex[TUL_TEX] = temp.tex[TLL_TEX] + texWidth * texHeight;
					temp.tex[TUR_TEX] = temp.tex[TLR_TEX] + texWidth * texHeight;
				}
				else
					//face where z = 1
				if (z == depth - 1)
				{
					temp.tex[BLL_TEX] = ((z - 2) * (texWidth * texHeight)) + ((y - 1) * (texWidth)) + (x - 1);
					temp.tex[BLR_TEX] = temp.tex[BLL_TEX] + 1;
					temp.tex[TLL_TEX] = temp.tex[BLL_TEX] + texWidth;
					temp.tex[TLR_TEX] = temp.tex[BLL_TEX] + texWidth + 1;

					temp.tex[BUL_TEX] = temp.tex[BLL_TEX] + texWidth * texHeight;
					temp.tex[BUR_TEX] = temp.tex[BLR_TEX] + texWidth * texHeight;
					temp.tex[TUL_TEX] = temp.tex[TLL_TEX] + texWidth * texHeight;
					temp.tex[TUR_TEX] = temp.tex[TLR_TEX] + texWidth * texHeight;
				}
				else
					//face where x = -1
				if (x == 0)
				{
					temp.tex[BLL_TEX] = ((z - 1) * (texWidth * texHeight)) + ((y - 1) * (texWidth));
					temp.tex[BLR_TEX] = temp.tex[BLL_TEX] + 1;
					temp.tex[TLL_TEX] = temp.tex[BLL_TEX] + texWidth;
					temp.tex[TLR_TEX] = temp.tex[BLL_TEX] + texWidth + 1;

					temp.tex[BUL_TEX] = temp.tex[BLL_TEX] + texWidth * texHeight;
					temp.tex[BUR_TEX] = temp.tex[BLR_TEX] + texWidth * texHeight;
					temp.tex[TUL_TEX] = temp.tex[TLL_TEX] + texWidth * texHeight;
					temp.tex[TUR_TEX] = temp.tex[TLR_TEX] + texWidth * texHeight;
				}
				else
					//face where x = 1
				if (x == width - 1)
				{
					temp.tex[BLL_TEX] = ((z - 1) * (texWidth * texHeight)) + ((y - 1) * (texWidth)) + (texWidth - 2);
					temp.tex[BLR_TEX] = temp.tex[BLL_TEX] + 1;
					temp.tex[TLL_TEX] = temp.tex[BLL_TEX] + texWidth;
					temp.tex[TLR_TEX] = temp.tex[BLL_TEX] + texWidth + 1;

					temp.tex[BUL_TEX] = temp.tex[BLL_TEX] + texWidth * texHeight;
					temp.tex[BUR_TEX] = temp.tex[BLR_TEX] + texWidth * texHeight;
					temp.tex[TUL_TEX] = temp.tex[TLL_TEX] + texWidth * texHeight;
					temp.tex[TUR_TEX] = temp.tex[TLR_TEX] + texWidth * texHeight;
				}
				else
					//face where y = -1
				if (y == 0)
				{
					temp.tex[BLL_TEX] = ((z - 1) * (texWidth * texHeight)) + (x - 1);
					temp.tex[BLR_TEX] = temp.tex[BLL_TEX] + 1;
					temp.tex[TLL_TEX] = temp.tex[BLL_TEX] + texWidth;
					temp.tex[TLR_TEX] = temp.tex[BLL_TEX] + texWidth + 1;

					temp.tex[BUL_TEX] = temp.tex[BLL_TEX] + texWidth * texHeight;
					temp.tex[BUR_TEX] = temp.tex[BLR_TEX] + texWidth * texHeight;
					temp.tex[TUL_TEX] = temp.tex[TLL_TEX] + texWidth * texHeight;
					temp.tex[TUR_TEX] = temp.tex[TLR_TEX] + texWidth * texHeight;
				}
				else
					//face where y = 1
				if (y == height - 1)
				{
					temp.tex[BLL_TEX] = ((z - 1) * (texWidth * texHeight)) + ((y - 2) * (texWidth)) + (x - 1);
					temp.tex[BLR_TEX] = temp.tex[BLL_TEX] + 1;
					temp.tex[TLL_TEX] = temp.tex[BLL_TEX] + texWidth;
					temp.tex[TLR_TEX] = temp.tex[BLL_TEX] + texWidth + 1;

					temp.tex[BUL_TEX] = temp.tex[BLL_TEX] + texWidth * texHeight;
					temp.tex[BUR_TEX] = temp.tex[BLR_TEX] + texWidth * texHeight;
					temp.tex[TUL_TEX] = temp.tex[TLL_TEX] + texWidth * texHeight;
					temp.tex[TUR_TEX] = temp.tex[TLR_TEX] + texWidth * texHeight;
				}
				else
				{
					temp.tex[BLL_TEX] = ((z - 1) * (texWidth * texHeight)) + ((y - 1) * (texWidth)) + (x - 1);
					temp.tex[BLR_TEX] = temp.tex[BLL_TEX] + 1;
					temp.tex[TLL_TEX] = temp.tex[BLL_TEX] + texWidth;
					temp.tex[TLR_TEX] = temp.tex[BLL_TEX] + texWidth + 1;

					temp.tex[BUL_TEX] = temp.tex[BLL_TEX] + texWidth * texHeight;
					temp.tex[BUR_TEX] = temp.tex[BLR_TEX] + texWidth * texHeight;
					temp.tex[TUL_TEX] = temp.tex[TLL_TEX] + texWidth * texHeight;
					temp.tex[TUR_TEX] = temp.tex[TLR_TEX] + texWidth * texHeight;
				}

				temp.point.x = -1.0f + x * (2.0f / (float)(width - 1));
				temp.point.y = -1.0f + y * (2.0f / (float)(height - 1));
				temp.point.z = -1.0f + z * (2.0f / (float)(depth - 1));


				//put that temp gridpoint into a string to print
				string str = "";
				str.append(to_string(temp.point.x));				
				str.append(" ");
				str.append(to_string(temp.point.y));
				str.append(" ");
				str.append(to_string(temp.point.z));

				for (int i = 0; i < 8; ++i)
				{
					str.append(" ");
					str.append(to_string(temp.tex[i]));
				}

				gridNum++;
				myfile << str << "\n";
			}
		}
	}


	myfile.close();
}