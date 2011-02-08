#include "MC3DVector.h"

#pragma mark -
#pragma mark Normalize
void vec2Normalize(vec2 *vector) {
  GLfloat vecMag = vec2Magnitude(*vector);
  if (vecMag == 0.0) {
    vector->x = 1.f;
    vector->y = 0.f;
    return;
  }
  vector->x /= vecMag;
  vector->y /= vecMag;
}
void vec3Normalize(vec3 *vector) {
  GLfloat vecMag = vec3Magnitude(*vector);
  if ( vecMag == 0.0 )
  {
    vector->x = 1.0;
    vector->y = 0.0;
    vector->z = 0.0;
    return;
  }
  vector->x /= vecMag;
  vector->y /= vecMag;
  vector->z /= vecMag; 
}
void vec4Normalize(vec4 *vector) {
  GLfloat vecMag = vec4Magnitude(*vector);
  if (vecMag == 0.0) {
    vector->x = 1.0;
    vector->y = 0.0;
    vector->z = 0.0;
    vector->w = 1.0;
    return;
  }
  vector->x /= vecMag;
  vector->y /= vecMag;
  vector->z /= vecMag;
  vector->w /= vecMag;
}

#pragma mark -
#pragma mark Comparing Vectors

GLboolean vec2Equal(vec2 vector1, vec2 vector2) {
  if (vector1.x == vector2.x && vector1.y == vector2.y)
    return GL_TRUE;
  return GL_FALSE;
}
GLboolean vec3Equal(vec3 vector1, vec3 vector2) {
  if (vector1.x == vector2.x && vector1.y == vector2.y && vector1.z == vector2.z)
    return GL_TRUE;
  return GL_FALSE;
}
GLboolean vec4Equal(vec4 vector1, vec4 vector2) {
  if (vector1.x == vector2.x && vector1.y == vector2.y && vector1.z == vector2.z && vector1.w == vector2.w)
    return GL_TRUE;
  return GL_FALSE;
}

#pragma mark -
#pragma mark Dot Product

GLfloat vec2DotProduct(vec2 vector1, vec2 vector2) {
  return vector1.x*vector2.x + vector1.y*vector2.y;
}
GLfloat vec3DotProduct(vec3 vector1, vec3 vector2) {
  return vector1.x*vector2.x + vector1.y*vector2.y + vector1.z*vector2.z;
}
GLfloat vec4DotProduct(vec4 vector1, vec4 vector2) {
  return vector1.x*vector2.x + vector1.y*vector2.y + vector1.z*vector2.z + vector1.w*vector2.w;
}

#pragma mark -
#pragma mark Cross Product

vec3 vec3CrossProduct(vec3 vector1, vec3 vector2) {
  vec3 ret;
  ret.x = (vector1.y * vector2.z) - (vector1.z * vector2.y);
  ret.y = (vector1.z * vector2.x) - (vector1.x * vector2.z);
  ret.z = (vector1.x * vector2.y) - (vector1.y * vector2.x);
  return ret; 
}

#pragma mark -
#pragma mark Make With Points

vec2 vec2MakeWithPoints(vec2 start, vec2 end) {
  vec2 ret;
  ret.x = end.x - start.x;
  ret.y = end.y - start.y;
  vec2Normalize(&ret);
  return ret;
}
vec3 vec3MakeWithPoints(vec3 start, vec3 end) {
  vec3 ret;
  ret.x = end.x - start.x;
  ret.y = end.y - start.y;
  ret.z = end.z - start.z;
  vec3Normalize(&ret);
  return ret;
}
vec4 vec4MakeWithPoints(vec4 start, vec4 end) {
  vec4 ret;
  ret.x = end.x - start.x;
  ret.y = end.y - start.y;
  ret.z = end.z - start.z;
  ret.w = end.w - start.w;
  vec4Normalize(&ret);
  return ret;
}
#pragma mark -
#pragma mark Length
GLfloat vec2Length(vec2 vector) {
  return sqrtf(vector.x * vector.x + vector.y + vector.y);
}
GLfloat vec3Length(vec3 vector) {
  return sqrtf(vector.x * vector.x + vector.y + vector.y + vector.z * vector.z); 
}
GLfloat vec4Length(vec4 vector) {
  return sqrtf(vector.x * vector.x + vector.y + vector.y + vector.z * vector.z + vector.w * vector.w); 
}
#pragma mark -
#pragma mark Vector Add

