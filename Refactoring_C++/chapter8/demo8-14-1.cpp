
class Employee
{
private:
	int _type;

public:
	static const int ENGINEER = 0;
	static const int SALESMAN = 1;
	static const int MANAGER = 2;

	Employee(int type) : _type(type) {}
};

