#pragma once

#include "cinder/gl/gl.h"
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
    kUnbreakable,   // Steel Brick
    kStrong,        // Solid CLay Brick
    kMedium,        // Normal Clay Brick
    kWeak           // Cracked Clay Brick
};

class Brick {
private:
    BrickType type_;
    BrickCondition condition_;
    glm::vec2 brick_top_left_corner_;
    glm::vec2 brick_bottom_right_corner_;

    friend class Ball;
    friend class Level;

public:
    /**
     * Constructor that initializes brick attribute
     * @param type
     * @param condition
     * @param top_left_corner vec2 representing the coordinate of the top left corner of the brick
     * @param bottom_right_corner vec2 representing the coordinate of the bottom right corner of the brick
     */
    Brick(BrickType type, BrickCondition condition, const glm::vec2 &top_left_corner,
          const glm::vec2 &bottom_right_corner);

    /** Setter Methods */
    void SetBrickType(BrickType type);

    void SetBrickCondition(BrickCondition condition);

    /**
     * Draws brick in the cinder application
     */
    void Draw();

};

} // namespace brickbreaker