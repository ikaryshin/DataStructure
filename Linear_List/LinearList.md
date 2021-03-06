#### 线性表

注意是否带动态变化

线性表结构：数组（指针） + 数组（线性表）的长度

- 表的初始化
    - 初始化数组（分配空间）
- 表的删除
    - 将表长设为空
    - 释放数组空间
- 判断表是否为空
    - 判断表长是否为0
- 求表长
    - 返回表长
- 表的遍历
    - 遍历
- 表的清空
    - 将表长设为0
- 寻找元素
    - 搜索线性表
- 插入元素
    - 数组元素的整体移动
    - 注意移动的具体实现
- 删除元素
    - 数组元素的整体移动
    - 注意移动的具体实现


#### 错误点

- 内存分配
    - 可能没有空间
    - 另外，注意malloc, realloc的使用
- 表中数组元素访问的范围
- 注意for loop的各个部分的执行顺序
- 写比较复杂的循环时，一定要画流程图，仔细分析各部分的关系
- 特别是要关注第一个、最后一个这种特殊情况
- 结构体变量作为函数的参数，修改之后的成员值不能返回到主调函数
- 结构体数组作为函数的参数，修改后的元素的成员值能返回到主调函数
- 结构体指针变量作为函数的参数，修改后的结构体成员的值能返回到主调函数