vec2 vec2Add(vec2 vector1, vec2 vector2) {
  vec2 ret;
  ret.x = vector1.x + vector2.x;
  ret.y = vector1.y + vector2.y;
  return ret;
}
vec3 vec3Add(vec3 vector1, vec3 vector2) {
  vec3 ret;
  ret.x = vector1.x + vector2.x;
  ret.y = vector1.y + vector2.y;
  ret.z = vector1.z + vector2.z;
  return ret;
}
vec4 vec4Add(vec4 vector1, vec4 vector2) {
  vec4 ret;
  ret.x = vector1.x + vector2.x;
  ret.y = vector1.y + vector2.y;
  ret.z = vector1.z + vector2.z;
  ret.w = vector1.w + vector2.w;
  return ret;
}
void vec2AddTo(vec2 *vector1, vec2 vector2) {
  vector1->x += vector2.x;
  vector1->y += vector2.y;
}
void vec3AddTo(vec3 *vector1, vec3 vector2) {
  vector1->x += vector2.x;
  vector1->y += vector2.y;
  vector1->z += vector2.z;
}
void vec4AddTo(vec4 *vector1, vec4 vector2) {
  vector1->x += vector2.x;
  vector1->y += vector2.y;
  vector1->z += vector2.z;
  vector1->w += vector2.w;
}

#pragma mark -
#pragma mark Vector Subtract

vec2 vec2Subtract(vec2 vector1, vec2 vector2) {
  vec2 ret;
  ret.x = vector1.x - vector2.x;
  ret.y = vector1.y - vector2.y;
  return ret; 
}
vec3 vec3Subtract(vec3 vector1, vec3 vector2) {
  vec3 ret;
  ret.x = vector1.x - vector2.x;
  ret.y = vector1.y - vector2.y;
  ret.z = vector1.z - vector2.z;
  return ret;
}
vec4 vec4Subtract(vec4 vector1, vec4 vector2) {
  vec4 ret;
  ret.x = vector1.x - vector2.x;
  ret.y = vector1.y - vector2.y;
  ret.z = vector1.z - vector2.z;
  ret.w = vector1.w - vector2.w;
  return ret;
}
void vec2SubtractFrom(vec2 *vector1, vec2 vector2) {
  vector1->x -= vector2.x;
  vector1->y -= vector2.y;
}
void vec3SubtractFrom(vec3 *vector1, vec3 vector2) {
  vector1->x += vector2.x;
  vector1->y += vector2.y;
  vector1->z += vector2.z;
}
void vec4SubtractFrom(vec4 *vector1, vec4 vector2) {
  vector1->x -= vector2.x;
  vector1->y -= vector2.y;
  vector1->z -= vector2.z;
  vector1->w -= vector2.w;
}

#pragma mark -
#pragma mark Vector Multiplication

vec2 vec2Multiply(vec2 vector1, GLfloat scalar) {
  vec2 ret;
  ret.x = vector1.x * scalar;
  ret.y = vector1.y * scalar;
  return ret;
}
vec3 vec3Multiply(vec3 vector1, GLfloat scalar) {
  vec3 ret;
  ret.x = vector1.x * scalar;
  ret.y = vector1.y * scalar;
  ret.z = vector1.z * scalar;
  return ret;
}
vec4 vec4Multiply(vec4 vector1, GLfloat scalar) {
  vec4 ret;
  ret.x = vector1.x * scalar;
  ret.y = vector1.y * scalar;
  ret.z = vector1.z * scalar;
  ret.w = vector1.w * scalar;
  return ret; 
}
void vec2MultiplyBy(vec2 *vector1, GLfloat scalar) {
  vector1->x *= scalar;
  vector1->y *= scalar;
}
void vec3MultiplyBy(vec3 *vector1, GLfloat scalar) {
  vector1->x *= scalar;
  vector1->y *= scalar;
  vector1->z *= scalar;
}
void vecrMultiplyBy(vec4 *vector1, GLfloat scalar) {
  vector1->x *= scalar;
  vector1->y *= scalar;
  vector1->z *= scalar;
  vector1->w *= scalar;
}

#pragma mark -
#pragma mark Vector Division

