def match(t, p):
    return [i for i in range(len(t)-len(p)+1) if t[i:i+len(p)] == p]

t = p = ""
while True:
    print("\n1.Text  2.Pattern  3.Search  4.Exit")
    c = input("Choice: ")
    if c == "1": t = input("Enter text: ")
    elif c == "2": p = input("Enter pattern: ")
    elif c == "3":
        if not t or not p: print("Enter both first!")
        elif len(p) > len(t): print("Pattern too long!")
        else:
            r = match(t, p)
            print("Found at:", r if r else "No match")
    elif c == "4": break
    else: print("Invalid!")