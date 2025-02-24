#include "pch.h"
#include "../0703_BaseballKATA/Baseball.cpp"

using namespace std;

class BaseballFixture :public testing::Test {
public:
	Baseball game{ "123" };
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
	assertIllegalArgument("121");
}

TEST_F(BaseballFixture, ReturnSolveResultIfMatchedNumber) {
	GuessResult result = game.guess("123");

	EXPECT_TRUE(result.solved);
	EXPECT_EQ(3, result.strikes);
	EXPECT_EQ(0, result.balls);
}

TEST_F(BaseballFixture, ReturnSolveResult2S0B) {
	GuessResult result = game.guess("128");

	EXPECT_TRUE(result.solved == false);
	EXPECT_EQ(2, result.strikes);
	EXPECT_EQ(0, result.balls);
}

TEST_F(BaseballFixture, ReturnSolveResult1S2B) {
	GuessResult result = game.guess("132");

	EXPECT_TRUE(result.solved == false);
	EXPECT_EQ(1, result.strikes);
	EXPECT_EQ(2, result.balls);
}

TEST_F(BaseballFixture, ReturnSolveResult0S0B) {
	GuessResult result = game.guess("789");
	EXPECT_TRUE(result.solved == false);
	EXPECT_EQ(0, result.strikes);
	EXPECT_EQ(0, result.balls);
}

TEST_F(BaseballFixture, ReturnSolveResult0S3B) {
	GuessResult result = game.guess("312");
	EXPECT_TRUE(result.solved == false);
	EXPECT_EQ(0, result.strikes);
	EXPECT_EQ(3, result.balls);
}


