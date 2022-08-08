#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <sstream>
#include <stdexcept>
#include <algorithm>

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
			try{
				func();
				std::cerr << name << " — OK" << std::endl;
			} catch(std::runtime_error& e) {
				++fail_count;
				std::cerr << name << " — FAIL!" << std::endl;
			}
		}

		~TestRunner(){
			if (fail_count > 0){
				std::cerr << "FAILED (failures = " << fail_count << ")" << std::endl;
				exit(1);
			} else {
				std::cerr << "OK" << std::endl;
			}
		}

	private:
		int fail_count = 0;	
};

bool IsPalindrom(const std::string& str){
	return std::equal(str.begin(), str.begin() + str.size() / 2, str.begin());
}

void test_is_palindrom(){
	Assert(IsPalindrom(""), "empty string ->> palindrome");
    Assert(IsPalindrom("c"), "c string ->> palindrome");
    Assert(IsPalindrom("aca"), "aca string ->> palindrome");
    Assert(IsPalindrom("acdca"), "acdca string ->> palindrome");
    Assert(IsPalindrom("AccA"), "AcсA string ->> palindrome");
    Assert(IsPalindrom("caZaZac"), "caZaZac string ->> palindrome");
    Assert(IsPalindrom("++C++"), "++C++ string ->> palindrome");
    Assert(IsPalindrom("aBCBa"), "c string ->> palindrome");
    Assert(IsPalindrom("   aBCBa   "), "   aBCBa    string ->> palindrome");
    Assert(IsPalindrom("   aBcBa   "), "   aBcBa    string ->> palindrome");
    Assert(IsPalindrom("a B c B a"), "a B c B a string ->> palindrome");
    Assert(IsPalindrom("MalayalaM"), "MalayalaM string ->> palindrome");
    Assert(IsPalindrom("\t\n  \n\t"), "\t\n  \n\t string ->> palindrome");
    Assert(IsPalindrom("abcdefghijklmnopqrstuvwxyzzyxwvutsrqponmlkjihgfedcba"), 
	"abcdefghijklmnopqrstuvwxyzzyxwvutsrqponmlkjihgfedcba string ->> palindrome");

    Assert(!IsPalindrom("VC"), "VC string != palindrome");
    Assert(!IsPalindrom("VVddVC"), "VVddVC string != palindrome");
    Assert(!IsPalindrom("VVddCV"), "VVddCV string != palindrome");
    Assert(!IsPalindrom("VCddVV"), "VCddVC string != palindrome");
    Assert(!IsPalindrom("CVddVV"), "CVddVV string != palindrome");
    Assert(!IsPalindrom("cvDdvc"), "cvDdvc string != palindrome");
    Assert(!IsPalindrom("cvdDvc"), "cvdDvc string != palindrome");
    Assert(!IsPalindrom("Cvddvc"), "CvdDvc string != palindrome");
    Assert(!IsPalindrom("cvddvC"), "cvddvC string != palindrome");
    Assert(!IsPalindrom("cvddVc"), "cvddVc string != palindrome");
    Assert(!IsPalindrom("cVddvc"), "cvddVc string != palindrome");
    Assert(!IsPalindrom("abcdefghijklmnopqrstuvwxyzzyxwvutsrqponmlkjihgfedcbb"), 
	"aaaaaabcdefghijklmnopqrstuvwxyzzyxwvutsrqponmlkjihgfedcbaaaaaadcccccccccc string != palindrome");
    Assert(!IsPalindrom("   CVddVC"), "   CVvdVC string != palindrome");
    Assert(!IsPalindrom("CVddVC   "), "CVvdVC    string != palindrome");
}

int main() {
	TestRunner runner;
	runner.RunTest(test_is_palindrom, "test_is_palindrom");
	return 0;
}