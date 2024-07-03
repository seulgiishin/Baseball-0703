#include "pch.h"
#include "../0703_BaseballKATA/Baseball.cpp"

using namespace std;

TEST(BaseballGame, throwExceptionWhenInputLengthIsUnmatched) {
	Baseball game;
	EXPECT_THROW(game.guess(string("12")), length_error);
}

TEST(BaseballGame, throwExceptionWhenInvalidChar) {
	Baseball game;
	EXPECT_THROW(game.guess(string("12s")), invalid_argument);
}