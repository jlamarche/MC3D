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


#ifndef __MC3DMatrix__
#define __MC3DMatrix__

#include "MC3DCommon.h"
#include "MC3DTypes.h"

#ifdef __cplusplus
	extern "C" {
#endif

#pragma mark -
#pragma mark Inline Methods
static inline mat2 mat2Multiply(mat2 m1, mat2 m2) {
  mat2 result;
#if TARGET_IPHONE_SIMULATOR || TARGET_OS_IPHONE
  vDSP_mmul((float *)&m1, 1, (float *)&m2, 1, (float *)&result, 1, 2, 2, 2);
#else
  result.x.x = m1.x.x * m2.x.x + m1.x.y * m2.y.x;
  result.x.y = m1.x.x * m2.x.y + m1.x.y * m2.y.y;
  result.y.x = m1.y.x * m2.x.x + m1.y.y * m2.y.x;
  result.y.y = m1.y.x * m2.x.y + m1.y.y * m2.y.y;
#endif
  return result;
}
static inline mat3 mat3Multiply(mat3 m1, mat3 m2) {
  mat3 result;
#if TARGET_IPHONE_SIMULATOR || TARGET_OS_IPHONE
  vDSP_mmul((float *)&m1, 1, (float *)&m2, 1, (float *)&result, 1, 3, 3, 3);
#else
  result.x.x = m1.x.x * m2.x.x + m1.x.y * m2.y.x + m1.x.z;
  result.x.y = m1.x.x * m2.x.y + m1.x.y * m2.y.y + m1.x.z;
  result.x.z = m1.x.x * m2.x.z + m1.x.y * m2.y.z + m1.x.z;
  result.y.x = m1.y.x * m2.x.x + m1.y.y * m2.y.x + m1.y.z;
  result.y.y = m1.y.x * m2.x.y + m1.y.y * m2.y.y + m1.y.z;
  result.y.z = m1.y.x * m2.x.z + m1.y.y * m2.y.z + m1.y.z;
  result.z.x = m1.z.x * m2.x.x + m1.z.y * m2.y.x + m1.z.z;
  result.z.y = m1.z.x * m2.x.y + m1.z.y * m2.y.y + m1.z.z;
  result.z.z = m1.z.x * m2.x.z + m1.z.y * m2.y.z + m1.z.z;
#endif
  return result;
}
static inline mat4 mat4Multiply(mat4 m1, mat4 m2) {
  mat4 result;
#if TARGET_IPHONE_SIMULATOR || TARGET_OS_IPHONE
  vDSP_mmul((float *)&m1, 1, (float *)&m2, 1, (float *)&result, 1, 4, 4, 4);
#else
    result.x.x = m1.x.x * m2.x.x + m1.x.y * m2.y.x + m1.x.z * m2.z.x + m1.x.w * m2.w.x;
    result.x.y = m1.x.x * m2.x.y + m1.x.y * m2.y.y + m1.x.z * m2.z.y + m1.x.w * m2.w.y;
    result.x.z = m1.x.x * m2.x.z + m1.x.y * m2.y.z + m1.x.z * m2.z.z + m1.x.w * m2.w.z;
    result.x.w = m1.x.x * m2.x.w + m1.x.y * m2.y.w + m1.x.z * m2.z.w + m1.x.w * m2.w.w;
    result.y.x = m1.y.x * m2.x.x + m1.y.y * m2.y.x + m1.y.z * m2.z.x + m1.y.w * m2.w.x;
    result.y.y = m1.y.x * m2.x.y + m1.y.y * m2.y.y + m1.y.z * m2.z.y + m1.y.w * m2.w.y;
    result.y.z = m1.y.x * m2.x.z + m1.y.y * m2.y.z + m1.y.z * m2.z.z + m1.y.w * m2.w.z;
    result.y.w = m1.y.x * m2.x.w + m1.y.y * m2.y.w + m1.y.z * m2.z.w + m1.y.w * m2.w.w;
    result.z.x = m1.z.x * m2.x.x + m1.z.y * m2.y.x + m1.z.z * m2.z.x + m1.z.w * m2.w.x;
    result.z.y = m1.z.x * m2.x.y + m1.z.y * m2.y.y + m1.z.z * m2.z.y + m1.z.w * m2.w.y;
    result.z.z = m1.z.x * m2.x.z + m1.z.y * m2.y.z + m1.z.z * m2.z.z + m1.z.w * m2.w.z;
    result.z.w = m1.z.x * m2.x.w + m1.z.y * m2.y.w + m1.z.z * m2.z.w + m1.z.w * m2.w.w;
    result.w.x = m1.w.x * m2.x.x + m1.w.y * m2.y.x + m1.w.z * m2.z.x + m1.w.w * m2.w.x;
    result.w.y = m1.w.x * m2.x.y + m1.w.y * m2.y.y + m1.w.z * m2.z.y + m1.w.w * m2.w.y;
    result.w.z = m1.w.x * m2.x.z + m1.w.y * m2.y.z + m1.w.z * m2.z.z + m1.w.w * m2.w.z;
    result.w.w = m1.w.x * m2.x.w + m1.w.y * m2.y.w + m1.w.z * m2.z.w + m1.w.w * m2.w.w;
#endif

  return result;
}
static inline vec3 mat4MultiplyVec3(mat4 matrix, vec3 vector) {
  vec3 ret;
  ret.x = matrix.x.x * vector.x + matrix.x.y * vector.y + matrix.x.z * vector.z;
  ret.y = matrix.y.x * vector.x + matrix.y.y * vector.y + matrix.y.z * vector.z;
  ret.z = matrix.z.x * vector.x + matrix.z.y * vector.y + matrix.z.z * vector.z;
  return ret;
}
static inline vec4 mat4MultiplyVec4(mat4 matrix, vec4 vector) {
  vec4 ret;
  ret.x = matrix.x.x * vector.x + matrix.x.y * vector.y + matrix.x.z * vector.z + matrix.x.w * vector.w;
  ret.y = matrix.y.x * vector.x + matrix.y.y * vector.y + matrix.y.z * vector.z + matrix.y.w * vector.w;
  ret.z = matrix.z.x * vector.x + matrix.z.y * vector.y + matrix.z.z * vector.z + matrix.z.w * vector.w;
  ret.w = matrix.w.x * vector.x + matrix.w.y * vector.y + matrix.w.z * vector.z + matrix.w.w * vector.w;
  return ret;
}
#pragma mark -
#pragma mark Function Prototypes


#pragma mark -
#pragma mark Identity Matrix Functions
// Create and set to Identity
mat2 mat2Identity();
mat3 mat3Identity();
mat4 mat4Identity();
void mat2SetIdentity(mat2 *matrix);
void mat3SetIdentity(mat3 *matrix);
void mat4SetIdentity(mat4 *matrix);

#pragma mark -
#pragma mark Copy


// Copy a Matrix
void mat2Copy(const mat2 *src, mat2 *dst);
void mat3Copy(const mat3 *src, mat3 *dst);
void mat4Copy(const mat4 *src, mat4 *dst);

#pragma mark -
#pragma mark Translation

// Create a new translate matrix
mat3 mat3CreateTranslate(GLfloat x, GLfloat y);
mat4 mat4CreateTranslate(GLfloat x, GLfloat y, GLfloat z);

// Set an existing matrix to a translate matrix
void mat3SetTranslate(mat3 *matrix, GLfloat x, GLfloat y);
void mat4setTranslate(mat4 *matrix, GLfloat x, GLfloat y, GLfloat z);

// multiply an existing matrix by a translate matrix, replacing current values with result
void mat3Translate(mat3 *matrix, GLfloat x, GLfloat y);
void mat4Translate(mat4 *matrix, GLfloat x, GLfloat y, GLfloat z);

#pragma mark -
#pragma mark Scaling

// Create a new scaling matrix
mat3 mat3CreateUniformScale(GLfloat amount);
mat4 mat4CreateUniformScale(GLfloat amount);
mat3 mat3CreateScale(GLfloat x, GLfloat y);
mat4 mat4CreateScale(GLfloat x, GLfloat y, GLfloat z);

// Setting an existing matrix to scale
void mat3SetUniformScale(mat3 *matrix, GLfloat amount);
void mat4SetUniformScale(mat4 *matrix, GLfloat amount);
void mat3SetScale(mat3 *matrix, GLfloat x, GLfloat y);
void mat4setScale(mat4 *matrix, GLfloat x, GLfloat y, GLfloat z);

// multiply an existing matrix by a scale matrix, replacing current values with result
void mat3Scale(mat3 *matrix, GLfloat x, GLfloat y);
void mat4Scale(mat4 *matrix, GLfloat x, GLfloat y, GLfloat z);

#pragma mark -
#pragma mark Rotation

// mat3 allows z-axis rotation only, mat4 on an arbitrary vector
mat3 mat3CreateRotationRadians(GLfloat radians);
mat3 mat3CreateRotationDegrees(GLfloat degrees);
mat4 mat4CreateRotationRadians(vec3 vector, GLfloat radians);
mat4 mat4CreateRotationDegrees(vec3 vector, GLfloat degrees);

void mat3SetRotationRadians(mat3 *matrix, GLfloat radians);
void mat3SetRotationDegrees(mat3 *matrix, GLfloat degrees);
void mat4SetRotationRadians(mat4 *matrix, vec3 vector, GLfloat radians);
void mat4SetRotationDegrees(mat4 *matrix, vec3 vector, GLfloat degrees);

void mat3RotateRadians(mat3 *matrix, GLfloat radians);
void mat3RotateDegrees(mat3 *matrix, GLfloat degrees);
void mat4RotateRadians(mat4 *matrix, vec3 vector, GLfloat radians);
void mat4RotateDegrees(mat4 *matrix, vec3 vector, GLfloat degrees);

#pragma mark -
#pragma mark Matrix Transpose

mat3 mat3CreateTranspose(mat3 matrix);
mat4 mat4CreateTranspose(mat4 matrix);
void mat3Transpose(mat3 *matrix);
void mat4Transpose(mat4 *matrix);

#pragma mark -
#pragma mark Projection Matrix Functions

mat4 mat4CreateFrustum(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat near, GLfloat far);
mat4 mat4CreateOrtho(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat near, GLfloat far);
mat4 mat4Perspective(GLfloat fov, GLfloat near, GLfloat far, GLfloat aspectRatio);
mat4 mat4LookAt(vec3 position, vec3 target, vec3 up);

#pragma mark -
#pragma mark Quaternion Conversion
mat4 mat4CreateFromQuaternion(quaternion quat);
void mat4SetFromQuaternion(mat4 *matrix, quaternion quat);

#ifdef __cplusplus
}
#endif

#endif
