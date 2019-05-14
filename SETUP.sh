#!/bin/bash
echo "**************************************************************"
echo "This shellscript setups for APE_macro"
echo "**************************************************************"
echo "This file write alias in ~/.bashrc"
read -p "OK? [y/n]: " choice
if [ "$choice" = "y" ]; then
touch ~/.bashrc
echo '# alias setting for APE macro' >>  ~/.bashrc
echo 'alias maketmp="source /Users/ryousuke/GitHub/APE_macro/temp.sh"' >>  ~/.bashrc
echo 'alias epp_temp="echo /Users/ryousuke/GitHub/APE_macro/"' >>  ~/.bashrc
echo '' >>  ~/.bashrc
echo "**************************************************************"
echo "FINIFHED !"
echo "**************************************************************"
else
echo "BASH SCRIPT IS STOPPED"
fi
