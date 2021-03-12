#include <algorithm>


class IntRange
{
private:
	int _low;
	int _high;

public:
	IntRange(int low, int high) {
		initialize(low, high);
	}
	const bool includes(int arg) const {
		return arg >= getLow() && arg <= getHigh();
	}
	void grow(int factor) {
		_high = _high * factor;
	}

	const int getLow() const {
		return _low;
	}
	void setLow(int arg) {
		_low = arg;
	}
	const int getHigh() const {
		return _high;
	}
	void setHigh(int arg) {
		_high = arg;
	}
	void initialize(int low, int high) {
		_low = low;
		_high = high;
	}
};

class CappedRange : IntRange
{
private:
	int _cap;

public:
	CappedRange(int low, int high, int cap) : IntRange(low, high), _cap(cap) {}
	const int getCap() const {
		return _cap;
	}
	void setCap(int arg) {
		_cap = arg;
	}
	const int getHigh() const {
		return std::min(IntRange::getHigh(), getCap());
	}
};
