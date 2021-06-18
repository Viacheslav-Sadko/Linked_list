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
//prototype of functions
    int linked_list_extract(string group);
    int linked_list_extract_name(string name);
    bool comprassion_group_z( int& a, int& b, const  student& c, const student& d){ a=linked_list_extract(c.group); b=linked_list_extract(d.group); return (a < b); };
    bool comprassion_group_s( int& a, int& b, const  student& c, const student& d){ a=linked_list_extract(c.group); b=linked_list_extract(d.group); return (a > b); };
    bool comprassion_name_z( int& a, int& b, const  student& c, const student& d){ a=linked_list_extract_name(c.name); b=linked_list_extract_name(d.name); return (a < b); };
    bool comprassion_name_s( int& a, int& b, const  student& c, const student& d){ a=linked_list_extract_name(c.name); b=linked_list_extract_name(d.name); return (a > b); };
    void linked_list_sort_string(student*& linked_list, bool (*comprassion)(int& ,int& ,const student&, const student&));
    bool comprassion_year_z(const  student& a, const student& b){ return (a.year < b.year); };
    bool comprassion_year_s(const  student& a, const student& b){ return (a.year > b.year); };
    bool comprassion_mark_math_z(const  student& a, const student& b){ return (a.mark.math < b.mark.math); };
    bool comprassion_mark_math_s(const  student& a, const student& b){ return (a.mark.math > b.mark.math); };
    bool comprassion_mark_IT_z(const  student& a, const student& b){ return (a.mark.IT < b.mark.IT); };
    bool comprassion_mark_IT_s(const  student& a, const student& b){ return (a.mark.IT > b.mark.IT); };
    bool comprassion_mark_PE_z(const  student& a, const student& b){ return (a.mark.PE < b.mark.PE); };
    bool comprassion_mark_PE_s(const  student& a, const student& b){ return (a.mark.PE > b.mark.PE); };
    bool comprassion_mark_english_z(const  student& a, const student& b){ return (a.mark.english < b.mark.english); };
    bool comprassion_mark_english_s(const  student& a, const student& b){ return (a.mark.english > b.mark.english); };
    bool comprassion_mark_biology_z(const  student& a, const student& b){ return (a.mark.biology < b.mark.biology); };
    bool comprassion_mark_biology_s(const  student& a, const student& b){ return (a.mark.biology > b.mark.biology); };
    void linked_list_add(student*& linked_list, string name,int year,int course,string group, int number_student_book, int math, int english, int PE, int IT, int biology);
    void linked_list_print(const student* linked_list);
    void linked_list_sort(student*& linked_list, bool (*comprassion)(const student&, const student&));
    void linked_list_clear(student*& linked_list);
    void linked_list_add_to_other_list(student*& linked_list, student*& linked_list_2);
    void linked_list_average_counting(student* linked_list);
    void linked_list_delete_by_position(student*& linked_list, int position);
    student* linked_list_delete_first_node(student* linked_list);
    int linked_list_search(student* linked_list);
    void linked_list_insert_node_at_position(student* linked_list, string name,int year,int course,string group,int number_student_book, int math, int english, int PE, int IT, int biology,int position);
    void linked_list_replace_by_year_integer(student * linked_list, student *& linked_list_2, int integer, short int mod);
    void linked_list_replace_by_year_string(student * linked_list, student *& linked_list_2, string string, short int mod);
    int linked_list_search_integer(student* linked_list, int mark);
    int linked_list_search_string(student* linked_list, string name);

