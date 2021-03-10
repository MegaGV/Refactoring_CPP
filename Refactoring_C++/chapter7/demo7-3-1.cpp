#include <string>

class Person
{
private:
	std::string _name;
	std::string _officeAreaCode;
	std::string _officeNumber;

public:
	std::string getName() {
		return _name;
	}
	std::string getTelephoneNumber() {
		return "(" + _officeAreaCode + ")" + _officeNumber;
	}
	std::string getOfficeAreaCode() {
		return _officeAreaCode;
	}
	void setOfficeAreaCode(std::string arg) {
		_officeAreaCode = arg;
	}
	std::string getOfficeNumber() {
		return _officeNumber;
	}
	void setOfficeNumber(std::string arg) {
		_officeNumber = arg;
	}
};