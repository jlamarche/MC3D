#include "MC3DMatrix.h"
#include "MC3DVector.h"

#pragma mark -
#pragma mark Identity Matrix Functions

mat2 mat2Identity() {
  mat2 ret;
  mat2SetIdentity(&ret);
  return ret;
}
mat3 mat3Identity() {
  mat3 ret;
  mat3SetIdentity(&ret);
  return ret;
}
mat4 mat4Identity() {
  mat4 ret;
  mat4SetIdentity(&ret);
  return ret;
}
void mat2SetIdentity(mat2 *matrix) {
  matrix->x.x = 1.f; matrix->x.y = 0.f;
  matrix->y.x = 0.f; matrix->y.y = 1.f;
}
void mat3SetIdentity(mat3 *matrix) {
  matrix->x.x = 1.f; matrix->x.y = 0.f; matrix->x.z = 0.f;
  matrix->y.x = 0.f; matrix->y.y = 1.f; matrix->y.z = 0.f;
  matrix->z.x = 0.f; matrix->z.y = 0.f; matrix->z.z = 1.f;
}
void mat4SetIdentity(mat4 *matrix) {
  matrix->x.x = 1.f; matrix->x.y = 0.f; matrix->x.z = 0.f; matrix->x.w = 0.f;
  matrix->y.x = 0.f; matrix->y.y = 1.f; matrix->y.z = 0.f; matrix->y.w = 0.f;
  matrix->z.x = 0.f; matrix->z.y = 0.f; matrix->z.z = 1.f; matrix->z.w = 0.f;
  matrix->w.x = 0.f; matrix->w.y = 0.f; matrix->w.z = 0.f; matrix->w.w = 1.f;
}

#pragma mark -
#pragma mark Copy

void mat2Copy(const mat2 *src, mat2 *dst) {
  memcpy((void *)dst, (void *)src, sizeof(mat2));
}
void mat3Copy(const mat3 *src, mat3 *dst) {
  memcpy(dst, src, sizeof(mat3));
}
void mat4Copy(const mat4 *src, mat4 *dst) {
  memcpy(dst, src, sizeof(mat4));
}

#pragma mark -
#pragma mark Translation
mat3 mat3CreateTranslate(GLfloat x, GLfloat y) {
  mat3 ret;
  mat3SetTranslate(&ret, x, y);
  return ret;
}
mat4 mat4CreateTranslate(GLfloat x, GLfloat y, GLfloat z) {
  mat4 ret;
  mat4setTranslate(&ret, x, y, z);
  return ret;
}
void mat3SetTranslate(mat3 *matrix, GLfloat x, GLfloat y) {
  matrix->x.x = 1; matrix->x.y = 0; matrix->x.z = 0; 
  matrix->y.x = 0; matrix->y.y = 1; matrix->y.z = 0; 
  matrix->z.x = x; matrix->z.y = y; matrix->z.z = 1; 

}
void mat4setTranslate(mat4 *matrix, GLfloat x, GLfloat y, GLfloat z) {
  matrix->x.x = 1; matrix->x.y = 0; matrix->x.z = 0; matrix->x.w = 0;
  matrix->y.x = 0; matrix->y.y = 1; matrix->y.z = 0; matrix->y.w = 0;
  matrix->z.x = 0; matrix->z.y = 0; matrix->z.z = 1; matrix->z.w = 0;
  matrix->w.x = x; matrix->w.y = y; matrix->w.z = z; matrix->w.w = 1;
}
void mat3Translate(mat3 *matrix, GLfloat x, GLfloat y) {
  mat3 translate = mat3CreateTranslate(x, y);
  mat3 intermediate = mat3Multiply(*matrix, translate);
  mat3Copy(&intermediate, matrix);
}
void mat4Translate(mat4 *matrix, GLfloat x, GLfloat y, GLfloat z) {
  mat4 translate = mat4CreateTranslate(x, y, z);
  mat4 intermediate = mat4Multiply(*matrix, translate);
  mat4Copy(&intermediate, matrix);
}

#pragma mark -
#pragma mark Scaling

