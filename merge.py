#!/usr/bin/python


#merge C++Primer
ori_file = ["C++Primer/chapter01.md",
                    "C++Primer/chapter02.md",
                    "C++Primer/chapter03.md",
                    "C++Primer/chapter06.md",
                    "C++Primer/chapter07.md",
                    "C++Primer/chapter10.md"]
target_file = "C++Primer/notes.md"
merged_note = open(target_file,'w')
for str in ori_file:
    seperate_note = open(str,'r').readlines()
    merged_note.writelines(seperate_note)