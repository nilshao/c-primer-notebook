#include <iostream>
#include <list>
#include <string>
#include <locale>         // std::locale, std::tolower


class Node
{
  public:
    Node(std::string name, std::list<Node> children = {})
    {
        name_ = name;
        children_=children;
    };
   
    static int cToLower(int c) {
        return tolower(c);
    }

    int count_nodes_containing_string(std::string needle)
    {
        //TODO implement me, needs to be case-insensitive
        
        if(children.size()==0){
            return 0;
        }else{
            for(Node c: children){
                int count_this_node=1;
                if(c->name==needle){
                    
                    count_this_node += c.count_nodes_containing_string(std::string needle);

                }
                return count_this_node;
            }
        }
      //  needle; //TODO use the parameter
        return -1;
    }
private:
    std::string name_;
    std::list<Node> children_;
};

#ifndef RunTests
int main()
{
    //Create an example tree
    Node n("root",{
        {"MagaZino",{
            {"I"},
            {"Love"},
            {"magazino"}
            }},
        {"Hello",{
            {"Hello",{
                {"Hello",{
                    {"World"}
                }}
            }}
        }}
    });
    //Cout the solution
    std::cout << n.count_nodes_containing_string("test")<<std::endl;
}
#endif
