#include "composite-shape.hpp"

#include <stdexcept>
#include <utility>

namespace semenov
{
  CompositeShape::CompositeShape(const CompositeShape& other):
    CompositeShape()
  {
    if (!other.empty())
    {
      figures_ = new Shape*[other.size_];
      for (; size_ < other.size_; ++size_)
      {
        figures_[size_] = other.get(size_).clone();
      }
    }
  }

  CompositeShape::CompositeShape(CompositeShape&& other) noexcept:
    figures_(other.figures_),
    size_(other.size_)
  {
    other.figures_ = nullptr;
    other.size_ = 0;
  }

  CompositeShape& CompositeShape::operator=(const CompositeShape& other)
  {
    if (this != &other)
    {
      CompositeShape copy(other);
      std::swap(figures_, copy.figures_);
      std::swap(size_, copy.size_);
    }
    return *this;
  }

  CompositeShape& CompositeShape::operator=(CompositeShape&& other) noexcept
  {
    if (this != &other)
    {
      clear();
      figures_ = other.figures_;
      size_ = other.size_;
      other.figures_ = nullptr;
      other.size_ = 0;
    }
    return *this;
  }

  CompositeShape::~CompositeShape()
  {
    clear();
  }

  void CompositeShape::preappend(const Shape& figure)
  {
    add(0, figure);
  }

  void CompositeShape::append(const Shape& figure)
  {
    add(size_, figure);
  }

  void CompositeShape::add(std::size_t index, const Shape& figure)
  {
    if (index > size_)
    {
      throw std::out_of_range("Invalid insertion index");
    }

    Shape** const next = new Shape*[size_ + 1];
    try
    {
      next[index] = figure.clone();
    }
    catch (...)
    {
      delete[] next;
      throw;
    }
    for (std::size_t i = 0; i < index; ++i)
    {
      next[i] = figures_[i];
    }
    for (std::size_t i = index; i < size_; ++i)
    {
      next[i + 1] = figures_[i];
    }

    delete[] figures_;
    figures_ = next;
    ++size_;
  }

  Shape& CompositeShape::first()
  {
    return at(0);
  }

  const Shape& CompositeShape::first() const
  {
    return at(0);
  }

  Shape& CompositeShape::last()
  {
    return at(empty() ? 0 : size_ - 1);
  }

  const Shape& CompositeShape::last() const
  {
    return at(empty() ? 0 : size_ - 1);
  }

  Shape& CompositeShape::at(std::size_t index)
  {
    checkIndex(index);
    return get(index);
  }

  const Shape& CompositeShape::at(std::size_t index) const
  {
    checkIndex(index);
    return get(index);
  }

  Shape& CompositeShape::get(std::size_t index) noexcept
  {
    return *figures_[index];
  }

  const Shape& CompositeShape::get(std::size_t index) const noexcept
  {
    return *figures_[index];
  }

  void CompositeShape::remove(std::size_t index)
  {
    checkIndex(index);
    delete figures_[index];
    for (std::size_t i = index + 1; i < size_; ++i)
    {
      figures_[i - 1] = figures_[i];
    }
    figures_[--size_] = nullptr;
  }

  void CompositeShape::dropFirst()
  {
    remove(0);
  }

  void CompositeShape::dropLast()
  {
    remove(empty() ? 0 : size_ - 1);
  }

  void CompositeShape::clear() noexcept
  {
    for (std::size_t i = 0; i < size_; ++i)
    {
      delete figures_[i];
    }
    delete[] figures_;
    figures_ = nullptr;
    size_ = 0;
  }

  std::size_t CompositeShape::size() const noexcept
  {
    return size_;
  }

  bool CompositeShape::empty() const noexcept
  {
    return size_ == 0;
  }

  void CompositeShape::checkIndex(std::size_t index) const
  {
    if (index >= size_)
    {
      throw std::out_of_range("Invalid figure index");
    }
  }
}
