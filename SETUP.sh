#!/bin/bash
echo "**************************************************************"
echo "This shellscript setups for APE_macro"
curpath=`pwd`
echo "**************************************************************"
echo "This file write alias in ~/.bashrc"
read -p "OK? [y/n]: " choice
if [ "$choice" = "y" ]; then
touch ~/.bashrc
echo '# alias setting for APE macro' >>  ~/.bashrc
echo 'alias maketmp="source '$curpath'/temp.sh"' >>  ~/.bashrc
echo 'alias epp_temp="echo '$curpath'/"' >>  ~/.bashrc
echo '' >>  ~/.bashrc
source ~/.bashrc
echo "**************************************************************"
echo "FINIFHED !"
echo "**************************************************************"
else
echo "BASH SCRIPT IS STOPPED"
fi
