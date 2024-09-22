# careful! on your PC the partition on which the USB is located might not be /dev/sdb 
sudo dd if=homeaccounting.iso of=/dev/sdb && sync
