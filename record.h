#ifndef _RECORD_H_
#define _RECORD_H_

// type defition
typedef struct{
	int id;			//id indicate the existence of information for each.
	// TODO: define your own structure type here
	//name, school_year, RC, gender
	char name[20];
	int year;		//the year when he/she was/is freshman.
	char rc;        //t, j, k, s, p, c      
    //Torrey, Jankiryew, Kuyper, 
    //Sonyangwon, Philadelphos, Carmichael
    char gender;	//male or female (m/f)

} Record;

#endif
