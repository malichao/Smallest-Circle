#ifndef COMMON_H
#define COMMON_H

#include <chrono>

namespace smallest_circle {

static const double Epsilon = 1e-6;

struct Point {

  // Return Euclidean distance using std::hypot
  const double Distance(const Point& other) const;

  // Return squared distance, faster than Distance()
  const double DistanceSquare(const Point& other) const;

  // Return the length of the vector
  const double Length() const;

  // Return the squared length of the vector
  const double LengthSquare() const;

  // Cross product(z component)
  const double Cross(const Point& other) const;

  // Dot product
  const double Dot(const Point& other) const;

  Point& operator+=(const Point& other);

  Point& operator-=(const Point& other);

  const Point operator+(const Point& other) const;

  const Point operator-(const Point& other) const;

  const Point operator*(const double scale) const;

  const bool operator==(const Point& other) const;

  double x, y;
};

struct Circle {
  // Build a default circle
  Circle();

  // Build a circle with given center and radius
  Circle(const Point& p, const double r);

  // Build a circle with 2 points on its circumference
  Circle(const Point& p1, const Point& p2);

  // Build a circle with 3 points on its circumference, reference:
  // https://en.wikipedia.org/wiki/Circumscribed_circle
  // section: Cartesian coordinates from cross- and dot-products
  // WARN: If all 3 points are colinear, the constructor will break
  Circle(const Point& p1, const Point& p2, const Point& p3);

  // Check if the circle encloses a point
  bool Encloses(const Point& p);

  Point center;
  double radius = 0;
};

const double Now();
}

#endif  // COMMON_H
