//
// Created by Vlad on 13.04.2020.
//
#include <string>
using namespace std;

#ifndef OOP9_UNIVERSIADE_H
#define OOP9_UNIVERSIADE_H

struct Person
{
    string name;
    string surname;
    string nameOfUniversity;
    int result;
    struct Person *next;
    struct Person *prev;
};

class Universiade
{
protected:
     string name;
    static int day ;
    static int mounth ;
    static int year;
    Person *StartOfList;
    Person *getEndOfList();

public:
    Universiade(){StartOfList = nullptr;};
    virtual string print()
    {
        return "Universiade";
    }

    virtual string print(string& str)
    {
        return str+"Universiade";
    }
    //Universiade(string name, int day, int mounth, int year);
    static void setDate(int day1,int mounth1, int year1)
    {
        day = day1;
        mounth = mounth1;
        year = year1;
    };
     void setName(const string& name1)
    {
        name = name1;
    };
     string getName()
    {
        return name;
    };
    static int getday()
    {
        return day;
    };
    static int getmounth()
    {
        return mounth;
    };
    static int getyear()
    {
        return year;
    };
    Person *GetStart(){return StartOfList;};
    void AddElement(string name, string surname, int result, string nameOfUniversity);
    virtual ~Universiade(){};

};

class LeaderList: virtual public Universiade
{
protected:
    Person *Leader;

public:
    Person *GetLeader(){return Leader;}
    void SetLeader();
    virtual string print()
    {
        return "LeaderList";
    };

    virtual string print(string& str)
    {
        return str+"LeaderList";
    };
    virtual ~LeaderList(){};
};

class WorkWithList: virtual public Universiade
{
public:
    virtual void Sort() = 0;
    int Size();
    virtual string print()
    {
        return "WorkWithList";
    };

    virtual string print(string& str)
    {
        return str+"WorkWithList";
    };
    virtual ~WorkWithList(){};
};

class MoreBetter: public LeaderList, public WorkWithList
{
public:
    string print()
    {
        return "MoreBetter";
    }

    string print(string& str)
    {
        return str+"MoreBetter";
    }
    void Sort();
    ~MoreBetter(){};
};

class SmallerBetter: public LeaderList, public WorkWithList
{
public:
    string print()
    {
        return "SmallerBetter";
    }

    string print(string& str)
    {
        return str+"SmallerBetter";
    }
    void Sort();
    ~SmallerBetter(){};
};

#endif //OOP9_UNIVERSIADE_H
