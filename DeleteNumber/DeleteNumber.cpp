#include <iostream>
using namespace std;

#define MAXNUM 256


struct LinkNode
{
	char nID;
	struct LinkNode* pNext;
};

int main(void)
{
	char* InputFile = "input.txt";
	char* OutputFile = "output.txt";

	LinkNode*  head = new LinkNode;
	head->pNext = NULL;

	LinkNode* pNode, *eNode = head;

	char  String[MAXNUM];
	int   j = 0, size = 0;
	int   k;

	for (int i = 0; i < MAXNUM; i++)
	{
		String[i] = 'a';
	}

	FILE* pInput = fopen(InputFile, "r");
	FILE* pOutput = fopen(OutputFile, "wt+");

	cout << "------------" << "Delete Number Problem:" << "-----------" << endl;
	fgets(String, MAXNUM - 1, pInput);
	cout << "Oringin number is:";
	while (String[j] != '\n')
	{	
		pNode = new LinkNode;
		pNode->nID = String[j];
		cout << pNode->nID;
		pNode->pNext = NULL;

		eNode->pNext = pNode;
		eNode = pNode;
		j++;
		size++;
	}
	cout << endl;
	
	fscanf(pInput, "%d", &k);
	cout << "Delete Number is:" << k << endl;

	if (k > size)
	{
		cout << "The number is out of range!" << endl;
		return -1;
	}
	if (k == size)
	{
		fprintf(pOutput, "No Solution");
		return 0;
	}

	int i, count, n;
	LinkNode* current = head->pNext;

	while (k > 0)
	{
		LinkNode* tmp;
		count = 0;
		n = 0;
		for (i = 0; (i < size - 1) && (current->nID <= current->pNext->nID); i++)
		{
			current = current->pNext;
			count++;
		}

		current = head->pNext;
		while (n < count - 1)
		{
			current = current->pNext;
			n++;
		}
		tmp = current->pNext;
		current->pNext = tmp->pNext;
		delete tmp;
		tmp = NULL;

		current = head->pNext;
		size--;
		k--;
	}

	cout << "Result is :";
	LinkNode* list = head->pNext;
	while (list != NULL)
	{
		fprintf(pOutput, "%c", list->nID);
		cout << list->nID;
		list = list->pNext;
	}
	cout << endl;

	while (head->pNext != NULL)
	{
		LinkNode* tmp;
		tmp = head->pNext;
		head->pNext = tmp->pNext;
		delete tmp;
		tmp = NULL;
	}

	delete head;
	head = NULL;

	fclose(pInput);
	fclose(pOutput);

	system("pause");
	return 0;
}