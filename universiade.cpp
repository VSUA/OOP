
#include "universiade.h"

Person *Universiade::getEndOfList()
{
    Person *tmp;
    tmp = StartOfList;
    while(tmp)
    {
        if(tmp->next == nullptr)
        {
            return tmp;
        }
        tmp = tmp->next;
    }
}

void Universiade::AddElement(string name1, string surname1, int result1, string nameOfUniversity1)
{
    Person *curr = new Person;
    Person *tmp;
    if(!StartOfList)
    {
        this->StartOfList = curr;
        curr->prev = nullptr;
        curr->name = name1;
        curr->surname = surname1;
        curr->result = result1;
        curr->nameOfUniversity = nameOfUniversity1;
        curr->next = nullptr;

    } else {
        tmp = getEndOfList();
        tmp->next = curr;
        curr->prev = tmp;
        curr->name = name1;
        curr->surname = surname1;
        curr->result = result1;
        curr->nameOfUniversity = nameOfUniversity1;
        curr->next = nullptr;
    }
}

void LeaderList::SetLeader()
{
    Person *tmp = StartOfList;
    Person *Max = StartOfList;
    while(tmp)
    {
        if(tmp->result > Max->result)
        {
            Max = tmp;
        }
        tmp = tmp->next;
    }
    Leader = Max;
}

int WorkWithList::Size()
{
    Person *tmp;
    tmp = StartOfList;
    int i = 0;
    while(tmp)
    {
        tmp = tmp->next;
        i++;
    }
    return i;
}

void MoreBetter::Sort()
{
    Person *pp1, *pp2, *pTmp = nullptr, *pPrev1, *pPrev2 , *pNext1, *pNext2;

    for(pp1 = StartOfList; pp1 != nullptr; pp1 = pp1->next)
    {
        for (pp2 = pp1->next; pp2 != nullptr; pp2=pp2->next )
        {
            pPrev1 = pp1->prev;
            pPrev2 = pp2->prev;
            pNext1 = pp1->next;
            pNext2 = pp2->next;

            if(pp1->result < pp2->result)
            {
                if(pp1->next == pp2) //Зміна розташування елементів списку між собою, якщо вони розташовані послідовно
                {
                    //pPrev1->next = pp2;

                    pp2->prev = pp1->prev;
                    pp1->prev = pp2;

                    pTmp=pp2->next;
                    pp2->next = pp1;
                    pp1->next= pTmp;

                } else //Зміна розташування елементів списку між собою, якщо вони не розташовані послідовно
                {
                    pPrev2->next = pp1;
                    pNext1->prev =pp2;

                    pTmp = pp2->next;
                    pp2->next = pp1->next;
                    pp1->next = pTmp;

                    pTmp = pPrev1;
                    pp1->prev = pp2->prev;
                    pp2->prev = pTmp;
                }

                if(!pPrev1) //Зміна адреси на головного елемента списку
                {
                    StartOfList = pp2;

                }else
                {
                    pPrev1->next = pp2;
                }

                if(pNext2)
                {
                    pNext2->prev = pp1;
                }
                pTmp = pp1;
                pp1=pp2;
                pp2=pTmp;

            }

        }

    }
}


void SmallerBetter::Sort()
{
    Person *pp1, *pp2, *pTmp = nullptr, *pPrev1, *pPrev2 , *pNext1, *pNext2;

    for(pp1 = StartOfList; pp1 != nullptr; pp1 = pp1->next)
    {
        for (pp2 = pp1->next; pp2 != nullptr; pp2=pp2->next )
        {
            pPrev1 = pp1->prev;
            pPrev2 = pp2->prev;
            pNext1 = pp1->next;
            pNext2 = pp2->next;

            if(pp1->result > pp2->result)
            {
                if(pp1->next == pp2) //Зміна розташування елементів списку між собою, якщо вони розташовані послідовно
                {
                    //pPrev1->next = pp2;

                    pp2->prev = pp1->prev;
                    pp1->prev = pp2;

                    pTmp=pp2->next;
                    pp2->next = pp1;
                    pp1->next= pTmp;

                } else //Зміна розташування елементів списку між собою, якщо вони не розташовані послідовно
                {
                    pPrev2->next = pp1;
                    pNext1->prev =pp2;

                    pTmp = pp2->next;
                    pp2->next = pp1->next;
                    pp1->next = pTmp;

                    pTmp = pPrev1;
                    pp1->prev = pp2->prev;
                    pp2->prev = pTmp;
                }

                if(!pPrev1) //Зміна адреси на головного елемента списку
                {
                    StartOfList = pp2;

                }else
                {
                    pPrev1->next = pp2;
                }

                if(pNext2)
                {
                    pNext2->prev = pp1;
                }
                pTmp = pp1;
                pp1=pp2;
                pp2=pTmp;

            }

        }

    }
}
