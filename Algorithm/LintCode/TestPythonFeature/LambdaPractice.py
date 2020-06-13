import math
class Point:
    def __init__(self, a = 0, b = 0):
        self.x = a
        self.y = b
        self.distant = 0

    def __str__(self):
        return "[" + str(self.x) + "," + str(self.y) + "]"

k = 3

p1 = Point(4,6)
p2 = Point(4,7)
p3 = Point(4,4)
p4 = Point(2,5)
p5 = Point(1,1)

ori = Point(0,0)

pt_list = [p1, p2, p3, p4, p5]

for n in pt_list:
    dx = n.x - ori.x
    dy = n.y - ori.y
    n.distant = math.sqrt(dx * dx + dy * dy)


a = sorted(pt_list, key = lambda point : (point.distant, point.x, point.y), reverse = True)

for ptr in a:
    print(ptr)
