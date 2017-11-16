#include "datatypes.h"
#include "key.h"

boolean unlocked[KEY_MAX_SIZE];

boolean key_unlocked(input_key_t key)
{
    return unlocked[key];
}

void key_lock(input_key_t key)
{
    unlocked[key] = B_FALSE;
}

void key_unlock(input_key_t key)
{
    unlocked[key] = B_TRUE;
}