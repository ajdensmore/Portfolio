# A bash script to read N integers in an array(A) and find the one integer that does not have a pair

read n
read -a arr
for i in ${arr[@]}; do
  count=0
  for j in ${arr[@]}; do
    if [ $i -eq $j ]; then
        count+=1
    fi
  done
  if [ $count -eq 1 ]; then
    echo $i
    break
  fi
done
