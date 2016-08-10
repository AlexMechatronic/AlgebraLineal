#include "stdLineal.h"

/////////////OPERACIONES DE CUATERNIONES/////////////

Quaternion opRotation_Q(Quaternion angle, Quaternion position)
{
	Quaternion qR = mult_Q(mult_Q(angle, position), inv_Q(angle));
	return qR;
}

Quaternion add_Q(Quaternion q1, Quaternion q2)
{
	Quaternion q3;
	q3.w = q1.w + q2.w;
	q3.x = q1.x + q2.x;
	q3.y = q1.y + q2.y;
	q3.z = q1.z + q2.z;
	return q3;
}

Quaternion sus_Q(Quaternion q1, Quaternion q2) //resta q1 a q1 osea q2-q1
{
	Quaternion q3;
	q3.w = q1.w - q2.w;
	q3.x = q1.x - q2.x;
	q3.y = q1.y - q2.y;
	q3.z = q1.z - q2.z;
	return q3;
}

Quaternion inv_Q(Quaternion q) //es el conjugado del cuaternion q
{
	q.x *= -1;
	q.y *= -1;
	q.z *= -1;
	return q;
}
Quaternion mult_Q(Quaternion q1, Quaternion q2) //es el producto de cuaterniones
{
	Quaternion q3;
	q3.w = q1.w*q2.w - q1.x*q2.x - q1.y*q2.y - q1.z*q2.z;
	q3.x = q1.w*q2.x + q1.x*q2.w + q1.y*q2.z - q1.z*q2.y;
	q3.y = q1.w*q2.y - q1.x*q2.z + q1.y*q2.w + q1.z*q2.x;
	q3.z = q1.w*q2.z + q1.x*q2.y - q1.y*q2.x + q1.z*q2.w;
	return q3;
}

Quaternion multScal_Q(float scalar, Quaternion q)
{
	q.w *= scalar;
	q.x *= scalar;
	q.y *= scalar;
	q.z *= scalar;
	return q;
}

float norm_Q(Quaternion q) //obtiene la normal del cuaternion
{
	return sqrt(q.w*q.w + q.x*q.x + q.y*q.y + q.z*q.z);
}
/////////////////OPERACIONES CON ANGULOS DE EULER///////////////
EulerAngles getEulerAngles(Quaternion q)
{
	EulerAngles eulerAngles;
	eulerAngles.roll = radiansToDegrees(atan2(2.0f * (quaternion.y * quaternion.z - quaternion.w * quaternion.x), 2.0f * quaternion.w * quaternion.w - 1.0f + 2.0f * quaternion.z * quaternion.z));
	eulerAngles.pitch = radiansToDegrees(-atan((2.0f * (quaternion.x * quaternion.z + quaternion.w * quaternion.y)) / sqrt(1.0f - pow((2.0f * quaternion.x * quaternion.z + 2.0f * quaternion.w * quaternion.y), 2.0f))));
	eulerAngles.yaw = radiansToDegrees(atan2(2.0f * (quaternion.x * quaternion.y - quaternion.w * quaternion.z), 2.0f * quaternion.w * quaternion.w - 1.0f + 2.0f * quaternion.x * quaternion.x));
	return eulerAngles;
}

float radiansToDegrees (float radians)
{
	return 57.2957795130823f * radians;
}


////////////////////////OPERACIONES CON VECTORES//////////////////
Vector norm_V(Vector v) //obtiene la normal del vector
{
	return sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
}


//////////EXTRA///////
float map(dataRaw, in_min, in_max, out_min, out_max)
{
	return = (dataRaw - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;	
}
