#! python3
# day6.py - Day 6 of advent of code 2015

lights_lit = set()
def perform_command(command):
    global lights_lit
    splited = command.split()
    if len(splited) == 4:
        y_from, x_from = splited[1].split(",")
        y_from, x_from = int(y_from),int(x_from) 
        y_to, x_to = splited[3].split(",")
        y_to, x_to = int(y_to),int(x_to) 
        y_range = range(y_from, y_to + 1)
        x_range = range(x_from, x_to + 1)
        generated_lights = [(y, x) for y in y_range for x in x_range]
        #print(generated_lights)
        for light in generated_lights:
            if light in lights_lit:
                lights_lit.remove(light)
            else:
                lights_lit.add(light)
    elif len(splited) == 5:
        option = splited[1]
        y_from, x_from = splited[2].split(",")
        y_from, x_from = int(y_from),int(x_from) 
        y_to, x_to = splited[4].split(",")
        y_to, x_to = int(y_to),int(x_to) 
        y_range = range(y_from, y_to + 1)
        x_range = range(x_from, x_to + 1)

        generated_lights = [(y, x) for y in y_range for x in x_range]
        #print(generated_lights)
        if option == "on":
            for light in generated_lights:
                lights_lit.add(light)
        elif option == "off":
            for light in generated_lights:
                if light in lights_lit:
                    lights_lit.remove(light)

with open("input.txt", "r") as file_input:
    commands = [line.rstrip() for line in file_input]

test_case = ["turn on 0,0 through 999,999", "toggle 0,0 through 999,0", "turn off 499,499 through 500,500"]
#for command in commands:
    #splited = command.split()
    #print(splited)
for command in commands:
    perform_command(command)

#print(lights_lit)
print(len(lights_lit))