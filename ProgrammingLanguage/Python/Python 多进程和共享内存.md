# Python 多进程和共享内存

1. python 多线程和多进程对比
   - multiprocessing.dummy vs multiprocessing
   - 对于临界区的介绍
   - GIL对性能的影响
2. python Pool用法
   - 传参方式和原理
   - catch exception
   - join和future的基本用法
3. python 3.8 shm介绍
   - shm基本概念和特点
     - 一块通用的byte array
     - 速度快
   - 如何往shm里存数据
     - 序列化
     - ndarray
   - shm的限制
     - 只能存二进制
     - 程序结束强制释放
     - 需要知道数据大小
   - PqiShm的改进
     - 可以持久化保存数据
     - 开发了一个shmServer来确保内存资源不会泄漏
     - 封装了对于ndarray和dataframe的存储