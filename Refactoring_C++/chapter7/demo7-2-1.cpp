

class Account
{
private:
	struct AccountType {};
	AccountType _type;
	double _interestRate;

public:
	double interestForAmount_days(double amount, int days) {
		return _interestRate * amount * days / 365;
	}
};

