#include "MC3DQuaternion.h"
#include "MC3DTypes.h"
#include "MC3DMatrix.h"
#include "MC3DVector.h"

#pragma mark -
#pragma mark Creating Quaternions
quaternion quaternionMakeWithMat4(mat4 matrix)  {
  quaternion quat;
  GLfloat trace, s;

    // Trace of diagonal
  trace = matrix.x.x + matrix.y.y + matrix.z.z;
  if (trace > 0.0f)
  {
    s = sqrtf(trace + 1.0f);
    quat.w = s * 0.5f;
    s = 0.5f / s;

    quat.x = (matrix.y.z - matrix.z.y) * s;
    quat.y = (matrix.z.x - matrix.x.z) * s;
    quat.z = (matrix.x.y - matrix.y.x) * s;
  }
  else
  {
    NSInteger biggest;
    enum      {AA,EE,II}; // LLVM doesn't like "I" as an enumeration, so substituting II for I.
    if (matrix.x.x > matrix.y.y)
      if (matrix.z.z > matrix.x.x)
      biggest = II;	
    else
      biggest = AA;
    else
      if (matrix.z.z > matrix.x.x)
      biggest = II;
    else
      biggest = EE;

    switch (biggest)
    {
      case AA:
      s = sqrtf(matrix.x.x - (matrix.y.y + matrix.z.z) + 1.0f);
      if (s > QUATERNION_TRACE_ZERO_TOLERANCE)
      {
        quat.x = s * 0.5f;
        s = 0.5f / s;
        quat.w = (matrix.y.z - matrix.z.y) * s;
        quat.y = (matrix.y.x + matrix.x.y) * s;
        quat.z = (matrix.z.x + matrix.x.z) * s;
        break;
      }
      s = sqrtf(matrix.z.z - (matrix.x.x + matrix.y.y) + 1.0f);
      if (s > QUATERNION_TRACE_ZERO_TOLERANCE)
      {
        quat.z = s * 0.5f;
        s = 0.5f / s;
        quat.w = (matrix.x.y - matrix.y.x) * s;
        quat.x = (matrix.x.z + matrix.z.x) * s;
        quat.y = (matrix.y.z + matrix.z.y) * s;
        break;
      }
      s = sqrtf(matrix.y.y - (matrix.z.z + matrix.x.x) + 1.0f);
      if (s > QUATERNION_TRACE_ZERO_TOLERANCE)
      {
        quat.y = s * 0.5f;
        s = 0.5f / s;
        quat.w = (matrix.z.x - matrix.x.z) * s;
        quat.z = (matrix.z.y + matrix.y.z) * s;
        quat.x = (matrix.x.y + matrix.y.x) * s;
        break;
      }
      break;

      case EE:
      s = sqrtf(matrix.y.y - (matrix.z.z + matrix.x.x) + 1.0f);
      if (s > QUATERNION_TRACE_ZERO_TOLERANCE)
      {
        quat.y = s * 0.5f;
        s = 0.5f / s;
        quat.w = (matrix.z.x - matrix.x.z) * s;
        quat.z = (matrix.z.y + matrix.y.z) * s;
        quat.x = (matrix.x.y + matrix.y.x) * s;
        break;
      }
      s = sqrtf(matrix.z.z - (matrix.x.x + matrix.y.y) + 1.0f);
      if (s > QUATERNION_TRACE_ZERO_TOLERANCE)
      {
        quat.z = s * 0.5f;
        s = 0.5f / s;
        quat.w = (matrix.x.y - matrix.y.x) * s;
        quat.x = (matrix.x.z + matrix.z.x) * s;
        quat.y = (matrix.y.z + matrix.z.y) * s;
        break;
      }
      s = sqrtf(matrix.x.x - (matrix.y.y + matrix.z.z) + 1.0f);
      if (s > QUATERNION_TRACE_ZERO_TOLERANCE)
      {
        quat.x = s * 0.5f;
        s = 0.5f / s;
        quat.w = (matrix.y.z - matrix.z.y) * s;
        quat.y = (matrix.y.x + matrix.x.y) * s;
        quat.z = (matrix.z.x + matrix.x.z) * s;
        break;
      }
      break;

      case II:
      s = sqrtf(matrix.z.z - (matrix.x.x + matrix.y.y) + 1.0f);
      if (s > QUATERNION_TRACE_ZERO_TOLERANCE)
      {
        quat.z = s * 0.5f;
        s = 0.5f / s;
        quat.w = (matrix.x.y - matrix.y.x) * s;
        quat.x = (matrix.x.z + matrix.z.x) * s;
        quat.y = (matrix.y.z + matrix.z.y) * s;
        break;
      }
      s = sqrtf(matrix.x.x - (matrix.y.y + matrix.z.z) + 1.0f);
      if (s > QUATERNION_TRACE_ZERO_TOLERANCE)
      {
        quat.x = s * 0.5f;
        s = 0.5f / s;
        quat.w = (matrix.y.z - matrix.z.y) * s;
        quat.y = (matrix.y.x + matrix.x.y) * s;
        quat.z = (matrix.z.x + matrix.x.z) * s;
        break;
      }
      s = sqrtf(matrix.y.y - (matrix.z.z + matrix.x.x) + 1.0f);
      if (s > QUATERNION_TRACE_ZERO_TOLERANCE)
      {
        quat.y = s * 0.5f;
        s = 0.5f / s;
        quat.w = (matrix.z.x - matrix.x.z) * s;
        quat.z = (matrix.z.y + matrix.y.z) * s;
        quat.x = (matrix.x.y + matrix.y.x) * s;
        break;
      }
      break;

      default:
      break;
    }
  } 
  return quat;
}
quaternion quaternionMakeWithVectors(vec3 vector1, vec3 vector2) {
  if (vec3Equal(vector1, vector2))
    return quaternionMakeWithAxisAndAngle(vector1, M_PI);

  vec3 c = vec3CrossProduct(vector1, vector2);
  GLfloat d = vec3DotProduct(vector1, vector2);
  GLfloat s = sqrtf((1.f + d) * 2.f);

  quaternion ret;
  ret.x = c.x / s;
  ret.y = c.y / s;
  ret.z = c.z / s;
  ret.w = s / 2.f;

  return ret;
}
quaternion quaternionMakeWithAxisAndAngle(vec3 axis, GLfloat angle)  {
  quaternion quat;
  GLfloat sinAngle;

  angle *= 0.5f;
  vec3Normalize(&axis);
  sinAngle = sinf(angle);
  quat.x = (axis.x * sinAngle);
  quat.y = (axis.y * sinAngle);
  quat.z = (axis.z * sinAngle);
  quat.w = cos(angle);

  return quat;
}
quaternion quaternionMakeWithEulerAngles(GLfloat x, GLfloat y, GLfloat z) {
  vec3 vx = vec3Make(1.f, 0.f, 0.f);
  vec3 vy = vec3Make(0.f, 1.f, 0.f);
  vec3 vz = vec3Make(0.f, 0.f, 1.f);

  quaternion qx = quaternionMakeWithAxisAndAngle(vx, x);
  quaternion qy = quaternionMakeWithAxisAndAngle(vy, y);
  quaternion qz = quaternionMakeWithAxisAndAngle(vz, z);

  quaternionMultiply(&qx, &qy );
  quaternionMultiply(&qx, &qz );
  return qx;
}

