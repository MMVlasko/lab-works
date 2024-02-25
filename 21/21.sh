if [[ $1 = "?" ]]; then
  echo "Usage:"
  echo "  ./$(basename -- "$0") <maximum file size (bytes)> <suffix> <output file name> [-i] [-d]"
  echo $'\nKeys:\n  -i    Show information about the progress of the merger'
  echo $'  -d    Delete source files'
  read -r
  exit
fi

for name in "$(dirname "$0")"/*
do
  if [[ -f $name ]]; then
    if [[ $(stat -c %s "$name") -le $1 && "${name##*.}" = "$2" ]]; then
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