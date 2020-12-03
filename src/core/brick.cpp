#include <core/brick.h>

namespace brickbreaker {

Brick::Brick(BrickType type, BrickCondition condition, const glm::vec2 &top_left_corner, const glm::vec2 &bottom_right_corner) {
    type_ = type;
    condition_ = condition;
    brick_top_left_corner_ = top_left_corner;
    brick_bottom_right_corner_ = bottom_right_corner;
}

BrickType Brick::GetBrickType() {
    return type_;
}

BrickCondition Brick::GetBrickCondition() {
    return condition_;
}

const glm::vec2 &Brick::GetBrickPosition() {
    return brick_top_left_corner_;
}

void Brick::SetBrickType(BrickType type) {
    type_ = type;
}

void Brick::SetBrickCondition(BrickCondition condition) {
    condition_ = condition;
}

void Brick::Draw() {
    // Determine Brick Type
    if(type_ == kCrackedClay) {
        ci::gl::color(ci::Color8u(128, 0, 0));
    }

    // Display Brick
    ci::gl::drawSolidRect(ci::Rectf(brick_top_left_corner_, brick_bottom_right_corner_));
}


} // namespace brickbreaker
