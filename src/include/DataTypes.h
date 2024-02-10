#pragma once

typedef enum DataTypes{
	FLOAT,
	DOUBLE,
	INT,
	LONG,
	STRING
} DataTypes;

int Datatype_Compare(DataTypes type,const void* v1,const void* v2,unsigned long size);

int compareInt (int a, int b);
#define COMPARE_DEF_MACRO(type,name) int name (type a,type b){if(a<b)return -1;if(a>b)return 1;return 0;}
#define COMPARE_MACRO(type,name) int name (type a,type b);


COMPARE_MACRO(float, compareFloat)
COMPARE_MACRO(int, compareInt)
COMPARE_MACRO(long, compareLong)
COMPARE_MACRO(double, compareDouble)
