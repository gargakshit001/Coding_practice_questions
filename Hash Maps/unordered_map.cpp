#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

int main()
{
    unordered_map<string, int> ourMap;

    ///insert
    pair<string, int> p("abc", 1);
    ourMap.insert(p);

    ///insert
    ourMap["def"] = 2;

    ///find or access
    cout<<ourMap["abc"]<<endl;
    cout<<ourMap.at("abc")<<endl;

    cout<<ourMap["ghi"]<<endl;  //This will give the default value which is 0 even though ghi index doesn't exist

    //Check for presence
    if(ourMap.count("ghi") > 0)
    {
      cout<<"ghi is present"<<endl;
    }

    //size function
    cout<<"size: "<<ourMap.size()<<endl;

    //erase an element
    ourMap.erase("ghi");

    if(ourMap.count("ghi") > 0)
    {
      cout<<"ghi is present"<<endl;
    }
    cout<<"size: "<<ourMap.size()<<endl;

    return 0;
}
