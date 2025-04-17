/* !file overlay11 */
OpcodeCheck = 0x022DDDD4;
GetParameterCount = 0x022DDD8C;
ScriptEngineReturnTwo = 0x022E246C;
ScriptMenuRequestDefaultCase = 0x022E60F0;
ScriptMenuRequestFinalize = 0x022E68AC;
ScriptMenuUpdateDefaultCase = 0x022E68F8;
ScriptMenuUpdateFinalize = 0x022E6E58;
IS_BASE_GAME_MENU_FINISHED = 0x02324C9C;

ENGINE_DISPLAY_INFO = 0x022A37AC; # EU: 0x020091c8

# Hook at the start of the frame, when it’s safe to write to the VRAM
FrameHookStart = 0x022e930c; # EU: 0x022e9c4c
FrameHookCallAtEnd = 0x02008f88; # EU: 0x02008f88 (the same)

/* !file overlay29 */
ApplyMoveEffect = 0x0232E864;
ApplyMoveEffectHookAddr = 0x0232F8A4;
ApplyMoveEffectJumpAddr = 0x023326CC;
ApplyItemEffectHookAddr = 0x0231B9D8;
ApplyItemEffectJumpAddr = 0x0231CB14;

/* Add your own symbols here... */

/* !file arm9 */
ShowKeyboardTypeCase3 = 0x02036914;
ShowKeyboardTypeDefaultCase = 0x02036A40;
ShowKeyboardReturn = 0x02036CAC;
PreprocessStringFromIdCallsite = 0x02039400;


ProcessWTEWrapper = 0x0201e12c; #EU: 0x0201e1c8;
DoSomethingOn3dAllocAndClearInput = 0x0201e13c; #EU: 0x0201e1d8;

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

GeomSetTexImageParam = 0x0201e494; # EU: 0x0201e530