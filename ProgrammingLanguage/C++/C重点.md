[toc]



# C重点

#### 1. 关键字

- typedef定义变量

  ```c++
  typedef int b; // 把b定义为int
  typedef int b[5]; // 把b定义为int[5]
  ```

#### 2. 结构体和类

 - 结构体初始化和**内存对齐**,结构体本质上就是内存

   ```c++
   struct data
   {
       /* data */
       char a; //占用4 (填充3)
       int b[2]={3,5}; // 占用2*4
       // 空格占用4,使c对齐到8
       double c=-8; // 占用8
       char d; // 占用8
   } x[2] = {{'a', {1, 2}, 3, 'd'}, {'a', {1, 2}, 3, 'd'}};
   ```

   

#### 3. 内存控制和指针

- static关键字定义的变量不会保存在stack中

- **系统调用后必须确认return value**

- malloc后必须memset为0

- 指针和数组

  用模式匹配和计算符号反推

  ```c++
  int (*A1)[3]; // A1指向int*指针数组 sizeof(A1) = 8
  int (*A2[3]); // A2是一个长度为3的指针数组,每个指针指向int sizeof(A2) = 3 * 8 = 24
  ```

- 函数指针

  ```c++
  int * (*f[5])(int, double) // f是一个长度为5的数组,元素是函数指针,这个函数返回int*
  ```


#### 4. 符号

字符串末尾是'\0' 

# C++

### 1.常用工具

##### 在线debug

[C++ Compiler Explorer](https://godbolt.org/)

[C++ Insights](https://cppinsights.io/)

