#include <iostream>
class test {
	public :
	int i;
	public :
		test (int t) : i(t) {};

		// bool min(const test& first, const test& second) {
		// 	return (first.i > second.i) ? 1 : 0;
		// }
		static test& min(test& first, test& second) {
			return (first.i < second.i) ? first : second;
		}
		static const test& min(const test& first, const test& second) {
			return (first.i < second.i) ? first : second;
		}
};

int main () {
	int i = 0;
	int j = 1;

	std::cout << i;
}