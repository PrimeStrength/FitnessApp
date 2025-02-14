#pragma once

#include <initializer_list>
#include "set.h"

namespace exercise
{

class workout
{
public:
    workout(std::initializer_list<set> sets) : _sets(sets) {}

    std::vector<set> get_set() const;

    void add_set(set);

private:
    std::vector<set> _sets;
};

}; // namespace exercise
