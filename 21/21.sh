if [[ $1 = "?" ]]; then
  echo "Usage:"
  echo "  ./$(basename -- "$0") <maximum file size (bytes)> <suffix> <output file name> [-i] [-d]"
  echo $'\nKeys:\n  -i    Show information about the progress of the merger'
  echo $'  -d    Delete source files'
  read -r
  exit
fi

home=$(dirname "$0")
touch "$3"

for name in "$home"/*
do
  if [[ -f $name ]]; then
    extension="${name##*.}"
    size=$(stat -c %s "$name")
    if [[ $size -le $1 && $extension = "$2" ]]; then
      cat "$name" >> "$3"
      if [[ $4 = "-i" || $5 = "-i" ]]; then
        echo "INFO: file <$(basename -- "$name")> insert to <$3>"
      fi
      if [[ $4 = "-d" || $5 = "-d" ]]; then
        rm "$name"
      fi
    fi
  fi
done

if [[ $4 = "-i" || $5 = "-i" ]]; then
  echo "INFO: completed"
fi

read -r