from pyecharts import Geo,Style
import pandas as pd 

#导入excel表举例
df=pd.read_csv('lianjia.csv',header=None,sep=',')     
df.head()

#导入自定义的地点经纬度
#geo_cities_coords={df.iloc[i][7]:[df.iloc[i][17],df.iloc[i][18]]
#geo_cities_coords={df.iloc[i][2]:[df.iloc[i][7]]
 #                   for i in range(len(df))}   
attr=list(df[7])
value=list(df[2])
style = Style(title_color= "#fff",title_pos = "center",
width = 1200,height = 600,background_color = "#404a59")

#可视化
geo = Geo('成都高新区房价分布',**style.init_style)
geo.add("",attr,value,visual_range=[0,1000],symbol_size= 5,
        visual_text_color= "#fff",is_piecewise = True,
        is_visualmap= True,maptype = 'china', visual_split_number= 10)

geo.render( '成都高新区房价分布.html')
