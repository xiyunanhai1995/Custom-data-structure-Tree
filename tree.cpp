#include"tree.h"


// 构造空二叉树T 
// 生成Root节点 
Status InitTree(Tree *T)
{
	if( (*T) != NULL)
	{
		puts("Tree already exists");
		return ERROR;
	} 
	(*T) = (TNode *)malloc(sizeof(TNode));
	(*T)->name = (char *)malloc(sizeof(char) * strlen(ROOT) + 1);
	strcpy((*T)->name, ROOT);
	(*T)->data = 0;
	(*T)->parent = NULL;
	(*T)->child = NULL;

	return OK;
}

// 生成 head 节点 
Status InitChild(Tree *T) 
{ 
	assert( (*T) != NULL );
	
    (*T)->child = (Node *)malloc(sizeof(Node)); // 产生头结点（生成了data和next指针）,并使L指向此头结点
    if( (*T)->child  == NULL )  return ERROR;	// 存储分配失败
        
    (*T)->child->tNode = (TNode *)malloc(sizeof(TNode));	//生成头节点的子树（仅存放子树个数） 
    (*T)->child->tNode->name = (char *)malloc(strlen((*T)->name) + strlen(HEAD) + 1); //头节点子树的name 
	strcpy((*T)->child->tNode->name, (*T)->name);
	strcat((*T)->child->tNode->name, HEAD);
    (*T)->child->tNode->data = 0;
    (*T)->child->tNode->parent = (*T);
    (*T)->child->tNode->child = NULL;
    (*T)->child->pre  = NULL; 
    (*T)->child->next = NULL;  		// 下一个指针域为空

    return OK;
}

// 前序输出所有节点 
// 以 TNode 检索的方式 
void ShowALL_Pre(const Tree T)
{
	puts("-------- Tree --------");
	if(T == NULL)
		puts("Tree is empty");
	else
		ShowAll_PreOrderTraverse(T);
	puts("----------------------");
}

// 前序输出，跳过所有 head 节点 
// 以 TNode 检索的方式 
void ShowNoHead_Pre(const Tree T)
{
	puts("-------- Tree --------");
	if(T == NULL)
		puts("Tree is empty");
	else
		ShowNoHead_PreOrderTraverse(T);
	puts("----------------------");
}

// 前序输出所有节点 
// 以 Node 检索的方式 
void ShowAllbyNode_Pre(const Tree T)
{
	puts("-------- Tree --------");
	if(T == NULL)
		puts("Tree is empty");
	else
		ShowAllbyNode_PreOrderTraverse(T->child);
	puts("----------------------");
}

// 后序输出所有节点
// 以 TNode 检索的方式
void ShowALL_Post(const Tree T)
{
	puts("-------- Tree --------");
	if(T == NULL)
		puts("Tree is empty");
	else
		ShowAll_PostOrderTraverse(T);
	puts("----------------------");
}

// 后序输出，跳过所有 head 节点 
// 以 TNode 检索的方式
void ShowNoHead_Post(const Tree T)
{
	puts("-------- Tree --------");
	if(T == NULL)
		puts("Tree is empty");
	else
		ShowNoHead_PostOrderTraverse(T);
	puts("----------------------");
}

// 后序输出，跳过所有 head 节点
// 以 Node 检索的方式 
void ShowNoHeadbyNode_Post(const Tree T)
{
	puts("-------- Tree --------");
	if(T == NULL)
		puts("Tree is empty");
	else
		ShowNoHeadbyNode_PostOrderTraverse(T->child);
	puts("----------------------");
}

//前序遍历所有（包括head） 
Status ShowAll_PreOrderTraverse(const Tree T)
{
	int i=0;
	
	if(T==NULL) return ERROR;
	if( strcmp(T->name, ROOT) != 0)
	{
		printf("(%s) <--- (%s: %d)\n",(T->parent)->name, T->name ,T->data);	//显示结点数据，可以更改为其它对结点操作
	}
	else
	{
		printf("%s: %d\n",T->name ,T->data);
	}

	if(T->child == NULL) return ERROR;
	Node* P = T->child;
	int len = P->tNode->data;
	for(i=0; i< len+1;i++)
	{
		ShowAll_PreOrderTraverse(P->tNode);
		P = P->next;
		if(P == NULL) return ERROR;
	}
	return OK;
}

