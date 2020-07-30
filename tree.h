#ifndef __TREE_H
#define __TREE_H
#include <stdio.h>   
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define OK	0
#define ERROR	1

//�������Ȳ��ó���20��������head�ڵ㣬head�ڵ㳤�ȿ��Զ�5�����ڴ��_head�� 
#define NAME_MAX	20	 

#define ROOT "Root"		// ���ڵ������ 
#define HEAD "_head"	// ͷ�ڵ�ӵĺ�׺���� 

typedef int Status;		//Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK��
typedef char * String;
typedef int TElemType; //������������Ϊ�ַ��� 
typedef int ElemType;

typedef struct Node
{
    struct TNode *tNode;
    struct Node  *pre;
    struct Node  *next;
}Node, *LinkList;

typedef struct TNode  //���ṹ
{
	char         *name;		//������� 
	TElemType    data;		//�������
	struct TNode *parent;	//˫�׽ڵ�ָ�� 
	struct Node  *child;		//�ӽڵ�ָ�� 
}TNode, *Tree;


// ��ϸ���ͼ� Tree.c  
Status InitTree(Tree *T); 	//����ն�����T
Status InitChild(Tree *T);	// ���� head �ڵ� 

Status ShowNoHead_PreOrderTraverse(const Tree T);				// ǰ�����������head
Status ShowAll_PreOrderTraverse(const Tree T);					// ǰ��������У�����head��  
Status ShowAllbyNode_PreOrderTraverse(const LinkList L);		// ǰ��������У�ʹ��Node��ʽ����

Status ShowNoHead_PostOrderTraverse(const Tree T);				// �������������head 
Status ShowAll_PostOrderTraverse(const Tree T);					// ����������У�����head�� 
Status ShowNoHeadbyNode_PostOrderTraverse(const LinkList L);	// �������������head��ʹ��Node��ʽ����

// ��ʾ����Ϣ
// ǰ�����
void ShowALL_Pre(const Tree T);			// ��ʾ���нڵ㣨����head��
void ShowNoHead_Pre(const Tree T);		// ��ʾ���нڵ㣬����head
void ShowAllbyNode_Pre(const Tree T);	// ����Node������ʽ����ʾ���нڵ㣨����head��

// ������� 
void ShowALL_Post(const Tree T);
void ShowNoHead_Post(const Tree T);
void ShowNoHeadbyNode_Post(const Tree T);

// �ڵ���� 
TElemType Get_TNodeData(const Tree T, const char *fname);	// ������ T �� TNode ���ͽڵ�fname �� data
Status _Get_TNodeData(const Tree T, const char *fname, TElemType *fE);	// ���ڲ�������
TNode * Get_TNode(Tree *pT, const char *fname);	// ������ T �� TNode���ͽڵ� fname �ĵ�ַ
Status _Get_TNode(Tree *pT, const char *fname, TNode **fT);		// ���ڲ�������

Status Inset_childTNode(Tree *pT, const char *ParentName, const char * name, TElemType data);	// ���� T ��˫�׽ڵ� ParentName �²����ӽڵ� name������Ϊ data
Node * Get_Node(Tree *pT, const char *TNodeName);	// ������ T �� Node ���ͽڵ� TNodeName �ĵ�ַ
Status _Get_Node(LinkList *pL, const char *TNodeName, Node **fL);	// ���ڲ�������
Status InsetPosNext_TNode(Tree *pT, const char *TNodeName, const char * name, TElemType data);	// ���� T �Ľڵ� TNodeName �ĺ�������ֵܽڵ� name������Ϊ data

Status _Delete_PostOrderTraverse(Node *L);	// ���ڲ�������
Status Delete_TNode(Tree *pT, const char *TNodeName);	// ɾ���� T �Ľڵ�TNodeName�����������ӽڵ㣩
Status Delete_Tree(Tree *T);	// ɾ���� T

#endif





