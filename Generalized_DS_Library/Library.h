#include<iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////

// Structure for singly linear and singly circular

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
struct NodeS
{
    T data;
    struct NodeS *next;
};

///////////////////////////////////////////////////////////////////////////////////////////

// Structure for doubly linear and singly circular

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
struct NodeD
{
    T data;
    struct NodeD *next;
    struct NodeD *prev;
};

///////////////////////////////////////////////////////////////////////////////////////////

// Class of singly linear Linked list

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class SinglyLL
{
    public:
        struct NodeS<T> * first;
        int iCount;

    SinglyLL();

    void Display();
    int Count();
    
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);
    
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);

    int SearchFirstOccurance(T);
    int SearchLastOccurance(T);
    int CalFreq(T);
    T Min();
    T Max();
    T Summation();
};

template <class T>
SinglyLL <T>::SinglyLL()
{
    first = NULL;
    iCount = 0;
}

template <class T>
void SinglyLL<T>::Display()
{
    cout<<"Elements of Singly Linear Linked list are : "<<"\n";

    NodeS<T> * temp = first;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp -> next;
    }
    cout<<"NULL"<<"\n";
}

template <class T>
int SinglyLL<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyLL<T>::InsertFirst(T no)
{
    NodeS<T> * newn = new NodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::InsertLast(T no)
{
    NodeS<T> * newn = new NodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        NodeS<T> *temp = first;

        while(temp->next != NULL)
        {
            temp= temp -> next;
        }
        temp->next = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::DeleteFirst()
{
    if(first == NULL)
    {
        return;
    }
    else if(first -> next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        NodeS<T> *temp = first;

        first = first -> next;
        delete temp;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteLast()
{
        if(first == NULL)
    {
        return;
    }
    else if(first -> next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        NodeS<T> *temp = first;

        while(temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }

        delete temp -> next;
        temp -> next = NULL;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::InsertAtPos(T no, int iPos)
{   
    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        NodeS<T> * temp = first;
        NodeS<T> * newn = new NodeS<T>;

        newn -> data = no;
        newn -> next = NULL;

        for(int iCnt = 1; iCnt < iPos -1; iCnt++)
        {
            temp = temp -> next;
        }

        newn -> next = temp -> next;
        temp -> next = newn;
        
        iCount++;
    }
}

template <class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
{
    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        NodeS<T> * temp = first;
        NodeS<T> * tempX = NULL;

        for(int iCnt = 1; iCnt < iPos -1; iCnt++)
        {
            temp = temp -> next;
        }

        tempX = temp -> next -> next;
        delete temp -> next;
        temp -> next = tempX;
        
        iCount--;
    }
}

template <class T>
int SinglyLL<T>:: SearchFirstOccurance(T no)
{
    if(iCount == 0)
    {
        cout<<"Linked List is empty\n";
        return 0;
    }

    NodeS<T> * temp = first;
    int iFirst = 0;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if(temp -> data == no)
        {
            iFirst = iCnt;
            break;
        }
        temp = temp -> next;
    }
    return iFirst;
}

template <class T>
int SinglyLL<T>:: SearchLastOccurance(T no)
{
    if(iCount == 0)
    {
        cout<<"Linked List is empty\n";
        return 0;
    }

    NodeS<T> * temp = first;
    int iLast = 0;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if(temp -> data == no)
        {
            iLast = iCnt;
        }
        temp = temp -> next;
    }
    return iLast;
}

template <class T>
int SinglyLL<T>:: CalFreq(T no)
{
    if(iCount == 0)
    {
        cout<<"Linked List is empty\n";
        return 0;
    }

    NodeS<T> * temp = first;
    int iFreq = 0;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if(temp -> data == no)
        {
            iFreq++;
        }
        temp = temp -> next;
    }
    return iFreq;
}

template <class T>
T SinglyLL<T>:: Min()
{
    if(iCount == 0)
    {
        cout<<"Linked List is empty\n";
        return 0;
    }

    NodeS<T> * temp = first;
    T Min = temp -> data;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if(temp -> data < Min)
        {
            Min = temp -> data;
        }
        temp = temp -> next;
    }
    return Min;
}

template <class T>
T SinglyLL<T>:: Max()
{
    if(iCount == 0)
    {
        cout<<"Linked List is empty\n";
        return 0;
    }

    NodeS<T> * temp = first;
    T Max = temp -> data;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if(temp -> data > Max)
        {
            Max = temp -> data;
        }
        temp = temp -> next;
    }
    return Max;
}

template <class T>
T SinglyLL<T>:: Summation()
{
    if(iCount == 0)
    {
        cout<<"Linked List is empty\n";
        return 0;
    }

    NodeS<T> * temp = first;
    T Sum = 0;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        Sum = Sum + temp -> data;

        temp = temp -> next;
    }
    return Sum;
}

