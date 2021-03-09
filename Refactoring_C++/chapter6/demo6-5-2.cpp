#include <algorithm>

class Test
{
private:
	int _quantity;
	double _itemPrice;

	const double basePrice() const {
		return _quantity * _itemPrice;
	}
	const double quantityDiscount() const {
		return std::max(0, _quantity - 500) * _itemPrice * 0.05;
	}
	const double shipping() const {
		return std::min(basePrice() * 0.1, 100.0);
	}
public:
	double price() {
		double basePrice = _quantity * _itemPrice;
		double quantityDiscount = std::max(0, _quantity - 500) * _itemPrice * 0.05;
		double shipping = std::min(basePrice * 0.1, 100.0);
		return basePrice - quantityDiscount + shipping;
	}

	double price2() {
		return basePrice() - quantityDiscount() + shipping();
	}
};