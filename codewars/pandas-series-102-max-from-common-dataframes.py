#!/usr/bin/env python3

"""

Max From Common DataFrames
Input parameters
Two pandas.DataFrame objects

Task
Your function must return a new pandas.DataFrame with the same data and columns from the first parameter. For common columns in both inputs you must return the greater value of each cell for that column.

You must not modify the original inputs.

Input DataFrame will never be empty. The number rows of both inputs will be the same.

Examples
Inputs
   A    B    C
0  2.5  2.0  2.0
1  2.0  2.0  2.0
   C    B    D    E
0  1.0  6.0  7.0  1.0
1  8.5  1.0  9.0  1.0

Output
   A    B    C
0  2.5  6.0  2.0
1  2.0  2.0  8.5

Hint: Use pandas methods

"""

import pandas as pd
import numpy as np

def max_common(a, b):
    r = a.copy()
    k = a.columns.intersection(b.columns)
    r[k] = a[k].clip(lower=b.reindex_like(a)[k])
    return r

df_a = pd.DataFrame(data=[[2.5, 2.0, 2.0], [2.0, 2.0, 2.0]], columns=list('ABC'))
df_b = pd.DataFrame(data=[[1.0, 6.0, 7.0, 1.0], [8.5, 1.0, 9.0, 1.0]], columns=list('CBDE'))
df_out = pd.DataFrame(data=[[2.5, 6.0, 2.0], [2.0, 2.0, 8.5]], columns=list('ABC'))
assert(np.allclose(max_common(df_a, df_b), df_out))
