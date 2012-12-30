#ifndef GUARD_avatar_h
#define GUARD_avatar_h

#include <allegro5/allegro_tiled.h>

#define MALLOC(x) (x *)al_malloc(sizeof(x))

typedef struct {
    int x, y;
    ALLEGRO_BITMAP *bitmap;
} Avatar;

Avatar* create_avatar(int x, int y, const char* image_path);

int get_width(Avatar *tar);
int get_height(Avatar *tar);

ALLEGRO_MAP_TILE** get_occupied_tile_ids(Avatar *tar, ALLEGRO_MAP_LAYER *layer, ALLEGRO_MAP *map);
// TODO bool is_walkable
void walk(Avatar *tar, int x, int y);
void draw_avatar(Avatar *tar, ALLEGRO_MAP *map, int mx, int my);
void free_avatar(void *data);

#endif
