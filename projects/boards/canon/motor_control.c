#include <platform.h>
#include "motor_control.h"

/**
 * @brief Frequency of pwm outputs in kilohertz
 */
#define MOTOR_CONTROL_PWM_FREQUENCY_kHz 20000


/**
 * @brief Function called on each modification on one of the three sensor input pins
 */
static void motor_control_hall_callback(void)
{
  //get u/v/w hall value
  const unsigned int u_hall = !!platform_gpio_get(PLATFORM_GPIO_UHALL);
  const unsigned int v_hall = !!platform_gpio_get(PLATFORM_GPIO_VHALL);
  const unsigned int w_hall = !!platform_gpio_get(PLATFORM_GPIO_WHALL);

  //TODO !
  (void)u_hall;
  (void)v_hall;
  (void)w_hall;
}


void motor_control_init(void)
{
  //set hall sensor input pins as interrupt source
  platform_gpio_set_interrupt(PLATFORM_GPIO_UHALL, MCUAL_GPIO_BOTH_EDGE, motor_control_hall_callback);
  platform_gpio_set_interrupt(PLATFORM_GPIO_VHALL, MCUAL_GPIO_BOTH_EDGE, motor_control_hall_callback);
  platform_gpio_set_interrupt(PLATFORM_GPIO_WHALL, MCUAL_GPIO_BOTH_EDGE, motor_control_hall_callback);

  //init frequency and duty cycle
  platform_set_frequency(PLATFORM_PWM_U | PLATFORM_PWM_V | PLATFORM_PWM_W, MOTOR_CONTROL_PWM_FREQUENCY_kHz);
  platform_set_duty_cycle(PLATFORM_PWM_U, 0);
  platform_set_duty_cycle(PLATFORM_PWM_V, 0);
  platform_set_duty_cycle(PLATFORM_PWM_W, 0);
}


void motor_control_process_event(uint64_t timestamp_us)
{
  (void)timestamp_us;

  //TODO !
  //[
  platform_gpio_set(PLATFORM_GPIO_UEN | PLATFORM_GPIO_VEN);
  platform_gpio_clear(PLATFORM_GPIO_WEN);
  //]
  //TODO !
}
