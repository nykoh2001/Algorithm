import pandas as pd 

del_col = ['노드유형코드','노드유형명','회전제한유무','회전제한유무명', 'TM_X좌표','TM_Y좌표']
nodes = pd.read_csv('서울시 노드 정보.csv')

node_df = pd.DataFrame(nodes)

r_cnt, c_cnt = nodes.shape

node_df = node_df.drop(del_col, axis=1)

header = node_df.columns

for i in range(20):
  chunk_df = pd.DataFrame(columns=header)
  # chunk_df.columns = header
  idx = 1
  for j in range(i, r_cnt, 20):
    # print("j", j)
    chunk_df.loc[idx] = node_df.iloc[j].values
    idx += 1
  chunk_df.to_csv(f"./csv_chunk/data_{i}.csv", index=False)