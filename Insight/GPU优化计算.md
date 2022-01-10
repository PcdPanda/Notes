# GPU优化计算

### 1. 基本架构

1. 流处理器 **SP** (Stream Processor)

   执行若干个**Thread**

   - L0缓存

   - 寄存器

   - 调度单元

   - warp 调度器

   - 浮点,整数,张量运算器

     <img src="C:\Users\PANDA\AppData\Roaming\Typora\typora-user-images\image-20210418231520860.png" alt="image-20210418231520860" style="zoom:50%;" />

2. 流多处理器 **SM** (Stream Multiprocessor)

   对应一个**Block**

   - 上百个**SP**
   - L1缓存（共享内存）

### 2. Numba库

 1. 安装和测试

    ``` bash
    # 安装numba
    conda install numba
    # 选择显卡序号
    CUDA_VISIBLE_DEVICES='5' python example.py
    ```

    ```python
    from numba import cuda 
    print(cuda.gpus)
    ```

2. 使用装饰器运行

   ```python
   @cuda.jit
   def gpu_print():
       # GPU核函数
       print("print by gpu.")
   
   def main():
       gpu_print[1, 2]() # 用1个block,每个block有2个thread
       cuda.synchronize() # 阻塞至GPU运算完成
   ```

   

