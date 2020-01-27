#include <iostream>

#include "filter.h"

int main() {
  std::cout << "Each link consists of 2 integers. "
               "Enter them separated by space and press enter.\n";
  links::Filter filter;
  while (true) {
    links::Link link;
    std::cin >> link;
    bool inserted = filter.insert(link);
    if (inserted) {
      std::cout << "New " << link << "\n";
    } else {
      std::cout << link << " is already in:\n";
      auto chains = filter.getChains(link);
      for (auto& chain : chains) {
        std::cout << chain << ", ";
      }
      std::cout << "\n";
    }
  }
}
