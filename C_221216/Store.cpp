#include "Framework.h"

Store::Store()
{
	CreateItems();
}

Store::~Store()
{
	for (auto item : items) {
		delete item;
	}
}

void Store::ShowItems()
{
	for (int i = 0; i < items.size(); i++) {
		cout << i+1 << " : ";
		items[i]->ShowInfo();
		cout << "\n";
	}
}

void Store::CreateItems()
{
	auto datas = DataManager::Get()->GetItemDatas();
	for (auto data : datas) {
		items.push_back(new Item(data.second));
	}

	sort(items.begin(), items.end(), Item::Compare);
}
