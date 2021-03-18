
class Employee;

class EmployeeType
{
public:
	static const int ENGINEER = 0;
	static const int SALESMAN = 1;
	static const int MANAGER = 2;

	virtual int getTypeCode() const = 0;

	virtual const int payAmount(const Employee* emp) const = 0;
};

class Engineer : public EmployeeType
{
public:
	int getTypeCode() const override {
		return ENGINEER;
	}
	const int payAmount(const Employee* emp) const override;
};

class SalesMan : public EmployeeType
{
public:
	int getTypeCode() const override {
		return SALESMAN;
	}
	const int payAmount(const Employee* emp) const override;
};

class Manager : public EmployeeType
{
public:
	int getTypeCode() const override {
		return MANAGER;
	}
	const int payAmount(const Employee* emp) const override;
};

EmployeeType* newType3(int arg) {
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

	const int getType() const {
		return _type->getTypeCode();
	}
	void setType(int arg) {
		_type = newType3(arg);
	}
	const int getMonthlySalary() const {
		return _monthlySalary;
	}
	const int getCommission() const {
		return _commission;
	}
	const int getBouns() const {
		return _bouns;
	}

	const int payMent() const {
		return _type->payAmount(this);
	}
};

const int Engineer::payAmount(const Employee* emp) const {
	return emp->getMonthlySalary();
}
const int SalesMan::payAmount(const Employee* emp) const {
	return emp->getMonthlySalary() + emp->getCommission();
}
const int Manager::payAmount(const Employee* emp) const {
	return emp->getMonthlySalary() + emp->getBouns();
}
