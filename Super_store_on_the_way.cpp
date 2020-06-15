#include<iostream>
#include<sstream>
#include<cstdlib>
#define Size 50
using namespace std;

struct Inventory{
long ProductId;
string name;
float Rate;
long Quantity;
struct Inventory *next;
};
struct Inventory *s[Size]={};



struct Customer{
long CustomerId;
string name;
float points;
struct Customer *next;
};
struct Customer *c[Size]={};



class Security{
    public:
void Update_Stock(){

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
  cout<<"NOT FOUND";
}
else{
cout<<"ProductId"<<"   "<<"Name"<<"   "<<"PRICE"<<"   "<<"Quantity"<<endl;
cout<<t->ProductId<<"   "<<t->name<<"   "<<t->Rate<<"   "<<t->Quantity<<endl;
}
}
};


class Customer_DataSet{
public:
    //Bubble sort for sorting IDs
    void bubbleSort(struct Customer *start[],int count)
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
    string t=a->name;                       //Here, Name should also swapped after sorting the Ids
    a->name=b->name;
    b->name=t;
    float p=a->points;
    a->points=b->points;
    b->points=p;
}
void Insert(long Id,string name,float points){              //Here, Insert function for inserting elements in Hash Table, where ID is a key value

//Implementation has done by linked list called chaining
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
        //cout<<t->name;
        //cout<<"\n";
        break;
    }

    t=t->next;
  }

  if(t==NULL){
        int points=0;
        string name="a";
    Insert(Customer_Id,name,points);
  }
}
Customer* Search_CustomerId(long Id){
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
void Update_Point(long Id,float points){
 struct Customer *c;
 c=Search_CustomerId(Id);
 c->points=points;
}
void Show(long Id){
 struct Customer *c;
 c=Search_CustomerId(Id);
 cout<<c->CustomerId<<" "<<c->points;
}
};



class Billing_Dataset:public Security,public Customer_DataSet{
public:
long customer_Id;
long Item1_Id;
long Quantity1;
long Item2_Id;
long Quantity2;
long Item3_Id;
long Quantity3;

void Customer_Id(long Id){
  customer_Id=Id;
Search_Customer(Id);
}
long Transaction_Id=rand()%100000000000;

void Item1Id(long Id){
Item1_Id=Id;
}
void SetQuan1(long q){
Quantity1=q;
}
void Item2Id(long Id){
Item2_Id=Id;
}
void SetQuan2(long q){
Quantity2=q;
}
void Item3Id(long Id){
Item3_Id=Id;
}
void SetQuan3(long q){
Quantity3=q;
}

void calculate()
{
struct Inventory *t1,*t2,*t3,*n1,*n2,*n3;

t1=Search_item(Item1_Id);
t2=Search_item(Item2_Id);
t3=Search_item(Item3_Id);

n1=t1;
n1->Quantity=Quantity1;
n2=t2;
n2->Quantity=Quantity2;
n3=t3;
n3->Quantity=Quantity3;


cout<<"Product_Id"<<"   "<<"Name"<<"   "<<"Rate"<<"Quantity"<<"Total Rate"<<endl;
cout<<n1->ProductId<<"   "<<n1->name<<"   "<<n1->Rate<<"   "<<n1->Quantity<<"   "<<n1->Rate*n1->Quantity<<endl;
cout<<n2->ProductId<<"   "<<n2->name<<"   "<<n2->Rate<<"   "<<n2->Quantity<<"   "<<n2->Rate*n2->Quantity<<endl;
cout<<n3->ProductId<<"   "<<n3->name<<"   "<<n3->Rate<<"   "<<n3->Quantity<<"   "<<n3->Rate*n3->Quantity<<endl;
}
void make_payment(){


cout<<"Transaction ID:"<<Transaction_Id<<"\n";
cout<<"Customer ID:"<<customer_Id<<"\n\n\n";
struct Inventory *t1,*t2,*t3,*n1,*n2,*n3;

t1=Search_item(Item1_Id);
t2=Search_item(Item2_Id);
t3=Search_item(Item3_Id);

n1=t1;
n1->Quantity=Quantity1;
n2=t2;
n2->Quantity=Quantity2;
n3=t3;
n3->Quantity=Quantity3;

cout<<"Product_Id"<<"   "<<"Name"<<"   "<<"Rate"<<"   "<<"Quantity"<<"   "<<"Total Rate"<<endl<<"\n";
cout<<n1->ProductId<<"   "<<n1->name<<"   "<<n1->Rate<<"   "<<n1->Quantity<<"   "<<n1->Rate*n1->Quantity<<endl;
cout<<n2->ProductId<<"   "<<n2->name<<"   "<<n2->Rate<<"   "<<n2->Quantity<<"   "<<n2->Rate*n2->Quantity<<endl;
cout<<n3->ProductId<<"   "<<n3->name<<"   "<<n3->Rate<<"   "<<n3->Quantity<<"   "<<n3->Rate*n3->Quantity<<endl<<"\n\n";
cout<<"TOTAL="<<n1->Rate*n1->Quantity+n2->Rate*n2->Quantity+n3->Rate*n3->Quantity<<"\n";
Update_Point(customer_Id,n1->Rate*n1->Quantity+n2->Rate*n2->Quantity+n3->Rate*n3->Quantity);
}

};




class Inventory_Dataset:public Security{
    public:

    //Bubble sort for sorting IDs
    void bubbleSort(struct Inventory *start[],int count)
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
    string t=a->name;                       //Here, Name should also swapped after sorting the Ids
    a->name=b->name;
    b->name=t;
    float r=a->Rate;
    a->Rate=b->Rate;
    b->Rate=r;
    long q=a->Quantity;
    a->Quantity=b->Quantity;
    b->Quantity=q;
}

void Add_item(long Id,string name,float rate,long Quantity){              //Here, Insert function for inserting elements in Hash Table, where ID is a key value

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


void Update_item_Rate(long Id){
struct Inventory *t;
t=Search(Id);
cout<<"How many Rate do you want for this Product?\n";
float rate;
cin>>rate;
t->Rate=rate;
}
void Update_item_Quantity(long Id){
struct Inventory *t;
t=Search(Id);
cout<<"How many Quantity do you want to increase?\n";
float Quantity;
cin>>Quantity;
t->Quantity=t->Quantity+Quantity;
}


};
class Manager_Dataset:public Inventory_Dataset{


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
stringstream ss;              //Here, I have used stringstream for convert long to string
ss<<CUSTOMER_DATASET[k][l+1];
string str;
ss>>str;
t.Insert(CUSTOMER_DATASET[k][l],str,CUSTOMER_DATASET[k][l+2]);    //For insert values in function
}

Billing_Dataset nj;
nj.Customer_Id(9400000001);

nj.Item1Id(111100000001);
nj.SetQuan1(3);
nj.Item2Id(222200001114);
nj.SetQuan2(1);
nj.Item3Id(222200001234);
nj.SetQuan3(2);

nj.make_payment();

return 0;
}
