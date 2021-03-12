#include <string>
#include <vector>


class Order
{
private:
	class Customer
	{
	private:
		std::string _name;

	public:
		Customer(std::string name) : _name(name) {}
		const std::string getName() const {
			return _name;
		}
		void setName(std::string arg) {
			_name = arg;
		}
	};

	Customer _customer;
public:
	Order(std::string customerName) : _customer(customerName) {}
	const std::string getCustomerName() const {
		return _customer.getName();
	}
	void setCustomer(std::string customerName) {
		_customer = Customer(customerName);
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


