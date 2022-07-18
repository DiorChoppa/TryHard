#include <iostream>
#include <string>
#include <map>
#include <set>
#include <iomanip>
#include <sstream>

class Date {
	public:
		int GetDay() const {
			return day;	
		}
		int GetMonth() const {
			return month;	
		}
		int GetYear() const {
			return year;	
		}

	private:
		int year;
		int month;
		int day;
};

class DataBase {
	public:


	private:
		std::map<Date, std::string> db;
};

int main(){


	return 0;
}