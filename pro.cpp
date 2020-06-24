#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
class Node{
	public :
	string user_name;
	long long int id;
	string bank_name;
	long int bal;
	long long int loan;
	Node *block_add;
	Node *next;
};
class List : public Node{
	public:
	Node *head;
	void create_blockchain();
	void display_blockchain();	
	void display_blockchain_head();
	void display_blockchain_node(Node *ptr);
	void search_blockchain();
	void insert_block();
	void transact_blockchain();
	void insert_Loan();
	void bank_database();
	void detect_remove_loop();
};
void List :: create_blockchain(){
	cout<<"\n \tCREATING THE BLOCKCHAIN : \n";
	head = new Node();
	Node *temp, *new_node;
	head->user_name ="RBI";
	head->id=18070124029;
	head->bank_name="CENTRAL";
	head->bal=0;
	head->block_add=head;
	head->next=NULL;
	temp=head;
	
	string c_uname,c_bname;
	long long int c_id; 
	char choice;
	long int c_bal,c_loan;
	int n;
	
	do{
	cout<<"\nEnter the name of the user : ";
	cin>>c_uname;
	cout<<"\nEnter the Unique Identification Number or Aadhar number of the user : ";
	cin>>c_id;
	cout<<"\nEnter the name of the Bank : ";
	cin>>c_bname;
	cout<<"\nEnter the Account Balance : ";
	cin>>c_bal;
	cout<<"\nEnter the Account Outsanding Loan Amount : ";
	cin>>c_loan;
	
	new_node = new Node();
	new_node->user_name=c_uname;
	new_node->id=c_id;
	new_node->bank_name=c_bname;
	new_node->bal=c_bal;
	new_node->loan=c_loan;
	new_node->block_add=new_node;	
	new_node->next=NULL;
	
	temp->next=new_node;
	temp=temp->next;	
	cout<<"\n \t\t*User details are entered*";
	cout<<"\nDo you want to add another node to the private BlockChain :\n 1. Press y or Y for yes. \n";
	cin>>choice;
	cout<<"\n";
	}while(choice=='y'||choice=='Y');
	
	cout<<"\n\t BLOCKCHAIN NETWORK SUCCESFULLY CREATED";
}
void List :: display_blockchain(){
	Node *ptr;
	ptr=head->next;
	cout<<"\n\nDISPLAYING BLOCKCHAIN DETAILS : \n";
	while(ptr!=NULL){
		cout<<"\t ACCOUNT HOLDERS NAME : "<<ptr->user_name<<"\t AADHAR NUMBER : "<<ptr->id;
		cout<<"\n";
		cout<<"\t BANK NAME : "<<ptr->bank_name<<"\t\t BLOCK ADDRESS : "<<ptr->block_add;
		cout<<"\n";
		cout<<"\t ACCOUNT BALANCE : "<<ptr->bal<<"\t ACCOUNT LOAN O/S : "<<ptr->loan;
		cout<<"\n\n";
		ptr=ptr->next;
	}
}
void List :: display_blockchain_head(){

	cout<<"\n\nDISPLAYING GENESIS NODE DETAILS\n";
	Node *ptr;
	ptr=head->next;
	long long int balance=0,loann=0,count=0;
	while(ptr!=NULL){
		balance=balance+ptr->bal;
		loann=loann+ptr->loan;
		count++;
		ptr=ptr->next;
	}
	head->id=count;
	head->bal=balance;
	head->loan=loann;
	cout<<"\tACCOUNT HOLDERS NAME : "<<head->user_name<<"\t\t\tNO. OF ACCOUNTS ASSOCIATED WITH RBI : "<<head->id;
	cout<<"\n";
	cout<<"\tBANK NAME : "<<head->bank_name<<"\t\t\t\tBLOCK ADDRESS : "<<head->block_add;
	cout<<"\n";
	cout<<"\tACCOUNT BALANCE i.e. TOTAL BALANCE IN ALL ACCOUNTS : "<<head->bal<<"\tTOTAL LOAN IN ALL ACCOUNTS : "<<head->loan;
	cout<<"\n\n";	
}
void List :: display_blockchain_node(Node *ptr){
		cout<<"\n DISPLAYING BLOCK DETAILS\n";
		cout<<"\t ACCOUNT HOLDERS NAME : "<<ptr->user_name<<"\t AADHAR NUMBER : "<<ptr->id;
		cout<<"\n";
		cout<<"\t BANK NAME : "<<ptr->bank_name<<"\t\t BLOCK ADDRESS : "<<ptr->block_add;
		cout<<"\n";
		cout<<"\t ACCOUNT BALANCE : "<<ptr->bal<<"\t ACCOUNT LOAN O/S : "<<ptr->loan;
		cout<<"\n\n";
}
void List :: search_blockchain(){
	Node *ptr;
	ptr=head;
	int found=0,choice;
	long long int s_id;
	string s_uname,s_bname;
	cout<<"\n SEARCHING THE DATABASE";
	cout<<"\n1. for SEARCH by User Name. \n2. for SEARCH by Id number.";
	cin>>choice;
	if(choice==2){
	cout<<"\n Enter the Id or AADHAR No. : ";
	cin>>s_id;
	while(ptr!=NULL){
		if(ptr->id==s_id){
			found=1;
			cout<<"\nRecord Found";
			display_blockchain_node(ptr);
		}
		ptr=ptr->next;
	}
}
	else if(choice==1){
	cout<<"\n Enter the User's name' : ";
	cin>>s_uname;
	while(ptr!=NULL){
		if(ptr->user_name==s_uname){
			found=1;
			cout<<"\nRecord Found";
			display_blockchain_node(ptr);
		}
		ptr=ptr->next;
	}
	}
	else{
		cout<<"\n Invalid Entry.";
	}
	if(found!=1){	
	cout<<"\nOOPS! Record not found";
	}
}
void List :: bank_database(){
	Node *ptr;
	ptr=head;
	int found=0,choice;
	long long int s_id;
	string s_uname,s_bname;
	cout<<"\n BANK WISE - CLIENT DATABASE";
	cout<<"\n Enter the Bank's Name : ";
	cin>>s_bname;
	while(ptr!=NULL){
		if(ptr->bank_name==s_bname){
			found=1;
			display_blockchain_node(ptr);
		}
		ptr=ptr->next;
	}
	if(found!=1){	
	cout<<"\nNO ACCOUNT ASSOCIATED WITH THIS BANK";
	}
}
void List :: insert_block(){
	string c_uname,c_bname;
	long long int c_id;
	int found=0; 
	long int c_bal,c_loan;
	Node *ptr,*temp,*new_node;
	ptr=head;
	temp=head;
	cout<<"\nEnter the name of the user : ";
	cin>>c_uname;
	cout<<"\nEnter the Unique Identification Number or Aadhar number of the user : ";
	cin>>c_id;
	cout<<"\nEnter the name of the Bank : ";
	cin>>c_bname;
	cout<<"\nEnter the Account Balance : ";
	cin>>c_bal;
	cout<<"\nEnter the Account Outsanding Loan Amount : ";
	cin>>c_loan;
	while(ptr!=NULL){
		if(ptr->id==c_id){
			cout<<"\n Account having similar Id Already Exists";
			found=1;
			break;
		}
		ptr=ptr->next;
	}
	if(found!=1){
	while(temp->next!=NULL){
		temp=temp->next;
	}
	
	new_node = new Node();
	new_node->user_name=c_uname;
	new_node->id=c_id;
	new_node->bank_name=c_bname;
	new_node->bal=c_bal;
	new_node->block_add=new_node;	
	new_node->loan=c_loan;
	new_node->next=NULL;
	temp->next=new_node;

	cout<<"\nBLOCK SUCCESSFULLY INSERTED";
	display_blockchain_node(new_node);
	}
}
void List :: transact_blockchain(){
	cout<<"\n BLOCKCHAIN TRANSACTION MODE";
	long long int t_id,t_amnt;
	Node *ptr =head;
	Node *new_node;
	int choice;
	int found =0;
	cout<<"\n Enter the id of the Account for which you want to Transact :";
	cin>>t_id;
	while(ptr!=NULL){
		if(ptr->id==t_id){
			found=1;
		if(ptr->bal!=0){
		new_node = new Node();
		cout<<"\n Press 1. to add Money.\n Press 2. to withdraw money\n Any other to Exit";
		cin>>choice;
		if(choice == 1){
			cout<<"\n Enter the ammount you want to add to your balance\n";
			cin>>t_amnt;
			new_node->user_name=ptr->user_name;
			new_node->id=ptr->id;
			new_node->bank_name=ptr->bank_name;
			new_node->bal=t_amnt+ptr->bal;
			ptr->bal=0;
			new_node->loan=ptr->loan;
			ptr->loan=0;
			new_node->block_add=new_node;
			new_node->next=ptr->next;
			ptr->next=new_node;
			break;
		}
		else if(choice==2){
			cout<<"\n Enter the amount you want to withdraw from your balance\n";
			cin>>t_amnt;
			if(t_amnt<ptr->bal){
			new_node->user_name=ptr->user_name;
			new_node->id=ptr->id;
			new_node->bank_name=ptr->bank_name;
			new_node->bal=ptr->bal-t_amnt;
			ptr->bal=0;
			new_node->loan=ptr->loan;
			new_node->block_add=new_node;
			new_node->next=ptr->next;
			ptr->next=new_node;
			break;
		}
		else{
			cout<<"\n Insufficient Balance. Consider Taking a Loan.";
			break;
			}
		}
		else{
			cout<<"\n Exit Transaction Mode";
			break;
			}
		}
	}
		ptr=ptr->next;
	}
	if(found!=1){
		cout<<"\n Invalid Id";
	}
	if(found==1){
		cout<"\nTransaction is succesfull";
	}
}
void List :: insert_Loan(){
	cout<<"\n BLOCKCHAIN LOAN MODE";
	long long int t_id,t_amnt;
	Node *ptr =head;
	Node *new_node;
	int choice;
	int found =0;
	cout<<"\n Enter the id of the Account for which you want to Transact :";
	cin>>t_id;
	while(ptr!=NULL){
		if(ptr->id==t_id && ptr->bal>0){
		found=1;
		new_node = new Node();
			cout<<"\n Enter the amount for which you want to take Loan\n";
			cin>>t_amnt;
			if(ptr->loan>0){
				cout<<"\n LOAN not granted.";
				cout<<"\n Please clear your previous dues.";
			}
			else if(ptr->loan<=0){
			new_node->user_name=ptr->user_name;
			new_node->id=ptr->id;
			new_node->bank_name=ptr->bank_name;
			new_node->bal=ptr->bal;
			ptr->bal=0;
			new_node->loan=t_amnt;
			new_node->block_add=new_node;
			new_node->next=ptr->next;
			ptr->next=new_node;
			break;
			}
		}
		ptr=ptr->next;
		}
	if(found!=1){
		cout<<"\n Invalid Id";
	}
	if(found==1){
		cout<<"\nLoan Granted.";
	}
}

