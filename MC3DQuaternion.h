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

#ifndef __MC3DQuaternion__
#define __MC3DQuaternion__

#include "MC3DCommon.h"
#include "MC3DTypes.h"

#ifdef __cplusplus
	extern "C" {
#endif


#pragma mark -
#pragma mark Creating Quaternions
quaternion quaternionMakeWithMat4(mat4 matrix);
quaternion quaternionMakeWithVectors(vec3 vector1, vec3 vector2);
quaternion quaternionMakeWithAxisAndAngle(vec3 axis, GLfloat angle);
quaternion quaternionMakeWithEulerAngles(GLfloat x, GLfloat y, GLfloat z);

#pragma mark -
#pragma mark Interpolation
quaternion quaternionMakeWithNLERP(quaternion *start, quaternion *finish, GLclampf progress);
quaternion quaternionMakeWithSLERP(quaternion *start, quaternion *finish, GLclampf progress);

#pragma mark -
#pragma mark Converting from Quaternions
void quaternionExtractAxisAndAngle(quaternion quat, vec3 *axis, GLfloat *angle);
void quaternionExtractEulerAnglesDegrees(quaternion quat, GLfloat *rotx, GLfloat *roty, GLfloat *rotz);
void quaternionExtractEulerAnglesRadians(quaternion quat, GLfloat *rotx, GLfloat *roty, GLfloat *rotz);

#pragma mark -
#pragma mark Quaternion Calcuations
GLfloat quaternionDotProduct(quaternion *quat1, quaternion *quat2);
GLfloat quaternionMagnitude(quaternion quat);

#pragma mark -
#pragma mark In-Place Operations
void quaternionNormalize(quaternion *quaternion);
void quaternionMultiply(quaternion *quat1, quaternion *quat2);
void quaternionInvert(quaternion  *quat);

#pragma mark -
quaternion quaternionRotate(quaternion first, quaternion second);

#ifdef __cplusplus
}
#endif

#endif
