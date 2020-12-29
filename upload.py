#!/bin/sh
#!/usr/bin/python

update_info = 'update'

chmod +x merge.py 
./merge.py

git add .
git commit -m "Update \"$update_info\""
git push