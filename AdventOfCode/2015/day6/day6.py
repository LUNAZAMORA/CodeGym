#! python3
# day6.py - Day 6 of advent of code 2015

lights_lit = [False]*1000000
lights_lit_2 = [False]*1000000
def perform_command(command):
    global lights_lit
    splited = command.split()
    if len(splited) == 4:
        y_from, x_from = splited[1].split(",")
        y_from, x_from = int(y_from),int(x_from) 
        y_to, x_to = splited[3].split(",")
        y_to, x_to = int(y_to),int(x_to) 
        for row in range(y_from, y_to + 1):
            for col in range(x_from, x_to + 1):
                i = row * 1000 + col
                lights_lit[i] ^= True
                lights_lit_2[i] += 2
    elif len(splited) == 5:
        option = splited[1]
        y_from, x_from = splited[2].split(",")
        y_from, x_from = int(y_from),int(x_from) 
        y_to, x_to = splited[4].split(",")
        y_to, x_to = int(y_to),int(x_to) 

        if option == "on":
            for row in range(y_from, y_to + 1):
                for col in range(x_from, x_to + 1):
                    i = row * 1000 + col
                    lights_lit[i] |= True
                    lights_lit_2[i] += 1
        elif option == "off":
            for row in range(y_from, y_to + 1):
                for col in range(x_from, x_to + 1):
                    i = row * 1000 + col
                    lights_lit[i] &= False
                    if lights_lit_2[i] > 0:
                        lights_lit_2[i] -= 1

with open("input.txt", "r") as file_input:
    commands = [line.rstrip() for line in file_input]

test_cases = ["turn on 0,0 through 999,999", "toggle 0,0 through 999,0", "turn off 499,499 through 500,500"]
test_cases_2 = ["turn on 0,0 through 0,0", "toggle 0,0 through 999,999"]
#for command in commands:
    #splited = command.split()
    #print(splited)
#for command in test_cases_2:
for command in commands:
    perform_command(command)

#print(lights_lit)
# Result Part 1
print(sum(lights_lit))
# Result Part 2
print(sum(lights_lit_2))