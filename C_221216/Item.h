#pragma once
struct ItemData
{
	ItemData();
	~ItemData();

	int key = -1;
	int price = 0;
	string name = "";
};

class Item {
public:
	Item(ItemData data);
	~Item();

	void ShowInfo();

	inline bool operator>=(const Item& other) {
		return price >= other.price;
	}
	inline bool operator<(const Item& other) {
		return price < other.price;
	}
private:
	int price;
	string name;
};