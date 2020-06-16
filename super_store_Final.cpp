/*
 ======================================================================|
                          |=    Programmer Name: Nilay Shah           =|
                          |=     Id:201901026                         =|
                          |=     Program: Final Assignment-SuperStore =|
  =====================================================================|
 */

/*
Here, In this application there are main four objects:  [1]Inventory_Dataset
                                                        [2]Billing_Dataset
                                                        [3]Manager_Dataset
                                                        [4]Customer_Dataset
I have implemented an extra object named Security which is used for access by Billing_Dataset.
*/

#include<iostream>
#include<sstream>
#include<cstdlib>
#include <iomanip>
#define Size 50
using namespace std;

//I have used 3 structure for Customer,billing and Inventory.Also, because Item & customer Dataset is bigger I have implemented "Hashing by Chaining" for search and update operations.

struct Inventory{
long ProductId;
string name;
float Rate;
long Quantity;
struct Inventory *next;
};
struct Inventory *s[Size]={};

struct node{
    long Id;
    long Quantity;
    string name;
    float rate;
    struct node *next;

    struct node *prev;
};
struct node *head=NULL;
struct node *tail=NULL;



struct Customer{
long CustomerId;
string name;
float points;
struct Customer *next;
};
struct Customer *c[Size]={};

//Here,Security object is very important for access of Billing object to this object. Because Billing object can only update stock and get product information.
//Manager object can access all function of an Inventory object so this object is very important in that way.


class Security{
    public:
void Update_Stock(long Id,long Quan){
struct Inventory *t;
t=Search_item(Id);
t->Quantity=(t->Quantity)-(Quan);
}

Inventory* Search_item(long Id){
  int count=Id%Size;

  struct  Inventory *t=s[count];
  while(t!=NULL){
    if(t->ProductId==Id){
     return t;
        break;
    }
    t=t->next;
  }
  if(t==NULL){
    return NULL;
  }
return NULL;
}

void Get_Product_Info(long Id){
struct Inventory *t;
t=Search_item(Id);
if(t==NULL){
  cout<<"NOT FOUND\n";
}
else{
cout<<"ProductId"<<setw(15)<<"Name"<<setw(15)<<"PRICE"<<setw(15)<<"Quantity"<<endl;
cout<<setw(10)<<t->ProductId<<setw(11)<<t->name<<setw(15)<<t->Rate<<setw(13)<<t->Quantity<<endl;
}
}
};

/*
Customer object is accessible from billing object.
Customer information upload by billing object.

*/

