#include <set>

class Customer;

class Order
{
private:
	Customer* _customer;

public:
	Customer* getCustomer() {
		return _customer;
	}
	void setCustomer(Customer& arg) {
		_customer = &arg;
	}
};

class Customer
{
private:
	std::set<Order*> _orders;

};