///////////////////////////////////////////////////////////////////////////////////////////

// Class of singly circular Linked list

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class SinglyCL
{
    public:
        struct NodeS<T> * first;
        struct NodeS<T> * last;
        int iCount;

    SinglyCL();

    void Display();
    int Count();
    
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);
    
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);

    int SearchFirstOccurance(T);
    int SearchLastOccurance(T);
    int CalFreq(T);
    T Min();
    T Max();
    T Summation();
};

template <class T>
SinglyCL <T>::SinglyCL()
{
    first = NULL;
    last = NULL;
    iCount = 0;
}

template <class T>
void SinglyCL<T>::Display()
{
    NodeS<T> * temp = first;

    cout<<"Elements of Singly Circular Linked list are : "<<"\n";
    cout<<" -> ";
    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        cout<<"|"<<temp -> data<<"| -> ";
        temp = temp -> next;
    }
    cout<<"\n";
}

template <class T>
int SinglyCL<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyCL<T>::InsertFirst(T no)
{
    NodeS<T> * newn = new NodeS<T>;

    newn -> data = no;
    newn -> next = NULL;


    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn -> next = first;
        first = newn;
    }
    last -> next = first;
    iCount++;
}

template <class T>
void SinglyCL<T>::InsertLast(T no)
{
    NodeS<T> * newn = new NodeS<T>;

    newn -> data = no;
    newn -> next = NULL;

    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        last -> next = newn;
        last = last -> next;
    }
    last -> next = first;
    iCount++;
}

template <class T>
void SinglyCL<T>::DeleteFirst()
{
    if((first == NULL) && (last == NULL))
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        first = first -> next;
        delete last -> next;
        last -> next = first;
    }
    iCount--;
}

template <class T>
void SinglyCL<T>::DeleteLast()
{
    if(iCount == 0)
    {
        return;
    }
    else if(iCount == 1)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        NodeS<T> * temp = first;

        while(temp -> next != last)
        {
            temp = temp -> next;
        }
        delete last;
        last = temp;
        last -> next = first;
    }
    iCount--;
}

template <class T>
void SinglyCL<T>::InsertAtPos(T no, int iPos)
{
    if((iPos < 1) || (iPos > iCount + 1))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos > iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        NodeS<T> * newn = new NodeS<T>;

        newn -> data = no;
        newn -> next = NULL;

        NodeS<T> * temp = first;

        for(int iCnt = 1; iCnt < (iPos - 1); iCnt++)
        {
            temp = temp -> next;
        }
        newn -> next = temp -> next;
        temp -> next = newn;

        iCount++;
    }
}

template <class T>
void SinglyCL<T>::DeleteAtPos(int iPos)
{
    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid Position\n";
        return;
    }
    
    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        NodeS<T> * temp = first;
        NodeS<T> * tempX = temp -> next;

        for(int iCnt = 1; iCnt < (iPos - 1); iCnt++)
        {
            temp = temp -> next;
        }
        tempX = temp -> next;

        temp -> next = temp -> next -> next;
        delete tempX;

        iCount--;
    }
}

template <class T>
int SinglyCL<T>:: SearchFirstOccurance(T no)
{
    if(iCount == 0)
    {
        cout<<"Linked List is empty\n";
        return 0;
    }

    NodeS<T> * temp = first;
    int iFirst = 0;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if(temp -> data == no)
        {
            iFirst = iCnt;
            break;
        }
        temp = temp -> next;
    }
    return iFirst;
}

template <class T>
int SinglyCL<T>:: SearchLastOccurance(T no)
{
    if(iCount == 0)
    {
        cout<<"Linked List is empty\n";
        return 0;
    }

    NodeS<T> * temp = first;
    int iLast = 0;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if(temp -> data == no)
        {
            iLast = iCnt;
        }
        temp = temp -> next;
    }
    return iLast;
}

template <class T>
int SinglyCL<T>:: CalFreq(T no)
{
    if(iCount == 0)
    {
        cout<<"Linked List is empty\n";
        return 0;
    }

    NodeS<T> * temp = first;
    int iFreq = 0;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if(temp -> data == no)
        {
            iFreq++;
        }
        temp = temp -> next;
    }
    return iFreq;
}

template <class T>
T SinglyCL<T>:: Min()
{
    if(iCount == 0)
    {
        cout<<"Linked List is empty\n";
        return 0;
    }

    NodeS<T> * temp = first;
    T Min = temp -> data;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if(temp -> data < Min)
        {
            Min = temp -> data;
        }
        temp = temp -> next;
    }
    return Min;
}

template <class T>
T SinglyCL<T>:: Max()
{
    if(iCount == 0)
    {
        cout<<"Linked List is empty\n";
        return 0;
    }

    NodeS<T> * temp = first;
    T Max = temp -> data;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if(temp -> data > Max)
        {
            Max = temp -> data;
        }
        temp = temp -> next;
    }
    return Max;
}

