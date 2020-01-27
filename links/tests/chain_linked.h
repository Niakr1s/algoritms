#ifndef CHAIN_LINKED_H
#define CHAIN_LINKED_H

#include <gtest/gtest.h>

#include "chain.h"
#include "link.h"

using namespace links;

TEST(chain, isLinked_true1) {
  Link link1{1, 2};
  Link link2{2, 5};
  Chain chain;
  chain.insert(link1);
  chain.insert(link2);
  Link link3{1, 5};
  ASSERT_TRUE(chain.isLinked(link1));
  ASSERT_TRUE(chain.isLinked(link1.reversed()));
  ASSERT_TRUE(chain.isLinked(link2));
  ASSERT_TRUE(chain.isLinked(link2.reversed()));
  ASSERT_TRUE(chain.isLinked(link3));
  ASSERT_TRUE(chain.isLinked(link3.reversed()));
}

TEST(chain, isLinked_false1) {
  Link link1{1, 2};
  Link link2{2, 5};
  Chain chain;
  chain.insert(link1);
  chain.insert(link2);
  Link link3{1, 7};
  ASSERT_FALSE(chain.isLinked(link3));
  ASSERT_FALSE(chain.isLinked(link3.reversed()));
}

#endif  // CHAIN_LINKED_H
