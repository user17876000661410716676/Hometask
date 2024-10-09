#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;
using namespace chrono;

int main() {
	int n;
	cin >> n;
	n = n % 1001;
	mt19937 mt(time(nullptr));
	vector<int> Sort1(n);
	for (int i = 0; i < n; i++) {
		Sort1[i] = mt() % 100;
	}

	for (int i = 0; i < n; i++) {
		cout << Sort1[i] << endl;
	}
	auto start = steady_clock::now();
	for (int j = 0; j < n - 1; j++) {
		if (j % 2 == 0) {
			if (Sort1[j] < Sort1[j + 1]) {
				swap(Sort1[j], Sort1[j + 1]);
			}
		}
		else {
			if (Sort1[j] > Sort1[j + 1]) {
				swap(Sort1[j], Sort1[j + 1]);
			}
		}
	}
	auto end = steady_clock::now();
	duration < double > elapsed_seconds = end - start;
	cout << " elapsed time : " << elapsed_seconds.count() << "s\n";
	for (int i = 0; i < n; i++) {
		cout << Sort1[i] << endl;
	}
}