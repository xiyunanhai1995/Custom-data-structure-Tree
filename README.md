# Custom-data-structure-Tree
## 实现自定义的数据结构——树

最近看了一些公司的面试题，发现涉及 IT技术，包括 AI 行业的题目都会涉及到最基本的 C/C++、数据结构和算法之类的，突发奇想写了一个貌似没啥用的数据结构，就当是复习了 [手工哭笑表情]
# 1 结构

<p align="center"><img src="Pictures/1.1 结构.png" width="90%"\></p>
<p align="center" style="color:orange; font-size:14px; color: #999; " >图1.1 自定义树的整体结构</p>

该自定义结构不同于二叉树及其他数据结构，每个节点的子节点**<font color=red>个数不受限制</font>**，最大限度**<font color=red>保留了数据的原始结构</font>**，并实现了其前序和后序遍历的方法。优点是节省了内存，但缺点则是基于链表结构查询的时间开销会相对较大。当然二者不可兼得  
举个例子，图<font color=blue>1.1</font>所示，即是该自定义树的一种结构
> **<font color=red>【注】</font>**：根节点 Root 仅用来表示树自身，其 data 不储存任何数据  

而图<font color=blue>1.1</font>右边则是程序中的结构，为此设计了两种子结构 TNode 和 Node，TNode 用于表示树的节点信息，而 Node 则用于构成链表，组成某节点的子节点集合  
## 1.1 节点结构 TNode
如<font color=blue>图1.2</font>所示包括4种数据类型：（1）节点的名称 name、（2）数据 data、（3）双亲节点指针 parent、（4）子节点指针 child。data用于储存该节点的数据，parent 节点指针用于向上层查找，child 节点用于向下层查找。（图中灰色块表示普通变量，蓝色块表示指针变量）


<p align="center"><img src="Pictures/1.2 TNode结构.png" width="30%"\></p>
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

<p align="center"><img src="Pictures/1.3 Node结构.png" width="50%"\></p>
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


<p align="center"><img src="Pictures/1.4 链表的头节点.png" width="70%"\></p>
<p align="center" style="color:orange; font-size:14px; color: #999; " >图1.4 链表的头节点</p>

> **<font color=red>【注】</font>**：因为链表的头节点没有前继节点，故 **pre 始终为 NULL**，而且也禁止为头节点添加子节点，所有 **child 也始终为 NULL**。

# 2 遍历

对于一种自定义的数据结构来说，最核心需要实现的功能就是遍历，程序中对于不同功能设计了两种遍历算法：**<font color=red>前序遍历</font>** 和 **<font color=red>后序遍历</font>**。对于节点的插入操作，可以通过前序遍历或后序遍历来实现，而节点的删除操作因为涉及动态内存的释放，则需使用后序遍历来实现。

## 2.1 前序遍历
由于head节点的存在，故可进一步设计出两种遍历方式：（1）遍历所有节点，包括head（2）跳过所有head。
由于**兄弟节点插入**设计为**后插入**（具体见第3章），故需要遍历head节点，即需要使用第（1）种遍历方式，而**插入子节点**（具体见第3章）或是单纯的输出显示所有节点信息，则第（2）种就可以。
如<font color=blue>图2.1</font>所示为树的第（1）种：前序遍历所有节点，包括所有head

<p align="center"><img src="Pictures/2.1 前序遍历所有.png" width="70%"\></p>
<p align="center" style="color:orange; font-size:14px; color: #999; " >图2.1 前序遍历，包括所有节点</p>

控制台输出如<font color=blue>图2.2</font>所示，格式为 **<font color=red>(双亲节点name)  <——  (该节点的name: 该节点的data)</font>**。  

<img src="Pictures/2.2.png" width="280">  

![test](Pictures/2.2.png)  

<p align="center"><img src="Pictures/2.2.png" width="480"\></p>  

<p align="center"><img src="Pictures/2.2.png" width="30%"\></p>
<p align="center" style="color:orange; font-size:14px; color: #999; " >图2.2 前序遍历所有（控制台输出）</p>  


> **<font color=red>【注】</font>**：Root 节点无双亲，故仅显示name和data。
> 如图2.3所示为树的第（2）种：前序遍历，跳过所有head

