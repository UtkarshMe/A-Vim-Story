#include <assert.h>

#include "datatypes.h"
#include "action.h"
#include "map.h"
#include "input.h"

void action_make_move(map_t *map, input_key_t key)
{
    point_t point;
    int loop = 1;

    /* check if key's available */

    /* calculate the update */
    point.x = map -> cursor.x;
    point.y = map -> cursor.y;

    while (loop--) {
        switch (key) {
            case 'j':
                point.y += 1;
                break;
            case 'k':
                point.y -= 1;
                break;
            case 'l':
                point.x += 1;
                break;
            case 'h':
                point.x -= 1;
                break;
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                loop = key - '0';
                key = input_get_key();
                break;
        }

        if (!map_is_free(map, point)) {
            break;
        } else {
            map -> cursor.x = point.x;
            map -> cursor.y = point.y;
        }
    }
}
