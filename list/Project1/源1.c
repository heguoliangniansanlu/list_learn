#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define MAXSIZE 100
typedef int ElemType;
typedef struct 
{
	ElemType data[MAXSIZE];
	int length;
}SeqList;

void initList(SeqList* L)
{
	L->length = 0;
}
void appendElem(SeqList* L, ElemType e) 
{
	if (L->length >=MAXSIZE)
	{
		printf("表已满\n");
		return 0;
	}
	L->data[L->length] = e;
	L->length++;
	return 1;
}
void ListElem(SeqList* L) 
{
	for (int i = 0; i < L->length; i++)
	{
		printf("%d ", L->data[i]);
	}
	printf("\n");

}
void insertElem(SeqList *L,int pos , ElemType e)
{
	for (int i = L->length; i >= pos-1; i--)
	{
		L->data[i]=L->data[i-1];
	}
	L->data[pos-1] = e;
	L->length++;
}
void deleteElem(SeqList* L, int pos)
{
	for (int i = pos-1; i < L->length; i++)
	{
		L->data[i] = L->data[i+1];
    }
	L->length--;
}
int findElem(SeqList *L,ElemType e)
{
	for (int i =0;i < L->length;i++ )
	{
		if (L->data[i] == e)
		{
			printf("%d", i + 1);
			
		}
		
	}
	return 0;
}

int main(int argc,char const *argv[])
{
	SeqList list;
	initList(&list);
	printf("初始化成功，目前长度占用%d\n",list.length);
	printf("目前占用字节%zu\n",sizeof(list.data));
	appendElem(&list, 1);
	appendElem(&list, 22);
	appendElem(&list, 34);
	appendElem(&list, 56);
	//insertElem(&list, 2, 11);
	//deleteElem(&list, 3);
	//findElem(&list, 22);
	ListElem(&list);
	

 }