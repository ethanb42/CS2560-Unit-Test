#include "pch.h"
#include <gtest/gtest.h>
#include "Checkout.h"

class CheckoutTests:public::testing::Test {
public:

protected:
	Checkout checkOut;

};

//Refactored out of code, I commented it out to show it
/*
//Make sure google test works
TEST(CheckoutTests, CanAssert) {
	ASSERT_TRUE(true);
}

//Can create instance of checkout
TEST(CheckoutTests, CanInstantiateCheckout) {
	Checkout co;
}
*/

/*
//Can add item price
TEST_F(CheckoutTests, CanAddItemPrice) {
	
	checkOut.addItemPrice("a", 1);
}

//Can add an item
TEST_F(CheckoutTests, CanAddItem) {
	
	checkOut.addItem("a");
}
*/


//Can calculate the current total
TEST_F(CheckoutTests, CanCalculateTotal) {
	//the two previous test cases are being tested here
	checkOut.addItemPrice("a", 1);
	checkOut.addItem("a");
	int total = checkOut.calculateTotal();
	ASSERT_EQ(1, total);
}

//Can add multiple items and get correct total
TEST_F(CheckoutTests, CanGetTotalForMultipleItems) {
	checkOut.addItemPrice("a", 1);
	checkOut.addItemPrice("b", 2);
	checkOut.addItem("a");
	checkOut.addItem("b");
	int total = checkOut.calculateTotal();
	ASSERT_EQ(3, total);
}

//can add discount rules
TEST_F(CheckoutTests, CanAddDiscount) {
	checkOut.addDiscount("a", 3, 2);
}

TEST_F(CheckoutTests, CanCalculateWithDiscount) {
	checkOut.addItemPrice("a", 1);
	checkOut.addDiscount("a", 3, 2);
	checkOut.addItem("a");
	checkOut.addItem("a");
	checkOut.addItem("a");
	int total = checkOut.calculateTotal();
	ASSERT_EQ(2, total);
}

TEST_F(CheckoutTests, ItemWithNoPriceThrowsException) {
	ASSERT_THROW(checkOut.addItem("a"), std::invalid_argument);
}