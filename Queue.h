#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <string>
using namespace std;


class Queue
{
    private:
        struct QueueNode
        {
            int pSize;        //size of party
            string pName;     //name of party
            QueueNode *next;  //pointer to next node
        };
        QueueNode *front;
        QueueNode *rear;
        int numItems;

    public:
        //Constructor - creates an empty queue
        Queue()
        {
            front = 0;
            rear = 0;
            numItems = 0;
        }

        bool isEmpty() const
        {
            bool status;

            if(numItems>0)
                status = false;
            else
                status = true;
            return status;
        }

       /* bool isFull() const
        {

        }*/

        void clear()
        {
            //Dummy values.
            int value;
            string dummy;

            while(!isEmpty())
                dequeue(value,dummy);
        }

        //Destructor
        ~Queue()
        {
            clear();
        }

        void enqueue(int num, string name)
        {
            //might need to pass a string name up there
            QueueNode *newNode = 0;

            //Create a new node and store num there.
            newNode = new QueueNode;
            newNode->pSize = num;
            newNode->pName = name;
            newNode->next = 0;

            //Adjust front and rear as needed.
            if(isEmpty())
            {
                front = newNode;
                rear = newNode;
            }
            else
            {
                rear->next = newNode;
                rear = newNode;
            }
            //Update numItems.
            numItems++;
        }

        void dequeue(int &num, string &name)
        {
            QueueNode *temp = 0;

            if(isEmpty())
            {
                cout << "The queue is empty.\n";
            }
            else
            {
                //Save front node value in num
                num = front->pSize;
                name = front->pName;

                //Remove front node and delete it.
                temp = front;
                front = front->next;
                delete temp;

                //Update numItems.
                numItems--;
            }
        }

        int getSizeAtFront()
        {
            if(front == 0)
                return 0;
            else
                return front->pSize;
        }

};

#endif // QUEUE_H
