#ifndef DATATYPES_H_PH0MEKHP
#define DATATYPES_H_PH0MEKHP

/* include the generated config file */
#include "config.h"

/* max map size */
#define MAPMAXX 900
#define MAPMAXY 900
#define MAXGEMS 10
#define MAXSTORYLEN 300

/**
 * A type to store boolean values:
 * B_TRUE and B_FALSE
 */
typedef enum { B_FALSE, B_TRUE } boolean;


/**
 * Enum to store the number of items in the menu
 */
enum menu_item {
    MENU_NEW_GAME,
    MENU_HELP,
    MENU_QUIT,
    MENU_SIZE
};


/**
 * Define the input key type
 */
#define KEY_MAX_SIZE 128
typedef int input_key_t;


/**
 * A data structure to store the 2D point pair
 */
typedef struct {
    int x;
    int y;
} point_t;


/**
 * Define the types of tiles in the map
 */
enum map_tile_type {
    TILE_WATER,
    TILE_BORDER,
    TILE_BRICK,
    TILE_GRASS,
    TILE_LETTER,
    TILE_DOOR,
    TILE_GEM,
    TILE_SIZE
};

/**
 * A structure to represent a tile on the map
 */
typedef struct {
    enum map_tile_type type;
    char value;
} map_tile_t;


/**
 * Define a type for storing color
 */
typedef enum {
    COL_BLK_BLK,                /* read as color - black on black */
    COL_WHI_WHI,
    COL_RED_RED,
    COL_GRN_GRN,
    COL_BLU_BLU,
    COL_BLK_WHI,
    COL_BLK_BLU,
    COL_YEL_YEL,
    COL_WHI_BLU,
} color_t;


/**
 * A data structure to store the map
 */
typedef struct {
    void *handle;
    point_t size;
    point_t cursor;
    int real_x;
    map_tile_t *data;
    int gems_left;
    int chars_left;
    char *story;
} map_t;


/**
 * Stores the all the map description. To be used in map files
 */
typedef struct {
    point_t size;
    point_t cursor;
    point_t exit;
    char story[MAXSTORYLEN];
    struct {
        int count;
        point_t data[MAXGEMS];
    } gems;
    char data[MAPMAXY][MAPMAXX];
} mapfile_data_t;


/**
 * Store the game status
 */
typedef struct {
    int score;
} game_status_t;


/**
 * A datastructure to store the game details
 */
typedef struct {
    int level;
    game_status_t status;
} game_t;

#endif /* end of include guard: DATATYPES_H_PH0MEKHP */
