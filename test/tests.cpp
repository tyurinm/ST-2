// Copyright 2025 tyurinm

#include <gtest/gtest.h>
#include <cstdint>
#include <cmath>
#include "tasks.h"

TEST(CircleTests, SetNegativeRadiusTest) {
  Circle c(-5.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
  EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTests, SetNegativeFerenceTest) {
  Circle c(5.0);
  c.setFerence(-10.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
  EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTests, SetNegativeAreaTest) {
  Circle c(5.0);
  c.setArea(-25.0);
  EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
}

TEST(CircleTests, SetPositiveRadiusTest) {
  Circle c(3.0);
  c.setRadius(4.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 4.0);
  EXPECT_NEAR(c.getFerence(), 2 * M_PI * 4.0, 1e-9);
  EXPECT_NEAR(c.getArea(), M_PI * 16.0, 1e-9);
}

TEST(CircleTests, ConstructorTest) {
  Circle c(2.5);
  EXPECT_DOUBLE_EQ(c.getRadius(), 2.5);
  EXPECT_NEAR(c.getFerence(), 2.0 * M_PI * 2.5, 1e-9);
  EXPECT_NEAR(c.getArea(), M_PI * 2.5 * 2.5, 1e-9);
}

TEST(CircleTests, SetRadiusTest) {
  Circle c(1.0);
  c.setRadius(4.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 4.0);
  EXPECT_NEAR(c.getFerence(), 8.0 * M_PI, 1e-9);
  EXPECT_NEAR(c.getArea(), 16.0 * M_PI, 1e-9);
}

TEST(CircleTests, SetFerenceTest) {
  Circle c(3.0);
  c.setFerence(10.0);
  EXPECT_NEAR(c.getFerence(), 10.0, 1e-9);
  EXPECT_NEAR(c.getRadius(), 10.0 / (2.0 * M_PI), 1e-9);
  EXPECT_NEAR(c.getArea(), M_PI * (10.0 / (2.0 * M_PI)) *
    (10.0 / (2.0 * M_PI)), 1e-9);
}

TEST(CircleTests, SetAreaTest) {
  Circle c(3.0);
  c.setArea(28.27);
  EXPECT_NEAR(c.getArea(), 28.27, 1e-9);
  EXPECT_NEAR(c.getRadius(), std::sqrt(28.27 / M_PI), 1e-9);
  EXPECT_NEAR(c.getFerence(), 2 * M_PI * std::sqrt(28.27 / M_PI), 1e-9);
}

TEST(CircleTests, ZeroRadiusTest) {
  Circle c(0.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
  EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTests, SetZeroRadiusTest) {
  Circle c(5.0);
  c.setRadius(0.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
  EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTests, LargeRadiusTest) {
  Circle c(1e6);
  EXPECT_DOUBLE_EQ(c.getRadius(), 1e6);
  EXPECT_NEAR(c.getFerence(), 2 * M_PI * 1e6, 1e-9);
  EXPECT_NEAR(c.getArea(), M_PI * 1e6 * 1e6, 1e-9);
}

TEST(CircleTests, SetLargeNegativeFerenceTest) {
  Circle c(1.0);
  c.setFerence(-1000000.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
  EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTests, SetLargeRadiusTest) {
  Circle c(1e5);
  c.setRadius(1e6);
  EXPECT_DOUBLE_EQ(c.getRadius(), 1e6);
  EXPECT_NEAR(c.getFerence(), 2 * M_PI * 1e6, 1e-9);
  EXPECT_NEAR(c.getArea(), M_PI * 1e6 * 1e6, 1e-9);
}

TEST(CircleTests, RadiusAfterLargeNegativeFerenceTest) {
  Circle c(5.0);
  c.setFerence(-100.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
  EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTests, SetNegativeAreaWithZeroAreaTest) {
  Circle c(3.0);
  c.setArea(-50.0);
  EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
}


TEST(TasksTests, CalculateRopeGapTest) {
  double additionalLength = 1.0;
  double gap = calculateRopeGap(additionalLength);
  double earthRadius = 6378.1 * 1000;
  EXPECT_NEAR(gap, 1.0 / (2 * M_PI), 1e-6);
}

TEST(TasksTests, CalculateRopeGapZeroTest) {
  double additionalLength = 0.0;
  double gap = calculateRopeGap(additionalLength);
  EXPECT_DOUBLE_EQ(gap, 0.0);
}

TEST(TasksTests, CalculateRopeGapLargeTest) {
  double additionalLength = 1000.0;
  double gap = calculateRopeGap(additionalLength);
  double earthRadius = 6378.1 * 1000;
  EXPECT_NEAR(gap, additionalLength / (2 * M_PI), 1e-6);
}

TEST(TasksTests, CalculatePoolCostsTest) {
  double poolRadius = 3.0;
  double pathWidth = 1.0;
  double pavingCost = 1000.0;
  double fenceCost = 2000.0;

  double totalCost = calculatePoolCosts(poolRadius, pathWidth,
    pavingCost, fenceCost);

  Circle pool(poolRadius);
  Circle full(poolRadius + pathWidth);

  double expectedPavingArea = full.getArea() - pool.getArea();
  double expectedFenceLength = full.getFerence();

  double expectedTotalCost = (expectedPavingArea * pavingCost) +
    (expectedFenceLength * fenceCost);

  EXPECT_NEAR(totalCost, expectedTotalCost, 1e-6);
}

TEST(TasksTests, CalculatePoolCostsZeroRadiusTest) {
  double poolRadius = 0.0;
  double pathWidth = 1.0;
  double pavingCost = 1000.0;
  double fenceCost = 2000.0;

  double totalCost = calculatePoolCosts(poolRadius, pathWidth,
    pavingCost, fenceCost);

  Circle pool(poolRadius);
  Circle full(poolRadius + pathWidth);

  double expectedPavingArea = full.getArea() - pool.getArea();
  double expectedFenceLength = full.getFerence();

  double expectedTotalCost = (expectedPavingArea * pavingCost) +
    (expectedFenceLength * fenceCost);

  EXPECT_NEAR(totalCost, expectedTotalCost, 1e-6);
}

TEST(TasksTests, CalculatePoolCostsLargeRadiusTest) {
  double poolRadius = 100.0;
  double pathWidth = 10.0;
  double pavingCost = 1000.0;
  double fenceCost = 2000.0;

  double totalCost = calculatePoolCosts(poolRadius, pathWidth,
    pavingCost, fenceCost);

  Circle pool(poolRadius);
  Circle full(poolRadius + pathWidth);

  double expectedPavingArea = full.getArea() - pool.getArea();
  double expectedFenceLength = full.getFerence();

  double expectedTotalCost = (expectedPavingArea * pavingCost) +
    (expectedFenceLength * fenceCost);

  EXPECT_NEAR(totalCost, expectedTotalCost, 1e-6);
}

TEST(TasksTests, CalculatePoolCostsNoPathTest) {
  double poolRadius = 3.0;
  double pathWidth = 0.0;
  double pavingCost = 1000.0;
  double fenceCost = 2000.0;

  double totalCost = calculatePoolCosts(poolRadius, pathWidth,
    pavingCost, fenceCost);

  Circle pool(poolRadius);
  Circle full(poolRadius + pathWidth);

  double expectedPavingArea = full.getArea() - pool.getArea();
  double expectedFenceLength = full.getFerence();

  double expectedTotalCost = (expectedPavingArea * pavingCost) +
    (expectedFenceLength * fenceCost);

  EXPECT_NEAR(totalCost, expectedTotalCost, 1e-6);
}

TEST(TasksTests, CalculatePoolCostsZeroPathWidthTest) {
  double poolRadius = 10.0;
  double pathWidth = 0.0;
  double pavingCost = 500.0;
  double fenceCost = 1500.0;

  double totalCost = calculatePoolCosts(poolRadius, pathWidth,
    pavingCost, fenceCost);

  Circle pool(poolRadius);
  Circle full(poolRadius + pathWidth);

  double expectedPavingArea = full.getArea() - pool.getArea();
  double expectedFenceLength = full.getFerence();

  double expectedTotalCost = (expectedPavingArea * pavingCost) +
    (expectedFenceLength * fenceCost);

  EXPECT_NEAR(totalCost, expectedTotalCost, 1e-6);
}

TEST(TasksTests, CalculatePoolCostsLargePathWidthTest) {
  double poolRadius = 3.0;
  double pathWidth = 10.0;
  double pavingCost = 1000.0;
  double fenceCost = 2000.0;

  double totalCost = calculatePoolCosts(poolRadius, pathWidth,
    pavingCost, fenceCost);

  Circle pool(poolRadius);
  Circle full(poolRadius + pathWidth);

  double expectedPavingArea = full.getArea() - pool.getArea();
  double expectedFenceLength = full.getFerence();

  double expectedTotalCost = (expectedPavingArea * pavingCost) +
    (expectedFenceLength * fenceCost);

  EXPECT_NEAR(totalCost, expectedTotalCost, 1e-6);
}
