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
    ToDoItem(std::string name, std::string description)
    {
        _name = name;
        _description = description;
        _id = rand() % 100 + 1;
    }
    ToDoItem(): _id(0), _name(""), _description(""), _completed(false){}
    ~ToDoItem() = default;
    void setCompleted(bool status) { _completed = status; }
    bool getCmpleted() { return _completed; }
    int getId() { return _id; }
    

};
int main()
{
    srand(time(NULL));
    std::string version = "v0.0.1";
    bool exit = false;

    std::list<ToDoItem> todoItems;
    std::list<ToDoItem>::iterator it;
    todoItems.clear();

    ToDoItem test("Name", "desc");
    todoItems.push_back(test);
    while (!exit)
    {
        system("cls");
        std::cout << "ToDo List - " << version << std::endl;
        std::cout << std::endl;
        for (it = todoItems.begin(); it !=todoItems.end(); it++)
        {

        }
    }
}