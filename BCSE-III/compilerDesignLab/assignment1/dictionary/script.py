import os
for i in range(ord('a'), ord('z')+1):
    cmd = "python extraction.py " + chr(i) + ".json"
    print(chr(i-32),os.system(cmd))