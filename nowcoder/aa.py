import numpy as np
from scipy.stats import ortho_group
d = 4
seed = 1
size = 2
a, b = np.int64(ortho_group.rvs(size=size, dim=d, random_state=seed))
print(a)
print(np.linalg.det(a))
print(a @ a.T)