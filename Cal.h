#ifndef _CAL_H_
#define _CAL_H_

enum Gender{MALE,FEMALE};

typedef struct 
{
	enum Gender gender;
	float age;
	float weight;
	float height;
	float resistance;

    float TBW;     	//总水分重量
    float Protein;	//蛋白质
    float Minerals;	//无机盐
	float BFM;		//脂肪重量
	float FFM;		//去脂体重
	float SM;		//骨骼肌
	float BMC;		//骨矿含量
	float BMI;		//体格指数
	float PBF;  	//体脂肪率
	float PBW;		//体水分率
    float BMR;		//基础代谢
	float VFA;		//内脏脂肪指数 
	float BodyAge;	//身体年龄 
    float TotalScore;//综合评分
    
}Infor;

void BCM_Cal(Infor* person);

#endif