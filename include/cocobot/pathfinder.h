#ifndef COCOBOT_PATHFINDER_H
#define COCOBOT_PATHFINDER_H

#include "cocobot/pathfinder_table.h"

#define TRAJECTORY_NBR_POINTS_MAX 160


/**
 * Get execution time to go from starting point to target point
 * Arguments:
 *  - starting_point_x: trajectory starting point x
 *  - starting_point_y: trajectory starting point y
 *  - target_point_x: trajectory target point x
 *  - target_point_y: trajectory target point y
 *  
 * Return Value: Time (ms) to execute the trajectory, 0 if the trajectory is not available
 **/
uint16_t cocobot_pathfinder_get_trajectory_time(int16_t starting_point_x, int16_t starting_point_y, int16_t target_point_x, int16_t target_point_y);

/**
 * Execute trajectory from starting point to target point
 * Arguments:
 *  - starting_point_x: trajectory starting point x
 *  - starting_point_y: trajectory starting point y
 *  - target_point_x: trajectory target point x
 *  - target_point_y: trajectory target point y
 *  
 * Return Value: NO_TRAJECTORY_AVAILABLE if the target_point is not reachable 0 eitherway 
 */
char cocobot_pathfinder_execute_trajectory(int16_t starting_point_x, int16_t starting_point_y, int16_t target_point_x, int16_t target_point_y);

/**
 * Allow the entire start zone for pathfinder
 */
void cocobot_pathfinder_allow_start_zone();

/**
 * Initialize the pathFinder
 * Arguments : 
 *  - robot_length (mm)
 *  - robot_width (mm)
 */
void cocobot_pathfinder_init(uint16_t robot_length, uint16_t robot_width);

#endif //COCOBOT_PATHFINDER_H
