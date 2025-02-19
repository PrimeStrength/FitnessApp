#pragma once
#include "exercise.h"
namespace exercise
{

class rep
{
public:
    explicit rep(exercise* ex) : _ex(ex) {}

    rep(exercise* ex, int intensity, int duration_s)
       : _ex(ex), _intensity(intensity), _duration_s(duration_s)
    {
    }

    exercise get_exercise() const;
    std::optional<int> get_intensity() const;
    std::optional<int> get_duration_s() const;

private:
    exercise* _ex;
    // The meaning of intensity depends on the exercise. For strength,
    // it means mass. For cardio, its meaning is less clear. For
    // climbing, it means grade, etc.
    std::optional<int> _intensity;
    std::optional<int> _duration_s;
};

} // namespace exercise
