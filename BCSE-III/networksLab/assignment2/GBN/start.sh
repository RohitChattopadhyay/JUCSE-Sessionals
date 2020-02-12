bash kill.sh
rm output.txt
sleep 1
gnome-terminal -- python ./sender.py
sleep 1
gnome-terminal -- python ./receiver.py
sleep 1
gnome-terminal -- python ./channel.py