class Customer_DataSet{
public:
    //Bubble sort for sorting IDs
    void bubbleSort(struct Customer *start[],int count)                               //for speedy search
{
    int swapped;
    struct Customer *ptr1;
    struct Customer *lptr = NULL;

    /* Checking for empty list */
    if (start[count] == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = start[count];

        while (ptr1->next != lptr)
        {
            if (ptr1->CustomerId > ptr1->next->CustomerId)
            {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}

/* function to swap data of two nodes a and b*/
void swap(struct Customer *a, struct Customer *b)
{
    int temp = a->CustomerId;
    a->CustomerId = b->CustomerId;
    b->CustomerId = temp;
    string t=a->name;           //Here, Name should also swapped after sorting the Ids
    a->name=b->name;
    b->name=t;
    float p=a->points;
    a->points=b->points;
    b->points=p;
}
void Insert(long Id,string name,float points){              //Here, Insert function for inserting elements in Hash Table, where ID is a key value

//Implementation has been done by linked list called chaining
    int count=Id%Size;
    struct Customer *temp;
    temp=new Customer;
    temp->CustomerId=Id;
    temp->name=name;
    temp->points=points;
    if(c[count]==NULL){
        c[count]=temp;
        c[count]->CustomerId=Id;
        c[count]->name=name;
        c[count]->points=points;
        c[count]->next=NULL;
    }
    else{
        struct Customer *t;
        t=c[count];
        while(t->next!=NULL){
            t=t->next;
            }
            t->next=temp;
            temp->next=NULL;
    }

    int n=0;
    struct Customer *r=c[count];
    while(r!=NULL){
        r=r->next;
        n++;
    }
bubbleSort(c,count);                    //for sort IDs
}
void Search_Customer(long Customer_Id){
  int count=Customer_Id%Size;

  struct Customer *t=c[count];
  while(t!=NULL){
    if(t->CustomerId==Customer_Id){
        break;
    }
    t=t->next;
  }
  if(t==NULL){           //If there is new customer;add has been done by this condition.
        int points=0;
        string name="a";
    Insert(Customer_Id,name,points);
  }
}
Customer* Search_CustomerId(long Id){        //Here, Customer Id's pointer is returned.
  int count=Id%Size;
  struct  Customer *t=c[count];
  while(t!=NULL){
    if(t->CustomerId==Id){
     return t;
        break;
    }
    t=t->next;
  }
  if(t==NULL){
    return NULL;
  }
return NULL;
}
void Update_Point(long Id,float points){            //point is updated by this function.
 struct Customer *c;
 c=Search_CustomerId(Id);
 c->points=points;
}
void Show(long Id){         //You can show this updated points by calling this function.
 struct Customer *c;
 c=Search_CustomerId(Id);
 cout<<"Customer_Id"<<setw(10)<<"Name"<<setw(10)<<"Points"<<"\n";
 cout<<c->CustomerId<<setw(10)<<c->name<<setw(10)<<c->points<<"\n";
}
};

//Here,this is a main object Billing_Dataset.In this object customer can Buy an item and cancel an item from it list.
//Also, make_payment function will print the bill.
//Also, new customer will be add on customer dataset by this object.

class Billing_Dataset:public Security,public Customer_DataSet{
long customer_Id;
public:
    void Customer_Id(long Id){
  customer_Id=Id;
Search_Customer(Id);
}
long Transaction_Id=rand()%100000000000;          //Here,Transaction Id is randomly generated of 12 digits.

void Add_item(long Id,long Quantity){           //Item has been add by linked list data structure.
struct node *temp;
temp=new node;
temp->Quantity=Quantity;
temp->Id=Id;
struct Inventory *t;
t=Search_item(Id);
temp->name=t->name;
temp->rate=t->Rate;
tail=temp;
if(head==NULL){
    head=temp;
    tail=head;
    tail->next=NULL;
    temp->prev=NULL;
    head->prev=NULL;
}
else
{
    struct node *x;
    x=head;
    while((x->next)!=NULL){
        x=x->next;
    }

    x->next=temp;
    temp->prev=x;
    tail=temp;
    temp->next=NULL;
}
}
void Buy_item(long Id,long Quantity){
Add_item(Id,Quantity);
}
void Cancel_item(long Id){
    struct node *temp;
    temp=new node;

temp=head;

while(temp!=NULL){
    if(temp->Id==Id && temp==head){
            head=temp->next;
            break;
    }
 if(temp->Id==Id && temp==tail){
        struct node *p;

 p=head;
 while(p->next!=tail){
    p=p->next;
 }
 p->next=NULL;
 tail=p;
 break;
 }
if((temp->Id==Id && (temp!=head && temp!=tail))){
        struct node *rj;

rj=head;
while(rj->Id!=Id){
    rj=rj->next;
}
       struct node *mj;
       mj=new node;
       mj=head;
while((mj->next)!=rj){
    mj=mj->next;
    break;
}
mj->next=rj->next;
rj->next=NULL;
}
    temp=temp->next;

}
}

//By this function bill is printed.
void make_payment(){
cout<<"**************************************************************\n";
cout<<"                         |BILL|\n";
cout<<"Transaction ID:"<<Transaction_Id<<"\n";
cout<<"   Customer ID:"<<customer_Id<<"\n";
struct node *p;
p=head;


cout<<"--------------------------------------------------------------\n";
cout<<"Product_Id"<<setw(10)<<"Name"<<setw(13)<<"Rate"<<setw(13)<<"Quantity"<<setw(13)<<"Total Rate"<<endl;
cout<<"--------------------------------------------------------------\n";
float total=0;
while(p!=NULL){
cout<<p->Id<<setw(7)<<p->name<<setw(13)<<p->rate<<setw(10)<<p->Quantity<<setw(13)<<p->rate*p->Quantity<<endl;
total=total+p->rate*p->Quantity;


Update_Stock(p->Id,p->Quantity);
p=p->next;
}
Update_Point(customer_Id,total);
cout<<setw(57)<<"TOTAL="<<total<<"\n";
cout<<"**************************************************************\n";
}

};
//Inventory has been add or delete or update by manager object.

class Inventory_Dataset:public Security{
    public:

    //Bubble sort for sorting IDs
    void bubbleSort(struct Inventory *start[],int count) //I used it for speedy search.
{
    int swapped;
    struct Inventory *ptr1;
    struct Inventory *lptr = NULL;

    /* Checking for empty list */
    if (start[count] == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = start[count];

        while (ptr1->next != lptr)
        {
            if (ptr1->ProductId > ptr1->next->ProductId)
            {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}

/* function to swap data of two nodes a and b*/
void swap(struct Inventory *a, struct Inventory *b)
{
    long temp = a->ProductId;
    a->ProductId = b->ProductId;
    b->ProductId = temp;
    string t=a->name;   //Here, Name should also swapped after sorting the Ids
    a->name=b->name;
    b->name=t;
    float r=a->Rate;
    a->Rate=b->Rate;
    b->Rate=r;
    long q=a->Quantity;
    a->Quantity=b->Quantity;
    b->Quantity=q;
}

void Add_item(long Id,string name,float rate,long Quantity){  //Here, Insert function for inserting elements in Hash Table, where ID is a key value

//Implementation has done by linked list called chaining
    int count=Id%Size;
    struct Inventory *temp;
    temp=new Inventory;
    temp->ProductId=Id;
    temp->name=name;
    temp->Rate=rate;
    temp->Quantity=Quantity;
    if(s[count]==NULL){
        s[count]=temp;
        s[count]->ProductId=Id;
        s[count]->name=name;
        s[count]->Rate=rate;
        s[count]->Quantity=Quantity;
        s[count]->next=NULL;
    }
    else{
        struct Inventory *t;
        t=s[count];
        while(t->next!=NULL){
            t=t->next;
            }
            t->next=temp;
            temp->next=NULL;

    }

    int n=0;
    struct Inventory *r=s[count];
    while(r!=NULL){
        r=r->next;
        n++;
    }
bubbleSort(s,count);                    //for sort IDs
}

//manager can delete and item from inventory by this delete function.

void Delete(long Id){
    int count=Id%Size;
    struct Inventory *temp;
    temp=new Inventory;

temp=s[count];
struct Inventory *tail;
tail=s[count];
while(tail->next!=NULL){
    tail=tail->next;
}


while(temp!=NULL){
    if(temp->ProductId==Id && temp==s[count]){
            s[count]=temp->next;
            break;
    }
 if(temp->ProductId==Id && temp==tail){
        struct Inventory *p;

 p=s[count];
 while(p->next!=tail){
    p=p->next;
 }
 p->next=NULL;
 tail=p;
 break;
 }
if((temp->ProductId==Id && (temp!=s[count] && temp!=tail))){
        struct Inventory *rj;

rj=s[count];
while(rj->ProductId!=Id){
    rj=rj->next;
}
       struct Inventory *mj;
       mj=new Inventory;
       mj=s[count];
while((mj->next)!=rj){
    mj=mj->next;
    break;
}
mj->next=rj->next;
rj->next=NULL;
}
    temp=temp->next;
}
}

Inventory* Search(long Id){
  int count=Id%Size;

  struct  Inventory *t=s[count];
  while(t!=NULL){
    if(t->ProductId==Id){
     return t;
        break;
    }
    t=t->next;
  }

}

};

//Manager object can upload & update the inventory data.
//Also ,manager object can retrieve any information about item and can make any changes to the inventory.
//Also,manager can add or  delete the product from inventory and can make changes in the rate and quantity of product by upload_item.

class Manager_Dataset:public Inventory_Dataset{

void Update_item_Rate(long Id){          //If manager needs to update item_rate then it is used.
struct Inventory *t;
t=Search(Id);
cout<<"How many Rate do you want for this Product?\n";
float rate;
cin>>rate;
t->Rate=rate;
}
void Update_item_Quantity(long Id){  //If manager needs to update item_Quantity then it is used.
struct Inventory *t;
t=Search(Id);
cout<<"How many Quantity do you want to increase?\n";
float Quantity;
cin>>Quantity;
t->Quantity=t->Quantity+Quantity;
}

};


int main(){

long INVENTORY_DATASET[100][4] = {
{111100000001,1,100,20},{111100000002,2,110,20},{111100000003,3,120,20},{111100000004,4,130,20},{111100000005,5,140,20},{111100000006,6,150,20},{111100000007,7,160,20},{111100000008,8,170,20},{111100000009,9,180,20},{111100000010,10,190,20},
{111100000011,11,200,20},{111100000012,12,210,20},{111100000013,13,220,20},{111100000014,14,230,20},{111100000015,15,240,20},{111100000016,16,250,20},{111100000017,17,260,20},{111100000018,18,270,20},{111100000019,19,280,20},{111100000020,20,290,20},
{111100000021,21,300,20},{111100000022,22,310,20},{111100000023,23,320,20},{111100000024,24,330,20},{111100000025,25,340,20},{111100000026,26,350,20},{111100000027,27,360,20},{111100000028,28,370,20},{111100000029,29,380,20},{111100000030,30,390,20},
{111100000031,31,400,20},{111100000032,32,410,20},{111100000033,33,420,20},{111100000034,34,430,20},{111100000035,35,440,20},{111100000036,36,450,20},{111100000037,37,460,20},{111100000038,38,470,20},{111100000039,39,480,20},{111100000040,40,490,20},
{111100000041,41,500,20},{111100000042,42,510,20},{111100000043,43,520,20},{111100000044,44,530,20},{111100000045,45,540,20},{111100000046,46,550,20},{111100000047,47,560,20},{111100000048,48,570,20},{111100000049,49,580,20},{222200001111,50,590,20},
{222200001114,51,600,20},{222200001117,52,610,20},{222200001120,53,620,20},{222200001123,54,630,20},{222200001126,55,640,20},{222200001129,56,650,20},{222200001132,57,660,20},{222200001135,58,670,20},{222200001138,59,680,20},{222200001141,60,690,20},
{222200001144,61,700,20},{222200001147,62,710,20},{222200001150,63,720,20},{222200001153,64,730,20},{222200001156,65,740,20},{222200001159,66,750,20},{222200001162,67,760,20},{222200001165,68,770,20},{222200001168,69,780,20},{222200001171,70,790,20},
{222200001174,71,800,20},{222200001177,72,810,20},{222200001180,73,820,20},{222200001183,74,830,20},{222200001186,75,840,20},{222200001189,76,850,20},{222200001192,77,860,20},{222200001195,78,870,20},{222200001198,79,880,20},{222200001201,80,890,20},
{222200001204,81,900,20},{222200001207,82,910,20},{222200001210,83,920,20},{222200001213,84,930,20},{222200001216,85,940,20},{222200001219,86,950,20},{222200001222,87,960,20},{222200001225,88,970,20},{222200001228,89,980,20},{222200001231,90,990,20},
{222200001234,91,1000,20},{222200001237,92,1010,20},{222200001240,93,1020,20},{222200001243,94,1030,20},{222200001246,95,1040,20},{222200001249,96,1050,20},{222200001252,97,1060,20},{222200001255,98,1070,20},{222200001258,99,1080,20},{222200001261,100,1090,20},
};
int i,j=0;
Manager_Dataset t1;
for(i=0;i<100;i++){
stringstream ss;              //Here, I have used stringstream for convert long to string
ss<<INVENTORY_DATASET[i][j+1];
string str;
float rate=INVENTORY_DATASET[i][j+2];
long Quantity=INVENTORY_DATASET[i][j+3];
ss>>str;
t1.Add_item(INVENTORY_DATASET[i][j],str,rate,Quantity);    //For insert values in function
}

long CUSTOMER_DATASET[100][3] = {
{9400000001,1,0},{9400000002,2,0},{9400000003,3,0},{9400000004,4,0},{9400000005,5,0},{9400000006,6,0},{9400000007,7,0},{9400000008,8,0},{9400000009,9,0},{9400000010,10,0},
{9400000011,11,0},{9400000012,12,0},{9400000013,13,0},{9400000014,14,0},{9400000015,15,0},{9400000016,16,0},{9400000017,17,0},{9400000018,18,0},{9400000019,19,0},{9400000020,20,0},
{9400000021,21,0},{9400000022,22,0},{9400000023,23,0},{9400000024,24,0},{9400000025,25,0},{9400000026,26,0},{9400000027,27,0},{9400000028,28,0},{9400000029,29,0},{9400000030,30,0},
{9400000031,31,0},{9400000032,32,0},{9400000033,33,0},{9400000034,34,0},{9400000035,35,0},{9400000036,36,0},{9400000037,37,0},{9400000038,38,0},{9400000039,39,0},{9400000040,40,0},
{9400000041,41,0},{9400000042,42,0},{9400000043,43,0},{9400000044,44,0},{9400000045,45,0},{9400000046,46,0},{9400000047,47,0},{9400000048,48,0},{9400000049,49,0},{9400000050,50,0},
{9400000051,51,0},{9400000052,52,0},{9400000053,53,0},{9400000054,54,0},{9400000055,55,0},{9400000056,56,0},{9400000057,57,0},{9400000058,58,0},{9400000059,59,0},{9400000060,60,0},
{9400000061,61,0},{9400000062,62,0},{9400000063,63,0},{9400000064,64,0},{9400000065,65,0},{9400000066,66,0},{9400000067,67,0},{9400000068,68,0},{9400000069,69,0},{9400000070,70,0},
{9400000071,71,0},{9400000072,72,0},{9400000073,73,0},{9400000074,74,0},{9400000075,75,0},{9400000076,76,0},{9400000077,77,0},{9400000078,78,0},{9400000079,79,0},{9400000080,80,0},
{9400000081,81,0},{9400000082,82,0},{9400000083,83,0},{9400000084,84,0},{9400000085,85,0},{9400000086,86,0},{9400000087,87,0},{9400000088,88,0},{9400000089,89,0},{9400000090,90,0},
{9400000091,91,0},{9400000092,92,0},{9400000093,93,0},{9400000094,94,0},{9400000095,95,0},{9400000096,96,0},{9400000097,97,0},{9400000098,98,0},{9400000099,99,0},{9400000100,100,0}
};
int k,l=0;
Billing_Dataset t;
for(k=0;k<100;k++){
stringstream ss;  //Here, I have used stringstream for convert long to string
ss<<CUSTOMER_DATASET[k][l+1];
string str;
ss>>str;
t.Insert(CUSTOMER_DATASET[k][l],str,CUSTOMER_DATASET[k][l+2]);    //For insert values in function
}

Billing_Dataset nj;
nj.Customer_Id(9400000001);

nj.Add_item(111100000001,3);//item1,quantity
nj.Add_item(222200001114,1);//item2,quantity
nj.Add_item(222200001234,2); //item3,quantity

//If customer need to buy another item than  //nj.Buy_item(222200001198,2);//
//If customer need to cancel any item than //nj.Cancel_item(222200001198);//


nj.make_payment();   //This will print the bill.
Manager_Dataset kj;
//Here,we can confirm that inventory (quantity) is update after customer shopping episode
//If manager needs to delete any item than use //kj.Delete(111100000001);//

kj.Get_Product_Info(111100000001);
kj.Get_Product_Info(222200001114);
kj.Get_Product_Info(222200001234);

//If need other info  //kj.Get_Product_Info(222200001198);//
//If you need to show the situation after shopping episode i.e. customer point than //nj.Show(9400000001);//

//If manager need to update stock rate or update stock quantity than use //update_item_Rate(Id)// and //update_item_Quantity(Id)//

return 0;
}