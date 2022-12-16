#include "Framework.h"

ItemData::ItemData()
{
}

ItemData::~ItemData()
{
}

Item::Item(ItemData data)
{
	name = data.name;
	price = data.price;
}

Item::~Item()
{
}

void Item::ShowInfo()
{
}
