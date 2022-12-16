#include "Framework.h"
#include <fstream>
#include <sstream>
#include <vector>
#include "FileLoader.h"


stringstream FileLoader::LoadFile(string filename)
{
	stringstream ss;
	ifstream ifs(filename);
	
	string s;
	while (getline(ifs, s)) {
		ItemData data;
		size_t at = s.find_first_of('\t');
		string key = s.substr(0, at);
		s = s.substr(at + 1);
	}
	ifs.close();
	return ss;
}

void FileLoader::SaveFile(string filename, stringstream ss)
{
	ofstream ofs(filename, ios::out);

	string s;
	while (ss >> s) {
		ofs << s;
	}

	ofs.close();
}
