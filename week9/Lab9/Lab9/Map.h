#pragma once

template<class K, class V>
class Map
{
    struct elements
    {
        K key;
        V value;
        int index;

        V operator=(const V& v)
        {
            value = v;
            return value;

        }
    };
    elements* elem=new elements[3];
    int count=0;
    int allocated_space = 2;
  public:
    elements& operator[](const K& key)
    {
        for (int i = 0; i < count; i++)
            if (elem[i].key == key)
                return elem[i];
        V* aux_val = new V();
        Set(key,*aux_val);
        return elem[count - 1];
    }

    void Set(const K& key,const V& value)
    {
        for (int i=0;i<count;i++)
        {
            if (elem[i].key==key)
            {
                elem[i].value = value;
                return;
            }
        }
        if (allocated_space==count)
        {
            allocated_space *= 2;
            elements* newElem = new elements[allocated_space + 1];
            for (int i=0;i<count;i++)
            {  
                newElem[i] = elem[i];
            }
            delete[] elem;
            elem = newElem;
        }
        elem[count++] = { key, value, count };
    }

    bool Get(const K& key, V& value)
    {
        for (int i=0;i<count;i++)
        {
            if (elem[i].key==key)
            {
                value = elem[i].value;
                return true;
            }
        }
        return false;
    }
    int Count()
    {
        return count;
    }
    void Clear()
    {
        delete[] elem;
        allocated_space = 2;
        count           = 0;
        elem            = new elements[allocated_space + 1];
    }
    bool Delete(const K& key)
    {
        for (int i=0;i<count;i++)
        {
            if (key == elem[i].key)
            {
                delete elem[i];
                return true;
            }
        }
        return false;
    }

    bool Includes(const Map<K, V>& map)
    {
        V aux;
        for (elements& a : map)
        {
            if (!Get(a.key, aux))
            {
                return false;
            }
        }
        return true;
    }
    elements* begin() const
    {
        return &elem[0];
    }

    elements* end() const
    {
        return &elem[count];
    }
   
};