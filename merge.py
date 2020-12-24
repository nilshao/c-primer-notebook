#!/usr/bin/python

#merge internet
internet_file = ["internet/seperate_notes/lesson1.md",
                "internet/seperate_notes/lesson2.md",
                "internet/seperate_notes/lesson3.md",
                "internet/seperate_notes/lesson4.md",
                "internet/seperate_notes/lesson5.md",
                "internet/seperate_notes/lesson6.md"]
merge_internet_dir = "internet/internet_merged.md"
merged_note = open(merge_internet_dir,'w')
for str in internet_file:
    seperate_note = open(str,'r').readlines()
    merged_note.writelines(seperate_note)

#merge operation system
os_file = ["operation_system/notes/Chapter01.md",
            "operation_system/notes/Chapter02_1.md",
            "operation_system/notes/Chapter02_2.md",
            "operation_system/notes/Chapter02_3.md",
            "operation_system/notes/Chapter02_4.md",
            "operation_system/notes/Chapter03.md",
            "operation_system/notes/Chapter04_1.md",
            "operation_system/notes/Chapter04_2.md",
            "operation_system/notes/Chapter05.md"]
merge_os_dir= "operation_system/operation_system_merged.md"
merged_note = open(merge_os_dir,'w')
for str in os_file:
    seperate_note = open(str,'r').readlines()
    merged_note.writelines(seperate_note)