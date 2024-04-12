from sys import stdin 

input = stdin.readline

class stack:
  top = -1 
  data = []
  
  def process_line(self, N:int):
    for _ in range(N):
      line = input().split()
      first = line[0]
      
      if first == "1":
        second = line[1]
        self.push(int(second))
      elif first == "2":
        self.pop()
      elif first == "3":
        self.data_cnt()
      elif first == "4":
        print(self.is_empty())
      elif first == "5":
        self.print_top()
  
  def push(self, number: int):
    self.data.append(number)
    self.top += 1
  
  def is_empty(self):
    if self.top == -1: return 1
    return 0

  def data_cnt(self):
    print(self.top + 1)
  
  def print_top(self):
    if self.top == -1:
      print(-1)
    else:
      print(self.data[self.top])
  
  def pop(self):
    self.print_top()
    if self.top >= 0:
      self.data.pop()
      self.top -= 1
      
stack = stack()

N = int(input())

stack.process_line(N)