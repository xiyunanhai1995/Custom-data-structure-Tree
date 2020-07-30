#ifndef __TREE_H
#define __TREE_H
#include <stdio.h>   
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define OK	0
#define ERROR	1

//命名长度不得超过20（不包括head节点，head节点长度可以多5，用于存放_head） 
#define NAME_MAX	20	 

#define ROOT "Root"		// 根节点的名称 
#define HEAD "_head"	// 头节点加的后缀名称 

typedef int Status;		//Status是函数的类型,其值是函数结果状态代码，如OK等
typedef char * String;
typedef int TElemType; //定义数据类型为字符串 
typedef int ElemType;

typedef struct Node
{
    struct TNode *tNode;
    struct Node  *pre;
    struct Node  *next;
}Node, *LinkList;

typedef struct TNode  //结点结构
{
	char         *name;		//结点名称 
	TElemType    data;		//结点数据
	struct TNode *parent;	//双亲节点指针 
	struct Node  *child;		//子节点指针 
}TNode, *Tree;


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
void ShowALL_Pre(const Tree T);			// 显示所有节点（包括head）
void ShowNoHead_Pre(const Tree T);		// 显示所有节点，跳过head
void ShowAllbyNode_Pre(const Tree T);	// 采用Node检索方式，显示所有节点（包括head）

// 后序遍历 
void ShowALL_Post(const Tree T);
void ShowNoHead_Post(const Tree T);
void ShowNoHeadbyNode_Post(const Tree T);

// 节点操作 
TElemType Get_TNodeData(const Tree T, const char *fname);	// 返回树 T 的 TNode 类型节点fname 的 data
Status _Get_TNodeData(const Tree T, const char *fname, TElemType *fE);	// （内部函数）
TNode * Get_TNode(Tree *pT, const char *fname);	// 返回树 T 的 TNode类型节点 fname 的地址
Status _Get_TNode(Tree *pT, const char *fname, TNode **fT);		// （内部函数）

Status Inset_childTNode(Tree *pT, const char *ParentName, const char * name, TElemType data);	// 在树 T 的双亲节点 ParentName 下插入子节点 name，数据为 data
Node * Get_Node(Tree *pT, const char *TNodeName);	// 返回树 T 的 Node 类型节点 TNodeName 的地址
Status _Get_Node(LinkList *pL, const char *TNodeName, Node **fL);	// （内部函数）
Status InsetPosNext_TNode(Tree *pT, const char *TNodeName, const char * name, TElemType data);	// 在树 T 的节点 TNodeName 的后面插入兄弟节点 name，数据为 data

Status _Delete_PostOrderTraverse(Node *L);	// （内部函数）
Status Delete_TNode(Tree *pT, const char *TNodeName);	// 删除树 T 的节点TNodeName（及其所有子节点）
Status Delete_Tree(Tree *T);	// 删除树 T

#endif





