//
//       ^                     ____________________
//      / \                   |                   |
//     / _ \                  | MartianCraft 3D   |
//    ( (_) )                 | Platform-Agnostic |
//   /|  |  |\                | 3D Foundation     |
//  //|__|__|\\               |___________________|
// (/   (|)   \)
//      \ /    
//       v
//
//    Copyright 2011 Jeff LaMarche & MartianCraft. All rights reserved.
//    http://www.martiancraft.com       jeff@martiancraft.com
//
//    Redistribution and use in source and binary forms, with or without modification, are
//    permitted provided that the following condition is met:
//
//    Redistributions of source code must retain the above copyright notice, this
//    condition and the following disclaimer.
//
//    THIS SOFTWARE IS PROVIDED BY JEFF LAMARCHE & MARTIANCRAFT, LLC AS IS AND ANY EXPRESS OR 
//    IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY 
//    AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL JEFF LAMARCHE & 
//    MARTIANCRAFT, LLC OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, 
//    EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE 
//    GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  
//    AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
//    NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
//    ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef __MC3DTypes__
#define __MC3DTypes__
#include "MC3DCommon.h"

#ifdef __cplusplus
	extern "C" {
#endif

#pragma mark -
#pragma mark Vectors Datatypes
struct vec2 {
  GLfloat x;
  GLfloat y;
};
typedef struct vec2 vec2;
typedef vec2* vec2Ptr;

struct vec3 {
  GLfloat	x;
  GLfloat y;
  GLfloat z;
};
typedef struct vec3 vec3;
typedef vec3* vec3Ptr;

struct vec4 {
  GLfloat x;
  GLfloat y;
  GLfloat z;
  GLfloat w;
};
typedef struct vec4 vec4;
typedef vec4* vec4Ptr;

struct ivec2 {
  GLint x;
  GLint y;
};
typedef struct ivec2 ivec2;
typedef struct ivec2* ivec2Ptr;

struct ivec3 {
  GLint x;
  GLint y;
  GLint z;
};
typedef struct ivec3 ivec3;
typedef struct ivec3* ivec3Ptr;

struct ivec4 {
  GLint x;
  GLint y;
  GLint z;
  GLint w;
};
typedef struct ivec4 ivec4;
typedef struct ivec4* ivec4Ptr;

#pragma mark -
#pragma mark Matrix Datatypes

struct mat2 {
  vec2 x;
  vec2 y;
};
typedef struct mat2 mat2;
typedef mat2* mat2Ptr;

struct mat3 {
  vec3 x;
  vec3 y;
  vec3 z;
};
typedef struct mat3 mat3;
typedef mat3* mat3Ptr;

struct mat4 {
  vec4 x;
  vec4 y;
  vec4 z;
  vec4 w;
};
typedef struct mat4 mat4;
typedef mat4* mat4Ptr;

#pragma mark -
#pragma mark Quaternion Datatypes

struct quaternion {
  GLfloat x;
  GLfloat y;
  GLfloat z;
  GLfloat w;
};
typedef struct quaternion quaternion;
typedef quaternion* quaternionPtr;

#pragma mark -
#pragma mark Texture Coordinates Datatypes

struct texCoord {
  GLfloat     u;
  GLfloat     v;
};
typedef struct texCoord texCoord;
typedef texCoord* texCoordPtr;

#pragma mark -
#pragma mark Bone Datatypes

#pragma mark -
#pragma mark Vertex 
struct vertex {
  vec3 position;
  texCoord texCoord;
};
typedef struct vertex vertex;
typedef vertex* vertexPtr;

#ifdef __cplusplus
}
#endif

#endif
