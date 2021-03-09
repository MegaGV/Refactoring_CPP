

class Test
{
public:
	const int discount(const int& inputVal, const int& quantity, const int& yearToDate) const {
		int result = inputVal;
		if (inputVal > 50) result -= 2;
		if (quantity > 100) result -= 1;
		if (yearToDate > 10000) result -= 4;
		return result;
	}
};