
class Employee
{
protected:
	int _type;

public:
	static const int ENGINEER = 0;
	static const int SALESMAN = 1;
	static const int MANAGER = 2;

	virtual int getType();
	static Employee* create(int type) {
		switch (type) {
		case ENGINEER:
			return new Engineer();
		case SALESMAN:
			return new SalesMan();
		case MANAGER:
			return new Manager();
		}
	}
	
private:
	Employee() = default;
	Employee(int type) : _type(type) {}
};

class Engineer : public Employee
{
public :
	Engineer() = default;
	int getType() {
		return Employee::ENGINEER;
	}
};

class SalesMan : public Employee
{
public:
	SalesMan() = default;
	int getType() {
		return Employee::SALESMAN;
	}
};

class Manager : public Employee
{
public:
	Manager() = default;
	int getType() {
		return Employee::MANAGER;
	}
};