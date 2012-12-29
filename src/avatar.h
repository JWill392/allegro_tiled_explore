#ifndef GUARD_avatar_h
#define GUARD_avatar_h

#include <allegro5/allegro_tiled.h>

#define MALLOC(x) (x *)al_malloc(sizeof(x))

typedef struct {
    int x, y;
    ALLEGRO_BITMAP *bitmap;
} Avatar;

Avatar* create_avatar(int x, int y, const char* image_path);
char get_occupied_tile_id(Avatar *tar, ALLEGRO_MAP_LAYER *layer);
// TODO bool is_walkable
bool walk(Avatar *tar, int x, int y);
void draw_avatar(Avatar *tar, ALLEGRO_MAP *map, int mx, int my);
void free_avatar(void *data);

#endif
