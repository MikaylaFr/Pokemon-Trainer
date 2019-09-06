#include <vector>
#include <utility>
#include <iostream>

#include "menu.hpp"


int TestRandomInt(const Menu &menu) {
  // Test Cases
  std::vector<std::pair<int, int>> input({{1, 3}, {1, 100}, {-1, 1000}});

  // This test is just an example.
  for (const auto it : input) {
    int rand_int = menu.randomInt(it.first, it.second);
    if (rand_int < it.first || rand_int > it.second) {
      std::cout << "TestRandomInt failed on input: "
                << it.first << " " << it.second << std::endl;
      return 1;
    }
  }
  // Checks for seg fault in randomInt
  menu.randomInt(10, -1);
  return 0;
}

int main(int argc, char** argv) {
  const Menu menu;
  return TestRandomInt(menu);
}

