#include <iostream>
using namespace std;

int main() {
	int n = 0, k = 0;
	cin >> n >> k;
	cout << n * 3 + min(k - 1, n - k);
}