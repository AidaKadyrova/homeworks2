#pragma once
#include "comparator.h"
#include <QList>
/**
  * @class Sorter
  * it has one public method bubbleSort
  */
template <typename T>
class Sorter
{
public:
    Sorter(){}
    /**
      * methon sorts an array of template
      * @param list - list which is wanted to be sorted
      * @param c - is comparator, which can compare template elements
      * methon returns sorted list
      */
    QList<T>* bubbleSort(QList<T>* &list, Comparator<T>* c)
    {
    int listSize = list->size();
    for (int i = 0; i < listSize - 1; i++)
        for (int j = i; j < listSize; j++)
            if (c->compare(list->at(i), list->at(j)) > 0)
                list->swap(i, j);
    return list;
    }
};
