#include <iostream>
#include <vector>
#include <stack>

struct NodeList{
	int val;
	NodeList* next;
	NodeList(int a) :val(a), next(NULL) {}
};

int printListFromTailToHead(NodeList* head) {
	int ret = 0;
	std::vector<int> tmpv;
	std::stack<int> tmpStack;
	NodeList* tmphead = head;
	while (tmphead != NULL) {
		tmpStack.push(tmphead->val);
		tmphead = tmphead->next;
	}
	while (!tmpStack.empty()) {
		tmpv.push_back(tmpStack.top());
		tmpStack.pop();
	}
	for (auto i : tmpv) {
		std::cout << i << ' ';
	}


	return ret;
}

int main() 
{	//NodeList: 1-->2-->3;
	NodeList* phead;
	NodeList node1(1);
	phead = &node1;
	NodeList node2(2);
	node1.next = &node2;
	NodeList node3(3);
	node2.next = &node3;

	NodeList* pnode = phead;
	std::cout << "original NodeList:\n" << std::endl;
	while (pnode != NULL) {
		std::cout << pnode->val << ' ';
		pnode = pnode->next;
	}
	std::cout << "TailToHead NodeList:\n" << std::endl;
	printListFromTailToHead(phead);

	return 0;
}