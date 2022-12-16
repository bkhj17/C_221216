#include "Framework.h"
#include <fstream>

DataManager* DataManager::instance = nullptr;

DataManager::DataManager()
{
}

DataManager::~DataManager()
{
}

void DataManager::LoadItemData()
{
	ifstream ifs("ItemTable.csv", ios::in);

	ItemData data;

	bool isFirstLine = true;
	while (!ifs.eof()) {
		string tmp;
		ifs >> tmp;

		ItemData data;
		size_t at = tmp.find_first_of(',');
		string key = tmp.substr(0, at);
		data.key = stoi(key);

		tmp = tmp.substr(at + 1);
		at = tmp.find_first_of(',');
		data.name = tmp.substr(0, at);

		tmp = tmp.substr(at + 1);
		data.price = std::stoi(tmp);

		itemList.PushBack(data);
	}

	ifs.close();
}