mat3 mat3CreateUniformScale(GLfloat amount) {
  mat3 ret;
  mat3SetUniformScale(&ret, amount);
  return ret;
}
mat4 mat4CreateUniformScale(GLfloat amount) {
  mat4 ret;
  mat4SetUniformScale(&ret, amount);
  return ret;
}
mat3 mat3CreateScale(GLfloat x, GLfloat y) {
  mat3 ret;
  mat3SetScale(&ret, x, y);
  return ret;
}
mat4 mat4CreateScale(GLfloat x, GLfloat y, GLfloat z) {
  mat4 ret;
  mat4setScale(&ret, x, y, z);
  return ret;
}
void mat3SetUniformScale(mat3 *matrix, GLfloat amount) {
  matrix->x.x = amount; matrix->x.y =    0.f; matrix->x.z =    0.f; 
  matrix->y.x =    0.f; matrix->y.y = amount; matrix->y.z =    0.f; 
  matrix->z.x =    0.f; matrix->z.y =    0.f; matrix->z.z = amount; 
}
void mat4SetUniformScale(mat4 *matrix, GLfloat amount) {
  matrix->x.x = amount; matrix->x.y =    0.f; matrix->x.z =    0.f; matrix->x.w = 0.f;
  matrix->y.x =    0.f; matrix->y.y = amount; matrix->y.z =    0.f; matrix->y.w = 0.f;
  matrix->z.x =    0.f; matrix->z.y =    0.f; matrix->z.z = amount; matrix->z.w = 0.f;
  matrix->w.x =    0.f; matrix->w.y =    0.f; matrix->w.z =    0.f; matrix->w.w = 1.f;
}
void mat3SetScale(mat3 *matrix, GLfloat x, GLfloat y) {
  matrix->x.x = x; matrix->x.y = 0.f; matrix->x.z = 0.f; 
  matrix->y.x = 0.f; matrix->y.y = y; matrix->y.z = 0.f; 
  matrix->z.x = 0.f; matrix->z.y = 0.f; matrix->z.z = 1.f; 
}
void mat4setScale(mat4 *matrix, GLfloat x, GLfloat y, GLfloat z) {
  matrix->x.x =   x; matrix->x.y = 0.f; matrix->x.z = 0.f; matrix->x.w = 0.f;
  matrix->y.x = 0.f; matrix->y.y =   y; matrix->y.z = 0.f; matrix->y.w = 0.f;
  matrix->z.x = 0.f; matrix->z.y = 0.f; matrix->z.z =   z; matrix->z.w = 0.f;
  matrix->w.x = 0.f; matrix->w.y = 0.f; matrix->w.z = 0.f; matrix->w.w = 1.f;
}
void mat3Scale(mat3 *matrix, GLfloat x, GLfloat y) {
  mat3 scale = mat3CreateScale(x, y);
  mat3 intermediate = mat3Multiply(*matrix, scale);
  mat3Copy(&intermediate, matrix);
}
void mat4Scale(mat4 *matrix, GLfloat x, GLfloat y, GLfloat z) {
  mat4 scale = mat4CreateScale(x, y, z);
  mat4 intermediate = mat4Multiply(*matrix, scale);
  mat4Copy(&intermediate, matrix);
}

#pragma mark -
#pragma mark Rotation

