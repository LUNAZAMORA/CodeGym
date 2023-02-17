#! python3
# day1.py - Day 1 of advent of code 2015

directions = {
    '(' : 1,
    ')' : -1,
}

floor_result = 0
#direction_input = ")))"
with open("input.txt", 'r') as file_input:
    direction_input = file_input.readline()


for step in direction_input:
    floor_result += directions[step]

# Result of part1
print(floor_result)

# Part 2
floor_sum = 0
character_position = -1

for index, step in enumerate(direction_input):
    floor_sum += directions[step]
    if floor_sum == -1:
        character_position = index + 1
        break
print(character_position)