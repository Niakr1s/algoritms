#ifndef CHAIN_GLUE_H
#define CHAIN_GLUE_H

#include <gtest/gtest.h>

#include "chain.h"

using namespace links;

TEST(chain, gluable_with) {
  Chain chain1;
  chain1.insert(Link{1, 2});
  chain1.insert(Link{2, 5});
  chain1.insert(Link{5, 6});
  Chain chain2;
  chain2.insert(Link{5, 6});
  chain2.insert(Link{6, 8});

  ASSERT_TRUE(chain1.gluableWith(chain2));
  ASSERT_TRUE(chain2.gluableWith(chain1));
}

TEST(chain, glue_with) {
  Chain chain1;
  chain1.insert(Link{1, 2});
  chain1.insert(Link{2, 5});
  chain1.insert(Link{5, 6});
  Chain chain2;
  chain2.insert(Link{5, 6});
  chain2.insert(Link{6, 8});

  Chain chain12 = chain1.glueWith(chain2);
  Chain chain21 = chain2.glueWith(chain1);

  ASSERT_EQ(chain12.links().size(), 4);
  ASSERT_EQ(chain21.links().size(), 4);
}

TEST(chain, not_gluable_with) {
  Chain chain1;
  chain1.insert(Link{1, 2});
  chain1.insert(Link{2, 5});
  Chain chain2;
  chain2.insert(Link{5, 6});
  chain2.insert(Link{6, 8});

  ASSERT_FALSE(chain1.gluableWith(chain2));
  ASSERT_FALSE(chain2.gluableWith(chain1));
}

TEST(chain, reversed) {
  Chain chain1;
  chain1.insert(Link{1, 2});
  chain1.insert(Link{2, 5});
  chain1 = chain1.reversed();

  ASSERT_EQ(chain1.links().front(), Link(5, 2));
  ASSERT_EQ(chain1.links().back(), Link(2, 1));
}

#endif  // CHAIN_GLUE_H