mat3 mat3CreateRotationRadians(GLfloat radians) {
  mat3 ret;
  mat3SetRotationRadians(&ret, radians);
  return ret;
}
mat3 mat3CreateRotationDegrees(GLfloat degrees) {
  mat3 ret;
  mat3SetRotationDegrees(&ret, degrees);
  return ret;
}
mat4 mat4CreateRotationRadians(vec3 vector, GLfloat radians) {
  mat4 ret;
  mat4SetRotationRadians(&ret, vector, radians);
  return ret;
}
mat4 mat4CreateRotationDegrees(vec3 vector, GLfloat degrees) {
  mat4 ret;
  mat4SetRotationDegrees(&ret, vector, degrees);
  return ret;
}
void mat3SetRotationRadians(mat3 *matrix, GLfloat radians) {
  matrix->x.x =  cosf(radians); matrix->x.y = sinf(radians); matrix->x.z = 0.f;
  matrix->y.x = -sinf(radians); matrix->y.y = cosf(radians); matrix->y.z = 0.f;
  matrix->z.x =            0.f; matrix->z.y =           0.f; matrix->z.z = 1.f;       
}
void mat3SetRotationDegrees(mat3 *matrix, GLfloat degrees) {
  mat3SetRotationRadians(matrix, DEGREES_TO_RADIANS(degrees));
}
void mat4SetRotationRadians(mat4 *matrix, vec3 v, GLfloat radians) {
  GLfloat mag = vec3Magnitude(v);
  if (mag == 0.0) {
    v.x = 1.0;
    v.y = 0.0;
    v.z = 0.0;
  }
  else if (mag != 1.0) {
    v.x /= mag;
    v.y /= mag;
    v.z /= mag;
  }
  GLfloat c = cosf(radians);
  GLfloat s = fastSinf(radians);

  matrix->x.x = (v.x * v.x) * (1.f - c) + c;
  matrix->x.y = (v.x * v.y) * (1.f - c) - (v.z * s);
  matrix->x.z = (v.x * v.z) * (1.f - c) + (v.y * s);
  matrix->x.w = 0.f;

  matrix->y.x = (v.y * v.x) * (1.f - c) + (v.z * s);
  matrix->y.y = (v.y * v.y) * (1.f - c) + c;
  matrix->y.z = (v.y * v.z) * (1.f - c) - (v.x * s);
  matrix->y.w = 0.f;

  matrix->z.x = (v.x * v.z) * (1.f - c) - (v.y * s);
  matrix->z.y = (v.y * v.z) * (1.f - c) + (v.x * s);
  matrix->z.z = (v.z * v.z) * (1.f - c) + c;
  matrix->z.w = 0.f;

  matrix->w.x = 0.f;
  matrix->w.y = 0.f;
  matrix->w.z = 0.f;
  matrix->w.w = 1.f;
}
void mat4SetRotationDegrees(mat4 *matrix, vec3 vector, GLfloat degrees) {
  mat4SetRotationRadians(matrix, vector, DEGREES_TO_RADIANS(degrees));
}
void mat3RotateRadians(mat3 *matrix, GLfloat radians) {
  mat3 rotate = mat3CreateRotationRadians(radians);
  mat3 intermediate = mat3Multiply(*matrix, rotate);
  mat3Copy(&intermediate, matrix);
}
void mat3RotateDegrees(mat3 *matrix, GLfloat degrees) {
  mat3 rotate = mat3CreateRotationDegrees(degrees);
  mat3 intermediate = mat3Multiply(*matrix, rotate);
  mat3Copy(&intermediate, matrix);
}
void mat4RotateRadians(mat4 *matrix, vec3 vector, GLfloat radians) {
  mat4 rotate = mat4CreateRotationRadians(vector, radians);
  mat4 intermediate = mat4Multiply(*matrix, rotate);
  mat4Copy(&intermediate, matrix);
}
void mat4RotateDegrees(mat4 *matrix, vec3 vector, GLfloat degrees) {
  mat4 rotate = mat4CreateRotationDegrees(vector, degrees);
  mat4 intermediate = mat4Multiply(*matrix, rotate);
  mat4Copy(&intermediate, matrix);
}

#pragma mark -
#pragma mark Matrix Transpose

mat3 mat3CreateTranspose(mat3 matrix) {
  mat3 ret;
  ret.x.x = matrix.x.x; ret.x.y = matrix.y.x; ret.x.z = matrix.z.x;
  ret.y.x = matrix.x.y; ret.y.y = matrix.y.y; ret.y.z = matrix.z.y;
  ret.z.x = matrix.x.z; ret.z.y = matrix.y.z; ret.z.z = matrix.z.z;
  return ret;
}
mat4 mat4CreateTranspose(mat4 matrix) {
  mat4 ret;
  ret.x.x = matrix.x.x; ret.x.y = matrix.y.x; ret.x.z = matrix.z.x; ret.x.w = matrix.w.x;
  ret.y.x = matrix.x.y; ret.y.y = matrix.y.y; ret.y.z = matrix.z.y; ret.y.w = matrix.w.y;
  ret.z.x = matrix.x.z; ret.z.y = matrix.y.z; ret.z.z = matrix.z.z; ret.z.w = matrix.w.z;
  ret.w.x = matrix.x.w; ret.w.y = matrix.y.w; ret.w.z = matrix.z.w; ret.w.w = matrix.w.w;
  return ret;
}
void mat3Transpose(mat3 *matrix) {
  mat3 intermediate = mat3CreateTranspose(*matrix);
  mat3Copy(&intermediate, matrix);
}
void mat4Transpose(mat4 *matrix) {
  mat4 intermediate = mat4CreateTranspose(*matrix);
  mat4Copy(&intermediate, matrix);
}
void mat4SubMatrx(mat4 mr, mat3 *mb, int i, int j) {
    // Calculates 3x3 sub matrix
  GLfloat *src = (GLfloat *)&mr;
  GLfloat *dst = (GLfloat *)mb;
  int di, dj, si, sj;

  for( di = 0; di < 3; di ++ )  {
    for( dj = 0; dj < 3; dj ++ )  {
      si = di + ( ( di >= i ) ? 1 : 0 );
      sj = dj + ( ( dj >= j ) ? 1 : 0 );
      dst[di * 3 + dj] = src[si * 4 + sj];
    }
  }
}

#pragma mark -
#pragma mark Matrix Transpose

