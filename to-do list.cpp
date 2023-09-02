#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool completed;

    Task(const std::string& desc) : description(desc), completed(false) {}
};

void displayTasks(const std::vector<Task>& tasks) {
    std::cout << "To-Do List:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". ";
        if (tasks[i].completed) {
            std::cout << "[Completed] ";
        }
        std::cout << tasks[i].description << "\n";
    }
}

int main() {
    std::vector<Task> taskList;
    std::string taskDescription; 

    while (true) {
        std::cout << "Options:\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Mark Task as Completed\n";
        std::cout << "4. Remove Task\n";
        std::cout << "5. Quit\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cin.ignore(); 
                std::cout << "Enter task description: ";
                std::getline(std::cin, taskDescription);
                taskList.push_back(Task(taskDescription));
                std::cout << "Task added!\n";
                break;
            case 2:
                displayTasks(taskList);
                break;
            case 3:
                displayTasks(taskList);
                std::cout << "Enter the task number to mark as completed: ";
                int completeIndex;
                std::cin >> completeIndex;
                if (completeIndex > 0 && completeIndex <= static_cast<int>(taskList.size())) {
                    taskList[completeIndex - 1].completed = true;
                    std::cout << "Task marked as completed!\n";
                } else {
                    std::cout << "Invalid task number.\n";
                }
                break;
            case 4:
                displayTasks(taskList);
                std::cout << "Enter the task number to remove: ";
                int removeIndex;
                std::cin >> removeIndex;
                if (removeIndex > 0 && removeIndex <= static_cast<int>(taskList.size())) {
                    taskList.erase(taskList.begin() + removeIndex - 1);
                    std::cout << "Task removed!\n";
                } else {
                    std::cout << "Invalid task number.\n";
                }
                break;
            case 5:
                std::cout << "Goodbye!\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please enter a valid option.\n";
                break;
        }
    }

    return 0;
}
