# 遗传算法Geppy和deap使用

### 1. 基本概念

- pset: 表达式和terminal的结合,会在gene compile的时候运行
  - 有head个(算符/输入)
  - **leaf**: max_n * head + 1个输入 (max_n为每个算符的最大输入)
- gene: pset中随机选取元素组成的**list**
- individual: 
  - gene组成的**list** (每条gene都不一样,但是通过相同的function生成)
  - link: 一个把individual中不同gene组合起来的函数
- population: 许多individual (每个individual不一样,但通过相同方式生成)

### 2. 初始化

1. 用geppy生成primitive set

   ```python
   # 初始化集合和输入名
   pset = gep.PrimitiveSet('Main', input_names = factor_names)
   
   # 添加算符
   pset.add_function(F.add, 2) # 第二个参数2代表add这个function需要接收两个参数
   
   # 添加常数输入
   pset.add_constant_terminal(3)
   
   # 添加随机值输入
   pset.add_ephemeral_terminal(name='enc', gen=lambda: random.randint(0, 20))
   ```

2. 通过继承方式，用deap创建objective function

   ```python
   # 定义拟合函数和个体的class
   creator.create("FitnessMax", base.Fitness, weights=(1,))  # to maximize the objective (fitness)
   creator.create("Individual", gep.Chromosome, fitness=creator.FitnessMax)
   
   # 定义生成个体和种群的方法
   toolbox = gep.Toolbox()
   toolbox.register('rnc_gen', random.randint, a=-10, b=10)
   toolbox.register('gene_gen', gep.Gene, pset=pset, head_length= GeneArgs.head_length)
   toolbox.register('individual', creator.Individual, gene_gen=toolbox.gene_gen, n_genes=GeneArgs.n_genes, linker=None)
   toolbox.register("population", tools.initRepeat, list, toolbox.individual)
   
   # 定义运行个体的方法
   toolbox.register('compile', gep.compile_, pset=pset)
   
   # 定义评价和选择的方法
   toolbox.register('evaluate', evaluate)
   toolbox.register('select', tools.selTournament, tournsize=3) # 随机抽3个取3个中最好的
   
   # 添加突变和杂交的方法
   toolbox.register('mut_uniform', gep.mutate_uniform, pset=pset, ind_pb=GeneArgs.mut_uniform_pb, pb=1)
   toolbox.register('mut_invert', gep.invert, pb=GeneArgs.mut_invert_pb)
   toolbox.register('mut_is_transpose', gep.is_transpose, pb=GeneArgs.mut_is_transpose_pb)
   toolbox.register('mut_ris_transpose', gep.ris_transpose, pb=GeneArgs.mut_ris_transpose_pb)
   toolbox.register('mut_gene_transpose', gep.gene_transpose, pb=GeneArgs.mut_gene_transpose_pb)
   toolbox.register('cx_1p', gep.crossover_one_point, pb=GeneArgs.cx_1p_pb)
   toolbox.register('cx_2p', gep.crossover_two_point, pb=GeneArgs.cx_2p_pb)
   toolbox.register('cx_gene', gep.crossover_gene, pb=GeneArgs.cx_gene_pb)
   toolbox.register('mut_ephemeral', gep.mutate_uniform_ephemeral, ind_pb=GeneArgs.mut_ephemeral_ipb, pb=GeneArgs.mut_ephemeral_pb)
   ```

3. 重命名函数,来作为通用的GEP调用接口

   ```python
   stats = tools.Statistics(key=lambda ind: ind.fitness.values[0])
   stats.register("avg", np.mean)
   stats.register("std", np.std)
   stats.register("min", np.min)
   stats.register("max", np.max)
   ```

4. 生成最优集合和ptf

   ```python
   hof = tools.HallOfFame(GeneArgs.n_hof)   # 名人堂保存fit最好的个体
   ptf = tools.ParetoFront() # 
   ```

   

### 3. 随机生成population并开始进化

```python
pop = toolbox.population(n=GeneArgs.n_pop)
# start evolution
pop, log, fit_record = gep.gep_simple(pop, toolbox, factors, Y, n_generations = GeneArgs.n_gen, n_elites=GeneArgs.n_elites,
                                      stats=stats, hall_of_fame=hof, pareto_front=ptf, verbose=True)
```

