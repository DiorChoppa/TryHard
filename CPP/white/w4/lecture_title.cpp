#include <iostream>
#include <string>

struct Specialization{
	std::string value;
	
	explicit Specialization(std::string mew){
		value = mew;
	}
};

struct Course{
	std::string value;

	explicit Course(std::string mew){
		value = mew;
	}
};

struct Week{
	std::string value;

	explicit Week(std::string mew){
		value = mew;
	}
};

struct LectureTitle {
	std::string specializtion;
	std::string course;
	std::string week;

	LectureTitle(Specialization sp, Course cs, Week wk){
		specializtion = sp.value;
		course = cs.value;
		week = wk.value;
	}
};

int main(){
	LectureTitle title(
		Specialization("C++"),
		Course("White belt"),
		Week("4th")
	);

	return 0;
}