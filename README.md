# 基于C语言编写的身体各项指数计算=>BCM模块

**此模块是基于PHP5.6版本生成的扩展骨架。**
> 不知道PHP的其他版本调用会不会产生问题，需要自行检测</br>
> 由于公司购买的是别家生产的电路板，在测量数据的时候需要用到别人的算法，但是别人又不愿意公开出来
于是打包编译了一个动态库来给我调用，在使用的时候由于调用的是动态库加载，（libbcm.so）
需要make -ldl来安装编译模块

**该动态库可以计算如下。**

```c
float TBW;      //总水分重量
float Protein;  //蛋白质
float Minerals; //无机盐
float BFM;      //脂肪重量
float FFM;      //去脂体重
float SM;       //骨骼肌
float BMC;      //骨矿含量
float BMI;      //体格指数
float PBF;      //体脂肪率
float PBW;      //体水分率
float BMR;      //基础代谢
float VFA;      //内脏脂肪指数
float BodyAge;  //身体年龄
float TotalScore;//综合评分
```
