#include <string>
#include <vector>
#include <map>

class Customer
{
private:
	std::string _name;
	static std::map<std::string, std::shared_ptr<Customer>> _instances;

	static void loadCustomers() {
		store("Lemon Car Hire");
		store("Associated Coffee Machines");
		store("Bilston Gasworks");
	}
	static void store(std::string name) {
		_instances.emplace(name, std::make_shared<Customer>(name));
	}
public:
	Customer(std::string name) : _name(name) {}
	const std::string getName() const {
		return _name;
	}
	void setName(std::string arg) {
		_name = arg;
	}
	static Customer* create(std::string name) {
		auto result = _instances.find(name);
		if (result == _instances.end()) {
			store(name);
			return _instances.find(name)->second.get();
		}
		else
			return result->second.get();
	}
};

class Order
{
private:
	Customer* _customer = nullptr;
public:
	Order(std::string customerName) {
		_customer = Customer::create(customerName);
	}
	const std::string getCustomerName() const {
		return _customer->getName();
	}
	void setCustomer(std::string customerName) {
		_customer = Customer::create(customerName);
	}

	int numberOfOrdersFor(std::vector<Order> orders, std::string customerName) {
		int result = 0;
		for (auto it = orders.cbegin(); it != orders.cend(); it++) {
			if (!(*it).getCustomerName().compare(customerName))
				result++;
		}
		return result;
	}
};

