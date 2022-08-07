#include <iostream>
#include <map>
#include <vector>

enum class Lang {
	DE, FR, IT
};

struct Region {
	std::string name;
	std::string parent_name;
	std::map<Lang, std::string> names;
	int64_t population;
};

bool operator < (const Region& lhs, const Region& rhs){
	return std::tie(lhs.name, lhs.names, lhs.parent_name, lhs.population) <
			std::tie(rhs.name, rhs.names, rhs.parent_name, rhs.population);
}

int FindMaxRepetitionCount(const std::vector<Region>& regions){
	if(regions.empty()) return 0;

	std::map<Region, int> all;
	for(const auto& r : regions)
		all[r]++;
	
	int max = 0;
	for(const auto& pair : all)
		if(pair.second > max)
			max = pair.second;

	return max;
}

int main() {
	std::cout << FindMaxRepetitionCount({
      {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Russia",
          "Eurasia",
          {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
          89
      }, {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Russia",
          "Eurasia",
          {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
          89
      },
  		}) << std::endl;

	std::cout << FindMaxRepetitionCount({
      {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Russia",
          "Eurasia",
          {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
          89
      }, {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Moscow",
          "Toulouse",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          89
      }, {
          "Moscow",
          "Russia",
          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
          31
      },
  		}) << std::endl;
	return 0;
}