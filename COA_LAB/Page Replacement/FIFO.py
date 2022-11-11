#page in the sequence
f=int(input("Enter number of frames: "))
frame=[ 0 for _ in range(f)]

pages=[int(x) for x in input().split()]

#for storing the frame status 
frames=[[0 for _ in range(len(pages))] for _ in range(f)]

i=0
hit=0
for k in range(len(pages)):
    if pages[k] in frame: hit+=1
    else: 
        frame[i]=pages[k]
        i=(i+1)%f
    for j in range(f):
        frames[j][k]=frame[j]

print(pages)
for i in range(f):
    print(frames[i])

print("HIT: ", hit)
print("HIT ratio: ", hit/len(pages))

