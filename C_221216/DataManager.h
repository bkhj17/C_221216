#pragma once
class DataManager
{
private:
	DataManager();
	~DataManager();
public:
	static DataManager* Get() { 
		if (instance == nullptr)
			instance = new DataManager;
		return instance; 
	}
	static void Delete() { if (instance) delete instance; }

	ItemData GetItemData(int key);
	map<int, ItemData>& GetItemDatas() { return itemDatas; }
private:
	void LoadItemData();
	static DataManager* instance;

	//DoublyLinkedList<ItemData> itemList;
	map<int, ItemData> itemDatas;	//Ű�� �ߺ��Ǽ� �ȵ�
};

