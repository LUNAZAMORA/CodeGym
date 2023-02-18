#! python3 
# day2.py - Advent of code day2 2015 python solution
import re

# Read the input
# Each line is format lxwxh


# regex version
#dimension_regex = re.compile(r"(\d+)x(\d+)x(\d+)")

# Get the paper for each present given the string of the dimensions in
# format l x w x h
def get_paper_for_each_present(present_dimensions):

    # Regex version
    #match = dimension_regex.search(present_dimensions)
    #l, w, h = int(match.group(1)), int(match.group(2)), int(match.group(3))

    l, w, h = map(int, present_dimensions.split('x'))
    sides = (l*w , w*h , h*l)
    extra = min(sides)
    surface_area = sum(map(lambda x: 2*x, sides))
    return  surface_area + extra

def get_feet_of_ribbon(present_dimensions):
    l, w, h = map(int, present_dimensions.split('x'))
    volume = l*w*h
    sides = [l, w, h]
    sides.pop(sides.index(max(sides)))
    wrap = sum(map(lambda x: 2*x, sides))
    return wrap + volume
    
with open("input.txt", 'r') as file_input:
    dimensions_list = [line.strip() for line in file_input]

# Now we get the total paper needed
result = 0
for present in dimensions_list:
    result += get_paper_for_each_present(present)

# Result of part1
print(result)

ribbon = 0
for present in dimensions_list:
    ribbon += get_feet_of_ribbon(present)

print(ribbon)
