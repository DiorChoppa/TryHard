#include <iostream>
#include <algorithm>
#include <map>
#include <tuple>
#include <vector>

enum class TaskStatus{
	NEW,
	IN_PROGRESS,
	TESTING,
	DONE
};

using TasksInfo = std::map<TaskStatus, int>;

TaskStatus Next(TaskStatus status){
	return static_cast<TaskStatus>(static_cast<int>(status) + 1);
}

void RemoveZeros(TasksInfo& tasks_info) {
  // Соберём те статусы, которые нужно убрать из словаря
  std::vector<TaskStatus> statuses_to_remove;
  for (const auto& task_item : tasks_info) {
    if (task_item.second == 0) {
      statuses_to_remove.push_back(task_item.first);
    }
  }
  for (const TaskStatus status : statuses_to_remove) {
    tasks_info.erase(status);
  }
}

class TeamTasks {
	public:
		const TasksInfo& GetPersonTasksInfo(const std::string& person) const{
			return person_tasks.at(person);
		}
  
		// Добавить новую задачу (в статусе NEW) для конкретного разработчитка
		void AddNewTask(const std::string& person) {
			person_tasks[person][TaskStatus::NEW]++;
		}
  
		// Обновить статусы по данному количеству задач конкретного разработчика
		std::tuple<TasksInfo, TasksInfo> PerformPersonTasks(
			const std::string& person, int task_count){
				TasksInfo updated_tasks, new_tasks;

				TasksInfo& tasks = person_tasks[person];

				for(TaskStatus status = TaskStatus::NEW; status != TaskStatus::DONE; status = Next(status)){
					updated_tasks[Next(status)] = std::min(task_count, tasks[status]);
					task_count -= updated_tasks[Next(status)];
				}
				for(TaskStatus status = TaskStatus::NEW; status != TaskStatus::DONE; status = Next(status)){
					new_tasks[status] = tasks[status] - updated_tasks[Next(status)];
					tasks[status] += updated_tasks[status] - updated_tasks[Next(status)];
				}

				tasks[TaskStatus::DONE] += updated_tasks[TaskStatus::DONE];

				RemoveZeros(updated_tasks);
				RemoveZeros(new_tasks);

				return {updated_tasks, new_tasks};
			};
	
	private:
		std::map<std::string, TasksInfo> person_tasks;
};

void PrintTasksInfo(TasksInfo tasks_info) {
  std::cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
      ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
      ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
      ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << std::endl;
}

int main() {
  TeamTasks tasks;
  tasks.AddNewTask("Ilia");
  for (int i = 0; i < 3; ++i) {
    tasks.AddNewTask("Ivan");
  }
  std::cout << "Ilia's tasks: ";
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
  std::cout << "Ivan's tasks: ";
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));
  
  TasksInfo updated_tasks, untouched_tasks;
  
  std::tie(updated_tasks, untouched_tasks) =
      tasks.PerformPersonTasks("Ivan", 2);
  std::cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  std::cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);
  
  std::tie(updated_tasks, untouched_tasks) =
      tasks.PerformPersonTasks("Ivan", 2);
  std::cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  std::cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);

  return 0;
}