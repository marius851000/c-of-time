#include <pmdsky.h>
#include "smalllib/flat_vram_copy_export.h"
#include "extern.h"

extern void ResetCopyToSpriteVRAMOrders(struct SomeFlatVRAMAllocContainer *param_1);

__attribute__((used)) void PerformAndResetSpriteVRAMCopyCommandReplacedForSprite(struct AnotherRenderAllocStuff *ele) {
    struct SomeFlatVRAMAllocContainer* container = ele->sprite_vram_copy_command;

    int back_vramcnt_b = VRAMCNT_B;
    VRAMCNT_B = 0b10000000;

    DebugPrint(2, "Will perform %i loop", container->size);

    for (int i = 0; i < container->size; i++) {
        struct copy_to_obj_vram_order* order = &container->copy_to_sprite_vram_command[i];

        DebugPrint(2, "Would copy from %#08x to %#08x, of size %i", order->src, order->dst, order->len_output);

        //ExecuteCopyToFlatVRAMCommand(order);
    }


    VRAMCNT_B = back_vramcnt_b; // somehow can’t set it to what is in FrameHookCallAtEnd for some reason.


    ResetCopyToSpriteVRAMOrders(container);
}