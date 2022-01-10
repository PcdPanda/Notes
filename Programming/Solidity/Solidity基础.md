[toc]

# 1. Solidity语法

### 1.1 预处理

1. 指定版本号

   ```solidity
   pragma solidity >=0.5.0 <0.6.0;
   ```
2. 导入需要用的包

   ```solidity
   import "./MyContract.sol";
   ```

3. 使用特定的包

   ```solidity
   using SafeMath for uint256;
   ```

### 1.2 数据结构

##### 数组

注意定义时下标的顺序

```solidity
string[] names;
uint[] memory values = new uint[](3); // 赋值为3
```

##### mapping

类似于dict,hash

```solidity
mapping(uint=> address) userInfo; // 储存用户信息的dict
```

##### event

事件可以通过emit向全网广播

```solidity
event NewEvent(string indexed publisher, string content); 
// indexed可以让用户根据索引来过滤event
emit NewEvent("publisher", "event"); // 广播消息
```

##### Struct

结构体Struct,<u>使用结构体储存数据(uint32等)可以减少对gases的消耗</u>

```solidity
struct MyStruct{
	string Name;
	uint256 uid;
	address MyAddress;
}
```

##### Contract

Solidity基本对象

```solidity
contract MyContract{

}
```

##### library

一种特殊的库,用来重载基本data type的操作

```solidity
library SafeMath{
}
```

### 1.3 函数和Modifier

##### 函数定义

- struct/array/string必须指定保存在memory/storage(<u>消耗大量gas</u>)/calldata

```solidity
function MyFunction(string memory _input1, uint _input2) returns (string){
	return "Answer";
}
```

##### 关键字 requires

函数的执行过程类似transaction,可以添加附加条件设定函数是否可以执行

```solidity
function Buy(string memory item, uint price) returns (uint){
	requires(balance[msg.sender]>=price) // 添加条件,如果无法达成则无法运行
	balance[msg.sender] -= price;
	return balance[msg.sender];
}
```

##### 关键字 modifier

类似于装饰器,可以在进入函数之前执行

```solidity
modifier checker(){ // 定义一个modifier
	requres(balance[msg.sender]>=0);
	_;
}
function Buy(string memory item, uint price) checker returns (uint) {
```

##### 关键字 payable

需要用户支付一定token才能调用函数

```solidity
function BuySomething() payable{
	require(msg.value >= 5 ether); // 需要支付的金额
	address payable receiver= address(this); // 定义一个收钱的账户,必须是payable的
	address.transfer(5); // 向该账户转账
}
```

### 1.4 智能合约编程

##### caller scope

- public: 所有人都可以访问,<u>但是gas消耗大</u>

  ```solidity
  mapping(address=>uint) public balance; // 定义public变量
  ```
- private: 只可以被内部访问,<u>不可以被继承合约访问</u>

  ```solidity
  function addMoney(uint money) private{ // 定义private函数
  	balance[msg.sender] += money;
  }
  ```
- external: 只可以被外部访问,但是gas消耗小

  ```solidity
  mapping(address=>uint) external balance;
  ```
- internal: 可以被自己或者继承合约访问

  ```solidity
  mapping(address=>uint) internal balance;
  ```

##### 方法作用域

- view: 该方法只会查看contract的数据,**不会消耗gases**
- pure: 该方法不会利用到contract中的任何数据

##### 继承

```solidity
contract childContract is ParentContract, ERC21{ //多重继承
	uint256 public var
	constructor ParentContract(parent_arg) public(){ // 先调用父类构造函数
		var++;
	}
}
```

# 2. 编译和测试

### 2.1 项目目录结构

使用npm和truffle来编译和管理smart contract

- build (编译后文件)
  - contracts
    - *.json
- contract (只能合约源代码)
  - *.sol
- test (测试项目)

### 2.2 编译

### 2.3 测试

使用Ganache在线下测试只能合约
