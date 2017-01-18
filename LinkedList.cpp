#include <bits/stdc++.h>
using namespace std;
struct node
{
    int val;
    node *next;
};
class LinkedList
{
private:
    node *head;
    node *tail;
public :
    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }
    void addNodeFront(int val)
    {
        node *temp = new node();
        temp->val = val;
        temp->next = head;
        head = temp;
        if(tail == NULL)
            tail = head;
    }
    void addNodeBack(int val)
    {
        node *temp = new node();
        temp->val = val;
        tail->next = temp;
        tail = tail->next;
    }
    void deleteNodeFront()
    {
        if(head == NULL)
            return;
        node *temp = head;
        head = head->next;
        delete(temp);
        if(head == NULL)
            tail = NULL;
    }
    void deleteNodeBack()
    {
        if(tail == NULL)
            return;
        if(head == tail)
        {
            node* temp = head;
            head = tail = NULL;
            delete(temp);
            return;
        }
        node *temp = head;
        while(temp->next != tail)
            temp = temp->next;
        tail = temp;
        temp = temp->next;
        delete(temp);
        tail->next = NULL;
    }
    void Searching(int val)
    {
        //code here.
    }
    void removeNode(node* traverse,node *temp)
    {
        while(traverse!=NULL && traverse->next!=temp)
            traverse = traverse->next;
        if(traverse!=NULL)
            traverse->next = temp->next;
    }
    node* getMin(node *traverse)
    {
        int val = traverse->val;
        node* ans = traverse;
        while(traverse!=NULL)
        {
            if(val > traverse->val)
            {
                val = traverse->val;
                ans = traverse;
            }
            traverse = traverse->next;
        }
        return ans;
    }
    void sortSelectionSort()
    {
        node *traverse = head;
        node *Front = NULL;
        while(traverse!=NULL)
        {
            node *temp = getMin(traverse);
            if(Front == NULL)
            {
                Front = temp;
                head = Front;
            }
            else
            {
                Front->next = temp;
                Front = Front->next;
            }
            if(temp!=traverse)
                removeNode(traverse,temp);
            else
            {
                traverse = traverse->next;
                temp->next = NULL;
            }
        }
        node *temp = head;
        while(temp->next!=NULL)
            temp = temp->next;
        tail = temp;
    }
    void printLinkedList()
    {
        node *temp = head;
        while(temp!=NULL)
        {
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
    node* calMid(node *Start)
    {
        node *temp = Start->next->next;
        while(temp)
        {
            Start = Start->next;
            temp = temp->next;
            if(temp!=NULL)
                temp = temp->next;
        }
        return Start;
    }
    node* mergeSort(node *Start, node *End)
    {

        if(Start == End)
            return Start;
        node* mid = calMid(Start);
        node* midNext = mid->next;
        mid->next = NULL;
        Start = mergeSort(Start,mid);
        midNext = mergeSort(midNext,End);
        node* temp = Start;
        if(midNext->val < Start->val)
            Start = midNext;
        node* prev = NULL;
        node* temp2 = midNext;
        bool flag = 0;
        while(temp&&temp2)
        {
            if(temp2->val < temp->val)
            {
                node *temp3 = temp2->next;
                if(prev!=NULL)
                    prev->next = temp2;
                temp2->next = temp;
                prev = temp2;
                temp2 = temp3;
            }
            else
            {
                prev = temp;
                temp = temp->next;
            }
        }
        if(temp==NULL)
            prev->next = temp2;
        return Start;
    }
    void sortMergeSort(){
       head = mergeSort(head,tail);
    }
};
int main()
{
    LinkedList L1;
    L1.addNodeFront(1);
    L1.printLinkedList();
    L1.addNodeBack(-1);
    L1.printLinkedList();
    L1.deleteNodeFront();
    L1.printLinkedList();
    L1.deleteNodeBack();
    L1.printLinkedList();
    for(int i=0; i<10; i++)
    {
        L1.addNodeFront(10-i);
    }
    for(int i=0; i<10; i++)
    {
        L1.addNodeBack(10-i);
    }
    L1.printLinkedList();
    L1.sortSelectionSort();
    L1.printLinkedList();
}
