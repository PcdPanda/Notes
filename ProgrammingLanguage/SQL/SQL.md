[toc]

# 1. 创建/写入数据

### 1.1 Data Define Language (DDL)

##### 创建/删除数据库

```sql
CREATE DATABASE [IF NOT EXISTS] MyDB; -- 创建数据库
USE MyDB;
DROP DATABASE [IF EXISTS] MyDB; -- 删除数据库
```

##### 创建表

```sql
CREATE TABLE [IF NOT EXISTS] Orders (
    OrderID int NOT NULL,
    OrderNumber int NOT NULL,
    PersonID int AUTO_INCREMENT,
    PRIMARY KEY (OrderID), -- 主键
    FOREIGN KEY (PersonID) REFERENCES Persons(PersonID) -- 外键
);
```

##### 修改表

```sql
ALTER TABLE Customers(
    ADD Email varchar(255), -- 添加列
    DROP COLUMN Email, -- 删除列
    ENGINE = InnoDB;
); 
```

##### 删除/清空表

```sql
DROP TABLE [IF EXISTS] MyTable; -- 删除表
TRUNCATE TABLE MyTable; -- 清空表内数据
```

### 1.2 视图(View)

##### 创建/更新视图

视图类似table,但是没有被实际保存,当访问视图时,<u>会实时执行视图query获取数据</u>

```sql
CREATE OR REPLACE VIEW sales_by_client AS -- 创建或修改视图
SELECT c.client_id, c.name, SUM(invoices_total) AS total_sales
FROM clients c 
JOIN ON invoices 
USING (client_id)
GROUP BY c.client_id;
```

##### 从视图删除数据

删除视图中的数据,不会修改磁盘中的数据

```sql
DELETE FROM t1 WHERE id = 1; -- 不会影响磁盘中的真实数据
```

### 1.3 写入/更新数据

##### 使用query创建表并写入数据

```sql
CREATE TABLE invoices_archive AS SELECT * FROM invoices i;
```

##### 使用INSERT写入数据

```sql
INSERT INTO customers(id, name, birthday, city) -- 指定写入的列
VALUES  (DEFAULT, 'John', '2003-09-23', NULL), -- 使用default填充id
        (12, 'ABC', ' 1239-24-23', 'Shanghai');
```

##### 更新/删除数据

```sql
UPDATE invoices SET payment_total = 10 * invoice_total, payment_date = DEFAULT WHERE id = 1; -- 更新数据
DELETE FROM invoice WHERE id IN (SELECT id FROM client c WHERE name = 'ABC'); -- 删除数据
```

### 1.4 设计范式

##### Table Relationship

- One-to-Many: Many的表使用One的表作为外键
- Many-to-Many: 创建junction table用来连接两个many表的主键

##### Norm Form

1. 表格的每一列不可以再继续拆分,例如name_address列应该被拆分为name,address两列
2. 表格必须有唯一主键,当有重复的tuple时,应该引用外部的table
3. 表格不需要保存有依赖关系的列,例如有了价格和数量,就不需要保存总价

# 2. SELECT查询

### 2.1 基本查询

##### 从特定表中查询需求的数据

```sql
SELECT [DISTINCT] c1 AS alias FROM t1 [WHERE c1 > val AND c2 < val];
```

##### 排序和限制返回行数

降序排序,且返回101-103的3行数据

```SQL
SELECT c1 FROM t1 [ORDER by c2] DESC LIMIT 100, 3;
```

##### 数据匹配

- 匹配特定选项

  ```sql
  SELECT c1 FROM t1 WHERE c1 in ("a", "b", "c");
  ```

- 匹配时间

  ```sql
  SELECT * from pandas where birthdate BETWEEN '1997-09-01' AND '1997-09-24';
  ```

##### 模式匹配

- like使用通配符匹配

  ```sql
  SELECT * from pandas where names like '%p%' OR names like '_CD';
  ```

- REGEXP使用正则表达式匹配

  ```sql
  SELECT * from pandas where names REGEXP '^p|\%CD$';
  ```

### 2.2 聚合查询 (Aggregate)

##### 常规聚合函数

- 获得全表的聚合结果

  ```sql
  SELECT MAX(c1), AVG(c2) FROM t1;
  ```

- 分组聚合

  ```sql
  SELECT COUNT(DISTINCT c1) AS c WHERE c>5 FROM t2 GROUP BY c2 HAVING c1 > 10;
  ```

##### Window Function

- 语法是<u>[聚合函数] OVER (PARTITION BY <分区列> ORDER BY <排序列>)</u>

  根据cid分区,然后获得每个分区中的排序

  ```sql
  SELECT *, RANK() OVER (ORDER BY cid) FROM enrolled ORDER BY cid;
  ```

