#include <iostream>
#include <fstream>
#include <string>

struct Duration{
	int hour;
	int min;
};

Duration ReadDuration(std::istream& stream){
	int h =0;
	int m = 0;
	stream >> h;
	stream.ignore(10);
	stream >> m;
	return Duration {h, m};
}

void PrintDuration(std::ostream& stream, const Duration& duration){
	stream << std::setfill ('0');
	stream << std::setw (2) << duration.hour << ':'
			<< std::setw (2) << duration.min;
}

std::ostream& operator << (std::ostream& stream, const Duration& duration){
	stream << std::setfill ('0');
    stream << std::setw (2) << duration.hour << ':'
	<< std::setw (2) << duration.min;
	return stream;
}

std::istream& operator >> (std::istream& stream, Duration& duration){
	stream >> duration.hour;
	stream.ignore(1);
	stream >> duration.min;
	return stream;
}

int main(){
	std::stringstream dur_ss("02:50");
    Duration dur1 {0, 0};
    dur_ss >> dur1;
    std::cout << dur1 << std::endl;

	return 0;
}