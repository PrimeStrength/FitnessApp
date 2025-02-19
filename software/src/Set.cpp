#include "Set.h"
#include "Exercise.h"

namespace exercise 
{

void to_json(json& j, const exercise::Set& set)
{
    j = json
    {
        {"reps", set.getReps()},
        {"exercise", set.getExercise()}
    };
}
    void from_json(const json& j, exercise::Set& set) 
    {
    
        j.at("reps").get_to(set.getRepsNonConst());
        j.at("exercise").get_to(exercise);
    
        set.setReps(reps);
        set.setExercise(exercise);
    }

} // namespace