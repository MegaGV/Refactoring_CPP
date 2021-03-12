
class Person
{
private:
	int _bloodGroup;

public:
	static const int O = 0;
	static const int A = 1;
	static const int B = 2;
	static const int AB = 3;

	Person(int bloodGroup) : _bloodGroup(bloodGroup) {}
	void setBloodGroup(int arg) {
		_bloodGroup = arg;
	}
	int getBloodGroup() {
		return _bloodGroup;
	}
};