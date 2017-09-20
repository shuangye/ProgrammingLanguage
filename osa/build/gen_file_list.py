#! env python3

import sys
import os
import shutil

def walk(dir_path):
    count = 0
    file_list = ""
    for root, dirs, files in os.walk(dir_path):        
        for file in files:
            base, ext = os.path.splitext(file)
            if (".CPP" == ext.upper() or ".CC" == ext.upper() or ".C" == ext.upper()):
                file_list += os.path.join(dir_path, file) + " "
                count += 1

    file_list = file_list.replace('\\', '/')
    print(file_list)                
    return count
                
                
                
if "__main__" == __name__:
    if (len(sys.argv) > 1):
        count = walk(sys.argv[1])
        print("Found {count} file(s).".format(count = count))
    else:
        print("Usage: {me} dir_path".format(me = sys.argv[0]))