// 前序遍历，跳过所有head 
Status ShowNoHead_PreOrderTraverse(const Tree T)
{
	int i=0;
	
	if(T==NULL) return ERROR;
	if( strcmp(T->name, ROOT) != 0)
	{
		printf("(%s) <--- (%s: %d)\n",(T->parent)->name, T->name ,T->data);	//显示结点数据，可以更改为其它对结点操作
	}
	else
	{
		printf("%s: %d\n",T->name ,T->data);
	}
	
	if(T->child == NULL) return ERROR;
	Node* P = T->child;
	int len = P->tNode->data;
	for(i=0; i< len;i++)
	{
		P = P->next;
		if(P == NULL) return ERROR;
		ShowNoHead_PreOrderTraverse(P->tNode); //再先序遍历左子树
	}
	return OK;
}

// 前序遍历所有，使用Node方式进行
Status ShowAllbyNode_PreOrderTraverse(const LinkList L)
{
	int i=0;
	
	if(L==NULL) return ERROR;
	if( ! strcmp(L->tNode->name, ROOT))
	{
		puts("Forest operation is not supported temporarily!");
		return ERROR;
	}
	
	printf("(%s) <--- (%s: %d)\n", (L->tNode->parent)->name, L->tNode->name ,L->tNode->data);	//显示结点数据
	
	Node* P = L;
	//if(L->tNode->child == NULL) return ERROR;
	if( strstr(P->tNode->name, HEAD) != NULL)	// 如果该节点是head节点
	{
		int len = P->tNode->data;
		for(i=0; i< len; i++)
		{
			P = P->next;
			if(P == NULL) return ERROR;
			ShowAllbyNode_PreOrderTraverse(P);
		}
	}else	// 如果该节点不是head节点 
	{
		ShowAllbyNode_PreOrderTraverse(P->tNode->child);
	}

	return OK;
}

//后序遍历，跳过所有head  
Status ShowNoHead_PostOrderTraverse(const Tree T)
{
	int i=0;
	
	if(T==NULL) return ERROR;
	if(T->child == NULL) return ERROR;
	
	Node* P = T->child;
	int len = P->tNode->data;
	for(i=0; i< len;i++)
	{
		P = P->next;
		if(P == NULL) return ERROR;
		ShowNoHead_PostOrderTraverse(P->tNode); //再先序遍历左子树

		printf("(%s) <--- (%s: %d)\n",(P->tNode->parent)->name, P->tNode->name ,P->tNode->data);	
	}
	return OK;
}

//后遍历所有（包括head） 
Status ShowAll_PostOrderTraverse(const Tree T)
{
	int i=0;
	
	if(T==NULL) return ERROR;
	

	if(T->child == NULL) return ERROR;
	Node* P = T->child;
	int len = P->tNode->data;
	for(i=0; i< len+1;i++)
	{
		ShowAll_PostOrderTraverse(P->tNode);
		
		printf("(%s) <--- (%s: %d)\n",(P->tNode->parent)->name, P->tNode->name ,P->tNode->data);

		P = P->next;
		if(P == NULL) return ERROR;
	}

	return OK;
}


// 后序遍历，跳过head，使用Node方式进行
Status ShowNoHeadbyNode_PostOrderTraverse(const LinkList L)
{
	int i=0;
	
	if(L==NULL) return ERROR;
	if( ! strcmp(L->tNode->name, ROOT))
	{
		puts("Forest operation is not supported temporarily!");
		return ERROR;
	}
	
	Node* P = L;
	//if(L->tNode->child == NULL) return ERROR;
	if( strstr(P->tNode->name, HEAD) != NULL)	// 如果该节点是head节点 
	{
		int len = P->tNode->data;
		for(i=0; i< len; i++)
		{
			P = P->next;
			if(P == NULL) return ERROR;
			ShowNoHeadbyNode_PostOrderTraverse(P);
		}
	}else	// 如果该节点不是head节点 
	{
		ShowNoHeadbyNode_PostOrderTraverse(P->tNode->child);
		
		printf("(%s) <--- (%s: %d)\n", (P->tNode->parent)->name, P->tNode->name, P->tNode->data);
	}

	return OK;
}

