#ifndef FILTER_EXEC_H
#define FILTER_EXEC_H

#include <gtest/gtest.h>

#include <tuple>

#include "filter.h"

using namespace links;

TEST(filter, exec1) {
  std::vector<std::tuple<Link, bool, size_t>> links{
      {Link{3, 4}, true, 1},  {Link{4, 9}, true, 1}, {Link{8, 0}, true, 2},
      {Link{2, 3}, true, 2},  {Link{5, 6}, true, 3}, {Link{2, 9}, false, 3},
      {Link{5, 9}, true, 2},  {Link{7, 4}, true, 3}, {Link{4, 8}, true, 2},
      {Link{5, 6}, false, 2}, {Link{0, 2}, true, 1}, {Link{6, 1}, true, 1}};

  Filter filter;

  int counter = 0;
  for (auto& [link, inserted, size] : links) {
    ASSERT_EQ(filter.insert(link), inserted);
    std::cout << counter++ << ". Inserted " << link << ", new size is "
              << filter.getChains().size() << std::endl;
    ASSERT_EQ(filter.getChains().size(), size);
  }
}

#endif  // FILTER_EXEC_H
