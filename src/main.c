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

static int CUSTOM_SPRITE_ID = 0;
static struct animation_control ANIMATION_CONTROL;
extern struct animation_control ALERT_ANIMATION_SUB;

__attribute((used)) void TestCustomLoadWAN() {
    CUSTOM_SPRITE_ID = LoadWanTableEntry(WAN_TABLE,"rom0:FONT/alert.wan",0);
    InitAnimationControlWithSet(&ANIMATION_CONTROL);
    SetSpriteIdForAnimationControl(&ANIMATION_CONTROL,CUSTOM_SPRITE_ID);
    SetAnimationForAnimationControl(&ANIMATION_CONTROL,0,0,0x3e4,0xd,0,1,0);
    //ANIMATION_CONTROL.field23_0x38 = 0;
    //ANIMATION_CONTROL.field1_0x2 = ANIMATION_CONTROL.field1_0x2 | 2;

    ANIMATION_CONTROL.field10_0x1c = 100; // x coord
    ANIMATION_CONTROL.field11_0x1e = 100; // y coord
    //ANIMATION_CONTROL.field1_0x2 = ANIMATION_CONTROL.field1_0x2 & 0xfffd;
}

__attribute((used)) void TestCustomRenderWAN() {
    for (int a = 0; a < 10; a++) {
        ANIMATION_CONTROL.field10_0x1c = 100 + a * 5;
        ANIMATION_CONTROL.field11_0x1e = 100 + a * 5;
        RenderAndAdvanceWANAnimation(&ANIMATION_CONTROL);
    }
    //RenderAlert();
}
