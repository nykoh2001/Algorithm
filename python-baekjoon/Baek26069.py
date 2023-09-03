from sys import stdin

input = stdin.readline 

N = int(input())

##### Dictionary를 사용한 Solution #####

rabbits = dict()

rabbits["ChongChong"] = True

for i in range(N):
  rabbit0, rabbit1 = input().rstrip().split(" ")
  try:
    if (rabbits[rabbit0] == True):
      rabbits[rabbit0] = True 
      rabbits[rabbit1] = True 
  except:
    try:
      if (rabbits[rabbit1] == True):
        rabbits[rabbit0] = True 
        rabbits[rabbit1] = True 
    except:
      pass
    
print(len(rabbits))

##### Set을 사용한 Solution #####

rabbits = {'ChongChong'}

for i in range(N):
  rabbit0, rabbit1 = input().rstrip().split(" ")
  if rabbit0 in rabbits or rabbit1 in rabbits:
    rabbits.add(rabbit0)
    rabbits.add(rabbit1)

print(len(rabbits))