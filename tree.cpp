#include"tree.h"


// ����ն�����T 
// ����Root�ڵ� 
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

// ���� head �ڵ� 
Status InitChild(Tree *T) 
{ 
	assert( (*T) != NULL );
	
    (*T)->child = (Node *)malloc(sizeof(Node)); // ����ͷ��㣨������data��nextָ�룩,��ʹLָ���ͷ���
    if( (*T)->child  == NULL )  return ERROR;	// �洢����ʧ��
        
    (*T)->child->tNode = (TNode *)malloc(sizeof(TNode));	//����ͷ�ڵ����������������������� 
    (*T)->child->tNode->name = (char *)malloc(strlen((*T)->name) + strlen(HEAD) + 1); //ͷ�ڵ�������name 
	strcpy((*T)->child->tNode->name, (*T)->name);
	strcat((*T)->child->tNode->name, HEAD);
    (*T)->child->tNode->data = 0;
    (*T)->child->tNode->parent = (*T);
    (*T)->child->tNode->child = NULL;
    (*T)->child->pre  = NULL; 
    (*T)->child->next = NULL;  		// ��һ��ָ����Ϊ��

    return OK;
}

// ǰ��������нڵ� 
// �� TNode �����ķ�ʽ 
void ShowALL_Pre(const Tree T)
{
	puts("-------- Tree --------");
	if(T == NULL)
		puts("Tree is empty");
	else
		ShowAll_PreOrderTraverse(T);
	puts("----------------------");
}

// ǰ��������������� head �ڵ� 
// �� TNode �����ķ�ʽ 
void ShowNoHead_Pre(const Tree T)
{
	puts("-------- Tree --------");
	if(T == NULL)
		puts("Tree is empty");
	else
		ShowNoHead_PreOrderTraverse(T);
	puts("----------------------");
}

// ǰ��������нڵ� 
// �� Node �����ķ�ʽ 
void ShowAllbyNode_Pre(const Tree T)
{
	puts("-------- Tree --------");
	if(T == NULL)
		puts("Tree is empty");
	else
		ShowAllbyNode_PreOrderTraverse(T->child);
	puts("----------------------");
}

// ����������нڵ�
// �� TNode �����ķ�ʽ
void ShowALL_Post(const Tree T)
{
	puts("-------- Tree --------");
	if(T == NULL)
		puts("Tree is empty");
	else
		ShowAll_PostOrderTraverse(T);
	puts("----------------------");
}

// ����������������� head �ڵ� 
// �� TNode �����ķ�ʽ
void ShowNoHead_Post(const Tree T)
{
	puts("-------- Tree --------");
	if(T == NULL)
		puts("Tree is empty");
	else
		ShowNoHead_PostOrderTraverse(T);
	puts("----------------------");
}

// ����������������� head �ڵ�
// �� Node �����ķ�ʽ 
void ShowNoHeadbyNode_Post(const Tree T)
{
	puts("-------- Tree --------");
	if(T == NULL)
		puts("Tree is empty");
	else
		ShowNoHeadbyNode_PostOrderTraverse(T->child);
	puts("----------------------");
}

