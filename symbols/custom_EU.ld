/* !file overlay11 */
OpcodeCheck = 0x022DE714;
GetParameterCount = 0x022DE6CC;
ScriptEngineReturnTwo = 0x022E2DAC;
ScriptMenuRequestDefaultCase = 0x022E6A30;
ScriptMenuRequestFinalize = 0x022E71EC;
ScriptMenuUpdateDefaultCase = 0x022E7238;
ScriptMenuUpdateFinalize = 0x022E7798;
IS_BASE_GAME_MENU_FINISHED = 0x023257DC;

/* !file overlay29 */
ApplyMoveEffect = 0x0232F2A4;
ApplyMoveEffectHookAddr = 0x023302D0;
ApplyMoveEffectJumpAddr = 0x02333110;
ApplyItemEffectHookAddr = 0x0231C408;
ApplyItemEffectJumpAddr = 0x0231D574;

/* Add your own symbols here... */

/* !file overlay29 */
PrintDialogue = 0x0234df04; # is called "DungeonModeMessage?" in my EU Ghidra. Likely a label assigned by me (marius) a long while ago.
YesNoMenuWithStringPtr = 0x0234e0bc;
DungeonSetAnimation = 0x0230525c;
InteractWithSecretBazaarNpcCallsite = 0x022f6584;
DungeonTurnCallsite = 0x022e0458;


/* !file arm9 */
ShowKeyboardTypeCase3 = 0x02036C10;
ShowKeyboardTypeDefaultCase = 0x02036D3C;
ShowKeyboardReturn = 0x02036FA8;
PreprocessStringFromIdCallsite = 0x020396FC;
