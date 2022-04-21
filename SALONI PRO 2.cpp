#include<fstream>
#include<iostream>


using namespace std;

class shopping
{
	private:
		int pcode;
		float price;
		float dis;
		string pname;
		
		public:
			void menu();
			void administrator();
			void buyer();
			void add();
			void edit();
			void rem();
			void list();
			void receipt();
			
			
			
};

void shopping :: menu()
{
	m:
	int choice;
	string email;
	string password;
	cout<<"\n\t______________________________________________________\n";
	cout<<"\t                                                        \n";
	cout<<"\t              SUPERMARKET MAIN MENU                      \n";
	cout<<"\t                                                         \n";
	cout<<"\t _______________________________________________________\n";
	cout<<"\t                                                        \n";
	
	cout<<"\t |        1) ADMINISTRATOR             |\n";
	cout<<"\t |                                     |\n";
	cout<<"\t |        2) BUYER                     |\n";
	cout<<"\t |                                     |\n";
	cout<<"\t |        3) EXIT                      |\n";
	cout<<"\t |                                     |\n";
	cout<<"\n\t\t\t Please select!";
	
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			
			cout<<"\t\t\t PLEASE LOGIN \n";
			cout<<"\t\t\t ENTER EMAIL \n";
			cin>>email;
			cout<<"\t\t\t ENTER PASSWORD \n";
			cin>>password;
			if(email=="shv@gmail.com"&& password=="Shv@9" )
			{
				administrator();
				
			}
			else
			{
			cout<<"INVALID EMAIL/PASSWORD";
		}
		break;
		case 2:
		{
			buyer();
		}
		case 3:
		{
			exit(0);
		}
		default:
			{
			cout<<"\n PLEASE SELECT FROM THE GIVEN OPTIONS\n";
			
		}
			
	}
	
	goto m;
	
}

void shopping :: administrator()
{ m:
	int choice;
	cout<<"\n\n\n\t\t\t ADMINISTRATOR MENU";
	cout<<"\n\n\n\t\t\t |______  1) Add the product _______|";
	cout<<"\n\n\n\t\t\t |______  2) Modify the product_____|";
	cout<<"\n\n\n\t\t\t |______  3) Delete the product_____|";
	cout<<"\n\n\n\t\t\t |______  4) Back to main menu _____|";
	
	cout<<"\n\n\n\t\t\t PLEASE ENTER YOUR CHOICE \n";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
		
		
			add();
			break;
			
	   	case 2:
			edit();
			break;
			
		case 3:
			rem();
			break;
			
		case 4:
			menu();
			break;
			
			default:
				cout<<"invalid choice";
				
			
	}
	goto m;
}
	void shopping :: buyer()
	{    m:
		int choice;
		cout<<"\n\t\t Buyer \n";
		cout<<"\t\t\t_________________\n";
		cout<<"\t\t                  \n ";
		cout<<"\t\t\t 1) BUY PRODUCT  \n";
		cout<<"\t\t\t 2) GO BACK      \n";
		cout<<"\t\t\t ENTER YOUR CHOICE :";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				receipt();
				break;
				
	    	case 2:
		    	menu();
		    	break; 
		    default:
		    	cout<<"INVALID CHOICE";
		    	
			
			
		}
		goto m;
	}
	
	void shopping :: add()
	{    m:
		fstream data;
		int c;
		int token=0;
		float p;
		float d;
		string n;
		
		cout<<"\n\n\t\t\t Add new produt";
		cout<<"\n\n\t product code of the product";
		cin>>pcode;
		cout<<"\n\n\t Name of the product";
		cin>>pname;
		cout<<"\n\n\t Price of the product";
		cin>>price;
		cout<<"\n\n\t Discount on product";
		cin>>dis;
		
		data.open("database.txt",ios::in);
		
		if(!data)
		{ data.open("database.txt",ios::app|ios::out);
		
		data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
		
		}
		else
		{data>>c>>n>>p>>d;
		
		while(!data.eof())
		
		{
			if( c == pcode)
			{
				token++;
			}
			data>>c>>n>>p>>d;
		}
		data.close();
		
		
		if(token==1)
		goto m;
		else
		{
			data.open("database.txt" , ios::app|ios::out);
				data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
				data.close();
		}
		
		
		
		
	}
	cout<<"\n\n\t\t Record inserted !";
	
	
	
	
	
}


