#include <pmdsky.h>
#include <cot.h>
#include "mesh_render.h"

extern void FrameHookCallAtEnd();
// On each frame, but only in the overworld (overlay 11)
__attribute__((used)) void OnEachFrame() {
  TestDrawMesh();
  FrameHookCallAtEnd();
}