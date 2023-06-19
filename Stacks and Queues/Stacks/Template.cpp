#include<iostream>
using namespace std;
template <typename T, typename V>  //V can be same as T or different from T

class Pair
{
    T x;
    V y;

public:

    void setX(T x)
    {
        this->x = x;
    }
    T getX()
    {
        return x;
    }

    void setY(V y)
    {
        this->y = y;
    }
    V getY()
    {
        return y;
    }
};

int main()
{
    Pair<int, int> p1;
    p1.setX(10);
    p1.setY(15);

    cout<<p1.getX()<<" "<<p1.getY()<<" "<<endl;

    Pair<int, double> p2;
    p2.setX(100);
    p2.setY(100.10);
    cout<<p2.getX()<<" "<<p2.getY()<<" "<<endl;

    //Printing triplet using Pair class

    Pair<Pair<int, double>, char> p3;
    p3.setY('A');
    Pair<int, double> p4;
    p4.setX(1);
    p4.setY(1.25);
    p3.setX(p4);

    cout<<p3.getX().getX()<<" "<<p3.getX().getY()<<" "<<p3.getY()<<endl;

    return 0;
}
