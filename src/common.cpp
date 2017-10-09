#include <SmallestCircle/common.h>
#include <cmath>

namespace smallest_circle {
using namespace std;

const double Point::Distance(const Point &other) const {
  return std::hypot(other.x - this->x, other.y - this->y);
}

Circle::Circle() : center{0, 0}, radius(0) {}

Circle::Circle(const Point &p, const double r) : center(p), radius(r) {}

Circle::Circle(const Point &p1, const Point &p2) {
  this->center.x = (p1.x + p2.x) / 2;
  this->center.y = (p1.y + p2.y) / 2;
  this->radius = p1.Distance(p2) / 2;
}

Circle::Circle(const Point &p1, const Point &p2, const Point &p3) {}

bool Circle::Encloses(const Point &p) {
  return this->radius > 0 && this->center.Distance(p) <= this->radius;
}
}
