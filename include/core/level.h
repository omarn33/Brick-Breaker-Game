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

    size_t GetNumberOfDestroyableBricks();

    /** Setter Methods */
    void SetLevelNumber(size_t level);

    const std::vector<Brick> &Level::GetBricks();

    /**
     * Alters the Brick type in order to illustrate damage after ball collision
     * @param index int representing the index in which the brick is located in the vector<Brick> bricks_
     */
    void ErodeBrick(size_t index);

    /**
     * Draws the Brick in the cinder application
     */
    void Draw();
};

}  // namespace brickbreaker
