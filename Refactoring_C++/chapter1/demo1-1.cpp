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

	std::string statement()
	{
		double totalAmount = 0;
		int frequentRenterPoints = 0;
		std::string result = "Rental Record for " + getName() + "\n";
		for (auto it = _rentals.cbegin(); it != _rentals.cend(); it++)
		{
			Rental each(*it);
			double thisAmount = 0;
			switch (each.getMovie().getPriceCode())
			{
			case Movie::REGULAR:
				thisAmount += 2;
				if (each.getDaysRented() > 2)
					thisAmount += (each.getDaysRented() - 2) * 1.5;
				break;
			case Movie::NEW_RELEASE:
				thisAmount += each.getDaysRented() * 3;
				break;
			case Movie::CHILDRENS:
				thisAmount += 1.5;
				if (each.getDaysRented() > 3)
					thisAmount += (each.getDaysRented() - 3) * 1.5;
				break;
			}

			// add frequent renter points
			frequentRenterPoints++;
			// add bonus for a two day new release rental
			if ((each.getMovie().getPriceCode() == Movie::NEW_RELEASE) && each.getDaysRented() > 1)
				frequentRenterPoints++;

			// show figures for this rental
			result += "\t" + each.getMovie().getTitle() + "\t" + std::to_string(thisAmount) + "\n";
			totalAmount += thisAmount;
		}
		// add footer lines
		result += "Amount owed is " + std::to_string(totalAmount) + "\n";
		result += "You earned " + std::to_string(frequentRenterPoints) + " frequent renter points";
		return result;
	}
};