#pragma mark -
#pragma mark Interpolation

quaternion quaternionMakeWithSLERP(quaternion *start, quaternion *finish, GLclampf progress) {
  GLfloat startWeight, finishWeight, difference;
  quaternion ret;

  difference = ((start->x * finish->x) + (start->y * finish->y) + (start->z * finish->z) + (start->w * finish->w));
  if ((1.f - fabs(difference)) > .01f)  {
    GLfloat theta, oneOverSinTheta;

    theta = acosf(fabsf(difference));
    oneOverSinTheta = (1.f / sinf(theta));
    startWeight = (sinf(theta * (1.f - progress)) * oneOverSinTheta);
    finishWeight = (sinf(theta * progress) * oneOverSinTheta);
    if (difference < 0.f) 
      startWeight = -startWeight;
  } else  {
    startWeight = (1.f - progress);
    finishWeight = progress;
  }
  ret.x = (start->x * startWeight) + (finish->x * finishWeight);
  ret.y = (start->y * startWeight) + (finish->y * finishWeight);
  ret.z = (start->z * startWeight) + (finish->z * finishWeight);
  ret.w = (start->w * startWeight) + (finish->w * finishWeight);
  quaternionNormalize(&ret);

  return ret;
}
quaternion quaternionMakeWithNLERP(quaternion *start, quaternion *finish, GLclampf progress) {
  quaternion ret;
  GLfloat inverseProgress = 1.0f - progress;
  ret.x = (start->x * inverseProgress) + (finish->x * progress);     
  ret.y = (start->y * inverseProgress) + (finish->y * progress);
  ret.z = (start->z * inverseProgress) + (finish->z * progress);
  ret.w = (start->w * inverseProgress) + (finish->w * progress);
  quaternionNormalize(&ret);
  return ret;
}

#pragma mark -
#pragma mark Converting from Quaternions

