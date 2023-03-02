class Picture:
    def __init__(self, rows):
        self._rows = rows
 
    def width(self):
        return max(len(row) for row in self._rows)
 
    def height(self):
        return len(self._rows)
 
    def display(self):
        for row in self._rows:
            print(row)
 
    @classmethod
    def from_file(cls, filename):
        with open(filename, 'r') as f:
            rows = f.readlines()
        return cls(rows)

# Create a Picture object
p = Picture([
    "************",
    "*          *",
    "*  Hello,  *",
    "*   World  *",
    "*          *",
    "************"
])
 
# Test the width and height methods
assert p.width() == 12
assert p.height() == 6
 
# Test the display method
p.display()
 
# Create a Picture object from a file
p2 = Picture.from_file('picture.txt')
 
# Test the width and height methods
assert p2.width() == 10
assert p2.height() == 5

