#include <iostream>

int Partition_Function(int n, int k) {
	if (n == 0 && k == 0) { return 1; }
	if (n <= 0 || k <= 0) { return 0; }
	return Partition_Function(n - k, k) + Partition_Function(n - 1, k - 1);
}

int main() {
	int n, k, result = 0;
	std::cin >> n >> k;
	for (int i = 1; i <= k; ++i) {
		result += Partition_Function(n, i);
	}
	std::cout << result;
}
