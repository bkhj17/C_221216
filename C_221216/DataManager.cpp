#include "Framework.h"
#include <fstream>

DataManager* DataManager::instance = nullptr;

DataManager::DataManager()
{
	LoadItemData();
}

DataManager::~DataManager()
{
}

ItemData DataManager::GetItemData(int key)
{
	return itemDatas[key];
}

void DataManager::LoadItemData()
{
	ifstream ifs;
	ifs.open("ItemTable.csv", ios::in);

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

		//itemDatas.insert(pair<int, ItemData>(data.key, data));
		//itemDatas.insert(make_pair(data.key, data));
		//itemDatas.insert({data.key, data});
		itemDatas[data.key] = data;
	}

	ifs.close();
}
