def totalPairs(n, values):
    # Participants code will be here
    counter=0
    for start in range(len(values)-1):
        currMax=0
        for end in values[start+1:]:
            if (end>currMax and values[start]>currMax):
                counter+=1
                currMax=max(currMax,end)
    return counter

if __name__ == "__main__":
    n = int(input())
    values = list(map(int, input().split()))
    answer = totalPairs(n, values)
    print(answer)