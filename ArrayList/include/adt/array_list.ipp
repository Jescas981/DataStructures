#include "array_list.hpp"

namespace ADT {
// Constructor related
template <typename T, typename A>
ArrayList<T, A>::ArrayList(std::initializer_list<T> list)
    : capacity_(list.size()), length_(list.size()) {
  data_ = alloc_.allocate(capacity_);
  std::memcpy(data_, list.begin(), sizeof(T) * list.size());
}
// ADT Related
template <typename T, typename A>
void ArrayList<T, A>::Add(T item) {
  Resize(length_);
  data_[length_++] = item;
}

template <typename T, typename A>
template <typename... Args>
void ArrayList<T, A>::Append(Args&&... args) {
  Resize(length_);
  data_[length_++] = T(std::forward<Args>(args)...);
}

template <typename T, typename A>
void ArrayList<T, A>::Remove(iterator it) {
  for (; it != end() - 1; ++it) {
    *it = *(it + 1);
  }
  --length_;
}

template <typename T, typename A>
auto ArrayList<T, A>::LinearSearch(T item) const -> iterator {
  for (iterator it = begin(); it != end(); ++it) {
    if (*it == item) return it;
  }
  return end();
}

template <typename T, typename A>
auto ArrayList<T, A>::BinarySearch(T item) const -> iterator {
  size_t l{0}, h = length_ - 1;
  while (l <= h) {
    size_t m = (l + h) / 2;
    if (data_[m] == item) {
      return begin() + m;
    } else if (data_[m] > item) {
      h = m - 1;
    } else {
      l = m - 1;
    }
  }
}

template <typename T, typename A>
auto ArrayList<T, A>::Search(T item) -> iterator {
  iterator it = LinearSearch(item);
  if (it != end()) std::swap(*it, *begin());
  return it;
}

template <typename T, typename A>
void ArrayList<T, A>::Sort(size_t l, size_t h) {
  size_t i{l}, j{h};
  while (i <= j) {
    while (data_[i] < data_[h]) ++i;  // Left side
    while (data_[j] > data_[h]) --j;  // Right side
    std::swap(data_[i], data_[j]);
  }
  // Partition
}

// Allocator Related
template <typename T, typename A>
void ArrayList<T, A>::Reserve(size_t capacity) {
  T* buffer = nullptr;
  buffer = alloc_.allocate(capacity);
  std::memcpy(buffer, data_, sizeof(T) * length_);
  alloc_.deallocate(data_, capacity_);
  data_ = buffer;
  capacity_ = capacity;
}

template <typename T, typename A>
void ArrayList<T, A>::Resize(size_t length) {
  if (length >= capacity_) {
    Reserve(length * kMultCapacity);
  }
  length_ = length;
}

}  // namespace ADT
