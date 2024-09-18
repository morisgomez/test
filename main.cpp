#include <iostream>
#include <string>
using namespace std;

typedef std::string ItemType; 
//reminds me of templates from csci 2.....
//typedef std::int ItemType;
//typedef std::float ItemType;

struct Node
{
    ItemType value;
    Node *next;
    Node()
    {
        value = "default";
        next = NULL;
    }
}; //end Node structure.

class LinkedList
{
private:
    Node *head; //points to the head of List.
    
public:
//constructor:
    LinkedList()
    {
        head = NULL;
    }
//copy constructor:
    LinkedList(const LinkedList& rhs)
    {
        //we are making a copy of rhs.
        //rhs is the already existing list.
        //rhs can be considered the rhs list here.
        if(rhs.head == NULL) //rhs exists but empty.
        {
            head = rhs.head; //head points to other head which is NULL
        }
        //rhs exists, not empty, so copy nodes from rhs.
        else
        {
            //takes care of first Node:
            Node *temp = rhs.head; //pts to 1st node of rhs.
            Node *n = new Node; //new Node for new List.
            n->value = temp->value; //copy rhs value into new node.
            head = n; //make head of new list point to first Node.
            temp = temp->next; //shift rhs node to 2nd.
            
            
            while(temp != NULL) //not at end of linked list.
            {
                Node *x = new Node;
                n->next = x;
                n = x;
                x->value = temp->value;
                temp = temp->next;
            } //close while loop
            //at end of linked list.
        } //close else statement.
    } //close copy constructor:
    
//destructor function:
    ~LinkedList()
    {
        Node *remove; //store node to delete.
        remove = head; //first node.
        while(remove != NULL) //until end of list.
        {
            Node *n = remove->next; //create a n every iteration?
            //what happens to the old n?
            delete remove; //delete node remove is pointing to.
            remove = n; //link remove to node n is pointing to.
        } //close while loop.
    } //close destructor:
    
//assigment operator function:
    //Z = W
    //Linked List Z = Linked List W
    //Linked List Z = rhs List
    //List being changed is to left side of = in main function.
    //List that is rhs is the right side of = in main function.
    //need to change everything stored in the Z list
    //to whatever is in the W list(rhs).
    
    const LinkedList& operator=(const LinkedList& rhs)
    {
        //1) check for aliasing:
        //went based off StudentTestScores class example.
        //a = a ex. of aliase.
        if(&rhs == this)
        {
            return *this;
        }
        else //otherwise continue with process.
        {
            //2) destroy allocated memory:
            //used destructor code.
            //need to clear the memory/data stored in Z List
            //to input rhs data.
            Node *remove; //store node to delete.
            remove = head; //first node.
            while(remove != NULL) //until end of list.
            {
                Node *n = remove->next; //create an n every iteration?
                //what happens to the old n?
                delete remove; //delete node remove is pointing to.
                remove = n; //link remove to node n is pointing to.
            } //close while loop.
            
            //3) copy all Nodes in W(rhs) list into Z.
            //used copy constructor code.
            if(rhs.head == NULL) //rhs exists but empty.
            {
                head = rhs.head; //head points to other head which is NULL
            }
            //rhs exists, not empty, so copy nodes from rhs.
            else
            {
                //takes care of first Node:
                Node *temp = rhs.head; //pts to 1st node of rhs.
                Node *n = new Node; //new Node for new List.
                n->value = temp->value; //copy rhs value into new node.
                head = n; //make head of new list point to first Node.
                temp = temp->next; //shift rhs node to 2nd.
                
                
                while(temp != NULL) //not at end of linked list.
                {
                    Node *x = new Node;
                    n->next = x;
                    n = x;
                    x->value = temp->value;
                    temp = temp->next;
                } //close while loop
                //at end of linked list.
            } //close nested else statement.
        } //close outer else.
        return *this; //??????????????
} //close assignment operator function.
    
//insertToFront() function:
    void insertToFront(const ItemType &val)
    {
        //step 1: create new Node n.
        Node *n = new Node();
        n->value = val;
        n->next = NULL;
        
        //step 2: check if list is empty or not.
        if(head == NULL) //if empty...
        {
            head = n; //head points to n.
        }
        else if(head != NULL) //if not empty...
        {
            n->next = head; //1st node becomes 2nd.
            head = n; //n node becomes head.
        }
    } //close insertToFront() function.
        
//printList() function:
    void printList() const
    {
        Node *current = head;
        while(current != NULL)
        {
            cout << current->value << " ";
            current = current->next;
        } //end while loop.
        cout << endl;
    } //close printList() function.

//size() function:
    int size() const
    {
        Node *current = head;
        int counter = 0;
        while(current != NULL)
        {
            counter = counter + 1;
            current = current->next;
        } //end while loop.
        return counter;
    } //close size() function.

//void reverseList():
    //ListOne.reverseList();
    //reverses the linked list.
    //regular: Greef Karga Cara Dune Baby Yoda The Mandalorian
    //reverse: The Mandalorian Baby Yoda Cara Dune Greef Karga
    void reverseList()
    {
        //note: not moving nodes, we are just altering
        //pointers' address.
        //changing direction of pointer arrows.
        Node *previous = NULL; //the last thing in reversed list.
        Node *current = head; //first node.
        Node *nexT = NULL; //for forward nodes.
        
        while(current != NULL) //stop after last node in original list.
        {
            nexT = current->next;
            current->next = previous; //actual reversal of ptr!!!!
            previous = current; //traverse to next node.
            current = nexT; //traverse to next node.
        }
        head = previous; //head is the last node with address.
    } //close reverseList() function.
    
//void printReverse() const:
    void printReverse() const
    {
        Node *current = head;
        while(current != NULL)
        {
            cout << current->value << " ";
            current = current->next;
        } //end while loop.
        cout << endl;
    } //close printReverse() function.
    
//bool get(int i, ItemType& item) const:
    bool get(int i, ItemType& item) const //ListOne.get(3, "moris");
    //if there is no node ListOne[i], return false.
    //if there is a node at location ListOne[i],
    //item = "moris" and return true.
    
