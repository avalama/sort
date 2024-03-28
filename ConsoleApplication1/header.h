#pragma once
#include <iostream>
#include "node.h"
using namespace std;
struct FailBlock
{
	double value;
	int estpos;
	FailBlock* next;
};
int methood1(double*, int, int);
int methood2(double*, int, int);
int methood3(double*, int, int);
double* failfix(double*, FailBlock*, int, int);