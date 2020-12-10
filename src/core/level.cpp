#include <core/level.h>

namespace brickbreaker {

Level::Level(size_t level_number, const std::vector<Brick> &bricks, size_t number_of_steel_bricks) {
    level_number_ = level_number;
    bricks_ = bricks;
    number_of_steel_bricks_ = number_of_steel_bricks;
}

size_t Level::GetLevelNumber() {
    return level_number_;
}

size_t Level::GetNumberDestroyableOfBricks() {
    return (bricks_.size() - number_of_steel_bricks_);
}

void Level::SetLevelNumber(size_t level) {
    level_number_ = level;
}

std::vector<Brick> &Level::GetBricks() {
    return bricks_;
}

void Level::ErodeBrick(size_t index) {
    // Degrade to respective brick
    if(bricks_.at(index).type_ == kSolidClay) {
        bricks_.at(index).SetBrickType(kNormalClay);
        bricks_.at(index).SetBrickCondition(kMedium);
    }
    else if(bricks_.at(index).type_ == kNormalClay) {
        bricks_.at(index).SetBrickType(kCrackedClay);
        bricks_.at(index).SetBrickCondition(kWeak);
    } else if(bricks_.at(index).type_ == kCrackedClay) {
        // Delete brick
        bricks_.erase(bricks_.begin() + index);
    }
}

void Level::Draw() {
    // Display all bricks within the level
    for(int brick = 0; brick < bricks_.size(); ++brick) {
        bricks_.at(brick).Draw();
    }
}
}  // namespace brickbreaker
