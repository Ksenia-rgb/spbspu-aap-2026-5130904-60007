#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include <cstddef>
#include <shape.hpp>

namespace semenov {
  class CompositeShape {
  public:
    CompositeShape() noexcept = default;
    CompositeShape(const CompositeShape& other);
    CompositeShape(CompositeShape&& other) noexcept;
    CompositeShape& operator=(const CompositeShape& other);
    CompositeShape& operator=(CompositeShape&& other) noexcept;
    ~CompositeShape();

    void preappend(const Shape& figure);
    void append(const Shape& figure);
    void add(std::size_t index, const Shape& figure);

    // first() and last() throw std::out_of_range when empty.
    Shape& first();
    const Shape& first() const;
    Shape& last();
    const Shape& last() const;
    Shape& at(std::size_t index);
    const Shape& at(std::size_t index) const;
    // The caller must ensure index < size().
    Shape& get(std::size_t index) noexcept;
    const Shape& get(std::size_t index) const noexcept;

    // Invalid indices and drops from an empty object throw std::out_of_range.
    void remove(std::size_t index);
    void dropFirst();
    void dropLast();
    void clear() noexcept;
    std::size_t size() const noexcept;
    bool empty() const noexcept;

  private:
    Shape** figures_ = nullptr;
    std::size_t size_ = 0;
    void checkIndex(std::size_t index) const;
  };
}

#endif
