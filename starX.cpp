// starX.cpp

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

void assertEquals(string expected, string actual, string message);
string starX(int width);
void runTests(void);

std::string starX(int width)
{
    std::string result = "";

    if ((width % 2 == 0) || (width < 3)) {
        return ""; // only odd widths >= 3 allowed
    }

    int middle_star = width / 2;   // zero-based index for the middle row
    string outer_spaces = "";
    int spaces = width - 2;

    for (int i = 0; i < middle_star; i++) {   // stop before the middle
        std::string inner_spaces(spaces, ' ');
        result += outer_spaces + "*" + inner_spaces + "*" + outer_spaces + "\n";

        outer_spaces += " ";
        spaces -= 2;
    }

    // Add the middle row (just one star in the center)
    result += outer_spaces + "*" + outer_spaces + "\n";
    string inner_spaces = " ";
    
    for (int i = middle_star; i < width - 1; i++){
      std::string outer_spaces(middle_star-1, ' ');
      result += outer_spaces + "*" + inner_spaces + "*" + outer_spaces + "\n";   
      middle_star -= 1;
      inner_spaces += "  ";
    }
    return result;
}

// Test-Driven Development;
// check expected results against actual

void runTests(void)
{

  // The following line works because in C and C++ when string literals
  // are separated only by whitespace (space, tab, newline), they
  // automatically get concatenated into a single string literal

  string starX3Expected =
      "* *\n"
      " * \n"
      "* *\n";

  assertEquals(starX3Expected, starX(3), "starX(3)");

  string starX5Expected =
      "*   *\n"
      " * * \n"
      "  *  \n"
      " * * \n"
      "*   *\n";

  assertEquals(starX5Expected, starX(5), "starX(5)");

  assertEquals("", starX(0), "starX(0)");
  assertEquals("", starX(2), "starX(2)");
  assertEquals("", starX(4), "starX(4)");
}

void assertEquals(string expected, string actual, string message = "")
{
  if (expected == actual)
  {
    cout << "PASSED: " << message << endl;
    ;
  }
  else
  {
    cout << "   FAILED: " << message << endl
         << "   Expected:[\n"
         << expected << "] actual = [\n"
         << actual << "]\n"
         << endl;
  }
}

// Main function

int main(int argc, char *argv[])
{
  int width = stoi(argv[1]);
  cout << starX(width);
  if (width == -1){
    runTests();
    exit(0);
  }
  return 0;
}

