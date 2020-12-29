#!/bin/sh
#!/usr/bin/python

update_info = "test"

chmod +x merge.py 
./merge.py

git add .
git commit -m "Update,"$update_info" !"
git push