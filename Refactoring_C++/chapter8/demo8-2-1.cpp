#include <string>
#include <vector>

class Order
{
private:
	std::string _customer;

public:
	Order(std::string customer) : _customer(customer) {}
	const std::string getCustomer() const {
		return _customer;
	}
	void setCustomer(std::string arg) {
		_customer = arg;
	}

	int numberOfOrdersFor(std::vector<Order> orders, std::string customer) {
		int result = 0;
		for (auto it = orders.cbegin(); it != orders.cend(); it++) {
			if (!(*it).getCustomer().compare(customer))
				result++;
		}
		return result;
	}
};

