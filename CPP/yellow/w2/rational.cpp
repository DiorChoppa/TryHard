#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <sstream>
#include <stdexcept>

template <class T>
std::ostream& operator << (std::ostream& os, const std::vector<T>& s){
	os << "{";
	bool first = true;
	for (const auto& x : s){
		if (!first){
			os << ", ";
		}
		first = false;
		os << x;
	}
	return os << "}";
}

template <class T>
std::ostream& operator << (std::ostream& os, const std::set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
std::ostream& operator << (std::ostream& os, const std::map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template <class T, class U>
void AssertEqual(const T& t, const U& u, const std::string& hint = {}){
	if (t != u){
		std::ostringstream os;
		os << "Assertion failed: " << t << " != " << u;
		if (!hint.empty()){
			os << " hint: " << hint;
		}
		throw std::runtime_error(os.str());
	}
}

void Assert(bool b, const std::string hint){
	AssertEqual(b, true, hint);
}

class TestRunner{
	public:
		template <class TestFunc>
		void RunTest(TestFunc func, const std::string& name){
			try:
				func();
				std::cerr << name << " OK" << std::endl;
			} catch (std::exception& e) {
				++fail_count;
				std::cerr << name << " fail: " << e.what() << std::endl;
			} catch (...) {
				++fail_count;
				std::cerr << "Unknown exception caught!" << std::endl;
			}

	~TestRunner(){
		if (fail_count > 0){
			std::cerr << fail_count << " uint tests failed." << std::endl;
			exit(1);
		}
	}

	private:
		int fail_count = 0;
};

void TestPredefined() {
  AssertEqual(Rational(1, 1).Numerator(), 1, "Canonical form of 1/1 is 1/1");
  AssertEqual(Rational(1, 1).Denominator(), 1, "Canonical form of 1/1 is 1/1");
  AssertEqual(Rational(3, 5).Numerator(), 3, "Canonical form of 3/5 is 3/5");
  AssertEqual(Rational(3, 5).Denominator(), 5, "Canonical form of 3/5 is 3/5");
  AssertEqual(Rational(2147483647, 2147483647).Numerator(), 1, "Canonical form of 2147483647/2147483647 is 1/1");
  AssertEqual(Rational(2147483647, 2147483647).Denominator(), 1, "Canonical form of 2147483647/2147483647 is 1/1");
  AssertEqual(Rational(-5, 4).Numerator(), -5, "Canonical form of -5/4 is -5/4");
  AssertEqual(Rational(-5, 4).Denominator(), 4, "Canonical form of -5/4 is -5/4");
  AssertEqual(Rational(5, -4).Numerator(), -5, "Canonical form of 5/-4 is -5/4");
  AssertEqual(Rational(5, -4).Denominator(), 4, "Canonical form of 5/-4 is -5/4");
  AssertEqual(Rational(-6, -2).Numerator(), 3, "Canonical form of -6/-2 is 3/1");
  AssertEqual(Rational(-6, -2).Denominator(), 1, "Canonical form of -6/-2 is 3/1");
  AssertEqual(Rational(21, 56).Numerator(), 3, "Canonical form of 21/56 is 3/8");
  AssertEqual(Rational(21, 56).Denominator(), 8, "Canonical form of 21/56 is 3/8");
  AssertEqual(Rational(0, 100).Numerator(), 0, "Canonical form of 0/100 is 0/1");
  AssertEqual(Rational(0, 100).Denominator(), 1, "Canonical form of 0/100 is 0/1");
  AssertEqual(Rational().Numerator(), 0, "Canonical form of default constructed is 0/1");
  AssertEqual(Rational().Denominator(), 1, "Canonical form of default constructed is 0/1");
}

class Rational {
	public:
		Rational();
		Rational (int numerator, int denumenator);
		int Numerator() const {};
		int Denumerator() const {};
};

int main() {
  TestRunner runner;
  runner.RunTest(TestPredefined, "TestPredefined");
  return 0;
}