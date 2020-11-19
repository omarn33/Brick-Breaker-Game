#include <core/brick.h>

namespace brickbreaker {

Brick::Brick(BrickType type, BrickCondition condition, const glm::vec2 &top_left_corner, double length, double width) {
    type_ = type;
    condition_ = condition;
    brick_top_left_corner_ = top_left_corner;
    length_ = length;
    width_ = width;
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

double Brick::GetBrickLength() {
    return length_;
}

double Brick::GetBrickWidth() {
    return width_;
}

void Brick::SetBrickType(BrickType type) {
    type_ = type;
}

void Brick::SetBrickCondition(BrickCondition condition) {
    condition_ = condition;
}

} // namespace brickbreaker
