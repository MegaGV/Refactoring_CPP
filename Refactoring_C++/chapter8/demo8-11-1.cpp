#include <string>
#include <set>

class Course
{
private:
	std::string _name;
	bool _isAdvanced;
public:
	Course(std::string name, bool isAdvanced) : _name(name), _isAdvanced(isAdvanced) {}
	bool isAdvanced() {
		return _isAdvanced;
	}
};

class Person
{
private:
	std::set<Course> _courses;
public:
	std::set<Course> getCourses() {
		return _courses;
	}
	void setCourses(std::set<Course> arg) {
		_courses = arg;
	}
};