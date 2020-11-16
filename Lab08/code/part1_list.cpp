#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <iomanip>


class list_node {
    std::string data;
    list_node *next;

public:
    list_node(std::string _st): data(_st),next(nullptr) {};
    list_node() {};
    list_node* get_next() {
        return next;
    };
    void set_next(list_node *n) {
        next = n;
    }
    void set(std::string _st) {
        data = _st;
    }
    std::string& get() {
        return data;
    }
};

class my_list {
    list_node *head;
    list_node *tail;

public:
    my_list() {
        head = nullptr;
        tail = nullptr;
    };
    ~my_list() {
        // release its memory
        while (head != nullptr) {
            auto temp = head->get_next();
            delete head;
            head = temp;
        }
    };
    bool empty() {
        return head == nullptr;
    };
    void push_back(std::string st) {

        // allocate new node, and initialize it
        list_node *node = new list_node(st);

        if (empty()) {
            tail = node;
            head = node;
        } else {
            tail->set_next(node);
            tail = node;
        }
    };

    void push_front(std::string st) {
        // allocate new node and initialize it
        list_node *node = new list_node(st);

        if (empty()) {
            tail = node;
            head = node;
        } else {
            node->set_next(head);
            head = node;
        }
    };

    /*
     * TODO: implement this function.
     * - Print the strings in the order they appear in the list, separated by " -> "
     * - Must iterate through entire list to get each string in order.
     *
     * Output example: "Tokyo -> Ottawa -> Washington -> London -> Madrid
    */
    void print() {
        // student implements
    };

    /*
     * TODO: implement this function.
     * - Return true if the given string is in the list but false otherwise.
     * - Must iterate through entire list to look for given string.
    */
    bool exists(std::string str) {
        // student implements
    }

    std::string &front() {
        // retrieve the string at the front of the list
        return head->get();
    };

    std::string &back() {
        // retrieve the string at the back of the list
        return tail->get();
    };

};


int main() {
    my_list list;

    std::string line;
    // read one string at a time and insert at the end of the list
    while (getline(std::cin, line)) {
        list.push_back(line);
    }

    std::cout << "Capitals:" << std::endl;

    list.print();

    std::cout << std::endl;

    std::cout << std::boolalpha << "is Ottawa in the list? "    << list.exists("Ottawa") << std::endl;
    std::cout << std::boolalpha << "is Brazilia in the list? "  << list.exists("Brazilia") << std::endl;

    // Let us test an empty list

    my_list emptyList;

    std::cout << "Print empty list:" << std::endl;

    emptyList.print();

    std::cout << std::boolalpha << "is anything in the list? "    << list.exists("") << std::endl;
}
