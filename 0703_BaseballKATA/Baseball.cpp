#include <stdexcept>

using namespace std;

class Baseball {
public:
	void guess(const string& input) {
		if (input.length() != 3) {
			throw length_error("Must be three letters");
		}

		for (char ch : input) {
			if (ch < 'a' || ch>'9') {
				throw invalid_argument("Must be number");
			}
		}
	}
};