
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

	const bool includes(const TempRange& arg) const {
		return arg.getLow() >= low && arg.getHigh() <= high;
	}
};

class HeatingPlan
{
private:
	TempRange _range;
public:
	const bool withinRange(const TempRange& roomRange) const {
		return _range.includes(roomRange);
	}
};

class Room
{
public:
	const bool withinPlan(const HeatingPlan& plan) const {
		return plan.withinRange(daysTempRange());
	}

	const TempRange daysTempRange() const {
		return TempRange();
	}
};