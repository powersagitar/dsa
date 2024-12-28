#include <graph.h>
#include <gtest/gtest.h>

#include <vector>

namespace {

template <typename T>
void EXPECT_VEC_EQ(const std::vector<T> &vec_a, const std::vector<T> &vec_b) {
  EXPECT_EQ(vec_a.size(), vec_b.size());

  for (size_t i = 0; i < vec_a.size(); ++i) {
    EXPECT_EQ(vec_a[i], vec_b[i]);
  }
}

template <typename T>
void EXPECT_2D_VEC_EQ(const std::vector<std::vector<T>> &vec_a,
                      const std::vector<std::vector<T>> &vec_b) {
  EXPECT_EQ(vec_a.size(), vec_b.size());

  for (size_t i = 0; i < vec_a.size(); ++i) {
    EXPECT_VEC_EQ(vec_a[i], vec_b[i]);
  }
}

}  // namespace

TEST(Graph, EmptyGraph) {
  dsa::UndirectedGraph<int> graph;
  EXPECT_EQ(graph.Size(), 0);

  std::vector<int> expected_vertices;
  std::vector<std::vector<bool>> expected_adj_matrix;

  auto vertices = graph.vertices();
  auto adj_matrix = graph.adj_matrix();

  EXPECT_VEC_EQ(vertices, expected_vertices);
  EXPECT_2D_VEC_EQ(adj_matrix, expected_adj_matrix);
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

  EXPECT_VEC_EQ(vertices, expected_vertices);
  EXPECT_2D_VEC_EQ(adj_matrix, expected_adj_matrix);

  graph.AddEdge(0, 1);
  graph.AddEdge(1, 2);

  vertices = graph.vertices();
  adj_matrix = graph.adj_matrix();

  expected_adj_matrix[0][1] = true;
  expected_adj_matrix[1][0] = true;
  expected_adj_matrix[1][2] = true;
  expected_adj_matrix[2][1] = true;

  EXPECT_VEC_EQ(vertices, expected_vertices);
  EXPECT_2D_VEC_EQ(adj_matrix, expected_adj_matrix);

  graph.RemoveEdge(1, 0);
  graph.RemoveEdge(2, 1);

  vertices = graph.vertices();
  adj_matrix = graph.adj_matrix();

  expected_adj_matrix[0][1] = false;
  expected_adj_matrix[1][0] = false;
  expected_adj_matrix[1][2] = false;
  expected_adj_matrix[2][1] = false;

  EXPECT_VEC_EQ(vertices, expected_vertices);
  EXPECT_2D_VEC_EQ(adj_matrix, expected_adj_matrix);
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

  EXPECT_VEC_EQ(vertices, expected_vertices);
  EXPECT_2D_VEC_EQ(adj_matrix, expected_adj_matrix);

  graph.AddEdge(0, 1);
  graph.AddEdge(1, 2);

  vertices = graph.vertices();
  adj_matrix = graph.adj_matrix();

  expected_adj_matrix[0][1] = true;
  expected_adj_matrix[1][0] = true;
  expected_adj_matrix[1][2] = true;
  expected_adj_matrix[2][1] = true;

  EXPECT_VEC_EQ(vertices, expected_vertices);
  EXPECT_2D_VEC_EQ(adj_matrix, expected_adj_matrix);

  graph.RemoveEdge(1, 0);
  graph.RemoveEdge(2, 1);

  vertices = graph.vertices();
  adj_matrix = graph.adj_matrix();

  expected_adj_matrix[0][1] = false;
  expected_adj_matrix[1][0] = false;
  expected_adj_matrix[1][2] = false;
  expected_adj_matrix[2][1] = false;

  EXPECT_VEC_EQ(vertices, expected_vertices);
  EXPECT_2D_VEC_EQ(adj_matrix, expected_adj_matrix);
}
