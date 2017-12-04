#include <stdio.h>
#include <stdlib.h>
#include <operomnia1/operomnia.h>
#include <operomnia1/draw/draw.h>
#include <operomnia1/error.h>

#include "world_map.h"
#include "draw_time.h"
#include "conf.h"

void home_init( operomnia_data * in_data );

void home_loop( operomnia_data * in_data );

void home_exit( operomnia_data * in_data );

int main( int argc, char ** argv ) {
  //display * main_window = initialize();
  operomnia_data * data = malloc( sizeof *data );
  init_op( data, X_WIDTH,Y_HEIGHT, ANTI_ALIAS, DISP_FLAGS, FPS, BG_COLOR );
  printf( "Hello, world\n" );
  home_init( data );
  bool quit = false;
  while( true ) {
    int events = catch_events( data );
    switch( events ) {
      case -1:
        if( remove( "homepid.txt" ) != 0 ) {
          error( "couldn't remove homepid.txt file", CLOSE );
        }
        quit = true;
        break;
      case 1:
        home_loop(data);
        break;
    }
    if( quit ) {
      break;
    }
  };
  //wait(3);
  home_exit( data );
  exit_op( data );
  return 0;
}

font * time_font;
world_map * map;

void home_init( operomnia_data * in_data ) {
  time_font = load_font( "atwriter.ttf", TIME_SIZE );
  map = get_world_map( in_data );
  //time_font->al_font = al_load_font( "atwriter.ttf",  0, 72 );
}

void home_loop( operomnia_data * in_data ) {
  clear_color( new_color(BG_COLOR) );

  world_map_input( in_data, map );
  draw_world_map( map );

  draw_time( time_font );

  draw_all();
}

void home_exit( operomnia_data * in_data ) {
  destroy_world_map( map );
  destroy_font( time_font );
}
