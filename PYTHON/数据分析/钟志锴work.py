# -*- coding: utf-8 -*-
import pandas as pd
import numpy as np
data = pd.read_excel('../data/meal_order_detail.xlsx', encoding="gbk")
data=data.amounts[:20]
# 平均值、最小值和最大值
avg=sum(data)//20

maxn=max(data)

minn=min(data)

