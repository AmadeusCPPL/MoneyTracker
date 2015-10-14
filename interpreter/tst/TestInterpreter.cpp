#include "Interpreter.h"
#include "gtest/gtest.h"


TEST(validCommand, TestValidCommand)
{
	Interpreter interpreter;
	EXPECT_EQ(true, interpreter.isValidCommand("create"));
	EXPECT_EQ(true, interpreter.isValidCommand("income"));
	EXPECT_EQ(false, interpreter.isValidCommand("abc"));
}
//=============================================================================

TEST(validAmount, TestValidAmount)
{
	Interpreter interpreter;
	EXPECT_EQ(true, interpreter.isValidAmount("12.24"));
	EXPECT_EQ(true, interpreter.isValidAmount("+200"));
	EXPECT_EQ(true, interpreter.isValidAmount("-1021.23"));
	EXPECT_EQ(true, interpreter.isValidAmount("22.125"));
	EXPECT_EQ(true, interpreter.isValidAmount("-00012.24"));
	EXPECT_EQ(false, interpreter.isValidAmount("12,24"));	
}
//=============================================================================
 
TEST (returnOperation, TestAmountOperation)
{
	Interpreter interpreter;
	EXPECT_EQ('+', interpreter.returnOperation("+12.24"));
	EXPECT_EQ('+', interpreter.returnOperation("22.125"));
	EXPECT_EQ('-', interpreter.returnOperation("-12.24"));
}
//=============================================================================

TEST (roundNumber, TestRoundNumber)
{
	Interpreter interpreter;
	EXPECT_FLOAT_EQ(22.13, interpreter.roundNumber('+',22.125));
	EXPECT_FLOAT_EQ(123.1, interpreter.roundNumber('+',123.1));
	EXPECT_FLOAT_EQ(123.56, interpreter.roundNumber('-',123.5599));
}
//=============================================================================