template <class T>
T SinglyCL<T>:: Summation()
{
    if(iCount == 0)
    {
        cout<<"Linked List is empty\n";
        return 0;
    }

    NodeS<T> * temp = first;
    T Sum = 0;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        Sum = Sum + temp -> data;

        temp = temp -> next;
    }
    return Sum;
}

///////////////////////////////////////////////////////////////////////////////////////////

// Class of doubly linear Linked list

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class DoublyLL
{
    public:
        struct NodeD<T> * first;
        int iCount;

    DoublyLL();

    void Display();
    int Count();
    
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);
    
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);

    int SearchFirstOccurance(T);
    int SearchLastOccurance(T);
    int CalFreq(T);
    T Min();
    T Max();
    T Summation();
};

template <class T>
DoublyLL <T>::DoublyLL()
{
    first = NULL;
    iCount = 0;
}

template <class T>
void DoublyLL<T>::Display()
{
    NodeD<T> * temp = first;

    cout<<"Elements of Doubly Linear Linked List are : \n";
    cout<<"NULL <=> ";
    while(temp != NULL)
    {
        cout<<"|"<<temp -> data<<"| <=> ";
        temp = temp -> next;
    }
    cout<<"NULL\n";
}

template <class T>
int DoublyLL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyLL<T>::InsertFirst(T no)
{
    NodeD<T> * newn = new NodeD<T>;

    newn -> data = no;
    newn -> next = NULL;
    newn -> prev = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        newn -> next = first;
        first -> prev = newn;

        first = newn;
    }
    iCount++;
}

template <class T>
void DoublyLL<T>::InsertLast(T no)
{
    NodeD<T> * newn = new NodeD<T>;

    newn -> data = no;
    newn -> next = NULL;
    newn -> prev = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        NodeD<T> * temp = first;

        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        newn -> prev = temp;
        temp -> next = newn;
    }
    iCount++;
}

template <class T>
void DoublyLL<T>::DeleteFirst()
{
    if(first == NULL)
    {
        return;
    }
    else if(first -> next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        first = first -> next;
        delete first -> prev;
        first -> prev = NULL;
    }
    iCount--;
}

template <class T>
void DoublyLL<T>::DeleteLast()
{
    if(first == NULL)
    {
        return;
    }
    else if(first -> next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        NodeD<T> * temp = first;

        while(temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }
        delete temp -> next;
        temp -> next = NULL;
    }
    iCount--;
}

template <class T>
void DoublyLL<T>::InsertAtPos(T no, int iPos)
{
    if((iPos < 1) || (iPos > iCount + 1))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos > iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        NodeD<T> * temp = first;
        NodeD<T> * newn = new NodeD<T>;

        newn -> data = no;
        newn -> next = NULL;
        newn -> prev = NULL;

        for(int iCnt = 1; iCnt < (iPos - 1); iCnt++)
        {
            temp = temp -> next;
        }   
        newn -> next = temp -> next;
        temp -> next -> prev = newn;

        temp -> next = newn;
        newn -> prev = temp;

        iCount++;
    }
}

template <class T>
void DoublyLL<T>::DeleteAtPos(int iPos)
{
    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos > iCount)
    {
        DeleteLast();
    }
    else
    {
        NodeD<T> * temp = first;

        for(int iCnt = 1; iCnt < (iPos - 1); iCnt++)
        {
            temp = temp -> next;
        }   
        temp -> next = temp -> next -> next;
        delete temp -> next -> prev;

        temp -> next -> prev = temp;

        iCount--;
    }
}

template <class T>
int DoublyLL<T>:: SearchFirstOccurance(T no)
{
    if(iCount == 0)
    {
        cout<<"Linked List is empty\n";
        return 0;
    }

    NodeD<T> * temp = first;
    int iFirst = 0;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if(temp -> data == no)
        {
            iFirst = iCnt;
            break;
        }
        temp = temp -> next;
    }
    return iFirst;
}

template <class T>
int DoublyLL<T>:: SearchLastOccurance(T no)
{
    if(iCount == 0)
    {
        cout<<"Linked List is empty\n";
        return 0;
    }

    NodeD<T> * temp = first;
    int iLast = 0;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if(temp -> data == no)
        {
            iLast = iCnt;
        }
        temp = temp -> next;
    }
    return iLast;
}

template <class T>
int DoublyLL<T>:: CalFreq(T no)
{
    if(iCount == 0)
    {
        cout<<"Linked List is empty\n";
        return 0;
    }

    NodeD<T> * temp = first;
    int iFreq = 0;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if(temp -> data == no)
        {
            iFreq++;
        }
        temp = temp -> next;
    }
    return iFreq;
}

