# 基于C语言编写的身体各项指数计算=>BCM模块

**此模块是基于PHP5.6.40版本生成的扩展骨架。**
> 不知道PHP的其他版本调用会不会产生问题，需要自行检测</br>
> 由于公司购买的是别家生产的电路板，在计算数据的时候需要用到别人的算法，但是别人又不愿意公开出来</br>
> 于是打包编译了一个动态库来给我调用，在使用的时候由于调用的是动态库加载，（libbcm.so）</br>
> 需要`make -ldl`来安装编译模块</br>
> `make -ldl`之前需要将so动态库放到系统当中</br>

```shell
# su
# echo /usr/local/lib > /etc/ld.so.conf.d/local.conf
# cp libbcm.so /usr/local/lib
# /sbin/ldconfig
```

> 具体文档地址：[https://iszmxw.github.io/bcm/docs](https://iszmxw.github.io/bcm/docs)

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
