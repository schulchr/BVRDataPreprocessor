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
					info.stride = StrideTypes::BYTE;
				if (stride == 16)
					info.stride = StrideTypes::SHORT;
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
		if (info.stride == StrideTypes::BYTE)
			cout << "8-bit (byte) \n";
		if (info.stride == StrideTypes::SHORT)
			cout << "16-bit (short) \n";
	}
	if (info.dataType == DataTypes::IMAGES)
		cout << "images \n";
	cout << "*****************\n";

	if (info.dataType == DataTypes::BINARY)
		processBinary(info);
	
}

/*
Right now, this function will only do a factor of 4 downsampling
example: 1024x1024x1024 -> 256x256x256
*/
void processBinary(DataInfo info)
{
	//Setup the file for the data
	string filename;
	filename.append(info.dataPath.c_str());
	filename.append(info.fileName.c_str());

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
	
	unsigned char *data = NULL;
	//Setup an array to hold the volume data
	if (info.stride == StrideTypes::BYTE)
		data = (unsigned char *)malloc(info.depth * info.height * info.width * sizeof(char));

	/*Read in all the data (might need to handle this differently...
	but since it's assumed this program will ran on a desktop, it should have enough memory)
	*/
	fread(data, sizeof(unsigned char), info.depth * info.width * info.height, file);
		
}

/*
	This will downsize the data by a give factor. 
*/
void downsizeData(DataInfo info, int factor)
{

}