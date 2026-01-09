#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node* PNODE;

class DoublyCL
{
    private :          
        PNODE first;
        PNODE last;
        int iCount;
        
    public:
        DoublyCL()
        {
            cout<<"Object of DoublyCL gets created.\n";
            this -> first = NULL;
            this -> last = NULL;
            this -> iCount = 0;
        }

        void InsertFirst(int no)        
        {
            PNODE newn = NULL;

            newn = new NODE;

            newn -> data = no;
            newn -> next = NULL;
            newn -> prev = NULL;

            if((this -> first == NULL) && (this -> last == NULL))
            {
                this -> first = newn;
                this -> last = newn;
            }
            else
            {
            newn -> next = this -> first;
            this -> first -> prev = newn;
            this -> first = newn;
            }
           
            this -> last -> next = this -> first;
            this -> first -> prev = this -> last;
            this -> iCount++;
        }

        void InsertLast(int no)
        {
            PNODE newn = NULL;
            newn = new NODE;

            newn -> data = no;
            newn -> next = NULL;
            newn -> prev = NULL;

            if((this -> first == NULL )&& (this -> last == NULL))      
            {
                this -> first = newn;
                this -> last = newn;
            }
            else
            {
                
                this -> last -> next = newn;
                newn -> prev = this -> last;
                this -> last = newn;
            }

            this -> last -> next = this -> first;
            this -> first -> prev = this -> last;
            this -> iCount++;
        }

        void DeleteFirst()
        {
            if((this -> first == NULL) && (this -> last == NULL))                  
            {
                 return;
            }

            else if(this -> first == this -> last)                            
            {
                delete this -> first;
                this -> first = NULL;
                this -> last = NULL;
            }
            else
            {
                this -> first = this -> first->next;
                delete this->first -> prev;

                this -> last-> next = this -> first;
                this -> first -> prev = this -> last;
            }
            this -> iCount--;
        }

        void DeleteLast()
        {
             if((this -> first == NULL) && (this -> last == NULL))                  
            {
                 return;
            }

            else if(this -> first == this -> last)                            
            {
                delete this -> first;
                this -> first = NULL;
                this -> last = NULL;
            }
            else
            {
                this -> last = this -> last -> prev;
                delete this-> last -> next;

                this -> last-> next = this -> first;
                this -> first -> prev = this -> last;
            }

            this -> iCount--;
        }

        void Display()
        {
            cout<<"<=>";

            do  
            {
                cout<<"| "<<this ->first -> data<<" |<=>";
                this -> first = this -> first -> next;
            }while(this -> first != this -> last ->next);
            
            cout<<"\n";
        }

        int Count()
        {
            return this  -> iCount;
        }

        void InsertAtPos(int no, int pos)
        {
            PNODE temp = NULL;
            int iCnt = 0;
            PNODE newn = NULL;

            if(pos < 1 || pos > this -> iCount+1)
            {
                cout<<"Inavlid Position\n";
                return;
            }

            if(pos == 1)
            {
                this -> InsertFirst(no);
            }
            else if(pos == this -> iCount+1)
            {
                this -> InsertLast(no);
            }
            else
            {
                newn = new NODE;

                newn -> data = no;
                newn -> next = NULL;
                newn -> prev = NULL;

                temp = this ->first;
                for(iCnt = 1; iCnt < pos - 1; iCnt++)
                {
                    temp = temp -> next;
                }
                newn -> next = temp -> next;
                temp -> next -> prev = newn;
                temp -> next = newn;
                newn -> prev = temp;
             }
             this -> iCount++;
        }

        void DeleteAtPos(int pos)
        { 
            PNODE temp = NULL;
            int iCnt = 0;
            
            if(pos < 1 || pos > this -> iCount)
            {
                cout<<"Inavlid Position\n";
                return;
            }

            if(pos == 1)
            {
                this -> DeleteFirst();
            }
            else if(pos == this -> iCount)
            {
                this -> DeleteLast();
            }
            else
            {
                temp = this -> first;
                for(iCnt = 1; iCnt < pos - 1; iCnt++)
                {
                    temp = temp -> next;
                }

                temp -> next = temp -> next -> next;
                
                delete temp -> next -> prev;

                temp -> next -> prev = temp;

                
            }

            this -> iCount--;
        }

};

int main()
{
    DoublyCL obj;
    int iRet = 0;
    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();

    iRet=obj.Count();

    cout<<"number of nodes are:"<<iRet<<"\n";

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);

    obj.Display();

    iRet=obj.Count();

    cout<<"number of nodes are:"<<iRet<<"\n";

    obj.DeleteFirst();
    
    obj.Display();

    iRet=obj.Count();

    cout<<"number of nodes are:"<<iRet<<"\n";

    obj.DeleteLast();

    obj.Display();

    iRet=obj.Count();

    cout<<"number of nodes are:"<<iRet<<"\n";

    obj.InsertAtPos(105,4);

    obj.Display();

    iRet=obj.Count();

    cout<<"number of nodes are:"<<iRet<<"\n";

    obj.DeleteAtPos(4);

    obj.Display();

    iRet=obj.Count();

    cout<<"number of nodes are:"<<iRet<<"\n";

    return 0;
}