#ifndef GRAPH_H_
#define GRAPH_H_

#include <initializer_list>
#include <vector>

namespace dsa {

template <typename T>
class UndirectedGraph final {
 public:
  UndirectedGraph() = default;

  explicit UndirectedGraph(std::initializer_list<T> vertices) noexcept {
    for (const T &vertex : vertices) {
      vertices_.emplace_back(vertex);
    }

    const size_t size = vertices_.size();

    for (size_t i = 0; i < size; ++i) {
        adj_matrix_.emplace_back(std::vector<bool>(size, false));
    }
  }

  void AddEdge(const size_t from, const size_t to) noexcept {
    adj_matrix_[from][to] = true;
    adj_matrix_[to][from] = true;
  }

  void RemoveEdge(const size_t from, const size_t to) noexcept {
    adj_matrix_[from][to] = false;
    adj_matrix_[to][from] = false;
  }

  bool HasEdge(const size_t from, const size_t to) const noexcept {
    return adj_matrix_[from][to];
  }

  void Insert(const size_t index, const T &vertex) noexcept {
    const size_t new_size = Size() + 1;

    vertices_.insert(vertices_.begin() + index, vertex);

    for (std::vector<bool> &row : adj_matrix_) {
       row.insert(row.begin() + index, false);
    }

    adj_matrix_.insert(adj_matrix_.begin() + index, std::vector<bool>(new_size, false));
  }

  size_t Size() const noexcept { return vertices_.size(); }

  const std::vector<std::vector<bool>> &adj_matrix() const noexcept { return adj_matrix_; }
  const std::vector<T> &vertices() const noexcept { return vertices_; }

 private:
  std::vector<std::vector<bool>> adj_matrix_;
  std::vector<T> vertices_;
};

}  // namespace dsa

#endif  // GRAPH_H_