int main(){
    int n, year, course, number_student_book, math, IT, PE, biology, english, average_mark, position, mark;
    string name, group;
    student *linked_list = NULL;
    student *linked_list_2 = NULL;
    //Adding nodes
        linked_list_add(linked_list, "Stas", 2002, 2, "DS-81", 2302, 4,4,5,2,1);
        linked_list_add(linked_list, "Sasha", 1998, 3, "DS-91", 2301, 3,4,5,4,3);
        linked_list_add(linked_list, "Slavik", 1995, 6, "DS-51", 7331, 5,5,5,5,5);
        linked_list_add(linked_list, "Lena", 1999, 5, "DS-41", 2431, 3,4,5,3,4);
        linked_list_add(linked_list, "Oksana", 1999, 5, "DS-41", 2431, 3,4,5,3,4);
        linked_list_add(linked_list, "Sasha", 2001, 3, "DS-91", 2301, 3,4,5,4,3);
        linked_list_add(linked_list, "Alexey", 1999, 5, "DS-41", 2431, 3,4,5,3,4);
        linked_list_add(linked_list, "Stas", 2002, 2, "DS-81", 2302, 4,4,5,2,5);
        linked_list_add(linked_list, "Maks", 2002, 1, "DS-01", 3201, 3,4,5,5,3);
        linked_list_add(linked_list, "Maks", 2001, 1, "DS-01", 3201, 3,4,5,2,4);
        linked_list_add(linked_list, "Sasha", 2003, 3, "DS-91", 2301, 3,4,5,4,3);
        linked_list_add(linked_list, "Maks", 2001, 1, "DS-01", 3201, 3,4,5,2,1);
        linked_list_add(linked_list, "Sasha", 2003, 3, "DS-91", 2301, 3,4,5,4,3);
        linked_list_add(linked_list, "Maks", 2003, 1, "DS-01", 3201, 3,4,5,2,5);
        linked_list_add(linked_list, "Slavik", 2001, 6, "DS-51", 7331, 5,5,5,5,5);
        linked_list_add(linked_list, "Lena", 2002, 5, "DS-41", 2431, 3,4,5,3,4);
        linked_list_add(linked_list, "Stas", 2002, 2, "DS-81", 2302, 4,4,5,2,5);
        linked_list_add(linked_list, "Oksana", 2001, 5, "DS-41", 2431, 3,4,5,3,4);
        linked_list_add(linked_list, "Alexey", 2002, 5, "DS-41", 2431, 3,4,5,3,4);
        linked_list_add(linked_list, "Stas", 2002, 2, "DS-81", 2302, 4,4,5,2,5);
        linked_list_average_counting(linked_list);
        
    cout<<"My first project\nby Sadko Viacheslav\n";
    linked_list_print(linked_list);
    do{
    cout<<endl<<"Меню: \n1) Вивести весь список\n2) Додати нового студента\n3) Відсортувати список\n4) Фільтрування списку\n5) Робота з іншим списком\n6) Очистити весь список\n7) Вихід\nПункт: ";
    cin>>n;
    switch(n){
        case 1:
        linked_list_print(linked_list);
        break;
        case 2:
        cout<<"Додавання:\n1) На початок списку\n2) За позицією\n3) В кінець списку\n4) Повернутися на головне меню\n";
        cin>>n;
        cout<<"Ім'я студента: ";
        cin>>name;
        cout<<"Рік народження: ";
        cin>>year;
        cout<<"Курс: ";
        cin>>course;
        cout<<"Група: ";
        cin>>group;
        cout<<"Номер залікової книги: "; 
        cin>>number_student_book;
        cout<<"Оцінка з математики: "; 
        cin>>math;
        cout<<"Оцінка з англійскьої мови : ";
        cin>>english;
        cout<<"Оцінка з ФВ: ";
        cin>>PE;
        cout<<"Оцінка з програмування: ";
        cin>>IT;
        cout<<"Оцінка з біології: ";
        cin>>biology;
        switch(n){
            case 1:
            linked_list_add(linked_list, name,year,course,group,number_student_book, math, english, PE, IT, biology);
            linked_list_average_counting(linked_list);
            break;
            case 2:
            cout<<"Позиція, на яку потрібно додати нового студента: ";
            cin>>position;
            linked_list_insert_node_at_position(linked_list, name,year,course,group,number_student_book, math, english, PE, IT, biology, position);
            linked_list_average_counting(linked_list);
            case 3:
            break;
        }
        break;
        case 3:
        cout<<"\nСортування:\n1) За роком народження\n2) За ім'ям\n3) За оцінкою\n4) За групою\n\n5) Повернутися на головне меню\n";
        cin>>n;
        switch(n){
            case 1:
            cout<<"1) За зростанням\n2) За спаданням\n";
            cin>>n;
            switch(n){
                case 1:
                linked_list_sort(linked_list, &comprassion_year_z);
                break;
                case 2:
                linked_list_sort(linked_list, &comprassion_year_s);
                break;
                case 3:
                break;
                default:
                cout<<"Такого пункту немає, оберіть інший\n";
                break;
            }
            break;
            case 2:
            cout<<"1) Від A-Z\n2) Від Z-A\n3) Повернутися на головне меню\n";
            cin>>n;
            switch(n){
                case 1:
                linked_list_sort_string(linked_list, &comprassion_name_s);
                break;
                case 2:
                linked_list_sort_string(linked_list, &comprassion_name_z);
                break;
                case 3:
                break;
                default:
                cout<<"Такого пункту немає, оберіть інший\n";
                break;
            }
            break;
            case 3:
            cout<<"1) За математикою\n2) За інформатикою\n3) За фізичним вихованням\n4) За англійською\n5) За біологією\n6) Повернутися на головне меню\n";
            cin>>n;
            switch(n){
                case 1:
                cout<<"1) За зростанням\n2) За спаданням\n3) Повернутися на головне меню\n";
                cin>>n;
                switch(n){
                    case 1:
                    linked_list_sort(linked_list, &comprassion_mark_math_z);
                    break;
                    case 2:
                    linked_list_sort(linked_list, &comprassion_mark_math_s);
                    break;
                    case 3:
                    break;
                }
                break;
                case 2:
                cout<<"1) За зростанням\n2) За спаданням\n3) Повернутися на головне меню\n";
                cin>>n;
                switch(n){
                    case 1:
                    linked_list_sort(linked_list, &comprassion_mark_IT_z);
                    break;
                    case 2:
                    linked_list_sort(linked_list, &comprassion_mark_IT_s);
                    break;
                    case 3:
                    break;
                }
                break;
                case 3:
                cout<<"1) За зростанням\n2) За спаданням\n3) Повернутися на головне меню\n";
                cin>>n;
                switch(n){
                    case 1:
                    linked_list_sort(linked_list, &comprassion_mark_PE_z);
                    break;
                    case 2:
                    linked_list_sort(linked_list, &comprassion_mark_PE_s);
                    break;
                    case 3:
                    break;
                }
                break;
                case 4:
                cout<<"1) За зростанням\n2) За спаданням\n3) Повернутися на головне меню\n";
                cin>>n;
                switch(n){
                    case 1:
                    linked_list_sort(linked_list, &comprassion_mark_english_z);
                    break;
                    case 2:
                    linked_list_sort(linked_list, &comprassion_mark_english_s);
                    break;
                    case 3:
                    break;

                }
                break;
                case 5:
                cout<<"1) За зростанням\n2) За спаданням\n3) Повернутися на головне меню\n";
                cin>>n;
                switch(n){
                    case 1:
                    linked_list_sort(linked_list, &comprassion_mark_biology_z);
                    break;
                    case 2:
                    linked_list_sort(linked_list, &comprassion_mark_biology_s);
                    break;
                    case 3:
                    break;
                }
                break;
                case 6:
                break;
                default:
                cout<<"Такого пункту немає, оберіть інший\n";
                break;
            }
            break;
            case 4:
            cout<<"1) За зростанням\n2) За спаданням\n";
            cin>>n;
            switch(n){
                case 1:
                linked_list_sort_string(linked_list, &comprassion_group_s);
                break;
                case 2:
                linked_list_sort_string(linked_list, &comprassion_group_z);
                break;
            }
            break;
            default:
            cout<<"Такого пункту немає, оберіть інший\n";
            break;
        }
        break;
        case 4:
        cout<<"Фільтрування:\n1) Вивести список студентів, середній бал яких вище заданого\n2) Вивести студентів, із заданим іменем\n3) Повернутися на головне меню\n";
        cin>>n;
        switch(n){
            case 1:
            cout<<"Оцінка: ";
            cin>>average_mark;
            linked_list_search_integer(linked_list, average_mark);
            break;
            case 2:
            cout<<"Ім'я: ";
            cin>>name;
            linked_list_search_string(linked_list, name);
            break;
            case 3:
            break;
        }
        break;
        case 5:
        cout<<"Робота з новим списком:\n1) Вивести список\n2) Перемістити за роком\n3) Перемістити за іменем\n4) Перемістити за середнім балом\n5) Очистити весь список\n6) Повернутися на головне меню\n";
        cin>>n;
        switch(n){
            case 1:
            linked_list_print(linked_list_2);
            break;
            case 2:
            cout<<"Рік: ";
            cin>>year;
            linked_list_replace_by_year_integer(linked_list, linked_list_2, year, 1);
            break;
            case 3:
            cout<<"Ім'я: ";
            cin>>name;
            linked_list_replace_by_year_string(linked_list, linked_list_2, name, 1);
            break;
            case 4:
            cout<<"Середній бал: ";
            cin>>mark;
            linked_list_replace_by_year_integer(linked_list, linked_list_2, mark, 2);
            break;
            case 5:
            linked_list_clear(linked_list_2);
            break;
            case 6:
            break;
            default:
            cout<<"Такого пункту немає, оберіть інший\n";
            break;
        }
        break;
        case 6:
        linked_list_clear(linked_list);
        break;
        case 7:
        break;
        default:
        cout<<"Такого пункту немає, оберіть інший\n";
        break;
    }}
    while(n!=7);   
}