//ǰ��������У�����head�� 
Status ShowAll_PreOrderTraverse(const Tree T)
{
	int i=0;
	
	if(T==NULL) return ERROR;
	if( strcmp(T->name, ROOT) != 0)
	{
		printf("(%s) <--- (%s: %d)\n",(T->parent)->name, T->name ,T->data);	//��ʾ������ݣ����Ը���Ϊ�����Խ�����
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

// ǰ���������������head 
Status ShowNoHead_PreOrderTraverse(const Tree T)
{
	int i=0;
	
	if(T==NULL) return ERROR;
	if( strcmp(T->name, ROOT) != 0)
	{
		printf("(%s) <--- (%s: %d)\n",(T->parent)->name, T->name ,T->data);	//��ʾ������ݣ����Ը���Ϊ�����Խ�����
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
		ShowNoHead_PreOrderTraverse(P->tNode); //���������������
	}
	return OK;
}

// ǰ��������У�ʹ��Node��ʽ����
Status ShowAllbyNode_PreOrderTraverse(const LinkList L)
{
	int i=0;
	
	if(L==NULL) return ERROR;
	if( ! strcmp(L->tNode->name, ROOT))
	{
		puts("Forest operation is not supported temporarily!");
		return ERROR;
	}
	
	printf("(%s) <--- (%s: %d)\n", (L->tNode->parent)->name, L->tNode->name ,L->tNode->data);	//��ʾ�������
	
	Node* P = L;
	//if(L->tNode->child == NULL) return ERROR;
	if( strstr(P->tNode->name, HEAD) != NULL)	// ����ýڵ���head�ڵ�
	{
		int len = P->tNode->data;
		for(i=0; i< len; i++)
		{
			P = P->next;
			if(P == NULL) return ERROR;
			ShowAllbyNode_PreOrderTraverse(P);
		}
	}else	// ����ýڵ㲻��head�ڵ� 
	{
		ShowAllbyNode_PreOrderTraverse(P->tNode->child);
	}

	return OK;
}

//�����������������head  
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
		ShowNoHead_PostOrderTraverse(P->tNode); //���������������

		printf("(%s) <--- (%s: %d)\n",(P->tNode->parent)->name, P->tNode->name ,P->tNode->data);	
	}
	return OK;
}

//��������У�����head�� 
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


// �������������head��ʹ��Node��ʽ����
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
	if( strstr(P->tNode->name, HEAD) != NULL)	// ����ýڵ���head�ڵ� 
	{
		int len = P->tNode->data;
		for(i=0; i< len; i++)
		{
			P = P->next;
			if(P == NULL) return ERROR;
			ShowNoHeadbyNode_PostOrderTraverse(P);
		}
	}else	// ����ýڵ㲻��head�ڵ� 
	{
		ShowNoHeadbyNode_PostOrderTraverse(P->tNode->child);
		
		printf("(%s) <--- (%s: %d)\n", (P->tNode->parent)->name, P->tNode->name, P->tNode->data);
	}

	return OK;
}

// ���� T �а����Ʋ��ҽڵ��ֵ
TElemType Get_TNodeData(const Tree T, const char *fname)
{
	assert( T != NULL );
	assert( fname != NULL );
	
	TElemType data=0;
	
	_Get_TNodeData(T, fname, &data);
	
	return data;
}

// �ڲ����� 
// ���� T �а����Ʋ��ҽڵ��ֵ 
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
			_Get_TNodeData(P->tNode, fname, fE); //���������������
		}
		return OK;
	}
}

// ����ĳһ�ڵ㣬����ָ�� fT ָ��ýڵ� 
TNode * Get_TNode(Tree *pT, const char *fname)
{
	assert(pT != NULL);
	assert(fname != NULL);

	TNode *fT=NULL;
	
	_Get_TNode(pT, fname, &fT);
	
	return fT;
}

// ���� T �а����Ʋ��ҽڵ��ַ 
// ������head�ڵ� ��head�ڵ���Ϊ�ڲ���Ϣʹ�ã� 
// ��ΪҪ��T����&���������Ա���ʹ��ָ��ָ��T��ֻ��ָ����ܲ�����
// û��flag��־λ�ᵼ�� ���������һ���Ѿ����ϣ�����Ȼ��ѭ���������� 
// �����flag��־Ϊ����� �ڲ��ҵ�ֱ���˳� 
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



// ���� T �е�����Ϊ ParentName �ĸ��ڵ��²����ӽڵ� name
// name ���ܺ��� T ���нڵ��ظ� 
// ���ܲ��� head �ڵ��£�TNodeName��ֹ����ĳһhead���ƣ� 
// name ���ó��� NAME_MAX 
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
	
	Node *Lp;	//ר���������½ڵ� 	
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


// ���ҽڵ� Node ��λ�ã���ʹ��ָ�� fL ָ�� ָ�����ַ��ָ�� 
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

// ����������Ϊ�ڲ�ʹ��
// �ú���ʹ�ú��������Ž� flag2 �� 0 
// Ҫ��������Node��ʹ��  Get_Node ���� 
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

