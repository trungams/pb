#pragma once

#include <iostream>
#include <string>
#include <vector>

struct CustomData {
  CustomData(const std::string &s, const std::vector<int> &v) : str(s), v(v) {}

  std::string str;
  std::vector<int> v;
};

template <typename T> class Matrix {
public:
  Matrix() {}
  Matrix(size_t rows, size_t cols) : rows_(rows), cols_(cols) {
    buffer_ = new T[rows_ * cols_];
  }
  ~Matrix() { delete[] buffer_; }

  T *operator[](size_t r) { return buffer_ + r * cols_; }
  T *operator[](size_t r) const { return buffer_ + r * cols_; }

  T *data() { return buffer_; }
  size_t rows() const { return rows_; }
  size_t cols() const { return cols_; }

  friend std::ostream &operator<<(std::ostream &os, const Matrix &m) {
    os << "[";
    for (int i = 0; i < static_cast<int>(m.rows()); i++) {
      os << "[";
      for (int j = 0; j < static_cast<int>(m.cols()); j++) {
        if (j > 0)
          os << " ";
        os << m[i][j];
      }
      os << "]";
      if (i + 1 < static_cast<int>(m.rows()))
        os << "\n";
    }
    os << "]";
    return os;
  }

private:
  size_t rows_;
  size_t cols_;
  T *buffer_;
};

using Int64Matrix = Matrix<int64_t>;
using DoubleMatrix = Matrix<double>;

