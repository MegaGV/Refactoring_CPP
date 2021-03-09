#include <iostream>
#include <string>
#include <vector>

class Test 
{
private:
	std::string _name;
	std::vector<double> elements;
	
public:
	void printOwing() const {
		double outstanding = 0.0;

		// print banner
		std::cout << "***********************" << std::endl;
		std::cout << "**** Customer Owes ****" << std::endl;
		std::cout << "***********************" << std::endl;

		// calculate outstanding
		for (auto arg : elements) {
			outstanding += arg;
		}

		// print details
		std::cout << "name: " << _name << std::endl;
		std::cout << "amount: " << std::to_string(outstanding) << std::endl;
	}

};

