#ifndef CHAIN_INSERT_H
#define CHAIN_INSERT_H

#include <gtest/gtest.h>

#include "chain.h"
#include "link.h"

using namespace links;

TEST(chain, insert_into_empty) {
  Chain chain;
  Link link1{1, 2};
  ASSERT_TRUE(chain.insert(link1));
  ASSERT_EQ(chain.links().size(), 1);
  ASSERT_EQ(chain.links()[0], link1);
}

TEST(chain, insert_equal) {
  Chain chain;
  Link link1{1, 1};
  ASSERT_FALSE(chain.insert(link1));
  ASSERT_EQ(chain.links().size(), 0);
}

TEST(chain, insert_adjusted1) {
  Chain chain;
  Link link1{1, 2};
  Link link2{2, 3};
  ASSERT_TRUE(chain.insert(link1));
  ASSERT_TRUE(chain.insert(link2));
  ASSERT_EQ(chain.links().size(), 2);
  ASSERT_EQ(chain.links()[0], link1);
  ASSERT_EQ(chain.links()[1], link2);
}

TEST(chain, insert_adjusted2) {
  Chain chain;
  Link link1{1, 2};
  Link link2{1, 5};
  ASSERT_TRUE(chain.insert(link1));
  ASSERT_TRUE(chain.insert(link2));
  ASSERT_EQ(chain.links().size(), 2);
  ASSERT_EQ(chain.links()[1], link1);
  ASSERT_EQ(chain.links()[0], link2.reversed());
}

TEST(chain, insert_non_adjusted1) {
  Chain chain;
  Link link1{1, 2};
  Link link2{3, 5};
  ASSERT_TRUE(chain.insert(link1));
  ASSERT_FALSE(chain.insert(link2));
  ASSERT_EQ(chain.links().size(), 1);
}

TEST(chain, insert_existing1) {
  Chain chain;
  Link link1{1, 2};
  ASSERT_TRUE(chain.insert(link1));
  ASSERT_FALSE(chain.insert(link1));
  ASSERT_FALSE(chain.insert(link1.reversed()));
  ASSERT_EQ(chain.links().size(), 1);
}

TEST(chain, insert_existing2) {
  Chain chain;
  Link link1{1, 2};
  Link link2{3, 2};
  ASSERT_TRUE(chain.insert(link1));
  ASSERT_TRUE(chain.insert(link2));
  Link link3{3, 1};
  ASSERT_FALSE(chain.insert(link3));
  ASSERT_FALSE(chain.insert(link3.reversed()));
}

TEST(chain, insert_loop1) {
  Chain chain;
  Link link1{1, 2};
  Link link2{3, 2};
  Link link3{3, 1};

  ASSERT_TRUE(chain.insert(link1));
  ASSERT_TRUE(chain.insert(link2));
  ASSERT_FALSE(chain.insert(link3));
  ASSERT_FALSE(chain.insert(link3.reversed()));
}

#endif  // CHAIN_INSERT_H
