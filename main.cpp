#include "main.h"

int main()
{
	DataInfo info;
	
	//ask user for name of the size file
	cout << "Name of the size file: ";
	getline(std::cin, info.sizeFile);

	info.sizeFile.append(".size");

	cout << "Opening " << info.sizeFile;

	ifstream infoFile;
	infoFile.open(info.sizeFile);


	if (infoFile.is_open())
	{
		string line;

		getline(infoFile, info.dataPath);
		getline(infoFile, line);

		if (line.compare("images") == 0)
			info.dataType = DataTypes::IMAGES;
		if (line.compare("binary") == 0)
			info.dataType = DataTypes::BINARY;

		getline(infoFile, line);
		info.fileName = line;

		while (getline(infoFile, line))
		{
			string token = line.substr(0, line.find(" "));
			string value = line.substr(line.find(" "), line.find(";"));
			if (token.compare("h") == 0)
				info.height = atoi(value.c_str());
			if (token.compare("w") == 0)
				info.width = atoi(value.c_str());
			if (token.compare("d") == 0)
				info.depth = atoi(value.c_str());
			if (token.compare("s") == 0)
			{
				int stride = atoi(value.c_str());
				if (stride == 8)
					info.stride = StrideTypes::BYT;
				if (stride == 16)
					info.stride = StrideTypes::SHOR;
			}
		}
		infoFile.close();
	}
	else
	{
		cout << "Cannot open file: " << info.sizeFile;
		return 1;
	}

	cout << "\n***Volume Info*** \n";
	cout << "Height: " << info.height << "\n";
	cout << "Width: " << info.width << "\n";
	cout << "Depth: " << info.depth << "\n";
	cout << "Data path: " << info.dataPath << "\n";
	cout << "Data type: ";
	if (info.dataType == DataTypes::BINARY)
	{
		cout << "binary \n";
		cout << "Stride: ";
		if (info.stride == StrideTypes::BYT)
			cout << "8-bit (byte) \n";
		if (info.stride == StrideTypes::SHOR)
			cout << "16-bit (short) \n";
	}
	if (info.dataType == DataTypes::IMAGES)
		cout << "images \n";
	cout << "*****************\n";

	if (info.dataType == DataTypes::BINARY)
		processBinary(info);
	
}

/*
Reads in, downsizes and splits up the data.
*/
void processBinary(DataInfo info)
{
	//Setup the file for the data
	string filename;
	filename.append(info.dataPath.c_str());
	filename.append(info.fileName.c_str());
	filename.append(".raw");

	FILE *file;
	errno_t res = fopen_s(&file, filename.c_str(), "rb");

	//Check if file was readable
	//res = 0, success
	//res != 0, error
	if (res != 0)
	{
		cout << "processBinary: Cannot read file \n";
		exit(1);
	}
	
	info.data = NULL;
	//Setup an array to hold the volume data
	if (info.stride == StrideTypes::BYT)
		info.data = (unsigned char *)malloc(info.depth * info.height * info.width * sizeof(unsigned char));

	/*Read in all the data (might need to handle this differently...
	but since it's assumed this program will ran on a desktop, it should have enough memory)
	*/
	fread(info.data, sizeof(unsigned char), info.depth * info.width * info.height, file);
	
	splitData(info, 2);

}

/*
	This will downsize the data by a give factor. 
*/
void downsizeData(DataInfo info, int factor)
{

}

/*
Split the data depending on the factor. 

This will not downsize the data, but rather split the data up into separate files given a certain factor. 

Example:

Given a 1024x1024x1024 data set, and a factor of 8, this function will split up the original data set and create multiple
128x128x128 chunks. (8^3 = 512 files)

The idea of this is to allow the file sizes to be small enough to load into a memory limited system. 
*/
void splitData(DataInfo info, int factor)
{
	int splitWidthX = info.width / factor;
	int splitWidthY = info.height / factor;
	int splitWidthZ = info.depth / factor;

	int fileCount = 0; //keeps track of the file name for the chunked up textures
	for (int z = 0; z < info.depth; z += splitWidthZ)
	{
		for (int y = 0; y < info.height; y += splitWidthY)
		{
			for (int x = 0; x < info.width; x += splitWidthX)
			{
				helperSplit(info, factor, x, x + splitWidthX, y, y + splitWidthY, z, z + splitWidthZ, splitWidthX, splitWidthY, splitWidthZ, fileCount++);
			}
		}
	}
}

/*
Helper function for writing data to the individual files
*/
void helperSplit(DataInfo info, int factor, int x_start, int x_end, int y_start, int y_end, int z_start, int z_end, int chunkWidth, int chunkHeight, int chunkDepth, int fileNum)
{
	cout << "starting to split at x: " << x_start << " y: " << y_start << " z: " << z_start << "\n";
	
	unsigned char *chunkData = NULL;
	//Setup an array to hold the chunk of volume data
	if (info.stride == StrideTypes::BYT)
		chunkData = (unsigned char *)malloc(chunkWidth * chunkHeight *  chunkDepth * sizeof(unsigned char));



	//Create the directory
	CreateDirectoryW(L".\\splitData", NULL);

	string chunkName;

	chunkName = ".\\splitData\\";
	chunkName.append(info.fileName);
	chunkName.append("_");
	chunkName.append(to_string(fileNum));
	chunkName.append(".raw");

	

	FILE *file;
	errno_t res = fopen_s(&file, chunkName.c_str(), "wb");
	
	int count = 0;

	for (int z = z_start; z < z_end; ++z)
	{
		for (int y = y_start; y < y_end; ++y)
		{
			for (int x = x_start; x < x_end; ++x)
			{
				chunkData[count++] = info.data[z * info.height * info.width + y * info.width + x];
			}
		}
	}


	
	fwrite(chunkData, sizeof(unsigned char), chunkWidth * chunkHeight * chunkDepth, file);

	fclose(file);

	free(chunkData);

}