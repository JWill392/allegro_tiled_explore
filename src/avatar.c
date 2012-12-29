#include <allegro5/allegro_tiled.h>
#include <allegro5/allegro_image.h>
#include "avatar.h"

Avatar* create_avatar(int x, int y, const char* image_path)
{
    Avatar *tar = MALLOC(Avatar);
    tar->x = x;
    tar->y = y;
    tar->bitmap = al_load_bitmap(image_path);
    
    return tar;
}

char get_occupied_tile_id(Avatar *tar, ALLEGRO_MAP_LAYER *layer)
{
    return al_get_single_tile_id(layer, tar->x, tar->y);
}

bool walk(Avatar *tar, int x, int y)
{
    tar->x += x;
    tar->y += y;
    
    return true;
}

void draw_avatar(Avatar *tar, ALLEGRO_MAP *map, int mx, int my)
{
    int gx = tar->x - mx;
    int gy = tar->y - my;
    
    al_draw_bitmap(tar->bitmap, gx, gy, 0);
}

void free_avatar(void *data)
{
    Avatar *tar = (Avatar*)data;
    al_destroy_bitmap(tar->bitmap);
    al_free(tar);
}
