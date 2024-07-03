#include "pch.h"
#include "../0703_BaseballKATA/Baseball.cpp"

using namespace std;

class BaseballFixture :public testing::Test {
public:
	Baseball game;
	void assertIllegalArgument(string guessNumber) {
		try {
			game.guess(guessNumber);
			FAIL();
		}
		catch (exception e) {
			//pass
		}
	}
};
TEST_F(BaseballFixture, throwExceptionWhenInvalidCase) {
	assertIllegalArgument("12");
	assertIllegalArgument("12s");
}