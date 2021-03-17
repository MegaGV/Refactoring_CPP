

class Person
{
private:
	const bool _isMale;
	const char _code;

	static Person* createMale() {
		return new Person(true, 'M');
	}
	static Person* createFeMale() {
		return new Person(false, 'F');
	}

protected:
	Person(bool isMale, char code) : _isMale(isMale), _code(code) {}
};