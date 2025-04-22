#include "render_sprite_3d.h"
#include "extern.h"
#include "smalllib/libnds_videoGL.h"

// from https://gist.github.com/sgsfak/9ba382a0049f6ee885f68621ae86079b
/*
 * The Dan Bernstein popuralized hash..  See
 * https://github.com/pjps/ndjbdns/blob/master/cdb_hash.c#L26 Due to hash
 * collisions it seems to be replaced with "siphash" in n-djbdns, see
 * https://github.com/pjps/ndjbdns/commit/16cb625eccbd68045737729792f09b4945a4b508
 */
uint32_t djb33_hash(const char* s, size_t len)
{
    uint32_t h = 5381;
    while (len--) {
        /* h = 33 * h ^ s[i]; */
        h += (h << 5);  
        h ^= *s++;
    }
    return h;
}

uint32_t hash_32bit(uint32_t to_hash) {
    return djb33_hash((char *) &to_hash, 4);
}

/// both x and y will be shifted by 4 bytes, hence they should not be in the range of about -2^11 to 2^11
uint32_t coord_to_xy32(int32_t x, int32_t y) {
    uint32_t y_upper_part = (((uint32_t) (y << 4)) & 0xFFFF) << 16;
    uint32_t x_lower_part = (((uint32_t) (x << 4)) & 0xFFFF);
    return y_upper_part | x_lower_part;
}

void get_size_from_indices(uint8_t shape_indice, uint8_t size_indice, struct vec2_16* out) {
    switch (shape_indice << 4 | size_indice) {
        case 0x00:
            out->x = 8;
            out->y = 8;
            break;
        case 0x01:
            out->x = 16;
            out->y = 16;
            break;
        case 0x02:
            out->x = 32;
            out->y = 32;
            break;
        case 0x03:
            out->x = 64;
            out->y = 64;
            break;
        case 0x10:
            out->x = 16;
            out->y = 8;
            break;
        case 0x11:
            out->x = 32;
            out->y = 8;
            break;
        case 0x12:
            out->x = 32;
            out->y = 16;
            break;
        case 0x13:
            out->x = 64;
            out->y = 32;
            break;
        case 0x20:
            out->x = 8;
            out->y = 16;
            break;
        case 0x21:
            out->x = 8;
            out->y = 32;
            break;
        case 0x22:
            out->x = 16;
            out->y = 32;
            break;
        case 0x23:
            out->x = 32;
            out->y = 64;
            break;
        default:
            out->x = 1;
            out->y = 1;
            break;
    };
    return;
}

void render_fragment(struct animation_control* anim_ctrl, struct wan_fragment* fragment, uint32_t fragment_pos) {
    struct vec2_16 size;
    get_size_from_indices(fragment->shape_indice, fragment->size_indice, &size);

    // That X part is pretty weird, but it work.
    int16_t offset_x = fragment->offset_x - 256 + anim_ctrl->anim_frame_offset.x;
    int16_t offset_y = fragment->offset_y + anim_ctrl->anim_frame_offset.y;

    uint32_t color = hash_32bit(((uint32_t) anim_ctrl) + fragment_pos);
    // send mesh
    GEOM_COMM_BEGIN_VTXS = 1;

    // ((ushort) (((short) x) << 6) << 16) | ((ushort) ((short) y) << 6);
    GEOM_COMM_COLOR = color;

    GEOM_COMM_VTX_16 = coord_to_xy32(offset_x, offset_y);
    GEOM_COMM_VTX_16 = 0x00000000;

    GEOM_COMM_COLOR = color;
    GEOM_COMM_VTX_XY = coord_to_xy32(offset_x, offset_y + size.y);

    GEOM_COMM_COLOR = color;
    GEOM_COMM_VTX_XY = coord_to_xy32(offset_x + size.x, offset_y + size.y);

    GEOM_COMM_COLOR = color;
    GEOM_COMM_VTX_XY = coord_to_xy32(offset_x + size.x, offset_y);

    GEOM_COMM_END_VTXS = 0;
}

void render_animation_control(struct animation_control* anim_ctrl) {
    /*struct wan_header* wan = GetWanForAnimationControl(anim_ctrl);*/
    if (anim_ctrl->wan_frames == NULL) { // That may be impossible. Replacing by an assertion would likely be appropriate.
        return;
    }

    struct wan_fragment* fragment = anim_ctrl->wan_frames[anim_ctrl->frame_id];

    if (fragment == NULL) {
        return;
    }

    ///////////////////////////////////////
    // Code that apply to all rectangles //
    GEOM_COMM_MTX_IDENTITY = 0;

    GEOM_COMM_MTX_TRANS = (CAMERA_INFO[0].camera_top_left_position.x << 4) + (anim_ctrl->position.x << 4);
    GEOM_COMM_MTX_TRANS = (CAMERA_INFO[0].camera_top_left_position.y << 4) + (anim_ctrl->position.y << 4);
    GEOM_COMM_MTX_TRANS = 0x0;

    GEOM_COMM_MTX_SCALE = (0x1 << 12);
    GEOM_COMM_MTX_SCALE = (0x1 << 12);
    GEOM_COMM_MTX_SCALE = (0x1 << 12);

    GEOM_COMM_POLYGON_ATTR = POLY_ALPHA(31) | POLY_CULL_BACK | POLY_MODULATION;

    GeomSetTexImageParam(0, 0, 0, 0, 0, 0, 0, 0);

    /////////////////////
    // The loop itself //

    //TODO: a check to warn if there is too much iteration of the loop
    uint32_t fragment_pos = 0;
    while (true) {
        render_fragment(anim_ctrl, fragment, fragment_pos);


        if (fragment->is_last) {
            break;
        }
        fragment = fragment + 1;
        fragment_pos++;
    }
}