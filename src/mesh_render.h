#ifndef _MESH_RENDER_H
#define _MESH_RENDER_H

#include <pmdsky.h>

void initializeCustom3D();
void finaliseCustom3d();
void sendMesh(struct iovec *command_buffer);
void doXRot(int angle);
void doYRot(int angle);
void doZRot(int angle);
void TestDrawMesh();

#endif