import sys

with open(sys.argv[1],"r") as f:
    infile = f.readlines()

score = 0

for i in infile:
    i = i.split("\n")[0]
    if i == "A X":
        score += 1 + 3 # Rock vs Rock (Draw)
    if i == "A Y":
        score += 2 + 6 # Rock vs Paper (Win)
    if i == "A Z":
        score += 3 + 0 # Rock vs Scissors (Lose)
    if i == "B X":
        score += 1 + 0 # Paper vs Rock (Lose)
    if i == "B Y":
        score += 2 + 3 # Paper vs Paper (Draw)
    if i == "B Z":
        score += 3 + 6 # Paper vs Scissors (Win)
    if i == "C X":
        score += 1 + 6 # Scissors vs Rock (Win)
    if i == "C Y":
        score += 2 + 0 # Scissors vs Paper (Lose)
    if i == "C Z":
        score += 3 + 3 # Scissors vs Scissors (Draw)

print(score)

