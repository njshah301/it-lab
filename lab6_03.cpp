#include <iostream>
using namespace std;
struct node
{
int data;
node *next;
int price;
};
class linked_list
{
private:
node *head,*tail;
public:
linked_list()
{
head = NULL;
tail = NULL;
}
node* gethead()
{
return head;
}
void front(int n,int price)
{
node *tmp = new node;
tmp -> data = n;
tmp->price=price;
tmp -> next = head;
head = tmp;

}
void after(node *a, int value,int price)
{
node* p = new node;
p->data = value;
p->price=price;
p->next = a->next;
a->next = p;
}
void last(int n,int price)
{
node *tmp = new node;
tmp->data = n;
tmp->price=price;
tmp->next = NULL;
if(head == NULL)
{
head = tmp;
tail = tmp;
}
else
{
tail->next = tmp;
tail = tail->next;
}
}
/*void display_loop()
{
node *tmp;
tmp= head;
while (tmp != NULL)
{
cout << tmp->data << endl;
cout<<"  "<<tmp->price<<"\n";
tmp = tmp->next;
}
cout << "NULL\n\n" << endl;
}

*/


/*void ret(int id)
{
int i=0;
node *tmp;
tmp= head;
while (tmp != NULL)
{
if(tmp->data==id){
cout<<tmp->price;
}
else
i++;
tmp = tmp->next;
}
cout << "NULL\n\n" << endl;
if(i==3)
cout<<"not exist";
}
*/
void del_id(int id)
{
node *tmp;
node *curr;
node *prev;

curr=head;

while (tmp != NULL)
{
prev=curr;
curr=curr+1;
if(tmp->data==id){
prev->next=curr->next;
}
else
cout<<tmp->data;
}

}






static void display_rec(node *head)
{
if(head == NULL)
{
cout << "NULL\n\n" << endl;
}
else
{
cout << head->data << endl;
display_rec(head->next);
}
}
void del (node *before_del)
{
node* temp;
temp = before_del->next;
before_del->next =
temp->next;
delete temp;
}
void del_first()
{
if (head)
{
node* temp = head;
head = head->next;
delete temp;
}
}
void del_last()
{
node* prev;
node* curr;
if (head==NULL)
{
// empty list
}
else if (head->next==NULL)
{
curr = head;
head = NULL;
delete curr;
}
else
{
curr = head;
while(curr->next != NULL)
{
prev = curr;
curr = curr->next;
}
prev->next = NULL;
delete curr;
}
}
};
int main()
{
int id;
linked_list a;
cout<<"enter id\n";
cin>>id;
a.last(1,1000);
a.last(2,2000);
a.front(3,3000);

a.del_id(id);
//a.display_loop();
//linked_list::display_rec(a.gethead());
//a.del_last();
//linked_list::display_rec(a.gethead());
//a.del_first();
//a.display_loop();
//linked_list::display_rec();
a.gethead();
//a.del_first();
//linked_list::display_rec(a.gethead());
return 0;
}
