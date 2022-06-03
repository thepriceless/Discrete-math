#include <iostream>
#include <vector>
#include <iomanip>
#include <climits>
#include <math.h>

class Square_Root {
public:
	long long seq0;
	long long seq1;
	long long seq2;

	int K;

	Square_Root(int k) {
		K = k;
		seq0 = 2;
		seq1 = 2;
		seq2 = 2;
	}

	void Recurrence() {
		const long long LIMIT = LLONG_MAX / 100;
		--K;
		int i = 2;
		seq2 = 2 * seq1 + K * seq0;
		while (true) {
			seq0 = seq1;
			seq1 = seq2;

			++i;
			seq2 = 2 * seq1 + K * seq0;
			if (seq2 > LIMIT) {
				seq1 /= 10;
				seq2 /= 10;
			}
		}
		++K;
	}
};

int main() {
	Square_Root test_(1);
	for (int att = 0; att < 1000; ++att) {
		for (long long i = 1; i < 1000; ++i) {
			std::sqrt(i);
		}
	}
	return 0;
}
