#include <iostream>
#include <string>
#include <vector>

class Test 
{
private:
	std::string _name;
	std::vector<double> elements;

	void printBanner() const {
		std::cout << "***********************" << std::endl;
		std::cout << "**** Customer Owes ****" << std::endl;
		std::cout << "***********************" << std::endl;
	}
	void printDetails(double outstanding) const {
		std::cout << "name: " << _name << std::endl;
		std::cout << "amount: " << std::to_string(outstanding) << std::endl;
	}
	const double getOutstanding(double initialValue = 0) const {
		double result = initialValue;
		for (auto arg : elements) {
			result += arg;
		}
		return result;
	}

public:
	void printOwing() const {
		printBanner();
		printDetails(getOutstanding());
	}

};

