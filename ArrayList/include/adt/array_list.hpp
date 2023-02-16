#pragma once
#include <cstring>
#include <initializer_list>
#include <iostream>
#include <memory>
#include <numeric>
#include <type_traits>
#include <utility>

namespace ADT {
template <typename T, typename A = std::allocator<T>>
class ArrayList {
  using iterator = T*;
  using const_iterator = const T*;
  static constexpr size_t kMultCapacity{3};
  size_t length_{0};
  size_t capacity_{kMultCapacity};
  T* data_{nullptr};
  A alloc_;

 public:
  explicit ArrayList() {}
  explicit ArrayList(std::initializer_list<T> list);
  explicit ArrayList(size_t capacity)
      : capacity_(capacity), data_{alloc_.allocate(capacity_)} {}
  // ADT related
  size_t size() const { return length_; }
  size_t capacity() const { return capacity_; }
  void Add(T item);
  template <typename... Arsg>
  void Append(Arsg&&... args);
  void Remove(iterator it);
  // Arithmetic related
  template <typename = std::enable_if_t<std::is_arithmetic_v<T>, T>>
  inline T Sum() const {
    return std::accumulate(begin(), end(), 0);
  }
  template <typename = std::enable_if_t<std::is_arithmetic_v<T>, T>>
  inline T Average() const {
    return Sum() / length_;
  }
  // Allocator
  void Reserve(size_t capacity);
  void Resize(size_t length);
  // Iterator related
  iterator begin() { return data_; }
  iterator end() { return data_ + length_; }
  iterator begin() const { return data_; }
  iterator end() const { return data_ + length_; }
};
}  // namespace ADT
