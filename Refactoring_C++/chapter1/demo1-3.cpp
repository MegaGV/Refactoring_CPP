#include <string>
#include <vector>

enum class Movie_Type{ REGULAR , NEW_RELEASE, CHILDRENS };

struct Price
{
	virtual int getPriceCode();
	virtual double getCharge(int daysRented);
	int getFrequentRenterPoints(int daysRented) {
			return 1;
			
	}
};
struct ChildrensPrice : Price
{
	int getPriceCode() override { return static_cast<int>(Movie_Type::CHILDRENS); }
	double getCharge(int daysRented) override {
		double result = 0;
		result += 1.5;
		if (daysRented > 3)
			result += (daysRented - 3) * 1.5;
		return result;
	}
};
struct NewReleasePrice : Price
{
	int getPriceCode() override { return static_cast<int>(Movie_Type::NEW_RELEASE); }
	double getCharge(int daysRented) override {
		double result = 0;
		result += daysRented * 3;
		return result;
	}
	int getFrequentRenterPoints(int daysRented) {
		return (daysRented > 1) ? 2 : 1;
	}
};
struct RegularPrice : Price
{
	int getPriceCode() override { return static_cast<int>(Movie_Type::REGULAR); }
	double getCharge(int daysRented) override {
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
	Price _price;

public:
	Movie(std::string title, int priceCode) : _title(title) {
		setPriceCode(priceCode);
	}
	int getPriceCode() { return _price.getPriceCode(); }
	void setPriceCode(int arg) {
		switch (arg) {
		case static_cast<int>(Movie_Type::REGULAR):
			_price = RegularPrice();
			break;
		case static_cast<int>(Movie_Type::CHILDRENS) :
			_price = ChildrensPrice();
			break;
		case static_cast<int>(Movie_Type::NEW_RELEASE) :
			_price = NewReleasePrice();
			break;
		}
	}
	std::string getTitle() { return _title; }
	double getCharge(int daysRented) {
		return _price.getCharge(daysRented);
	}
	int getFrequentRenterPoints(int daysRented) {
		
	}
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
	double getCharge() {
		return _movie.getCharge(_daysRented);
	}
	int getFrequentRenterPoints() {
		return _movie.getFrequentRenterPoints(_daysRented);
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

	std::string statement() {
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
	int getTotalFrequentRenterPoints() {
		int result = 0;
		for (auto it = _rentals.cbegin(); it != _rentals.cend(); it++)
		{
			Rental each(*it);
			result += each.getFrequentRenterPoints();
		}
		return result;
	}
};

