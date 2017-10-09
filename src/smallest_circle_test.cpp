#include <SmallestCircle/smallest_circle.h>
#include <string>
#include <iostream>
#include <SmallestCircle/common.h>
#include <cmath>

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

void TestFindSmallestCircle1() {
  vector<Point> test_points = {{-3, 4}, {4, 5}, {1, -4}};
  auto result = SmallestCircle::FindSmallestCircle(test_points);
  AssertDoubleEqual(result.center.x, 1);
  AssertDoubleEqual(result.center.y, 1);
  AssertDoubleEqual(result.radius, 5);
}

int main(int argc, char** argv) {
  try {
    TestCircle3Points();
    TestFindSmallestCircle1();
    cout << "Passed all test cases!\n";
  }
  catch (std::string& e) {
    cout << e;
  }
  catch (...) {
    cout << "Unexpected exception\n";
  }
}