<p align="center"><img src="Pictures/2.3 前序遍历，跳过head.png" width="50%"\></p>
<p align="center" style="color:orange; font-size:14px; color: #999; " >图2.3 前序遍历，跳过所有head</p>

 控制台输出如图2.4所示:

<p align="center"><img src="Pictures/2.4.png" width="30%"\></p>
<p align="center" style="color:orange; font-size:14px; color: #999; " >图2.4 控制台输出</p>

## 2.2 后序遍历
对于节点删除操作，因为要从该节点的最后一个子节点开始倒序释放（避免指针失效），故需使用后序遍历。同理，分为上述两种遍历方式，笔者实现了第（2）种跳过head的后序遍历，但仍未能实现第（1）种所有节点的后序遍历（如有大佬实现，希望不吝指教 o(*￣▽￣*)   
如图2.5所示为树的第（2）种：后序遍历，跳过所有head

<p align="center"><img src="Pictures/2.5 后序遍历，跳过head.png" width="50%"\></p>
<p align="center" style="color:orange; font-size:14px; color: #999; " >图2.5 后序遍历，跳过所有head</p>

控制台输出如图2.6所示：

<p align="center"><img src="Pictures/2.6.png" width="30%"\></p>
<p align="center" style="color:orange; font-size:14px; color: #999; " >图2.6 控制台输出</p>

# 3 插入

笔者实现了两种插入：（1）为该节点插入子节点（禁止为head节点插入子节点），该子节点会插入到最后一个位置；（2）在该节点的后面插入兄弟节点（可以 head 后插入）。

## 3.1 插入子节点

如图3.1所示，为插入子节点的示意图，首先遍历所有节点（可跳过head），找到需要插入子节的节点（作为双亲节点）后，逐步检索其子节点至最后一个，然后生成新的节点，并令其 parent 指针指向其双亲节点，最后令新生成的节点与最后一个子节点相连接（原最后一个节点的 next 指针指向新生成的节点，新生成节点的 pre 指针指向原最后一个节点），同时此条链表的长度+1（head 节点的 data+1）。

<p align="center"><img src="Pictures/3.1 插入子节点.png" width="90%"\></p>
<p align="center" style="color:orange; font-size:14px; color: #999; " >图3.1 插入子节点</p>

> 【注】：若​​​​该节点没有子节点，则先生成一个 head 节点再进行插入

## 3.2 在某一节点后插入兄弟节点

如图3.2所示，遍历检索到该节点，然后生成新的节点，并令新生成节点的 parent 节点指向该节点，然后断开该节点与后续节点之间的指针连接，将新生成节点的指针连接至两节点之间，同时此条链表的长度+1（head 节点的 data+1）。

<p align="center"><img src="Pictures/3.2 插入兄弟节点.png" width="90%"\></p>
<p align="center" style="color:orange; font-size:14px; color: #999; " >图3.2 插入兄弟节点</p>

> 【注】：如果该节点没有后继节点，则只需将新生成节点的后继指针 next 指向 NULL 即可。

## 4 删除

删除某一节点如图4.1所示，首先找到该节点和其后后继节点，然后断开后继节点与该节点和后后继节点之间的指针连接，并释放后继节点的内存，最后将该节点与后后继节点相连，同时 head 节点的 data-1。

<p align="center"><img src="Pictures/4.1 删除某一节点.png" width="90%"\></p>
<p align="center" style="color:orange; font-size:14px; color: #999; " >图4.1 删除某一节点</p>

如果该节点有子节点呢，则需要通过后序遍历找到该节点的子节点的最后一个节点（子节点可能仍存在子节点，则需要层层遍历），倒序依次释放所有节点。  
如图4.2所示，假如需要删除图1.1中的 B 节点，由于 B 节点存在子节点，则需要将其及其所有子节点全部删除，并释放内存，删除顺序同后序遍历顺序，不过在删除链表最后一个子节点后需要回过来删除该链表的 head 节点。  

<p align="center"><img src="Pictures/4.2 删除节点B.png" width="40%"\></p>
<p align="center" style="color:orange; font-size:14px; color: #999; " >图4.2 删除节点 B</p>

 删除节点B后的控制台输出为（前序遍历所有）：


