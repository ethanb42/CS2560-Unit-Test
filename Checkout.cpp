#include "pch.h"
#include "Checkout.h"


Checkout::Checkout()
{
	total = 0;
}


Checkout::~Checkout()
{
}

void Checkout::addItemPrice(std::string item, int price)
{
	prices[item] = price;
}

void Checkout::addItem(std::string item)
{
	std::map<std::string, int> ::iterator priceIter = prices.find(item);
	if (priceIter == prices.end()) {
		//no price found
		throw std::invalid_argument("Invalid item. No Price!");
	}

	items[item]++;
}

int Checkout::calculateTotal()
{
	total = 0;
	for (std::map<std::string, int>::iterator itemIter = items.begin(); itemIter != items.end(); itemIter++) {
		std::string item = itemIter->first;
		int itemCount = itemIter->second;
		calculateItem(item, itemCount);

	}
	return total;
}

void Checkout::addDiscount(std::string item, int numOfItems, int discountPrice)
{
	Discount discount;
	discount.numOfItems = numOfItems;
	discount.discountPrice = discountPrice;
	discounts[item] = discount;
}

void Checkout::calculateItem(std::string item, int itemCount)
{
	std::map<std::string, Discount>::iterator discountIter;
	discountIter = discounts.find(item);
	if (discountIter != discounts.end()) {
		Discount discount = discountIter->second;
		calculateDiscount(item, itemCount, discount);
	}
	else {
		total += itemCount * prices[item];
	}

}

void Checkout::calculateDiscount(std::string item, int itemCount, Discount discount)
{
	if (itemCount >= discount.numOfItems) {
		//apply the discount
		int numberOfDiscounts = itemCount / discount.numOfItems;
		total += numberOfDiscounts * discount.discountPrice;
		int remainingItems = itemCount % discount.numOfItems;
		total += remainingItems * prices[item];
	}
	else {
		total += itemCount * prices[item];
	}

}