void quaternionExtractAxisAndAngle(quaternion quat, vec3 *axis, GLfloat *angle)  {
  GLfloat s;
  quaternionNormalize(&quat);
  s = sqrtf(1.0f - (quat.w * quat.w));

  if (fabs(s) < 0.0005f) s = 1.0f;

  if (axis != NULL)  {
    axis->x = (quat.x / s);
    axis->y = (quat.y / s);
    axis->z = (quat.z / s);
  }

  if (angle != NULL) 
    *angle = (acosf(quat.w) * 2.0f);
}
void quaternionExtractEulerAnglesDegrees(quaternion quat, GLfloat *rotx, GLfloat *roty, GLfloat *rotz) {
  quaternionExtractEulerAnglesRadians(quat, rotx, roty, rotz);
  *rotx = RADIANS_TO_DEGREES(*rotx);
  *roty = RADIANS_TO_DEGREES(*roty);
  *rotz = RADIANS_TO_DEGREES(*rotz);
}
void quaternionExtractEulerAnglesRadians(quaternion quat, GLfloat *rotx, GLfloat *roty, GLfloat *rotz) {
    // Using doubles for intermediate calculations to avoid precision loss problems and rounding errors
  double sqw;
  double sqx;
  double sqy;
  double sqz;

  sqw = quat.w * quat.w;
  sqx = quat.x * quat.x;
  sqy = quat.y * quat.y;
  sqz = quat.z * quat.z;

  *rotx = (double)atan2(2.0 * ( quat.y * quat.z + quat.x * quat.w ) , ( -sqx - sqy + sqz + sqw ));
  *roty = (double)asin(-2.0 * ( quat.x * quat.z - quat.y * quat.w ));
  *rotz = (double)atan2(2.0 * ( quat.x * quat.y + quat.z * quat.w ) , (  sqx - sqy - sqz + sqw ));
}
#pragma mark -
#pragma mark Quaternion Calcuations

GLfloat quaternionDotProduct(quaternion *quat1, quaternion *quat2) {
  return quat1->x * quat2->x + quat2->y * quat2->y + quat1->z * quat2->z + quat1->w * quat2->w;
}
GLfloat quaternionMagnitude(quaternion quat) {
  return sqrtf( (quat.w * quat.w) + 
    (quat.x * quat.x) + 
    (quat.y * quat.y) + 
    (quat.z * quat.z) );
}

#pragma mark -
#pragma mark In-Place Operations

void quaternionMultiply(quaternion *quat1, quaternion *quat2)  {
  vec3 v1, v2, cp;
  GLfloat angle;

  v1.x = quat1->x;
  v1.y = quat1->y;
  v1.z = quat1->z;
  v2.x = quat2->x;
  v2.y = quat2->y;
  v2.z = quat2->z;
  angle = (quat1->w * quat2->w) - vec3DotProduct(v1, v2);

  cp = vec3CrossProduct(v1, v2);
  v1.x *= quat2->w;
  v1.y *= quat2->w;
  v1.z *= quat2->w;
  v2.x *= quat1->w;
  v2.y *= quat1->w;
  v2.z *= quat1->w;

  quat1->x = v1.x + v2.x + cp.x;
  quat1->y = v1.y + v2.y + cp.y;
  quat1->z = v1.z + v2.z + cp.z;
  quat1->w = angle;
}
void quaternionNormalize(quaternion *quaternion)  {
  GLfloat magnitude;

  magnitude = sqrtf((quaternion->x * quaternion->x) +
    (quaternion->y * quaternion->y) +
    (quaternion->z * quaternion->z) +
    (quaternion->w * quaternion->w));

  quaternion->x /= magnitude;
  quaternion->y /= magnitude;
  quaternion->z /= magnitude;
  quaternion->w /= magnitude;
}
void quaternionInvert(quaternion *quat)  {
  GLfloat length = 1.0f / ((quat->x * quat->x) +
    (quat->y * quat->y) +
    (quat->z * quat->z) +
    (quat->w * quat->w));
  quat->x *= -length;
  quat->y *= -length;
  quat->z *= -length;
  quat->w *= length;
}

#pragma mark -

quaternion quaternionRotate(quaternion first, quaternion second) {
  quaternion ret;
  ret.w = first.w * second.w - first.x * second.x - first.y * second.y - first.z * second.z;
  ret.x = first.w * second.x + first.x * second.w + first.y * second.z - first.z * second.y;
  ret.y = first.w * second.y + first.y * second.w + first.z * second.x - first.x * second.z;
  ret.z = first.w * second.z + first.z * second.w + first.x * second.y - first.y * second.x;
  quaternionNormalize(&ret);
  return ret;
}
