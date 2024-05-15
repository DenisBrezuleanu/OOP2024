#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

template <typename K,typename V,typename I=int>
class Map {
    int currentindex, maxindex;
public:
    struct elem {
        K key;
        V val;
        I index;
        void operator=(V newval)
        {
            this->val = newval;
        }
    }*vec;
    Map()
    {
        maxindex = 100;
        currentindex = 0;
        vec = (elem*)malloc(maxindex *sizeof(elem));
    }
    elem& operator[](K newkey)
    {
        for (int i = 0;i < currentindex;i++)
            if (vec[i].key == newkey)
                return vec[i];
        vec[currentindex].key = newkey;
        vec[currentindex].index = currentindex;
        currentindex++;
        return vec[currentindex-1];
    }
     void Set(K newkey,V newval)
    {
         for (int i = 0;i < currentindex;i++)
             if (vec[i].key == newkey)
             {
                 vec[i].val = newval;
                 return;
             }
         vec[currentindex].key = newkey;
         vec[currentindex].index = currentindex;
         vec[currentindex].val = newval;
         currentindex++;
    }
     bool Get(const K& newkey, V& newval) {
         for (int i = 0;i < currentindex;i++)
             if (vec[i].key == newkey)
             {
                 newval=vec[i].val;
                 return true;
             }
         return false;
     }
     int Count()
     {
         return currentindex;
     }
     bool Delete(const K& newkey)
     {
         for (int i = 0;i < currentindex;i++)
             if (vec[i].key == newkey)
             {
                 for (int j = i;j < currentindex - 1;j++)
                 {
                     vec[j] = vec[j + 1];
                 }
                 currentindex--;
                 return true;
             }
         return false;
     }
     void Clear()
     {
         this->currentindex = this->maxindex = 0;
         free(this->vec);
     }
     bool Includes(Map<K, V>& newmap)
     {
         if (this->Count() < newmap.Count())
         {
             for (int i = 0;i < this->Count();i++)
             {
                 bool ok = false;
                 for (int j = 0;j < newmap.Count();j++)
                     if (this->vec[i].key == newmap.vec[j].key)
                     {
                         ok = true;
                         break;
                     }
                 if (!ok)
                     return false;
             }
             return true;
         }
         else {
             for (int i = 0;i < newmap.Count();i++)
             {
                 bool ok = false;
                 for (int j = 0;j < this->Count();j++)
                     if (this->vec[i].key == newmap.vec[j].key)
                     {
                         ok = true;
                         break;
                     }
                 if (!ok)
                     return false;
             }
             return true;
         }
     }
    elem* begin() { return &vec[0]; }
    elem* end() { return &vec[currentindex]; }
};
int main()
{
    Map<int, const char*> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    m[20] = "result";
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    return 0;
}
