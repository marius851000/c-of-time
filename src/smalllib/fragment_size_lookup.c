#include "fragment_size_lookup.h"

void get_size_from_indices(uint8_t shape_indice, uint8_t size_indice, struct vec2_16* out) {
    get_size_tex_indices_from_sprite_indices(shape_indice, size_indice, out);
    out->x = 8 << out->x;
    out->y = 8 << out->y;
}

void get_size_tex_indices_from_sprite_indices(uint8_t shape_indice, uint8_t size_indice, struct vec2_16* out) {
    switch (shape_indice << 4 | size_indice) {
        case 0x00:
            out->x = 0;
            out->y = 0;
            break;
        case 0x01:
            out->x = 1;
            out->y = 1;
            break;
        case 0x02:
            out->x = 2;
            out->y = 2;
            break;
        case 0x03:
            out->x = 3;
            out->y = 3;
            break;
        case 0x10:
            out->x = 1;
            out->y = 0;
            break;
        case 0x11:
            out->x = 2;
            out->y = 0;
            break;
        case 0x12:
            out->x = 2;
            out->y = 1;
            break;
        case 0x13:
            out->x = 3;
            out->y = 2;
            break;
        case 0x20:
            out->x = 0;
            out->y = 1;
            break;
        case 0x21:
            out->x = 0;
            out->y = 2;
            break;
        case 0x22:
            out->x = 1;
            out->y = 2;
            break;
        case 0x23:
            out->x = 2;
            out->y = 3;
            break;
        default:
            out->x = 0;
            out->y = 0;
            break;
    };
}