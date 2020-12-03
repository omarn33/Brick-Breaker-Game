#pragma once

#include "brick.h"
#include <vector>

namespace brickbreaker {

class Level {
private:
    std::vector<Brick> bricks_;

public:
    Level(const std::vector<Brick> &bricks);

    void Draw();
};

}  // namespace brickbreaker
