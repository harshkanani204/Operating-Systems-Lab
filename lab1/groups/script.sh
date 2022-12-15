#!/bin/bash
#question 
#Generate a group id for each group here the group id is <RollNo1_RollNo2> (with <RollNo1> is less than <RollNo2>). If a group has only one member, then group id is simply <Roll_No>. NOTE: the output not contain duplicate entries for group ids.
#Print the duplicate roll numbers to <stderr> with appropriate error message.
#Print the list of roll numbers who have registered for this course but have not responded to the form (not part of any group) with an appropriate error message.
#All roll numbers should be valid (corresponds to a student who has registered in this course). Print the group id if this is not the case (again with appropriate error message).

#Solution
#creating a group id for each group
responses_file=$1
student_list_file=$2
echo "opening ${responses_file}..."
echo "opening ${student_list_file}..."

#filtering contents
cut -d ',' -f 3,4 ${responses_file} | sed 's/"//g' | sed 1d | sed 's/,/_/g' > temp1

#part1,2
#saving roll number of everyone 
awk -F'_' '{
    if($2 != "")
    {
        print( $1 "\n" $2 )
    }
    else
    {
        print($1)
    }
    fi
    }' temp1 > responded

#all the roll number appeared more than once will be stored in file named duplicated
sort responded | uniq -D | uniq > duplicate

#temporary group ids file(two group id with same rollnumber are still there)
awk -F'_' '{
    if($2 != "")
    {
        if($2>$1)
            print ($1 "_" $2);
        else
            print ($2 "_" $1)
    }
    else
    {
        print($1)
    }
    fi
    }' temp1 > group_ids

:> tmpfile

#removing roll number appeared more than once
while read dup;
do
    echo "*Roll no" $dup "is conflicting in" >> tmpfile
    grep  $dup group_ids >> tmpfile
done < duplicate
cat tmpfile > error.log

#final group ids
while read dup;
do
    grep -v $dup group_ids> temp2
    mv temp2 group_ids
done < duplicate

#part3
cp responded resp_not_in_list
cp ${student_list_file} didnt_respond

while read dup;
do
    grep -v $dup resp_not_in_list > tmpfile
    mv tmpfile resp_not_in_list
done < didnt_respond

echo "Students who responded but not in student list" >> error.log
cat resp_not_in_list >> error.log

:> tmpfile2 
while read roll_no;
do 
    grep $roll_no group_ids >> tmpfile2
done < resp_not_in_list
cat tmpfile2 >> error.log


while read dup;
do
    
    grep -v $dup didnt_respond > tmpfile
    mv tmpfile didnt_respond
done < responded
echo "Students who didnt responded" >> error.log
cat didnt_respond >> error.log
cat error.log
rm -r temp1
rm -r tmpfile2