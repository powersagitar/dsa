#include <dsa/graph.h>
#include <gtest/gtest.h>

#include <vector>

TEST(Graph, EmptyGraph) {
  dsa::UndirectedGraph<int> graph;
  EXPECT_EQ(graph.Size(), 0);

  std::vector<int> expected_vertices;
  std::vector<std::vector<bool>> expected_adj_matrix;

  auto vertices = graph.vertices();
  auto adj_matrix = graph.adj_matrix();

  EXPECT_EQ(vertices, expected_vertices);
  EXPECT_EQ(adj_matrix, expected_adj_matrix);
}

TEST(Graph, WithInitializer1) {
  dsa::UndirectedGraph<int> graph({1, 2, 3});
  EXPECT_EQ(graph.Size(), 3);

  std::vector<int> expected_vertices{1, 2, 3};
  std::vector<std::vector<bool>> expected_adj_matrix{
      {false, false, false},
      {false, false, false},
      {false, false, false},
  };

  auto vertices = graph.vertices();
  auto adj_matrix = graph.adj_matrix();

  EXPECT_EQ(vertices, expected_vertices);
  EXPECT_EQ(adj_matrix, expected_adj_matrix);

  graph.AddEdge(0, 1);
  graph.AddEdge(1, 2);

  vertices = graph.vertices();
  adj_matrix = graph.adj_matrix();

  expected_adj_matrix[0][1] = true;
  expected_adj_matrix[1][0] = true;
  expected_adj_matrix[1][2] = true;
  expected_adj_matrix[2][1] = true;

  EXPECT_EQ(vertices, expected_vertices);
  EXPECT_EQ(adj_matrix, expected_adj_matrix);

  graph.RemoveEdge(1, 0);
  graph.RemoveEdge(2, 1);

  vertices = graph.vertices();
  adj_matrix = graph.adj_matrix();

  expected_adj_matrix[0][1] = false;
  expected_adj_matrix[1][0] = false;
  expected_adj_matrix[1][2] = false;
  expected_adj_matrix[2][1] = false;

  EXPECT_EQ(vertices, expected_vertices);
  EXPECT_EQ(adj_matrix, expected_adj_matrix);
}

TEST(Graph, WithInitializer2) {
  // NOLINTNEXTLINE(readability-magic-numbers)
  dsa::UndirectedGraph<int> graph{1, 2, 3, 4, 5};
  EXPECT_EQ(graph.Size(), 5);

  // NOLINTNEXTLINE(readability-magic-numbers)
  std::vector<int> expected_vertices{1, 2, 3, 4, 5};
  std::vector<std::vector<bool>> expected_adj_matrix{
      {false, false, false, false, false}, {false, false, false, false, false},
      {false, false, false, false, false}, {false, false, false, false, false},
      {false, false, false, false, false},
  };

  auto vertices = graph.vertices();
  auto adj_matrix = graph.adj_matrix();

  EXPECT_EQ(vertices, expected_vertices);
  EXPECT_EQ(adj_matrix, expected_adj_matrix);

  graph.AddEdge(0, 1);
  graph.AddEdge(1, 2);

  vertices = graph.vertices();
  adj_matrix = graph.adj_matrix();

  expected_adj_matrix[0][1] = true;
  expected_adj_matrix[1][0] = true;
  expected_adj_matrix[1][2] = true;
  expected_adj_matrix[2][1] = true;

  EXPECT_EQ(vertices, expected_vertices);
  EXPECT_EQ(adj_matrix, expected_adj_matrix);

  graph.RemoveEdge(1, 0);
  graph.RemoveEdge(2, 1);

  vertices = graph.vertices();
  adj_matrix = graph.adj_matrix();

  expected_adj_matrix[0][1] = false;
  expected_adj_matrix[1][0] = false;
  expected_adj_matrix[1][2] = false;
  expected_adj_matrix[2][1] = false;

  EXPECT_EQ(vertices, expected_vertices);
  EXPECT_EQ(adj_matrix, expected_adj_matrix);
}
