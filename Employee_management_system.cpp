#include <iostream>
using namespace std;

struct Employee 
{
	// add enum in this program
	
	int Emp_id;
	char name[30];
	char Gender;
	char phone_no[10];
	char address[80];
	double salary;
	double tax;
	
};

double calculate_tax(double salary)
{
	double tax;
	if (salary < 10000)
	{
		tax = 0;
	}
	else if (salary > 10000 && salary <=20000)
	{
		tax = (salary / 100) * 2;
	}
	else if (salary > 20000 && salary <=50000)
	{
		tax  = (salary / 100) * 5;
	}
	else
	{
		tax = (salary / 100) * 10;	
	}
	return tax;
}

struct Employee add_record()
{
	
	struct Employee record;
	cout<<"ID : ";
	cin>>record.Emp_id;
	cin.ignore();
	cout<<"Name : ";
	cin.getline(record.name, 30);
	cout<<"Address : ";
	cin.getline(record.address, 80);
	cout<<"gender : ";
	cin>>record.Gender;
	cout<<"phone_no : ";
	cin>>record.phone_no;
	cout<<"salary : ";
	cin>>record.salary;
	
	record.tax = calculate_tax(record.salary);
	
	return record;
}

print_record(struct Employee record)
{
	
		
	cout<<endl<<endl;
	cout<<"ID : "<< record.Emp_id<<endl;
	cout<<"Name : "<< record.name<<endl;
	cout<<"Address : "<< record.address<<endl;
	cout<<"gender : "<< record.Gender<<endl;
	cout<<"phone_no : "<< record.phone_no<<endl;
	cout<<"salary : "<< record.salary<<endl;
	cout<<"tax : "<<record.tax;
	
	cout<<endl<<endl<<endl;
	
}


int main()
{
	
	cout<<"           EMPLOYEE'S RECORD     "<<endl;
	cout<<"------------------------------------"<<endl;
	cout<<"------------------------------------"<<endl<<endl;
	cout<<" New Records           		[ N ]"<<endl;
	cout<<" Append a Record           	[ A ]"<<endl;
	cout<<" Delete a Record           	[ D ]"<<endl;
	cout<<" Modify a Record           	[ M ]"<<endl;
	cout<<" Find a Record           	[ F ]"<<endl;
	cout<<" Sorting Records           	[ S ]"<<endl;
	cout<<" Print Records           	[ P ]"<<endl;
	cout<<" Exit          			[ E ]"<<endl;

	
	int records = 1; // change this value to increase number of employess
	int emp_found=0;
	Employee e[30];
	
	char Choice;
	
	while (Choice != 'E' || Choice != 'e')
	{
		cout<<endl<<endl;
		cout<<"Enter your Choice : ";
		cin>>Choice;
		switch(Choice)
		{
			
			case 'D':
			case 'd':
				int delete_emp_id;
				cout<<"Enter the id of the Employee you want to delete : ";
				cin>>delete_emp_id;
				for ( int i = 0 ; i < records ; i++)
				{
					if(e[i].Emp_id == delete_emp_id)
					{
						emp_found++;
						if (i == records )
						{
							records--;
						}
						else{
							for( int j = i ; j < records - 1 ; j++ )
							{
								e[j] = e[j + 1];
							}	
							records--;						
						}
					}
				}
				if (emp_found == 0)
				{
					cout<<"Employee with such id does not exit"<<endl;
				}
				else
				{
					cout<<"Employee deleted successfully"<<endl;
				}
				break;
			
			case 'S':
			case 's':
				int sort_order;
				cout<<"Enter 1 - Ascending 0 - descending : ";
				cin>>sort_order;
				if (sort_order == 1)
				{
					for (int i = 0 ; i < records ; i++)
					{
						 for(int j = 0; j <= records-i ; j++)
						 {
						 	if (e[j].Emp_id > e[j + 1].Emp_id)
						 	{
						 		Employee temp;
						 		temp = e[j];
						 		e[j] = e[j + 1];
						 		e[j + 1] = temp;
							 }
						 }
					}
				}
				else
				{
					for(int i=0;i<records;i++)
					{		
						for(int j=i+1;j<records;j++)
						{
							if(e[i].Emp_id < e[j].Emp_id)
							{
								Employee temp;
								temp  = e[i];
								e[i] = e[j];
								e[j]=temp;
							}
						}
					}
				}
				break;
			
			case 'E':
			case 'e':
				return 0;
				
			case 'F':
			case 'f':
				int key_id;
				cout<<"Enter Employee id of employee whom you want to find : ";
				cin>>key_id;
				for(int i= 0 ; i < records; i++)
				{
					if ( e[i].Emp_id == key_id )
					{
						cout<<"Employee Found"<<endl<<endl;
						break;
					}
				}
				break;
				
			case 'A':
			case 'a':
				Employee new_emp;
				new_emp = add_record();
				records += 1;
				e[records - 1] = new_emp;
	
				break;
							
			case 'N':
			case 'n':
				for(int i = 0 ; i < records ; i++)
					{
						cout<<"Enter data for Empoyee number : "<<i+1<<endl;
						e[i] =  add_record();	
					}	
				break;	
				
			case 'P':
			case 'p':
				char option;
				cout<<"One by One or All (O/A)?  ";
				cin>>option;
				if (option == 'O' || option == 'o')
				{
					int i = 0, print_next;
					e[i];
					print_record(e[i]);
					i++;
					if (i < records - 1)
					{
						while (print_next == 1)
						{
							cout<< "1 to print next 0 to exit";
							cin>>print_next;
							if (print_next == 1)
							{
								print_record(e[i]);
								i++;
							}
							else
							{
								break;
							}
						}					
					}		
				}
				
				else
				{
					cout<<records;
					for (int i= 0 ; i< records ; i++)
					{
						
						print_record(e[i]);
					}
				}
				break;
		
			case 'M':
			case 'm':
				int emp_id, i = 0;
				bool not_found = true;
				cout<<"Enter Employee id whom you want to modify : ";
				cin>>emp_id;
				while(i< records)
				{
					if (e[i].Emp_id == emp_id )
					{
						e[i] = add_record();
						break;
					}
					else 
					{
						not_found = false;
					}
					i++;
				}
				
				if (not_found == false)
				{
					cout<<"Employee with such if does not exit ";
				}
				
				break;
				
				

				 
		}
	}	
}
