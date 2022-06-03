#include <iostream>
#include <vector>
#include <iomanip>
#include <climits>
#include <cmath>

class Square_Root {
public:
	long long seq0;
	long long seq1;
	long long seq2;

	int K;

	Square_Root(int k) {
		K = k;
	}

	void Recurrence() {
		const long long LIMIT = LLONG_MAX / 1000;
		--K;
		int i = 2;
		seq2 = 2 * seq1 + K * seq0;
		while (true) {
			seq0 = seq1;
			seq1 = seq2;

			++i;
			seq2 = 2 * seq1 + K * seq0;
			if (seq2 > LIMIT) {
				seq1 /= 100;
				seq2 /= 100;
			}

			if (abs(static_cast<long double>(seq2) / static_cast<long double>(seq1) - static_cast<long double>(seq1) / static_cast<long double>(seq0)) < 0.0001) { break; }
		}
		++K;
	}
};

int main() {
	Square_Root test(1);
	for (int att = 0; att < 1000; ++att) {
		for (long long i = 1; i < 1000; ++i) {
			test.K = i;
			test.seq0 = 2;
			test.seq1 = 2;
			test.Recurrence();
		}
	}
	return 0;
}

