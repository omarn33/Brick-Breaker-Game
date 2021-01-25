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
    /**
     * Constructor that creates a level with a given number of bricks
     * @param level_number size_t representing the level number
     * @param bricks vector<Brick> storing the bricks for the designated level
     * @param number_of_steel_bricks size_t the number of steel bricks associated with a given level
     */
    Level(size_t level_number, const std::vector<Brick> &bricks, size_t number_of_steel_bricks);

    /** Getter Methods */
    size_t GetLevelNumber();

    /** Setter Methods */
    void SetLevelNumber(size_t level);

    const std::vector<Brick> &Level::GetBricks();

    /**
     * Returns the number of non-steel bricks in the level
     * @return size_t representing the number of non-steel bricks
     */
    size_t GetNumberOfDestroyableBricks();

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
