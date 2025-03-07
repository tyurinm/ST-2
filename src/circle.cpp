// Copyright 2025 tyurinm
#include <cstdint>
#include <cmath>
#include "circle.h"

Circle::Circle(double r) : radius(r) {
  if (r < 0) {
    radius = 0;
  }
  updateFromRadius();
}

void Circle::updateFromRadius() {
  if (radius < 0) {
    radius = 0;
  }
  ference = 2 * M_PI * radius;
  area = M_PI * radius * radius;
}

void Circle::updateFromFerence() {
  if (ference < 0) {
    ference = 0;
  }
  radius = ference / (2 * M_PI);
  area = M_PI * radius * radius;
}

void Circle::updateFromArea() {
  if (area < 0) {
    area = 0;
  }
  radius = std::sqrt(area / M_PI);
  ference = 2 * M_PI * radius;
}

void Circle::setRadius(double r) {
  if (r < 0) {
    radius = 0;
  } else {
    radius = r;
  }
  updateFromRadius();
}

void Circle::setFerence(double f) {
  if (f < 0) {
    ference = 0;
  } else {
    ference = f;
  }
  updateFromFerence();
}

void Circle::setArea(double a) {
  if (a < 0) {
    area = 0;
  } else {
    area = a;
  }
  updateFromArea();
}

double Circle::getRadius() const { return radius; }

double Circle::getFerence() const { return ference; }

double Circle::getArea() const { return area; }
