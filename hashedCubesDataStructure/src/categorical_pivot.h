#pragma once

#include "pivot.h"
#include "type_definitions.h"

class CategoricalPivot : public Pivot {
  public:
    CategoricalPivot(PivotPointSize start_point, PivotPointSize end_point, CategoryPivitSize& value) Pivot(start_point, end_point), cat_pivot_value(value) { }
    CategoricalPivot(const Pivot& pivot_range, CategoryPivitSize& value) Pivot(pivot_range), cat_pivot_value(value) { }
    ~CategoricalPivot() = default;

    inline const CategoryPivotSize& value() const;

  protected:
    CategoryPivotSize cat_pivot_value;
};

const CategoryPivotSize& CategoricalPivot::value() const {
  return cat_pivot_value;
}
