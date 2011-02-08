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


#ifndef __MG3DVector__
#define __MG3DVector__

#include "MC3DCommon.h"
#include "MC3DTypes.h"
#pragma mark -
#pragma mark Inline Methods

#ifdef __cplusplus
	extern "C" {
#endif


// Certain methods that are called often are inlined for performance
static inline GLfloat vec2Magnitude(vec2 vector) {
  return sqrtf((vector.x * vector.x) + (vector.y * vector.y));
}
static inline GLfloat vec3Magnitude(vec3 vector) {
  return sqrtf((vector.x * vector.x) + (vector.y * vector.y) + (vector.z * vector.z)); 
}
static inline GLfloat vec4Magnitude(vec4 vector) {
  return sqrtf((vector.x * vector.x) + (vector.y * vector.y) + (vector.z * vector.z) + (vector.w * vector.w));
}
static inline vec2 vec2Make(GLfloat x, GLfloat y) {
  vec2 ret;
  ret.x = x;
  ret.y = y;
  return ret;
}
static inline vec3 vec3Make(GLfloat x, GLfloat y, GLfloat z) {
  vec3 ret;
  ret.x = x;
  ret.y = y;
  ret.z = z;
  return ret;
}
static inline vec4 vec4Make(GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
  vec4 ret;
  ret.x = x;
  ret.y = y;
  ret.z = z;
  ret.w = w;
  return ret;
}
static inline ivec2 ivec2Make(GLint x, GLint y) {
  ivec2 ret;
  ret.x = x;
  ret.y = y;
  return ret;
}
static inline ivec3 ivec3Make(GLint x, GLint y, GLint z) {
  ivec3 ret;
  ret.x = x;
  ret.y = y;
  ret.z = z;
  return ret;
}
static inline ivec4 ivec4Make(GLint x, GLint y, GLint z, GLint w) {
  ivec4 ret;
  ret.x = x;
  ret.y = y;
  ret.z = z;
  ret.w = w;
  return ret;
}
#pragma mark -
#pragma mark Method Prototypes

// Normalizing a vector (changing magnitude to 1.0 without changing direction)
void vec2Normalize(vec2 *vector);
void vec3Normalize(vec3 *vector);
void vec4Normalize(vec4 *vector);

// Comparing vectors
GLboolean vec2Equal(vec2 vector1, vec2 vector2);
GLboolean vec3Equal(vec3 vector1, vec3 vector2);
GLboolean vec4Equal(vec4 vector1, vec4 vector2);

// Dot Product: http://en.wikipedia.org/wiki/Dot_product
GLfloat vec2DotProduct(vec2 vector1, vec2 vector2);
GLfloat vec3DotProduct(vec3 vector1, vec3 vector3);
GLfloat vec4DotProduct(vec4 vector1, vec4 vector4);

// Cross Product: http://en.wikipedia.org/wiki/Cross_product
vec3 vec3CrossProduct(vec3 vector1, vec3 vector2);

// Creates a vector from two vertices
vec2 vec2MakeWithPoints(vec2 start, vec2 end);
vec3 vec3MakeWithPoints(vec3 start, vec3 end);
vec4 vec4MakeWithPoints(vec4 start, vec4 end);

// Calculating length of vector
GLfloat vec2Length(vec2 vector);
GLfloat vec3Length(vec3 vector);
GLfloat vec4Length(vec4 vector);

// Adds two vectors and returns results
vec2 vec2Add(vec2 vector1, vec2 vector2);
vec3 vec3Add(vec3 vector1, vec3 vector2);
vec4 vec4Add(vec4 vector1, vec4 vector2);

// Adds second vector to first, in place
void vec2AddTo(vec2 *vector1, vec2 vector2);
void vec3AddTo(vec3 *vector1, vec3 vector2);
void vec4AddTo(vec4 *vector1, vec4 vector2);

// Subtracting a vector from another vector and returning the result
vec2 vec2Subtract(vec2 vector1, vec2 vector2);
vec3 vec3Subtract(vec3 vector1, vec3 vector2);
vec4 vec4Subtract(vec4 vector1, vec4 vector2);

// Subracting the second vector from the first, in place
void vec2SubtractFrom(vec2 *vector1, vec2 vector2);
void vec3SubtractFrom(vec3 *vector1, vec3 vector2);
void vec4SubtractFrom(vec4 *vector1, vec4 vector2);

// Multiplying a vector by a scalar and returning the result
vec2 vec2Multiply(vec2 vector1, GLfloat scalar);
vec3 vec3Multiply(vec3 vector1, GLfloat scalar);
vec4 vec4Multiply(vec4 vector1, GLfloat scalar);

// Multiplying a vector by a scalar in place
void vec2MultiplyBy(vec2 *vector1, GLfloat scalar);
void vec3MultiplyBy(vec3 *vector1, GLfloat scalar);
void vecrMultiplyBy(vec4 *vector1, GLfloat scalar);

// Dividing a vector by a scalar and returning the result
vec2 vec2Divide(vec2 vector1, GLfloat scalar);
vec3 vec3Divide(vec3 vector1, GLfloat scalar);
vec4 vec4Divide(vec4 vector1, GLfloat scalar);

// Dividing a vector by a scalar in place
void vec2DivideBy(vec2 *vector1, GLfloat scalar);
void vec3DivideBy(vec3 *vector1, GLfloat scalar);
void vec4DivideBy(vec4 *vector1, GLfloat scalar);

// Flipping a vector so it points in opposite direction
void vec2Flip(vec2 *flip);
void vec3Flip(vec3 *flip);
void vec4Flip(vec4 *flip);

// Linear interpolation between two vectors, returning result, amount is from 0.0 to 1.0
vec2 vec2Lerp(vec2 start, vec2 finish, GLclampf amount);
vec3 vec3Lerp(vec3 start, vec3 finish, GLclampf amount);
vec4 vec4Lerp(vec4 start, vec4 finish, GLclampf amount);

// Ease-in interpolation between two vectors, returning result, amount is from 0.0 to 1.0
vec2 vec2EaseIn(vec2 start, vec2 finish, GLclampf amount);
vec3 vec3EaseIn(vec3 start, vec3 finish, GLclampf amount);
vec4 vec4EaseIn(vec4 start, vec4 finish, GLclampf amount);

// Ease-out interpolation between two vectors, returning result, amount is from 0.0 to 1.0
vec2 vec2EaseOut(vec2 start, vec2 finish, GLclampf amount);
vec3 vec3EaseOut(vec3 start, vec3 finish, GLclampf amount);
vec4 vec4EaseOut(vec4 start, vec4 finish, GLclampf amount);

// Ease-in-out interpolation between two vectors, returning results, amount is from 0.0 to 1.0
vec2 vec2EaseInOut(vec2 start, vec2 finish, GLclampf amount);
vec3 vec3EaseInOut(vec3 start, vec3 finish, GLclampf amount);
vec4 vec4EaseInOut(vec4 start, vec4 finish, GLclampf amount);

// Triple scalar product, used in some physics simulation calculations

GLfloat vec3TripleScalarProduct(vec3 vector1, vec3 vector2, vec3 vector3);
#ifdef __cplusplus
}

#endif

#endif
