# art-wifi-unicast
ART-WiFi (unicast with automatic retransmissions)

Working setup:

a) A pair of WiFi devices -- a sender and a receiver

b) A 10-second batch conatains a specified number of packets to be transmitted;
  After each batch, power selection script is called to set the transmission power;
  Sender program repeats bathces for a specified time.


0. Requirements

a) Wireless LAN adapter (device ID: wlan0) that supports Ad-Hoc mode

b) Linux and Pre-installed package: libpcap0.8-dev


1. Change configure files

a) dev_id.cnf: device id -- odd number ID is for active device (sender); even number ID is for reactive device (receiver)
  (e.g., set 1 on sender device and 0 on receiver device)

b) target_mac.cnf: WiFi adapter MAC address of "the other device" in the pair, required for both devices
  (check with "ifconfig" and find "HWaddr" on the other device)
  (if set as default "ff:ff:ff:ff:ff:ff", broadcast mode will be used instead of unicast)


2. Compile

Type "make" command to compile


3. Run

a) execute "setup.sh" before running sender or receiver program for the first time after each system boot-up
  (before executing "setup.sh" for the first time, type "chmod +x setup.sh" to set it as executable)
  (type "sudo ./setup.sh" to execute "setup.sh")

b) reactive device (receiver):
Receiver program should start before the sender program in order to wait for and receive packets.
Start receiver program by "sudo ./wz"

c) active device (sender):

sudo ./wz <number of packets per batch> <number of batches to transmit>
  (e.g., "sudo ./wz 1000 30")
  
Also, a multi-run example is available as "run.sh", editable as text file
  (before executing "run.sh" for the first time, type "chmod +x run.sh" to set it as executable)
  (type "sudo ./run.sh" to execute the multi-run script)


4. Change power selection script (as needed)

The file "py/handler.py" contains the power selection algorithm according to "ART" approach.
Change the script between the "#" lines to modify the "ART" approach or design a different power selection appoarch.
Note: as retransmission is envolved, the "packet receiption ratio" here cannot represent link reliablity. Since "ART" approach is based on accurate PRR data, this approach may not work as the same way as in the IWQoS version.
