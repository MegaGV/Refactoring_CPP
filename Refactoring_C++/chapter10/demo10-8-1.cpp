

class Price
{
private:
	int _quantity;
	int _itemPrice;

	double discountedPrice(int basePrice, int discountLevel) {
		if (discountLevel == 2)
			return basePrice * 0.1;
		else
			return basePrice * 0.05;
	}
public:
	double getPrice() {
		int basePrice = _quantity * _itemPrice;
		int discountLevel;
		if (_quantity > 100)
			discountLevel = 2;
		else
			discountLevel = 1;
		double finalPrice = discountedPrice(basePrice, discountLevel);
		return finalPrice;
	}

};