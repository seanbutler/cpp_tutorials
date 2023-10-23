#include <initializer_list>
#include <vector>
#include <iostream>

class Lispish {
    public:
    
        std::string head;
        std::vector<std::string> body;

        Lispish(std::initializer_list<std::string> list) {

            head = *(list.begin());

            for (std::initializer_list<std::string>::iterator it = list.begin()+1;
                    it != list.end(); ++it) 
            {
                body.push_back(*it);
            }
        }
};

int main() {

    Lispish mylist = {"This", "Is", "A", "Phrase"};

    std::cout << "head: " << mylist.head << std::endl;

    
    std::cout << "rest: ";
    
    for (std::vector<std::string>::iterator it = mylist.body.begin(); 
            it != mylist.body.end(); 
            ++it) 
    {
        std::cout << *it << "..." ;
    }
    std::cout << std::endl;

}