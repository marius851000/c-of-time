/* !file overlay11 */
OpcodeCheck = 0x022DE714;
GetParameterCount = 0x022DE6CC;
ScriptEngineReturnTwo = 0x022E2DAC;
ScriptMenuRequestDefaultCase = 0x022E6A30;
ScriptMenuRequestFinalize = 0x022E71EC;
ScriptMenuUpdateDefaultCase = 0x022E7238;
ScriptMenuUpdateFinalize = 0x022E7798;
IS_BASE_GAME_MENU_FINISHED = 0x023257DC;

ENGINE_DISPLAY_INFO = 0x022a40ec;

# Hook at the start of the frame, when it’s safe to write to the VRAM
FrameHookStart = 0x022e9c4c;
FrameHookCallAtEnd = 0x02008f88;

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


ProcessWTEWrapper = 0x0201e1c8;
DoSomethingOn3dAllocAndClearInput = 0x0201e1d8;

WhereVanillaSetBG0APriority = 0x02077c24;


/* !file ram */

# 3D Engine stuff (same EU/US/JP)
GEOM_COMM_BEGIN_VTXS = 0x04000500;
GEOM_COMM_END_VTXS = 0x04000504;
GEOM_COMM_VTX_16 = 0x0400048c;
GEOM_COMM_MTX_PUSH = 0x04000444;
GEOM_COMM_MTX_POP = 0x04000448;
GEOM_COMM_MTX_IDENTITY = 0x4000454;
GEOM_COMM_MTX_SCALE = 0x400046C;
GEOM_COMM_MTX_TRANS = 0x4000470;
GEOM_COMM_MTX_MODE = 0x4000440;
GEOM_COMM_POLYGON_ATTR = 0x040004a4;
GEOM_COMM_COLOR = 0x04000480;
GEOM_COMM_MTX_LOAD_4x4 = 0x4000458;
GEOM_COMM_PLTT_BASE = 0x40004AC;
GEOM_COMM_MTX_MULT_3x3 = 0x4000468;

GeomSetTexImageParam = 0x0201e530;

BG0CNT_A = 0x04000008;

BG0_A_PRIORITY = 0x022a410c;