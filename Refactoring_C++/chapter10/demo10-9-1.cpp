#include <vector>

class Date
{
private:
	int year;
	int month;
	int day;

public:
	bool equals(Date date);
	bool after(Date date);
	bool before(Date date);
};

class Entry
{
private:
	Date _chargeDate;
	double _value;

public:
	Entry(double value, Date chargeDate) : _value(value), _chargeDate(chargeDate) {}
	Date getDate() {
		return _chargeDate;
	}
	double getValue() {
		return _value;
	}
};

class Account
{
private:
	std::vector<Entry> entrys;

public:
	double getFlowBetween(Date start, Date end) {
		double result = 0;
		for (auto e : entrys) {
			if (e.getDate().equals(start) || e.getDate().equals(end) ||
				(e.getDate().after(start) && e.getDate().before(end))) {
				result += e.getValue();
			}
		}
		return result;
	}
};