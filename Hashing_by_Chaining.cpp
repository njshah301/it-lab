/*
 ======================================================================|
                          |=    Programmer Name: Nilay Shah           =|
                          |=     Id:201901026                         =|
                          |=     Program: Hashing by Chaining         =|

  =====================================================================|

                                         */

#include<iostream>
#include<sstream>
#define Size 13                         //I have defined size=13 as Hash Table size
using namespace std;
struct Student{
long StudentId;
string name;
struct Student *next;
};
struct Student *s[Size]={};

class Hash{
public:
    //Bubble sort for sorting IDs
    void bubbleSort(struct Student *start[],int count)
{
    int swapped,i;
    struct Student *ptr1;
    struct Student *lptr = NULL;

    /* Checking for empty list */
    if (start[count] == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = start[count];

        while (ptr1->next != lptr)
        {
            if (ptr1->StudentId > ptr1->next->StudentId)
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
void swap(struct Student *a, struct Student *b)
{
    int temp = a->StudentId;
    a->StudentId = b->StudentId;
    b->StudentId = temp;
    string t=a->name;                       //Here, Name should also swapped after sorting the Ids
    a->name=b->name;
    b->name=t;
}
void Insert(long Id,string name){              //Here, Insert function for inserting elements in Hash Table, where ID is a key value

//Implementation has done by linked list called chaining
    int count=Id%Size;
    struct Student *temp;
    temp=new Student;
    temp->StudentId=Id;
    temp->name=name;
    if(s[count]==NULL){
        s[count]=temp;
        s[count]->StudentId=Id;
        s[count]->name=name;
        s[count]->next=NULL;
    }
    else{
        struct Student *t;
        t=s[count];
        while(t->next!=NULL){
            t=t->next;
            }
            t->next=temp;
            temp->next=NULL;

    }

    int n=0;
    struct Student *r=s[count];
    while(r!=NULL){
        r=r->next;
        n++;
    }
bubbleSort(s,count);                    //for sort IDs
}
void Search(int Id){
  int count=Id%Size;

  struct  Student *t=s[count];
;  while(t!=NULL){
    if(t->StudentId==Id){
        cout<<t->name;
        cout<<"\n";
        break;
    }

    t=t->next;
  }

  if(t==NULL){
    cout<<"Not Found\n";
  }
}



}t1,t2,t3;
int main(){
    int i,j=0;

long HASH_DATASET[100][2] = {
{201600001,1},{201600002,2},{201600003,3},{201600004,4},{201600005,5},{201600006,6},{201600007,7},{201600008,8},{201600009,9},{201600010,10},
{201600011,11},{201600012,12},{201600013,13},{201600014,14},{201600015,15},{201600016,16},{201600017,17},{201600018,18},{201600019,19},{201600020,20},
{201600021,21},{201600022,22},{201600023,23},{201600024,24},{201600025,25},{201700113,26},{201700117,27},{201700121,28},{201700125,29},{201700129,30},
{201700133,31},{201700137,32},{201700141,33},{201700145,34},{201700149,35},{201700153,36},{201700157,37},{201700161,38},{201700165,39},{201700169,40},
{201700173,41},{201700177,42},{201700181,43},{201700185,44},{201700189,45},{201700193,46},{201700197,47},{201700201,48},{201700205,49},{201700209,50},
{201911001,51},{201911005,52},{201911009,53},{201911013,54},{201911017,55},{201911021,56},{201911025,57},{201911029,58},{201911033,59},{201911037,60},
{201911041,61},{201911045,62},{201911049,63},{201911053,64},{201911057,65},{201911061,66},{201911065,67},{201911069,68},{201911073,69},{201911077,70},
{201911081,71},{201911085,72},{201911089,73},{201911093,74},{201911097,75},{201911101,76},{201911105,77},{201911109,78},{201911113,79},{201911117,80},
{201911121,81},{201911125,82},{201911129,83},{201911133,84},{201911137,85},{201911141,86},{201911145,87},{201911149,88},{201911153,89},{201911157,90},
{201911161,91},{201911165,92},{201911169,93},{201911173,94},{201911177,95},{201911181,96},{201911185,97},{201911189,98},{201911193,99},{201911197,100},
};

for(i=0;i<100;i++){
stringstream ss;              //Here, I have used stringstream for convert long to string
ss<<HASH_DATASET[i][j+1];
string str;
ss>>str;
t1.Insert(HASH_DATASET[i][j],str);    //For insert values in function
}
// given in test case
t1.Search(201600021);
t1.Search(201911165);
t1.Search(201911197);
return 0;
}
