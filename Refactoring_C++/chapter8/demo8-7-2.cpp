#include <set>

class Customer;

class Order
{
private:
	std::set<Customer*> _customers;

public:
	void addCustomer(Customer* arg);
	void addedCustomer(Customer* arg);
	void removeCustomer(Customer* arg);
	std::set<Customer*>& getCustomers(){
		return _customers;
	}
};
class Customer
{
private:
	std::set<Order*> _orders;

public:
	void addOrder(Order* arg) {
		_orders.emplace(arg);
		(*arg).addCustomer(this);
	}
	void addedOrder(Order* arg) {
		_orders.emplace(arg);
	}
	void removeOrder(Order& arg) {
		auto it = _orders.find(&arg);
		if (it != _orders.end()) {
			_orders.erase(it);
			arg.getCustomers().erase(arg.getCustomers().find(this));
		}
	}
	std::set<Order*>& getOrders() {
		return _orders;
	}
};

void Order::addCustomer(Customer* arg) {
	_customers.emplace(arg);
	(*arg).addedOrder(this);
}
void Order::addedCustomer(Customer* arg) {
	_customers.emplace(arg);
}
void Order::removeCustomer(Customer* arg) {
	auto it = _customers.find(arg);
	if (it != _customers.end()) {
		_customers.erase(it);
		(*arg).getOrders().erase((*arg).getOrders().find(this));
	}
}
