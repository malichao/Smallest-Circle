#include <SmallestCircle/common.h>
#include <cmath>

namespace smallest_circle {
using namespace std;
const double Point::Distance(const Point &other) const {
  return std::hypot(other.x - this->x, other.y - this->y);
}

const double Point::Length() const { return sqrt(Dot(*this)); }

Point &Point::operator+=(const Point &other) {
  this->x += other.x;
  this->y += other.y;
  return *this;
}

Point &Point::operator-=(const Point &other) {
  this->x -= other.x;
  this->y -= other.y;
  return *this;
}

const Point smallest_circle::Point::operator+(const Point &other) const {
  Point temp{this->x, this->y};
  temp += other;
  return temp;
}

const Point smallest_circle::Point::operator-(const Point &other) const {
  Point temp{this->x, this->y};
  temp -= other;
  return temp;
}

const Point Point::operator*(const double scale) const {
  Point temp{this->x, this->y};
  temp.x *= scale;
  temp.y *= scale;
  return temp;
}

const double Point::Cross(const Point &other) const {
  return this->x * other.y - this->y * other.x;
}

const double Point::Dot(const Point &other) const {
  return this->x * other.x + this->y * other.y;
}

Circle::Circle() : center{0, 0}, radius(0) {}

Circle::Circle(const Point &p, const double r) : center(p), radius(r) {}

Circle::Circle(const Point &p1, const Point &p2) {
  this->center.x = (p1.x + p2.x) / 2;
  this->center.y = (p1.y + p2.y) / 2;
  this->radius = p1.Distance(p2) / 2;
}

Circle::Circle(const Point &p1, const Point &p2, const Point &p3) {
  const Point p12 = p1 - p2;
  const Point p13 = p1 - p3;
  const Point p21 = p2 - p1;
  const Point p23 = p2 - p3;
  const Point p31 = p3 - p1;
  const Point p32 = p3 - p2;
  double t1 = p12.Cross(p23);
  double t2 = p12.Length();
  double t3 = p23.Length();
  double t4 = p31.Length();
  this->radius =
      p12.Length() * p23.Length() * p31.Length() / (fabs(p12.Cross(p23)) * 2);

  double temp = pow(p12.Cross(p23), 2) * 2;
  double alpha = pow(p23.Length(), 2) * p12.Dot(p13) / temp;
  double beta = pow(p13.Length(), 2) * p21.Dot(p23) / temp;
  double gamma = pow(p12.Length(), 2) * p31.Dot(p32) / temp;

  auto pp1 = p1 * alpha;
  auto pp2 = p2 * beta;
  auto pp3 = p3 * gamma;
  this->center = p1 * alpha + p2 * beta + p3 * gamma;
}

bool Circle::Encloses(const Point &p) {
  return this->radius > 0 && this->center.Distance(p) <= this->radius;
}
}
