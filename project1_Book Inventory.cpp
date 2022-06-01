#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
class book
{
	private:
			char *author,*title,*publisher;
		    float *price;
			int *stock;
	public:
		    book()
		    	  {
		    	  	author=new char[20];
		    	  	title= new char[20];
		    	  	publisher= new char[20];
		    	  	price= new float[20];
		    	  	stock= new int[20];
				  }
			void feeddata();
			void editdata();
			void showdata();
			int  search(char[],char[]);
			void buybook();
};
void book::feeddata()
{
	cin.ignore();
	cout<<"Enter author name: "; cin.getline(author,20);
	cout<<"Enter title name: ";  cin.getline(title,20);
	cout<<"Enter publisher name: "; cin.getline(publisher,20);
	cout<<"Enter price: "; cin>>*price;
	cout<<"Enter stock position: "; cin>>*stock;
}
void book::editdata()
{
    cout<<"Enter author name: "; cin.getline(author,20);
	cout<<"Enter title name: ";  cin.getline(title,20);
	cout<<"Enter publisher name: "; cin.getline(publisher,20);
	cout<<"Enter price: "; cin>>*price;
	cout<<"Enter stock position: "; cin>>*stock;	
}
void book::showdata()
{
	cout<<"Show author: "; cin>>author;
	cout<<"Shou title: "; cin>>title;
	cout<<"show publisher: "; cin>>publisher;
	cout<<"Show price: "; cin>>*price;
	cout<<"Show stock: "; cin>>*stock;
}
int book::search(char tbuy[20], char abuy[20])
{
	if(strcmp(tbuy,title)==0 && strcmp(abuy,author)==0)
	     return 1;
	else
	    return 0;
}
void book::buybook()
{
	int count;
	cout<<"\nEnter number of books to buy: "; cin>>count;
	if(count<=*stock)
	{
		*stock=*stock-count;
		cout<<"\nBuy book sucessfully";
		cout<<"\nAmount "<<(*price)*count;
	}
	else
	    cout<<"\nNot available in stock";
}
int main()
{
	book *B[20];
	int i=0,r,t,choice;
	char tbuy[20], abuy[20];
	while(1)
	{
		cout<<"\n\n\t\tMENU"
		<<"\n1. Entry of New Book"
		<<"\n2. Buy Book"
		<<"\n3. Search For Book"
		<<"\n4. Edit Details Of Book"
		<<"\n5. Exit"
		<<"\n\nEnter your Choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1: B[i]=new book;
			        B[i]->feeddata();
			        i++;
			        break;
			case 2: cin.ignore();
				    cout<<"\nEnter Title Of Book: "; cin.getline(tbuy,20);
				    cout<<"Enter Author Of Book: ";  cin.getline(abuy,20);
				    for(t=0;t<i;t++)
				    {
				    	if(B[t]->search(tbuy,abuy))	{
						B[t]->buybook();
						break;
					}
					if(t==1)
				    cout<<"\nThis Book is Not in Stock";
				
				    break;
			case 3: cin.ignore();
				    cout<<"\nEnter Title Of Book: "; cin.getline(tbuy,20);
			        cout<<"Enter Author Of Book: ";  cin.getline(abuy,20);
				    for(t=0;t<i;t++)	
					{
					if(B[t]->search(tbuy,abuy))	
					{
						cout<<"\nBook Found Successfully";
						B[t]->showdata();
						break;
					}
				    }
				    if(t==i)
				    cout<<"\nThis Book is Not in Stock";
				    break;
			case 4: cin.ignore();
				    cout<<"\nEnter Title Of Book: "; cin.getline(tbuy,20);
				    cout<<"Enter Author Of Book: ";  cin.getline(abuy,20);
				    for(t=0;t<i;t++)	
					{
					if(B[t]->search(tbuy,abuy))	
					{
						cout<<"\nBook Found Successfully";
						B[t]->editdata();
						break;
					}
				}
				    if(t==i)
				    cout<<"\nThis Book is Not in Stock";
				    break;
			
			case 5: exit(0);
			        default: cout<<"\nInvalid Choice Entered";
		}
	}
}
            return 0;
}

