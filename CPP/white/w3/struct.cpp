#include <iostream>

struct LectureTitle {
	std::string specialization;
	std::string course;
	std::string week;
};

struct DetailedLecture {
	LectureTitle title;
	int duration;
};

int main(){
	LectureTitle title = {"C++", "White belt", "OOP"};
	DetailedLecture lecture1 = {title, 5400};

	DetailedLecture lecture2 = {
		{"C++", "White belt", "OOP"},
		5400
	};

	std::cout << lecture2.title.specialization << "\n";

	return 0;
}