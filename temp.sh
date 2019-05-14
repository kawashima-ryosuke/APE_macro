#!/bin/bash
echo "**************************************************************"
echo "This shellscript makes a working directry for analysis."
echo "Current directry is"
pwd
curpath=`pwd`
SCRIPT_DIR=`epp_temp`
echo "**************************************************************"
read -p "Please input path and directory name: " name
echo "Now making"
mkdir $curpath/$name
mkdir $curpath/$name/out
cp -r $SCRIPT_DIR/program $curpath/$name/.
cp -r $SCRIPT_DIR/data $curpath/$name/.
#fi
echo "Program finished"
