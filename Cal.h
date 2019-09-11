#ifndef __CAL_H__
#define __CAL_H__

enum Gender{male,female};

typedef struct
{
	enum Gender	gender;
	float	age;
	float	weight;
	float	height;
	float	resistance;

	float	BFM;
	float	FFM;
	float	TBW;
}Infor;

#endif

