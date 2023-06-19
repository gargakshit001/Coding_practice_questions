#include<iostream>
#include<string>
using namespace std;

template <typename v>
class MapNode
{
public:
  string key;
  v value;
  MapNode* next;

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
};

template <typename v>
class ourMap
{
  MapNode<v>** buckets;
  int count;
  int numBuckets;

public:
  ourMap()
  {
    count = 0;
    numBuckets = 5;
    buckets = new MapNode<v>* [numBuckets];

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

    for(int i = key.length() - 1; i >= 0; i--)
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
    buckets = new MapNode<v>* [ 2 * numBuckets];
    for(int i = 0; i < 2 * numBuckets; i++)
    {
      buckets[i] = NULL;
    }

    int oldBucketCount = numBuckets;
    numBuckets *= 2;
    count  = 0;

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
  double getloadFactor()
  {
    return (1.0 * count) / numBuckets;
  }

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

int main()
{
  ourMap<int> map;
  for(int i = 0; i < 10; i++)
  {
    char c = '0' + i;
    string key = "abc";
    key = key + c;
    int value = i + 1;
    map.insert(key, value);
    cout<<map.getloadFactor()<<endl;
  }

  for(int i = 0; i < 10; i++)
  {
    char c = '0' + i;
    string key = "abc";
    key = key + c;
    cout<<key<<": "<<map.getValue(key)<<endl;
  }

  cout<<"Size: "<<map.size()<<endl;

  map.remove("abc2");
  map.remove("abc7");

  for(int i = 0; i < 10; i++)
  {
    char c = '0' + i;
    string key = "abc";
    key = key + c;
    cout<<key<<": "<<map.getValue(key)<<endl;
  }

  cout<<"Size: "<<map.size()<<endl;
}
