#include "SmallestCircle/smallest_circle.h"
#include <algorithm>
#include <cassert>

namespace smallest_circle {
using namespace std;
// TODO: test the following specail cases:
//      1 point: return itself and 0 radius
//      2 points: return the middle of 2 points as center and half of the length
//                as radius
//      3 points: triangles, return should be circumcircle
//      3 points on a line: similar to 2 points
Circle SmallestCircle::FindSmallestCircle(const vector<Point> &points) {
  // Handle special cases
  if (points.empty()) return {};
  if (points.size() == 1) return Circle(points.back(), 0);
  if (points.size() == 2) return Circle(points.front(), points.back());

  // Section 4.4, random permutation makes the algorithm an average running time
  // of O(n)
  vector<Point> points_(points);
  random_shuffle(points_.begin(), points_.end());

  Circle min_circle(points_[0], points_[1]);
  for (int i = 2; i < points_.size(); i++) {
    if (!min_circle.Encloses(points_[i])) {
      min_circle = FindSmallestCircle(points_, i, points_[i]);
    }
  }
  return min_circle;
}

Circle SmallestCircle::FindSmallestCircle(const std::vector<Point> &points,
                                          const size_t end, const Point &q) {
  Circle min_circle(q, points[end]);
  for (int i = 0; i < end; i++) {
    if (!min_circle.Encloses(points[i])) {
      min_circle = FindSmallestCircle(points, i, points[i], q);
    }
  }
  return min_circle;
}

Circle SmallestCircle::FindSmallestCircle(const std::vector<Point> &points,
                                          const size_t end, const Point &q1,
                                          const Point &q2) {
  Circle min_circle(q1, q2);
  for (int i = 0; i < end; i++) {
    if (!min_circle.Encloses(points[i])) {
      if (q1 == points[i] || q2 == points[i]) continue;
      min_circle = Circle(q1, q2, points[i]);
    }
  }
  return min_circle;
}
}
