#ifndef COURSE_H_INCLUDED
#define COURSE_H_INCLUDED

#include"Node.h"
#include"String.h"
#include <stdlib.h>
#include <fstream>
#include <stdio.h>

using namespace std;

class Course
{
private:
    struct Node course[50];
    FILE *fp;
    int maxcourses[10];
    vector<int> cnum[8];
	vector<int> number;
public:
    Course(){}
    ~Course(){}
    void Nodebuffer()
    {
        fp = fopen("course_inf.txt","r");
        char tmp[100];
        int curr = 0;
        while(!feof(fp))
        {
            fgets(tmp,100,fp);
            if(tmp[0]>='0'&&tmp[0]<='9')
            {
                Getnum(tmp);
                for(int i=0;i<8;i++)
                {
                    maxcourses[i] = number[7-i];
                }
                number.clear();
            }
            if(tmp[0]=='c')
            {
                Getnum(tmp);
                Getname(tmp,course[curr].coursename);
                course[curr].num = number.back();
                number.pop_back();
                course[curr].coursetime = number.back();
                number.pop_back();
                course[curr].semester = number.back();
                number.pop_back();
                for(int i = number.size()-1;i>=0;i--)
                {
                    course[curr].prenum.push_back(number[i]);
                }
                number.clear();
                curr++;
            }
        }
        fclose(fp);
    }
    void Getnum(char *str)
    {
        for(int i = strlen(str)-1;i>=0;i--)
        {
            if(str[i]>='0'&&str[i]<='9')
            {
                if(str[i-1]>='0'&&str[i-1]<='9')
                {
                    number.push_back((int)(str[i-1] - '0') * 10 + (str[i] - '0'));
                    i--;
                }
                else
                {
                    number.push_back((int)(str[i]-'0'));
                }
            }
        }
    }
    void Getname(char *str1,char *str2)
    {
        int j = 0;
        for(int i = 0;i<strlen(str1);i++)
        {
            if(str1[i]>='0'&&str1[i]<='9')
            {
                continue;
            }
            else if(str1[i]!=' '&&str1[i]!='c')
            {
                str2[j] = str1[i];
                j++;
            }
        }
    }
    void firstOrder()
    {
        for(int i=0;i<38;i++)
        {
            if(course[i].semester != 0)
            {
                cnum[course[i].semester-1].push_back(course[i].num);
                course[i].ifordered = true;
            }
        }
    }
    void secondOrder()
    {
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<38;j++)
            {
                if(course[j].prenum.empty()&&!course[j].ifordered)
                {
                    if(cnum[i].size()<maxcourses[i])
                    {
                        cnum[i].push_back(course[j].num);
                        for(int k=0;k<38;k++)
                        {
                            for(vector<int>::iterator t = course[k].prenum.begin();t != course[k].prenum.end();t++)
                            {
                                if(*t==course[j].num)
                                {
                                    course[k].prenum.erase(t);
                                    break;
                                }
                            }
                        }
                        course[j].ifordered = true;
                    }
                }
            }
        }
    }
    void NodePrinthelp(int m)
    {
        if(course[m].num<10)
        {
            printf("c0%d %s\n",course[m].num,course[m].coursename);
        }
        else
        {
            printf("c%d %s\n",course[m].num,course[m].coursename);
        }
    }
    void Printhelp()
    {
        for(int i=0;i<8;i++)
        {
            printf("第 %d 学期(%d门)：\n" ,i+1,maxcourses[i]);
		    vector<int>::iterator t;
		    for(t = cnum[i].begin();t != cnum[i].end();t++)
            {
			    NodePrinthelp(*t-1);
            }
        }
    }
    void run()
    {
        Nodebuffer();
        firstOrder();
        secondOrder();
        Printhelp();
    }
};

#endif // COURSE_H_INCLUDED
