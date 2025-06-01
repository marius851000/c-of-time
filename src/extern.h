#pragma once

#include <pmdsky.h>
#include <cot.h>

#include "smalllib/camera_info_export.h"

// Store wether some background should be disable, per-screen
struct EngineDisplayInfo {
    bool disable_bg0;
    bool disable_bg1;
    bool disable_bg2;
    bool disable_bg3;
    bool disable_obj;
};
extern struct EngineDisplayInfo ENGINE_DISPLAY_INFO[2];



volatile extern int16_t BG0CNT_A;
volatile extern uint16_t BG0_A_PRIORITY;


// texture loading related functions
void ProcessWTEWrapper(struct wte_handle *wte_ref,undefined4 dest_vram_offset,undefined4 palette_high_byte, undefined4 palette_low_byte);

// camera stuff
extern struct camera_information CAMERA_INFO[2];

// 3d engine stuff
volatile extern int GEOM_COMM_BEGIN_VTXS;
volatile extern int GEOM_COMM_END_VTXS;
volatile extern int GEOM_COMM_VTX_16;
volatile extern int GEOM_COMM_VTX_XY;
volatile extern int GEOM_COMM_MTX_PUSH;
volatile extern int GEOM_COMM_MTX_POP;
volatile extern int GEOM_COMM_MTX_SCALE;
volatile extern int GEOM_COMM_MTX_IDENTITY;
volatile extern int GEOM_COMM_MTX_TRANS;
volatile extern int GEOM_COMM_MTX_MODE;
volatile extern int GEOM_COMM_POLYGON_ATTR;
volatile extern int GEOM_COMM_COLOR;
volatile extern int GEOM_COMM_MTX_LOAD_4x4;
volatile extern int GEOM_COMM_PLTT_BASE;
volatile extern int GEOM_COMM_MTX_MULT_3x3;

// VRAM stuff

volatile extern uint8_t VRAMCNT_B;

// Not really extern, defined in an asm file
// copied from libnds
// Argument 1: a pointer
// Argument 2: a size of datas following the pointer in bytes
// Flush the range of data from the cache
void DC_FlushRange(const void *base, uint32_t size);