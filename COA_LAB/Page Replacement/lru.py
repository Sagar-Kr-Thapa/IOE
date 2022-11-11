f = int(input("Enter the total number of frames: "))

frame = []
pages=[int(x) for x in input().split()]



hit = 0
for i in range(len(pages)):
    if (pages[i] in frame):
        hit += 1
    else:
        if(len(frame)<f):
            frame.append(pages[i]) 
        else:
            visited_pages = pages[:i]
            visited_pages = visited_pages[::-1]

            k=0
            lru = 0
            index = 0 
            distinct=[]
            while(k<f):
                if (visited_pages[index] not in distinct):
                    distinct.append(visited_pages[index])
                    lru = visited_pages[index]
                    k +=1
                index+=1

            find = frame.index(lru)
            frame[find] = pages[i] 


print("HIT:",hit)
print("HIT Ratio:", hit/len(pages))



    

