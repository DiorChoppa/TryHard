#include <iostream>
#include <string>
#include <exception>

std::string AskTimeServer(){
	return "03:30:00";
}

class TimeServer {
	public:
		std::string GetCurrentTime(){
			try {
				LastFetchedTime = AskTimeServer();
				return LastFetchedTime;
			} catch (std::system_error& se) {
				return LastFetchedTime;
			}
		}

	private:
		std::string LastFetchedTime = "00:00:00";
};

int main(){
	TimeServer ts;
	try {
		std::cout << ts.GetCurrentTime() << std::endl;
	} catch (std::exception& e){
		std::cout << "Exception got: " << e.what() << std::endl;
	}

	return 0;
}