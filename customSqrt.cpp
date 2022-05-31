#include <iostream>
#include <vector>
#include <iomanip>

class Square_Root {
public:
	int K;
	std::vector<long double> Sequence;


	Square_Root(int k) {
		K = k;
		Sequence.resize(1000);
		Sequence[0] = 2;
		Sequence[1] = 2;
	}

	void Recurrence() {
		const long double LIMIT = LDBL_MAX / 100;
		--K;
		Sequence[2] = 2 * Sequence[1] + K * Sequence[0];
		int i = 2;
		while (abs((Sequence[i] / Sequence[i - 1]) - (Sequence[i - 1] / Sequence[i - 2])) > 0.00001 && Sequence[i] < LIMIT) {
			++i;
			Sequence[i] = 2 * Sequence[i - 1] + K * Sequence[i - 2];
			//std::cout << Sequence[i] << '\n';
			//std::cout << "seq: " << std::setprecision(8) << Sequence[i] / Sequence[i - 1] - 1 << '\n';
			//std::cout << "dif: " << std::setprecision(8) << (Sequence[i] / Sequence[i - 1]) - (Sequence[i - 1] / Sequence[i - 2]) << '\n';
		}
		//std::cout << std::setprecision(6) << (Sequence[i]) / (Sequence[i - 1]) - 1 << '\n';
		++K;
	}
};

int main() {
	Square_Root test(1);
	for (int i = 1; i < 200; ++i) {
		test.K = i;
		test.Recurrence();
	}
}