// 在树 T 中按名称查找节点的值
TElemType Get_TNodeData(const Tree T, const char *fname)
{
	assert( T != NULL );
	assert( fname != NULL );
	
	TElemType data=0;
	
	_Get_TNodeData(T, fname, &data);
	
	return data;
}

// 内部函数 
// 在树 T 中按名称查找节点的值 
Status _Get_TNodeData(const Tree T, const char *fname, TElemType *fE)
{ 
	int i=0;
	
	if(T==NULL) return ERROR;
	if( ! strcmp(T->name, fname) )
	{
		(*fE) = T->data;
	}
	else
	{
		if(T->child == NULL) return ERROR;
		Node* P = T->child;
		int len = P->tNode->data;
		for(i=0; i< len; i++)
		{
			P = P->next;
			if(P == NULL) return ERROR;
			_Get_TNodeData(P->tNode, fname, fE); //再先序遍历左子树
		}
		return OK;
	}
}

// 查找某一节点，并令指针 fT 指向该节点 
TNode * Get_TNode(Tree *pT, const char *fname)
{
	assert(pT != NULL);
	assert(fname != NULL);

	TNode *fT=NULL;
	
	_Get_TNode(pT, fname, &fT);
	
	return fT;
}

// 在树 T 中按名称查找节点地址 
// 会跳过head节点 （head节点作为内部信息使用） 
// 因为要对T进行&操作，所以必须使用指针指向T（只有指向才能操作）
// 没有flag标志位会导致 即便链表第一个已经符合，但仍然会循环整个链表 
// 添加了flag标志为后可以 在查找到直接退出 
Status _Get_TNode(Tree *pT, const char *fname, TNode **fT)
{ 
	int i=0;
	static int flag=0;
	
	if((*pT)==NULL) return ERROR;
	if( ! strcmp((*pT)->name, fname) )
	{
		(*fT) = (*pT);
		flag = 1;
	}
	else
	{
		if((*pT)->child == NULL) return ERROR;
		Node* P = (*pT)->child;
		int len = P->tNode->data;
		for(i=0; i < len; i++)
		{
			if(flag == 1) 
			{
				flag = 0;
				return OK;
			}
			P = P->next;
			if(P == NULL) return ERROR;
			_Get_TNode(&(P->tNode), fname, &(*fT));
		}
		return OK;
	}
}



// 在树 T 中的名称为 ParentName 的父节点下插入子节点 name
// name 不能和树 T 已有节点重复 
// 不能插在 head 节点下（TNodeName禁止输入某一head名称） 
// name 不得超过 NAME_MAX 
Status Inset_childTNode(Tree *pT, const char *ParentName, const char * name, TElemType data)
{
	assert((*pT) != NULL);
	assert(ParentName != NULL);
	assert(name != NULL);

	if( strlen(name) > NAME_MAX )
	{
		puts("Name too long, Name length shall not exceed 20");
		return ERROR; 
	}
	
	TNode *fT=NULL, *fT2=NULL;
	
	_Get_TNode(pT, ParentName, &fT);
	if(fT == NULL)
	{
		printf("Parent node \'%s\' not found in Tree\n", ParentName);
		return ERROR;
	}
	_Get_TNode(pT, name, &fT2);
	if(fT2 != NULL)
	{
		printf("Child node \'%s\' already exists in Tree\n", name);
		return ERROR;
	}
	
	Node *Lp;	//专用于生成新节点 	
	Lp = (Node *)malloc(sizeof(Node));
	Lp->tNode = (TNode *)malloc(sizeof(TNode));
	Lp->tNode->name = (char *)malloc(sizeof(char) * (strlen(name) + 1));
	strcpy(Lp->tNode->name, name);
	Lp->tNode->data = data;
	Lp->tNode->parent = fT;
	Lp->tNode->child = NULL;
	Lp->pre  = NULL;
	Lp->next = NULL;
	
	if(fT->child == NULL)
		InitChild( &fT );
	Node **fL = &(fT->child);

	int i=0;
	int len = (*fL)->tNode->data;
	for(i=0; i < len + 1; i++)
	{
		if( i == len )
			Lp->pre = *fL;
		fL = &((*fL)->next);
	}
	
	*fL = Lp;
	
	fT->child->tNode->data += 1;
	
	return OK;
}


