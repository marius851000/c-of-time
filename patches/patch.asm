// Replace the "GetMovePower" function with a custom one.
// Since a branch is inserted at the start of the function, the function is practically
// replaced with our own. The "b" instruction doesn't modify the link register, so
// execution will continue after the call to `GetMovePower` once our function returns.

.nds
.include "symbols.asm"

.open "arm9.bin", arm9_start
    .org WhereVanillaSetBG0APriority
    .area 0x4
        mov r0, r1 ; essentially no-op
    .endarea

    ; This is the function that copy the sprite texture to sprite VRAM normally.
    ; With out modification, it would write to it, but it can’t as it is in texture mode (unlike sprite mode)
    ; I will instead replace the callers
    ; Still, if this function would be executed (without this patch), it would cause a warning in NO$GBA and crash SkyTemple (and likely also an independant desmume)
    .org ExecuteCopyToFlatVRAMCommand
    .area 0x4
        bx r14
    .endarea

    ; Doesn’t appear to be used, at least not often. TODO: if actually used in overworld.
    .org DecodeFragmentByteAssemblyTable
    .area 0x4
        bx r14
    .endarea

    ; This is what actually write to sprite VRAM
    .org CallerToPerformedCopyVRAMForSpriteVRAM
    .area 0x4
        bl PerformAndResetSpriteVRAMCopyCommandReplacedForSprite
    .endarea

    .org FunctionThatWillSetObjs
    .area 0x4
        mov r0, r1 ; basically nop
    .endarea
.close

.open "overlay11.bin", overlay11_start
    .org FrameHookStart
    .area 0x4
        bl OnEachFrame
    .endarea
.close