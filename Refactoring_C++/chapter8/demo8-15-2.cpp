
class EmployeeType 
{
public:
	virtual int getTypeCode() const;
	static EmployeeType newType(int arg) {
		switch (arg) {
		case Employee::ENGINEER:
			return Engineer();
		case Employee::SALESMAN:
			return SalesMan();
		case Employee::MANAGER:
			return Manager();
		}
	}
};

class Engineer : public EmployeeType
{
	int getTypeCode() const override {
		return Employee::ENGINEER;
	}
};

class SalesMan : public EmployeeType
{
	int getTypeCode() const override {
		return Employee::SALESMAN;
	}
};

class Manager : public EmployeeType
{
	int getTypeCode() const override {
		return Employee::MANAGER;
	}
};

class Employee
{
private:
	EmployeeType _type;
	int _monthlySalary;
	int _commission;
	int _bouns;

public:
	static const int ENGINEER = 0;
	static const int SALESMAN = 1;
	static const int MANAGER = 2;

	Employee(int type) {
		setType(type);
	}

	const int payAmount() const {
		switch (getType()) {
		case ENGINEER:
			return _monthlySalary;
		case SALESMAN:
			return _monthlySalary + _commission;
		case MANAGER:
			return _monthlySalary + _bouns;
		}
	}

	const int getType() const {
		return _type.getTypeCode();
	}
	void setType(int arg) {
		_type = EmployeeType::newType(arg);
	}
};

