#include<iostream>
#include<string>
using namespace std;

template<typename v>
class MapNode
{
  string key;
  v value;
  MapNode* next;

public:
  MapNode(string key, v value)
  {
    this->key = key;
    this->value = value;
    next = NULL;
  }

  ~MapNode()
  {
    delete next;
  }
};                                                                                                                                                                                          

template <typename v>
class ourMap
{
  MapNode<v>** buckets;
  int numBuckets;
  int count;

public:
  ourMap()
  {
    numBuckets = 5;
    count = 0;
    buckets = MapNode<v>* [numBuckets];

    for(int i = 0; i < numBuckets; i++)
    {
      buckets[i] = NULL;
    }
  }

  ~ourMap()
  {
    for(int i = 0; i < numBuckets; i++)
    {
      delete buckets[i];
    }

    delete []buckets;
  }

  int size()
  {
    return count;
  }

private:
  int getBucketIndex(string key)
  {
    int hashCode = 0;
    int currCoeff = 1;

    fir(int i = key.length() - 1; i >= 0; i++)
    {
      hashCode += key[i] * currCoeff;
      hashCode = hashCode % numBuckets;
      currCoeff *= 37;
      currCoeff = currCoeff % numBuckets;
    }
    return hashCode % numBuckets;
  }

  void rehash()
  {
    MapNode<v>** temp = buckets;
    buckets = MapNode<v>* [2 * numBuckets];
    for(int i = 0; i < 2 * numBuckets; i++)
    {
      buckets[i] = NULL;
    }

    int oldBucketCount = numBuckets;
    numBuckets *= 2;
    count = 0;

    for(int i = 0; i < oldBucketCount; i++)
    {
      MapNode<v>* head = temp[i];
      while(head != NULL)
      {
        string key = head->key;
        v value = head->value;
        insert(key, value);
        head = head->next;
      }
    }

    for(int i = 0; i < oldBucketCount; i++)
    {
      MapNode<v>* head = temp[i];
      delete head;
    }
    delete []temp;
  }

public:
  void insert(string key, v value)
  {
    int bucketIndex = getBucketIndex(key);
    MapNode<v>* head = buckets[bucketIndex];

    while(head != NULL)
    {
      if(head->key == key)
      {
        head->value = value;
        return;
      }
      head = head->next;
    }

    head = buckets[bucketIndex];
    MapNode<v>* node = new MapNode<v>(key, value);
    node->next = head;
    buckets[bucketIndex] = node;
    count++;
    double loadFactor = (1.0 * count) / numBuckets;
    if(loadFactor > 0.7)
    {
      rehash();
    }
  }

  v getValue(string key)
  {
    int bucketIndex = getBucketIndex(key);
    MapNode<v>* head = buckets[bucketIndex];
    while(head != NULL)
    {
      if(head->key == key)
      {
        return head->value;
      }
      head = head->next;
    }
    return 0;
  }

  v remove(string key)
  {
    int bucketIndex = getBucketIndex(key);
    MapNode<v>* head = buckets[bucketIndex];
    MapNode<v>* prev = NULL;

    while(head != NULL)
    {
      if(head->key == key)
      {
        if(prev == NULL)
        {
          buckets[bucketIndex] = head->next;
        }
        else
        {
          prev->next = head->next;
        }
        v ans = head->value;
        head->next = NULL;
        delete head;
        count--;
        return ans;
      }
      prev = head;
      head = head->next;
    }
    return 0;
  }
};
