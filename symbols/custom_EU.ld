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
ApplyMoveEffectHookAddr = 0x023302E4;
ApplyMoveEffectJumpAddr = 0x0233310C;
ApplyItemEffectHookAddr = 0x0231C438;
ApplyItemEffectJumpAddr = 0x0231D574;

/* Add your own symbols here... */

/* !file arm9 */
ShowKeyboardTypeCase3 = 0x02036C10;
ShowKeyboardTypeDefaultCase = 0x02036D3C;
ShowKeyboardReturn = 0x02036FA8;
PreprocessStringFromIdCallsite = 0x020396FC;

/* mine */

/* !file arm9 */
InitSomeGraphicStuffHook = 0x02027174;
RenderAndAdvanceWANAnimation = 0x0201cff8;
RenderAnimationControl = 0x0201c660;
SwitchAnimationControlToNextFrame = 0x0201c4f4;
RenderAlert = 0x0202a2dc;
ALERT_ANIMATION_SUB = 0x022ab6bc;

/* !file overlay29 */
ObjectRenderHook = 0x022eaaac;
MaybeRenderObjectAndMonster = 0x022e2194;
PaletteAllocatorMarkAsUsed = 0x022df338;
PaletteAllocatorFindEmpty = 0x022df2a8;
AllocateGeneralSpriteMemoryForMonster = 0x022e2958;
MarkSpriteMemoryAsUsedForGeneralMonster = 0x022e2804;
