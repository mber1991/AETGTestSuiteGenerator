#include "stdafx.h"

TestCase::TestCase(void)
{
	//throw _EXCEPTION_;
}

TestCase::TestCase(int factorSize)
{
	options = new int[factorSize];
}


TestCase::~TestCase(void)
{
	delete [] options;
}