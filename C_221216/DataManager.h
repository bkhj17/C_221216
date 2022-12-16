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


	void LoadItemData();

private:
	static DataManager* instance;

	DoublyLinkedList<ItemData> itemList;
};

