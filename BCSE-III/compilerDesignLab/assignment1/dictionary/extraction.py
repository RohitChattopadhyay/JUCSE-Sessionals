import json,sys,os
with open(sys.argv[1],encoding="utf8") as f:
  data = json.load(f)
dir = sys.argv[1][0]
os.mkdir(dir)
for key in data:
    try:
        defination  = data[key]["meanings"][0]["def"]
        speech_part = data[key]["meanings"][0]["speech_part"]        
        filePath = dir + "/" + str(len(key))
        with open(filePath, 'a') as outfile:
            outfile.write(";".join([key,speech_part,defination])+"\n")
        pass
    except:
        print(key)
        pass

