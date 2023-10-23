#include <iostream>

// ----------------------------------------------------------------------

struct IntOps {
    static int clear () { return 0; };
    static int add ( int x , int y ) { return x + y ; }
};

class StrOps {
    public:
        static std::string clear () { return ""; };
        static std::string add ( std::string x , std::string y ) { return x +" "+ y ; }
};

// ----------------------------------------------------------------------

template <typename T>
struct MyList{
    T head;
    struct MyList<T> *tail;
};

template < typename T , typename O >
T fold ( MyList<T> *ptr )
{
    T total = O::clear();
    while ( ptr ) {
        total = O::add(total, ptr->head);
        ptr = ptr->tail;
    }
    return total;
}

// ----------------------------------------------------------------------

std::string ds[] = {
                std::string("One"), 
                std::string("Two"),
                std::string("Three"), 
                std::string("Four")
            };

int main(int, char**) {
    std::cout << "!!!\n";

    {
        MyList<int> *numListPtr;
        MyList<int> *tmplistPtr;

        auto Total = fold<int, IntOps>;

        tmplistPtr = (MyList<int>*)malloc(sizeof(MyList<int>));
        numListPtr = tmplistPtr;

        for(int n=1;n<=10;n++){
            tmplistPtr->head = n;
            tmplistPtr->tail = (MyList<int>*)malloc(sizeof(MyList<int>));
            tmplistPtr=tmplistPtr->tail;
        }    
        std::cout << Total(numListPtr) << std::endl;

    }



    {
        MyList<std::string> *numListPtr;
        MyList<std::string> *tmplistPtr;

        auto Total = fold<std::string, StrOps>;

        tmplistPtr = (MyList<std::string>*)malloc(sizeof(MyList<std::string>));
        numListPtr = tmplistPtr;

        for(int n=0;n<=3;n++){
            tmplistPtr->head = ds[n];
            tmplistPtr->tail = (MyList<std::string>*)malloc(sizeof(MyList<std::string>));
            tmplistPtr=tmplistPtr->tail;
        }    

        std::cout << Total(numListPtr) << std::endl;
    }

}
