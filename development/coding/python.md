# Tests
- `setup.cfg`常用设置
    ```
    addopts = -v --durations=0 --showlocals  # 显示耗时较久测试
    python_files = tests/*.py  # 查找tests目录下的测试文件
    ```
- 在`conftest.py`里设置`sys.path.insert(0, os.path.abspath("./src/python"))`从而从本地导入

# Cython
```compiler_directives=dict(language_level=3, cpp_locals=True)```来确保避免调用空构造函数