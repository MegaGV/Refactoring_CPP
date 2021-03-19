#include <vector>

class Date
{
private:
	int year;
	int month;
	int day;

public:
	const bool equals(const Date& date) const;
	const bool after(const Date& date) const;
	const bool before(const Date& date) const;
};

class Entry
{
private:
	Date _chargeDate;
	double _value;

public:
	Entry(const double& value, const Date& chargeDate) : _value(value), _chargeDate(chargeDate) {}
	const Date getDate() const {
		return _chargeDate;
	}
	const double getValue() const {
		return _value;
	}
};

class DateRange
{
private:
	const Date _start;
	const Date _end;

public:
	DateRange(const Date& start, const Date& end) : _start(start), _end(end) {}
	const Date getStart() const {
		return _start;
	}
	const Date getEnd() const {
		return _end;
	}
	const bool includes(const Date& arg) const {
		return (arg.equals(getStart()) || arg.equals(getEnd()) ||
			(arg.after(getStart()) && arg.before(getEnd())));
	}
};

class Account
{
private:
	std::vector<Entry> entrys;

public:
	const double getFlowBetween(const DateRange& range) const {
		double result = 0;
		for (auto e : entrys) {
			if (range.includes(e.getDate())){
				result += e.getValue();
			}
		}
		return result;
	}
};