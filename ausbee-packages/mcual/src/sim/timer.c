#include <stdlib.h>
#include <mcual.h>

volatile uint32_t cnts[MCUAL_TIMER9 + 1];

void mcual_timer_init(mcual_timer_t timer, int32_t freq_Hz)
{
  (void)timer;
  (void)freq_Hz;
}

void mcual_timer_enable_channel(mcual_timer_t timer, mcual_timer_channel_t channel)
{
  (void)timer;
  (void)channel;
}

void mcual_timer_set_duty_cycle(mcual_timer_t timer, mcual_timer_channel_t channel, uint32_t duty_cycle)
{
  (void)timer;
  (void)channel;
  (void)duty_cycle;
}

uint32_t mcual_timer_get_value(mcual_timer_t timer)
{
  return cnts[timer];
}

uint32_t mcual_timer_get_timer_tick(mcual_timer_t timer)
{
  return 0;
}

void mcual_timer_init_encoder(mcual_timer_t timer)
{
}

void mcual_timer_set_value(mcual_timer_t timer, uint32_t cnt)
{
  cnts[timer] = cnt;
}
