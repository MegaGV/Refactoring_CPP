#include <string>

class Person
{
private:
	struct TelephoneNumber
	{
	private:
		std::string _officeAreaCode;
		std::string _officeNumber;

	public:
		const std::string getTelephoneNumber() const {
			return "(" + _officeAreaCode + ")" + _officeNumber;
		}
		const std::string getOfficeAreaCode() const {
			return _officeAreaCode;
		}
		void setOfficeAreaCode(std::string arg) {
			_officeAreaCode = arg;
		}
		const std::string getOfficeNumber() const {
			return _officeNumber;
		}
		void setOfficeNumber(std::string arg) {
			_officeNumber = arg;
		}
	};

	std::string _name;
	TelephoneNumber _officeTelephone;

public:
	std::string getName() {
		return _name;
	}
	std::string getTelephoneNumber() {
		return _officeTelephone.getTelephoneNumber();
	}
	TelephoneNumber& getOfficeTelephone() {
		return _officeTelephone;
	}
};

