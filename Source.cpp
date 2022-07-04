#include <iostream>
#include <string>
#include <ctime>
#include <list>
class ToDoItem
{
private:
    std::string _description;
    std::string _name;
    int _id;
    bool _completed;
public:
    ToDoItem(std::string name = "", std::string description = "") : _name(name), _description(description), _completed(false)
    {
        _id = rand() % 100 + 1;
    }
    //ToDoItem(): _id(0), _name(""), _description(""), _completed(false){}
    ~ToDoItem() = default;

    void setCompleted(bool status) { _completed = status; }
    bool getCompleted() const { return _completed; }
    int getId() const { return _id; }
        
    std::string getName() const { return _name; }
    void setName(std::string name) { _name = name; }
    std::string getDescription() const { return _description; }
    void setDescription(std::string description) { _description = description; }

};
int main()
{
    srand(time(NULL));
    std::string version = "v0.0.1";
    bool exit = false;
    char input_option;
    int input_id;
    std::string input_string;
    std::list<ToDoItem> todoItems;
    std::list<ToDoItem>::iterator it;
    todoItems.clear();
    
    //ToDoItem test("Name", "desc");
    //todoItems.push_back(test);
    while (!exit)
    {
        bool found = false;
        system("cls");
        std::cout << "ToDo List - " << version << std::endl;
        std::cout << std::endl;
        for (it = todoItems.begin(); it !=todoItems.end(); it++)
        {
            std::cout << it->getId() << " | " << it->getName() << " | ";
            it->getCompleted() ? std::cout << "done" : std::cout << "Not done" << std::endl;
        }
        if (todoItems.empty())
        {
            std::cout << "Add your first task!" << std::endl;
        }
        std::cout << std::endl << std::endl;
        std::cout << "Choose one:" << std::endl;
        std::cout << "[a]dd a new Todo" << std::endl;
        std::cout << "[c]omplete ToDo" << std::endl;
        std::cout << "[g]et in ToDo" << std::endl;
        std::cout << "[e]dit ToDo" << std::endl;
        std::cout << "[d]elete ToDo" << std::endl;
        std::cout << "[q]uit" << std::endl;
        std::cout << "Choice: ";
        std::cin >> input_option;

        if (input_option == 'q')
        {
            std::cout << "Have a good one, bye!";
            // safe to tabel ets
            exit = true;
        }
        else if (input_option == 'a')
        {
            ToDoItem tmp;
            system("cls");
            // scan name description and add to list
            std::cout << "Enter Title of the ToDos: ";
            std::cin.clear();
            std::cin.ignore();
            std::cin >> input_string;
            tmp.setName(input_string);
            std::cout << "Enter Description of the ToDos: ";
            std::cin.clear();
            std::cin.ignore();
            std::getline(std::cin, input_string);
            tmp.setDescription(input_string);

            todoItems.push_back(tmp);
        }
        else if (input_option == 'c')
        {
            if (!todoItems.empty())
            {
                std::cout << "Enter id to mark completed: ";
                std::cin >> input_id;
                std::list<ToDoItem>::iterator it_copy;
                for (it_copy = todoItems.begin(); it_copy != todoItems.end(); it_copy++)
                {
                    if (it_copy->getId() == input_id)
                    {
                        it_copy->setCompleted(true);
                        found = true;
                        std::cout << std::endl << "Your ToDo finally complete!" << std::endl;
                        system("pause");
                    }
                }

                if (!found)
                {
                    std::cout << std::endl << "It seems that there's no your ToDo" << std::endl;
                    system("pause");
                }
            }
            else
            {
                std::cout << "Empty list, add your first ToDo now!" << std::endl;
            }
        }
        else if (input_option == 'g')
        {
            if (!todoItems.empty())
            {
                std::cout << "Enter id to see description of ToDos: ";
                std::cin >> input_id;
                std::list<ToDoItem>::iterator it_get;
                for (it_get = todoItems.begin(); it_get != todoItems.end(); it_get++)
                {
                    if (it_get->getId() == input_id)
                    {
                        std::cout << std::endl;
                        std::cout << "Id: " << it_get->getId() << std::endl;
                        std::cout << "Name: " << it_get->getName() << std::endl;
                        std::cout << "Description: " << it_get->getDescription() << std::endl;
                        std::cout << "Status: ";
                        it_get->getCompleted() ? std::cout << "done" : std::cout << "Not done" << std::endl;
                        found = true;
                        system("pause");
                    }
                }

                if (!found)
                {
                    std::cout << std::endl << "It seems that there's no your ToDo" << std::endl;
                    system("pause");
                }
            }
            else
            {
                std::cout << "Empty list, add your first ToDo now!" << std::endl;
            }
        }
        if (input_option == 'e')
        {
            
            if (!todoItems.empty())
            {
                std::cout << "Enter id to mark completed: ";
                std::cin >> input_id;
                std::list<ToDoItem>::iterator it_edit;
                for (it_edit = todoItems.begin(); it_edit != todoItems.end(); it_edit++)
                {
                    if (it_edit->getId() == input_id)
                    {
                        std::cout << std::endl;
                        std::cout << it_edit->getId() << " | " << it_edit->getName() << " | ";
                        it_edit->getCompleted() ? std::cout << "done" : std::cout << "Not done" << std::endl;

                        char input_edit;
                        std::cout << "What would you like to edit?" << std::endl <<
                            "[n]ame" << std::endl <<
                            "[d]scription" << std::endl;
                        std::cout << "Choice: ";
                        std::cin >> input_edit;
                        if (input_edit == 'n')
                        {
                            std::cout << "Enter Title of the ToDos: ";
                            std::cin.clear();
                            std::cin.ignore();
                            std::cin >> input_string;
                            it_edit->setName(input_string);
                            std::cout << std::endl << "Your ToDo finally edited!" << std::endl;
                            system("pause");
                        }
                        else if (input_edit == 'd')
                        {
                            std::cout << "Enter Description of the ToDos: ";
                            std::cin.clear();
                            std::cin.ignore();
                            std::getline(std::cin, input_string);
                            it_edit->setDescription(input_string);
                            std::cout << std::endl << "Your ToDo finally edited!" << std::endl;
                            system("pause");
                        }
                        else
                        {
                            std::cout << std::endl << "Something went wrong!" << std::endl;
                            system("pause");
                        }

                        found = true;


                    }
                }

                if (!found)
                {
                    std::cout << std::endl << "It seems that there's no your ToDo" << std::endl;
                    system("pause");
                }
            }
            else
            {
                std::cout << "Empty list, add your first ToDo now!" << std::endl;
            }
        }
        if (input_option == 'd')
        {
            
            if (!todoItems.empty())
            {
                std::cout << "Enter id to mark completed: ";
                std::cin >> input_id;
                std::list<ToDoItem>::iterator it_del;
                for (it = todoItems.begin(); it != todoItems.end(); it++)
                {
                    if (it->getId() == input_id)
                    {
                        it = todoItems.erase(it); // need to fix
                        found = true;
                        std::cout << std::endl << "Your ToDo finally delete!" << std::endl;
                        system("pause");
                    }
                }

                if (!found)
                {
                    std::cout << std::endl << "It seems that there's no your ToDo" << std::endl;
                    system("pause");
                }
            }
            else
            {
                std::cout << "Empty list, add your first ToDo now!" << std::endl;
            }
        }
        if (input_option == 'e')
        {
            if (!todoItems.empty())
            {

            }
            else
            {
                std::cout << "Empty list, add your first ToDo now!" << std::endl;
            }
        }
    }



    return 101;
}