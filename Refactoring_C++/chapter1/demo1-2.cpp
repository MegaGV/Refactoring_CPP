#include <string>
#include <vector>

class Movie
{
public:
	const static int CHILDRENS = 2;
	const static int REGULAR = 0;
	const static int NEW_RELEASE = 1;

private:
	std::string _title;
	int _priceCode;

public:
	Movie(std::string title, int priceCode) : _title(title), _priceCode(priceCode) {}
	int getPriceCode() { return _priceCode; }
	void setPriceCode(int arg) { _priceCode = arg; }
	std::string getTitle() { return _title; }
};

class Rental
{
private:
	Movie _movie;
	int _daysRented;

public:
	Rental(Movie movie, int daysRented) : _movie(movie), _daysRented(daysRented) {}
	int getDaysRented() { return _daysRented; }
	Movie getMovie() { return _movie; }
	double getCharge(){
		double result = 0;
		switch (getMovie().getPriceCode())
		{
		case Movie::REGULAR:
			result += 2;
			if (getDaysRented() > 2)
				result += (getDaysRented() - 2) * 1.5;
			break;
		case Movie::NEW_RELEASE:
			result += getDaysRented() * 3;
			break;
		case Movie::CHILDRENS:
			result += 1.5;
			if (getDaysRented() > 3)
				result += (getDaysRented() - 3) * 1.5;
			break;
		}
		return result;
	}
	int getFrequentRenterPoints() {
		if ((getMovie().getPriceCode() == Movie::NEW_RELEASE) && getDaysRented() > 1)
			return 2;
		else
			return 1;
	}
};

class Customer
{
private:
	std::string _name;
	std::vector<Rental> _rentals{};

public:
	Customer(std::string name) : _name(name) {}
	void addRental(Rental arg) { _rentals.emplace_back(arg); }
	std::string getName() { return _name; }

	std::string statement(){
		std::string result = "Rental Record for " + getName() + "\n";
		for (auto it = _rentals.cbegin(); it != _rentals.cend(); it++)
		{
			Rental each(*it);

			// show figures for this rental
			result += "\t" + each.getMovie().getTitle() + "\t" + std::to_string(each.getCharge()) + "\n";
		}

		// add footer lines
		result += "Amount owed is " + std::to_string(getTotalCharge()) + "\n";
		result += "You earned " + std::to_string(getTotalFrequentRenterPoints()) + " frequent renter points";
		return result;
	}

private:
	double getTotalCharge() {
		double result = 0;
		for (auto it = _rentals.cbegin(); it != _rentals.cend(); it++)
		{
			Rental each(*it);
			result += each.getCharge();
		}
		return result;
	}
	int getTotalFrequentRenterPoints(){
		int result = 0;
		for (auto it = _rentals.cbegin(); it != _rentals.cend(); it++)
		{
			Rental each(*it);
			result += each.getFrequentRenterPoints();
		}
		return result;
	}
};

