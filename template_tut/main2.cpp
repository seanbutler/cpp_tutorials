#include <iostream>

// ----------------------------------------------------------------------

class Printable {
    public:
        void print() {std::cout << "Printable"; }
};

template<typename T>
class RepeatPrint : public T {
    public:
        void repeat(unsigned int n=10) {

            for (int c=0;c<n;c++)
                T::print();
        }
};

template<typename P>
RepeatPrint<P> repeatPrint(P const& printable)
{
    return RepeatPrint<P>(printable);
}

// ----------------------------------------------------------------------

int main(int, char**) {
    std::cout << "!!!\n";


    Printable n;    
    repeatPrint(n).repeat(10);

}
