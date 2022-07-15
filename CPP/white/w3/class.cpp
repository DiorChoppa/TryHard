#include <iostream>
#include <vector>

class Route {
	public:
		Route() {
			source = "Moscow";
			destination = "Saint Petersburg";
			UpdateLength();
			std::cout << "Default constructed\n";
		}

		Route(const std::string& new_source, const std::string& new_destination){
			source = new_source;
			destination = new_destination;
			UpdateLength();
			std::cout << "Constructed\n";
		}

		~Route() {
			std::cout << "Destructed\n";
		}

		std::string GetSource() {return source;}
		std::string GetDestination() {return destination;}
		int GetLength() {return length;}
		void SetSource(const std::string& new_source){
			source = new_source;
			UpdateLength();
		}
		void SetDestination(const std::string& new_destination){
			destination = new_destination;
			UpdateLength();
		}
		int ComputeDistance(std::string& source, std::string& destination){
			return source.length() - destination.length();
		}


	private:
		std::string source;
		std::string destination;
		int length;
		std::vector<std::string> compute_distance_log;

		void UpdateLength(){
			length = ComputeDistance(source, destination);
			compute_distance_log.push_back(source + " — " + destination);
		}
};

int main(){
	// Route route;
	// route.SetSource("Moscow");
	// route.SetDestination("Dubai");
	// std::cout << "Route from " <<
	// 	route.GetSource() << " to " <<
	// 	route.GetDestination();

	// Route rout ("Moscow", "Dubai");
	for (int i : {0, 1}){
		std::cout << "Step " << i << ": " << 1 << "\n";
		Route route;
		std::cout << "Step " << i << ": " << 2 << "\n";
	}
	std::cout << "End\n";
	return 0;
}

// void PrintRoute(const Route& route);
// PrintRoute(Route());
// PrintRoute({});