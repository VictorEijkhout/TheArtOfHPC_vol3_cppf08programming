#!/usr/bin/env python

import re
import sys

if len(sys.argv)<2:
    print("Invalid commandline <<%s>>" % str(sys.argv))
    print("Usage: cutspace.py fn"); sys.exit(1)

fn = sys.argv[1]
f = open(fn,"r")
nwhite = None
lines = []; firstline = True
try :
    for line in f.readlines():
        line = line.rstrip()
        append = True
        if firstline:
            firstline = False
        ## do not append file name line
        if re.match(r'//.*cxx',line): continue
        ## analyze if not a blank line
        if not re.search("^[ ]*$",line):
            white = re.search("^([ ]*)([^ ])",line).groups()
            #print line,":",white
            white = len(white[0])
            if nwhite is None or white<nwhite:
                nwhite = white
        if append:
            lines.append(line+"\n")
except UnicodeDecodeError:
    print("Non ascii character in",fn)
f.close()
#print nwhite

f = open(fn,"w")
firstline = True
if nwhite is None:
    nwhite = 0
#f.write(".. deleting %d spaces\n" % nwhite)
for line in lines:
    f.write( re.sub("^"+nwhite*" ","",line) )

f.flush()
f.close()
