// Write a program to add two polynomials using linked lists.

#include<iostream>
using namespace std;

class Polynomial_node{
    public:
    int coff;
    int deg;
    Polynomial_node* next;
    Polynomial_node(int coff, int deg){
        this->coff=coff;
        this->deg=deg;
        next=NULL;
    }
};

//take_input()
Polynomial_node* making_polynomial(){
    cout<<"Enter degree of the polynomial: "<<endl;
    int degree;
    cin>>degree;
    cout<<"Enter coff of highest degree: "<<endl;
    int coff;
    cin>>coff;
    Polynomial_node* term = new Polynomial_node(coff,degree);
    Polynomial_node* temp = term;
    int i = degree-1;
    while(i != -1){
        cout<<"Enter the coff of term with power "<<i<<endl;
        int coff;
        cin>>coff;
        Polynomial_node* next_term = new Polynomial_node(coff,i);
        temp->next=next_term;
        temp=temp->next;
        i--;
    }
    return term;
}

//printing
void printing_polynomial(Polynomial_node* term){
    while(term->next!=NULL){
        cout<<term->coff<<"x^"<<term->deg<<"+";
        term=term->next;
    }
    cout<<term->coff;
}

Polynomial_node* adding_polynomials(Polynomial_node* term1, Polynomial_node* term2){
    int deg1 = term1->deg;
    int deg2 = term2->deg;

    Polynomial_node* new_term;
    Polynomial_node* temp1;

    if(deg1>deg2){
        int cnt = 0;
        new_term = new Polynomial_node(term1->coff,term1->deg);
        temp1=new_term;
        while (cnt!=deg1-deg2-1)
        {
            term1=term1->next;
            Polynomial_node* new_term2 = new Polynomial_node(term1->coff,term1->deg);
            temp1->next=new_term2;
            temp1=temp1->next;
            cnt++;
        }
        term1=term1->next;
        while (term1!=NULL)
    {
        int coff = term1->coff + term2->coff;
        int degree = term1->deg;
        Polynomial_node* new_term3=new Polynomial_node(coff,degree);
        temp1->next=new_term3;
        term1=term1->next;     
        term2=term2->next;
        temp1=temp1->next;
    }
    }

    if(deg2>deg1){
        int cnt = 0;
        new_term = new Polynomial_node(term2->coff,term2->deg);
        while (cnt!=deg2-deg1-1)
        {
            term2=term2->next;
            Polynomial_node* new_term2 = new Polynomial_node(term2->coff,term2->deg);
            temp1->next=new_term2;
            temp1=temp1->next;
            cnt++;
        }
        term2=term2->next;
        while (term1!=NULL)
    {
        int coff = term1->coff + term2->coff;
        int degree = term1->deg;
        Polynomial_node* new_term3=new Polynomial_node(coff,degree);
        temp1->next=new_term3;
        term1=term1->next;     
        term2=term2->next;
        temp1=temp1->next;
    }
    }
    

    if(deg1==deg2){
        new_term=new Polynomial_node(term1->coff+term2->coff,term1->deg);
        Polynomial_node* temp2 = new_term;
        while(term1->next!=NULL){
            Polynomial_node* a = new Polynomial_node(term1->next->coff+term2->next->coff, term1->next->deg);
            temp2->next=a;
        temp2=temp2->next;
        term1=term1->next;
        term2=term2->next;
    }
    }

    return new_term;
}

int main(){
    Polynomial_node* term1 = making_polynomial();
    printing_polynomial(term1);
    cout<<endl;
    Polynomial_node* term2 = making_polynomial();
    printing_polynomial(term2);
    cout<<endl;
    Polynomial_node*final=adding_polynomials(term1,term2);
    printing_polynomial(final);
    return 0;
}
