#include <include/generated/autoconf.h>
#ifdef CONFIG_LIBCOCOBOT_ASSERV

#include <FreeRTOS.h>
#include <task.h>
#include <cocobot.h>
#include <platform.h>
#include <stdio.h>
#include <stdarg.h>

//LCD pixel memory
static uint8_t framebuffer[504];
static char print_buffer[32];

//from https://github.com/andygock/glcd/blob/master/fonts/font5x7.h (BSD licence)
static const char Font5x7[] = {
  0x00, 0x00, 0x00, 0x00, 0x00,// (space)
  0x00, 0x00, 0x5F, 0x00, 0x00,// !
  0x00, 0x07, 0x00, 0x07, 0x00,// "
  0x14, 0x7F, 0x14, 0x7F, 0x14,// #
  0x24, 0x2A, 0x7F, 0x2A, 0x12,// $
  0x23, 0x13, 0x08, 0x64, 0x62,// %
  0x36, 0x49, 0x55, 0x22, 0x50,// &
  0x00, 0x05, 0x03, 0x00, 0x00,// '
  0x00, 0x1C, 0x22, 0x41, 0x00,// (
  0x00, 0x41, 0x22, 0x1C, 0x00,// )
  0x08, 0x2A, 0x1C, 0x2A, 0x08,// *
  0x08, 0x08, 0x3E, 0x08, 0x08,// +
  0x00, 0x50, 0x30, 0x00, 0x00,// ,
  0x08, 0x08, 0x08, 0x08, 0x08,// -
  0x00, 0x60, 0x60, 0x00, 0x00,// .
  0x20, 0x10, 0x08, 0x04, 0x02,// /
  0x3E, 0x51, 0x49, 0x45, 0x3E,// 0
  0x00, 0x42, 0x7F, 0x40, 0x00,// 1
  0x42, 0x61, 0x51, 0x49, 0x46,// 2
  0x21, 0x41, 0x45, 0x4B, 0x31,// 3
  0x18, 0x14, 0x12, 0x7F, 0x10,// 4
  0x27, 0x45, 0x45, 0x45, 0x39,// 5
  0x3C, 0x4A, 0x49, 0x49, 0x30,// 6
  0x01, 0x71, 0x09, 0x05, 0x03,// 7
  0x36, 0x49, 0x49, 0x49, 0x36,// 8
  0x06, 0x49, 0x49, 0x29, 0x1E,// 9
  0x00, 0x36, 0x36, 0x00, 0x00,// :
  0x00, 0x56, 0x36, 0x00, 0x00,// ;
  0x00, 0x08, 0x14, 0x22, 0x41,// <
  0x14, 0x14, 0x14, 0x14, 0x14,// =
  0x41, 0x22, 0x14, 0x08, 0x00,// >
  0x02, 0x01, 0x51, 0x09, 0x06,// ?
  0x32, 0x49, 0x79, 0x41, 0x3E,// @
  0x7E, 0x11, 0x11, 0x11, 0x7E,// A
  0x7F, 0x49, 0x49, 0x49, 0x36,// B
  0x3E, 0x41, 0x41, 0x41, 0x22,// C
  0x7F, 0x41, 0x41, 0x22, 0x1C,// D
  0x7F, 0x49, 0x49, 0x49, 0x41,// E
  0x7F, 0x09, 0x09, 0x01, 0x01,// F
  0x3E, 0x41, 0x41, 0x51, 0x32,// G
  0x7F, 0x08, 0x08, 0x08, 0x7F,// H
  0x00, 0x41, 0x7F, 0x41, 0x00,// I
  0x20, 0x40, 0x41, 0x3F, 0x01,// J
  0x7F, 0x08, 0x14, 0x22, 0x41,// K
  0x7F, 0x40, 0x40, 0x40, 0x40,// L
  0x7F, 0x02, 0x04, 0x02, 0x7F,// M
  0x7F, 0x04, 0x08, 0x10, 0x7F,// N
  0x3E, 0x41, 0x41, 0x41, 0x3E,// O
  0x7F, 0x09, 0x09, 0x09, 0x06,// P
  0x3E, 0x41, 0x51, 0x21, 0x5E,// Q
  0x7F, 0x09, 0x19, 0x29, 0x46,// R
  0x46, 0x49, 0x49, 0x49, 0x31,// S
  0x01, 0x01, 0x7F, 0x01, 0x01,// T
  0x3F, 0x40, 0x40, 0x40, 0x3F,// U
  0x1F, 0x20, 0x40, 0x20, 0x1F,// V
  0x7F, 0x20, 0x18, 0x20, 0x7F,// W
  0x63, 0x14, 0x08, 0x14, 0x63,// X
  0x03, 0x04, 0x78, 0x04, 0x03,// Y
  0x61, 0x51, 0x49, 0x45, 0x43,// Z
  0x00, 0x00, 0x7F, 0x41, 0x41,// [
  0x02, 0x04, 0x08, 0x10, 0x20,// "\"
  0x41, 0x41, 0x7F, 0x00, 0x00,// ]
  0x04, 0x02, 0x01, 0x02, 0x04,// ^
  0x40, 0x40, 0x40, 0x40, 0x40,// _
  0x00, 0x01, 0x02, 0x04, 0x00,// `
  0x20, 0x54, 0x54, 0x54, 0x78,// a
  0x7F, 0x48, 0x44, 0x44, 0x38,// b
  0x38, 0x44, 0x44, 0x44, 0x20,// c
  0x38, 0x44, 0x44, 0x48, 0x7F,// d
  0x38, 0x54, 0x54, 0x54, 0x18,// e
  0x08, 0x7E, 0x09, 0x01, 0x02,// f
  0x08, 0x14, 0x54, 0x54, 0x3C,// g
  0x7F, 0x08, 0x04, 0x04, 0x78,// h
  0x00, 0x44, 0x7D, 0x40, 0x00,// i
  0x20, 0x40, 0x44, 0x3D, 0x00,// j
  0x00, 0x7F, 0x10, 0x28, 0x44,// k
  0x00, 0x41, 0x7F, 0x40, 0x00,// l
  0x7C, 0x04, 0x18, 0x04, 0x78,// m
  0x7C, 0x08, 0x04, 0x04, 0x78,// n
  0x38, 0x44, 0x44, 0x44, 0x38,// o
  0x7C, 0x14, 0x14, 0x14, 0x08,// p
  0x08, 0x14, 0x14, 0x18, 0x7C,// q
  0x7C, 0x08, 0x04, 0x04, 0x08,// r
  0x48, 0x54, 0x54, 0x54, 0x20,// s
  0x04, 0x3F, 0x44, 0x40, 0x20,// t
  0x3C, 0x40, 0x40, 0x20, 0x7C,// u
  0x1C, 0x20, 0x40, 0x20, 0x1C,// v
  0x3C, 0x40, 0x30, 0x40, 0x3C,// w
  0x44, 0x28, 0x10, 0x28, 0x44,// x
  0x0C, 0x50, 0x50, 0x50, 0x3C,// y
  0x44, 0x64, 0x54, 0x4C, 0x44,// z
  0x00, 0x08, 0x36, 0x41, 0x00,// {
  0x00, 0x00, 0x7F, 0x00, 0x00,// |
  0x00, 0x41, 0x36, 0x08, 0x00,// }
  0x08, 0x08, 0x2A, 0x1C, 0x08,// ->
  0x08, 0x1C, 0x2A, 0x08, 0x08 // <-
};

