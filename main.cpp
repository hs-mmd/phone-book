#include <iostream>
#include <map>

using namespace std;

class contact
{
private:
    string main_phone_number;
    string home_phone_number;
    string work_phone_number;
    bool favorite;
    int ID; // ID for change the order of favorite member

public:
    contact()
    {
        main_phone_number = "no main_phone_number";
        home_phone_number = "no home_phone_number";
        work_phone_number = "no work_phone_number";
        favorite = false;
        ID = 0;
    }
    contact(string main_phone_number1, string home_phone_number1, string work_phone_number1, bool favorite1, int ID1)
    {
        main_phone_number = main_phone_number1;
        home_phone_number = home_phone_number1;
        work_phone_number = work_phone_number1;
        favorite = favorite1;
        ID = ID1;
    }
    string get_Main_phone()
    {
        return main_phone_number;
    }
    string get_home_phone()
    {
        return home_phone_number;
    }
    string get_work_phone()
    {
        return work_phone_number;
    }
    bool is_favorite()
    {
        return favorite;
    }
    int get_ID()
    {
        return ID;
    }

    void set_Main_phone(string main_phone_number1)
    {
        main_phone_number = main_phone_number1;
    }
    void set_home_phone(string home_phone_number1)
    {
        home_phone_number = home_phone_number1;
    }
    void set_work_phone(string work_phone_number1)
    {
        work_phone_number = work_phone_number1;
    }
    void set_favorite(bool favo)
    {
        favorite = favo;
    }
    void set_ID(int my_id)
    {
        ID = my_id;
    }
    void operator[](contact c);
};

ostream &operator<<(ostream &out, contact c)
{
    out << "main phone is : " << c.get_Main_phone() << "\n"
        << "home phone is : " << c.get_home_phone() << "\n"
        << "work phone is : " << c.get_work_phone() << "\n"
        << "Is he/she favorite? : " << c.is_favorite() << "\n"
        << "the Id is : " << c.get_ID() << endl;
    return out;
}
void insert_contact(map<string, contact> *map1, string name, contact person)
{
    (*map1).insert(make_pair(name, person));
}
void delete_contact(map<string, contact> *map1, string name)
{
    auto it = (*map1).find(name);
    if (it == (*map1).end())
    {
        cout << "the map doesnt have this contact" << endl;
        return;
    }

    (*map1).erase(name);
}
void edite_contact(map<string, contact> *map1, string name)
{
    auto it = (*map1).find(name);
    if (it == (*map1).end())
    {
        cout << "the map doesnt have this contact" << endl;
        return;
    }

    string strM, strH, strW;
    int ID;
    bool TF;
    cout << "enter main number : ";
    cin >> strM;
    (*map1)[name].set_Main_phone(strM);

    cout << "enter home number : ";
    cin >> strH;
    (*map1)[name].set_home_phone(strH);

    cout << "enter work number : ";
    cin >> strW;
    (*map1)[name].set_work_phone(strW);

    cout << "enter ID: ";
    cin >> ID;
    (*map1)[name].set_ID(ID);

    cout << "enter 1 or 0 to determine favorite person: ";
    cin >> TF;
    (*map1)[name].set_favorite(TF);

    cout << "do you want to edite also the name? if u want type YES : ";
    string str;
    cin >> str;
    if (str == "YES")
    {
        cout << "enter the name : ";
        cin >> str;
        (*map1).insert(make_pair(str, contact(strM, strH, strW, TF, ID)));
        (*map1).erase(name);
    }
    else
        cout << "its ok the name hasnt edited" << endl;
}
void show_the_contacts(map<string, contact> *map1) // it shows base on alphabetic order
{
    for (auto it = (*map1).begin(); it != (*map1).end(); it++)
    {
        cout << it->first << " : " << it->second << endl;
    }
}
void delete_favorite_contact(map<string, contact> *map1, string name) // if you pass the favorite one to this func
{                                                                     // so it will delete but if you dont it wont delete
    auto it = (*map1).find(name);
    if (it == (*map1).end())
    {
        cout << "the map doesnt have this contact" << endl;
        return;
    }

    bool is_favortie = (*map1).find(name)->second.is_favorite();
    if (is_favortie == true)
    {
        (*map1).erase(name);
    }
    else
        cout << name << " is not favorite so you cant delete him/her" << endl;
}
void insert_favorite_contact(map<string, contact> *map1, string name, contact person)
{
    if (person.is_favorite() == true)
    {
        (*map1).insert(make_pair(name, person));
    }
    else
        cout << name << " is not favorite so you cant insert him/her to a favorite list" << endl;
}
void show_the_favorites_contact(map<string, contact> *map1)
{
    for (auto it = (*map1).begin(); it != (*map1).end(); it++)
    {
        if (it->second.is_favorite() == true)
            cout << it->first << " : " << it->second << endl;
    }
}
void show_the_all_number_of_one_contact(map<string, contact> *map1, string name)
{
    auto it1 = (*map1).find(name);
    if (it1 == (*map1).end())
    {
        cout << "the map doesnt have this contact" << endl;
        return;
    }

    auto it = (*map1).find(name)->second;
    cout << "existing " << name << "'s "
         << "numbers" << endl;
    cout << "main :" << it.get_Main_phone() << "\n"
         << "home :" << it.get_home_phone() << "\n"
         << "work :" << it.get_work_phone() << endl;
}
void search_for_special_contact(map<string, contact> *map1, string name)
{
    int flag = 0, count = 0;
    for (auto it = (*map1).begin(); it != (*map1).end(); it++)
    {
        for (int i = 0; i < name.length(); i++)
        {
            if (it->first[i] != name[i])
                flag = 1;
        }
        if (flag == 0)
        {
            cout << it->first << " : " << it->second << endl;
            count = 1;
        }

        flag = 0;
    }

    if (count == 0)
        cout << "find nothing" << endl;
}

