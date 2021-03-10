


class Account
{
private:
	struct AccountType {
		const bool isPremium() const;
		const double overdraftCharge(int daysOverdrawn) const {
			if (isPremium()) {
				double result = 10;
				if (daysOverdrawn > 7)
					result += (daysOverdrawn - 7) * 0.85;
				return result;
			}
			else
				return daysOverdrawn * 1.75;
		}
		const double overdraftCharge(const Account* account) const {
			if (isPremium()) {
				double result = 10;
				if ((*account).getDaysOverdrawn() > 7)
					result += ((*account).getDaysOverdrawn() - 7) * 0.85;
				return result;
			}
			else
				return (*account).getDaysOverdrawn() * 1.75;
		}
	};

	AccountType _type;
	int _daysOverdrawn;
public:
	const double overdraftCharge() const {
		return _type.overdraftCharge(this);
	}
	const double overdraftCharge2() const {
		return _type.overdraftCharge(_daysOverdrawn);
	}
	const double bankCharge() {
		double result = 4.5;
		if (_daysOverdrawn > 0)
			result += _type.overdraftCharge(_daysOverdrawn);
		return result;
	}
	const int getDaysOverdrawn() const {
		return _daysOverdrawn;
	}
};

