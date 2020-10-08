#include <iostream>
using namespace std;

struct node
{
  public:
  node(int indata):
  data(indata)
  {
    data = indata;
    left = right = nullptr;
  };
  int data;
  struct node* left;
  struct node* right;
};

struct node* createnewnode(int data)
{

  struct node* temp = new node(data);
  return temp;
};

struct node * head = nullptr;

struct node* insertnode(struct node *h,int data)
{
  
   if(h == nullptr)
   {     struct node* n = createnewnode(data);
     return n;
   }
   else if(h->data > data)
   {
     h->left = insertnode(h->left,data);
     return h;
   }
   else 
   {
      h->right = insertnode(h->right,data);
      return h;
   }
};

struct node* inordsucc(struct node *inod)
{
    while(inod->left != nullptr)
    {
      inod = inod->left;
    }
    return inod;
};

struct node* deletenode(struct node* dn,int data)
{

   if ( dn->data < data)
   {
      dn->right = deletenode(dn->right, data);
      return dn;
   }
   else if(dn->data > data)
   {
     dn->left = deletenode(dn->left, data);
     return dn;
   }
   else if(dn->data == data)
   {

   if(dn->left == nullptr && dn->right == nullptr)
   {
       dn = nullptr;
       return dn;
   }
   else if(dn->left ==nullptr && dn->right!=nullptr)
   {
      return dn->right;
   }
   else if(dn->left !=nullptr && dn->right==nullptr)
   {
     return dn->left;
   }
   else 
   {
      struct node* ins = inordsucc(dn);
      dn->data = ins->data;
      dn->left = deletenode(ins,ins->data);
      return dn;
   }
   }

};

void printinorder(struct node* he)
{
  if(he!=nullptr)
  {
    std::cout<<"data is "<< he->data << "\n";
    printinorder(he->left);  
    printinorder(he->right);
  }
}


int main() {

   head = insertnode(head,4);
   head = insertnode(head,6);
   head = insertnode(head,2);
   head = insertnode(head,5);
   head = insertnode(head,9); 
   printinorder(head);

   head=deletenode(head,6);
   std::cout<<"after "<<std::endl;
   printinorder(head);


  
}