template <class T>
T DoublyLL<T>:: Min()
{
    if(iCount == 0)
    {
        cout<<"Linked List is empty\n";
        return 0;
    }

    NodeD<T> * temp = first;
    T Min = temp -> data;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if(temp -> data < Min)
        {
            Min = temp -> data;
        }
        temp = temp -> next;
    }
    return Min;
}

template <class T>
T DoublyLL<T>:: Max()
{
    if(iCount == 0)
    {
        cout<<"Linked List is empty\n";
        return 0;
    }

    NodeD<T> * temp = first;
    T Max = temp -> data;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if(temp -> data > Max)
        {
            Max = temp -> data;
        }
        temp = temp -> next;
    }
    return Max;
}

template <class T>
T DoublyLL<T>:: Summation()
{
    if(iCount == 0)
    {
        cout<<"Linked List is empty\n";
        return 0;
    }

    NodeD<T> * temp = first;
    T Sum = 0;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        Sum = Sum + temp -> data;

        temp = temp -> next;
    }
    return Sum;
}

///////////////////////////////////////////////////////////////////////////////////////////

// Class of doubly cicular Linked list

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class DoublyCL
{
    public:
        struct NodeD<T> * first;
        struct NodeD<T> * last;
        int iCount;

    DoublyCL();

    void Display();
    int Count();
    
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);
    
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);

    int SearchFirstOccurance(T);
    int SearchLastOccurance(T);
    int CalFreq(T);
    T Min();
    T Max();
    T Summation();
};

template <class T>
DoublyCL <T>::DoublyCL()
{
    first = NULL;
    last = NULL;
    iCount = 0;
}

template <class T>
void DoublyCL<T>::Display()
{
    NodeD<T> * temp = first;

    cout<<"Elements of Doubly Circular Linked List are : \n";
    cout<<" <=> ";
    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        cout<<"|"<<temp -> data<<"| <=> ";
        temp = temp -> next;
    }
    cout<<"\n";
}

template <class T>
int DoublyCL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyCL<T>::InsertFirst(T no)
{
    NodeD<T> * newn = new NodeD<T>;

    newn -> data = no;
    newn -> next = NULL;
    newn -> prev = NULL;

    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first -> prev = newn;
        first = newn;
    }
    last -> next = first;
    first -> prev = last;

    iCount++;
}

template <class T>
void DoublyCL<T>::InsertLast(T no)
{
    NodeD<T> * newn = new NodeD<T>;

    newn -> data = no;
    newn -> next = NULL;
    newn -> prev = NULL;

    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        last -> next = newn;
        newn->prev = last;
        last = last -> next;
    }
    last -> next = first;
    first -> prev = last;
    
    iCount++;
}

template <class T>
void DoublyCL<T>::DeleteFirst()
{
    if(iCount == 0)
    {
        return;
    }
    else if(iCount == 1)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        first = first -> next;
        delete last -> next;

        last -> next = first;
        first -> prev = last;
    }
    iCount--;
}

template <class T>
void DoublyCL<T>::DeleteLast()
{
    if(iCount == 0)
    {
        return;
    }
    else if(iCount == 1)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        last = last -> prev;
        delete last -> next;

        last -> next = first;
        first -> prev = last;
    }
    iCount--;
}

template <class T>
void DoublyCL<T>::InsertAtPos(T no, int iPos)
{
    if((iPos < 1) || (iPos > (iCount + 1)))
    {
        cout<<"Invalid Position\n";
        return;
    }
    
    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == (iCount + 1))
    {
        InsertLast(no);
    }
    else
    {
        NodeD<T> *  temp = first;

        for(int iCnt = 1; iCnt < (iPos - 1); iCnt++)
        {
            temp = temp -> next;
        }
        NodeD<T> * newn = new NodeD<T>;

        newn -> data = no;
        newn -> next = NULL;
        newn -> prev = NULL;

        newn -> next = temp -> next;
        temp -> next -> prev = newn;

        temp -> next = newn;
        newn -> prev = temp;

        iCount++;
    }
}

template <class T>
void DoublyCL<T>::DeleteAtPos(int iPos)
{
    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid Position\n";
        return;
    }
    
    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        NodeD<T> *  temp = first;

        for(int iCnt = 1; iCnt < (iPos - 1); iCnt++)
        {
            temp = temp -> next;
        }
        temp -> next = temp -> next -> next;
        delete temp -> next -> prev;
        temp -> next -> prev = temp;

        iCount--;
    }
}

template <class T>
int DoublyCL<T>:: SearchFirstOccurance(T no)
{
    if(iCount == 0)
    {
        cout<<"Linked List is empty\n";
        return 0;
    }

    NodeD<T> * temp = first;
    int iFirst = 0;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if(temp -> data == no)
        {
            iFirst = iCnt;
            break;
        }
        temp = temp -> next;
    }
    return iFirst;
}

