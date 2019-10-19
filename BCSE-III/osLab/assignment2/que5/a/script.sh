rm -f broadcaster receiver
gcc broadcaster.c -o broadcaster
gcc receiver.c -o receiver
receiver=0
echo "Enter number of receivers:"
read receiver
while [ $receiver -gt 0 ]
do
    gnome-terminal -e ./receiver
    receiver=`expr $receiver - 1`
done

gnome-terminal -e ./broadcaster