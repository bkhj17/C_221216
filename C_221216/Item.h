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

	inline bool operator<= (const Item & other) {
		return price <= other.price;
	}
	inline bool operator>(const Item& other) {
		return price > other.price;
	}

	//기본연산자 오버라이딩 해봐야 포인터에는 불가능하니 
	//포인터 비교할꺼면 전용함수를 직접 만들어줘야 한다
	static bool Compare(Item* l, Item* r) {
		return *l < *r;	//하지만 이렇게는 쓸 수 있지
	}
private:
	int price;
	string name;
};