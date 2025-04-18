#include <pmdsky.h>
#include <cot.h>
#include "mesh_render.h"

extern void FrameHookCallAtEnd();
// On each frame, but only in the overworld (overlay 11)
__attribute__((used)) void OnEachFrame() {
  BG0_A_PRIORITY = 0x3;

  ENGINE_DISPLAY_INFO[0].disable_bg2 = true;
  ENGINE_DISPLAY_INFO[0].disable_bg3 = true;

  TestDrawMesh();
  FrameHookCallAtEnd();
}