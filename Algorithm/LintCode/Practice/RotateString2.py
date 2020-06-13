class RotateString2:
    """
    @param str: A String
    @param left: a left offset
    @param right: a right offset
    @return: return a rotate string
    """
    def RotateString(self, str, left, right):
        if left == right:
            return str

        # has one trick, if offset is greater than the length
        offset = (left - right) % len(str)

        return self.moveLeft(str, offset) if offset > 0 else self.moveRight(str, -offset)

    def RotateString_Simple(self, str, left, right):
        if left == right:
            return str
        # because python support negative number as index    
        offset = (left - right) % len(str)
        return str[offset:] + str[:offset]


    def moveRight(self, string, offset):
        size = len(string)
        left_str = string[ : size - offset]
        right_str = string[size - offset : ]
        return right_str + left_str


    def moveLeft(self, string, offset):
        left_str = string[ : offset]
        right_str = string[offset : ]
        return right_str + left_str


test = RotateString2()
string = "abcdefg"
left = 1
right = 20
out = test.RotateString(string, left, right)
print(out)