#pragma once
#include <nlohmann/json.hpp>
//#include <initializer_list>
#include <vector>
#include "Exercise.h"
#include "Rep.h"

namespace exercise
{

class Set 
{
	using json = nlohmann::json;
public:

    // set(std::initializer_list<Rep> reps): m_reps(reps) {} 

    //Set(std::vector<Rep> reps) : m_reps{reps} {}
    Set() = default;

    //std::vector<Rep> get_reps() const;
    //void add_rep(Rep);

    const std::vector<Rep>& getReps() const {return m_reps;}
    const Exercise& getExercise() const { return m_exercise;}

    std::vector<Rep>& getRepsNonConst() {return m_reps;}

    void setReps(std::vector<Rep> reps){m_reps = reps;}

private:
    std::vector<Rep> m_reps{};
    Exercise m_exercise{"No Name"};

};
    void to_json(json& j, const Set& set);
    void from_json(const json& j,Set& set);


}; //namespace exercise