void shopping::edit()
{
	fstream data,data1;
	int pkey;
	int token =0;
	int c;
	float p;
	float d;
	string n;
	
	
	cout<<"\n\n\t\t Modify the product";
	cout<<"\n\n\t\t PRODUCT CODE";
	cin>>pkey;
	
		data.open("database.txt",ios::in);
		
		if(!data)
		{
			cout<<"\n\n\t\t FILE DOESN'T EXIST";
			
		}
	    else
	    {
	    	data1.open("database.txt",ios::app|ios::out);
	    	data>>pcode>>pname>>price>>dis;
	    		while(!data.eof())
		
		{
			if( pkey == pcode)
			{
				cout<<"\n\t\t PRODUCT NEW CODE";
				cin>>c;
				cout<<"\n\t\t NAME OF THE PRODUCT";
				cin>>n;
				cout<<"\n\t\t PRICE OF THE PRODUCT";
				cin>>p;
				cout<<"\n\t\t DISCOUNT";
				cin>>d;
				data1<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
				cout<<"\n\n\t\t RECORD EDITED";
				token++;
			}
	    	else
	    	{
	    		data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
				
			}
			data>>pcode>>pname>>price>>dis;
			
		}
		data.close();
		data1.close();
		
		remove("database.txt");
		rename("database1.txt","database.txt");
		if(token==0)
	
	{
		cout<<"\n\n RECORD NOT FOUND SORRY";
		
	}
}
}
void shopping::rem()
{	fstream data,data1;
	int pkey;
	int token =0;

	
	
	cout<<"\n\n\t\t Delete the product";
	cout<<"\n\n\t\t PRODUCT CODE";
	cin>>pkey;
	
		data.open("database.txt",ios::in);
		
		if(!data)
		{
			cout<<"\n\n\t\t FILE DOESN'T EXIST";
			
		}
	    else
	    {
	    	data1.open("database.txt",ios::app|ios::out);
	    	data>>pcode>>pname>>price>>dis;
	    		while(!data.eof())
		
		{
			if( pcode== pkey)
			{
			
				cout<<"\n\n\t\t product deleted successfully";
				token++;
			}
	    	else
	    	{
	    		data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
				
			}
			data>>pcode>>pname>>price>>dis;
		}
				data.close();
		data1.close();
		
		remove("database.txt");
		rename("database1.txt","database.txt");
		if(token==0)
	
	{
		cout<<"\n\n RECORD NOT FOUND SORRY";
		
	}
}
			
	
	
}


void shopping:: list()
{
	fstream data;
	data.open("database.txt",ios::in);
	cout<<"\n\n________________________________________________\n";
	cout<<"ProNo\t\tName\t\tPrice\n";
	cout<<"\n\n_________________________________________________\n";
	data>>pcode>>pname>>price>>dis;
	    		while(!data.eof())
		{
				cout<<" "<<pcode<<" "<<pname<<" "<<price<<"\n";
				data>>pcode>>pname>>price>>dis;
		}
		data.close();
		
}
void shopping ::receipt()
{
	fstream data;
	int arrc[100];
	int arrq[100];
	char choice;
	int c=0;
	float amount;
	float dis=0;
	float total=0;
	cout<<"\n\n\t\t RECIEPT";
	data.open("database.txt",ios::in);
	if(!data)
	{
		cout<<"\n\n\t\t EMPTY DATABASE";
		
	}
	else
	{
		data.close();
		
	list();
	cout<<"\n___________________________________________\n";
	cout<<"\n             PLEASE PLACE THE ORDER        \n";
	cout<<"\n___________________________________________\n";
	do
	{   m:
		cout<<"\n\t ENTER PRODUCT CODE";
		cin>>arrc[c];
		cout<<"\n\t ENTER THE PRODUCT QUANTITY";
		cin>>arrq[c];
		for(int i =0;i<c;i++)
		{
			if(arrc[c]==arrq[i])
			{
				cout<<"\n\n\t\t DUPLICATE PRODUCT CODE . PLEASE TRY AGAIN!";
				goto m;
				
			}
		}
		c++;
		cout<<"\n\n DO YOU WANT TO BUY ANOTHER PRODUCT IF YES  PRESS y ELSE NO";
		cin>>choice;
		
	}
	while(choice=='y');
	cout<<"\n\n\t\t _______________RECIEPT__________________\n";
	cout<<"\n Product No\t Product Name\t Product Quantity\t Price\t Amount\t Amount with discount\n";
	
	for(int i =0;i<c;i++)
	{
			data.open("database.txt",ios::in);
				data>>pcode>>pname>>price>>dis;
				while(!data.eof())
				{
					if(pcode==arrc[i])
					{
						amount=price*arrq[i];
						dis=amount-(amount*dis/100);
						total=total+dis;
						cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t"<<amount<<"\t\t"<<dis;
						
					}
					
						data>>pcode>>pname>>price>>dis;
				}
	}
	data.close();
	}
	cout<<"\n\n___________________________________________________________";
	cout<<"\n TOTAL AMOUNT : "<<total;
	
	
}
int main()
{
	shopping s;
	s.menu();
}
