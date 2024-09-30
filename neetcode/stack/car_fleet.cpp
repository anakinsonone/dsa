/*
 * Car Fleet

 * There are n cars traveling to the same destination on a one-lane highway.

 * You are given two arrays of integers position and speed, both of length n.

 *     position[i] is the position of the ith car (in miles)
 *     speed[i] is the speed of the ith car (in miles per hour)

 * The destination is at position target miles.

 * A car can not pass another car ahead of it. It can only catch up to another
 car
 * and then drive at the same speed as the car ahead of it.

 * A car fleet is a non-empty set of cars driving at the same position and same
 * speed. A single car is also considered a car fleet.

 * If a car catches up to a car fleet the moment the fleet reaches the
 destination,
 * then the car is considered to be part of the fleet.

 * Return the number of different car fleets that will arrive at the
 destination.

 * Example 1:
 * Input: target = 10, position = [1,4], speed = [3,2]
 * Output: 1
 * Explanation: The cars starting at 1 (speed 3) and 4 (speed 2) become a fleet,
 * meeting each other at 10, the destination.

 * Example 2:
 * Input: target = 10, position = [4,1,0,7], speed = [2,2,1,1]
 * Output: 3
 * Explanation: The cars starting at 4 and 7 become a fleet at position 10. The
 * cars starting at 1 and 0 never catch up to the car ahead of them. Thus, there
 * are 3 car fleets that will arrive at the destination.
*/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>
int main() {
  int target, p, s;
  std::cin >> target >> p >> s;

  std::vector<int> positions(p, 0);
  for (int i = 0; i < p; i++)
    std::cin >> positions[i];

  std::vector<int> speeds(s, 0);
  for (int i = 0; i < s; i++)
    std::cin >> speeds[i];

  std::vector<std::pair<double, double>> pairs(p);
  for (int i = 0; i < p; i++) {
    pairs[i] = {positions[i], speeds[i]};
  }

  std::sort(
      pairs.begin(), pairs.end(),
      [](const std::pair<double, double> &a,
         const std::pair<double, double> &b) { return b.first < a.first; });

  int fleetCount = 0;
  std::vector<double> timeToReach(p);
  for (int i = 0; i < p; i++) {
    timeToReach[i] = (target - pairs[i].first) / pairs[i].second;
    if (i >= 1 && timeToReach[i] <= timeToReach[i - 1]) {
      timeToReach[i] = timeToReach[i - 1];
    } else {
      fleetCount++;
    }
  }

  std::cout << fleetCount;

  return 0;
}
