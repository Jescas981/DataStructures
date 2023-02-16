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
  Resize(--length_);
  for (; it != end() - 1; ++it) {
    *it = *(it + 1);
  }
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
  } else if (length <= capacity_ / kMultCapacity) {
    Reserve(length);
  }
  length_ = length;
}

}  // namespace ADT
