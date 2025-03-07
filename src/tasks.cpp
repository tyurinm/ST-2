// Copyright 2025 tyurinm
#include "tasks.h"

double calculateRopeGap(double additionalLength) {
  const double earthRadius = 6378.1 * 1000;
  Circle earth(earthRadius);
  double newFerence = earth.getFerence() + additionalLength;
  earth.setFerence(newFerence);

  return earth.getRadius() - earthRadius;
}

double calculatePoolCosts(double poolRadius, double pathWidth,
  double pavingCost, double fenceCost) {
  Circle pool(poolRadius);
  Circle full(poolRadius + pathWidth);

  double pavingArea = full.getArea() - pool.getArea();
  double fenceLength = full.getFerence();

  double totalCost = (pavingArea * pavingCost) + (fenceLength * fenceCost);
  return totalCost;
}
