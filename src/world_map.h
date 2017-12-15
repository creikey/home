#ifndef H_WORLD_MAP
#define H_WORLD_MAP

#include <operomnia1/operomnia.h>
#include <operomnia1/draw/draw.h>

typedef struct _world_map {
  image * map_image;
  vector dims;
  vector map_pos;
  vector last_mouse_pos;
  vector scale;
} world_map;

world_map * get_world_map( operomnia_data * in_data );

void world_map_input( operomnia_data * in_data, world_map * in_map );

void draw_world_map( world_map * in_map );

vector find_map_center( world_map * in_map );

void destroy_world_map( world_map * in_map );

#define SCALE_FACT 0.01
#define MAP_PATH "world_pol_2015-1.png"
#define MOUSE_MULTIPLIER new_vector(2,2)

#endif
