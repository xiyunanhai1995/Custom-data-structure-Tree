#include"tree.h"


int main()
{	
	Tree T=NULL; 	//ͷָ��
	InitTree(&T); 	//���� T�� ROOT �ڵ� 
	
	Inset_childTNode(&T, ROOT, "A", 1);		// �� ROOT �ڵ��²����ӽڵ� A 
	Inset_childTNode(&T, ROOT, "B", 2);
	Inset_childTNode(&T, ROOT, "C", 3);
	Inset_childTNode(&T, "A", "D", 4);
	Inset_childTNode(&T, "B", "E", 5);
	InsetPosNext_TNode(&T, "E", "F", 6);	// �� E �ڵ�����ڵ� F 

	Inset_childTNode(&T, "jack", "F", 6);	// invalid���� T �в����ڽڵ� jack 
	Inset_childTNode(&T, "A", "D", 6);		// invalid���� T ���Ѿ����ڽڵ� D 
	ShowALL_Pre(T);		// ��ʾ�� T ��ǰ������� 
	
	TElemType data=0;
	data = Get_TNodeData(T, "E");	// ���ҽڵ� E �� data 
	printf("E: %d\n", data);
	
	TNode *fT=NULL; 
	fT = Get_TNode(&T, "E");		// ���ҽڵ� E������ָ�� fTָ�����ַ ��TNode��ʽ�� 
	printf("(%s) <--- (%s: %d)\n", (fT->parent)->name, fT->name, fT->data);
	
	Node *fL=NULL; 
	fL = Get_Node(&T, "E");			// ���ҽڵ� E������ָ�� fTָ�����ַ ��Node ��ʽ�� 
	printf("(%s) <--- (%s: %d)\n", (fL->tNode->parent)->name, fL->tNode->name, fL->tNode->data);
	
	//Delete_TNode(&T, "B");	// ɾ���ڵ� B 
	Delete_TNode(&T, "A");	// ɾ���ڵ� A 
	Delete_TNode(&T, "E");
	Delete_TNode(&T, "D");	//invalid�������ڽڵ� D��ɾ�� A ʱ���Ѿ����������ӽڵ�ɾ�������� D�� 
	
	ShowALL_Pre(T);
	
	Delete_Tree(&T);		// ɾ���� T 
	
	ShowALL_Pre(T);
	
	InitTree(&T);			// ���½����� T ������ T �� ROOT �ڵ㣩 
	Inset_childTNode(&T, ROOT, "A", 1);
	Inset_childTNode(&T, ROOT, "B", 2);
	InsetPosNext_TNode(&T, "B", "C", 3);
	
	ShowALL_Pre(T);

	return 0;
}








