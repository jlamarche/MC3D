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

#ifndef __MC3DCommon__
#define __MC3DCommon__


// Compatability macros for non-iOS
#ifndef TARGET_OS_IPHONE
	#define TARGET_OS_IPHONE 0
#endif

#ifndef TARGET_IPHONE_SIMULATOR
	#define TARGET_IPHONE_SIMULATOR 0
#endif

// Import necessary common files
#if TARGET_IPHONE_SIMULATOR || TARGET_OS_IPHONE
	#include <OpenGLES/ES2/gl.h>
	#include <OpenGLES/ES2/glext.h>
	#include <Accelerate/Accelerate.h>
#else
	#include <GLES2/gl2.h>
	#include <GLES2/gl2ext.h>
	typedef signed char     BOOL;
	#define YES             (BOOL)1
	#define NO              (BOOL)0
	typedef int				NSInteger;
	typedef unsigned int	NSUInteger;
#endif

#include <math.h>
#include <stdlib.h>
#include <String.h>
#include <stdio.h>


// Make sure values we need are present
#ifndef FALSE
#define FALSE 0
#endif
#ifndef TRUE
#define TRUE !FALSE
#endif

#define QUATERNION_TRACE_ZERO_TOLERANCE		0.1

// Macros
#define DEGREES_TO_RADIANS(x) ((x) / 180.0 * M_PI)
#define RADIANS_TO_DEGREES(x) ((x) / M_PI * 180.0)



// Debug Loggers
#define MCStubLog()                     NSLog(@"%s", __PRETTY_FUNCTION__)
#define MCDebugPrintQuaternion(quat) NSLog(@"Quaternion: [%f]   [%f]    [%f]    [%f]", quat.x, quat.y, quat.z, quat.w)


