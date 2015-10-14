#include "Errors.h"
#include "gtest/gtest.h"

//=============================================================================
TEST(SuccesTest, IsEmpty)
{
	Success_C::SetSuccess(IS_EMPTY);
	ASSERT_EQ(IS_EMPTY, Success_C::GetSuccess());
}

TEST(SuccesTest, FILE_CREATED_SUCC)
{
	Success_C::SetSuccess(FILE_CREATED_SUCC);
	ASSERT_EQ(FILE_CREATED_SUCC, Success_C::GetSuccess());
}

//=============================================================================
TEST(ErrorTest, NoError)
{
	Error_C::SetError(IS_OK);
	ASSERT_EQ(IS_OK, Error_C::GetError());	
}

TEST(ErrorTest, FileNameError)
{
	Error_C::SetError(FILE_NAME_ERR);
	ASSERT_EQ(FILE_NAME_ERR, Error_C::GetError());	
}

TEST(ErrorTest, AmountError)
{
	Error_C::SetError(AMOUNT_ERR);
	ASSERT_EQ(AMOUNT_ERR, Error_C::GetError());	
}

TEST(ErrorTest, CommandError)
{
	Error_C::SetError(COMMAND_ERR);
	ASSERT_EQ(COMMAND_ERR, Error_C::GetError());
}

TEST(ErrorTest, NoFileNameError)
{
	Error_C::SetError(NO_FILE_NAME_ERR);
	ASSERT_EQ(NO_FILE_NAME_ERR, Error_C::GetError());
}

TEST(ErrorTest, NegIncomeError)
{
	Error_C::SetError(NEG_INCOME_ERR);
	ASSERT_EQ(NEG_INCOME_ERR, Error_C::GetError());	
}

TEST(ErrorTest, InvalidIncomeError)
{
	Error_C::SetError(INVALID_INCOME_ERR);
	ASSERT_EQ(INVALID_INCOME_ERR, Error_C::GetError());
}

TEST(ErrorTest, NoAmountError)
{
	Error_C::SetError(NO_AMOUNT_ERR);
	ASSERT_EQ(NO_AMOUNT_ERR, Error_C::GetError());
}

TEST(ErrorTest, OpenFileError)
{
	Error_C::SetError(OPEN_FILE_ERR);
	ASSERT_EQ(OPEN_FILE_ERR, Error_C::GetError());
}
//=============================================================================
