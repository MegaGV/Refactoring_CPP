
class Employee
{
private:
	int _type;
	int _monthlySalary;
	int _commission;
	int _bouns;

public:
	static const int ENGINEER = 0;
	static const int SALESMAN = 1;
	static const int MANAGER = 2;

	Employee(int type) : _type(type) {}

	int payAmount() {
		switch (_type) {
		case ENGINEER:
			return _monthlySalary;
		case SALESMAN:
			return _monthlySalary + _commission;
		case MANAGER:
			return _monthlySalary + _bouns;
		}
	}
};

