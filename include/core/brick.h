#pragma once

#include "../../../../include/glm/glm.hpp"
#include "../../../../include/cinder/Color.h"
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

class Brick {
    BrickType type_;
    BrickCondition condition_;
    glm::vec2 brick_top_left_corner_;
    double length_;
    double width_;

    friend class Ball;

    /**
     * Constructor that initializes brick attribute
     * @param type
     * @param condition
     * @param top_left_corner vec2 representing the coordinate of the top left corner of the brick
     * @param bottom_right_corner vec2 representing the coordinate of the bottom right corner of the brick
     */
    Brick(BrickType type, BrickCondition condition, const glm::vec2 &top_left_corner,
          const glm::vec2 &bottom_right_corner);

    /** Getter Methods */
    BrickType GetBrickType();

    BrickCondition GetBrickCondition();

    const glm::vec2 &GetBrickPosition();

    /** Setter Methods */
    void SetBrickType(BrickType type);

    void SetBrickCondition(BrickCondition condition);

};

} // namespace brickbreaker