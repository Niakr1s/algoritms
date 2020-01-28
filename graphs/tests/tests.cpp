#include <gtest/gtest.h>

#include "graph.h"

using namespace graphs;

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

namespace tests {

void printConnectionPaths(int from, const std::vector<ConnectionPath>& paths) {
  for (auto& path : paths) {
    std::cout << from << ">" << path << ", distance = " << path.distance()
              << "\n";
  }
}

void checkConnectionPaths(const Graph& graph, int from, int to,
                          int expected_size) {
  std::cout << "all connections between " << from << " and " << to << ":\n";
  std::vector<ConnectionPath> paths = graph[from]->connectionPaths(to);
  printConnectionPaths(from, paths);
  std::cout << "\n";
  ASSERT_EQ(paths.size(), expected_size);
}

void addConnection(Graph& graph, int id1, int id2, double distance) {
  graph.addConnection(id1, id2, distance);
  std::cout << "added connection between " << id1 << " and " << id2
            << " with distance " << distance << "\n";
}

class MockNode : public Node {
 public:
  using Node::Node;

  std::string info() const override { return ""; }
};

TEST(tmp, test1) {
  Graph graph;

  for (int i = 0; i != 10; ++i) {
    graph.insertNode(std::make_shared<MockNode>(graph));
  }

  addConnection(graph, 3, 4, 1);
  addConnection(graph, 4, 9, 1);
  addConnection(graph, 8, 0, 1);
  addConnection(graph, 2, 3, 1);
  addConnection(graph, 5, 6, 1);
  addConnection(graph, 2, 9, 1);
  addConnection(graph, 5, 9, 1);
  addConnection(graph, 7, 3, 1);
  addConnection(graph, 4, 8, 1);
  addConnection(graph, 5, 6, 1);
  addConnection(graph, 0, 2, 1);
  addConnection(graph, 6, 1, 1);
  std::cout << std::endl;

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

}  // namespace tests
