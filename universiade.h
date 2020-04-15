#include <string>
using namespace std;
#ifndef UNIVERSIADE_H
#define UNIVERSIADE_H


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
public:
    static string name;
    static int day ;
    static int mounth ;
    static int year;

public:
    Universiade(){};
    string print()
    {
        return "Universiade";
    }

    string print(string str)
    {
        return str+"Universiade";
    }


    //Universiade(string name, int day, int mounth, int year);
    void setDate(int day1,int mounth1, int year1)
    {
        day = day1;
        mounth = mounth1;
        year = year1;
    };
    void setName(string name1)
    {
        name = name1;
    };
    string getName()
    {
        return name;
    };
    int getday()
    {
        return day;
    };
    int getmounth()
    {
        return mounth;
    };
    int getyear()
    {
        return year;
    };

};


class MoreBetter : public Universiade
{
protected:

    Person *StartOfList;
    Person *Leader;

protected:

    Person *getEndOfList();

public:
    MoreBetter(){};
    string print()
    {
        return "MoreBetter";
    }

    string print(string str)
    {
        return str+"MoreBetter";
    }
    Person *GetLeader(){return Leader;}
    void SetLeader();
    void AddElement(string name, string surname, int result, string nameOfUniversity);
    void Sort();
    int Size();
    Person *GetStart();

};

class SmallerBetter : public Universiade
{
protected:

    Person *StartOfList;
    Person *Leader;

protected:

    Person *getEndOfList();

public:
    SmallerBetter(){};
    string print()
    {
        return "SmallerBetter";
    }

    string print(string str)
    {
        return str+"SmallerBetter";
    }

    Person *GetLeader(){return Leader;}
    void SetLeader();
    void AddElement(string name, string surname, int result, string nameOfUniversity);
    void Sort();
    int Size();
    Person *GetStart();


};

#endif // UNIVERSIADE_H
