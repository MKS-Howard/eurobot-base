#include "cocobot/pathfinder_table_utils.h"
#include "cocobot.h"
#include <string.h>
#include <math.h>

void cocobot_pathfinder_initialize_table(cocobot_node_s table[][TABLE_WIDTH/GRID_SIZE], uint16_t robot_length, uint16_t robot_width)
{
    memset(table, 0, (TABLE_LENGTH / GRID_SIZE) * sizeof(cocobot_node_s));
    for(int i = 0; i < TABLE_LENGTH / GRID_SIZE; i++)
    {
        memset(table[i], 0, (TABLE_WIDTH / GRID_SIZE) * sizeof(cocobot_node_s));
        for(int j = 0; j < TABLE_WIDTH / GRID_SIZE; j++)
        {
            table[i][j].x = i;
            table[i][j].y = j;
            table[i][j].nodeType = NEW_NODE;
        }
    }
    
    uint16_t half_width = robot_width/2 + (GRID_SIZE-1);
    uint8_t grid_half_width = (half_width / GRID_SIZE) + 1;
    uint16_t half_diag = (uint16_t) (sqrtf((robot_length * robot_length) + (robot_width * robot_width)) / 2) + (GRID_SIZE-1);
    uint8_t grid_half_diag = half_diag / GRID_SIZE;

    //walls half diag = soft_obstacle
    cocobot_pathfinder_set_rectangle(table, TABLE_LENGTH / GRID_SIZE, grid_half_diag, 0, 0, SOFT_OBSTACLE);  
    cocobot_pathfinder_set_rectangle(table, TABLE_LENGTH / GRID_SIZE, grid_half_diag, 0, TABLE_WIDTH/GRID_SIZE - grid_half_diag, SOFT_OBSTACLE);  
    cocobot_pathfinder_set_rectangle(table, grid_half_diag, TABLE_WIDTH / GRID_SIZE, 0, 0, SOFT_OBSTACLE);
    cocobot_pathfinder_set_rectangle(table, grid_half_diag, TABLE_WIDTH / GRID_SIZE, TABLE_LENGTH / GRID_SIZE - grid_half_diag, 0, SOFT_OBSTACLE);  

    // dune soft_obstacle
    cocobot_pathfinder_set_rectangle(table, grid_half_diag, 200/GRID_SIZE, 800/GRID_SIZE - grid_half_diag, 0/GRID_SIZE, SOFT_OBSTACLE);
    cocobot_pathfinder_set_rectangle(table, grid_half_diag, 200/GRID_SIZE, 800/GRID_SIZE + 1, 0/GRID_SIZE, SOFT_OBSTACLE);
    cocobot_pathfinder_set_circle(table, 810/GRID_SIZE, 200/GRID_SIZE, (half_diag + 10) / GRID_SIZE, SOFT_OBSTACLE);
    cocobot_pathfinder_set_rectangle(table, grid_half_diag, 200/GRID_SIZE, 2200/GRID_SIZE - grid_half_diag, 0/GRID_SIZE, SOFT_OBSTACLE);
    cocobot_pathfinder_set_rectangle(table, grid_half_diag, 200/GRID_SIZE, 2200/GRID_SIZE + 1, 0/GRID_SIZE, SOFT_OBSTACLE);
    cocobot_pathfinder_set_circle(table, 2210/GRID_SIZE, 200/GRID_SIZE, (half_diag + 10) / GRID_SIZE, SOFT_OBSTACLE);
    
    //Central T soft_obstacle
    cocobot_pathfinder_set_rectangle(table, 1200/GRID_SIZE, grid_half_diag, 900/GRID_SIZE, 750/GRID_SIZE - grid_half_diag, SOFT_OBSTACLE);
    cocobot_pathfinder_set_rectangle(table, 1200/GRID_SIZE, grid_half_diag, 900/GRID_SIZE, 750/GRID_SIZE + 1, SOFT_OBSTACLE);
    cocobot_pathfinder_set_circle(table, 900/GRID_SIZE, 760/GRID_SIZE, (half_diag + 10) / GRID_SIZE, SOFT_OBSTACLE);
    cocobot_pathfinder_set_circle(table, 2100/GRID_SIZE, 760/GRID_SIZE, (half_diag + 10) / GRID_SIZE, SOFT_OBSTACLE);
    cocobot_pathfinder_set_rectangle(table, grid_half_diag, 600/GRID_SIZE, 1470/GRID_SIZE - grid_half_diag, 750/GRID_SIZE, SOFT_OBSTACLE);
    cocobot_pathfinder_set_rectangle(table, grid_half_diag, 600/GRID_SIZE, 1470/GRID_SIZE + 1, 750/GRID_SIZE, SOFT_OBSTACLE);
    cocobot_pathfinder_set_circle(table, 1500/GRID_SIZE, 1350/GRID_SIZE, (half_diag + 25) / GRID_SIZE, SOFT_OBSTACLE);
    
    //iles soft_obstacle
    cocobot_pathfinder_set_circle(table, 0/GRID_SIZE, 2000/GRID_SIZE, (250 + half_diag)/GRID_SIZE, SOFT_OBSTACLE); 
    cocobot_pathfinder_set_circle(table, 3000/GRID_SIZE, 2000/GRID_SIZE, (250 + half_diag)/GRID_SIZE, SOFT_OBSTACLE); 

    //Expand walls half width = forbidden 
    cocobot_pathfinder_set_rectangle(table, TABLE_LENGTH / GRID_SIZE, grid_half_width, 0, 0, FORBIDDEN);  
    cocobot_pathfinder_set_rectangle(table, TABLE_LENGTH / GRID_SIZE, grid_half_width, 0, TABLE_WIDTH/GRID_SIZE - grid_half_width, FORBIDDEN);  
    cocobot_pathfinder_set_rectangle(table, grid_half_width, TABLE_WIDTH / GRID_SIZE, 0, 0, FORBIDDEN);
    cocobot_pathfinder_set_rectangle(table, grid_half_width, TABLE_WIDTH / GRID_SIZE, TABLE_LENGTH / GRID_SIZE - grid_half_width, 0, FORBIDDEN);  

    // dune forbidden
    cocobot_pathfinder_set_rectangle(table, grid_half_width, 200/GRID_SIZE, 800/GRID_SIZE - grid_half_width, 0/GRID_SIZE, FORBIDDEN);
    cocobot_pathfinder_set_rectangle(table, grid_half_width, 200/GRID_SIZE, 800/GRID_SIZE + 1, 0/GRID_SIZE, FORBIDDEN);
    cocobot_pathfinder_set_circle(table, 810/GRID_SIZE, 200/GRID_SIZE, (half_width + 10) / GRID_SIZE, FORBIDDEN);
    cocobot_pathfinder_set_rectangle(table, grid_half_width, 200/GRID_SIZE, 2200/GRID_SIZE - grid_half_width, 0/GRID_SIZE, FORBIDDEN);
    cocobot_pathfinder_set_rectangle(table, grid_half_width, 200/GRID_SIZE, 2200/GRID_SIZE + 1, 0/GRID_SIZE, FORBIDDEN);
    cocobot_pathfinder_set_circle(table, 2210/GRID_SIZE, 200/GRID_SIZE, (half_width + 10) / GRID_SIZE, FORBIDDEN);
    
    //Central T forbidden
    cocobot_pathfinder_set_rectangle(table, 1200/GRID_SIZE, grid_half_width, 900/GRID_SIZE, 750/GRID_SIZE - grid_half_width, FORBIDDEN);
    cocobot_pathfinder_set_rectangle(table, 1200/GRID_SIZE, grid_half_width, 900/GRID_SIZE, 750/GRID_SIZE + 1, FORBIDDEN);
    cocobot_pathfinder_set_circle(table, 900/GRID_SIZE, 760/GRID_SIZE, (half_width + 10) / GRID_SIZE, FORBIDDEN);
    cocobot_pathfinder_set_circle(table, 2100/GRID_SIZE, 760/GRID_SIZE, (half_width + 10) / GRID_SIZE, FORBIDDEN);
    cocobot_pathfinder_set_rectangle(table, grid_half_width, 600/GRID_SIZE, 1470/GRID_SIZE - grid_half_width, 750/GRID_SIZE, FORBIDDEN);
    cocobot_pathfinder_set_rectangle(table, grid_half_width, 600/GRID_SIZE, 1470/GRID_SIZE + 1, 750/GRID_SIZE, FORBIDDEN);
    cocobot_pathfinder_set_circle(table, 1500/GRID_SIZE, 1350/GRID_SIZE, (half_width + 25) / GRID_SIZE, FORBIDDEN);
    
    //iles soft_obstacle
    //iles forbidden
    cocobot_pathfinder_set_circle(table, 0/GRID_SIZE, 2000/GRID_SIZE, (250 + half_width)/GRID_SIZE, FORBIDDEN); 
    cocobot_pathfinder_set_circle(table, 3000/GRID_SIZE, 2000/GRID_SIZE, (250 + half_width)/GRID_SIZE, FORBIDDEN); 

    //dune obstacle
    cocobot_pathfinder_set_rectangle(table, 20/GRID_SIZE, 200/GRID_SIZE, 800/GRID_SIZE, 0/GRID_SIZE, OBSTACLE);
    cocobot_pathfinder_set_rectangle(table, 20/GRID_SIZE, 200/GRID_SIZE, 2200/GRID_SIZE, 0/GRID_SIZE, OBSTACLE);

    // central T obstacle
    cocobot_pathfinder_set_rectangle(table, 1200/GRID_SIZE, 20/GRID_SIZE, 900/GRID_SIZE, 750/GRID_SIZE, OBSTACLE);
    cocobot_pathfinder_set_rectangle(table, 60/GRID_SIZE, 600/GRID_SIZE, 1470/GRID_SIZE, 750/GRID_SIZE, OBSTACLE);

    // iles obstacle
    cocobot_pathfinder_set_circle(table, 0/GRID_SIZE, 2000/GRID_SIZE, 250/GRID_SIZE, OBSTACLE); 
    cocobot_pathfinder_set_circle(table, 3000/GRID_SIZE, 2000/GRID_SIZE, 250/GRID_SIZE, OBSTACLE);

}

