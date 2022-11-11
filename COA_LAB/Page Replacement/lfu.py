f = int(input("Enter the total number of frames: "))

frame = []

pages = [int(x) for x in input().split()]
    
hit = 0
occurances=[0 for _ in range(f)]

for i in range(len(pages)):
    if pages[i] in frame :
        hit+=1
        getindex = frame.index(pages[i])
        occurances[getindex] +=1 
    
    else:
        if len(frame)<f:
            frame.append(pages[i]) 
            occurances[len(frame)-1] = 1 

        else:
            if (occurances.count(min(occurances)) == 1):
                getindex = occurances.index(min(occurances))
                frame[getindex] = pages[i]
                occurances[getindex] = 1 

            else:
                visited_pages = pages[:i]
                visited_pages = visited_pages[::-1]
                repeated_min=[]
                minimum = min(occurances)
                for j in range(f):
                    if(occurances[j] == minimum):
                        repeated_min.append(frame[j])

                replaced_index = 0 
                for j in range(len(repeated_min)):
                    if(visited_pages.index(repeated_min[j])>replaced_index):
                        replaced_index = visited_pages.index(repeated_min[j])
                        replaced_value = repeated_min[j]

                getindex = frame.index(replaced_value)
                frame[getindex] = pages[i]
                occurances[getindex] = 1


print("HIT: ",hit )
print("HIT ratio: ", hit/len(pages))







                        

                
                    
                    







