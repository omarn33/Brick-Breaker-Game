#pragma once

#include "../../../../include/glm/glm.hpp"
#include <cinder/Color.h>
#include <vector>

namespace brickbreaker {

enum BrickType {
    kSteel,
    kSolidClay,
    kNormalClay,
    kCrackedClay
};

enum BrickCondition {
    kUnbreakable,
    kStrong,
    kMedium,
    kWeak
};

/** >>>>>>> I think Brick should be a STRUCT but then should that be implemented in Brick.cpp? <<<<<<<< */
class Brick {
    BrickType type_;
    BrickCondition condition_;
    glm::vec2 brick_top_left_corner_;
    double brick_length_;
    double brick_width_;

    /**
     * Constructor that initialize brick attributes
     * @param top_left_corner vec2 representing the coordinate of the top left corner of the brick
     * @param length double representing the length of the brick
     * @param width double representing the width of the brick
     */
    Brick(BrickType type, BrickCondition condition, const glm::vec2& top_left_corner, double length, double width);

    /** Getter Methods */
    BrickType GetBrickType();

    BrickCondition GetBrickCondition();

    const glm::vec2& GetBrickPosition();

    double GetBrickLength();

    double GetBrickWidth();

    /** Setter Methods */
    void SetBrickType(BrickType type);

    void SetBrickCondition(BrickCondition condition);

};

} // namespace brickbreaker