vec2 vec2Divide(vec2 vector1, GLfloat scalar) {
  vec2 ret;

  if (scalar == 0.f) {
    printf("Attempt to divide by zero, returning origin");
    ret.x = ret.y = 0.f;
  }

  ret.x = vector1.x / scalar;
  ret.y = vector1.y / scalar;
  return ret;
}
vec3 vec3Divide(vec3 vector1, GLfloat scalar) {
  vec3 ret;

  if (scalar == 0.f) {
    printf("Attempt to divide by zero, returning origin");
    ret.x = ret.y = ret.z = 0.f;
  }

  ret.x = vector1.x / scalar;
  ret.y = vector1.y / scalar;
  ret.z = vector1.z / scalar;
  return ret;
}
vec4 vec4Divide(vec4 vector1, GLfloat scalar) {
  vec4 ret;

  if (scalar == 0.f) {
    printf("Attempt to divide by zero, returning origin");
    ret.x = ret.y = ret.z = ret.w = 0.f;
  }

  ret.x = vector1.x / scalar;
  ret.y = vector1.y / scalar;
  ret.z = vector1.z / scalar;
  ret.w = vector1.w / scalar;
  return ret;
}
void vec2DivideBy(vec2 *vector1, GLfloat scalar) {
  if (scalar == 0.f) {
    printf("Attempt to divide by zero, leaving original vector untouched");
    return;
  }
  vector1->x /= scalar;
  vector1->y /= scalar;
}
void vec3DivideBy(vec3 *vector1, GLfloat scalar) {
  if (scalar == 0.f) {
    printf("Attempt to divide by zero, leaving original vector untouched");
    return;
  }
  vector1->x /= scalar;
  vector1->y /= scalar;
  vector1->z /= scalar;
}
void vec4DivideBy(vec4 *vector1, GLfloat scalar) {
  if (scalar == 0.f) {
    printf("Attempt to divide by zero, leaving original vector untouched");
    return;
  }
  vector1->x /= scalar;
  vector1->y /= scalar;
  vector1->z /= scalar;
  vector1->w /= scalar;
}

#pragma mark -
#pragma mark Vector Flipping

void vec2Flip(vec2 *vector) {
  vector->x = -vector->x;
  vector->y = -vector->y; 
}
void vec3Flip(vec3 *vector) {
  vector->x = -vector->x;
  vector->y = -vector->y;
  vector->z = -vector->z;
}
void vec4Flip(vec4 *vector) {
  vector->x = -vector->x;
  vector->y = -vector->y;
  vector->z = -vector->z;
  vector->w = -vector->w;
}

#pragma mark -
#pragma mark Linear Interpolation

vec2 vec2Lerp(vec2 start, vec2 finish, GLclampf amount) {
  vec2 ret;
  ret.x = start.x * (1.f - amount) + finish.x * amount;
  ret.y = start.y * (1.f - amount) + finish.y * amount;
  return ret;
}
vec3 vec3Lerp(vec3 start, vec3 finish, GLclampf amount) {
  vec3 ret;
  ret.x = start.x * (1.f - amount) + finish.x * amount;
  ret.y = start.y * (1.f - amount) + finish.y * amount;
  ret.z = start.z * (1.f - amount) + finish.z * amount;
  return ret;
}
vec4 vec4Lerp(vec4 start, vec4 finish, GLclampf amount) {
  vec4 ret;
  ret.x = start.x * (1.f - amount) + finish.x * amount;
  ret.y = start.y * (1.f - amount) + finish.y * amount;
  ret.z = start.z * (1.f - amount) + finish.z * amount;
  ret.w = start.w * (1.f - amount) + finish.w * amount;
  return ret; 
}

#pragma mark -
#pragma mark Quadratic Ease-In

vec2 vec2EaseIn(vec2 start, vec2 finish, GLclampf amount) {
  return vec2Lerp(start, finish, amount * amount);
}
vec3 vec3EaseIn(vec3 start, vec3 finish, GLclampf amount) {
  return vec3Lerp(start, finish, amount * amount);
}
vec4 vec4EaseIn(vec4 start, vec4 finish, GLclampf amount) {
  return vec4Lerp(start, finish, amount * amount);
}

#pragma mark -
#pragma mark Triple Scalar Product

GLfloat vec3TripleScalarProduct(vec3 vector1, vec3 vector2, vec3 vector3) {
  return 
    (vector1.x * (vector2.y * vector3.z - vector2.z * vector3.y)) +
    (vector1.y * (-vector2.x * vector3.z + vector2.z * vector3.x)) +
    (vector1.z * (vector2.x * vector3.y - vector2.y * vector3.x)) ;
}