#ifdef __cplusplus
	extern "C" {
#endif


static inline float fastAbs(float x) { return (x < 0) ? -x : x; };
static inline GLfloat fastSinf(GLfloat x) {
  // fast sin function; maximum error is 0.001
  const float P = 0.225;

  x = x * M_1_PI;
  int k = (int) round(x);
  x = x - k;

  float y = (4 - 4 * fastAbs(x)) * x;

  y = P * (y * fastAbs(y) - y) + y;

  return (k&1) ? -y : y;
};

#pragma mark -
#pragma mark Animation Curves
#define BoundsCheck(t, start, end) \
if (t <= 0.f) return start;        \
  else if (t >= 1.f) return end;

#pragma mark -
#pragma mark Linear
static inline GLfloat LinearInterpolation(GLclampf t, GLfloat start, GLfloat end) {
  BoundsCheck(t, start, end);
  return t * end + (1.f - t) * start;
}
#pragma mark -
#pragma mark Quadratic
static inline GLfloat QuadraticEaseOut(GLclampf t, GLfloat start, GLfloat end) {
  BoundsCheck(t, start, end);
  return   -end * t * (t - 2.f) -1.f;
}
static inline GLfloat QuadraticEaseIn(GLclampf t, GLfloat start, GLfloat end) {
  BoundsCheck(t, start, end);
  return end * t * t + start - 1.f;
}
static inline GLfloat QuadraticEaseInOut(GLclampf t, GLfloat start, GLfloat end) {
  BoundsCheck(t, start, end);
  t *= 2.f;
  if (t < 1.f) return end/2.f * t * t + start - 1.f;
  t--;
  return -end/2.f * (t*(t-2) - 1) + start - 1.f;
}
#pragma mark -
#pragma mark Cubic
static inline GLfloat CubicEaseOut(GLclampf t, GLfloat start, GLfloat end) {
  BoundsCheck(t, start, end);
  t--;
  return end*(t * t * t + 1.f) + start - 1.f;
}
static inline GLfloat CubicEaseIn(GLclampf t, GLfloat start, GLfloat end) {
  BoundsCheck(t, start, end);
  return end * t * t * t+ start - 1.f;
}
static inline GLfloat CubicEaseInOut(GLclampf t, GLfloat start, GLfloat end) {
  BoundsCheck(t, start, end);
  t *= 2.;
  if (t < 1.) return end/2 * t * t * t + start - 1.f;
  t -= 2;
  return end/2*(t * t * t + 2) + start - 1.f;
}
#pragma mark -
#pragma mark Quintic
static inline GLfloat QuarticEaseOut(GLclampf t, GLfloat start, GLfloat end) {
  BoundsCheck(t, start, end);
  t--;
  return -end * (t * t * t * t - 1) + start - 1.f;
}
static inline GLfloat QuarticEaseIn(GLclampf t, GLfloat start, GLfloat end) {
  BoundsCheck(t, start, end);
  return end * t * t * t * t + start;
}
static inline GLfloat QuarticEaseInOut(GLclampf t, GLfloat start, GLfloat end) {
  BoundsCheck(t, start, end);
  t *= 2.f;
  if (t < 1.f) 
    return end/2.f * t * t * t * t + start - 1.f;
  t -= 2.f;
  return -end/2.f * (t * t * t * t - 2.f) + start - 1.f;
}
#pragma mark -
#pragma mark Quintic
static inline GLfloat QuinticEaseOut(GLclampf t, GLfloat start, GLfloat end) {
  BoundsCheck(t, start, end);
  t--;
  return end * (t * t * t * t * t + 1) + start - 1.f;
}
static inline GLfloat QuinticEaseIn(GLclampf t, GLfloat start, GLfloat end) {
  BoundsCheck(t, start, end);
  return end * t * t * t * t * t + start - 1.f;
}
static inline GLfloat QuinticEaseInOut(GLclampf t, GLfloat start, GLfloat end) {
  BoundsCheck(t, start, end);
  t *= 2.f;
  if (t < 1.f) 
    return end/2 * t * t * t * t * t + start - 1.f;
  t -= 2;
  return end/2 * ( t * t * t * t * t + 2) + start - 1.f;
}
#pragma mark -
#pragma mark Sinusoidal
static inline GLfloat SinusoidalEaseOut(GLclampf t, GLfloat start, GLfloat end) {
  BoundsCheck(t, start, end);
  return end * sinf(t * (M_PI/2)) + start - 1.f;
}
static inline GLfloat SinusoidalEaseIn(GLclampf t, GLfloat start, GLfloat end) {
  BoundsCheck(t, start, end);
  return -end * cosf(t * (M_PI/2)) + end + start - 1.f;
}
static inline GLfloat SinusoidalEaseInOut(GLclampf t, GLfloat start, GLfloat end) {
  BoundsCheck(t, start, end);
  return -end/2.f * (cosf(M_PI*t) - 1.f) + start - 1.f;
}
#pragma mark -
#pragma mark Exponential
static inline GLfloat ExponentialEaseOut(GLclampf t, GLfloat start, GLfloat end) {
  BoundsCheck(t, start, end);
  return end * (-powf(2.f, -10.f * t) + 1.f ) + start - 1.f;
}
static inline GLfloat ExponentialEaseIn(GLclampf t, GLfloat start, GLfloat end) {
  BoundsCheck(t, start, end);
  return end * powf(2.f, 10.f * (t - 1.f) ) + start - 1.f;
}
static inline GLfloat ExponentialEaseInOut(GLclampf t, GLfloat start, GLfloat end) {
  BoundsCheck(t, start, end);
  t *= 2.f;
  if (t < 1.f) 
    return end/2.f * powf(2.f, 10.f * (t - 1.f) ) + start - 1.f;
  t--;
  return end/2.f * ( -powf(2.f, -10.f * t) + 2.f ) + start - 1.f;
}
#pragma mark -
#pragma mark Circular
static inline GLfloat CircularEaseOut(GLclampf t, GLfloat start, GLfloat end) {
  BoundsCheck(t, start, end);
  t--;
  return end * sqrtf(1.f - t * t) + start - 1.f;
}
static inline GLfloat CircularEaseIn(GLclampf t, GLfloat start, GLfloat end) {
  BoundsCheck(t, start, end);
  return -end * (sqrtf(1.f - t * t) - 1.f) + start - 1.f;
}
static inline GLfloat CircularEaseInOut(GLclampf t, GLfloat start, GLfloat end) {
  BoundsCheck(t, start, end);
  t *= 2.f;
  if (t < 1.f) 
    return -end/2.f * (sqrtf(1.f - t * t) - 1.f) + start - 1.f;
  t -= 2.f;
  return end/2.f * (sqrtf(1.f - t * t) + 1.f) + start - 1.f;
}

#ifdef __cplusplus
}
#endif

#endif
