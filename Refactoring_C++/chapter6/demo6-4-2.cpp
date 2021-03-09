#include <iostream>

class Test
{
private:
	int _quantity;
	int _itemPrice;

	const int basePrice() const {
		return _quantity * _itemPrice;
	}
	const double discountFactor() const {
		return basePrice() > 1000 ? 0.95 : 0.98;
	}

public:
	double getPrice() {
		return basePrice() * discountFactor();
	}
};