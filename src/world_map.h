#ifndef H_WORLD_MAP
#define H_WORLD_MAP

#include <operomnia1/draw/draw.h>

image * get_world_map();

void world_map_input( operomnia_data * in_data, image * in_world_map, float * map_scale );

void draw_world_map( image * in_image );

void destroy_world_map( image * in_map );

#define SCALE_FACT 0.05

#endif
