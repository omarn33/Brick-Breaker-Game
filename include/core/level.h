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

    /** Getter Methos */
    size_t GetLevelNumber();

    const std::vector<Brick> &Level::GetBricks();

    void Draw();
};

}  // namespace brickbreaker
