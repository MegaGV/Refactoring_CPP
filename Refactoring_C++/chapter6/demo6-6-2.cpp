#include <algorithm>

class Test
{
private:
	double _primaryForce;
	double _secondaryForce;
	double _mass;
	int _delay;

	const double getAcc(double force) const {
		return force / _mass;
	}
	const int getPrimaryTime(int time) const {
		return std::min(time, _delay);
	}
	const int getSecondaryTime(int time) const {
		return time - _delay;
	}
	const double getPrimaryVel() const {
		return getAcc(_primaryForce) * _delay;
	}

public:
	const double getDistanceTravelled(int time) const {
		double result = 0.5 * getAcc(_primaryForce) * getPrimaryTime(time) * getPrimaryTime(time);
		if (getSecondaryTime(time) > 0) {
			result += getPrimaryVel() * getSecondaryTime(time) +
				0.5 * getAcc(_primaryForce + _secondaryForce) * getSecondaryTime(time) * getSecondaryTime(time);
		}
		return result;
	}
};