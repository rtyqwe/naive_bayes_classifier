#! /bin/sh
infile_de=$1
infile_en=$2
rm output
for ((i = 1; i <= 400; i++)); do
    tail -n $i $infile_de > outfilede_$i
    tail -n $i $infile_en > outfileen_$i
    ./textClassifier outfilede_$i outfileen_$i dat/tweets/hasselhoff_de_test.txt \
    dat/tweets/hasselhoff_en_test.txt \
    | grep accuracy >> output
    rm outfilede_$i
    rm outfileen_$i
    
   
done