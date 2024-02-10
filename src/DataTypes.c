
#include"include/DataTypes.h"
#include<stdio.h>
#include <string.h>

//int compareInt (int a, int b)
//{
//    if (a < b) return -1;
//    if (a > b) return 1;
//    return 0;
//}


COMPARE_DEF_MACRO(float, compareFloat)
COMPARE_DEF_MACRO(int, compareInt)
COMPARE_DEF_MACRO(long, compareLong)
COMPARE_DEF_MACRO(double, compareDouble)
int Datatype_Compare(DataTypes type,const void* v1,const void* v2,unsigned long size){

	switch(type){
		case FLOAT:
			{
				return compareFloat(*(float*)v1, *(float*)v2);
			}
		case DOUBLE:
			{
				return compareDouble(*(double*)v1, *(double*)v2);
			}
		case INT:
			{
				return compareInt(*(int*)v1, *(int*)v2);
			}
		case LONG:
			{
				return compareLong(*(long*)v1, *(long*)v2);
			}
		case STRING:
			{
				return strncmp(v1,v2,size);
			}
		default:
			{
				printf("DATA TYPE NOT SUPPORTED");
				return 0;
			}
	}

}