template <class T>
int DoublyCL<T>:: SearchLastOccurance(T no)
{
    if(iCount == 0)
    {
        cout<<"Linked List is empty\n";
        return 0;
    }

    NodeD<T> * temp = first;
    int iLast = 0;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if(temp -> data == no)
        {
            iLast = iCnt;
        }
        temp = temp -> next;
    }
    return iLast;
}

template <class T>
int DoublyCL<T>:: CalFreq(T no)
{
    if(iCount == 0)
    {
        cout<<"Linked List is empty\n";
        return 0;
    }

    NodeD<T> * temp = first;
    int iFreq = 0;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if(temp -> data == no)
        {
            iFreq++;
        }
        temp = temp -> next;
    }
    return iFreq;
}

template <class T>
T DoublyCL<T>:: Min()
{
    if(iCount == 0)
    {
        cout<<"Linked List is empty\n";
        return 0;
    }

    NodeD<T> * temp = first;
    T Min = temp -> data;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if(temp -> data < Min)
        {
            Min = temp -> data;
        }
        temp = temp -> next;
    }
    return Min;
}

template <class T>
T DoublyCL<T>:: Max()
{
    if(iCount == 0)
    {
        cout<<"Linked List is empty\n";
        return 0;
    }

    NodeD<T> * temp = first;
    T Max = temp -> data;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if(temp -> data > Max)
        {
            Max = temp -> data;
        }
        temp = temp -> next;
    }
    return Max;
}

template <class T>
T DoublyCL<T>:: Summation()
{
    if(iCount == 0)
    {
        cout<<"Linked List is empty\n";
        return 0;
    }

    NodeD<T> * temp = first;
    T Sum = 0;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        Sum = Sum + temp -> data;

        temp = temp -> next;
    }
    return Sum;
}

///////////////////////////////////////////////////////////////////////////////////////////

// Class of Stack

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class Stack
{
    public:
        struct NodeD<T> * first;
        int iCount;

    Stack();

    void Push(T);
    T Pop();

    void Display();
    int Count();

    int SearchFirstOccurance(T);
    int SearchLastOccurance(T);
    int CalFreq(T);
    T Min();
    T Max();
    T Summation();
};

template <class T>
Stack<T>:: Stack()
{
    first = NULL;
    iCount = 0;
}

template <class T>
void Stack<T>:: Push(T no)
{
    NodeD<T> * newn = new NodeD<T>;

    newn -> data = no;
    newn -> next = NULL;
    newn -> prev = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        NodeD<T> *  temp = first;

        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
        newn -> prev = temp;
    }
    iCount++;
}

template <class T>
T Stack<T>:: Pop()
{
    T Value;

    if(iCount == 0)
    {
        cout<<"Stack is empty\n";
        return -1;
    }
    else if(iCount == 1)
    {
        Value = first -> data;
        delete first;
        first = NULL;
    }
    else
    {
        NodeD<T> *  temp = first;

        while(temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }
        Value = temp -> next -> data;
        delete (temp -> next);
        temp -> next = NULL;
    }
    iCount--;
    return Value;
}

template <class T>
void Stack<T>:: Display()
{
    if(first == NULL)
    {
        cout<<"Nothing to display as Stack is empty\n";
        return;
    }
    NodeD<T> *  temp = first;

    while(temp -> next != NULL)
    {
        temp = temp -> next;
    }
    
    cout<<"Elements of Stack are : \n";
    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        cout<<"    "<<temp -> data<<"\n";
        cout<<"----------\n";
        temp = temp -> prev;
    }
}

template <class T>
int Stack<T>:: Count()
{
    return iCount;
}

template <class T>
int Stack<T>:: SearchFirstOccurance(T no)
{
    if(iCount == 0)
    {
        cout<<"Linked List is empty\n";
        return 0;
    }

    NodeD<T> * temp = first;
    int iFirst = 0;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if(temp -> data == no)
        {
            iFirst = iCnt;
            break;
        }
        temp = temp -> next;
    }
    return iFirst;
}

template <class T>
int Stack<T>:: SearchLastOccurance(T no)
{
    if(iCount == 0)
    {
        cout<<"Linked List is empty\n";
        return 0;
    }

    NodeD<T> * temp = first;
    int iLast = 0;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if(temp -> data == no)
        {
            iLast = iCnt;
        }
        temp = temp -> next;
    }
    return iLast;
}

template <class T>
int Stack<T>:: CalFreq(T no)
{
    if(iCount == 0)
    {
        cout<<"Linked List is empty\n";
        return 0;
    }

    NodeD<T> * temp = first;
    int iFreq = 0;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if(temp -> data == no)
        {
            iFreq++;
        }
        temp = temp -> next;
    }
    return iFreq;
}

