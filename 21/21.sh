if [[ $1 = "?" ]]; then
  echo "Usage:"
  echo "  ./$(basename -- "$0") <maximum file size (bytes)> <suffix> <output file name> [-i] [-d]"
  echo $'\nKeys:\n  -i    Show information about the progress of the merger'
  echo $'  -d    Delete source files'
  exit 0
fi

ok=0
for name in "$(dirname "$0")"/*
do
  if [[ -f $name ]]; then
    if [[ $(stat -c %s "$name") -le $1 && "${name##*.}" = "$2" ]]; then
      cat "$name" >> "$3"
      if [[ ok -eq 0 ]]; then ok=1; fi

      if [[ $4 = "-i" || $5 = "-i" ]]; then
        echo "INFO: file <$(basename -- "$name")> (size: $(stat -c %s "$name") b) insert to <$3>"
      fi

      if [[ $4 = "-d" || $5 = "-d" ]]; then
        rm "$name"
      fi
    fi
  fi
done

if [[ ok -eq 1 ]]; then
  echo "INFO: completed"
else
  echo "INFO: such files not found"
fi