// 查找节点 Node 的位置，并使用指针 fL 指向 指向其地址的指针 
int flag2=0;
Node * Get_Node(Tree *pT, const char *TNodeName)
{
	assert( (*pT) != NULL );
	assert( TNodeName != NULL );

	struct Node *fL=NULL;
		
	_Get_Node(&((*pT)->child), TNodeName, &fL);
	flag2 = 0;
	
	return fL;
}

// 本函数仅作为内部使用
// 该函数使用后必须紧接着将 flag2 置 0 
// 要单独搜索Node请使用  Get_Node 函数 
Status _Get_Node(LinkList *pL, const char *TNodeName, Node **fL)
{
	int i=0;
	
	if((*pL)==NULL) return ERROR;
	if( ! strcmp((*pL)->tNode->name, ROOT))
	{
		puts("Forest operation is not supported temporarily!");
		return ERROR;
	}
	if(  ! strcmp((*pL)->tNode->name, TNodeName) )
	{	
		(*fL) = (*pL);	
		flag2 = 1;
	}
	
	Node* P = (*pL);
	if(flag2 == 0)
	{
		if( strstr( P->tNode->name, HEAD) != NULL)
		{
			int len = P->tNode->data;
			for(i=0; i< len; i++)
			{
				if(flag2 == 1)
					return OK;
				P = P->next;
				if(P == NULL) return ERROR;
				_Get_Node(&P, TNodeName, fL);
			}
		}else
		{
			if(flag2 == 1)
				return OK;
			_Get_Node( &(P->tNode->child), TNodeName, fL);
		}
	}
	else
	{
		return OK;
	}

	return OK;
}

// 在树 T 中的 TNodeName 的节点后插入新节点 
// 可以插在 head 节点后（TNodeName可以输入某一head名称） 
Status InsetPosNext_TNode(Tree *pT, const char *TNodeName, const char * name, TElemType data)
{ 
	assert((*pT) != NULL);
	assert(TNodeName != NULL);
	assert(name != NULL);

	Node *fL=NULL, *fL2=NULL;
	
	_Get_Node(&((*pT)->child), TNodeName, &fL);	// 查询是否存在节点 TNodeName
	flag2 = 0;
	if(fL == NULL)
	{
		printf("node \'%s\' not found in Tree\n", TNodeName);
		return ERROR;
	}
	
	_Get_Node(&((*pT)->child), name, &fL2);	// 查询是否已存在节点 name 
	flag2 = 0;
	if(fL2 != NULL)
	{
		printf("node \'%s\' already exists in Tree\n", name);
		return ERROR;
	}	
	
	Node *Lp;	//专用于生成新节点 	
	Lp = (Node *)malloc(sizeof(Node));
	Lp->tNode = (TNode *)malloc(sizeof(TNode));
	Lp->tNode->name = (char *)malloc(sizeof(char) * (strlen(name)+1));
	strcpy(Lp->tNode->name, name);
	Lp->tNode->data = data;
	
	Lp->tNode->parent = fL->tNode->parent;
	Lp->tNode->child = NULL;
	Lp->pre  = NULL;
	Lp->next = NULL;
	
	if(fL->next == NULL)	// 节点 TNodeName 后无节点 
	{
		fL->next = Lp;
		Lp->pre = fL;
	}
	else
	{
		Lp->next = fL->next;
		Lp->pre = fL;
		Lp->next->pre = Lp;
		fL->next = Lp;
	} 
	
	fL->tNode->parent->child->tNode->data += 1;

	return OK;
}

 
Status _Delete_PostOrderTraverse(Node *L)
{
	int i=0;
	
	if(L==NULL) return ERROR;
	if( ! strcmp(L->tNode->name, ROOT))
	{
		puts("Forest operation is not supported temporarily!");
		return ERROR;
	}
	
	Node *P = L;	// 用于索引 
	static Node *K = NULL;	// 用于释放内存 

	if( strstr(P->tNode->name, HEAD) != NULL)	// 如果该节点是head节点 
	{
		int len = P->tNode->data;
		for(i=0; i< len + 1; i++)
		{
			P = P->next;
			if(i != 0)	// 避免第一次释放头节点 
			{
				if( K->next != NULL )
				{
					K->pre->next = K->next;
					K->next->pre = K->pre;
					
					K->pre = NULL;
					K->next = NULL; 
					
					free(K);
					K = NULL;
				}
				else
				{
					//K->pre = NULL;
					//K->next = NULL;	//已经是NULL了 
					
					free(K);
					K = NULL;
				}				
			} 
				
			if(P == NULL) return ERROR;
			_Delete_PostOrderTraverse(P);
		}
	}else	// 如果该节点不是head节点 
	{
		_Delete_PostOrderTraverse(P->tNode->child);
		
		K = P;	
		
		free(K->tNode->name);
		K->tNode->name = NULL;
		K->tNode->parent = NULL;
		K->tNode->child = NULL;
		free(K->tNode);
		K->tNode = NULL;
		
		// 如果 K 前就是head节点，并且无后序节点，那么顺便释放 head 节点
		if( (strstr(K->pre->tNode->name, HEAD) != NULL )  &&  ( K->next == NULL) )	 
		{
			free(K->pre->tNode->name);
			K->pre->tNode->name = NULL;
			K->pre->tNode->parent = NULL;
			K->pre->tNode->child = NULL;
			free(K->pre->tNode);	
			K->pre->tNode = NULL;
			
			K->pre->next = NULL;
			
			free(K->pre);
			K->pre = NULL;
		}
	}
	
	return OK;
}