//send lcd system command
static void cocobot_lcd_send_command(uint8_t data)
{
  //set command output
  platform_gpio_clear(PLATFORM_GPIO_ALARM0);

  //send data (SPI)
  platform_spi_slave_select(PLATFORM_SPI_CS0_SELECT);
  platform_spi_slave_transfert(data);
  platform_spi_slave_select(PLATFORM_SPI_CS_UNSELECT);
}

void cocobot_lcd_render(void)
{
  //set x=0 y=0
  cocobot_lcd_send_command(0x80);
  cocobot_lcd_send_command(0x40);

  //send the whole framebuffer to lcd (SPI)
  platform_gpio_set(PLATFORM_GPIO_ALARM0);
  platform_spi_slave_select(PLATFORM_SPI_CS0_SELECT);
  for(unsigned int i = 0; i < sizeof(framebuffer); i += 1)
  {
    platform_spi_slave_transfert(framebuffer[i]);
  }
  platform_spi_slave_select(PLATFORM_SPI_CS_UNSELECT);
}

void cocobot_lcd_clear(void)
{
  //set all LCD memory to 0x00 (white)
  for(unsigned int i = 0; i < sizeof(framebuffer); i += 1)
  {
    framebuffer[i] = 0x00;
  }
}

void cocobot_lcd_pixel(uint16_t xpos, uint16_t ypos, uint8_t value)
{
  //prevent buffer overflow
  if(xpos >= 84)
  {
    return;
  }
  if(ypos >= 48)
  {
    return;
  }

  if(value)
  {
    //set pixel (black)
    framebuffer[84 * (ypos / 8) + xpos] |= (1 << (ypos % 8));
  }
  else
  {
    //clear pixel (white)
    framebuffer[84 * (ypos / 8) + xpos] &= ~(1 << (ypos % 8));
  }
}

