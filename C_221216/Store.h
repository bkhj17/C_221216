#pragma once
class Store
{
public:
	Store();
	~Store();
	
	void ShowItems();

private:
	void CreateItems();
private:
	vector<Item*> items;
};

