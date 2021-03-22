#include <string>
#include <vector>

enum class Movie_Type { REGULAR, NEW_RELEASE, CHILDRENS };

struct Price
{
	virtual const int getPriceCode() const = 0;
	virtual const double getCharge(int daysRented) const = 0;
	const int getFrequentRenterPoints(int daysRented) const {
		return 1;
	}
};
struct ChildrensPrice : Price
{
	const int getPriceCode() const override { 
		return static_cast<int>(Movie_Type::CHILDRENS); 
	}
	const double getCharge(int daysRented) const override {
		double result = 0;
		result += 1.5;
		if (daysRented > 3)
			result += (daysRented - 3) * 1.5;
		return result;
	}
};
struct NewReleasePrice : Price
{
	const int getPriceCode() const override { 
		return static_cast<int>(Movie_Type::NEW_RELEASE); 
	}
	const double getCharge(int daysRented) const override {
		double result = 0;
		result += daysRented * 3;
		return result;
	}
	const int getFrequentRenterPoints(int daysRented) const {
		return (daysRented > 1) ? 2 : 1;
	}
};
struct RegularPrice : Price
{
	const int getPriceCode() const override { 
		return static_cast<int>(Movie_Type::REGULAR); 
	}
	const double getCharge(int daysRented) const override {
		double result = 0;
		result += 2;
		if (daysRented > 2)
			result += (daysRented - 2) * 1.5;
		return result;
	}
};
class Movie
{
private:
	std::string _title;
	std::shared_ptr<Price> _price;

public:
	Movie(std::string title, Movie_Type type) : _title(title) {
		setPriceCode(type);
	}
	const int getPriceCode() const { 
		return (*_price).getPriceCode(); 
	}
	void setPriceCode(Movie_Type type) {
		switch (type) {
		case Movie_Type::REGULAR:
			_price = std::make_shared<RegularPrice>();
			break;
		case Movie_Type::CHILDRENS:
			_price = std::make_shared<ChildrensPrice>();
			break;
		case Movie_Type::NEW_RELEASE:
			_price = std::make_shared<NewReleasePrice>();
			break;
		}
	}
	const std::string getTitle() const {
		return _title;
	}
	const double getCharge(int daysRented) const {
		return (*_price).getCharge(daysRented);
	}
	const int getFrequentRenterPoints(int daysRented) const {
		return (*_price).getFrequentRenterPoints(daysRented);
	}
};

class Rental
{
private:
	Movie _movie;
	int _daysRented;

public:
	Rental(Movie movie, int daysRented) : _movie(movie), _daysRented(daysRented) {}
	const int getDaysRented() const { 
		return _daysRented; 
	}
	const std::string getTitle() const {
		return _movie.getTitle();
	}
	const double getCharge() const {
		return _movie.getCharge(_daysRented);
	}
	const int getFrequentRenterPoints() const {
		return _movie.getFrequentRenterPoints(_daysRented);
	}
};

class Customer
{
private:
	std::string _name;
	std::vector<Rental> _rentals;

public:
	Customer(std::string name) : _name(name) {}
	void addRental(Rental rental) { 
		_rentals.emplace_back(rental); 
	}
	void addRental(Movie movie, int daysRented) {
		_rentals.push_back({ movie, daysRented }); 
	}
	const std::string getName() const { 
		return _name; 
	}

	const std::string statement() const {
		std::string result = "Rental Record for " + getName() + "\n";
		for (auto it = _rentals.cbegin(); it != _rentals.cend(); it++) {
			// show figures for this rental
			result += "\t" + (*it).getTitle() + "\t" + std::to_string((*it).getCharge()) + "\n";
		}

		// add footer lines
		result += "Amount owed is " + std::to_string(getTotalCharge()) + "\n";
		result += "You earned " + std::to_string(getTotalFrequentRenterPoints()) + " frequent renter points";
		return result;
	}

	const std::string htmlStatement() const {
		std::string result = "<H1>Rental Record for <EM>" + getName() + "</EM></H1><P>\n";
		for (auto it = _rentals.cbegin(); it != _rentals.cend(); it++) {
			// show figures for this rental
			result += "\t" + (*it).getTitle() + "\t" + std::to_string((*it).getCharge()) + "<BR>\n";
		}
		
		// add footer lines
		result += "<P>Amount owed is <EM>" + std::to_string(getTotalCharge()) + "</EM><P>\n";
		result += "You earned <EM>" + std::to_string(getTotalFrequentRenterPoints()) + "</EM> frequent renter points<P>";
		return result;
	}

private:
	const double getTotalCharge() const {
		double result = 0;
		for (auto it = _rentals.cbegin(); it != _rentals.cend(); it++) {
			result += (*it).getCharge();
		}
		return result;
	}
	const int getTotalFrequentRenterPoints() const {
		int result = 0;
		for (auto it = _rentals.cbegin(); it != _rentals.cend(); it++) {
			result += (*it).getFrequentRenterPoints();
		}
		return result;
	}
};

