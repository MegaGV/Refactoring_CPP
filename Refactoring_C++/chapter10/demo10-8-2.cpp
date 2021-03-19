

class Price
{
private:
	int _quantity;
	int _itemPrice;

	double discountedPrice() {
		if (getDiscountLevel() == 2)
			return getBasePrice() * 0.1;
		else
			return getBasePrice() * 0.05;
	}
	int getDiscountLevel( ) {
		return _quantity > 100 ? 2 : 1;
	}
	int getBasePrice() {
		return _quantity * _itemPrice;
	}
public:
	double getPrice() {
		return discountedPrice();
	}

};