### 2.3 连接查询 (Join/Union)

<u>当出现同名表/列时需要使用alias</u>

<u>使用行数较少的表去连接行数较多的表</u>

##### 内连接

保留两个表之间可以连接的tuple

```sql
SELECT * FROM employee e INNER JOIN employee j ON e.manager=j.employee_id
```

##### 外连接

无法连接的tuple也会保留,连接字段会设置为NaN

```sql
SELECT * FROM employee e OUTER JOIN employee j ON e.manager=j.employee_id
```

##### 左/右连接

左/右表中的记录会被保留,如果有多条匹配,则会保存多条,无法匹配的则会成为NaN

```sql
SELECT * FROM animal a LEFT JOIN zoo.panda p ON a.name = p.name AND a.zoo = p.zoo;
```

##### 交叉连接

返回两个表的笛卡尔积,不用设定连接列

```sql
SELECT a.panda FROM animal CROSS JOIN zoo.panda p;
```

##### Union

将两个表(<u>schema必须相同</u>)垂直拼接在一起

```sql
SELECT name, 'Shanghai' as place FROM animal a WHERE p ='S'
UNION 
SELECT name, 'Beijing' as place FROM animal a WHERE p ='B';
```

### 2.4 嵌套查询

##### <u>Join时需要添加alias</u>

```sql
SELECT * FROM t1 JOIN (SELECT * FROM t2 LIMIT 10, 5) t2 ON t1.c1=t2.c1;
```

##### 外部query访问内部query时,<u>必须给内部query添加alias</u>

```sql
SELECT * FROM (
    SELECT *, RANK() OVER (PARTITION BY cid ORDER BY grade ASEC) as rank FROM enrolled AS ranking
) WHERE ranking.rank = 1;
```

##### 内部被嵌套的query可以直接引用外部数据

```sql
SELECT (SELECT s.name FROM student AS s WHERE s.sid=E.sid) 
AS name FROM enrolled AS e WHERE cid="database";
```

### 2.5 COMMON TABLE EXPRESSION(CTE)

##### 使用WITH创建临时表

``` sql
WITH cteNAME (col1, col2) AS (SELECT 1, 2) # 创建临时表
SELECT col1 + col2 FROM cteNAME; # 使用临时表来聚合
```

##### CTE递归,<u>必须有WHERE作为终止条件</u>

```sql
WITH RECURSIVE cteNAME(counter) AS (
	(SELECT 1) UNION ALL ( # UNION ALL保留duplicates
        SELECT counter + 1 FROM cteNAME WHERE counter < 10 # 递归
    ) 
)SELECT * FROM cteNAME;
```

# 3. 事务/函数/触发器

### 3.1 事务

##### 特性

| 原子性                  | 一致性                 | 隔离性                    | 持久性               |
| ----------------------- | ---------------------- | ------------------------- | -------------------- |
| 要么都完成,要么都不完成 | 不会破坏data integrity | 不会被没有commit的tnx影响 | commit后改变永久生效 |

##### 隔离级别

- UNCOMMITTED: 无隔离性,事务A可能读取B还没commit的数据
- COMMITTED: A运行时B commit了,则A前后两次读取同一数据结果可能不一致
- REPEATABLE READ: A不会看见B的update但是会看见B的insert,读取同一个表的结果可能不一致
- SERIALIZABLE: 结果和AB或者BA顺序运行一致

##### 创建事务

```sql
START TRANSACTION;  --是用start不是create
INSERT INTO orders(customer_id, order_id, status)
VALUES (1,'2019-01-01', 1);
ROLLBACK; -- 取消事务
COMMIT; -- 提交事务
```

# 4. 函数/存储过程/触发器

创建一个query函数,可以被模块化重复调用

### 4.1 存储过程

1. 修改换行符,因为过程中的分号不代表过程结束

2. 定义函数和输入/输出参数,前缀说明变量作用于

   - IN: 变量只会用于传入参数
   - OUT: 调用者可以通过传入变量,获得存储过程的修改值,<u>但是该变量在存储过程中会被初始化为NULL</u>
   - INOUT: 变量在存储过程中会被初始化为传入参数,调用者也可以获得修改值

3. 使用begin和end描述过程起止

   ```sql
   DELIMITER $$ -- 修改换行符
   CREATE PROCEDURE get_unpaid_customers(IN client_id INT, OUT invoices_count INT, INOUT invoices_total DECIMAL(9,2)) 
   -- 定义函数和输入输出
   BEGIN
       DECLARE total DECIMAL(9,2) DEFAULT 0 -- 定义局部变量local variable
       SELECT COUNT(*), SUM(invoices_total) INTO invoices_count, invoices_total -- 导入SELECT结果至变量
       FROM invoices i
       WHERE client_id = i.client_id AND i.payment_total = 0
       SET total = invoices_total * invoices_count -- 更新表中数据
   END $$
   DELIMITER;
   ```

