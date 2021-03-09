#include <algorithm>

class Test
{
private:
	int _quantity;
	double _itemPrice;

public:
	double price() {
		// price is base price - quantity discount + shipping
		return _quantity * _itemPrice -
			std::max(0, _quantity - 500) * _itemPrice * 0.05 +
			std::min(_quantity * _itemPrice * 0.1, 100.0);
	}
};