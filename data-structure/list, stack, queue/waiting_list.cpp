#include <iostream>
#include <string>
#include <queue>
#include <random>

using namespace std;

// 한 대의 프린터 공유
// 프린터는 한 번에 하나의 인쇄 요청 수행
// 인쇄 요청 내역 저장, 작업 완료 후 저장된 인쇄 요청 처리

// job class : 작업 id, username, print page cnt
// printer class : 인쇄 작업 추가, 추가된 모든 인쇄 작업 처리
// 요청된 순서대로 처리
// 여러 사람이 프린터에 작업 추가하는 시나리오

class Job
{
private:
  int job_id;
  string username;
  int page_cnt;

public:
  static int current_id;
  Job(string username, int page_cnt)
  {
    this->job_id = current_id;
    this->username = username;
    this->page_cnt = page_cnt;
  }
  void print()
  {
    cout << "ID: " << this->job_id << " USERNAME: " << this->username << " PAGES: " << this->page_cnt << endl;
  }
};

int Job::current_id = 0;

class Printer
{
private:
  queue<Job> print_jobs;

public:
  void add_job(Job job)
  {
    this->print_jobs.push(job);
    Job::current_id++;
  }
  void execute()
  {
    Job executing = this->print_jobs.front();
    cout << "실행 중... " << endl;
    executing.print();
    cout << "실행 완료" << endl;
    this->print_jobs.pop();
  }
  bool empty()
  {
    return this->print_jobs.empty();
  }
};

int main()
{
  // random number
  random_device rd;

  mt19937_64 mt(rd());

  uniform_int_distribution<int> range(0, 1);

  string users[7] = {"Kim", "Lee", "Park", "Choi", "Jung", "Jang", "Koh"};
  int pages[7] = {2, 4, 1, 6, 7, 10, 42};

  Printer printer = Printer();

  for (int i = 0; i < 7; i++)
  {
    Job job = Job(users[i], pages[i]);
    printer.add_job(job);
    int rand = range(mt);
    if (rand == 1)
    {
      printer.execute();
    }
  }

  while (!printer.empty())
  {
    printer.execute();
  }
}