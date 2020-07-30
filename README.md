# Custom-data-structure-Tree
##实现自定义的数据结构——树

I want you

最近看了一些公司的面试题，发现涉及 IT技术，包括 AI 行业的题目都会涉及到最基本的 C/C++、数据结构和算法之类的，突发奇想写了一个貌似没啥用的数据结构，就当是复习了 [手工哭笑表情]
# 1 结构
<center>
    <img style="border-radius: 0.3125em;
    box-shadow: 0 2px 4px 0 rgba(34,36,38,.12),0 2px 10px 0 rgba(34,36,38,.08);" 
    src="Pictures/1.1 结构.png" width="90%">
    <br>
    <div style="color:orange; border-bottom: 1px solid #d9d9d9;
    display: inline-block;
    color: #999;
    padding: 2px;">图1.1 自定义树的整体结构</div>
</center>
该自定义结构不同于二叉树及其他数据结构，每个节点的子节点**<font color=red>个数不受限制</font>**，最大限度**<font color=red>保留了数据的原始结构</font>**，并实现了其前序和后序遍历的方法。优点是节省了内存，但缺点则是基于链表结构查询的时间开销会相对较大。当然二者不可兼得  
举个例子，图<font color=blue>1.1</font>所示，即是该自定义树的一种结构
> **<font color=red>【注】</font>**：根节点 Root 仅用来表示树自身，其 data 不储存任何数据  

而图<font color=blue>1.1</font>右边则是程序中的结构，为此设计了两种子结构 TNode 和 Node，TNode 用于表示树的节点信息，而 Node 则用于构成链表，组成某节点的子节点集合  
# 1.1 节点结构 TNode
如图<font color=blue>1.2</font>所示包括4种数据类型：（1）节点的名称 name、（2）数据 data、（3）双亲节点指针 parent、（4）子节点指针 child。data用于储存该节点的数据，parent 节点指针用于向上层查找，child 节点用于向下层查找。（图中灰色块表示普通变量，蓝色块表示指针变量）
<center>
    <img style="border-radius: 0.3125em;
    box-shadow: 0 2px 4px 0 rgba(34,36,38,.12),0 2px 10px 0 rgba(34,36,38,.08);" 
    src="Pictures/1.2 TNode结构.png" width="30%">
    <br>
    <div style="color:orange; border-bottom: 1px solid #d9d9d9;
    display: inline-block;
    color: #999;
    padding: 2px;">1.2 TNode结构</div>
</center>
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
