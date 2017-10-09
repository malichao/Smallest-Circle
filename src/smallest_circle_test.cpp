#include <SmallestCircle/smallest_circle.h>
#include <string>
#include <iostream>

using namespace std;
// Ad-hoc test framework, TODO: Use GTest
#define AssertEqual(val, target)                                        \
  {                                                                     \
    int line = __LINE__;                                                \
    if (val != target) {                                                \
      throw "Assertion '" + to_string(val) + "==" + to_string(target) + \
          "' at line " + to_string(line) + " failed.\n";                \
    }                                                                   \
  }

int main(int argc, char** argv) {
  try {
    AssertEqual(1, 1);
    AssertEqual(1.0, 1.1);
    AssertEqual(true, false);
  }
  catch (std::string& e) {
    cout << e;
  }
  catch (...) {
    cout << "Unexpected exception\n";
  }
}
