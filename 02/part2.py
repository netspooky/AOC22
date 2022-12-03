import sys

with open(sys.argv[1],"r") as f:
    infile = f.readlines()

score = 0

for i in infile:
    i = i.split("\n")[0]
    if i == "A X":
        score += 0 + 3
    if i == "A Y":
        score += 3 + 1
    if i == "A Z":
        score += 6 + 2
    if i == "B X":
        score += 0 + 1
    if i == "B Y":
        score += 3 + 2
    if i == "B Z":
        score += 6 + 3
    if i == "C X":
        score += 0 + 2
    if i == "C Y":
        score += 3 + 3
    if i == "C Z":
        score += 6 + 1

print(score)

