#include <stdio.h>
#include <operomnia1/mouse.h>
#include <operomnia1/memory.h>
#include <operomnia1/draw/draw.h>
#include <operomnia1/draw/image.h>

#include "world_map.h"

vector find_map_center( world_map * in_map ) {
  vector map_center;
  map_center.x = ((in_map->dims.x)*(in_map->scale.x))/2;
  map_center.y = ((in_map->dims.y)*(in_map->scale.y))/2;
  combine_vector( &map_center, in_map->map_pos);
  return map_center;
}

world_map * get_world_map( operomnia_data * in_data ) {
  world_map * to_return = malloc (sizeof *to_return);
  to_return->map_image = load_image( MAP_PATH, false, false );
  set_image_pivot_point( to_return->map_image, new_vector(400,400) );
  to_return->map_pos = new_vector(0,0);
  to_return->last_mouse_pos = get_mouse_pos(in_data);
  to_return->scale = new_vector(1,1);
  to_return->dims = get_image_dimensions( to_return->map_image );
  return to_return;
}

void world_map_input( operomnia_data * in_data, world_map * in_map ) {

  vector m_pos = get_mouse_pos(in_data);
  vector mouse_delta = subtract_vectors( m_pos, in_map->last_mouse_pos );
  in_map->last_mouse_pos = m_pos;

  if( is_key_down( in_data, ALLEGRO_KEY_SPACE ) ) {
    in_map->map_pos = add_vectors( multiply_vectors( mouse_delta, MOUSE_MULTIPLIER ), in_map->map_pos );
  }

  if( get_mouse_buttons(in_data).left_button ) {
    //in_map->map_pos = subtract_vectors( in_map->map_pos, new_vector(SCALE_FACT*(in_map->map_pos.x),SCALE_FACT*(in_map->map_pos.y)) );
    //vector scale_movement = v( (SCALE_FACT*in_map->dims.x)/2, (SCALE_FACT*in_map->dims.y)/2 );
    vector prev_center = find_map_center( in_map );
    in_map->scale.x += SCALE_FACT;
    in_map->scale.y += SCALE_FACT;
    vector after_center = find_map_center( in_map );
    vector center_delta = subtract_vectors( after_center, prev_center );
    printf( "Center delta is (%f, %f)\n", center_delta.x, center_delta.y );
    combine_vector( &in_map->map_pos, center_delta );
    //combine_vector( &in_map->map_pos, scale_movement );
  }
  if( get_mouse_buttons(in_data).right_button ) {
    in_map->map_pos = add_vectors( in_map->map_pos, new_vector(SCALE_FACT*in_map->dims.x,SCALE_FACT*in_map->dims.y) );
    in_map->scale.x -= SCALE_FACT;
    in_map->scale.y -= SCALE_FACT;
  }
  scale_image( in_map->map_image, in_map->scale );
}

void draw_world_map( world_map * in_map ) {
  draw_image( in_map->map_image, in_map->map_pos );
}

void destroy_world_map( world_map * in_map ) {
  free_image( in_map->map_image );
  op_free( in_map );
}
