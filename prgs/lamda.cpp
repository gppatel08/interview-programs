#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void show(std::vector<int> v) {
	cout << "vec elem  : ";
	for(auto it = std::begin(v); it != std::end(v); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

int main(int argc, char* argv[]) {
	int oddCount = 0, evenCount = 0;
	auto isOddEven = [&](int num) { if(num%2) ++oddCount; else ++evenCount;};

	std::vector<int> v;
	for(auto i = 1; i < argc; i++) {
		v.push_back(atoi(argv[i]));
	}

	for_each(std::begin(v), std::end(v), isOddEven);
	show(v);
	cout << "oddCount  : " << oddCount << endl;
	cout << "evenCount : " << evenCount << endl;
}
