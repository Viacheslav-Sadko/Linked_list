#include <iostream>
#include <string>
#include <iomanip> 
using namespace std;
struct student_marks{
    int math;
    int IT;
    int PE;
    int english;
    int biology;
    int average;

};
struct student{
    string name;
    int year;
    int course;
    string group;
    int number_student_book;
    student_marks mark;
    student *next;
};
//functions
    void linked_list_add(student*& linked_list, string name,int year,int course,string group, int number_student_book, int math, int english, int PE, int IT, int biology){
        student* p = new student;
        p->name  = name;
        p->year  = year;
        p->course  = course;
        p->group  = group;
        p->number_student_book = number_student_book;
        p->mark.math  = math;
        p->mark.english = english;
        p->mark.PE  = PE;
        p->mark.IT = IT;
        p->mark.biology = biology;
        p->next  = linked_list;
        linked_list = p;
    }
    void node_print(const student* linked_list){ 
            cout<<linked_list->name
            <<"\t"<<"\t"<<linked_list->year
            <<"\t"<<linked_list->course<<"\t"
            <<linked_list->group
            <<"\t"<<linked_list->number_student_book
            <<"\t"<<linked_list->mark.math
            <<"\t"<<linked_list->mark.english
            <<"\t"<<linked_list->mark.PE<<"\t"
            <<linked_list->mark.IT
            <<"\t"<<linked_list->mark.biology<<endl;
    } 
    void linked_list_print(const student* linked_list){ 
        cout<<setw(70)<<"Оцінки"<<endl;
        cout<<"Ім'я"<<setw(25)<<"Рік н-ння"<<setw(9)<<"Курс"<<setw(15)<<"Група"<<setw(12)<<"№ з.к."<<setw(20)<<"Математика-Англійська-Ф.В.-Інформатика-Біологія"<<endl;
        for(; linked_list != NULL; linked_list = linked_list->next)
            cout<<linked_list->name
            <<"\t"<<"\t"<<linked_list->year
            <<"\t"<<linked_list->course<<"\t"
            <<linked_list->group
            <<"\t"<<linked_list->number_student_book
            <<"\t"<<linked_list->mark.math
            <<"\t"<<linked_list->mark.english
            <<"\t"<<linked_list->mark.PE<<"\t"
            <<linked_list->mark.IT
            <<"\t"<<linked_list->mark.biology<<endl;
    }  
    void linked_list_sort(student*& linked_list, bool (*comprassion)(const student&, const student&)){ //сортуваня вставками
        student *a, *b, *p, *h = NULL;
        for(student* i = linked_list; i != NULL; ) {
            a = i;
            i = i->next;
            b = h;
            for(p = NULL; (b != NULL) && (*comprassion)(*b, *a); ) {
                p = b;
                b = b->next;
            }
    
            if(p == NULL){
                a->next = h;
                h       = a;
            } else {
                a->next = b;
                p->next = a;
            }
        }
        if(h != NULL)
            linked_list = h;    
        linked_list_print(linked_list);
        cout<<endl;
    }
    void linked_list_clear(student*& linked_list){
        student* p;
        while(linked_list != NULL){
            p   = linked_list;
            linked_list = linked_list->next;
            delete p;
        }
        linked_list_print(linked_list);
    }
    int linked_list_extract(string group){
        return group[3] - 48; 
    }
    int linked_list_extract_name(string name){
        return name[0]; 
    }
    void linked_list_sort_string(student*& linked_list, bool (*comprassion)(int& ,int& ,const student&, const student&)){ //сортуваня вставками
        student *a, *b, *p, *h = NULL;
        int c,d;
        for(student* i = linked_list; i != NULL; ) {
            a = i;
            i = i->next;
            b = h;
            for(p = NULL; (b != NULL) && (*comprassion)(c,d,*b, *a); ) {
                p = b;
                b = b->next;
            }
    
            if(p == NULL){
                a->next = h;
                h       = a;
            } else {
                a->next = b;
                p->next = a;
            }
        }
        if(h != NULL)
            linked_list = h;    
        linked_list_print(linked_list);
        cout<<endl;
    }
    void linked_list_add_to_other_list(student*& linked_list, student*& linked_list_2){ 
        student* p = new student(); 
        p->name  = linked_list->name;
        p->year  = linked_list->year;
        p->course  = linked_list->course;
        p->group  = linked_list->group;
        p->number_student_book = linked_list->number_student_book;
        p->mark.math  = linked_list->mark.math;
        p->mark.english = linked_list->mark.english;
        p->mark.PE  = linked_list->mark.PE;
        p->mark.IT = linked_list->mark.IT;
        p->mark.biology = linked_list->mark.biology;
        p->next = linked_list_2;
        linked_list_2 = p;
    }
    void linked_list_average_counting(student* linked_list){ 
        for (student* j = linked_list; j != NULL; j = j->next){  
            j->mark.average =(j->mark.math+j->mark.english+j->mark.IT+j->mark.biology+j->mark.PE)/5;
        }
    }
    void linked_list_delete_by_position(student*& linked_list, int position){
        student*current=new student;
        student *previous=new student;
            current=linked_list;
            for(int i=1;i<position;i++)
            {
            previous=current;
            current=current->next;
            }
            previous->next=current->next;
        }
    student* linked_list_delete_first_node(student* linked_list) {
        student* temp = linked_list;
        linked_list = linked_list->next;
        delete temp;
        return linked_list;
    }
    int linked_list_search(student* linked_list){ 
        int c=1;
        for (student* j = linked_list; j != NULL; j = j->next){   
        
            if (((((j->mark.math < 3)||(j->mark.IT<3))||(j->mark.PE<3)) ||(j->mark.english<3))||(j->mark.biology<3)) {
                return c;
            }
            c++;
        }
        c=0;
    }
    void linked_list_insert_node_at_position(student* linked_list, string name,int year,int course,string group,int number_student_book, int math, int english, int PE, int IT, int biology,int position){
        int i;
        struct student *p, *temp;
        p = (struct student*)malloc(sizeof(struct student));
        p->name  = name;
        p->year  = year;
        p->course  = course;
        p->group  = group;
        p->number_student_book = number_student_book;
        p->mark.math  = math;
        p->mark.english = english;
        p->mark.PE  = PE;
        p->mark.IT = IT;
        p->mark.biology = biology;
        p->next = NULL;
        temp = linked_list;
        for(i=2; i<=position-1; i++){
            temp = temp->next;
            if(temp == NULL){
                break;
            }
        }
        if(temp != NULL){  
            p->next = temp->next; 
            temp->next = p;
        }
    }
    void linked_list_replace_by_year_integer(student * linked_list, student *& linked_list_2, int integer, short int mod){
        switch(mod){
            case 1:
            for (student* j = linked_list; j != NULL; j = j->next){
                if(j->year==integer){ 
                    linked_list_add_to_other_list(j, linked_list_2); 
                }
            }
            break;
            case 2:
            for (student* j = linked_list; j != NULL; j = j->next){
                if(j->mark.average==integer){ 
                    linked_list_add_to_other_list(j, linked_list_2); 
                }
            }
            break;
        }
        
    }
    void linked_list_replace_by_year_string(student * linked_list, student *& linked_list_2, string string, short int mod){
        for (student* j = linked_list; j != NULL; j = j->next){
            if(j->name==string){ 
                linked_list_add_to_other_list(j, linked_list_2); 
            }
        }
    }
    int linked_list_search_integer(student* linked_list, int mark){ 
        for (student* j = linked_list; j != NULL; j = j->next){   
            if (j->mark.average>mark) {
                node_print(j);
            }
        }
    }
    int linked_list_search_string(student* linked_list, string name){ 
        cout<<"Ім'я"<<setw(25)<<"Рік н-ння"<<setw(9)<<"Курс"<<setw(15)<<"Група"<<setw(12)<<"№ з.к."<<setw(20)<<"Математика-Англійська-Ф.В.-Інформатика-Біологія"<<endl;
        for (student* j = linked_list; j != NULL; j = j->next){   
            if (j->name==name) {
                node_print(j);
            }
        }
}