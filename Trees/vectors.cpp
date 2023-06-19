
#include<iostream>
#include <vector>
using namespace std;

int main()
{
    //vector<int>* vp = new vector<int>();  dynamically created
    vector<int> v;  //statically created

    //for inserting elements
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    cout<<v[0]<<endl;
    cout<<v[1]<<endl;
    cout<<v[2]<<endl;

    v[1] = 100;
    v[3] = 400;

    //Do not use this for inserting elements
    //cout<<v[1]<<endl;
    //cout<<v[3]<<endl;

    v.push_back(40);
    v.push_back(50);


/*Important NOTE:
    >push_back is a function in which it'll actually check what's the current size, is there space to add another element,
     if there is a need to double the space
    >If we directly add a new element, it won't increase the space*/

    //For Example:

    /*
    cout<<v[0]<<endl;
    cout<<v[1]<<endl;
    cout<<v[2]<<endl;
    cout<<v[3]<<endl;
    cout<<v[4]<<endl;
    cout<<v[5]<<endl; //will print garbage value

    //Therefore, v[] method is used to only update and get the elements


    cout<<"Size: "<<v.size()<<endl;

    //So to get the exact value, we can use v.at() function

    cout<<v.at(2)<<endl;
    cout<<v.at(5)<<endl;

    */


    //for deleting elements from the last
    v.pop_back();


    for(int i = 0; i < v.size(); i++)
    {
        cout<<"Capacity: "<<v.capacity()<<endl;
        cout<<"Size: "<<v.size()<<endl;
        cout<<v.at(i)<<endl;
    }



    return 0;
}
