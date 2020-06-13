class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None



a = TreeNode(1)
b = TreeNode(2)
c = TreeNode(3)

my_list = [a, b, c]

for item in my_list:
    print(item.val)

a.val = 9

for item in my_list:
    print(item.val)

item = 'pm25'
has_mask = False
if item in {'pm25'}:
    has_mask = True
print(has_mask)