
class TempRange
{
private:
	int low;
	int high;

public:
	const int getLow() const {
		return low;
	}
	const int getHigh() const {
		return high;
	}
};

class HeatingPlan
{
private:
	TempRange _range;
public:
	bool withinRange(int low, int high) {
		return (low >= _range.getLow() && high <= _range.getHigh());
	}
};

class Room
{
public:
	bool withinPlan(HeatingPlan plan) {
		int low = daysTempRange().getLow();
		int high = daysTempRange().getHigh();
		return plan.withinRange(low, high);
	}

	TempRange daysTempRange() {
		return TempRange();
	}
};