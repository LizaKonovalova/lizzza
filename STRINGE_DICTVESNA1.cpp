#include <iostream>
using namespace std;
struct node{
  string data;
	 int num;
 	node* next;
};
class string_dict{
	   node* head;
   public:
    string_dict(string a, int b){
     head = new node;
     head -> data = a;
     head -> num = b;
     head -> next = NULL;
    }
    void push(string a, int b){
     node* temp = new node;
     temp -> next = head;
     temp -> data = a;
     temp -> num = b;
     head = temp;
    }
    string pop(int b){
     node* temp = head;
     string a;
     if(temp->next == NULL){
      if(b == temp->num){
       a = temp->data;
       delete temp;
       return a;
      }
      else return "no element";
     }
     while(temp->next->next != NULL){
      if(temp->num == b
    ){
       a = temp->data;
       break;
      }
      else temp = temp->next;
     }
     if(temp->num == b)
      a = temp->data;
     if(temp->next->num == b)
      a = temp->next->data;
     if(a != temp->data && a != temp->next->data)
      return "no element";
     node* temp1 = temp->next;
     temp = temp->next;
     delete temp1;
     return a;
    }
    int find(string a){
     node* temp = head;
     if(temp->next == NULL)
      if(a == temp->data)
       return temp->num;
     while(temp->next->next != NULL){
      if(temp->data == a)
       return temp->num;
      temp = temp->next;
     }
     if(temp->data == a)
      return temp->num;
     if(temp->next->data == a)
      return temp->next->num;
     return -1;
    }
    ~string_dict(){
     while(head != NULL){
      node* temp = head;
      head = head -> next;
      delete temp;
     }
    }
};
int main(){
 int a, b;
 string a1 = "spring";
 string b1 = "so good";
 cin >> a >> b;
 string_dict obj1(a1, a);
 obj1.push(b1, b);
 cout << obj1.find(b1) << endl;
 cout << obj1.pop(a) << endl;
 cout << obj1.pop(b);
 return 0;
}
