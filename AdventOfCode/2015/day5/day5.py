#! python3 
# day5.py - Day 5 of advent of code 2015

vowels = ['a', 'e', 'i', 'o', 'u']
forbidden = ["ab", "cd", "pq", "xy"]

with open("input.txt", "r") as file_input:
    string_list = [line.strip() for line in file_input]

test_cases = ["ugknbfddgicrmopn", "aaa", "jchzalrnumimnmhp", "haegwjzuvuyypxyu", "dvszwmarrgswjxmb"]

def is_nice(string):
    vowel_count = 0
    twice = 0
    prev_c = 0
    bad_pair = 0
    for i, c in enumerate(string):
        if c == prev_c:
            twice += 1
        if c in vowels:
            vowel_count += 1
        prev_c = c
        if c == 'a' or c == 'c' or c == 'p' or c =='x':
            if string[i:i+2] in forbidden:
                bad_pair += 1
                break
    if vowel_count >= 3 and twice >= 1 and bad_pair == 0:
        #print("Vowel_count: %s, twice: %s" %(vowel_count, twice))
        return True
    return False

#for case in test_cases:
    #print("Is the string: %s nice? := %s" % (case, is_nice(case)))

# Result of Part 1
print(sum([is_nice(string) for string in string_list]))

more_test_cases = ["qjhvhtzxzqqjkmpb", "xxyxx", "uurcxstgmygtbstg", "ieodomkazucvgmuy"]
def is_real_nice(string):
    pair_of_two = 0
    pair_between = 0

    for i in range(len(string)):
        pair = ""
        if i == len(string) - 2:
            break
        pair = string[i] + string[i + 1]
        if string[i + 2:].find(pair) != -1:
            pair_of_two += 1
        if string[i + 1:].find(string[i]) == 1:
            pair_between += 1

    if pair_of_two >= 1 and pair_between >= 1:
        return True
    return False

     
#for case in more_test_cases:
    #print("Is the string: %s nice? := %s" % (case, is_real_nice(case)))

# Result of Part 2
print(sum([is_real_nice(string) for string in string_list]))