template <class T>
T Stack<T>:: Min()
{
    if(iCount == 0)
    {
        cout<<"Linked List is empty\n";
        return 0;
    }

    NodeD<T> * temp = first;
    T Min = temp -> data;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if(temp -> data < Min)
        {
            Min = temp -> data;
        }
        temp = temp -> next;
    }
    return Min;
}

template <class T>
T Stack<T>:: Max()
{
    if(iCount == 0)
    {
        cout<<"Linked List is empty\n";
        return 0;
    }

    NodeD<T> * temp = first;
    T Max = temp -> data;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if(temp -> data > Max)
        {
            Max = temp -> data;
        }
        temp = temp -> next;
    }
    return Max;
}

template <class T>
T Stack<T>:: Summation()
{
    if(iCount == 0)
    {
        cout<<"Linked List is empty\n";
        return 0;
    }

    NodeD<T> * temp = first;
    T Sum = 0;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        Sum = Sum + temp -> data;

        temp = temp -> next;
    }
    return Sum;
}

///////////////////////////////////////////////////////////////////////////////////////////

// Class of Queue

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class Queue
{
    public:
        NodeS<T> * first;
        int iCount;

    Queue();

    void Enqueue(T);
    T Dequeue();

    void Display();
    int Count();

    int SearchFirstOccurance(T);
    int SearchLastOccurance(T);
    int CalFreq(T);
    T Min();
    T Max();
    T Summation();
};

template <class T>
Queue<T>:: Queue()
{
    first = NULL;
    iCount = 0;
}

template <class T>
void Queue<T>:: Enqueue(T no)
{
    NodeS<T> * newn = new NodeS<T>;

    newn -> data = no;
    newn -> next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        NodeS<T> * temp = first;

        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
    }
    iCount++;
}

template <class T>
T Queue<T>:: Dequeue()
{
    T Value;

    if(iCount == 0)
    {
        cout<<"Queue is empty\n";
        return -1;
    }
    else if(iCount == 1)
    {
        Value = first -> data;
        delete first;
        first = NULL;
    }
    else
    {
        Value = first -> data;

        NodeS<T> * temp = first;
        first = first -> next;
        delete temp;
    }
    iCount--;
    return Value;
}

template <class T>
void Queue<T>:: Display()
{
    if(first == NULL)
    {
        cout<<"Nothing to display as Queue is empty\n";
        return;
    }
    NodeS<T> * temp = first;

    cout<<"Elements of Queue are : \n";
    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        cout<<temp -> data<<" -> ";
        temp = temp -> next;
    }
    cout<<"NULL\n";
}

template <class T>
int Queue<T>:: Count()
{
    return iCount;
}

template <class T>
int Queue<T>:: SearchFirstOccurance(T no)
{
    if(iCount == 0)
    {
        cout<<"Linked List is empty\n";
        return 0;
    }

    NodeS<T> * temp = first;
    int iFirst = 0;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if(temp -> data == no)
        {
            iFirst = iCnt;
            break;
        }
        temp = temp -> next;
    }
    return iFirst;
}

template <class T>
int Queue<T>:: SearchLastOccurance(T no)
{
    if(iCount == 0)
    {
        cout<<"Linked List is empty\n";
        return 0;
    }

    NodeS<T> * temp = first;
    int iLast = 0;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if(temp -> data == no)
        {
            iLast = iCnt;
        }
        temp = temp -> next;
    }
    return iLast;
}

template <class T>
int Queue<T>:: CalFreq(T no)
{
    if(iCount == 0)
    {
        cout<<"Linked List is empty\n";
        return 0;
    }

    NodeS<T> * temp = first;
    int iFreq = 0;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if(temp -> data == no)
        {
            iFreq++;
        }
        temp = temp -> next;
    }
    return iFreq;
}

template <class T>
T Queue<T>:: Min()
{
    if(iCount == 0)
    {
        cout<<"Linked List is empty\n";
        return 0;
    }

    NodeS<T> * temp = first;
    T Min = temp -> data;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if(temp -> data < Min)
        {
            Min = temp -> data;
        }
        temp = temp -> next;
    }
    return Min;
}

template <class T>
T Queue<T>:: Max()
{
    if(iCount == 0)
    {
        cout<<"Linked List is empty\n";
        return 0;
    }

    NodeS<T> * temp = first;
    T Max = temp -> data;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        if(temp -> data > Max)
        {
            Max = temp -> data;
        }
        temp = temp -> next;
    }
    return Max;
}

template <class T>
T Queue<T>:: Summation()
{
    if(iCount == 0)
    {
        cout<<"Linked List is empty\n";
        return 0;
    }

    NodeS<T> * temp = first;
    T Sum = 0;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        Sum = Sum + temp -> data;

        temp = temp -> next;
    }
    return Sum;
}

///////////////////////////////////////////////////////////////////////////////////////////

