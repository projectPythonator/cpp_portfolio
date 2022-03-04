#pragma once

class Pivot {
public:
  Pivot() = default;
  Pivot(PivotPointSize start_index, PivotPointSize end_index) {
    pivot_start_index_ = start_index;
    pivot_end_index_ = end_index;
  }
  Pivot(const Pivot&) = default;

  inline bool empty() const;
  inline PivotPointSize size() const;

  inline PivotPointSize front() const;
  inline PivotPointSize back() const;

  inline bool operator<(const Pivot& other) const;
  inline bool operator>(const Pivot& other) const;

  inline operator const Pivot*() const;

  inline bool endAfter(const PivotPointSize other) const;
  inline bool endAfter(const Pivot& other) const;
  inline bool endBefore(const Pivot& other) const;

 protected:
  PivotPointSize pivot_start_index_;
  PivotPointSize pivot_end_index_;
};

bool Pivot::empty() const {
  return (size() == 0);
}

PivotPointSize Pivot::size() const {
  return back() - front();
}

PivotPointSize Pivot::front() const {
  return pivot_start_index_;
}

PivotPointSize Pivot::back() const {
  return pivot_end_index_;
}

bool Pivot::operator<(const Pivot& other) const {
  return back() < other.front();
}

bool Pivot::operator>(const Pivot& other) const {
  return back > other.front();
}

Pivot::operator const Pivot*() const {
  return this;
}

bool Pivot::endAfter(const PivotPointSize other) const {
  return back() > other;
}

bool Pivot::endAfter(const Pivot& other) const {
  return back() > other.front();
}

bool Pivot::endBefore(const Pivot& other) const {
  return back() <= other.front();
}