<p align="center"><img src="Pictures/4.3 删除节点B（控制台输出）.png" width="30%"\></p>
<p align="center" style="color:orange; font-size:14px; color: #999; " >图4.3 删除节点 B</p>

删除树则是删除所有节点（包括Root节点），并释放所有内存。

# 结语

未来有时间会加入与二叉树的相互转换功能，目前完成了第一版，可能仍有Bug，如果发现的话，还望指正 (∩_∩)
主要采用C语言编写，部分使用了C++语法（有些C++语法实在太好用了，没控制住不好意思...）
OS：windows10；开发环境：Dev C++；编译器：MinGW GCC 4.8.1 32-bit Release（不过看控制台输出貌似使用的 G++ 编译器），所以如果编译失败的话建议换G++编译器试试

<p align="center"><img src="Pictures/5 控制台编译信息.png" width="30%"\></p>

已实现的功能函数如下：

```
// 详细解释见 Tree.c   
Status InitTree(Tree *T); 	//构造空二叉树T   
Status InitChild(Tree *T);	// 生成 head 节点   
Status ShowNoHead_PreOrderTraverse(const Tree T);				// 前序遍历，跳过head  
Status ShowAll_PreOrderTraverse(const Tree T);					// 前序遍历所有（包括head）   
Status ShowAllbyNode_PreOrderTraverse(const LinkList L);		// 前序遍历所有，使用Node方式进行  
Status ShowNoHead_PostOrderTraverse(const Tree T);				// 后序遍历，跳过head   
Status ShowAll_PostOrderTraverse(const Tree T);					// 后序遍历所有（包括head）  
Status ShowNoHeadbyNode_PostOrderTraverse(const LinkList L);	// 后序遍历，跳过head，使用Node方式进行  
// 显示树信息  
// 前序遍历  
void ShowALL_Pre(const Tree T);        // 显示所有节点（包括head）  
void ShowNoHead_Pre(const Tree T);     // 显示所有节点，跳过head  
void ShowAllbyNode_Pre(const Tree T);  // 采用Node检索方式，显示所有节点（包括head）  
// 后序遍历  
void ShowALL_Post(const Tree T);              
void ShowNoHead_Post(const Tree T);  
void ShowNoHeadbyNode_Post(const Tree T);  
// 节点操作   
TElemType Get_TNodeData(const Tree T, const char *fname);    // 返回树 T 的 TNode 类型节点fname 的 data  
Status _Get_TNodeData(const Tree T, const char *fname, TElemType *fE); // （内部函数）  
TNode * Get_TNode(Tree *pT, const char *fname);    // 返回树 T 的 TNode类型节点 fname 的地址  
Status _Get_TNode(Tree *pT, const char *fname, TNode **fT);	// （内部函数）  
// 在树 T 的双亲节点 ParentName 下插入子节点 name，数据为 data  
Status Inset_childTNode(Tree *pT, const char *ParentName, const char * name, TElemType data);      
Node * Get_Node(Tree *pT, const char *TNodeName);     // 返回树 T 的 Node 类型节点 TNodeName 的地址  
Status _Get_Node(LinkList *pL, const char *TNodeName, Node **fL);    // （内部函数）  
// 在树 T 的节点 TNodeName 的后面插入兄弟节点 name，数据为 data  
Status InsetPosNext_TNode(Tree *pT, const char *TNodeName, const char * name, TElemType data);    
Status _Delete_PostOrderTraverse(Node *L);    // （内部函数）  
Status Delete_TNode(Tree *pT, const char *TNodeName);    // 删除树 T 的节点TNodeName（及其所有子节点）  
Status Delete_Tree(Tree *T);    // 删除树 T  
```
> 【注】：内部函数不直接由用户调用。前三个内部函数是因为遍历是采取的递归算法进行参数检查时会带来 N-1 次的判断开销，故为了提高效率，设计了包裹内部函数的功能函数（同名，没有前面的下划线，由用户直接调用）；第四个内部函数是因为释放掉节点 TNodeName后还需要对其双亲节点的数据进行修改，所以需要进一步操作。（千言万语不如代码来的直观）

