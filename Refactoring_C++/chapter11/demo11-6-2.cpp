
class Employee
{
private:
	int _rate;

public:
	Employee(const int& rate) : _rate(rate) {}
	const int getRate() const {
		return _rate;
	}
};

class JobItem
{
private:
	int _quantity;

public:
	JobItem(const int& quantity) : _quantity(quantity) {}
	const int getQuantity() const { return _quantity; }
	virtual const int getUnitPrice() const = 0;
};

class PartsItem : public JobItem
{
private:
	int _unitPrice;

public:
	PartsItem(const int& unitPrice, const int& quantity) 
		: _unitPrice(unitPrice), JobItem::JobItem(quantity) {}
	const int getTotalPrice() const {
		return getUnitPrice() * JobItem::getQuantity();
	}
	const int getUnitPrice() const override {
		return _unitPrice;
	}
};

class LaborItem : public JobItem
{
private:
	Employee* _employee;

public:
	LaborItem(const int& quantity, Employee* const employee)
		: JobItem::JobItem(quantity), _employee(employee) {}
	 Employee* const getEmployee() const {
		return _employee;
	}
	const int getUnitPrice() const override {
		return _employee->getRate();
	}
};