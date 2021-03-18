
class EmployeeType 
{
public:
	static const int ENGINEER = 0;
	static const int SALESMAN = 1;
	static const int MANAGER = 2;

	virtual int getTypeCode() const = 0;
};

class Engineer : public EmployeeType
{
	int getTypeCode() const override {
		return ENGINEER;
	}
};

class SalesMan : public EmployeeType
{
	int getTypeCode() const override {
		return SALESMAN;
	}
};

class Manager : public EmployeeType
{
	int getTypeCode() const override {
		return MANAGER;
	}
};

EmployeeType* newType2(int arg) {
	switch (arg) {
	case EmployeeType::ENGINEER:
		return new Engineer();
	case EmployeeType::SALESMAN:
		return new SalesMan();
	case EmployeeType::MANAGER:
		return new Manager();
	default:
		return nullptr;
	}
}

class Employee
{
private:
	EmployeeType* _type;
	int _monthlySalary;
	int _commission;
	int _bouns;

public:
	Employee(int type) {
		setType(type);
	}

	const int payAmount() const {
		switch (getType()) {
		case EmployeeType::ENGINEER:
			return _monthlySalary;
		case EmployeeType::SALESMAN:
			return _monthlySalary + _commission;
		case EmployeeType::MANAGER:
			return _monthlySalary + _bouns;
		}
	}

	const int getType() const {
		return _type->getTypeCode();
	}
	void setType(int arg) {
		_type = newType2(arg);
	}
};

