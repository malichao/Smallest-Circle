#include "SmallestCircle/smallest_circle.h"
#include <algorithm>
namespace smallest_circle {
using namespace std;
// TODO: test the following specail cases:
//      1 point: return itself and 0 radius
//      2 points: return the middle of 2 points as center and half of the length
//                as radius
//      3 points: triangles, return should be circumcircle
//      3 points on a line: similar to 2 points
Circle SmallestCircle::FindSmallestCircle(const vector<Point> &points) {
  // Section 4.4, random permutation makes the algorithm an average running time
  // O(n)
  vector<Point> points_(points);
  random_shuffle(points_.begin(), points_.end());
  Circle min_circle;
  for (int i = 2; i < points_.size(); i++) {
    if (!min_circle.Encloses(points_[i])) {
      min_circle = FindSmallestCircle(points_, 0, i - 1, points_[i]);
    }
  }
  return min_circle;
}

Circle SmallestCircle::FindSmallestCircle(const std::vector<Point> &points,
                                          const size_t end, const Point &q) {
  Circle min_circle(q, points.front());
  for (int i = 1; i < end; i++) {
    if (!min_circle.Encloses(points[i])) {
      min_circle = FindSmallestCircle(points, i - 1, points[i], q);
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
      min_circle = Circle(q1, q2, points[i]);
    }
  }
  return min_circle;
}
}
