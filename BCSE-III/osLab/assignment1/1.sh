#!/bin/bash

read -p "Enter first content "  userv1
read -p "Enter second content " userv2

trap exit_nicely INT

function exit_nicely() {
        echo "Exiting program, thank you"
        exit 1
}

#Check type
if [[ $(expr "$userv1" + 0) == "" ]] || [[ $(expr "$userv2" + 0) == "" ]]; then
        echo "Non numeric input variable"
        exit_nicely
else
        while :
        do
                case "$((RANDOM % 6))" in
                        "0")
                                echo "Sum of $userv1 and $userv2 is $(($userv1+$userv2))"
                                ;;
                        "1")
                                echo "Multiplication of $userv1 and $userv2 is $(($userv1*$userv2))"
                                ;;
                        "2")
                                if [ "$userv2" -eq 0 ]; then
                                        echo "Division by 0 not possible"
                                else
                                        echo "Division of $userv1 by $userv2 is $(($userv1/$userv2))"
                                fi
                                ;;
                        "3")
                                echo "Sum of $userv2 and $userv1 is $(($userv1+$userv2))"
                                ;;
                        "4")
                                echo "Multiplication of $userv2 and $userv1 is $(($userv1*$userv2))"
                                ;;
                        "5")
                                if [ "$userv1" -eq 0 ]; then
                                        echo "Division by 0 not possible"
                                else
                                        echo "Division of $userv2 by $userv1 is $(($userv2/$userv1))"
                                fi
                                ;;
                esac
                sleep 1
        done
fi
