#include <stdio.h>
#include <time.h>
#include <operomnia1/operomnia.h>
#include <operomnia1/draw/draw.h>
#include <operomnia1/draw/text.h>

#include "draw_time.h"

void draw_time( font * in_font ) {
  time_t rawtime;
  struct tm * timeinfo;
  time( &rawtime );
  timeinfo = localtime( &rawtime );
  //draw_text( time_font, TIME_COLOR, new_vector(100,100), 0, "t");
  //al_draw_text( in_font->al_font, TIME_COLOR, 100, 100, 0, "test" );
  //draw_text( in_font, TIME_COLOR, new_vector(100,100), 0, "t");
  char * to_print = asctime( timeinfo );
  draw_rectangle_filled( new_vector(0,0), new_vector(get_text_width(in_font, to_print),get_font_height(in_font)+20), new_color(200,200,200));
  draw_textf( in_font, TIME_COLOR, new_vector(10,10), 0, "%s", to_print);
}
