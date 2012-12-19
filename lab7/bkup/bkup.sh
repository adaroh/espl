#!/bin/sh

fileName=$1
NCOPIES=$2

if [ ! -e $fileName ] 
  then
	echo "file not exists"
	exit 1
fi

while [ 0 -ne $NCOPIES ]; do
    
    tmpCopys=$(( $NCOPIES - 1 ))

    if [ -r $fileName.$tmpCopys ]
      then
	cp $fileName.$tmpCopys $fileName.$NCOPIES
    fi

    NCOPIES=$(( $NCOPIES - 1 ))
done

cp $fileName $fileName.1

exit 0