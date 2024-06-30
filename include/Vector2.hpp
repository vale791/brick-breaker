#pragma once
#include <iostream>

struct Vector2 {
  Vector2()
    :x(0.0d), y(0.0d)
  {}

  Vector2(double X, double Y)
    :x(X), y(Y)
  {}

  void print() {
    std::cout << x << ", " << y << '\n';
  }

  double x, y;
};
