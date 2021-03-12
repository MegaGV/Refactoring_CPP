
enum class BloodGroup { O, A, B, AB };

class Person
{
private:
	BloodGroup _bloodGroup;

public:
	Person(BloodGroup bloodGroup) : _bloodGroup(bloodGroup) {}
	void setBloodGroup(BloodGroup arg) {
		_bloodGroup = arg;
	}
	BloodGroup getBloodGroup() {
		return _bloodGroup;
	}
	int getBloodGroupCode() {
		return static_cast<int>(_bloodGroup);
	}
};