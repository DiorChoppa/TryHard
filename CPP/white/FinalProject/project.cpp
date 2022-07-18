#include <iostream>
#include <string>
#include <map>
#include <set>
#include <iomanip>
#include <sstream>
#include <fstream>

class Date {
	public:
		Date() {
			year = 0001;
			month = 01;
			day = 01;
		}

		Date (int new_year, int new_month, int new_day){
			year = new_year;
			if (new_month < 1 || new_month > 12){
				std::string error = "Month value is invalid = " + std::to_string(new_month);
				throw std::invalid_argument(error);
			}
			month = new_month;
			if (new_day < 1 || new_day > 31){
				std::string error = "Day value is invalid = " + std::to_string(new_day);
				throw std::invalid_argument(error);
			}
			day = new_day;
		}

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

bool operator < (const Date& lhs, const Date& rhs){
	if(lhs.GetYear() == rhs.GetYear()){
		if(lhs.GetMonth() == rhs.GetMonth()){
			return lhs.GetDay() < rhs.GetDay();
		} else return lhs.GetMonth() < rhs.GetMonth();
	} else {
		return lhs.GetYear() < rhs.GetYear();
	}
}

class DataBase {
	public:
		void AddEvent(const Date& date, std::string event){
			if(db.count(date) > 1){
				db[date].insert(event);
			} else {
				std::set<std::string> events;
				events.insert(event);
				db[date] = events;
			}
		}
		bool DeleteEvent(const Date& date, std::string event){
			bool r = true;
			if(db[date].count(event) > 0){
				db[date].erase(event);
			} else {
				r = false;
			}
			return r;
		}
		int DeleteDate(const Date& date){
			int n = 0;
			if (db.count(date) > 0){
				n = db[date].size();
				db.erase(date);
			}
			return n;
		}
		void Find(const Date& date) const {
			try {
				std::set<std::string> ss = db.at(date);
				for(const auto& i : ss){
					std::cout << i << std::endl;
				}
			} catch (std::out_of_range&){

			}
		}
		void Print() const {
			for(const auto& pair : db){
				for(const auto& event : pair.second){
					std::cout << std::setw(4) << std::setfill('0') << pair.first.GetYear() << '-';
					std::cout << std::setw(4) << std::setfill('0') << pair.first.GetMonth() << '-';
					std::cout << std::setw(4) << std::setfill('0') << pair.first.GetDay();
					std::cout << " " << event << std::endl;
				}
			}
		}

	private:
		std::map<Date, std::set<std::string>> db;
};

std::ostream& operator << (std::ostream& out, const Date& date){
	out << date.GetYear() << "-" << date.GetMonth() << "-" << date.GetDay();
	return out;
}

void EnsureNextSymbolEndSkipped(std::istream& stream){
	if(stream.peek() != '-'){
		throw std::runtime_error("");
	}
	stream.ignore(1);
}

std::istream& operator >> (std::istream& in, Date& date){
	std::string input;
	in >> input;
	std::stringstream stream(input);
	int y, m, d;
	
	try {
		stream >> y;
		EnsureNextSymbolEndSkipped(stream);
		stream >> m;
		EnsureNextSymbolEndSkipped(stream);
		stream >> d;
		if (stream.peek() != -1){
			throw std::runtime_error("");
		}
	} catch (std::runtime_error& re){
		throw std::runtime_error("Wrong date format: " + input);
	}
	date = Date(y, m, d);

	return in;
}

int main(){
	DataBase db;

	std::string command;
	while (getline(std::cin, command)){
		std::stringstream stream(command);
		std::string operation;
		stream >> operation;

		try {
			if (operation == "Add") {
                stream.ignore(1);
                Date date;
                try {
                    stream >> date;
                } catch (std::exception& ex) {
                    std::cout << ex.what() << std::endl;
                    break;
                }
                stream.ignore(1);
                std::string event;
                stream >> event;
                db.AddEvent(date, event);
            } else if (operation == "Del") {
                stream.ignore(1);
                Date date;
                try {
                    stream >> date;
                } catch (std::exception& ex) {
                    std::cout << ex.what() << std::endl;
                    break;
                }
                if (stream.peek() != -1) {
                    stream.ignore(1);
                    std::string event;
                    stream >> event;
                    if (db.DeleteEvent(date, event)) {
                        std::cout << "Deleted successfully" << std::endl;
                    } else {
                        std::cout << "Event not found" << std::endl;
                    }
                } else {
                    int n = 0;
                    n = db.DeleteDate(date);
                    std::cout << "Deleted " << n << " events" << std::endl;
                }
            } else if (operation == "Find") {
                stream.ignore(1);
                Date date;
                try {
                    stream >> date;
                } catch (std::exception& ex) {
                    std::cout << ex.what() << std::endl;
                    break;
                }
                db.Find(date);
            } else if (operation == "Print") {
                db.Print();
                break;
            } else if (operation == "") {

            } else {
                throw std::runtime_error("Unknown command: " + operation);
			}
		} catch (std::exception& ex){
			std::cout << ex.what() << std::endl;
			break;
		}
	}

	return 0;
}