// 删除节点 TNodeName 以及该节点的所有子节点 
// 不能删除 root 节点（不能直接通过该函数删除整个树）
// 删除最后一个子节点时会自动删除其head节点 
Status Delete_TNode(Tree *pT, const char *TNodeName)
{ 
	assert( (*pT) != NULL);
	assert( TNodeName != NULL);

	int i=0;
	
	if(strstr(TNodeName, HEAD) != NULL)
	{
		puts("Do not delete head node!");
		return ERROR; 
	}
	
	Node *fL=NULL;
	
	_Get_Node(&((*pT)->child), TNodeName, &fL);	// 查询是否存在节点 TNodeName
	flag2 = 0;
	if(fL == NULL)
	{
		printf("node \'%s\' not found in Tree\n", TNodeName);
		return ERROR;
	}
	
	if( (strstr(fL->pre->tNode->name, HEAD) != NULL )  &&  ( fL->next == NULL) )
	{
		fL->tNode->parent->child = NULL;
	}
	else
	{
		fL->tNode->parent->child->tNode->data -= 1;	//该节点的父节点的子节点数减 1 
	}
	
	_Delete_PostOrderTraverse(fL);
		
	if(fL->next != NULL )	// 如果该节点有后继节点 
	{
		fL->pre->next = fL->next;
		fL->next->pre = fL->pre;
		
		fL->next = NULL; 
	}
	else
	{
		if(fL->pre != NULL)
			fL->pre->next = NULL;		
	}
	
	fL->pre = NULL;
	free(fL);
	fL = NULL;
	
	return OK;
}

// 删除树
// 释放所有节点，包括 Root 
Status Delete_Tree(Tree *T)
{
	if( (*T) == NULL )
		return OK;
	
	char name[NAME_MAX+1];	// 长度根据个人命名习惯更改 

	Node *P = (*T)->child->next;
	Node *K=NULL;
	
	int i=0;
	int len = (*T)->child->tNode->data;
	for(i=0; i< len; i++)
	{
		K = P;
		P = P->next;
		strcpy(name, K->tNode->name); 
		Delete_TNode(T, name);			// 建议不要直接使用K->tNode->name，删除时会释放name指针 
		memset(name, '\0', NAME_MAX+1); 
	}
	
	free((*T)->name);
	(*T)->name = NULL;
	(*T)->parent = NULL;
	(*T)->child = NULL;
	free(*T);
	(*T) = NULL;
	
	return OK;
} 


