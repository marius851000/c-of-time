#include <pmdsky.h>
#include <cot.h>

#include "subs_dungeon_script.h"
#include "subs_extern.h"
#include "script_hook.h"

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

void __attribute__((used)) CustomInteractWithSecretBazaarNpc(struct entity* user, struct entity* shopkeeper) {
    if (!IsMonster(shopkeeper)) {
        InteractWithSecretBazaarNpc(user, shopkeeper);
        return;
    }

    // check if we aren’t already in a secret bazaar
    if (IsSecretBazaar()) {
        InteractWithSecretBazaarNpc(user, shopkeeper);
        return;
    }

    struct monster* monster = shopkeeper->info.monster;
    
    
    char script_name_buffer[0x30];
    snprintf(script_name_buffer, 0x30, "dun_%03d_floor_%02d/npc/%03d", DUNGEON_PTR->id.val, DUNGEON_PTR->floor, monster->statuses.monster_behavior.val);
    RunDungeonScript(script_name_buffer, shopkeeper);
}

__attribute__((used)) void HookDungeonTurn(bool firstTurn) {    
    if (firstTurn) {
        LoadNewFloor();
        char script_name_buffer[0x30];
        snprintf(script_name_buffer, 0x30, "dun_%03d_floor_%02d/enter", DUNGEON_PTR->id.val, DUNGEON_PTR->floor);
        RunDungeonScript(script_name_buffer, NULL);
    }

    struct entity* pc = DUNGEON_PTR->entity_table.header.active_monster_ptrs[0];
    if (EntityIsValid(pc)) {
        COT_LOGFMT("main", "x:%d, y:%d", pc->pos.x, pc->pos.y);
        RunScriptAtPosAsNeeeded(pc->pos.x, pc->pos.y);
    }
    RunFractionalTurn(firstTurn);
}