void List :: detect_remove_loop(){
	Node *slow,*fast;
	cout<<"\n Checking the List for Loop Detection";
	slow=head;
	fast=head;
	int found=0;
	while(slow && fast && fast->next){
		slow=slow->next;
		fast=fast->next->next;
		if(slow==fast){
			found=1;
			cout<<"\n LOOP FOUND";
			break;
		}
	}
	slow = head; 
        while (slow->next != fast->next) { 
            slow = slow->next; 
            fast = fast->next; 
        } 
        fast->next=NULL;
        cout<<"\nLOOP REMOVED";
        
    if(found!=1){
    	cout<<"\nLOOP NOT FOUND";
	}
}
int main(){
	
	int choice;
	List obj;
	system("color F0");
	cout<<"\t\t\tWELCOME TO PRIVATE BLOCKCHAIN MONITORED BY THE RESERVE BANK OF INDIA\n";
	
	while(choice!=10){
		cout<<"\n\nPLEASE ENTER THE OPERATION YOU WANT TO PERFORM : ";
		cout<<"\n1. CREATION OF BLOCKCHAIN.";
		cout<<"\n2. DISPLAYING THE THE ACCOUNTS IN THE BLOCKCHAIN.";
		cout<<"\n3. DISPLAYING THE DETAILS OF GENESIS NODE i.e. RBI.";
		cout<<"\n4. INSERTING NEW USER'S ACCOUNT IN THE BLOCKCHAIN.";
		cout<<"\n5.	SEARCHING-DATABASE BY USER NAME OR ID.";
		cout<<"\n6. TRANSACTIONS i.e. DEPOSIT/WITHDRAW PERTAINING TO EXISTING NODES.";
		cout<<"\n7. LOAN GRANTS";
		cout<<"\n8. SET OF USERS ASSOCIATED WITH A PARTICULAR BANK";
		cout<<"\n9. DETECTING WHETHER THERE IS A LOOP IN THE LINKED LIST / OVERLAP IN BLOCKCHAIN";
		cout<<"\n10.EXIT.\n";
		cin>>choice;
		switch(choice){
			case 1 :
				obj.create_blockchain();
				break;
			case 2:
				obj.display_blockchain();
				break;
			case 3 :
				obj.display_blockchain_head();
				break;
			case 4 :
				obj.insert_block();
				break;
			case 5:
				obj.search_blockchain();
				break;
			case 6:
				obj.transact_blockchain();
				break;
			case 7:
				obj.insert_Loan();
				break;
			case 8:
				obj.bank_database();
				break;
			case 9:
				obj.detect_remove_loop();
				break;
			case 10:
				cout<<"\n You have opted for EXIT Operation";
				break;
			default:
				cout<<"\nPLEASE ENTER A VALID OPERATION CHOICE.";
				break;
		}
	}
}
