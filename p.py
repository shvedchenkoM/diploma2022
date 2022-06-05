import sys
import math
f = math.ceil(float(open(sys.argv[1]).read().split(' ')[5].split('s')[0]))
print(f)
