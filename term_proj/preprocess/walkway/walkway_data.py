import geopandas as pd 
import json
from collections import OrderedDict
from shapely.geometry import Point
from shapely import wkt

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

#  https://data.seoul.go.kr/dataList/OA-21208/S/1/datasetView.do

def main():
  
  del_col = ["노드 유형 코드","링크 WKT","링크 ID","링크 유형 코드","시군구코드","시군구명","읍면동코드","읍면동명","고가도로","지하철네트워크","교량","터널","육교","횡단보도","공원,녹지","건물내"]
  data = pd.read_file('서울시 자치구별 도보 네트워크 공간정보.csv', encoding='euc-kr')

  df = pd.GeoDataFrame(data)
  df = df.drop(del_col, axis=1)
  
  # df['노드 WKT'] = wkt.loads(df['노드 WKT'])
  
  node_df = df[df["노드링크 유형"] == "NODE"]
  edge_df = df[df["노드링크 유형"] == "LINK"]

  node_r_cnt, _ = node_df.shape
  edge_r_cnt, _ = edge_df.shape
  
  node, edge = [], []

  print(node_df.columns)

  for row in range(node_r_cnt):
    _row = node_df.iloc[row]

    position = wkt.loads(_row["노드 WKT"])
    start_x = position.x 
    start_y = position.y
    node_data = OrderedDict()
    node_data["id"] = int(_row["노드 ID"])
    node_data["position"] = OrderedDict()
    node_data["position"]["latitude"] = float(start_y)
    node_data["position"]["longitude"] = float(start_x)
    
    node.append(node_data)
    
    
  for row in range(edge_r_cnt):
    print("row:", row)
    _row = (edge_df.iloc[row])
    edge_data = OrderedDict()
    edge_data["start"] = int(_row["시작노드 ID"])
    edge_data["end"] = int(_row["종료노드 ID"])
    edge_data["cost"] = float(_row["링크 길이"])
    
    edge.append(edge_data)
  
  result = OrderedDict()
  result["node"] = node
  result["edge"] = edge
  
  print("edge cnt:",edge_r_cnt)
  
  with open("walkway_node.json", "w") as file:
    json.dump(result, file, indent="\t")
  
  
if __name__ == "__main__":
    main()
