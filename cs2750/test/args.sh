if [[ $# > 2 || $# < 1 ]]
  then
  echo usage: "$0 [from-file] to-file"
  exit 1;
elif [[ $# == 2 ]]
    then
    from = "$1"
    to = "$2"
    echo $from and $to
else
    to = "$1"
    echo $to
fi

