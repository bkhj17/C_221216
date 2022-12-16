#pragma once
 
class FileLoader
{
public:
	static stringstream LoadFile(string filename);
	static void SaveFile(string filename, stringstream ss);
};

