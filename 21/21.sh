f=$(cat "wef")
for (( i = 0; i < 5; i++ )); do
    echo "${f:i:1}"
done
read -r