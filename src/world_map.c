#include <stdio.h>
#include <operomnia1/mouse.h>
#include <operomnia1/draw/draw.h>
#include <operomnia1/draw/image.h>

#include "world_map.h"

image * get_world_map() {
  return load_image( "world_map.png", false, false );
}

void world_map_input( operomnia_data * in_data, image * in_world_map, float * map_scale ) {
  if( get_mouse_buttons(in_data).left_button ) {
    *map_scale += SCALE_FACT;
    scale_image( in_world_map, *map_scale );
  }
  if( get_mouse_buttons(in_data).right_button ) {
    *map_scale -= SCALE_FACT;
    scale_image( in_world_map, *map_scale );
  }
}

void draw_world_map( image * in_image ) {
  draw_image( in_image, new_vector(0,0) );
}

void destroy_world_map( image * in_map ) {
  free_image( in_map );
}
