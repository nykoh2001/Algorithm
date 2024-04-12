import pandas as pd 
import json
from collections import OrderedDict
from haversine import haversine
import sys

# {
#   node: [
#     {
#       "id": 2757,
#       "position": {
#         "latitude": 37.504631,
#         "longitude": 126.763538
#       },
#     }, 
#     ...
#   ],
#   edge: [
#     {
#           "start": 1714,  #노드의 id
#           "end": 1703,   #노드의 Id
#           "cost": 90,
#     }, 
#     ...
# ]
# }

def get_cost(start_x, start_y, end_x, end_y):
  start = (start_y, start_x)
  end = (end_y, end_x)
  return int(haversine(start, end) * 1000) # m 단위로 환산
  

def main():
  
  del_col = ['노드유형코드','노드유형명','회전제한유무','회전제한유무명', 'TM_X좌표','TM_Y좌표']
  nodes = pd.read_csv('서울시 노드 정보.csv')

  node_df = pd.DataFrame(nodes)

  r_cnt, c_cnt = nodes.shape

  node_df = node_df.drop(del_col, axis=1)
  
  node, edge = [], []

  # proc_number = int(sys.argv[1])
  
  # data_csv = pd.read_csv(f"./csv_chunk/data_{proc_number}.csv")
  
  # r_cnt, _ = data_csv.shape
  
  # node_df = pd.DataFrame(data_csv)

  for row in range(r_cnt):
    print("row:", row)
    start_id, start_name, start_x, start_y = node_df.iloc[row]
    node_data = OrderedDict()
    node_data["id"] = int(start_id)
    node_data["position"] = OrderedDict()
    node_data["position"]["latitude"] = float(start_y)
    node_data["position"]["longitude"] = float(start_x)
    
    node.append(node_data)
    
    for j in range(row+1, r_cnt):
      end_id, end_name, end_x, end_y = node_df.iloc[j]
      edge_data = OrderedDict()
      edge_data["start"] = int(start_id)
      edge_data["end"] = int(end_id)
      edge_data["cost"] = get_cost(start_x=start_x, start_y=start_y, end_x=end_x, end_y=end_y)
      
      edge.append(edge_data)
  
  result = OrderedDict()
  result["node"] = node
  result["edge"] = edge
  # with open(f"./json/driveway_data_{proc_number}.json", "w") as file:
  #   json.dump(result, file, indent="\t")
  with open("driveway_data.json", "w") as file:
    json.dump(result, file, indent="\t")
  
  
if __name__ == "__main__":
    main()
