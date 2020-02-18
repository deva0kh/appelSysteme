#!/bin/sh 
if [ $# -ne 1 ]; then   
 echo "preciser le fichier a traiter"  
   exit 1
 fi 
nomfe=$1 
./majuscule < $nomfe | ./par 8