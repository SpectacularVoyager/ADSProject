#pragma once
#include<stdbool.h>
#include <stdio.h>
#include"DataTypes.h"
#define MAX_SIZE 20
#define MAX_STRING_SIZE 50

#define RECORD_SET_X_MACRO(fun,type) \
	void fun(RecordMetaData* metadata,Record* r,int i,type val);

#define RECORD_SET_X_DEF_MACRO(fun,type) \
	void fun(RecordMetaData* metadata,Record* r,int i,type val){\
		void* start=(void*)r;\
		start+=(metadata->offsets[i]);\
		*((type*)start)=val;\
	}\




typedef struct RecordMetaData{
	int n;
	unsigned int offsets[MAX_SIZE];
	unsigned int sizes[MAX_SIZE];
	char key[MAX_SIZE];
	int key_n;
	char sort[MAX_SIZE];
	int sort_n;
	int stride;
	DataTypes types[MAX_SIZE];
	const char* columns[MAX_SIZE];
} RecordMetaData;



typedef struct Record{
	const void* data;
} Record;

int Record_CompareTo(Record* r1,Record* r2);
int Record_EqualTo(Record* r1,Record* r2);

void Record_set(RecordMetaData* metadata,Record* r,int i,const void* data);

const void* Record_get(RecordMetaData* metadata,Record* r,int n);

void Record_print(Record* r,RecordMetaData* metadata);

void RecordMetaData_new(RecordMetaData* rmd,
		unsigned long sizes[],int n,
		char key[],unsigned int key_n,
		char sort[],unsigned int sort_n,
		DataTypes *types,
		const char* columns[MAX_SIZE]
		);

void RecordMetaData_Print(RecordMetaData* rmd);

int RecordMetaData_getIndexFromString(RecordMetaData* metadata,const char* str);

RECORD_SET_X_MACRO(Record_setInt,int)
RECORD_SET_X_MACRO(Record_setFloat,float)
RECORD_SET_X_MACRO(Record_setDouble,double)
RECORD_SET_X_MACRO(Record_setLong,long)

void Record_setString(RecordMetaData* metadata,Record* r,int i,char* val);
