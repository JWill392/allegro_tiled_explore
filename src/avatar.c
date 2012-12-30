#include "avatar.h"
#include "stdio.h"

Avatar* create_avatar(int x, int y, const char* image_path)
{
	Avatar *tar = MALLOC(Avatar);
	tar->x = x;
	tar->y = y;
	tar->bitmap = al_load_bitmap(image_path);
	
	return tar;
}

int get_width(Avatar *tar)
{
	return al_get_bitmap_width(tar->bitmap);
}
int get_height(Avatar *tar)
{
	return al_get_bitmap_height(tar->bitmap);
}

/*
 * Gets ids of tiles occupied by avatar's four corners.
 * 0 = top-left, 1=top-right, 2=bottom-right, 3=bottom-left
 * If tar is fully within one tile, all four will be the same
 *
 * This array is a shallow copy and must be freed when no longer needed.
 */
ALLEGRO_MAP_TILE** get_occupied_tile_ids(Avatar *tar, ALLEGRO_MAP_LAYER *layer, ALLEGRO_MAP *map)
{
	ALLEGRO_MAP_TILE **ret = (ALLEGRO_MAP_TILE**)al_malloc(sizeof(ALLEGRO_MAP_TILE*) * 4);

	const int tile_width  = al_get_tile_width(map);
	const int tile_height = al_get_tile_height(map);
	
	const int tar_width  = get_width(tar);
	const int tar_height = get_height(tar);

	assert(tar_width  <= (tile_width * 2));
	assert(tar_height <= (tile_height * 2));
	
	ret[0] = al_get_single_tile(map, layer, 
				tar->x					/ tile_width, 
				tar->y					/ tile_height);
	ret[1] = al_get_single_tile(map, layer, 
				(tar->x + tar_width)	/ tile_width, 
				tar->y					/ tile_height);
	ret[2] = al_get_single_tile(map, layer, 
				(tar->x + tar_width)	/ tile_width, 
				(tar->y + tar_height)	/ tile_height);
	ret[3] = al_get_single_tile(map, layer, 
				tar->x					/ tile_width, 
				(tar->y + tar_height)	/ tile_height);
	
	return ret;
}

void walk(Avatar *tar, int x, int y)
{
	tar->x += x;
	tar->y += y;
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
