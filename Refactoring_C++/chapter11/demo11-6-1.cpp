
class Employee
{
private:
	int _rate;

public:
	Employee(int rate) : _rate(rate) {}
	int getRate() {
		return _rate;
	}
};

class JobItem
{
private:
	int _unitPrice;
	int _quantity;
	Employee _employee;
	bool _isLabor;

public:
	JobItem(int unitPrice, int quantity, Employee employee, bool isLabor) 
		: _unitPrice(unitPrice), _quantity(quantity), _employee(employee), _isLabor(isLabor) {}
	int getTotalPrice() {
		return getUnitPrice() * _quantity;
	}
	int getUnitPrice() {
		return _isLabor ? _employee.getRate() : _unitPrice;
	}
	int getQuantity() {
		return _quantity;
	}
	Employee getEmployee(){
		return _employee;
	}
};