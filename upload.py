#!/bin/sh
#!/usr/bin/python

upload_info = 'test'

chmod +x merge.py 
./merge.py

echo upload_info

git add .
git commit -m upload_info
git push