import json
from collections import OrderedDict
from haversine import haversine
import geopandas as gpd

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
  
  # supported_drivers['LIBKML'] = 'rw'
  # supported_drivers['SHAPE_RESTORE_SHX'] = 'YES'

  node_df = gpd.read_file("MOCT_NODE.shp",encoding='cp949')
  print(node_df)
  
  edge_df = gpd.read_file("MOCT_LINK.shp",encoding='cp949')
    
  node_del_col = ['NODE_TYPE', 'NODE_NAME', 'TURN_P','UPDATEDATE','REMARK', 'HIST_TYPE','HISTREMARK']
  edge_del_col = ['LINK_ID', 'LANES', 'REMARK', 'HIST_TYPE', 'HISTREMARK', 'ROAD_RANK','ROAD_TYPE','ROAD_NO','ROAD_NAME','ROAD_USE','MULTI_LINK','CONNECT','MAX_SPD','REST_VEH','REST_W','REST_H', 'C-ITS', 'UPDATEDATE', 'geometry']

  node_r_cnt, _ = node_df.shape
  edge_r_cnt, _ = node_df.shape

  node_df = node_df.drop(node_del_col, axis=1)
  edge_df = edge_df.drop(edge_del_col, axis=1)
  
  node, edge = [], []

  print(node_df.columns)
  
  node_df = node_df.to_crs(4326)

  for row in range(node_r_cnt):
    start_id, geometry = node_df.iloc[row]

    start_x = geometry.x 
    start_y = geometry.y
    node_data = OrderedDict()
    node_data["id"] = int(start_id)
    node_data["position"] = OrderedDict()
    node_data["position"]["latitude"] = float(start_y)
    node_data["position"]["longitude"] = float(start_x)
    
    node.append(node_data)
    
    
  for row in range(edge_r_cnt):
    print("row:", row)
    start_id, end_id, length = (edge_df.iloc[row])
    edge_data = OrderedDict()
    edge_data["start"] = int(start_id)
    edge_data["end"] = int(end_id)
    edge_data["cost"] = float(length)
    
    edge.append(edge_data)
  
  node_result = OrderedDict()
  edge_result = OrderedDict()
  node_result["node"] = node
  edge_result["edge"] = edge
  
  print("edge cnt:",edge_r_cnt)
  
  with open("driveway_node.json", "w") as file:
    json.dump(node_result, file, indent="\t")
  with open("driveway_edge.json", "w") as file:
    json.dump(edge_result, file, indent="\t")
  
  
if __name__ == "__main__":
    main()
