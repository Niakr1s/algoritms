#include <gtest/gtest.h>

#include "chain_glue.h"
#include "chain_insert.h"
#include "chain_linked.h"
#include "filter_exec.h"

using namespace links;

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
