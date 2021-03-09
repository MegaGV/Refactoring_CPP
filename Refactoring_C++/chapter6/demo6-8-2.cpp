

class Account
{
public:
	int delta();
	int gamma(int inputVal, int quantity, int yearToDate) {
		return new Gamma(inputVal, quantity, yearToDate, delta())->compute();
	}
};

class Gamma
{
private:
	int delta;
	int inputVal;
	int quantity;
	int yearToDate;
	int importantValue1;
	int importantValue2;
	int importantValue3;

	void importantThing() {
		if ((yearToDate - importantValue1) > 100) {
			importantValue2 -= 20;
		}
	}

public:
	Gamma(int inputValArg, int quantityArg, int yearToDateArg, int deltaArg) 
		: inputVal(inputValArg), quantity(quantityArg), yearToDate(yearToDateArg), delta(deltaArg){}
	int compute() {
		importantValue1 = (inputVal * quantity) + delta;
		importantValue2 = (inputVal * yearToDate) + 100;
		importantThing();
		importantValue3 = importantValue2 * 7;
		// and so on
		return importantValue3 - 2 * importantValue1;
	}
};