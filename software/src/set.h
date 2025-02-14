#pragma once

#include <initializer_list>
#include <vector>
#include "rep.h"

namespace exercise
{

class set
{
public:
    set(std::initializer_list<rep> reps) : _reps(reps) {}

    std::vector<rep> get_reps() const;

    void add_rep(rep);

private:
    std::vector<rep> _reps;
};

}; // namespace exercise
