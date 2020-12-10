#pragma once

#include "brick.h"
#include <vector>

namespace brickbreaker {

class Level {
private:
    std::vector<Brick> bricks_;
    size_t level_number_;
    size_t number_of_steel_bricks_;

public:
    Level(size_t level_number, const std::vector<Brick> &bricks, size_t number_of_steel_bricks);

    /** Getter Methods */
    size_t GetLevelNumber();

    size_t GetNumberDestroyableOfBricks();

    /** Setter Methods */
    void SetLevelNumber(size_t level);

    std::vector<Brick> &Level::GetBricks();

    void ErodeBrick(size_t index);

    void Draw();
};

}  // namespace brickbreaker
