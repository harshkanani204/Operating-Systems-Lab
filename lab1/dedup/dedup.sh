# !/usr/bin/bash                                                                
input_dir=$1
cd ${input_dir}
mkdir temp
:> ./temp/seen
for FILE in *
do
    if [ -f "$FILE" ] 
    then
        if [ -L "$FILE" ] 
        then
            continue
        else
            echo "$FILE">>./temp/seen
        fi
    fi
done

while read files;
do 
    sed -i '1d' ./temp/seen
    cp ./temp/seen ./temp/seen2
    if [ -f "$files" ]
    then
        if [ -L "$files" ]
        then 
            continue
        fi
        while read iscopy;
        do
            if [ -f "$iscopy" ]
            then
                if [ -L "$iscopy" ]
                then 
                    continue
                fi
                cmp -s "$files" "$iscopy"
                if [ $? -eq 0 ]
                then
                    rm "$iscopy"
                    ln -s "$files" "$iscopy"
                fi
            fi
        done < ./temp/seen2
    fi
done < ./temp/seen
rm -r temp
