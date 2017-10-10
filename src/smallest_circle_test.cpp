#include <SmallestCircle/smallest_circle.h>
#include <string>
#include <iostream>
#include <SmallestCircle/common.h>
#include <cmath>
#include <cstdlib>
#include <fstream>

using namespace std;
using namespace smallest_circle;

// Ad-hoc test framework, TODO: Use GTest
#define AssertEqual(val, target)                                        \
  {                                                                     \
    int line = __LINE__;                                                \
    if (val != target) {                                                \
      throw "Assertion '" + to_string(val) + "==" + to_string(target) + \
          "' at line " + to_string(line) + " failed.\n";                \
    }                                                                   \
  }

#define AssertDoubleEqual(val, target)                                  \
  {                                                                     \
    int line = __LINE__;                                                \
    if (fabs(val - target) > Epsilon) {                                 \
      throw "Assertion '" + to_string(val) + "==" + to_string(target) + \
          "' at line " + to_string(line) + " failed.\n";                \
    }                                                                   \
  }

void TestCircle3Points() {
  Circle test1(Point{-3, 4}, Point{4, 5}, Point{1, -4});
  AssertDoubleEqual(test1.center.x, 1);
  AssertDoubleEqual(test1.center.y, 1);
  AssertDoubleEqual(test1.radius, 5);
}

// Test 3 points that form a triangle
void TestFindSmallestCircle1() {
  vector<Point> test_points = {{-3, 4}, {4, 5}, {1, -4}};
  auto result = SmallestCircle::FindSmallestCircle(test_points);
  AssertDoubleEqual(result.center.x, 1);
  AssertDoubleEqual(result.center.y, 1);
  AssertDoubleEqual(result.radius, 5);
}

// Test 3 points that form a line
void TestFindSmallestCircle2() {
  // Horizontal
  vector<Point> test_points = {{-1, 0}, {0, 0}, {1, 0}};
  auto result = SmallestCircle::FindSmallestCircle(test_points);
  AssertDoubleEqual(result.center.x, 0);
  AssertDoubleEqual(result.center.y, 0);
  AssertDoubleEqual(result.radius, 1);

  // Vertical
  test_points = {{0, -1}, {0, 0}, {0, 1}};
  result = SmallestCircle::FindSmallestCircle(test_points);
  AssertDoubleEqual(result.center.x, 0);
  AssertDoubleEqual(result.center.y, 0);
  AssertDoubleEqual(result.radius, 1);

  // 45 degree
  test_points = {{-1, -1}, {0, 0}, {1, 1}};
  result = SmallestCircle::FindSmallestCircle(test_points);
  AssertDoubleEqual(result.center.x, 0);
  AssertDoubleEqual(result.center.y, 0);
  AssertDoubleEqual(result.radius, 1.414213562);
}

// Test 2 points
void TestFindSmallestCircle3() {
  // Horizontal
  vector<Point> test_points = {{-1, 0}, {1, 0}};
  auto result = SmallestCircle::FindSmallestCircle(test_points);
  AssertDoubleEqual(result.center.x, 0);
  AssertDoubleEqual(result.center.y, 0);
  AssertDoubleEqual(result.radius, 1);

  // 45 degree
  test_points = {{1, 1}, {-1, -1}};
  result = SmallestCircle::FindSmallestCircle(test_points);
  AssertDoubleEqual(result.center.x, 0);
  AssertDoubleEqual(result.center.y, 0);
  AssertDoubleEqual(result.radius, 1.414213562);
}

// Test 1 point
void TestFindSmallestCircle4() {
  vector<Point> test_points = {{1, 1}};
  auto result = SmallestCircle::FindSmallestCircle(test_points);
  AssertDoubleEqual(result.center.x, 1);
  AssertDoubleEqual(result.center.y, 1);
  AssertDoubleEqual(result.radius, 0);

  test_points = {{1000, -1000}};
  result = SmallestCircle::FindSmallestCircle(test_points);
  AssertDoubleEqual(result.center.x, 1000);
  AssertDoubleEqual(result.center.y, -1000);
  AssertDoubleEqual(result.radius, 0);
}

void TestFindSmallestCircle5(const int range, const int test_nums) {
  auto RangeRand = [&]() { return (rand() % (range * 2) - range) * 1.0; };

  srand(0);  // Fix value for debugging
  vector<Point> ground_truth_points = {{RangeRand(), RangeRand()},
                                       {RangeRand(), RangeRand()},
                                       {RangeRand(), RangeRand()}};
  Circle ground_truth_circle = Circle(
      ground_truth_points[0], ground_truth_points[1], ground_truth_points[2]);

  auto GeneratePointWithinCircle = [](const Circle& circle) {
    double theta = rand() % 360 / 180.0 * M_PI;
    double radius = rand() % (static_cast<int>(circle.radius) * 100) / 100.0;
    return Point{circle.center.x + radius * cos(theta),
                 circle.center.y + radius * sin(theta)};
  };

  vector<Point> test_points(test_nums);
  for (auto& p : test_points)
    p = GeneratePointWithinCircle(ground_truth_circle);

  auto result = SmallestCircle::FindSmallestCircle(test_points);

  ofstream out("ground_truth_points.data");
  for (auto& p : ground_truth_points) {
    out << p.x << "," << p.y << "\n";
  }
  out.close();

  out.open("ground_truth_circle.data");
  out << ground_truth_circle.center.x << "," << ground_truth_circle.center.y
      << "," << ground_truth_circle.radius << "\n";
  out.close();

  out.open("test_points.data");
  for (auto& p : test_points) {
    out << p.x << "," << p.y << "\n";
  }
  out.close();

  out.open("test_result.data");
  out << result.center.x << "," << result.center.y << "," << result.radius
      << "\n";
  out.close();

  AssertDoubleEqual(result.center.x, ground_truth_circle.center.x);
  AssertDoubleEqual(result.center.y, ground_truth_circle.center.y);
  AssertDoubleEqual(result.radius, ground_truth_circle.radius);
}

int main(int argc, char** argv) {
  try {
    TestCircle3Points();
    //    TestFindSmallestCircle1();
    //    TestFindSmallestCircle2();
    //    TestFindSmallestCircle3();
    //    TestFindSmallestCircle4();
    TestFindSmallestCircle5(100, 10);
    cout << "Passed all test cases!\n";
  }
  catch (std::string& e) {
    cout << e;
  }
  catch (...) {
    cout << "Unexpected exception\n";
  }
}
