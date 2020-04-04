#include <FreeRTOS.h>
#include <task.h>
#include <platform.h>
#include <cocobot.h>
#include <stdio.h>
#include "meca.h"

//2020 table data
extern cocobot_pathfinder_table_init_s initTable[];

/**
 * @brief Main task for brain board
 * @param arg   Not used
 */
void run_strategy(void * arg)
{
  (void)arg;

  //DEBUG com.
  vTaskDelay(2000 / portTICK_PERIOD_MS); //wait smecanle start
  while(1)
  {
    cocobot_com_send(COCOBOT_COM_MECA_ACTION_PID, "B", 0); //init

    while(cocobot_position_get_distance() >= 0) {
      vTaskDelay(250 / portTICK_PERIOD_MS); 
      cocobot_com_send(COCOBOT_COM_MECA_ACTION_PID, "B", 2); //front down
      vTaskDelay(250 / portTICK_PERIOD_MS); 
      cocobot_com_send(COCOBOT_COM_MECA_ACTION_PID, "B", 1); //front up
    }

    cocobot_com_send(COCOBOT_COM_MECA_ACTION_PID, "B", 0); //init

    while(cocobot_position_get_distance() < 0) {
      vTaskDelay(250 / portTICK_PERIOD_MS); 
      cocobot_com_send(COCOBOT_COM_MECA_ACTION_PID, "B", 12); //back down
      vTaskDelay(250 / portTICK_PERIOD_MS); 
      cocobot_com_send(COCOBOT_COM_MECA_ACTION_PID, "B", 11); //back up
    }
  }
}


/**
 * @brief Raise the flag before the end of the match
 */
void set_flag_up(void)
{
  cocobot_com_send(COCOBOT_COM_MECA_ACTION_PID, "B", 25); //back up
  cocobot_game_state_add_points_to_score(10);
}



/**
 * @brief Handle packet from Cocoui or other boards if libcocobot didn't want it
 * @param pid   PID of the packet
 * @param data  buffer for packet data
 * @param len   len of packet data
 */
void com_handler(uint16_t pid, uint8_t * data, uint32_t len)
{
  (void)pid;
  (void)data;
  (void)len;
}


int main(void) 
{
  platform_init();

  cocobot_com_init(MCUAL_USART1, 1, 1, com_handler);
  cocobot_position_init(4);
  cocobot_action_scheduler_init();
  cocobot_asserv_init();
  cocobot_trajectory_init(4);
  cocobot_opponent_detection_init(3);
  cocobot_game_state_init(set_flag_up);
  cocobot_pathfinder_init(initTable);
  cocobot_action_scheduler_use_pathfinder(1);
  meca_init();

  //set initial position
  cocobot_position_set_x(0);
  cocobot_position_set_y(0);
  cocobot_position_set_angle(0);

  xTaskCreate(run_strategy, "strat", 600, NULL, 2, NULL );

  vTaskStartScheduler();

  return 0;
}
