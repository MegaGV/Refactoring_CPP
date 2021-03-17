
class Employee
{
protected:
	int _type;

public:
	static const int ENGINEER = 0;
	static const int SALESMAN = 1;
	static const int MANAGER = 2;

	virtual int getType() = 0;
};

class Engineer : public Employee
{
public :
	int getType() {
		return Employee::ENGINEER;
	}
};

class SalesMan : public Employee
{
public:
	int getType() {
		return Employee::SALESMAN;
	}
};

class Manager : public Employee
{
public:
	int getType() {
		return Employee::MANAGER;
	}
};

Employee* create(int type) {
	switch (type) {
	case Employee::ENGINEER:
		return new Engineer();
	case Employee::SALESMAN:
		return new SalesMan();
	case Employee::MANAGER:
		return new Manager();
	default:
		return nullptr;
	}
}