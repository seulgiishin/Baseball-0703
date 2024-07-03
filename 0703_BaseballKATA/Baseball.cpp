#include <stdexcept>

using namespace std;

struct GuessResult {
	bool solved;
	int strikes;
	int balls;
};

class Baseball {
public:
	Baseball(const string& number)
		:question(number) {}

	GuessResult guess(const string& guessNumber) {
		assrtIllegalArgument(guessNumber);
		if (guessNumber == question) {
			return { true,3,0 };
		}
		
		return { false, getStrikeCount(guessNumber) ,getBallCount(guessNumber)};
	}

	int getStrikeCount(const std::string& guessNumber)
	{
		int strikeCount = 0;
		for (int index = 0; index < QUESTION_LENGTH; index++) {
			if (question[index] == guessNumber[index])
				strikeCount++;
		}
		return strikeCount;
	}

	int getBallCount(const std::string& guessNumber)
	{
		int ballCount = 0;
		for (int guessIndex = 0; guessIndex < QUESTION_LENGTH; guessIndex++) {
			for (int questionIndex = 0; questionIndex < QUESTION_LENGTH; questionIndex++) {
				if (guessIndex == questionIndex) continue;
				if (guessNumber[guessIndex] == question[questionIndex])
					ballCount++;
			}
		}
		return ballCount;
	}


	void assrtIllegalArgument(const std::string& guessNumber)
	{
		if (guessNumber.length() != QUESTION_LENGTH) {
			throw length_error("Must be three letters");
		}

		for (char ch : guessNumber) {
			if (ch >= '0' && ch <= '9') continue;

			throw invalid_argument("Must be number");
		}

		if (isDuplicatedNumber(guessNumber)) {
			throw invalid_argument("Must not have the same number");
		}
	}
	bool isDuplicatedNumber(const std::string& guessNumber)
	{
		return guessNumber[0] == guessNumber[1] ||
			guessNumber[1] == guessNumber[2] ||
			guessNumber[2] == guessNumber[0];
	}
private:
	string question;
	const int QUESTION_LENGTH = 3;
};