#include <string>
#include <set>

class Course
{
private:
	std::string _name;
	bool _isAdvanced;
public:
	Course(std::string name, bool isAdvanced) : _name(name), _isAdvanced(isAdvanced) {}
	const bool isAdvanced() const {
		return _isAdvanced;
	}
	const std::string getName() const {
		return _name;
	}

	const bool operator< (const Course& course) const {
		return _name.compare(course.getName());
	}
};

class Person
{
private:
	std::set<Course> _courses;
public:
	const std::set<Course> getCourses() const {
		return _courses;
	}
	void initializeCourses(std::set<Course>& arg) {
		_courses = arg;
	}

	void addCourse(Course arg) {
		_courses.emplace(arg);
	}
	void removeCourse(Course arg) {
		auto it = _courses.find(arg);
		if (it != _courses.end())
			_courses.erase(it);
	}

	const int numberOfAdvancedCourses() const {
		int count = 0;
		for (auto course : _courses)
			if (course.isAdvanced())
				count++;
		return count;
	}
};