mat4 mat4CreateFrustum(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat near, GLfloat far) {    
  mat4 ret;

  ret.x.x = 2 * near / (right - left); 
  ret.x.y = 0.f; 
  ret.x.z = 0.f; 
  ret.x.w = 0.f;
  ret.y.x = 0.f; 
  ret.y.y = 2 * near / (top - bottom); 
  ret.y.z = 0.f; 
  ret.y.w =  0.f;
  ret.z.x = (right + left) / (right - left); 
  ret.z.y = (top + bottom) / (top - bottom); 
  ret.z.z = - (far + near) / (far - near); 
  ret.z.w = -1.f;
  ret.w.x = 0.f; 
  ret.w.y = 0.f; 
  ret.w.z = -2 * far * near / (far - near); 
  ret.w.w = 0.f;

  return ret;
}
mat4 mat4CreateOrtho(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat near, GLfloat far) {
  mat4 ret;

  ret.x.x = 2 / (right - left);
  ret.x.y = 0.f;
  ret.x.z = 0.f;
  ret.x.w = (right + left) / (right - left);
  ret.y.x = 0.f;
  ret.y.y = 2 / (top - bottom);
  ret.y.z = 0.f;
  ret.y.w = (top + bottom) / (top - bottom);
  ret.z.x = 0.f;
  ret.z.y = 0.f;
  ret.z.z = -2 / (far - near);
  ret.z.w = (far + near) / (far - near);
  ret.w.x = 0.f;
  ret.w.y = 0.f;
  ret.w.z = 0.f;
  ret.w.w = 1.f;

  return ret;
}
mat4 mat4Perspective(GLfloat fov, GLfloat near, GLfloat far, GLfloat aspectRatio) {
  GLfloat size = near * tanf(DEGREES_TO_RADIANS(fov) / 2.0); 
  return mat4CreateFrustum(-size, 
    size,
    -size / aspectRatio,
    size / aspectRatio,
    near,
    far);
}
mat4 mat4LookAt(vec3 position, vec3 target, vec3 up) {
  vec3 z = vec3Subtract(position, target);
  vec3Normalize(&z);
  vec3 x = vec3CrossProduct(up, z);
  vec3Normalize(&x);
  vec3 y = vec3CrossProduct(z, x);
  vec3Normalize(&y);

  mat4 ret;

  ret.x.x = x.x; ret.x.y = x.y; ret.x.z = x.z; ret.x.w = 0.f;
  ret.y.x = y.x; ret.y.y = y.y; ret.y.z = y.z; ret.y.w = 0.f;
  ret.z.x = z.x; ret.z.y = z.y; ret.z.z = z.z; ret.z.w = 0.f;
  ret.w.x = 0.f; ret.w.y = 0.f; ret.w.z = 0.f; ret.w.w = 1.f;

  vec3Flip(&position);
  vec4 position4;
  position4.x = position.x;
  position4.y = position.y;
  position4.z = position.z;
  position4.w = 0.f;
  vec4 positionPrime = mat4MultiplyVec4(ret, position4);
  mat4Transpose(&ret);
  ret.w = positionPrime;

  return ret;
}

#pragma mark -
#pragma mark Quaternion Conversion

mat4 mat4CreateFromQuaternion(quaternion quat) {
  mat4 ret;
  mat4SetFromQuaternion(&ret, quat);
  return ret;
}
void mat4SetFromQuaternion(mat4 *matrix, quaternion quat) {
  matrix->x.x  = (1.0f - (2.0f * ((quat.y * quat.y) + (quat.z * quat.z))));
  matrix->y.x  = (2.0f * ((quat.x * quat.y) - (quat.z * quat.w)));
  matrix->z.x  = (2.0f * ((quat.x * quat.z) + (quat.y * quat.w)));
  matrix->w.x  =  0.0f;
  matrix->x.y  = (2.0f * ((quat.x * quat.y) + (quat.z * quat.w)));
  matrix->y.y  = (1.0f - (2.0f * ((quat.x * quat.x) + (quat.z * quat.z))));
  matrix->z.y  = (2.0f * ((quat.y * quat.z) - (quat.x * quat.w)));
  matrix->w.y  =  0.0f;
  matrix->x.z  = (2.0f * ((quat.x * quat.z) - (quat.y * quat.w)));
  matrix->y.z  = (2.0f * ((quat.y * quat.z) + (quat.x * quat.w)));
  matrix->z.z  = (1.0f - (2.0f * ((quat.x * quat.x) + (quat.y * quat.y))));
  matrix->w.z  =  0.0f;
  matrix->x.w  =  0.0f;
  matrix->y.w  =  0.0f;
  matrix->z.w  =  0.0f;
  matrix->w.w  =  1.0f;
}
