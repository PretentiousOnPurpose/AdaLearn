#!/usr/bin/env python
# coding: utf-8

# In[1]:


import pandas as pd
import numpy as np


# In[2]:


ds = pd.read_csv("CIN.csv")


# In[3]:


ds.head()


# In[9]:


X = ds.iloc[:, :-2]
Y = ds.iloc[:, -2]


# In[10]:


X = X.values
Y = Y.values


# In[7]:


X.shape


# In[8]:


#for i in X:
#    print(str(i[0]) + "," + str(i[1]) + "," + str(i[2]) + "," + str(i[3]) + "," + str(i[4]))
    


# In[11]:


for i in Y:
    print(i)


# In[ ]:




