#include <gtest/gtest.h>

#include "graph.h"

using namespace graphs;

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

void printConnectionPaths(int from, const std::vector<ConnectionPath>& paths) {
  for (auto& path : paths) {
    std::cout << from << ">" << path << ", distance = " << path.distance()
              << "\n";
  }
}

void checkConnectionPaths(const Graph& graph, int from, int to,
                          int expected_size) {
  std::vector<ConnectionPath> paths = graph[from]->connectionPaths(to);
  printConnectionPaths(from, paths);
  std::cout << "\n";
  ASSERT_EQ(paths.size(), expected_size);
}

TEST(tmp, test1) {
  Graph graph;

  for (int i = 0; i != 10; ++i) {
    graph.insertNode(std::make_shared<Node>(graph));
  }

  graph.addConnection(3, 4, 1);
  graph.addConnection(4, 9, 1);
  graph.addConnection(8, 0, 1);
  graph.addConnection(2, 3, 1);
  graph.addConnection(5, 6, 1);
  graph.addConnection(2, 9, 1);
  graph.addConnection(5, 9, 1);
  graph.addConnection(7, 3, 1);
  graph.addConnection(4, 8, 1);
  graph.addConnection(5, 6, 1);
  graph.addConnection(0, 2, 1);
  graph.addConnection(6, 1, 1);

  ASSERT_TRUE(graph[0]->isConnectedDirectly(8));
  ASSERT_TRUE(graph[0]->isConnectedDirectly(2));
  ASSERT_TRUE(graph[1]->isConnectedDirectly(6));
  ASSERT_TRUE(graph[2]->isConnectedDirectly(3));
  ASSERT_TRUE(graph[2]->isConnectedDirectly(9));
  ASSERT_TRUE(graph[2]->isConnectedDirectly(0));
  ASSERT_TRUE(graph[3]->isConnectedDirectly(2));
  ASSERT_TRUE(graph[3]->isConnectedDirectly(4));
  ASSERT_TRUE(graph[3]->isConnectedDirectly(7));
  ASSERT_TRUE(graph[4]->isConnectedDirectly(3));
  ASSERT_TRUE(graph[4]->isConnectedDirectly(8));
  ASSERT_TRUE(graph[4]->isConnectedDirectly(9));
  ASSERT_TRUE(graph[5]->isConnectedDirectly(9));
  ASSERT_TRUE(graph[5]->isConnectedDirectly(6));
  ASSERT_TRUE(graph[6]->isConnectedDirectly(5));
  ASSERT_TRUE(graph[6]->isConnectedDirectly(1));
  ASSERT_TRUE(graph[7]->isConnectedDirectly(3));
  ASSERT_TRUE(graph[8]->isConnectedDirectly(4));
  ASSERT_TRUE(graph[8]->isConnectedDirectly(0));
  ASSERT_TRUE(graph[9]->isConnectedDirectly(4));
  ASSERT_TRUE(graph[9]->isConnectedDirectly(5));

  checkConnectionPaths(graph, 1, 6, 1);
  checkConnectionPaths(graph, 5, 6, 2);
  checkConnectionPaths(graph, 7, 2, 3);
}
