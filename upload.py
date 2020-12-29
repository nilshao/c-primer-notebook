#!/bin/sh
#!/usr/bin/python

upload_info = "test"

chmod +x merge.py 
./merge.py

git add .
git commit -m upload_info
git push