import json
from collections import OrderedDict

# https://www.its.go.kr/nodelink/nodelinkRef

def main():
  with open("driveway_data.json") as file:
    draiveway_data = json.load(file)
    
  node_list = draiveway_data["node"]
  node_cnt = len(node_list)
  
  edge_list = draiveway_data["edge"]
  edge_cnt = len(edge_list)
  
  nodes = []
  edges = []
  
  for node in node_list:
    lat = node["position"]["latitude"]
    lng = node["position"]["longitude"]
    if lat <= 37.715133 and lat >= 37.413294 and lng <= 127.269311 and lng >= 126.734086:
      nodes.append(node)
  
  seoul_node_id = [n["id"] for n in nodes]
  for edge in edge_list:
    start = edge["start"]
    end = edge["end"]
    
    if start in seoul_node_id and end in seoul_node_id:
      edges.append(edge)
      
  result = OrderedDict()
  result["node"] = nodes 
  result["edge"] = edges
  
  with open("driveway_seoul.json", "w") as file:
    json.dump(result, file, indent="\t")

if __name__ == "__main__":
  main()
    
    
    
