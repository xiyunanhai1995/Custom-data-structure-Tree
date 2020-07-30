# Custom-data-structure-Tree
## 实现自定义的数据结构——树

最近看了一些公司的面试题，发现涉及 IT技术，包括 AI 行业的题目都会涉及到最基本的 C/C++、数据结构和算法之类的，突发奇想写了一个貌似没啥用的数据结构，就当是复习了 [手工哭笑表情]
# 1 结构

<p align="center"><img src="1.1 结构.png" width="90%"\></p>
<p align="center" style="color:orange; font-size:14px; color: #999; " >图1.1 自定义树的整体结构</p>

该自定义结构不同于二叉树及其他数据结构，每个节点的子节点**<font color=red>个数不受限制</font>**，最大限度**<font color=red>保留了数据的原始结构</font>**，并实现了其前序和后序遍历的方法。优点是节省了内存，但缺点则是基于链表结构查询的时间开销会相对较大。当然二者不可兼得  
举个例子，图<font color=blue>1.1</font>所示，即是该自定义树的一种结构
> **<font color=red>【注】</font>**：根节点 Root 仅用来表示树自身，其 data 不储存任何数据  

而图<font color=blue>1.1</font>右边则是程序中的结构，为此设计了两种子结构 TNode 和 Node，TNode 用于表示树的节点信息，而 Node 则用于构成链表，组成某节点的子节点集合  
## 1.1 节点结构 TNode
如<font color=blue>图1.2</font>所示包括4种数据类型：（1）节点的名称 name、（2）数据 data、（3）双亲节点指针 parent、（4）子节点指针 child。data用于储存该节点的数据，parent 节点指针用于向上层查找，child 节点用于向下层查找。（图中灰色块表示普通变量，蓝色块表示指针变量）


<p align="center"><img src="Pictures/1.2 TNode结构.png" width="90%"\></p>
<p align="center" style="color:orange; font-size:14px; color: #999; " >图1.2 TNode结构</p>

程序定义如下：  

```
typedef struct TNode  //结点结构
{
	char         *name;		//结点名称 
	TElemType    data;		//结点数据
	struct TNode *parent;	                //双亲节点指针 
	LinkList     child;		//子节点指针 
}TNode, *Tree;
```

> **<font color=red>【注】</font>**：name为节点的标识符（等同于 ID 标记），根据名称长度分配不同大小的**动态内存**，**<font color=red>不可重复</font>**，TElemType为节点包含的数据类型，作者定义为 int，根据实际需要修改。

## 1.2 链表的节点结构 Node

如<font color=blue>图1.3</font>所示包括4种数据类型：（1）指向TNode节点的指针 tNode、（2）前一个链表节点的指针 pre、（3）下一个链表节点的指针 next。

<p align="center"><img src="Pictures/1.3 Node结构.png" width="90%"\></p>
<p align="center" style="color:orange; font-size:14px; color: #999; " >图1.3 Node结构</p>

程序定义如下：  
```
typedef struct Node  
{  
    struct TNode *tNode;  
    struct Node  *pre;  
    struct Node  *next;  
}Node, *LinkList; 
```
此处有个特殊的节点：链表的**头节点（head）**
如<font color=blue>图1.4</font>所示，该头节点中 tNode 指向的 TNode 节点储存其双亲点的子节点的数量信息（由 data存储，图中举例该双亲节点的子节点共有3个）。而其 name 会自动命名为 **<font color=red>“双亲名称” + “_head”</font>**，标记其为头节点（图中举例双亲名称为 “A”，故其头节点名称为“A_head”）。


<p align="center"><img src="Pictures/1.4 链表的头节点.png" width="90%"\></p>
<p align="center" style="color:orange; font-size:14px; color: #999; " >图1.4 链表的头节点</p>

> **<font color=red>【注】</font>**：因为链表的头节点没有前继节点，故 **pre 始终为 NULL**，而且也禁止为头节点添加子节点，所有 **child 也始终为 NULL**。

# 2 遍历

对于一种自定义的数据结构来说，最核心需要实现的功能就是遍历，程序中对于不同功能设计了两种遍历算法：**<font color=red>前序遍历</font>** 和 **<font color=red>后序遍历</font>**。对于节点的插入操作，可以通过前序遍历或后序遍历来实现，而节点的删除操作因为涉及动态内存的释放，则需使用后序遍历来实现。

## 2.1 前序遍历
由于head节点的存在，故可进一步设计出两种遍历方式：（1）遍历所有节点，包括head（2）跳过所有head。
由于**兄弟节点插入**设计为**后插入**（具体见第3章），故需要遍历head节点，即需要使用第（1）种遍历方式，而**插入子节点**（具体见第3章）或是单纯的输出显示所有节点信息，则第（2）种就可以。
如<font color=blue>图2.1</font>所示为树的第（1）种：前序遍历所有节点，包括所有head

<p align="center"><img src="Pictures/2.1 前序遍历所有.png" width="90%"\></p>
<p align="center" style="color:orange; font-size:14px; color: #999; " >图2.1 前序遍历，包括所有节点</p>

控制台输出如<font color=blue>图2.2</font>所示，格式为 **<font color=red>(双亲节点name)  <——  (该节点的name: 该节点的data)</font>**。
<center>
    <img style="border-radius: 0.3125em;
    box-shadow: 0 2px 4px 0 rgba(34,36,38,.12),0 2px 10px 0 rgba(34,36,38,.08);" 
    src="Pictures/2.2 前序遍历所有（控制台输出）.png" width="50%">
    <br>
    <div style="color:orange; border-bottom: 1px solid #d9d9d9;
    display: inline-block;
    color: #999;
    padding: 2px;">2.2 前序遍历所有（控制台输出）</div>
</center>

<p align="center"><img src="Pictures/2.2 前序遍历所有（控制台输出）.png" width="90%"\></p>
<p align="center" style="color:orange; font-size:14px; color: #999; " >图2.2 前序遍历所有（控制台输出）</p>

> **<font color=red>【注】</font>**：Root 节点无双亲，故仅显示name和data。