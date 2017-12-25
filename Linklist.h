#ifndef LINKLIST_H_
#define LINKLIST_H_


#include <iostream>
#include <string>
#include "String.h"

using namespace std;

//定义结点模板
struct DblNode
{
    //数据成员
    DblNode* last;
    DblNode* next;
    String data;
    DblNode();
    DblNode(DblNode* last1,DblNode* next1,String data1);
};

DblNode::DblNode()
{
    last = next = NULL;
}

DblNode::DblNode(DblNode* last1,DblNode* next1,String data1)
{
    last=last1;
    next=next1;
    data=data1;
}

class Linklist
{
protected:
    int currline;
public:
    DblNode* head;
    DblNode* tail;
    DblNode* curr;

    Linklist();
    ~Linklist();
    int length() const;
    void Tofirstline();
    void Toend();
    void Tolastline();
    void Tonextline();
    void Topointedline(int linenumber);
    void Insert(int linenumber,String newline);
    void Delete(int linenumber);
    void ReplaceLine(String S,int linenumber);
    DblNode* Getline(int linenumber);
};

Linklist::Linklist()
{
    head=tail=curr=new DblNode();
    if(!head)
        cout<<"error！"<<endl;
}

Linklist::~Linklist()
{
}

int Linklist::length() const
{
    int len = 0;
    for(DblNode* tmpline = head->next;tmpline!=NULL;tmpline=tmpline->next)
    {
        len++;
    }
    return len;
}

void Linklist::Tofirstline()
{
    curr = head->next;
}

void Linklist::Toend()
{
    curr = tail;
}

void Linklist::Tolastline()
{
    curr = curr->last;

}

void Linklist::Tonextline()
{
    curr = curr->next;
}

void Linklist::Topointedline(int linenumber)
{
    DblNode* temp = head;
    for(int i=0;i<linenumber;i++)
        temp = temp->next;
    curr = temp;
}

void Linklist::Insert(int linenumber,String e)
{
    DblNode *tmpLine,*nextLine,*newLine;
    tmpLine = Getline(linenumber-1);
    nextLine = tmpLine->next;
    newLine = new DblNode(tmpLine,nextLine,e);
    tmpLine->next = newLine;
	if (nextLine!=NULL)
		nextLine->last = newLine;
    linenumber++;
}

void Linklist::Delete(int linenumber)
{
    DblNode* tmpLine;
    tmpLine = Getline(linenumber);
    tmpLine->last->next = tmpLine->next;
    tmpLine->next->last = tmpLine->last;
    linenumber--;
    delete tmpLine;
}

void Linklist::ReplaceLine(String S,int linenumber)
{
    DblNode * temp = Getline(linenumber);
    temp->data = S;
}

DblNode*Linklist::Getline(int linenumber)
{
    DblNode* tmpLine = head;
    int curLine = 0;
    while(tmpLine!= NULL&&curLine<linenumber)
    {
        tmpLine = tmpLine->next;
        curLine++;
    }
    if(tmpLine!=NULL&&curLine==linenumber)
    {
        return tmpLine;
    }
    else
    {
        return NULL;
    }
}


#endif // LINKLIST_H_