// Class of Searching & Sorting Algorithms

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class ArrayX
{
    public :
        T *Arr;
        int iSize;

        ArrayX(int);
        ~ArrayX();
        void Accept();
        void Display();

        bool LinearSearch(T);
        bool BidirectionalSearch(T);
        bool BinarySearch(T);

        bool CheckSorted();
        void BubbleSortAscending();
        void BubbleSortDescending();
        void BubbleSortEfficient();
        void SelectionSortAscending();
        void SelectionSortDescending();
        void InsertionSortAscending();
        void InsertionSortDescending();
};

template <class T>
ArrayX<T>:: ArrayX(int iNo)
{
    this -> iSize = iNo;
    this -> Arr = new T[iSize];
}

template <class T>
ArrayX<T>:: ~ArrayX()
{
    delete []Arr;
}

template <class T>
void ArrayX<T>:: Accept()
{
    int iCnt = 0;

    cout<<"Enter the elements of array : \n";
    for(iCnt = 0; iCnt < iSize; iCnt++)
    {
        cin>>Arr[iCnt];
    }
}

template <class T>
void ArrayX<T>:: Display()
{
    int iCnt = 0;

    cout<<"Elements of array are : \n";
    for(iCnt = 0; iCnt < iSize; iCnt++)
    {
        cout<<Arr[iCnt]<<"\t";
    }
    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////////////////////

// Functions of searching algorithm

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
bool ArrayX<T>:: LinearSearch(T No)
{
    bool flag = false;

    for(int iCnt = 0; iCnt < iSize; iCnt++)
    {
        if(Arr[iCnt] == No)
        {
            flag = true;
            break;
        }
    }
    return flag;
}

template <class T>
bool ArrayX<T>:: BidirectionalSearch(T No)
{
    bool flag = false;
    int iStart = 0, iEnd = iSize-1;

    while(iStart <= iEnd)
    {
        if((Arr[iStart] == No) || (Arr[iEnd] == No))
        {
            flag = true;
            break;
        }
        iStart++;
        iEnd--;
    }
    return flag;
}

template <class T>
bool ArrayX<T>::BinarySearch(T No)
{
    bool flag = false;

    int iStart = 0, iEnd = 0, iMid = 0;

    iStart = 0;
    iEnd = iSize-1;

    while(iStart <= iEnd)
    {
        iMid = iStart + (iEnd - iStart) / 2;
        if((Arr[iMid] == No) || (Arr[iStart] == No) || (Arr[iEnd] == No))
        {
            flag = true;
            break;
        }
        else if(Arr[iMid] < No)
        {
            iStart = iMid + 1;
        }
        else if(Arr[iMid] > No)
        {
            iEnd = iMid - 1;
        }
    }
    return flag;
}

///////////////////////////////////////////////////////////////////////////////////////////

// Functions of sorting algorithm

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
bool ArrayX<T>::CheckSorted()
{
    int iCnt = 0;
    bool flag = true;

    for(iCnt = 0; iCnt < iSize-1; iCnt++)
    {
        if(Arr[iCnt] <= Arr[iCnt+1])
        {
            continue;
        }
        else
        {
            flag = false;
            break;
        }
    }
    return flag;
}

template <class T>
void ArrayX<T>:: BubbleSortAscending()
{
    T temp;
    int i = 0, j = 0;

    for(i = 0; i < iSize; i++)
    {
        for(j = 0; j < iSize - i - 1; j++)
        {
            if(Arr[j] > Arr[j+1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
            }
        }
    }
}

template <class T>
void ArrayX<T>:: BubbleSortDescending()
{
    T temp;
    int i = 0, j = 0;

    for(i = 0; i < iSize; i++)
    {
        for(j = 0; j < iSize - i - 1; j++)
        {
            if(Arr[j] < Arr[j+1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
            }
        }
    }
}

template <class T>
void ArrayX<T> :: BubbleSortEfficient()
{
    T temp;
    int i = 0, j = 0;
    bool flag = false;

    for(i = 0; i < iSize; i++)
    {
        flag = false;

        for(j = 0; j < iSize - i - 1; j++)
        {
            if(Arr[j] > Arr[j+1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
                flag = true;
            }
        }
        if(flag == false)
        {
            break;
        }
        cout<<"Data after pass : "<<i+1<<"\n";
        Display();
    }
}

template <class T>
void ArrayX<T>:: SelectionSortAscending()
{
    int i = 0, j = 0, min_index = 0;
    T temp;

    for(i = 0; i < iSize-1; i++)
    {
        min_index = i;

        for(j = i+1; j < iSize; j++)
        {
            if(Arr[j] < Arr[min_index])
            {
                min_index = j;
            }
        }
        temp = Arr[i];
        Arr[i] = Arr[min_index];
        Arr[min_index] = temp;
    }
}

template <class T>
void ArrayX<T>:: SelectionSortDescending()
{
    int i = 0, j = 0, min_index = 0;
    T temp;

    for(i = 0; i < iSize-1; i++)
    {
        min_index = i;

        for(j = i+1; j < iSize; j++)
        {
            if(Arr[j] > Arr[min_index])
            {
                min_index = j;
            }
        }
        temp = Arr[i];
        Arr[i] = Arr[min_index];
        Arr[min_index] = temp;
    }
}

template <class T>
void ArrayX<T>:: InsertionSortAscending()
{
    int i = 0, j = 0;
    T selected;

    for(i = 1; i < iSize; i++)
    {
        for(j = i-1, selected = Arr[i]; ((j >= 0) && (Arr[j] > selected)) ; j--)
        {
            Arr[j + 1] = Arr[j];
        }
        Arr[j + 1] = selected;
    }
}

template <class T>
void ArrayX<T>:: InsertionSortDescending()
{
    int i = 0, j = 0;
    T selected;

    for(i = 1; i < iSize; i++)
    {
        for(j = i-1, selected = Arr[i]; ((j >= 0) && (Arr[j] < selected)) ; j--)
        {
            Arr[j + 1] = Arr[j];
        }
        Arr[j + 1] = selected;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////

// Class of Binary Search Tree(BST)

///////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class BST
{
    public:
        struct NodeD<T> *head;

        BST();
        
        struct NodeD<T> *Insert(struct NodeD<T> *head, T No);

        void Preorder(struct NodeD<T> *head);
        void Postorder(struct NodeD<T> *head);
        void Inorder(struct NodeD<T> *head);

        bool Search(struct NodeD<T> *head, T No);

        int CountNodes(struct NodeD<T> *head);
        int CountLeafNodes(struct NodeD<T> *head);
        int CountParentNodes(struct NodeD<T> *head);
};

template <class T>
BST<T>::BST()
{
    head = NULL;
}

template <class T>      
struct NodeD<T>* BST<T>::Insert(struct NodeD<T> *head, T No)
{
    NodeD<T> *newn = new NodeD<T>;
    newn -> data = No;
    newn -> next = NULL;
    newn -> prev = NULL;

    NodeD<T> *temp = head;

    if(head == NULL)
    {
        head = newn;
    }
    else
    {
        while(1)
        {
            if(No == temp -> data)
            {
                cout<<"Dublicate element : Unable to insert\n";
                delete newn;
                break;
            }
            else if(No > temp -> data)
            {
                if(temp -> prev == NULL)
                {
                    temp -> prev = newn;
                    break;
                }
                temp = temp -> prev;
            }
            else if(No < temp -> data)
            {
                if(temp -> next == NULL)
                {
                    temp -> next = newn;
                    break;
                }
                temp = temp -> next;
            }
        }
    }
    return head;
}

template <class T>
void BST<T>::Preorder(struct NodeD<T> *head)
{
    if(head != NULL)
    {
        printf("%d\t",head -> data);
        Preorder(head -> next);
        Preorder(head -> prev);
    }
}

template <class T>
void BST<T>::Postorder(struct NodeD<T> *head)
{
    if(head != NULL)
    {
        Postorder(head -> next);
        Postorder(head -> prev);
        printf("%d\t",head -> data);
    }
}

template <class T>
void BST<T>::Inorder(struct NodeD<T> *head)
{
    if(head != NULL)
    {
        Inorder(head ->next);
        cout<<head -> data<<"\t";
        Inorder(head -> prev);
    }
}

template <class T>
bool BST<T>::Search(struct NodeD<T> *head, T No)
{
    bool flag = false;

    if(head == NULL)
    {
        printf("Tree is empty\n");
        return flag;
    }

    while(head != NULL)
    {
        if(No == head -> data)
        {
            flag = true;
            break;
        }
        else if(No > head -> data)
        {
            head = head -> prev;
        }
        else if(No < head -> data)
        {
            head = head -> next;
        }
    }
    return flag;
}

template <class T>
int BST<T>::CountNodes(struct NodeD<T> *head)
{
    static int iCount = 0;

    if(head != NULL)
    {
        iCount++;
        CountNodes(head -> next);
        CountNodes(head -> prev);
    }
    return iCount;
}

template <class T>
int BST<T>::CountLeafNodes(struct NodeD<T> *head)
{
    static int iCount = 0;

    if(head != NULL)
    {
        if((head -> next == NULL) && (head -> prev == NULL))
        {
            iCount++;
        }
        CountLeafNodes(head -> next);
        CountLeafNodes(head -> prev);
    }
    return iCount;
}

template <class T>
int BST<T>::CountParentNodes(struct NodeD<T> *head)
{
    static int iCount = 0;

    if(head != NULL)
    {
        if((head -> next != NULL) || (head -> prev != NULL))
        {
            iCount++;
        }
        CountParentNodes(head -> next);
        CountParentNodes(head -> prev);
    }
    return iCount;
}