4. 创建变量并传入参数调用存储过程

   ```sql
   SET @invoices_count = 0; -- 定义会话变量,连接断开会被删除
   SET @invoices_total = 0;
   CALL get_unpaid_customers (3, @invoices_count, @invoices_total); -- 变量值会被修改
   ```

5. 删除存储过程

   ```sql
   DROP PROCEDURE IF EXISTS get_unpaid_customers();
   ```

### 4.2 函数

1. 创建函数
2. 定义传入参数和返回值类型
3. 给函数添加属性
4. 在begin和end中写入函数过程

```sql
CREATE FUNCTION GET_SUM_MOD_2(n INT)
RETURNS INT -- 定义返回值类型
DETERMINISTIC -- 定义函数属性 deterministic表示同一个表格输出不变
READS SQL DATA
MODIFY SQL DATA -- 可以有多个属性
BEGIN
    DECLARE a INT DEFAULT 0
    DECLARE ans INT DEFAULT 1
    SELECT MOD(SUM(invoices_total), 2) FROM invoices INTO a
    SET ans = a
    RETURN ans
END;
```

### 4.3 触发器

当有事件发生时,触发器会被调用执行过程

##### 创建触发器 (TRIGGER)

1. 修改终止符并定义触发器
2. 设定触发器的触发时点
3. 定义触发器的运行过程

```sql
DELIMITER $$
CREATE TRIGGER payments_after_insert  -- 创建触发器
    AFTER INSERT ON payments
    BEFORE DELETE ON payments       
    AFTER UPDATE ON payments -- 插入/删除/更新都会调用触发器
    FOR EACH ROW   -- 触发时间, 条件用的table和操作的table不能相同，不然会无限循环
BEGIN -- 具体操作
    UPDATE invoices SET payment_total =1 WHERE invoice_id = NEW.invoice_id;
END $$
DELIMITER ;
```

##### 创建事件 (EVENT)

和触发器类似,但是按照周期触发

```sql
DELIMITER $$
CREATE EVENT yearly_delete_stale_audit_rows
ON SCHEDULE AT '2019-05-01' -- 从schedule之后开始运行
EVERY 2 DAYS STARTS '2019-01-01' ENDS '2029-01-01' -- 定义触发频率
DO BEGIN -- 执行event过程内容
    DELETE FROM payments_audit 
    WHERE action_date < NOW() - INTERVAL 1 YEAR
END $$
DELIMITER ;
```

# 5. 数据库优化

### 5.1 INDEX

```sql
CREATE [UNIQUE | FULLTEXT | SPATIAL] INDEX index_name USING {BTREE | HASH}
    ON tbl_name (key_part,...)
    [index_option]
    [algorithm_option | lock_option] ...

key_part: {col_name [(length)] | (expr)} [ASC | DESC]

index_option: {
    KEY_BLOCK_SIZE [=] value
  | index_type
  | WITH PARSER parser_name
  | COMMENT 'string'
  | {VISIBLE | INVISIBLE}
  | ENGINE_ATTRIBUTE [=] 'string'
  | SECONDARY_ENGINE_ATTRIBUTE [=] 'string'
}    

algorithm_option:
    ALGORITHM [=] {DEFAULT | INPLACE | COPY}

lock_option:
    LOCK [=] {DEFAULT | NONE | SHARED | EXCLUSIVE}
```

- B+数适合范围检索

- Hash适合匹配检索

### 5.2 EXPLAIN

explain后添加[SELECT/DELETE/UPDATE/INSERT]语句,可以获得相关执行信息

```sql
EXPLAIN SELECT * FROM abc JOIN def USING c1 WHERE k > 5;
```

##### 重要输出结果

- rows: 每个子查询访问的行数
- type: join type
- key: 用来筛选的key/index
- extra: 使用的临时内存信息,例如临时表

# 6. 权限管理

### 6.1 创建和设置用户

```sql
CREATE USER username@{ip|host} IDENTITY BY 'pwd';
SET PASSWORD FOR PANDA = '1234'; -- 修改密码
```

### 6.2 管理用户权限

```sql
GRANT SELECT, INSERT, DELETE, UPDATE, EXECUTE ON db.table TO username; -- 赋予用户权限
GRANT ALL ON *.* TO username; -- 赋予用户所有权限
SHOW GRANTS FOR username;
REVOKE INSERT ON *.* FROM username; -- 收回权限
```