void cocobot_lcd_print(int xpos, int ypos, const char * fmt, ...)
{
  va_list ap;

  va_start(ap, fmt);
  vsnprintf(print_buffer, sizeof(print_buffer), fmt, ap);
  va_end(ap);

  char * buffer = print_buffer;

  while(*buffer != 0)
  {
    //prevent buffer overflow
    if(*buffer > 127)
    {
      *buffer = '?';
    }
    if(*buffer < 32)
    {
      *buffer = '?';
    }

    //process character columns and rows
    for (int i = 0; i < 5; i++)
    {
      uint8_t b = Font5x7[(*buffer - 32) * 5 + i];
      for (uint8_t j = 0; j < 7; j++)
      {
        if (b & (1 << j))
        {
          cocobot_lcd_pixel(xpos + i, ypos + j, 1);
        }
        else
        {
          cocobot_lcd_pixel(xpos + i, ypos + j, 0);
        }
      }
    }

    xpos += 6;
    buffer += 1;
  }
}

void cocobot_lcd_draw_line(int x0, int y0, int x1, int y1)
{
  //algorithm need x1 < x0. variables are swapped if needed
  if(x1 < x0)
  {
    int y3 = y0;
    y0 = y1;
    y1 = y3;

    int x3 = x0;
    x0 = x1;
    x1 = x3;
  }

  //if line is not an exception (prevent div by 0)
  if(x0 != x1)
  {
    //find line parameters
    float p = ((float)(y0 - y1)) / ((float)(x0 - x1));
    float m = ((float)y0) - ((float)x0) * p;

    //draw pixels
    for(int i = x0; i <= x1; i += 1)
    {
      cocobot_lcd_pixel(i, i * p + m, 1);
    }
    cocobot_lcd_pixel(x1, y1, 1);
  }
  else
  {
    //handle special case (vertical line)
    for(int i = y0; i <= y1; i += 1)
    {
      cocobot_lcd_pixel(x0, i, 1);
    }
  }
}

void cocobot_lcd_init(void)
{
  //use alarm as LCD DATA/COMMAND pin
  platform_gpio_set_direction(PLATFORM_GPIO_ALARM0, MCUAL_GPIO_OUTPUT);

  //initialize LCD
  cocobot_lcd_send_command(0x21);
  cocobot_lcd_send_command(0xB0);
  cocobot_lcd_send_command(0x04);
  cocobot_lcd_send_command(0x12);
  cocobot_lcd_send_command(0x20);
  cocobot_lcd_send_command(0x0C);

  //reset LCD memory and render it
  cocobot_lcd_clear();
  cocobot_lcd_render();
}
#endif
