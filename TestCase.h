#ifndef TESTCASE_H
#define TESTCaSe_H
#pragma once

class TestCase
{
public:
	TestCase(void);
	TestCase(int factorSize);
	~TestCase(void);
	int* options; //A pointer that will hold all of our selected options
};
#endif
