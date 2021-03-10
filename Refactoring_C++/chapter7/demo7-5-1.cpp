#include <string>

class Person;

class Department
{
private:
	std::string _chargeCode;
	Person* _manager;

public:
	Department(Person* manager) : _manager(manager) {}
	Person* getManager() {
		return _manager;
	}
};

class Person
{
private:
	Department _department;

public:
	Department& getDepartment() {
		return _department;
	}
	void setDepartment(Department arg) {
		_department = arg;
	}
};

