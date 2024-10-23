import random

coord = list()
for i in range(1000):
  x, y = random.randrange(-10000, 10000), random.randrange(-10000, 10000)
  while [x, y] in coord:
    x, y = random.randrange(-10000, 10000), random.randrange(-10000, 10000)
  coord.append([x, y])

print(100)
for i in range(1000):
  print(coord[i][0], coord[i][1])
