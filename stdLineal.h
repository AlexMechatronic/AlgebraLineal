#ifndef _STD_LINEAL
#define _STD_LINEAL 

#include <math.h>

typedef struct QuaternionStruct{
	float w;
	float x;
	float y;
	float z;
} Quaternion;

Quaternion 	opRotation_Q(Quaternion angle, Quaternion position);
Quaternion 	add_Q(Quaternion q1, Quaternion q2);
Quaternion 	sus_Q(Quaternion q1, Quaternion q2); //resta q1 a q1 osea q2-q1
Quaternion 	inv_Q(Quaternion q); //es el conjugado del cuaternion q
Quaternion 	mult_Q(Quaternion q1, Quaternion q2); //es el producto de cuaterniones
Quaternion 	multScal_Q(float scalar, Quaternion q); //multiplicacion escalar
float 		norm_Q(Quaternion q); //obtiene la normal del cuaternion

typedef struct EulerAnglesStruct{
	float roll;     /* rotation around x axis in degrees */
	float pitch;    /* rotation around y axis in degrees */
	float yaw;      /* rotation around z axis in degrees */
} EulerAngles;

EulerAngles getEulerAngles(Quaternion q);
float radiansToDegrees (float radians);

typedef struct VectorStruct{
	float x;
	float y;
	float z;
}Vector;

Vector norm_V(Vector v); //obtiene la normal del vector

float map(dataRaw, in_min, in_max, out_min, out_max);

#endif