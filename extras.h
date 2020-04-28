#ifndef _EXTRAS_H_
#define _EXTRAS_H_

#include "record.h"

// function prototypes
int defragment(Record[]);
void search_name(Record[]);
void sort_RC(Record[], int);
void sort_year(Record[], int);
void sort_gender(Record[], int);
void sort(Record[]);
void swap(Record*, Record*);
int RCtoNum(char);
void sort(Record[]);
void ratio_gender(Record[]);

#endif
