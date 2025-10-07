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

void RenderAndAdvanceWANAnimation(struct animation_control*);
void RenderAlert();

static struct animation_control ANIMATION_CONTROL;

__attribute((used)) void TestCustomLoadWAN() {
    //int custom_sprite_id = LoadWanTableEntry(WAN_TABLE,"rom0:FONT/alert.wan",0);
    int custom_sprite_id = LoadWanTableEntryFromPack(WAN_TABLE, 3, 269, 0xf, 0);
    InitAnimationControlWithSet(&ANIMATION_CONTROL);
    SetSpriteIdForAnimationControl(&ANIMATION_CONTROL,custom_sprite_id);
    SetAnimationForAnimationControl(&ANIMATION_CONTROL,0,0,0x3e4,0xd,0,1,0);
    //ANIMATION_CONTROL.field23_0x38 = 0;
    //ANIMATION_CONTROL.field1_0x2 = ANIMATION_CONTROL.field1_0x2 | 2;

    ANIMATION_CONTROL.field10_0x1c = 100; // x coord
    ANIMATION_CONTROL.field11_0x1e = 50; // y coord
    //ANIMATION_CONTROL.field1_0x2 = ANIMATION_CONTROL.field1_0x2 & 0xfffd;
}

static int COUNTER = 0;
static int SPRITE_ID_IN_WAN_TABLE = 0;

__attribute((used)) void TestCustomRenderWAN() {

    if (COUNTER > 0) {
        DeleteWanTableEntry(WAN_TABLE, SPRITE_ID_IN_WAN_TABLE);
    }

    if (COUNTER >= 601) {
        COUNTER = 1;
    } else {
        COUNTER += 2;
    }

    SPRITE_ID_IN_WAN_TABLE = LoadWanTableEntryFromPack(WAN_TABLE, 2, COUNTER-1, 0xf, 0);
    InitAnimationControlWithSet(&ANIMATION_CONTROL);
    SetSpriteIdForAnimationControl(&ANIMATION_CONTROL,SPRITE_ID_IN_WAN_TABLE);
    SetAnimationForAnimationControl(&ANIMATION_CONTROL,0,0,0x3e4,0xd,0,1,0);
    ANIMATION_CONTROL.field10_0x1c = 50;
    ANIMATION_CONTROL.field11_0x1e = 50;
    RenderAndAdvanceWANAnimation(&ANIMATION_CONTROL);

}
