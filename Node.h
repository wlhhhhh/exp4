#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include<iostream>
#include<vector>
#include"Linklist.h"

struct Node
{
    int num;
    char coursename[30];
    int coursetime;
    int semester;
    vector<int> prenum;
    bool ifordered = false;
};


#endif // NODE_H_INCLUDED
