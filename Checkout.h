#pragma once
#include <string>
#include <map>

class Checkout
{
public:
	Checkout();
	virtual ~Checkout();
	void addItemPrice(std::string item, int price);
	void addItem(std::string item);
	int calculateTotal();
	void addDiscount(std::string item, int numOfItems, int discountPrice);

protected:
	int total;

	struct Discount {
		int numOfItems;
		int discountPrice;
	};

	std::map<std::string, int>prices;
	std::map<std::string, Discount>discounts;
	std::map<std::string, int>items;

	void calculateItem(std::string item, int itemCount);
	void calculateDiscount(std::string item, int itemCount, Discount discount);


	

	
};

