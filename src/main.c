#include <pmdsky.h>
#include <cot.h>

// Remove the comment in patches/patch.asm to enable this example patch.
// `attribute((used))` is required to prevent the compiler from optimizing out the function
// if it's only used in a patch.
__attribute__((used)) int CustomGetMovePower(struct entity* entity, struct move* move) {
  // Randomize move power
  int rolledPower = RandRange(1, 100);

  // Print the rolled value to the message log
  char messageBuffer[32];
  snprintf(messageBuffer, 32, "Rolled move power %d!", rolledPower);

  LogMessage(entity, messageBuffer, true);

  return rolledPower;
}

// You can add other patches here...

typedef enum PaletteAllocatorPool {
    PALETTE_POOL_FIRST=0 /* Alloc limited to the palette 0x0 */,
    PALETTE_POOL_PARTY=1 /* Alloc limited to 0x1B to 0x1E */,
    PALETTE_POOL_GENERAL=2 /* Alloc limited to 0x1 to 0x14 */
} PaletteAllocatorPool;

void RenderAndAdvanceWANAnimation(struct animation_control*);
void RenderAnimationControl(struct animation_control*);
void SwitchAnimationControlToNextFrame(struct animation_control*);
int PaletteAllocatorFindEmpty(PaletteAllocatorPool param_1);
void PaletteAllocatorMarkAsUsed(int palette_no);
bool AllocateGeneralSpriteMemoryForMonster(uint32_t *out_start,uint32_t *out_size,enum monster_id monster_id,undefined4 param_4, short palette_no);
void MarkSpriteMemoryAsUsedForGeneralMonster(uint32_t start, uint32_t size);

void RenderAlert();


static struct animation_control ANIMATION_CONTROL;

static bool SPRITE_LOADED = false;
// should only be called in dungeon mode, after the palette allocator has been initialised
__attribute((used)) void TestCustomLoadWAN() {
    //int custom_sprite_id = LoadWanTableEntry(WAN_TABLE,"rom0:FONT/alert.wan",0);
    enum monster_id monster_id_to_use = (enum monster_id) 100;
    int custom_sprite_id = LoadWanTableEntryFromPack(WAN_TABLE, 2, monster_id_to_use, 0xf, 0);
    InitAnimationControlWithSet(&ANIMATION_CONTROL);
    SetSpriteIdForAnimationControl(&ANIMATION_CONTROL,custom_sprite_id);
    int palette_to_use = PaletteAllocatorFindEmpty(PALETTE_POOL_GENERAL);
    if (palette_to_use == -1) {
        palette_to_use = 0x1F; // that’s ugly. Let’s hope it just doesn’t happen.
    } else {
        PaletteAllocatorMarkAsUsed(palette_to_use);
    }
    uint32_t sprite_alloc_start = 0;
    uint32_t sprite_alloc_size = 0;
    // Return false on failure. Ignore that for now.
    AllocateGeneralSpriteMemoryForMonster(&sprite_alloc_start, &sprite_alloc_size, monster_id_to_use, 0, palette_to_use);

    SetAnimationForAnimationControl(&ANIMATION_CONTROL,0,0,sprite_alloc_start + 0x62,palette_to_use,0xF,1,0);
    MarkSpriteMemoryAsUsedForGeneralMonster(sprite_alloc_start, sprite_alloc_size);
}

static int SPRITE_ID_IN_WAN_TABLE = 0;

__attribute((used)) void TestCustomRenderWAN() {
    if (!SPRITE_LOADED) {
        TestCustomLoadWAN();
        SPRITE_LOADED = true;
    }
    struct position* cam_pixel_pos = &DUNGEON_PTR->display_data.camera_pixel_pos;
    struct position* cam_tile_pos = &DUNGEON_PTR->display_data.camera_pos;
    for (int x_delta = cam_tile_pos->x - 6; x_delta <= cam_tile_pos->x + 6; x_delta++) {
        for (int y_delta = cam_tile_pos->y - 5; y_delta <= cam_tile_pos->y + 5; y_delta++) {

            if (x_delta % 3 == 0 && y_delta % 3 == 0) {
                ANIMATION_CONTROL.field10_0x1c = 24 * x_delta - cam_pixel_pos->x; // x coord
                ANIMATION_CONTROL.field11_0x1e = 24 * y_delta - cam_pixel_pos->y; // y coord

                RenderAnimationControl(&ANIMATION_CONTROL);
            }

        }
    }
    SwitchAnimationControlToNextFrame(&ANIMATION_CONTROL);
}
