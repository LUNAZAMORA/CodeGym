#! python3 
# day3.py - day3 of advent of code 2015

# ^ north, v south, > east, < west

with open("input.txt", "r") as file_input:
    directions = file_input.readline()

# Santa delivers presents 
# Using (x, y) coordintes of the houese
current_house_coordinates = (0, 0)

visited_houses = set()
# Starts with house at (0, 0) 
test_cases = ['>', "^>v<", "^v^v^v^v^v"]
visited_houses.add(current_house_coordinates)

def perform_move(move, current_house_coordinates):
    if move == '^': # y + 1
        x = current_house_coordinates[0]
        y = current_house_coordinates[1] + 1
        current_house_coordinates = (x, y)
    elif move == 'v': # y - 1
        x = current_house_coordinates[0]
        y = current_house_coordinates[1] - 1
        current_house_coordinates = (x, y)
    elif move == '>': # x + 1
        x = current_house_coordinates[0] + 1
        y = current_house_coordinates[1]
        current_house_coordinates = (x, y)
    elif move == '<': # x - 1
        x = current_house_coordinates[0] - 1
        y = current_house_coordinates[1]
        current_house_coordinates = (x, y)
    else:
        print("ERROR")
        return -1
    return current_house_coordinates
# Part 2 uses turns
turn = 0
#for case in test_cases:
    #turn = 0
    #visited_houses = set()
    #visited_houses.add(current_house_coordinates)
    #print()
    #print("START CASE: %s" % case)
    #for move in case:
for move in directions:
    current_house_coordinates = perform_move(move, current_house_coordinates)
    visited_houses.add(current_house_coordinates)

# Part1 result
print(len(visited_houses))

current_house_coordinates= (0, 0)
current_house_coordinates_robot = (0, 0)
visited_houses = set()
# Starts with house at (0, 0) 
visited_houses.add(current_house_coordinates)
for move in directions:
    # Then he performs a move given by an elf
    if turn == 0: # Santas turn
        current_house_coordinates = perform_move(move, current_house_coordinates)
        visited_houses.add(current_house_coordinates)
        #print("Santa's turn")
    elif turn == 1:
        current_house_coordinates_robot = perform_move(move, current_house_coordinates_robot)
        visited_houses.add(current_house_coordinates_robot)
        #print("Robot's turn")
    # Update turn
    turn ^= 1
    
    #print("On case: %s houses visited: %s" % (case, len(visited_houses))) 
    #print("\tSet is: %s" % visited_houses)

# Part 2 result
print(len(visited_houses))



