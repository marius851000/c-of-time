#include <pmdsky.h>
#include <cot.h>
#include "mesh_render.h"
#include "render_sprite_3d.h"
#include "extern.h"

void RenderLiveActorTest() {
  for (int i = 0; i < 24; i++) {
    struct live_actor* actor = &GROUND_STATE_PTRS.actors->actors[i];
    if (actor->entity.kind != -1 && actor->entity.is_enabled) {
      render_animation_control(&actor->animation.ctrl);
    }
  }
}

extern void FrameHookCallAtEnd();
// On each frame, but only in the overworld (overlay 11)
__attribute__((used)) void OnEachFrame() {
  BG0_A_PRIORITY = 0x3;

  ENGINE_DISPLAY_INFO[0].disable_bg2 = true;
  /*ENGINE_DISPLAY_INFO[0].disable_bg3 = true;*/

  //TestDrawMesh();

  
  initializeCustom3D();

  RenderLiveActorTest();
  
  finaliseCustom3d();

  FrameHookCallAtEnd();
}