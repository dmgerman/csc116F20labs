#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <iomanip>


class list_node {
    std::string data;
    std::shared_ptr<list_node> next;

public:
    list_node(std::string _st) : data(_st), next(nullptr) {};

    list_node() {};

    std::shared_ptr<list_node> get_next() {
        return next;
    };

    void set_next(std::shared_ptr<list_node> n) {
        next = n;
    }

    void set(std::string _st) {
        data = _st;
    }

    std::string &get() {
        return data;
    }
};

class my_list {
    std::shared_ptr<list_node> head;
    std::shared_ptr<list_node> tail;

public:
    my_list() {
        head = nullptr;
        tail = nullptr;
    };

    ~my_list() {
    };

    bool empty() {
        return head == nullptr;
    };

    void push_back(std::string str) {

        // allocate new node, and initialize it
        std::shared_ptr<list_node> node = std::make_shared<list_node>(str);

        if (empty()) {
            tail = node;
            head = node;
        } else {
            tail->set_next(node);
            tail = node;
        }
    };

    void push_front(std::string str) {
        // allocate new node and initialize it
        std::shared_ptr<list_node> node = std::make_shared<list_node>(str);

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
        std::shared_ptr<list_node> tmp = head;
        while (tmp != nullptr) {
            std::cout << tmp->get();
            if (tmp->get_next() != nullptr)
                std::cout << " -> ";
            tmp = tmp->get_next();
        }
        std::cout << std::endl;
    };

    /*
     * TODO: implement this function.
     * - Return true if the given string is in the list but false otherwise.
     * - Must iterate through entire list to look for given string.
    */
    bool exists(std::string str) {
        // student implements
        std::shared_ptr<list_node> tmp = head;
        while (tmp != nullptr) {
            if (str == tmp->get())
                return true;
            tmp = tmp->get_next();
        }
        return false;
    }

    std::string &front() {
        // retrieve the string at the front of the list
        return head->get();
    };

    std::string &back() {
        // retrieve the string at the back of the list
        return tail->get();
    };

    void remove_node(std::string str) {
        // define pointers to the current and the previous nodes,
        // starting the current from the head
        std::shared_ptr<list_node> prev = nullptr;
        std::shared_ptr<list_node> curr = head;
        // Check if the linked list is not empty and the head hold the string to be deleted
        if (head != nullptr && head->get() == str) {
            // advance the head to point at the next node,
            // if we have one element on the linked list, the "next" pointer will hold the value nullptr
            head = head->get_next();
            // reset the tail if it's pointing at this node (in case we have one-element linked list)
            // remember, curr still has the old value of the head (still pointing at the node)
            if (tail == curr) {
                tail = head;
            }
            // delete the node.
            curr.reset();
            return;
        }
        // Search for the sting in the remaining node and keep advancing the curr and prev pointers,
        // exit if we reach the end (if curr equals to nullptr)
        while (curr != nullptr) {
            if (str == curr->get()) {
                // if found, connect the previous node to the node after the current node
                prev->set_next(curr->get_next());
                // delete the memory reserved for the current node
                curr.reset();
                // advance the current pointer
                curr = prev->get_next();
                // don't exit and keep searching for the string in other nodes
            } else {
                // advance the current and the previous pointers
                prev = curr;
                curr = curr->get_next();
            }
        }
    }
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

    std::cout << std::boolalpha << "is Ottawa in the list? " << list.exists("Ottawa") << std::endl;
    std::cout << std::boolalpha << "is Brazilia in the list? " << list.exists("Brazilia") << std::endl;

    // Let us remove some elements
    list.remove_node("London");
    std::cout << "\nCapitals after removing London:" << std::endl;
    list.print();

    list.remove_node("Tokyo");
    std::cout << "\nCapitals after removing Tokyo:" << std::endl;
    list.print();

    list.remove_node("Stockholm");
    std::cout << "\nCapitals after removing Stockholm:" << std::endl;
    list.print();

    // Let us test an empty list

    my_list emptyList;

    std::cout << "Print empty list:" << std::endl;

    emptyList.print();

    std::cout << std::boolalpha << "is anything in the list? " << list.exists("") << std::endl;
}
