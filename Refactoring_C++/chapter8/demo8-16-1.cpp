

class Person
{
public:
	virtual bool isMale() = 0;
	virtual char getCode() = 0;
};

class Male : public Person
{
	bool isMale() override {
		return true;
	}
	char getCode() override {
		return 'M';
	}
};

class FeMale : public Person
{
	bool isMale() override {
		return false;
	}
	char getCode() override {
		return 'F';
	}
};