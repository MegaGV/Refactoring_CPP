
class IntRange
{
private:
	int _low;
	int _high;

public:
	IntRange(int low, int high) : _low(low), _high(high) {}
	bool includes(int arg) {
		return arg >= _low && arg <= _high;
	}
	void grow(int factor) {
		_high = _high * factor;
	}
};
