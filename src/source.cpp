/*
 * 想法：求树高同时保存当前最长路径
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZE 10

typedef struct Node {
	Node* left;
	Node* right;
	int data;
}Node, *pNode;

typedef struct NodeStack {
	pNode node;
	int flag;
}NodeStack,*pNodeStack;

pNode mmalloc(int value) {
	pNode node = (pNode)malloc(sizeof(Node));
	node->data = value;
	node->left = NULL;
	node->right = NULL;
	return node;
}

pNodeStack smalloc() {
	pNodeStack node = (pNodeStack)malloc(sizeof(NodeStack));
	node->node = NULL;
	node->flag = 1;
	return node;
}

/*
 *          r1
 *       /     \
 *     c2      c3
 *    /  \       / \
 *   c4  c5 c6 c7
 *              /
 *           c8
 */
void initTree(pNode &root) {
	pNode lchild, rchild;
	root = mmalloc(1);

	lchild = mmalloc(2);
	rchild = mmalloc(3);
	root->left = lchild;
	root->right = rchild;

	lchild = mmalloc(4);
	rchild = mmalloc(5);
	root->left->left = lchild;
	root->left->right = rchild;

	lchild = mmalloc(6);
	rchild = mmalloc(7);
	root->right->left = lchild;
	root->right->right = rchild;

	lchild = mmalloc(8);
	root->right->left->left = lchild;
}

void initStack(pNodeStack* stack) {
	for (int i = 0; i < MAXSIZE; i++) {
		stack[i] = smalloc();
	}
}

int BTDeepth(pNode &root) {
	if (root == NULL)
		return 0;
	int llen = BTDeepth(root->left);
	int rlen = BTDeepth(root->right);
	return llen > rlen ? llen + 1 : rlen + 1;
}

pNode* path(pNode &root, int &high) {
	pNodeStack* s = (pNodeStack*)malloc(sizeof(pNodeStack)*MAXSIZE);
	pNode* s1 = (pNode*)malloc(sizeof(pNode)*MAXSIZE);
	pNode p = root, q = NULL;
	initStack(s);
	int tops = 0, tops1 = 0;
	int i = 0;
	high = BTDeepth(root);
	while ((p || /*IsEmpty(s)*/tops) && (i != high)) {
		if (p) {
			/*Push(s, p);*/
			s[tops]->node = p; tops++;
			i++;
			p = p->left;
		}
		else {
			/*Pop(s, p);*/
			p = s[--tops]->node;
			i--;
			p = p->right;
		}
	}
	while (tops) {
		q = s[--tops]->node;/*Pop(s, p);*/
		s1[tops1++] = q;/*Push(s1, q);*/
	}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
	return s1;
}

void NodeCopy(pNode* src, pNode* des, int len) {
	for (int i = 0; i < len; i++) {
		des[i] = src[i];
	}
}

void NodeCopy(pNodeStack* src, pNode* des, int len) {
	for (int i = 0; i < len; i++) {
		des[i] = src[i]->node;
	}
}

void print(pNode* res, int len) {
	printf("path:");
	for (int i = 0; i < len; i++)
	{
		printf("%d", res[i]->data);
	}
	printf("\n");
}

int leh(pNode root, pNode* &res, pNode* &temp, int &max, int len) {
	if (root == NULL) {
		if (len > max) {//需要保存这条路径
			printf("\n");
			max = len;
			NodeCopy(temp, res, max);
			return 1;
		}
		return 0;
	}
	printf("%d", root->data);
	temp[len] = root;
	++len;
	leh(root->left, res, temp, max, len);
	leh(root->right, res, temp, max, len);
	return len;
}

//非递归实现
int leh2(pNode root, pNode* &res, int &max) {
	pNodeStack* stack = (pNodeStack*)malloc(sizeof(pNodeStack)*MAXSIZE);
	initStack(stack);
	int len = 0, top = 0;
	pNode p = root;
	while (p != NULL || top != 0) {//后序遍历
		if (p != NULL) {//p不为空，则入栈，flag=1
			stack[top]->node = p;
			stack[top++]->flag = 1;
			len++;
			p = p->left;
		}
		else {//p为空，flag=1，无操作，如果flag=2，则弹栈，最后访问栈顶右孩子
			p = stack[top - 1]->node;
			int sign = stack[--top]->flag;
			if (sign == 1) {
				stack[top]->node = p;
				stack[top++]->flag = 2;
				p = p->right;
				if (top > max) {
					max = top;
					NodeCopy(stack, res, max);
				}
			}
			else {
				printf("%d", p->data);
				p = NULL;
			}
		}
	}
	return 0;
}

int main() {
	pNode root;
	initTree(root);
	/*pNode* res, *temp;
	int max = 0, len = 0;
	res = (pNode*)malloc(sizeof(pNode)*MAXSIZE);
	temp = (pNode*)malloc(sizeof(pNode)*MAXSIZE);
	leh(root, res, temp, max, len);
	leh2(root, res, max);
	printf("\nmax=%d\n", max);
	print(res, max);
	*/
	int len;
	pNode* res = path(root, len);
	print(res, len);
	scanf/*_s*/("%d", &len);
}
