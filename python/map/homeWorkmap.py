from mpl_toolkits.basemap import Basemap
import matplotlib.pyplot as plt
import numpy as np
my_map=Basemap(projection='merc',lat_0=30.40,lon_0=104.04,resolution = 'l',
        area_thresh = 1000.0,
        llcrnrlon =73.40,llcrnrlat =3.52,
        urcrnrlon =135.23,urcrnrlat =53.33)
my_map.readshapefile("/home/hacker/map/CHN_adm_shp/CHN_adm1",'states',drawbounds=True)
#my_map.drawcoastlines()
#my_map.shadedrelief()
my_map.etopo()
#chengdu

lats=[30.4,30.82,31.52]
lons=[104.04,108.40,117.17]
x,y = my_map(lons, lats)
my_map.plot(x, y, 'bo', markersize=6)
my_map.plot(x,y)
labels = ['chengdu', 'wanzhou','hefei' ]
for label, xpt, ypt in zip(labels, x, y):
    plt.text(xpt+10000, ypt+500, label)

plt.show()
