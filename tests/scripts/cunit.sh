#! /bin/bash

reset='\033[0m'             # reset
                            # colors
red='\033[0;31m'            # red
green='\033[0;32m'          # green

function cunit {
    # get the nubmer of arguments
    number_of_arguments=$#
    # check the number of arguments
    if [[ $number_of_arguments -ne "1" ]]
    then
        echo -e "${red}cunit: Wrong number of arguments: 'cunit executable' ${reset}"
        return
    fi

    # get executable
    executable=$1

    output=$(./"$executable")
    passed=$(echo "$output" | grep "passed")
    failed=$(echo "$output" | grep "FAILED")
    # if we have passed results
    if test ! -z "$passed" 
    then
        echo -e "${green}${passed}${reset}"
    fi
    # if we have failed results
    if test ! -z "$failed" 
    then
        echo -e "${red}${failed}${reset}"
    fi
}