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
        std::cout << "[c]omplete todo" << std::endl;
        //std::cout << "[e]dit" << std::endl;
        //std::cout << "[d]elete" << std::endl;
        //std::cout << "[q]uit" << std::endl;
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

            // scan name description and add to list
            std::cout << "Enter Title of the ToDos: ";
            std::cin.clear();
            std::cin.ignore();
            std::cin >> input_string;
            tmp.setName(input_string);
            std::cout << "Enter Description of the ToDos: ";
            std::getline(std::cin, input_string);
            std::cin.clear();
            std::cin.ignore();
            tmp.setDescription(input_string);

            todoItems.push_back(tmp);
        }
        else if (input_option == 'c')
        {
            std::cout << "Enter id to mark completed: ";
            std::cin >> input_id;
            for (it = todoItems.begin(); it != todoItems.end(); it++)
            {
                if (it->getId() == input_id)
                {
                    it->setCompleted(true);
                }
            }
        }
    }



    return 101;
}