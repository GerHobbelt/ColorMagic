#include "gtest\gtest.h"
#include "pch.h"
#include "..\ColorMagic\ColorSpaces\icolor.h"
#include "..\ColorMagic\ColorSpaces\Colors.h"
#include "..\ColorMagic\ColorSpaces\rgb_truecolor.h"

using namespace ColorSpaces;

class RGB_True_Test : public ::testing::Test {
protected:
	rgb_truecolor* red;
	rgb_truecolor* yellow;
	rgb_truecolor* black;
	rgb_truecolor* grey;
	rgb_truecolor* white;
	rgb_truecolor* transparent;

	virtual void SetUp() 
	{
		red = new rgb_truecolor(255, 0, 0, 255);
		yellow = new rgb_truecolor(255, 255, 0, 255);
		black = new rgb_truecolor(0, 0, 0, 255);
		grey = new rgb_truecolor(128, 128, 128, 255);
		white = new rgb_truecolor(255, 255, 255, 255);
		transparent = new rgb_truecolor(255, 255, 255, 0);
	}

	virtual void TearDown()
	{
		delete red;
		delete yellow;
		delete black;
		delete grey;
		delete white;
		delete transparent;
	}
};

TEST_F(RGB_True_Test, From_HexCode_Tests)
{
	EXPECT_EQ(*red, *(Color(HexcodeColors::Red).get_rgb_true()));
	EXPECT_EQ(*yellow, *(Color(HexcodeColors::Yellow).get_rgb_true()));
	EXPECT_EQ(*black, *(Color(HexcodeColors::Black).get_rgb_true()));
	EXPECT_EQ(*grey, *(Color(HexcodeColors::Gray).get_rgb_true()));
	EXPECT_EQ(*white, *(Color(HexcodeColors::White).get_rgb_true()));
	EXPECT_EQ(*transparent, *(Color(HexcodeColors::Transparent).get_rgb_true()));
}
