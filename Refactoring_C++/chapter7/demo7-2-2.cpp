

class Account
{
private:
	struct AccountType {
	private:
		double _interestRate;

	public:
		void setInterestRate(double arg) {
			_interestRate = arg;
		}
		const double getInterestRate() const {
			return _interestRate;
		}
	};

	AccountType _type;

public:
	const double interestForAmount_days(double amount, int days) const {
		return getInterestRate() * amount * days / 365;
	}

private:
	void setInterestRate(double arg) {
		_type.setInterestRate(arg);
	}
	const double getInterestRate() const {
		return _type.getInterestRate();
	}
};

