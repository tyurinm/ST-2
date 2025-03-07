// Copyright 2025 tyurinm
#ifndef INCLUDE_TASKS_H_
#define INCLUDE_TASKS_H_
#include <cstdint>
#include <cmath>
#include "circle.h"

double calculateRopeGap(double additionalLength);
double calculatePoolCosts(double poolRadius, double pathWidth, 
	double pavingCost, double fenceCost);

#endif  // INCLUDE_TASKS_H_