    {
        bool flag = false;
        Node *current = head;
        int counter = 0; //tracks each Node passed in current.
        while(current != NULL)
        {
            if(counter == i)
            {
                item = current->value;
                flag = true;
                break;
            }
            else
            {
                current = current->next;
                counter = counter + 1;
                flag = false;
            }
        } //close while loop.
        return flag;
    } //close get() function.
    
//void append(const LinkedList &other):
    void append(const LinkedList &other) 
    //other = ListTen.
    {
        //part1: reach end of ListNine.
        Node* current = head;
        while (current != NULL)
        {
            current = current->next;
        }
        
        //part2: create new nodes for ListTen
        //copy data from listTen.
        //copying listTen and linking copy to first list.
        //whyy cant we just link the heads lol???
        
        int size = other.size(); //3
        Node* currentOther = other.head; //to traverse.
        for (int i = 0; i < size; i++) //loop 3 times.
        {
            //dynamic allocation:
            Node* n = new Node;
            n->next = NULL;
            n->value = currentOther->value; 
            //using values from other list
            current->next = n; //links first list to new first node.
            current = current->next;
            currentOther = currentOther->next;
        }
    } //close append() function.

//void swap(LinkedList &other):
    //ListOne.swap(ListTwo); calling.
    void swap(LinkedList &other) //swap ptrs
    {
        //step 1: swap heads
        Node *n = head; //pts to ListOne head.
        head = other.head; //changes ListOne head to other.head.
        other.head = n; //other.head becomes ListOne head.
        n = NULL;
        
    } //close swap() function.
}; //end LinkedList class.

int main()
{
    /*
    //1) create ListOne using constructor:
    LinkedList ListOne;
    ListOne.insertToFront("hello");
    ListOne.insertToFront("moris");
    ListOne.insertToFront("gomez");
    ListOne.printList();
    cout << ListOne.size() << endl;
    cout << "---------" << endl;
    
    //2) create ListTwo from ListOne using copy constructor:
    LinkedList ListTwo = ListOne; //copy constructor call.
    ListTwo.printList();
    cout << ListTwo.size() << endl;
    
    //3) call reverseList() on ListOne and then then printReverse():
    ListOne.reverseList();
    ListOne.printReverse();
    
    //4) create ListThree. Use assignment operator to copy
    //ListOne's nodes into ListThree:
    LinkedList ListThree;
    ListThree.insertToFront("el");
    ListThree.insertToFront("camino");
    ListThree.insertToFront("college");
    ListThree.printList();
    
    ListThree = ListOne;
    ListThree.printList();
    //remember we reversed ListOne using assignment operator.
    //List three should be: hello moris gomez.
    
    //5) use get function on ListThree:
    ItemType x;
    ListThree.get(1, x);
    cout << x << endl; //"moris"
    
    //6) construct 2 new Lists and use swap function on them:
    LinkedList ListFive;
    ListFive.insertToFront("happy");
    ListFive.insertToFront("birthday");
    ListFive.insertToFront("buddy");
    ListFive.printList();
    cout << "-----" << endl;
    
    LinkedList ListSix;
    ListSix.insertToFront("you're");
    ListSix.insertToFront("old");
    ListSix.insertToFront("friend");
    ListSix.printList();
    cout << "-----" << endl;
    
    ListFive.swap(ListSix);
    ListFive.printList();
    cout << "-----" << endl;
    ListSix.printList();
    cout << "-----" << endl;
     */
    
    //7) Construct a LinkedList x and a LinkedList y. Use append
    //function to link y to end of x:
    LinkedList ListNine;
    ListNine.insertToFront("fluffy");
    ListNine.insertToFront("holidays");
    ListNine.insertToFront("happy");
    ListNine.printList();
    
    LinkedList ListTen;
    ListTen.insertToFront("cute");
    ListTen.insertToFront("super");
    ListTen.insertToFront("you're");
    ListTen.printList();
    
    
    return 0;
}
