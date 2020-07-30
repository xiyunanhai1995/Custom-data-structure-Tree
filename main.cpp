#include"tree.h"


int main()
{	
	Tree T=NULL; 	//头指针
	InitTree(&T); 	//创建 T的 ROOT 节点 
	
	Inset_childTNode(&T, ROOT, "A", 1);		// 在 ROOT 节点下插入子节点 A 
	Inset_childTNode(&T, ROOT, "B", 2);
	Inset_childTNode(&T, ROOT, "C", 3);
	Inset_childTNode(&T, "A", "D", 4);
	Inset_childTNode(&T, "B", "E", 5);
	InsetPosNext_TNode(&T, "E", "F", 6);	// 在 E 节点后插入节点 F 

	Inset_childTNode(&T, "jack", "F", 6);	// invalid，树 T 中不存在节点 jack 
	Inset_childTNode(&T, "A", "D", 6);		// invalid，树 T 中已经存在节点 D 
	ShowALL_Pre(T);		// 显示树 T （前序遍历） 
	
	TElemType data=0;
	data = Get_TNodeData(T, "E");	// 查找节点 E 的 data 
	printf("E: %d\n", data);
	
	TNode *fT=NULL; 
	fT = Get_TNode(&T, "E");		// 查找节点 E，并令指针 fT指向其地址 （TNode方式） 
	printf("(%s) <--- (%s: %d)\n", (fT->parent)->name, fT->name, fT->data);
	
	Node *fL=NULL; 
	fL = Get_Node(&T, "E");			// 查找节点 E，并令指针 fT指向其地址 （Node 方式） 
	printf("(%s) <--- (%s: %d)\n", (fL->tNode->parent)->name, fL->tNode->name, fL->tNode->data);
	
	//Delete_TNode(&T, "B");	// 删除节点 B 
	Delete_TNode(&T, "A");	// 删除节点 A 
	Delete_TNode(&T, "E");
	Delete_TNode(&T, "D");	//invalid，不存在节点 D（删除 A 时，已经将其所有子节点删除，包括 D） 
	
	ShowALL_Pre(T);
	
	Delete_Tree(&T);		// 删除树 T 
	
	ShowALL_Pre(T);
	
	InitTree(&T);			// 重新建立树 T （创建 T 的 ROOT 节点） 
	Inset_childTNode(&T, ROOT, "A", 1);
	Inset_childTNode(&T, ROOT, "B", 2);
	InsetPosNext_TNode(&T, "B", "C", 3);
	
	ShowALL_Pre(T);

	return 0;
}








