#include <array>

#pragma once

enum class Joint : std::size_t {
    Hip,
	Shoulder,
	Elbow,
	Wrist,
	WristRot,
	Claw,
	Count
};

constexpr std::size_t toIndex(Joint j)
{
	return static_cast<std::size_t>(j);
};

constexpr std::size_t JointCount = toIndex(Joint::Count);

constexpr std::array<Joint, toIndex(Joint::Count)> allJoints{
	Joint::Hip,
	Joint::Shoulder,
	Joint::Elbow,
	Joint::Wrist,
	Joint::WristRot,
	Joint::Claw
};