int main()
{
    map<string, contact> my_map;

int choose,id;
    string name,main_num,home_num,work_num;
    bool TF;
    cout<<"choose :"<<"\n"<<"1.insert contact"<<"\n"<<"2.delete contact"<<"\n"<<"3.edite contact"<<"\n"
        <<"4.insert favorite contact"<<"\n"<<"5.delete favorite contact"<<"6.show the all number of one contact"
        <<"\n"<<"7.show the favorite contacts"<<"\n"<<"8.show the all contacts"<<"\n"
        <<"9.search for a specefic contact"<<endl;
    cin>>choose;
    if (choose == 1)
    {
        cout << "name : ";
        cin >> name;
        cout << "main_num : ";
        cin >> main_num;
        cout << "home_num : ";
        cin >> home_num;
        cout << "work_num : ";
        cin >> work_num;
        cout << "id : ";
        cin >> id;
        cout << "is favorite?(false or true) : ";
        cin >> TF;

        insert_contact(&my_map, name, contact(main_num, home_num, work_num, TF, id));
    }
    else if (choose == 2)
    {
        cout << "name : ";
        cin >> name;
        delete_contact(&my_map, name);
    }
    else if (choose == 3)
    {
        cout << "name : ";
        cin >> name;
        edite_contact(&my_map, name);
    }
    else if (choose == 4)
    {
        cout << "name : ";
        cin >> name;
        cout << "main_num : ";
        cin >> main_num;
        cout << "home_num : ";
        cin >> home_num;
        cout << "work_num : ";
        cin >> work_num;
        cout << "id : ";
        cin >> id;

        insert_favorite_contact(&my_map, name, contact(main_num, home_num, work_num, 1, id));
    }
    else if(choose == 5)
    {
        cout << "name : ";
        cin >> name;
        delete_favorite_contact(&my_map, name);
    }
    else if (choose == 6)
    {
        cout << "name : ";
        cin >> name;
        show_the_all_number_of_one_contact(&my_map, name);
    }

    return 0;
}
