#include<iostream>
using namespace std;
#define N 100
class dq
{
	int a[N];
	int front,rear; 
	public :
		dq()
		{
			front=-1;
			rear=-1;
		}
		bool empty()
		{
			return(front==-1&&rear==-1);
		}
		int size()
		{
			int counter=0,i;
			if(front==-1)
			return 0;
			else
			for(i=front;i!=(rear+1)%N;i=(i+1)%N)
			counter++;
			return counter;
		}
		bool full()
		{
			return (rear+1)%N==front?true:false;
		}
		void addfront(int x)
		{
			cout<<"adding front : "<<x<<" \n";
		    if(full())
		    {
			    cout<<"Error: queue is full\n";
		     	return;
		    }
		    if (empty())
		    { 
				front = rear = 0; 
		    }
		    else
		    {
	    	    front = (N+front-1)%N;
	     	}
	    	a[front] = x;
		}
		void addrear(int x)
		{
			cout<<"adding rear : "<<x<<" \n";
	    	if(full())
	    	{
	     		cout<<"Error: queue is full\n";
	    		return;
	    	}
	    	if (empty())
	    	{ 
	    		front = rear = 0; 
	    	}
	    	else
	    	{
	    	    rear = (rear+1)%N;
	    	}
	    	a[rear] = x;
		}
		int deletefront()
		{
			if(front==-1)
			cout<<"dq is empty";
			else
			front =(front+1)%N;
			return a[(N+front-1)%N];
		}
		int deleterear()
		{
			if(rear==-1)
			cout<<"dq is empty";
			else
			rear=(N-rear-1)%N;
			return a[(rear+1)%N];
		}
		void deque()
		{
			front =-1;
			rear=-1;
		}
		void print()
		{
			int i;
			cout<<"the queue is : ";
			if(front==0&&rear==0)
			cout<<a[0];
			else
			for(i=front;i!=(rear+1)%N;i=(i+1)%N)
			cout<<a[i]<<"  ";
			cout<<"\n";
		}
}dq1;
int main()
{
	int a,x,n,size;
	bool empty;
	while(a!=8)
	{
		cout<<"\n======================================";
		cout<<"\n if u wanna add at front enter 1 \n add at rear 2 \n delete at front 3 \n delete at rear 4 \n check empty 5 \n size 6 \n to empty queue 7  \n";
	cout<<"to exit enter 8 \n to print the queue 9 : ";
	cin>>a;
	cout<<"======================================"<<endl;
	switch(a)
	{
		case 1: 
		{
			cout<<"enter the element : ";
			cin>>x;
			dq1.addfront(x);
			break;
		}
		case 2: 
		{
			cout<<"enter the element : ";
			cin>>x;
			dq1.addrear(x);
			break;
		}
		case 3:
			{
				n=dq1.deletefront();
				cout<<"deleted element is :"<<n;
				break;
			}
			case 4:
			{
				n=dq1.deleterear();
				cout<<"deleted element is :"<<n;
				break;
			}
		case 5:
			{
				empty = dq1.empty();
				break;
			}
		case 6:
			{
				size =dq1.size();
				cout<<"size of queue is : "<<size;
				break;
			}
		case 7:
		{
			dq1.deque();
			break;
		}	
		case 8:
			break;
		case 9:
			{
				dq1.print();
				break;
			}
		default:
		{
			cout<<"\n you have entered wrong number \n";
		}
	}
	}
}
