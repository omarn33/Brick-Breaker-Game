#pragma once

#include "brick.h"
#include <vector>

namespace brickbreaker {

class Level {
private:
    std::vector<Brick> bricks_;
    size_t level_number_;

public:
    Level(size_t level_number, const std::vector<Brick> &bricks);

    /** Getter Methods */
    size_t GetLevelNumber();

    size_t GetNumberOfBricks();

    /** Setter Methods */
    void SetLevelNumber(size_t level);

    std::vector<Brick> &Level::GetBricks();

    void ErodeBrick(size_t index);

    void Draw();
};

}  // namespace brickbreaker
