#include <iostream>
using namespace std;

#include <vector>

enum class apple {green, red, yellow};
enum class orange {big, small, round};

apple a = apple::green;
orange o = orange ::round;



int main() {

    vector<int> vec1 = {5,6,7,8};
    vector<int> vec2 ={};


    for (vector<int>::iterator it = vec1.begin(); it != vec1.end(); ++it ){

         cout << *it << endl;
        vec2.push_back(*it);
    } // 5, 6, 7,8

    //print out vec2
    for(auto it=vec2.begin(); it!= vec2.end(); ++it){
        cout << *it << endl;
    }
    // 5, 6, 7,8

    // we consider tuple as the extension of pair
    //pair has two elements can contain different data type
    //tuple -> get

    pair<int, string> p1 = make_pair(23, "Hello, world");

    cout << p1.first << " " << p1.second << endl;

    tuple<int, string, char>  t1(49, "Miao", 'c');
    cout<< get<0>(t1) << endl;
    cout << get<1>(t1) << endl;
    cout << get<2>(t1) << endl;

//change the elements in tuple
//method1
    get<1>(t1) = "WOLF";
    cout << get<1>(t1)<<endl; //WOLF

//method2
    string &s = get<1>(t1);
    s = "Patient is virtue";
    cout << get<1>(t1)<<endl; //Patient is virtue

// i must be compile time constant
    //int i =1 ;
   // cout << get<i>(t1)<< endl; // wrong way to go

 tuple<int, string, char> t2; // default constructor

    t2 = make_tuple(12, "Cat", 'a'); // new way to build tuple

    //compare the tuple
    if(t1 > t2) {
        cout << "t1 is greater than t2" << endl; //t1 is greater than t2 print 12-96
    }
        // member by member copying
        t1 = t2;

       /* for (auto it = get<0>(t1); it != get<2>(t1); ++it) {
            cout << it << endl;
        } */   //not print tuple t1 ??? why??

    // how to print tuple with different type of elements?

    cout << "Print t1 "<< get<0>(t1) << get<1>(t1) << get<2>(t1) << endl; // t1 12Cata

    // !! Tuple can storage references!!
   cout <<"---------------------------------" << endl;
   string  str1 = "Catfood is fish";
    tuple<string&> t3(str1);
    cout << get<0>(t3) << endl; // Catfood is fish
    //Or
    tuple<string&> t4(str1);
    t4 = make_tuple(ref(str1));
    cout << get<0>(t4) << endl;

    //Tie
    int x;
    char y;
    string z;
    //make_tuple(ref(x), ref(y), ref(z)) = t2;
    //std::tie(x, y, z) = t2; // doing the same thing
   // std::tie(x, std::ignore, z) = t2;


    // concat tuple

    auto t5 = tuple_cat(t3, t4);

    // type straits
    cout << std::tuple_size<decltype(t5)>::value << endl; //2
   // std::tuple_element<1, decltype(t5)>::type ; //???



    return 0;
}