// ���� T �е� TNodeName �Ľڵ������½ڵ� 
// ���Բ��� head �ڵ��TNodeName��������ĳһhead���ƣ� 
Status InsetPosNext_TNode(Tree *pT, const char *TNodeName, const char * name, TElemType data)
{ 
	assert((*pT) != NULL);
	assert(TNodeName != NULL);
	assert(name != NULL);

	Node *fL=NULL, *fL2=NULL;
	
	_Get_Node(&((*pT)->child), TNodeName, &fL);	// ��ѯ�Ƿ���ڽڵ� TNodeName
	flag2 = 0;
	if(fL == NULL)
	{
		printf("node \'%s\' not found in Tree\n", TNodeName);
		return ERROR;
	}
	
	_Get_Node(&((*pT)->child), name, &fL2);	// ��ѯ�Ƿ��Ѵ��ڽڵ� name 
	flag2 = 0;
	if(fL2 != NULL)
	{
		printf("node \'%s\' already exists in Tree\n", name);
		return ERROR;
	}	
	
	Node *Lp;	//ר���������½ڵ� 	
	Lp = (Node *)malloc(sizeof(Node));
	Lp->tNode = (TNode *)malloc(sizeof(TNode));
	Lp->tNode->name = (char *)malloc(sizeof(char) * (strlen(name)+1));
	strcpy(Lp->tNode->name, name);
	Lp->tNode->data = data;
	
	Lp->tNode->parent = fL->tNode->parent;
	Lp->tNode->child = NULL;
	Lp->pre  = NULL;
	Lp->next = NULL;
	
	if(fL->next == NULL)	// �ڵ� TNodeName ���޽ڵ� 
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
	
	Node *P = L;	// �������� 
	static Node *K = NULL;	// �����ͷ��ڴ� 

	if( strstr(P->tNode->name, HEAD) != NULL)	// ����ýڵ���head�ڵ� 
	{
		int len = P->tNode->data;
		for(i=0; i< len + 1; i++)
		{
			P = P->next;
			if(i != 0)	// �����һ���ͷ�ͷ�ڵ� 
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
					//K->next = NULL;	//�Ѿ���NULL�� 
					
					free(K);
					K = NULL;
				}				
			} 
				
			if(P == NULL) return ERROR;
			_Delete_PostOrderTraverse(P);
		}
	}else	// ����ýڵ㲻��head�ڵ� 
	{
		_Delete_PostOrderTraverse(P->tNode->child);
		
		K = P;	
		
		free(K->tNode->name);
		K->tNode->name = NULL;
		K->tNode->parent = NULL;
		K->tNode->child = NULL;
		free(K->tNode);
		K->tNode = NULL;
		
		// ��� K ǰ����head�ڵ㣬�����޺���ڵ㣬��ô˳���ͷ� head �ڵ�
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

// ɾ���ڵ� TNodeName �Լ��ýڵ�������ӽڵ� 
// ����ɾ�� root �ڵ㣨����ֱ��ͨ���ú���ɾ����������
// ɾ�����һ���ӽڵ�ʱ���Զ�ɾ����head�ڵ� 
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
	
	_Get_Node(&((*pT)->child), TNodeName, &fL);	// ��ѯ�Ƿ���ڽڵ� TNodeName
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
		fL->tNode->parent->child->tNode->data -= 1;	//�ýڵ�ĸ��ڵ���ӽڵ����� 1 
	}
	
	_Delete_PostOrderTraverse(fL);
		
	if(fL->next != NULL )	// ����ýڵ��к�̽ڵ� 
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

// ɾ����
// �ͷ����нڵ㣬���� Root 
Status Delete_Tree(Tree *T)
{
	if( (*T) == NULL )
		return OK;
	
	char name[NAME_MAX+1];	// ���ȸ��ݸ�������ϰ�߸��� 

	Node *P = (*T)->child->next;
	Node *K=NULL;
	
	int i=0;
	int len = (*T)->child->tNode->data;
	for(i=0; i< len; i++)
	{
		K = P;
		P = P->next;
		strcpy(name, K->tNode->name); 
		Delete_TNode(T, name);			// ���鲻Ҫֱ��ʹ��K->tNode->name��ɾ��ʱ���ͷ�nameָ�� 
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


